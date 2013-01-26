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


// EncodeDlg.cpp : implementation file for Encode Dialog Box
//

#include "stdafx.h"
#include "Uud32.h"
#include "EncodeDlg.h"
#include "FileName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
// --------------------------------------------------
//

// Encoding Schemes
#define ENC_64		0
#define ENC_UU		1
#define ENC_XX		2
#define ENC_Y		3

// Output Modes
#define ENC_SINGLE	0
#define ENC_SPLIT	1
#define ENC_CLIP	2

//
// CSizeTable table
//
#include "hlp\encode.hh"

static struct CSizeDialog::DialogSizerInit ds_list[] ={
	{ 2,					DSZ_SET_D,					2	},	// Set dividers
	{ IDC_ENCODEGO,			DSZ_MOVEX_D,				Encode_Context,
		IDS_ENCODEGO	},
	{ IDC_ENCSRC,			DSZ_SIZEW,					Encode_Context,
		IDS_ENCSRC	},
	{ IDC_ENCSRCBROWSE,		DSZ_MOVEX,					Encode_Context,
		IDS_ENCSRCBROWSE	},
	{ IDC_ENCINFO,			DSZ_SIZEW,					0	},
	{ IDC_ENCINFOFRAME,		DSZ_SIZEW,					0	},
	{ IDC_LABELLINES,		DSZ_MOVEX,					Encode_Context	},
	{ IDC_ENCPROG,			DSZ_SIZEW,					0	},
	{ IDC_ENC64,			DSZ_NONE,					Encode_Context,
		IDS_ENC64	},
	{ IDC_ENCUU,			DSZ_NONE,					Encode_Context,
		IDS_ENCUU	},
	{ IDC_ENCXX,			DSZ_NONE,					Encode_Context,
		IDS_ENCXX	},
	{ IDC_OMFRAME,			DSZ_MOVEX,					0	},
	{ IDC_ENCSINGLE,		DSZ_MOVEX,					Encode_Context,
		IDS_ENCSINGLE	},
	{ IDC_ENCBRK,			DSZ_MOVEX,					Encode_Context,
		IDS_ENCBRK	},
	{ IDC_ENCCLIP,			DSZ_MOVEX,					Encode_Context,
		IDS_ENCCLIP	},
	{ IDC_ENCLINES,			DSZ_MOVEX,					Encode_Context,
		IDS_ENCLINES	},
	{ IDC_ENCDEST,			DSZ_SIZEW,					Encode_Context,
		IDS_ENCDEST	},
	{ IDC_ENCPATH,			DSZ_MOVEX,					Encode_Context,
		IDS_ENCPATH	},
	{ IDC_ENCGETHELP,		DSZ_MOVEX_D,				Encode_Context,
		IDS_ENCGETHELP	},
	{ IDC_SCHEMEFRAME,		DSZ_NONE,					0,
		0			},
	{ -1 }						// End of table marker
	};

//
// --------------------------------------------------
//

BEGIN_MESSAGE_MAP(EncodeDlg, CSizeDialog)
	//{{AFX_MSG_MAP(EncodeDlg)
	ON_BN_CLICKED(IDC_ENCODEGO, OnEncodego)
	ON_BN_CLICKED(IDC_ENCSINGLE, OnEncSingle)
	ON_BN_CLICKED(IDC_ENCCLIP, OnEncClip)
	ON_BN_CLICKED(IDC_ENCBRK, OnEncBrk)
	ON_EN_SETFOCUS(IDC_ENCINFO, OnSetfocusEncInfo)
	ON_EN_CHANGE(IDC_ENCSRC, OnChangeEncSrc)
	ON_BN_CLICKED(IDC_ENCUU, OnEncUU)
	ON_BN_CLICKED(IDC_ENCXX, OnEncXX)
	ON_BN_CLICKED(IDC_ENC64, OnEnc64)
	ON_BN_CLICKED(IDC_ENCPATH, OnEncPath)
	ON_EN_CHANGE(IDC_ENCDEST, OnChangeEncDest)
	ON_BN_CLICKED(IDC_ENCSRCBROWSE, OnEncSrcBrowse)
	ON_BN_CLICKED(IDC_ENCGETHELP, OnEncGetHelp)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_ENCYY, OnEncY)
	//}}AFX_MSG_MAP
	ON_MESSAGE(ENG_DONE, OnEngineDone)
	ON_MESSAGE(ENG_INFOPAINT, OnInfoPaint)
	ON_MESSAGE(ENG_MESSAGE, OnMessage)
	ON_MESSAGE(ENG_PROGRESS, OnProgress)
	ON_MESSAGE(MSG_CMDLINE, OnCommandLine)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// EncodeDlg dialog


