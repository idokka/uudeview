/*
 * This file is part of uudeview 32, a simple and friendly multi-part multi-
 * file uudecoder  program.
 *
 *	Copyright (c) 1997, 2001 by:
 *		Michael Newcomb <miken@miken.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * --> Commercial reuse is prohibited <--
 *
 */


// Engine.cpp : implementation file for secondary threads
//

#include "stdafx.h"
#include "Uud32.h"
#include "Engine.h"

#include "RenOutFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(Engine, CWinThread)
	//{{AFX_MSG_MAP(Engine)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_MESSAGE(ENG_LOAD, OnLoad)
	ON_MESSAGE(ENG_STOP, OnStop)
	ON_MESSAGE(ENG_DECODE, OnDecode)
	ON_MESSAGE(ENG_CANCEL, OnCancel)
	ON_MESSAGE(ENG_CLEAR, OnClear)
	ON_MESSAGE(ENG_LAUNCH, OnLaunch)
	ON_MESSAGE(ENG_DLAUNCH, OnDLaunch)
	ON_MESSAGE(ENG_DECLIST, OnDecList)
	ON_MESSAGE(ENG_ENCODE, OnEncode)
	ON_MESSAGE(ENG_RENAME, MsgSink)
	ON_MESSAGE(ENG_RENRES, MsgSink)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Engine

Engine::Engine()
{

	ClearVars();

}


Engine::Engine(CWnd *o, UINT ctrl_id)
{

	ClearVars();				// Do basic init

	owner = o;
	m_pMainWnd = o;
	m_bAutoDelete = FALSE;		// I'll delete it

	if (!CreateThread())		// Thread create failed
	{
		MessageBox(o->m_hWnd, "Could not create thread.", "Engine Thread-Up",
			MB_ICONSTOP | MB_OK | MB_APPLMODAL);
		return;
	}

	CRect r;

	r.top = r.left = 0;
	r.bottom = r.right = 36;

	TRACE("Engine Constructor ; Thread=0x%08lX\r\n",
		m_nThreadID);

	State = ENG_IDLE;		// Got to idle state

	UD.owner = o;			// For message posting from decoder control
	UD.m_xFileAuto = FALSE;		// Delete X files manually

}


Engine::~Engine()
{
	struct decode_queue_s *np, *c;

	for (c=d_top; c != NULL; c=np)
	{
		np = c->next;
		free((void *) c->fname);
		delete c;
	}

	if (msg_lock != NULL)
		delete msg_lock;

	if (queue_lock != NULL)
		delete queue_lock;

}


//
// Set up the thread
//

BOOL Engine::InitInstance()
{

	msg_lock = new CMutex(FALSE, "EngineMessageLock");
	queue_lock = new CMutex(FALSE, "DecodeQueueLock");

	ASSERT(msg_lock != NULL);
	ASSERT(queue_lock != NULL);

	TRACE("(Create) Queue_lock = %Fp\r\n",
		queue_lock);

return TRUE;
}



//
// Load files for decoding
//

afx_msg LONG Engine::OnLoad(UINT wParam, LONG lParam)
{
	if (StopMessage())
		return(TRUE);				// Done, jump out.

	struct decode_queue_s *np;
	CSingleLock l(queue_lock, FALSE);
	int rc;

	State = ENG_READING;

	cancelFlag = false;
	UD.cancelFlag = FALSE;

	do {

		if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
		{
			ASSERT(0);
			rc = -1;
			break;
		}	

		np = d_top;

		if (np != NULL)
			d_top = np->next;				// Always pop off; resume will continue with next if at all

		l.Unlock();							// Give back access

		if (np != NULL)
		{
			owner->PostMessage(ENG_ROWCHG, np->row, 0);		// Send up the row

			rc = UD.DLoad(np->fname);

#if defined(_DEBUG)
			if (rc != CUud32acxCtrl::uudRetOK)
				TRACE("LOAD: rc = [%s] -> %d\r\n", np->fname, rc);
#endif

			free((void *) np->fname);
			delete np;						// Blow the listing away

			if (rc != CUud32acxCtrl::uudRetOK || StopMessage())
				break;						// Jump out on failure
		}

	} while (np != NULL && !cancelFlag);

	if (cancelFlag)
	{
		rc = CUud32acxCtrl::uudRetCancel;		// Send back "cancelled."
		OnCancel(1, 0);						// Reset all
	}

	State = ENG_IDLE;

	owner->PostMessage(ENG_DONE, rc, ENG_LOAD);	// Send back the return code and what we were doing

return(TRUE);							// I handle this
}


