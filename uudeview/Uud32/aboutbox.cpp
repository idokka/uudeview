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


//
// Aboutbox generation
//
#include "stdafx.h"
#include "Uud32.h"
#include "AboutBox.h"

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_ABOUTDLL, m_Dll);
	DDX_Control(pDX, IDOK, m_OKButton);
	DDX_Control(pDX, IDC_ABOUTBMP, m_AboutPic);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//
// Dialog setup
//

BOOL CAboutDlg::OnInitDialog()
{
	BOOL rc = CDialog::OnInitDialog();

	CRect button, client, window, pic, edit;
	m_AboutPic.GetWindowRect(&pic);
	ScreenToClient(&pic);

	GetClientRect(&client);
	GetWindowRect(&window);

	int woffs = window.Width() - client.Width();		// NC area
	int hoffs = window.Height() - client.Height();

	m_OKButton.GetWindowRect(&button);
	ScreenToClient(&button);

	m_Dll.GetWindowRect(&edit);
	ScreenToClient(&edit);

	int eh = edit.Height();

	edit.top = pic.bottom + 1;
	edit.bottom = edit.top + eh;
	edit.right = pic.right;

	CString lv("Library version: ");

	CUud32acxCtrl AD;

	lv += AD.GetLibVersion();

	m_Dll.SetWindowText(lv);
	m_Dll.MoveWindow(edit, FALSE);

	int bwidth = button.Width();

	button.bottom = button.top + pic.Height() + eh;
	button.left = pic.right;
	button.right = button.left + bwidth;

	m_OKButton.MoveWindow(button, FALSE);

	window.bottom = window.top + pic.Height() + eh + hoffs;
	window.right = window.left + pic.Width() + bwidth + woffs;

	MoveWindow(window);

return(rc);
}