EncodeDlg::EncodeDlg(CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, EncodeDlg::IDD, NULL, pParent, 0, 0 /* MINW */, 0 /* Minh */)
{
	//{{AFX_DATA_INIT(EncodeDlg)
	m_EncScheme = -1;
	m_OutMode = -1;
	m_EncLines = 0;
	m_EncDest = _T("");
	m_EncSrc = _T("");
	//}}AFX_DATA_INIT

	encoder = NULL;

}


void EncodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EncodeDlg)
	DDX_Control(pDX, IDC_ENCGETHELP, m_GetHelp);
	DDX_Control(pDX, IDC_ENCSRCBROWSE, m_EncSrcBrowse);
	DDX_Control(pDX, IDC_ENCINFO, m_EncInfoBox);
	DDX_Control(pDX, IDC_ENCSRC, m_EncSrcBox);
	DDX_Control(pDX, IDC_ENCPATH, m_EncPath);
	DDX_Control(pDX, IDC_ENCDEST, m_EncDestBox);
	DDX_Control(pDX, IDC_ENCLINES, m_EncLineCtrl);
	DDX_Control(pDX, IDC_ENCODEGO, m_EncodeGo);
	DDX_Control(pDX, IDC_ENCPROG, m_ProgBar);
	DDX_Radio(pDX, IDC_ENC64, m_EncScheme);
	DDX_Radio(pDX, IDC_ENCSINGLE, m_OutMode);
	DDX_Text(pDX, IDC_ENCLINES, m_EncLines);
	DDV_MinMaxInt(pDX, m_EncLines, 100, 99999);
	DDX_Text(pDX, IDC_ENCDEST, m_EncDest);
	DDV_MaxChars(pDX, m_EncDest, 256);
	DDX_Text(pDX, IDC_ENCSRC, m_EncSrc);
	DDV_MaxChars(pDX, m_EncSrc, 256);
	//}}AFX_DATA_MAP
}

EncodeDlg::~EncodeDlg()
{

	if (encoder != NULL)
		delete encoder;

}


/////////////////////////////////////////////////////////////////////////////
// EncodeDlg message handlers

//
// Dialog setup
//

BOOL EncodeDlg::OnInitDialog()
{
	BOOL rc = CSizeDialog::OnInitDialog();

	allowOverwrite = false;		// Start with command-line overwrite option cleared

	m_EncodeGo.Disable();		// Go not enabled until a name exists

	m_ProgBar.SetPos(0);		// Progress bar is at 0

	CUud32App *pApp = (CUud32App *) AfxGetApp();

	if (pApp->GetCLMode())			// Command line mode
	{
		char wrk[_MAX_PATH + 16];

		GetCurrentDirectory(_MAX_PATH, wrk);

		m_EncDest = wrk;

		m_EncScheme = 0;

		m_OutMode = 0;

		m_EncLines = 1000;

		UpdateData(FALSE);
	}
	else
	{
		ri.Start(REG_BASE, REG_VNO, "encode");		// Set up RegINI for encode

		SaveState(false);			// Retrieve the saved state info
	}

	EnableToolTips();

	m_GetHelp.SetIcon(AfxGetApp()->LoadIcon(IDI_QMARK));

	dlgName = "Encode";		// Set the name for debugging

return(rc);
}



//
// Save/Restore info from Registry
//

