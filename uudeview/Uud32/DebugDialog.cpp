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


// DebugDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Uud32.h"
#include "DebugDialog.h"

#include "hlp\decopt.hh"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
// -------------------------------------
//
//
// Dialog autosizer info
//

static struct CSizeDialog::DialogSizerInit ds_list[] ={
	{ IDOK,				DSZ_NONE,					0	},
	{ IDC_CLEARDEBUG,	DSZ_NONE,					0	},
	{ IDC_DEB2CLIP,		DSZ_NONE,					0	},
	{ IDC_INFOHELP,		DSZ_MOVEX,					0	},
	{ IDC_INFODEBUG,	DSZ_SIZEW | DSZ_SIZEH,		0	},
	{ -1 }						// End of table marker
	};

static char *rini_name = "DebugPosn";

//
// Message Map
//

BEGIN_MESSAGE_MAP(DebugDialog, CSizeDialog)
	//{{AFX_MSG_MAP(DebugDialog)
	ON_BN_CLICKED(IDC_CLEARDEBUG, OnClearDebug)
	ON_BN_CLICKED(IDC_DEB2CLIP, OnDeb2Clip)
	ON_BN_CLICKED(IDC_INFOHELP, OnInfoHelp)
	//}}AFX_MSG_MAP
	ON_MESSAGE(DEBOX_ADD, OnAdd)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DebugDialog dialog


DebugDialog::DebugDialog(CRect *rp, CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, DebugDialog::IDD, rp, pParent, IDI_UUDEBUG, 0, 0)
{
	//{{AFX_DATA_INIT(DebugDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	LONG dbu = GetDialogBaseUnits();
	int hdbu = (dbu & 0xFFFF);			// Horiz dialog base units
	int vdbu = (dbu >> 16) & 0xFFFF;	// Vert dialog base units

	if (vdbu == 20 && hdbu == 10)		// Large fonts
	{
		min_w = 500;
		min_h = 180;
	}
	else if (vdbu = 16 && hdbu == 8)	// Small fonts
	{
		min_w = 386;
		min_h = 121;
	}
	else 								// Calculate size
	{
		// pixelX = (templateunitX * baseunitX) / 4 
		// pixelY = (templateunitY * baseunitY) / 8

		min_w = (200 * hdbu) / 4;
		min_h = (72 * vdbu) / 8;
	}

}


void DebugDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DebugDialog)
	DDX_Control(pDX, IDOK, m_Close);
	DDX_Control(pDX, IDC_DEB2CLIP, m_ToClip);
	DDX_Control(pDX, IDC_CLEARDEBUG, m_Clear);
	DDX_Control(pDX, IDC_INFODEBUG, m_Info);
	//}}AFX_DATA_MAP
}


/////////////////////////////////////////////////////////////////////////////
// DebugDialog message handlers


//
// Clear the dialog box
//

void DebugDialog::OnClearDebug() 
{

	m_Info.SetWindowText("");
	m_Info.UpdateWindow();
	
}


//
// Copy the text to the clipboard
//
void DebugDialog::OnDeb2Clip() 
{

	if (m_Info.GetWindowTextLength() == 0)
		return;

	m_Info.SetSel(0, -1, TRUE);		// Select all
	m_Info.Copy();					// Copy to clipboard
	m_Info.SetSel(-1, -1, TRUE);	// Remove the existing selection

	MessageBox("Debug Info copied to Clipboard.", "UUDeview Debug Info", 
		MB_ICONINFORMATION | MB_OK);
	
}


//
// Set up for debug dumping
//

void DebugDialog::Init(CRect *rp)
{

	wSizep = rp;					// Set the rectangle pointer

	if (m_hWnd == NULL)
		Create(IDD_DEBUGDIALOG, GetDesktopWindow());			// Have to show the Debug box
	else
	{
		ShowWindow(SW_SHOW);
		RedrawWindow();
		OnClearDebug();				// Need to clear the window
	}

	m_Close.Disable();
	m_Clear.Disable();
	m_ToClip.Disable();

}


//
// Allow the user to interact with the box
//

void DebugDialog::Ready()
{

	m_Close.Enable();
	m_Clear.Enable();
	m_ToClip.Enable();

}


//
// Appends a string
//

void DebugDialog::Add(CString& addstr)
{

	CString local(addstr);

	local += "\r\n";			// Append a CR/LF

	m_Info.ReplaceSel(local);

}


void DebugDialog::Add(const char * str)
{

	CString local(str);

	local += "\r\n";

	m_Info.ReplaceSel(local);

}

//
// Appends a plain old CR/LF
//

void DebugDialog::AddCR()
{

	m_Info.ReplaceSel("\r\n");

}


//
// Trip help
//

void DebugDialog::OnInfoHelp() 
{

	AfxGetApp()->WinHelp(Opt_Show_Debug_Info, HELP_CONTEXT);
	
}


//
// Add a string....
//

afx_msg LONG DebugDialog::OnAdd(UINT level, LONG csp)
{
	CString *cs = (CString *) csp;

	*cs += "\r\n";

	m_Info.ReplaceSel(*cs);

	delete cs;

return(TRUE);
}
