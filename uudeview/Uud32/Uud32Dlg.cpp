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


// Uud32Dlg.cpp : implementation for master parent dialog box
//

#include "stdafx.h"
#include "Uud32.h"
#include "Uud32Dlg.h"
#include "DecodeDlg.h"
#include "AboutBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUud32Dlg dialog

static struct CSizeDialog::DialogSizerInit ds_list[] ={
//	{ 2,						DSZ_SET_D,					2	},	// Set dividers
	{ IDCANCEL,					DSZ_MOVEX,					0,
		IDS_IDCANCEL		},
	{ IDC_GETHELP,				DSZ_MOVEX,					0,
		IDS_GETHELP			},
	{ IDC_ABOUTBUTTON,			DSZ_MOVEX,					0,
		IDS_ABOUTBUTTON		},
	{ IDC_DEBUGCLEARBUTTON,		DSZ_MOVEX,					0	},
	{ -1 }						// End of table marker
	};

//
// Message map
//

BEGIN_MESSAGE_MAP(CUud32Dlg, CSizeDialog)
	//{{AFX_MSG_MAP(CUud32Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB2, OnSelchangeTab)
	ON_BN_CLICKED(IDC_ABOUTBUTTON, OnAboutbutton)
	ON_BN_CLICKED(IDC_DEBUGCLEARBUTTON, OnClearFiles)
	ON_WM_CLOSE()
	ON_WM_DROPFILES()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_GETHELP, OnGetHelp)
	//}}AFX_MSG_MAP
	ON_WM_SETCURSOR()
	ON_MESSAGE(WAIT_CURSOR, OnSetWaitCursor)
	ON_WM_ACTIVATE()
	ON_MESSAGE(MSG_CMDNEXT, OnCmdLineNext)
	ON_MESSAGE(DM_GETDEFID, OnGetDefID)
END_MESSAGE_MAP()

//
// ---------------------------------------------
//

CUud32Dlg::CUud32Dlg(CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, CUud32Dlg::IDD, NULL, pParent, 0, 
		0 /* MINW */, 0 /* Minh */)
{
	//{{AFX_DATA_INIT(CUud32Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_UUDICON);

	waitMode = false;
	hWait = hArrow = NULL;

	LONG dbu = GetDialogBaseUnits();
	int hdbu = (dbu & 0xFFFF);			// Horiz dialog base units
	int vdbu = (dbu >> 16) & 0xFFFF;	// Vert dialog base units

	if (vdbu == 20 && hdbu == 10)		// Large fonts
	{
		min_w = 626;
		min_h = 491;
	}
	else if (vdbu = 16 && hdbu == 8)	// Small fonts
	{
		min_w = 472;
		min_h = 401;
	}
	else 								// Calculate size
	{
		// pixelX = (templateunitX * baseunitX) / 4 
		// pixelY = (templateunitY * baseunitY) / 8

		min_w = (232 * hdbu) / 4;
		min_h = (201 * vdbu) / 8;
	}

}

void CUud32Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUud32Dlg)
	DDX_Control(pDX, IDCANCEL, m_ExitButton);
	DDX_Control(pDX, IDC_DEBUGCLEARBUTTON, m_ClearFiles);
	DDX_Control(pDX, IDC_TAB2, m_Mode);
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUud32Dlg message handlers

BOOL CUud32Dlg::OnInitDialog()
{
	BOOL rc = CSizeDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	ASSERT(m_hIcon != NULL);

	SetIcon(m_hIcon, TRUE);		// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//
	// Set up tab control
	//
	TC_ITEM TabCtrlItem;
	TabCtrlItem.mask = TCIF_TEXT;
    TabCtrlItem.pszText = "&Decode";
	m_Mode.InsertItem( 0, &TabCtrlItem );
    TabCtrlItem.pszText = "&Encode";
	m_Mode.InsertItem( 1, &TabCtrlItem );

	//
	// Set up the "Clear Files" button
	//
#if defined(_DEBUG)
	m_ClearFiles.ShowWindow(SW_SHOW);		// Make the button appear

	CFileFind ff;
	BOOL frc = ff.FindFile("h:\\uu\\decode\\*.*", 0);
	bool gotsome = false;
	while (frc)
	{
		frc = ff.FindNextFile();
		if (!ff.IsDirectory())			// There are non-directory files
		{
			gotsome = true;
			break;
		}
	}
	ff.Close();

	if (gotsome && MessageBox("Clear decode directory?", "UUDeview Debug", MB_YESNO) == IDYES)
		OnClearFiles();
#endif

	//
	// State recovery
	ri.Start(REG_BASE, REG_VNO);		// Set up RegINI for master form

	//
	// Command-line setup

	pApp = (CUud32App *) AfxGetApp();		// Convenience pointer to the app
	paramCount = pApp->GetParamCount();

#if defined(_DEBUG)
	if (!pApp->GetCLMode())			// Not command-line mode
		SaveState(false);					// Recover state information but don't add /x
#else								// Automatically append "/x" in production
	if (pApp->GetCLMode())
	{
		pApp->AddParam(TRUE, "x");		// Make it exit when done
		paramCount++;
	}
	else
		SaveState(false);					// Recover state information if not in command-line mode
#endif

	currentParam = 0;

	currentPMode = 'a';				// Default to "add" for backwards compatibility

	//
	// Figure out the dialog window sizes
	//

	GetClientRect(&ref_wsize);		// Read the main window size
	m_Mode.GetWindowRect(&ref_tabsize);		// Read the tab window size
	ScreenToClient(&ref_tabsize);	// Convert to client coords

	RECT r;
	m_Mode.GetClientRect(&r);		// Read the control's client area
	m_Mode.AdjustRect(FALSE, &r);	// Find the display area

	WINDOWPLACEMENT wp;
	m_Mode.GetWindowPlacement(&wp);

	RECT irect;
	m_Mode.GetItemRect(0, &irect);

	r.top += wp.rcNormalPosition.top;
	r.left += wp.rcNormalPosition.left;
	r.bottom -= irect.bottom;
	r.right -= irect.left;

	//
	// Set up Decode child dialog
	decodeBox.Create(IDD_DECODE);
	decodeBox.MoveWindow(r.left, r.top, r.right, r.bottom, TRUE);

	//
	// Set up Encode child dialog
	encodeBox.Create(IDD_ENCODE);
	encodeBox.MoveWindow(r.left, r.top, r.right, r.bottom, TRUE);

	OnSelchangeTab(NULL, NULL);		// Show/hide windows, set caption

	dlgName = "UUD32 Main";

	PostMessage(MSG_CMDNEXT);

return(rc);
}