void EncodeDlg::SaveState(bool write)
{

	int scheme, outmode, lines;

	if (write)
	{
		UpdateData();			// Make sure we have the latest from the form

		scheme = m_EncScheme;
		outmode = m_OutMode;
		lines = m_EncLines;

		CFileName cfn;	// Peek at the source to get its path

		if (!m_EncSrc.IsEmpty())
		{
			cfn = m_EncSrc;
			srcDir = cfn.Path();	// Read back the path
		}

		if (!m_EncDest.IsEmpty())
		{
			cfn = m_EncDest;		// Same for output
			cfn.DirCheck();		// Watch out for path only
			destDir = cfn.Path();
		}
	}

	bool scheme_read = ri.BiDir("Scheme", scheme, write);

	bool om_read = ri.BiDir("OutMode", outmode, write);

	ri.BiDir("Lines", lines, write);

	ri.BiDir("SourceDir", srcDir, write);

	ri.BiDir("Dest", destDir, write);

	ri.Close();

	if (!write)
	{
		m_EncDest = destDir;

		m_EncScheme = (scheme_read) ? scheme : 1;

		m_OutMode = (om_read) ? outmode : 0;

		m_EncLines = (lines < 100) ? 1000 : lines;

		UpdateData(FALSE);			// Transfer updated vars to form

		switch (m_OutMode)		// Do button enables
		{
			case ENC_SINGLE:
				OnEncSingle();
				break;

			case ENC_SPLIT:
				OnEncBrk();
				break;

			case ENC_CLIP:
				OnEncClip();
				break;
		}
	}

}



//
// Various button pushes
//

void EncodeDlg::OnEncSingle() 
{

	m_EncLineCtrl.EnableWindow(FALSE);	// Shut off the "break lines" box
	m_EncDestBox.EnableWindow();	// Destination box is on
	m_EncPath.Enable();				// Path button on

}

void EncodeDlg::OnEncClip() 
{

	m_EncLineCtrl.EnableWindow(FALSE);	// Shut off the "break lines" box
	m_EncDestBox.EnableWindow(FALSE);	// Destination box is off
	m_EncPath.Disable();			// Path button off
	
}

void EncodeDlg::OnEncBrk() 
{

	m_EncLineCtrl.EnableWindow();	// Turn on the "break lines" box
	m_EncDestBox.EnableWindow();	// Destination box is on
	m_EncPath.Enable();				// Path button on
	
}


//
// User clicked in the Encode Info box, display the file info
//

void EncodeDlg::OnSetfocusEncInfo() 
{

	CString fileName;

	m_EncSrcBox.GetWindowText(fileName);		// Read the filename

	CFile fs;
	CFileStatus fstat;

	CString wrk;

	if (fs.GetStatus(fileName, fstat))
	{
		wrk.Format("%s --> %d bytes, %s", (const char *) fileName,
			fstat.m_size, 
			(const char *) fstat.m_mtime.Format("%m/%d/%y %H:%M:%S"));
		m_EncInfoBox.SetWindowText(wrk);
	}
	
}


//
// The source filename has changed
//
// Turn the Go button on if both filenames are non-null or the source
//  is non-null and the scheme is "To Clipboard"
//

void EncodeDlg::OnChangeEncSrc() 
{

	UpdateData();

	if (!m_EncSrc.IsEmpty() && (!m_EncDest.IsEmpty() || m_EncScheme == 2))
		m_EncodeGo.Enable();
	else
		m_EncodeGo.Disable();
	
}


//
// Encoding scheme has changed; have to change the default output file
//

void EncodeDlg::OnEncUU() 
{

	SetETO();
	
}

void EncodeDlg::OnEncXX() 
{

	SetETO();
	
}

void EncodeDlg::OnEnc64() 
{

	SetETO();
	
}


void EncodeDlg::OnEncY() 
{
	
	SetETO();

}

//
// Figure out the Output filename
//

void EncodeDlg::SetETO()
{

	UpdateData();

	if (m_EncSrc.IsEmpty())
		return;							// Nothing to do

	CFileName eto;

	if (m_EncDest.IsEmpty())
		eto = m_EncSrc;					// Default to the input file
	else
	{
		CFileName cfn(m_EncSrc);		// Get the current output

		eto = m_EncDest;

		eto.DirCheck();					// Watch for directory-only

		eto.SetFilename(cfn.Filename());	// Add the filename
	}

	switch (m_EncScheme)
	{
		case ENC_64:
			eto.SetExt("b64");
			break;

		case ENC_UU:
			eto.SetExt("uue");
			break;

		case ENC_XX:
			eto.SetExt("xxe");
			break;

		case ENC_Y:
			eto.SetExt("ntx");
			break;
	}

	m_EncDestBox.SetWindowText(eto);

}


//
// User wants to select a new path
//

void EncodeDlg::OnEncPath() 
{

	CString newpath;

	if (BrowseForDir(newpath, "Select Encoding Output Directory", this))
	{
		m_EncDestBox.SetWindowText(newpath);
		SetETO();
	}
	
}


//
// The encode-to destination has been updated
//

void EncodeDlg::OnChangeEncDest() 
{

	OnChangeEncSrc();
	
}


