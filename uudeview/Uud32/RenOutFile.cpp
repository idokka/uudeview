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


// RenOutFile.cpp : implementation file for Rename Output File dialog
//

#include "stdafx.h"
#include "Uud32.h"
#include "RenOutFile.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(RenOutFile, CDialog)
	//{{AFX_MSG_MAP(RenOutFile)
	ON_BN_CLICKED(IDC_RENBUTTON, OnRenButton)
	ON_BN_CLICKED(IDC_RENOWBUTTON, OnOwritwButton)
	ON_BN_CLICKED(IDC_RENSKIPBUTTON, OnSkipButton)
	ON_EN_CHANGE(IDC_RENFILENAME, OnChangeRenFileName)
	ON_EN_UPDATE(IDC_RENFILENAME, OnUpdateRenFileName)
	ON_BN_CLICKED(IDC_RENOUTCANCEL, OnRenOutCancel)
	ON_WM_ACTIVATE()
	ON_BN_CLICKED(IDC_ANUMBER, OnANumber)
	ON_BN_CLICKED(IDC_RENREST, OnRenReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RenOutFile dialog


RenOutFile::RenOutFile(CWnd* pParent /*=NULL*/)
	: CDialog(RenOutFile::IDD, pParent)
{
	//{{AFX_DATA_INIT(RenOutFile)
	m_FileNameVal = _T("");
	//}}AFX_DATA_INIT
}


void RenOutFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RenOutFile)
	DDX_Control(pDX, IDC_RENREST, c_ResetButton);
	DDX_Control(pDX, IDC_RENSKIPBUTTON, m_Skip);
	DDX_Control(pDX, IDC_RENOWBUTTON, m_OWrite);
	DDX_Control(pDX, IDC_RENFILENAME, m_FileName);
	DDX_Control(pDX, IDC_RENBUTTON, m_Rename);
	DDX_Text(pDX, IDC_RENFILENAME, m_FileNameVal);
	DDV_MaxChars(pDX, m_FileNameVal, 256);
	//}}AFX_DATA_MAP
}


/////////////////////////////////////////////////////////////////////////////
// RenOutFile message handlers

//
// Respond to the Rename Box buttons
//

void RenOutFile::OnRenButton() 
{

	UpdateData();			// Retrieve the new filename
	EndDialog(RENOUT_RENAME);
	
}

void RenOutFile::OnOwritwButton() 
{

	EndDialog(RENOUT_OWRITE);
	
}

void RenOutFile::OnSkipButton() 
{

	EndDialog(RENOUT_SKIP);
	
}

void RenOutFile::OnRenOutCancel() 
{
	
	EndDialog(IDCANCEL);

}

//
// Activate Autonumber feature
//

void RenOutFile::OnANumber() 
{
	
	if (MessageBox("Do you want UUDeview to generate\r\n"
		 "new filenames automatically when an output\r\n"
		 "filename already exists?", "AutoNumber Mode",
		 MB_YESNO | MB_ICONQUESTION) == IDYES)
		EndDialog(RENOUT_AUTO);
	
}


//
// Actually make the dialog box do things
//

int RenOutFile::Prompt(CString *path, CString& lfn, CUud32acxCtrl *UD)
{

	pathPointer = path;						// Set up pointers for handler functions
	UDp = UD;

	origValue = lfn;				// Store the original value

	m_FileNameVal = lfn;					// Set the initial value

	int rc = DoModal();						// Show the dialog and get results

	if (rc == RENOUT_RENAME)
	{
		lfn = m_FileNameVal;	// Alter the owner's filename
		if (lfn.IsEmpty())
			rc = IDCANCEL;
	}

return(rc);
}



//
// The control has changed
//

void RenOutFile::OnChangeRenFileName() 
{

	CString nfn;

	m_FileName.GetWindowText(nfn);

	if (FExist(*pathPointer + nfn))
	{
		m_OWrite.Enable();
		m_Rename.Disable();
		SetDefID(m_OWrite.GetDlgCtrlID());
	}
	else
	{
		m_OWrite.Disable();
		m_Rename.Enable();
		SetDefID(m_Rename.GetDlgCtrlID());
	}

	if (nfn.CompareNoCase(origValue) == 0)
		c_ResetButton.Disable();
	else
		c_ResetButton.Enable();
	
}

//
// Control is about to update, validate chars
//

void RenOutFile::OnUpdateRenFileName() 
{
	
	CString ntext;

	m_FileName.GetWindowText(ntext);

	CString nstr = UDp->FileFilter(ntext);

	if (ntext != nstr)
	{
		int start, end;
		m_FileName.GetSel(start, end);
		m_FileName.SetWindowText(nstr);		// Override the updated text
		m_FileName.SetSel(start, start);
	}

}


//
// We need to intercept the PreTranslateMessage handler
//  to prevent it from checking to see if the parent is in context
//  help mode (thread crash)
//

BOOL RenOutFile::PreTranslateMessage(MSG* pMsg) 
{
	ASSERT(m_hWnd != NULL);

	// allow tooltip messages to be filtered
	if (CWnd::PreTranslateMessage(pMsg))
		return TRUE;

	// filter both messages to dialog and from children
	PreTranslateInput(pMsg);

return(TRUE);						// Short out the CDialog handler
}


//
// Handle activation (redraw in case hidden)
//

void RenOutFile::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{

	CDialog::OnActivate(nState, pWndOther, bMinimized);

//	if (nState == WA_ACTIVE && !bMinimized)
		RedrawWindow();
	
}



//
// Reset to original value
//

void RenOutFile::OnRenReset() 
{

	m_FileName.SetWindowText(origValue);		// Override the updated text
	m_FileName.SetSel(0, 0);

	RedrawWindow();
	
}