void CUud32Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CUud32Dlg::OnDestroy()
{
	if (decodeBox.m_hWnd != NULL)		// Make sure subsidiary window destroys get called
		decodeBox.DestroyWindow();

	if (encodeBox.m_hWnd != NULL)
		encodeBox.DestroyWindow();

	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUud32Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CUud32Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//
// Switch page
//
void CUud32Dlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{

	switch (m_Mode.GetCurSel()) 
	{
		case DECODE_PAGE:							// Decode
			encodeBox.ShowWindow(SW_HIDE);
			decodeBox.ShowWindow(SW_SHOW);
			decodeBox.EnableToolTips(!decodeBox.options[OPT_HIDETIPS]);
			SetWindowText("UUDeview - Decode");
			break;

		case ENCODE_PAGE:							// Encode
			decodeBox.ShowWindow(SW_HIDE);
			encodeBox.ShowWindow(SW_SHOW);
			encodeBox.EnableToolTips(!decodeBox.options[OPT_HIDETIPS]);
			SetWindowText("UUDeview - Encode");
			break;
	}

	if (pResult != NULL)				// Protect from calls from OnInitDialog
		*pResult = 0;

}


//
// Show the About box
//

void CUud32Dlg::OnAboutbutton() 
{

	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
	
}


//
// Save window position, etc.
//


void CUud32Dlg::OnCancel() 
{
	SaveState(true);				// Write state information to Registry
	CFileName::KillXFiles();
	CDialog::OnCancel();

}

void CUud32Dlg::OnClose() 
{

	if (waitMode)					// Stop the close if we're waiting
		return;

	SaveState(true);				// Write state information to Registry
	CFileName::KillXFiles();
	CDialog::OnClose();
}


//
// Clear all the files in our test output directory
//

void CUud32Dlg::OnClearFiles() 
{

#if defined(_DEBUG)
	CFileFind ff;

	int dfc = 0;

	BOOL loop = ff.FindFile("L:\\No Backup\\UU\\Decode\\*.*", 0);

	while (loop)
	{
		loop = ff.FindNextFile();			// Always get first
		if (!ff.IsDirectory())
		{
			DeleteFile(ff.GetFilePath());
			dfc++;
		}
	}

	ff.Close();

	if (dfc > 0)
	{
		CString wrk;

		wrk.Format("%d files deleted", dfc);

		MessageBox(wrk, "Delete Test Output", MB_OK);
	}
#endif

}


//
// Activate...
//

afx_msg void CUud32Dlg::OnActivate( UINT nState, CWnd* pWndOther, BOOL bMinimized )
{

	if ((nState & (WA_ACTIVE | WA_CLICKACTIVE)) && !bMinimized)
	{
		decodeBox.Activate();
		encodeBox.Activate();
	}

}


//
// State save/restore from Registry
//

void CUud32Dlg::SaveState(bool write)
{
	if (pApp->GetCLMode())
		return;						// Don't save changes in command line mode

	int tab;

	if (write)					// "Writing" variable transfers
	{
		decodeBox.SaveState(true);		// Write out Decode Box state
		encodeBox.SaveState(true);
		tab = m_Mode.GetCurSel();
	}

	ri.BiDir("Mode", tab, write);

	ri.Close();

	if (!write)					// "Reading" variable transfers
	{
		m_Mode.SetCurSel(tab);
	}

}


//
// Drag-n-drop files
//
afx_msg void CUud32Dlg::OnDropFiles(HDROP hDropInfo)
{

	switch (m_Mode.GetCurSel())
	{
		case DECODE_PAGE:
			decodeBox.OnDropFiles(hDropInfo);
			break;

		case ENCODE_PAGE:
			encodeBox.OnDropFiles(hDropInfo);
			break;
	}

	::DragFinish(hDropInfo);			// Always free the memory

}


//
// Resize the dialog
//

void CUud32Dlg::OnSize(UINT nType, int cx, int cy) 
{
	CSizeDialog::OnSize(nType, cx, cy);

	if (m_Mode.m_hWnd != NULL)
		m_Mode.ShowWindow(SW_HIDE);

	if (m_Mode.m_hWnd == NULL || nType == SIZE_MINIMIZED)
		return;						// Can't resize yet or minimized

	CRect r(ref_tabsize);			// Create the current size

	r.right += cx - ref_wsize.Width();		// Calculate new size
	r.bottom += cy - ref_wsize.Height();

	m_Mode.MoveWindow(r, FALSE);			// Reposition
	
	m_Mode.GetClientRect(&r);		// Read the control's client area
	m_Mode.AdjustRect(FALSE, &r);	// Find the display area

	WINDOWPLACEMENT wp;
	m_Mode.GetWindowPlacement(&wp);

	RECT irect;
	m_Mode.GetItemRect(0, &irect);

	r.top += wp.rcNormalPosition.top;
	r.left += wp.rcNormalPosition.left;
	r.bottom -= irect.bottom;
	r.right -= irect.left;

	//
	// Set up Decode child dialog
	decodeBox.MoveWindow(r.left, r.top, r.right, r.bottom, FALSE);
	encodeBox.MoveWindow(r.left, r.top, r.right, r.bottom, FALSE);

	m_Mode.ShowWindow(SW_SHOW);

	UpdateWindow();
	
}


//
// Help button clicked...
//

void CUud32Dlg::OnGetHelp() 
{

	pApp->WinHelp(0, HELP_CONTENTS);

}


//
// Do the wait cursor
//

BOOL CUud32Dlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{

	if (waitMode)
	{
		if (hWait == NULL)
			hWait = pApp->LoadStandardCursor(IDC_WAIT);

		if (hWait != NULL)
			SetCursor(hWait);

		return(TRUE);
	}

return CWnd::OnSetCursor(pWnd, nHitTest, message);
}


//
// Set the new wait mode.  Old wait is returned
//

bool CUud32Dlg::SetWait(bool on)
{
	bool rc = waitMode;

	waitMode = on;

return(rc);
}


//
// Handle wait cursor requests from child windows
//

afx_msg LONG CUud32Dlg::OnSetWaitCursor(UINT on, LONG lParam)
{

	waitMode = (on != 0);

	m_ExitButton.EnableWindow(!waitMode);

	if (waitMode)
	{
		if (hWait == NULL)
			hWait = pApp->LoadStandardCursor(IDC_WAIT);

		if (hWait != NULL)
			SetCursor(hWait);
	}
	else
	{
		if (hArrow == NULL)
			hArrow = pApp->LoadStandardCursor(IDC_ARROW);

		if (hArrow != NULL)
			SetCursor(hArrow);
	}

return(TRUE);
}




//
// Next command line parameter
//

afx_msg LONG CUud32Dlg::OnCmdLineNext(WPARAM offset, LONG lParam)
{
	if (offset != 0)			// Just change the offset into the parameter list
	{
		currentParam += (signed int) offset;	// Move through the list if needed
		return(TRUE);
	}

	if (currentParam < 0 || currentParam >= paramCount)
		return(TRUE);				// Nothing more to do

	BOOL cFlag;

	CString param;

	if (!pApp->GetParam(currentParam++, cFlag, param))
		return(TRUE);			// Could not get the parameter

	if (cFlag)
	{
		param.MakeLower();			// Switch to lower

		switch (currentPMode = param[0])			// May have to switch modes
		{
			case 'd':				// Switch to decode mode
				m_Mode.SetCurSel(DECODE_PAGE);
				OnSelchangeTab(NULL, NULL);
				break;

			case 'e':				// Switch to encode mode
				m_Mode.SetCurSel(ENCODE_PAGE);
				OnSelchangeTab(NULL, NULL);
				break;

			case 'x':				// Exit
				currentParam--;		// Point back
				PostMessage(WM_CLOSE);		// Keep sending closes till it exits
				break;
		}

		param.Empty();				// Parameter is always empty on change
	}

	switch (m_Mode.GetCurSel())
	{
		case DECODE_PAGE:
			decodeBox.PostMessage(MSG_CMDLINE, currentPMode, (LPARAM) new CString(param));
			break;

		case ENCODE_PAGE:
			encodeBox.PostMessage(MSG_CMDLINE, currentPMode, (LPARAM) new CString(param));
			break;
	}

return(TRUE);
}


//
// Handle Default Request ID
//

afx_msg LONG CUud32Dlg::OnGetDefID(WPARAM wParam, LPARAM uuptr)
{

	return(MAKELONG(0, DC_HASDEFID));

}