//
// Browse for the source file
//

void EncodeDlg::OnEncSrcBrowse() 
{
	CFileDialog openFile(
		TRUE,					// OPEN
		NULL,					// Default extension
		NULL,					// Initial filename
		OFN_EXPLORER | OFN_FILEMUSTEXIST |
		  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_SHOWHELP,		// Flags
	    "All Files|*.*||",
		NULL);				// Owner is ME

	openFile.m_ofn.lpstrTitle = "Select File to Encode";

	CFileName cfn;
	CString spath;

	m_EncSrcBox.GetWindowText(cfn.GetStr());		// Read the current path

	if (!cfn.IsEmpty())		// Got a place to start
	{
		cfn.DirCheck();

		spath = cfn.Path();		// Read the path

		openFile.m_ofn.lpstrInitialDir = (const char *) spath;
	}
	else if (!srcDir.IsEmpty())		// Default from the Registry
		openFile.m_ofn.lpstrInitialDir = (const char *) srcDir;

	if (openFile.DoModal() == IDOK)
	{
		m_EncSrcBox.SetWindowText(openFile.GetPathName());
		OnSetfocusEncInfo();		// Update info
		SetETO();
	}
	
}



//
// Implement the "waiting" mode
//

void EncodeDlg::HourGlass(bool on)
{

	if (on)
	{
		EnablePushExcept(FALSE, IDC_ENCODEGO, IDC_ENCINFOFRAME, 
			IDC_ENCINFO, IDC_ENCPROG, 0);

		m_EncodeGo.SetLabel(IDS_CANCELBUTTON);

		GetParent()->PostMessage(WAIT_CURSOR, TRUE, 0);		// Turn on the wait cursor
	}
	else
	{
		UnStackEnabled(TRUE);

		m_EncodeGo.SetLabel(IDS_GO);

		GetParent()->PostMessage(WAIT_CURSOR, FALSE, 0);		// Turn off the wait cursor

		m_ProgBar.RedrawWindow();
	}

}


//
// Write a line to the status box
//

void EncodeDlg::Info(const char * newinfo)
{

	m_EncInfoBox.SetWindowText(newinfo);
	m_EncInfoBox.UpdateWindow();

}


//
// Handle files dropped from Explorer
//