//
// Stop the Engine
//

afx_msg LONG Engine::OnStop(UINT wParam, LONG lParam)
{

	State = ENG_DYING;

	MSG m;

	int mc = 0;

	while (::PeekMessage(&m, (HWND) -1, ENG_FIRST, ENG_LAST, PM_REMOVE))
		mc++;								// Purge all messages

	m_pMainWnd = NULL;					// Belongs to NOBODY; owner will destroy self

	UD.XFileDel();						// Kill X-Files

	::PostQuitMessage(0);

return(TRUE);							// I handle this
}



//
// Write a message into the buffer
//
// Returns number of characters written
//

int Engine::SetMessage(char *format, ...)
{
	CSingleLock l(msg_lock, FALSE);

	if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
		return(0);

	va_list ap;

	va_start(ap, format);

	int nc = vsprintf(messagebuffer, format, ap);

	ASSERT(nc > 0 && nc < (MAX_PATH + 80));

	va_end(ap);

	l.Unlock();

return(nc);
}


//
// Get back the message buffer
//

bool Engine::GetMessage(CString& s)
{
	CSingleLock l(msg_lock, FALSE);

	if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
		return(false);

	s = messagebuffer;

	l.Unlock();							// Give back access

return(true);
}


//
// Add a file to decode
//

afx_msg LONG Engine::OnDecode(UINT row, LONG fname)
{
	struct decode_queue_s *np = new struct decode_queue_s;

	np->row = row;					// Row comes as wParam
	np->fname = (const char *) fname;	// Filename comes as lParam
	np->next = NULL;

	CSingleLock l(queue_lock, FALSE);

	if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
	{
		free((void *) fname);
		delete np;
		return(false);
	}

	if (d_top == NULL)
		d_top = d_next = np;
	else
	{
		d_next->next = np;
		d_next = np;
	}

	l.Unlock();							// Give back access

return(TRUE);							// I handle this
}


//
// Somebody's posted a Cancel message
//

afx_msg LONG Engine::OnCancel(UINT wParam, LONG lParam)
{

	cancelFlag = true;

	UD.cancelFlag = TRUE;

return(TRUE);
}



//
// Clear the decode list
//

afx_msg LONG Engine::OnClear(UINT rst, LONG lParam)
{
	struct decode_queue_s *np, *c;

	CSingleLock l(queue_lock, FALSE);

	if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
		return(TRUE);

	for (c=d_top; c != NULL; c=np)
	{
		np = c->next;

		free((void *) c->fname);
		delete c;
	}

	d_top = d_next = NULL;

	l.Unlock();							// Give back access

	if (rst)
		UD.Reset();							// Reset the UUD control

return(TRUE);							// I handle this
}


//
// Just launch a file
//
afx_msg LONG Engine::OnLaunch(UINT wParam, LONG elsp)
{
	struct EngineLaunch *ep = (struct EngineLaunch *) elsp;

	int rc = 0;

	if (ep->app.IsEmpty())			// Caller didn't supply an app, try to find it
		ep->app = ep->filen.FindExec();

	if (!ep->app.IsEmpty() && (StopMessage() || (rc = ep->filen.Exec(ep->app)) != 0))
	{
		CString msg;

		if (rc != 0)		// Error, not stop message
			msg.Format("Error %d executing:\r\n%s %s",
				rc, (const char *) ep->app, (const char *) ep->filen);

		MSG m;

		while (::PeekMessage(&m, (HWND) -1, ENG_LAUNCH, ENG_LAUNCH, PM_REMOVE))
			delete (struct EngineLaunch *) m.lParam;		// Clear all pending launch messages

		if (rc != 0)
			MessageBox(owner->m_hWnd, msg, "Launch", 
				MB_ICONEXCLAMATION | MB_OK | MB_APPLMODAL | MB_SETFOREGROUND);
	}

	owner->PostMessage(ENG_DONE, rc, ENG_LAUNCH);	// Let owner know how it went

	delete ep;					// Always destroy the incoming struct

return(TRUE);
}



