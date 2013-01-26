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


// Uud32.cpp : Main app file
//

#include "stdafx.h"
#include "Uud32.h"
#include "Uud32Dlg.h"
#include "UUDCommand.h"

#include "shlobj.h"				// Needed for Directory Browser

#include "hlp\decode.hh"
#include "hlp\encode.hh"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CUud32App

BEGIN_MESSAGE_MAP(CUud32App, CWinApp)
	//{{AFX_MSG_MAP(CUud32App)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUud32App construction

CUud32App::CUud32App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CUud32App object

CUud32App theApp;

/////////////////////////////////////////////////////////////////////////////
// CUud32App initialization

BOOL CUud32App::InitInstance()
{
//	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	paramList = NULL;			// Clear the parameter list
	paramCount = 0;

	CLMode = false;				// Not command line mode yet

	UUDCommand udc;

	ParseCommandLine(udc);		// Grab the parameters

#if defined(_DEBUG)				// Point to working help file
	free((void *) m_pszHelpFilePath);
	m_pszHelpFilePath = strdup("H:\\My Documents\\Utilities\\Vc\\Uud32\\hlp\\UUD32.HLP");
#endif

	CUud32Dlg dlg;
	m_pMainWnd = &dlg;
	pDialog = &dlg;				// Convenience pointer

	dlg.DoModal();

	if (dlg.m_hWnd != NULL)
		dlg.DestroyWindow();	// Explicit destroy to silence annoying messages from debugger

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
return FALSE;
}


//
// Browse for directories
//
// Returns true if a directory was chose
//

bool BrowseForDir(
CString& dirname,							// Return for directory
const char *lpPrompt,						// Prompt string
CWnd *owner)								// Owner of dialog
{
	LPMALLOC pMalloc;
	bool rc = false;

	/* Gets the Shell's default allocator */
	if (::SHGetMalloc(&pMalloc) == NOERROR) {
		BROWSEINFO bi;
		TCHAR pszBuffer[MAX_PATH];
		LPITEMIDLIST pidl;
		LPITEMIDLIST  dpidl;
		LPSHELLFOLDER pDesktopFolder;
		TCHAR          szPath[MAX_PATH];
		OLECHAR       olePath[MAX_PATH];
		ULONG         chEaten;
		ULONG         dwAttributes;
		HRESULT       hr;

//		lstrcpy(szPath, csDir);
		szPath[0] = EOS;

		if (SUCCEEDED(::SHGetDesktopFolder(&pDesktopFolder))) {
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, szPath, -1, olePath,
				MAX_PATH);

			// Convert the path to an ITEMIDLIST.
			hr = pDesktopFolder->ParseDisplayName(NULL, NULL, olePath, 
				&chEaten, &dpidl, &dwAttributes);

			// pidl now contains a pointer to an ITEMIDLIST for dir. This ITEMIDLIST
			// needs to be freed using the IMalloc allocator returned from SHGetMalloc().

			// Get help on BROWSEINFO struct - it's got all the bit settings.
			bi.hwndOwner = owner->GetSafeHwnd();
			bi.pidlRoot = NULL; // dpidl;
			bi.pszDisplayName = pszBuffer;
			bi.lpszTitle = lpPrompt;
			bi.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
			bi.lpfn = NULL;
			bi.lParam = 0;

			// This next call issues the dialog box.
			if ((pidl = ::SHBrowseForFolder(&bi)) != NULL) {
				if (::SHGetPathFromIDList(pidl, pszBuffer)) {
					// At this point pszBuffer contains the selected path */.
					dirname = pszBuffer;		// Copy to list box
					rc = true;
				}
				// Free the PIDL allocated by SHBrowseForFolder.
				pMalloc->Free(pidl);
			}

			pMalloc->Free(dpidl);

			// Release the shell's allocator.
			pMalloc->Release();
		}
	}

return(rc);
}



/**/
/**
*
* FExist checks to see if a file already exists.
*
* It returns TRUE if the file exists.
*
**/

bool FExist(
const char *filename)
{

if (GetFileAttributes(filename) == 0xFFFFFFFF &&	// Couldn't read attributes (good!)
	GetLastError() == ERROR_FILE_NOT_FOUND)
	return(false);					// File doesn't exist

return(true);
}



//
// TrundleMessages handles messages that come in during lengthy
//  processing
//

int TrundleMessages(HWND hw)
{
	MSG msg;
	int mc = 0;

    while (::PeekMessage( &msg, hw, 0, 0, PM_NOREMOVE)) 
	{
        theApp.PumpMessage();
		mc++;
	}

return(mc);
}



//
// Add a parameter to the list
//

void CUud32App::AddParam(BOOL bFlag, LPCTSTR sparam)
{
	struct UUDParams *np = new struct UUDParams;

	np->flag = bFlag;
	np->param = sparam;
	np->next = NULL;

	if (paramList == NULL)
		paramList = paramLast = np;
	else
	{
		paramLast->next = np;
		paramLast = np;
	}

	paramCount++;

	if (bFlag)
		CLMode = true;				// We are in command-line mode

}



//
// Destroy the parameter list
//

int CUud32App::ExitInstance() 
{
	struct UUDParams *np, *c;

	for (c=paramList; c != NULL; c=np)
	{
		np = c->next;
		delete c;
	}
	
return(CWinApp::ExitInstance());
}


//
// Get a parameter based on the index
//
// Returns True if it worked
//

bool CUud32App::GetParam(int index, BOOL& flg, CString& parm)
{
	struct UUDParams *c = paramList;

	while (index-- > 0 && c != NULL)
		c = c->next;

	if (c == NULL)
		return(false);

	flg = c->flag;
	parm = c->param;

return(true);
}



//
// WinHelp hack
//

void CUud32App::WinHelp(DWORD dwData, UINT nCmd) 
{

	// Really hideous hack to handle "Help" from File Open dialog
	//  boxes
	if (dwData == 0x20066 && nCmd == HELP_CONTEXT)
		switch (pDialog->m_Mode.GetCurSel())
		{
			case DECODE_PAGE:			// Decode
				dwData = Decoding;
				break;

			case ENCODE_PAGE:						// Encode
				dwData = Encoding;
				break;
		}

	CWinApp::WinHelp(dwData, nCmd);

}