void EncodeDlg::OnDropFiles(HDROP hDropInfo)
{
	if (::DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0) != 1)	// Read count
	{
		MessageBox("You can only drop 1 file at a time\r\non the Encode window.",
			"Encode", MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	char fbuf[MAX_PATH + 1];
	CFileStatus fsta;

	::DragQueryFile(hDropInfo, 0, fbuf, MAX_PATH);

	if (CFile::GetStatus(fbuf, fsta) && (fsta.m_attribute & CFile::directory))
	{
		CString wrk;

		wrk.Format("\"%s\" is a directory, not a file.", fbuf);
			
		MessageBox(wrk, "Encode", MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	m_EncSrcBox.SetWindowText(fbuf);
	SetETO();								// Create default filename

}


//
// Trip the context help
//

void EncodeDlg::OnEncGetHelp() 
{

	OnContextHelp();
	
}


//
// Reflect message from Engine thread
//
#if SKIP
afx_msg void EncodeDlg::OnReflectProgress(
long CurrentAction, 
BSTR FAR* CurrentFile, 
short PartNo, 
short TotalParts, 
long CurrentFileSize, 
short Percent, 
BOOL FAR* Cancel)
{

	if (encoder->StopMessage())				// There's a STOP or CANCEL in the queue
	{
		*Cancel = TRUE;
		return;
	}

	switch (CurrentAction)
	{
		case CUud32acxCtrl::uudActNewStep:
			newStep = true;
			return;

		case CUud32acxCtrl::uudActEncoding:
			if (newStep || PartNo != oldPart)
			{
				CString cf(*CurrentFile);

				cf.MakeLower();

				encoder->SetMessage("Writing %s [Part %d/%d]",
					(const char *) cf, PartNo, TotalParts);

				PostMessage(ENG_INFOCHG, 0, 0);		// Info has changed

				oldPart = PartNo;
				newStep = false;
			}
			break;
	}

	PostMessage(ENG_PERCENT, Percent, 0);	// Percent has changed

}
#endif


//
// Job is done
//

LONG EncodeDlg::OnEngineDone(WPARAM rc, LPARAM action)
{

	HourGlass(false);

	if (rc == CUud32acxCtrl::uudRetExists)
	{
		if (!allowOverwrite && MessageBox("Overwrite existing output files?", "Encode", 
				MB_OKCANCEL | MB_ICONQUESTION) == IDCANCEL)
		{
			m_ProgBar.SetPos(0);
			return(TRUE);
		}
		encoder->UD.m_overwrite = TRUE;		// Allow overwriting now...
		HourGlass(true);
		encoder->PostThreadMessage(ENG_ENCODE, 0, (LPARAM) &ees);
		return(TRUE);
	}

	m_ProgBar.SetPos(0);

	if (rc == CUud32acxCtrl::uudRetCancel)
	{
		Info("Cancelled.");
		return(TRUE);
	}
	else if (rc != CUud32acxCtrl::uudRetOK)
	{
		Info(encoder->UD.GetLastMessage());
		return(TRUE);
	}

	Info("Done.");

	if (m_OutMode == ENC_CLIP)
	{
		HourGlass(true);

		int brc = encoder->UD.ClipboardFile(
			(long) GetTopLevelParent()->m_hWnd, ees.outFileName, 0);

		HourGlass(false);

		if (!brc)
		{
			MessageBox("Couldn't place encoded data on clipboard.", "Encode",
				MB_ICONEXCLAMATION | MB_OK);
			Info("Error!");
		}
		else
			MessageBox("Encoded file on clipboard.", "Encode", MB_OK);
	}

return(TRUE);
}



//
// Actual encoding routine
//
void EncodeDlg::OnEncodego() 
{

	if (!EngineSetup())
		return;							// Couldn't start engine thread

	if (encoder->State == Engine::ENG_ENCODING)
	{
		encoder->PostThreadMessage(ENG_CANCEL, 0, 0);
		encoder->UD.cancelFlag = TRUE;
		return;
	}

	UpdateData();						// Pull in all the information

	long lines;
	CFileName outfile;
	int encodingFlag;

	switch (m_EncScheme)
	{
		case ENC_64:
			encodingFlag = CUud32acxCtrl::uudEncB64;
			break;

		case ENC_UU:
			encodingFlag = CUud32acxCtrl::uudEncUU;
			break;

		case ENC_XX:
			encodingFlag = CUud32acxCtrl::uudEncXX;
			break;

		case ENC_Y:
			encodingFlag = CUud32acxCtrl::uudEncyEnc;
			break;
	}

	switch (m_OutMode)
	{
		case ENC_SINGLE:
			lines = 0;
			outfile = m_EncDest;
			break;

		case ENC_SPLIT:
			lines = m_EncLines;
			if (lines < 100)
			{
				MessageBox("Illegal number of lines per file.", "Encode",
					MB_ICONEXCLAMATION | MB_OK);
				return;
			}
			outfile = m_EncDest;
			break;

		case ENC_CLIP:
			lines = 0;
			outfile.Temp("uue");		// This will be our temp output
			outfile.XFile();			// Delete it later
			break;
	}

	HourGlass(true);

	encoder->UD.m_overwrite = (m_OutMode == ENC_CLIP);		// Overwrite for clipboard only

	CFileName ofn(m_EncSrc);

	ees.inFileName = m_EncSrc;
	ees.outFileName = outfile;
	ees.nameInFile = ofn.Filename();
	ees.encodeMode = encodingFlag;
	ees.linesPerFile = lines;

	encoder->PostThreadMessage(ENG_ENCODE, 0, (LPARAM) &ees);

}



//
// Set up the decoder engine
//

bool EncodeDlg::EngineSetup()
{
	if (encoder == NULL)
	{
		encoder = new Engine(this, UD_EID);

		if (encoder == NULL ||		// Still null
			encoder->State != Engine::ENG_IDLE)		// Spin-up failed
		{
			ArgMessageBox("UUDeview Encode Go", MB_ICONSTOP | MB_OK,
				"Could not create engine thread, error=%d",
				GetLastError());
			return(false);
		}
	}

return(true);
}


//
// Make sure the encoder thread gets shut down
//

void EncodeDlg::OnDestroy() 
{
	
	if (encoder != NULL && encoder->m_hThread != NULL && encoder->State != Engine::ENG_DYING) 
	{
		encoder->PostThreadMessage(ENG_CANCEL, 0, 0);	// Make sure it stops
		encoder->PostThreadMessage(ENG_STOP, 0, 0);

		WaitForSingleObject(encoder->m_hThread, 5000);
	}

	CSizeDialog::OnDestroy();
}



//
// Repaint progress controls during activation if the
//  background thread is running
//

void EncodeDlg::Activate()
{

	if (encoder != NULL && (encoder->State > Engine::ENG_IDLE))
	{
		encoder->SuspendThread();		// Stop the engine so we can paint

		PostMessage(ENG_INFOPAINT, 0, 0);	// Restart after processing updates
	}

}


//
// Repaint the window after all the update messages have been posted,
//  then restart the engine thread
//

afx_msg LONG EncodeDlg::OnInfoPaint(WPARAM w, LPARAM l)
{

	GetTopLevelParent()->RedrawWindow();

	encoder->ResumeThread();

return(TRUE);
}


//
// Handle Progress messages
//

afx_msg LONG EncodeDlg::OnProgress(WPARAM wParam, LPARAM uuptr)
{
	uuprogress *up = (uuprogress *) uuptr;

	if (encoder->StopMessage())				// There's a STOP or CANCEL in the queue
	{
		delete up;
		return(TRUE);
	}

	switch (up->action)
	{
		case CUud32acxCtrl::uudActNewStep:
			newStep = true;
			break;

		case CUud32acxCtrl::uudActEncoding:
			if (newStep || up->partno != oldPart)
			{
				CString wrk;

				wrk.Format("Writing %s [Part %d/%d]",
					strlwr(up->curfile), up->partno, up->numparts);

				oldPart = up->partno;
				newStep = false;
			}
			break;

	}

	m_ProgBar.SetPos(up->percent);

	delete up;						// Done with info structure

return(TRUE);
}


//
// Message are absorbed
//

afx_msg LONG EncodeDlg::OnMessage(WPARAM Level, LPARAM np)
{

	delete (CString *) np;

return(TRUE);
}



//
// Handle Command Line messages
//

afx_msg LONG EncodeDlg::OnCommandLine(WPARAM wParam, LPARAM lParam)
{
	CString *param = (CString *) lParam;

	bool rc = true;

	int offset = 0;

#if SKIP
	CString wrk;

	wrk.Format("Mode: %c, Param: %s",
		wParam, (const char *) *param);

	MessageBox(wrk, "OnCommandLine", MB_OK);
#endif

	if (param->IsEmpty())			// This is a flag by itself
		switch (wParam)
		{
			case 'g':				// Go!
				OnEncodego();
				break;
		}
	else							// Not a flag but a parameter
	{
		bool eto = true;

		switch (wParam)
		{
			case 'a':				// Add (source file)
			case 'e':				// Enter "Add" mode after /e for Encode
				m_EncSrcBox.SetWindowText(*param);
				break;

			case 'l':				// Every n lines
				rc = CLSetLines(*param);
				break;

			case 'o':				// Set options
				rc = CLSetOptions(*param);
				break;

			case 'p':				// Path
				m_EncDestBox.SetWindowText(*param);
				break;

			default:
				eto = false;
				break;
		}

		if (eto)
			SetETO();
	}

	delete param;			// Always delete the string sent from the parent window

	if (rc)
		GetParent()->PostMessage(MSG_CMDNEXT, offset);	// Move on to next item

return(TRUE);
}



//
// Set options from command line string
//

bool EncodeDlg::CLSetOptions(const char *oList)
{
	const char *p;

	UpdateData();

	for (p=oList; *p != EOS; p++)
		switch (*p)
		{
			case 'b':			// Base64
				m_EncScheme = 0;
				break;

			case 'c':			// To clipboard
				m_OutMode = 2;
				break;

			case 'l':			// Every n lines
				m_OutMode = 1;
				break;

			case 's':			// Single file
				m_OutMode = 0;
				break;

			case 'o':			// Overwrite mode
				allowOverwrite = true;
				break;

			case 'u':			// UU
				m_EncScheme = 1;
				break;

			case 'x':			// XX
				m_EncScheme = 2;
				break;

		}

	UpdateData(FALSE);

return(true);
}



//
// Set number of lines from command line
//

bool EncodeDlg::CLSetLines(const char *nLines)
{
	int n = atol(nLines);

	if (n > 100 && n < 9999)
	{
		UpdateData();

		m_OutMode = 1;			// Switch to every n lines mode

		m_EncLines = n;

		UpdateData(FALSE);
	}

return(true);
}