//
// Decode and launch a file
//
afx_msg LONG Engine::OnDLaunch(UINT wParam, LONG elsp)
{
	struct EngineLaunch *ep = (struct EngineLaunch *) elsp;

	int rc = 0;

	if (ep->app.IsEmpty())			// Caller didn't supply an app, try to find it
		ep->app = ep->filen.FindExec();

	if (!ep->app.IsEmpty() && (StopMessage() || (rc = ep->filen.Exec(ep->app)) != 0))
	{
		CString msg;

		if (rc != 0)		// Error, not stopmessage
			msg.Format("Error %d executing:\r\n%s %s",
				rc, (const char *) ep->app, (const char *) ep->filen);

		MSG m;

		while (::PeekMessage(&m, (HWND) -1, ENG_LAUNCH, ENG_LAUNCH, PM_REMOVE))
			delete (struct EngineLaunch *) m.lParam;		// Clear all pending launch messages

		if (rc != 0)
			MessageBox(owner->m_hWnd, msg, "Launch", 
				MB_ICONEXCLAMATION | MB_OK | MB_APPLMODAL | MB_SETFOREGROUND);
	}

	owner->PostMessage(ENG_DONE, rc, ENG_LAUNCH);	// Let owner know how it went

	delete ep;					// Always destroy the incoming struct

return(TRUE);
}


//
// Check to see if there are any pending Stop
//  messages
//

bool Engine::StopMessage()
{
	MSG m;

return(::PeekMessage(&m, (HWND) -1, ENG_STOP, ENG_CANCEL, PM_NOREMOVE) != 0);
}



//
// Decode the list
//
afx_msg LONG Engine::OnDecList(UINT wParam, LONG elsp)
{
	if (StopMessage())
		return(TRUE);				// Done, jump out.

	struct decode_queue_s *np;
	CSingleLock l(queue_lock, FALSE);
	int rc;

	State = ENG_DECODING;

	cancelFlag = false;
	UD.cancelFlag = FALSE;

	int errct = 0;

//	RenOutFile rfBox;

	CFileName ofn;

	do {

		if (!l.Lock(5 * 60 * 1000))							// Wait for clearance
		{
			ASSERT(0);
			rc = -1;
			break;
		}	

		np = d_top;

		if (np != NULL)
			d_top = np->next;				// Always pop off

		l.Unlock();							// Give back access

		if (np != NULL)
		{
			owner->PostMessage(ENG_ROWCHG, np->row, 0);		// Send up the row

			ofn = np->fname;		// Create an output filename

			if (!OWrite && ofn.Exists())		// If overwrite mode we don't care
			{
				if (ANumber && ofn.MakeUnique())		// Autonumber
					owner->PostMessage(ENG_UPDNAME,		// Send back new filename
						(WPARAM) np->row, (LPARAM) new CString(ofn.Filename()));
				else
				{
					CString nameOnly(ofn.Filename());
					CString cpath(ofn.Path());

					bool rpt;
//					int rrc;

					do
					{
						rpt = false;		// Repeat only if rename leads to existing name

//						rrc = rfBox.Prompt(&cpath, nameOnly, &UD, owner->m_hWnd);

//						rrc = RenamePrompt(&cpath, nameOnly);

						switch (RenamePrompt(&cpath, nameOnly))
						{
							case RENOUT_RENAME:
								ofn = cpath + nameOnly;	// Add back the path
								if (ofn.Exists())
									rpt = true;		// Have to go back and rename again
								else
									owner->PostMessage(ENG_UPDNAME,
										(WPARAM) np->row, (LPARAM) new CString(nameOnly));
								break;

							// case RENOUT_OWRITE:		use existing filename

							case IDCANCEL:
								cancelFlag = true;
								UD.cancelFlag = TRUE;

							// DON'T BLOCK THIS....

							case RENOUT_SKIP:
								goto nextfile;				// Skip this file

							case RENOUT_AUTO:			// Activate auto-number
								ofn.MakeUnique();		// Make this filename unique
								ANumber = true;
								owner->PostMessage(ENG_UPDNAME,
									(WPARAM) np->row, (LPARAM) new CString(ofn.Filename()));
								owner->PostMessage(ENG_SETAUTO, TRUE);		// Notify the owner
								break;
						}

					} while (rpt);			// Loop back if rename to new name that exists
				}				// Not auto number
			}					// Not overwrite and exists

			rc = UD.DFileTo(np->row, ofn);

#if defined(_DEBUG)
			if (rc != CUud32acxCtrl::uudRetOK)
				TRACE("Decode: rc = [%s] -> %d\r\n", np->fname, rc);
#endif

			if (rc != CUud32acxCtrl::uudRetOK)
			{
				if (rc == CUud32acxCtrl::uudRetCancel)
				{
					cancelFlag = true;
					UD.cancelFlag = TRUE;
				}
				else
				{
					errct++;		// Count errors...

					if (POE)
					{						// Pause on errors
						CString emsg(UD.GetLastMessage());	// Read the error message

						if (emsg.IsEmpty())
						{
							int flags = UD.GetDFileFlags(np->row);

							if (flags & CUud32acxCtrl::uudFileMisPart)
								emsg = "Missing Parts";
							else if (flags & CUud32acxCtrl::uudFileNoBegin)
								emsg = "No \"Begin\" Found";
							else if (flags & CUud32acxCtrl::uudFileNoEnd)
								emsg = "No \"End\" Found";
							else if (flags & CUud32acxCtrl::uudFileNoData)
								emsg = "No Data Found";
							else
								emsg = "Unknown Error (?)";
						}

						CString wrk;

						wrk.Format(
							"Error Decoding File:\r\n%s\r\nCode: %d [%s]\r\nContinue?",
							np->fname, rc, (const char *) emsg);

						cancelFlag = 
								(MessageBox(
									owner->m_hWnd,
									wrk,
									"Decode Files", 
									MB_ICONQUESTION | MB_OKCANCEL | MB_APPLMODAL | MB_SETFOREGROUND) == IDCANCEL);
					}					// POE
				}						// rc <> cancel
			}							// rc <> 0

			owner->PostMessage(ENG_UPDICO, (WPARAM) np->row, (LPARAM) 0);		// Update an icon in the decode out list

nextfile:
			free((void *) np->fname);
			delete np;						// Blow the listing away
		}								// Queue loop

	} while (np != NULL && !cancelFlag && !StopMessage());

	if (!cancelFlag && IFRecycle)
		DoRecycle();

	OnClear(0, 0);					// Delete everything in the list

	State = ENG_IDLE;

//	if (rfBox.m_hWnd != NULL)
//		rfBox.DestroyWindow();		// Make sure it's dead to prevent annoying debugger messages

	owner->PostMessage(ENG_DONE, 
		(cancelFlag) ? -1 : errct, ENG_DECLIST);	// Send back the return code and what we were doing

return(TRUE);
}



//
// Fire up the encoder
//
// --> Owner is responsible for freeing control structure <--
//

afx_msg LONG Engine::OnEncode(UINT wParam, LONG encsp)
{
	struct EngineEncode *ep = (struct EngineEncode *) encsp;

	State = ENG_ENCODING;

	UD.cancelFlag = FALSE;

	VARIANT mt;
	mt.vt = VT_EMPTY;

	int rc = UD.Encode(
		ep->inFileName,
		ep->outFileName,
		ep->nameInFile,
		ep->encodeMode,
		ep->linesPerFile,
		CUud32acxCtrl::uudEncHUud, mt, mt, mt);

#if defined(_DEBUG)
	if (rc != CUud32acxCtrl::uudRetOK)
		TRACE("Encode failed = %d\r\n", rc);
#endif

	State = ENG_IDLE;

	owner->PostMessage(ENG_DONE, rc, ENG_ENCODE);

return(TRUE);
}


//
// Progress handler
//
// Owner must free structure to prevent memory leak
//

int CUud32acxCtrl::BusyCallback(uuprogress *up)
{

	uuprogress *np = new uuprogress;

	*np = *up;

	owner->PostMessage(ENG_PROGRESS, 0, (LPARAM) np);

return(cancelFlag);
}


//
// Message handler
//
// Owner must free structure to prevent memory leak
//

void CUud32acxCtrl::MessageHandler(char *msg, int level)
{

	owner->PostMessage(ENG_MESSAGE, level, (LPARAM) new CString(msg));

}


//
// Set up basic engine variables
//

void Engine::ClearVars()
{

	msg_lock = queue_lock = NULL;

	d_top = d_next = NULL;

	State = ENG_UNINIT;

	owner = NULL;

	POE = false;

	OWrite = false;

	ANumber = false;

	IFRecycle = false;

}



//
// Recycle the input files we got something from
//

void Engine::DoRecycle()
{
	uulist *liter;
	uufile *fiter;

	CString acc;

	void *junk = NULL;

	CMapStringToPtr dupList;

	const char *fname;

    for (liter = UD.GetUulp(0); liter != NULL; liter = liter->NEXT)
		if (liter->state & UUFILE_DECODED) 
			for (fiter = liter->thisfile; fiter != NULL; fiter = fiter->NEXT) 
				if (fiter->data && (fname = fiter->data->sfname) != NULL && 
					!dupList.Lookup(fname, junk)) 
				{
					acc += fname;
					acc += EOS;

					dupList.SetAt(fname, junk);
				}

	if (acc.IsEmpty())			// Nothing to do
		return;

	SHFILEOPSTRUCT sfo;

	ZeroMemory(&sfo, sizeof(sfo));		// Clear the structure

	acc += EOS;			// Extra null at end

	sfo.wFunc = FO_DELETE;
	sfo.pFrom = acc;
	sfo.fFlags = FOF_ALLOWUNDO | FOF_FILESONLY;
	sfo.lpszProgressTitle = "Remove decoded files";

	SHFileOperation(&sfo);

}



//
// Forward the prompt request to the UI thread
//

int Engine::RenamePrompt(CString *path, CString &name)
{
	EngineRename er;

	er.path = *path;
	er.nameOnly = name;
	er.UD = &UD;

	owner->PostMessage(ENG_RENAME, 0, (LPARAM) &er);		// Send the rename message

	int rc = IDCANCEL;

	MSG m;

	bool brk = false;

	while (!brk && WaitMessage())
		while (!brk && PeekMessage(&m, (HWND) -1, ENG_FIRST, ENG_LAST, PM_NOREMOVE))
			switch (m.message)
			{
				case ENG_STOP:
				case ENG_CANCEL:
					return(IDCANCEL);

				case ENG_RENRES:
					brk = true;
					rc = m.wParam;			// Grab return code from message that was sent back
					PeekMessage(&m, (HWND) -1, ENG_RENRES, ENG_RENRES, PM_REMOVE);
					break;
			}

	if (rc != IDCANCEL)
		name = er.nameOnly;					// Send back the name

return(rc);
}



//
// Sink for messages used by engine but that we should 
//	never see -- normally retrieved by PeekMessage
//

afx_msg LONG Engine::MsgSink(UINT wParam, LONG lParam)
{

	return(TRUE);

}



//
// Set the engine's temporary folder
//

void Engine::SetTemp(CString &newTFolder)
{

	UD.m_tempFolder = newTFolder;

}


//
// Use Windows temporary folder
//

void Engine::WinTemp()
{

	UD.m_tempFolder.Empty();

}
