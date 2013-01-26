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


// LaunchDialog.cpp : implementation file for Launch / Decode & Launch dialog
//

#include "stdafx.h"
#include "Uud32.h"
#include "LaunchDialog.h"

#include "hlp\decode.hh"

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

#if SKIP
static struct CSizeDialog::DialogSizerInit ds_list[] ={
	{ IDOK,				DSZ_MOVEX,					0	},
	{ IDC_LAUNCHLIST,	DSZ_SIZEW,					0	},
	{ IDC_LAUNCHBROWSE, DSZ_MOVEX,					0	},
	{ IDC_LAUNCHALL,	DSZ_MOVEX,					0	},
	{ IDC_LAUNCHHELP,	DSZ_NONE,					0	},
	{ IDC_LAUNCHNAME,	DSZ_SIZEW,					0	},
	{ -1 }						// End of table marker
	};
LaunchDialog::LaunchDialog(CRect *rp, CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, LaunchDialog::IDD, rp, pParent)
#endif

/////////////////////////////////////////////////////////////////////////////
// LaunchDialog dialog


LaunchDialog::LaunchDialog(CWnd* pParent /*=NULL*/)
	: CDialog(LaunchDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(LaunchDialog)
	m_LaunchFile = _T("");
	m_LName = _T("");
	m_SkipLaunch = FALSE;
	//}}AFX_DATA_INIT
}


void LaunchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LaunchDialog)
	DDX_Control(pDX, IDC_SKIPLAUNCH, c_SkipLaunch);
	DDX_Control(pDX, IDC_LAUNCHALL, m_LaunchAll);
	DDX_Control(pDX, IDC_LAUNCHLIST, m_LaunchBox);
	DDX_CBString(pDX, IDC_LAUNCHLIST, m_LaunchFile);
	DDV_MaxChars(pDX, m_LaunchFile, 256);
	DDX_Text(pDX, IDC_LAUNCHNAME, m_LName);
	DDX_Check(pDX, IDC_SKIPLAUNCH, m_SkipLaunch);
	//}}AFX_DATA_MAP
}


//
// Setup after dialog created
//

BOOL LaunchDialog::OnInitDialog()
{
	BOOL rc = CDialog::OnInitDialog();

	if (multiflag)
		m_LaunchAll.Enable();
	else
		m_LaunchAll.Disable();

	if (mrulist != NULL)
		RegIni::Array2MRU(&m_LaunchBox, mrulist, MAX_MRU);

	CRect r;

	m_LaunchBox.GetWindowRect(&r);
	ScreenToClient(&r);
	r.bottom = r.top + 150;

	m_LaunchBox.MoveWindow(&r, FALSE);

	if (editMode)
		SetWindowText("Edit");

return(rc);
}


BEGIN_MESSAGE_MAP(LaunchDialog, CDialog)
	//{{AFX_MSG_MAP(LaunchDialog)
	ON_BN_CLICKED(IDC_LAUNCHALL, OnLaunchAll)
	ON_BN_CLICKED(IDC_LAUNCHBROWSE, OnLaunchBrowse)
	ON_BN_CLICKED(IDC_LAUNCHHELP, OnLaunchHelp)
	ON_BN_CLICKED(IDC_SKIPLAUNCH, OnSkipLaunch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LaunchDialog message handlers

void LaunchDialog::OnLaunchAll() 
{
	
	UpdateData();						// Retrieve the data
	EndDialog(LDIAG_ALL);				// Launch all
	
}


//
// Browse for an EXE
//

void LaunchDialog::OnLaunchBrowse() 
{

	CFileDialog openFile(
		TRUE,					// OPEN
		"exe",					// Default extension
		NULL,					// Initial filename
		OFN_EXPLORER | OFN_FILEMUSTEXIST |
		  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_SHOWHELP,		// Flags
		"Programs|*.exe|"
		  "All Executables|*.com; *.exe; *.bat; *.pif|"
		  "All Files|*.*||",
		NULL);				// Owner is ME

	openFile.m_ofn.lpstrTitle = "Select Launch Program";

	if (dir_ptr != NULL && !dir_ptr->IsEmpty())
		openFile.m_ofn.lpstrInitialDir = (const char *) *dir_ptr;

	if (openFile.DoModal() == IDOK)
	{
		m_LaunchBox.SetWindowText(openFile.GetPathName());
		if (dir_ptr != NULL)
		{
			CFileName fn(openFile.GetPathName());
			*dir_ptr = fn.Path();			// Adjust the parent's initial dir
		}
	}
	
}


//
// Show the dialog, return the click code
//

int LaunchDialog::GetLFN(CFileName &fname, bool multi, 
	CString &appname, CString mru[MAX_MRU], CString *dirp,
	BOOL *skipFlag)
{

	m_LName = fname;				// Set the filename
	m_LaunchFile = fname.FindExec();

	multiflag = multi;

	mrulist = mru;					// Point to MRU array

	dir_ptr = dirp;

	editMode = false;

	int rc = DoModal();				// Show the box

	if (rc != IDCANCEL)
	{
		appname = m_LaunchFile;
		if (mrulist != NULL)
			RegIni::AddMRU(mru, appname, MAX_MRU);

		*skipFlag = m_SkipLaunch;
	}


return(rc);
}


//
// Launch the Help
//

void LaunchDialog::OnLaunchHelp() 
{

	AfxGetApp()->WinHelp(Launch_Box, HELP_CONTEXT);
	
}



//
// Get the filename used to edit files
//

int LaunchDialog::GetEFN(CFileName &fname, bool multi, CString &appname, 
CString mru[], CString *dirp, CString &lastEdit, BOOL *skipFlag)
{

	m_LName = fname;				// Set the filename

	if (lastEdit.IsEmpty())			// No "last editor," use Notepad
	{
		char wrk[_MAX_PATH + 16];

		char *p = wrk + GetWindowsDirectory(wrk, _MAX_PATH);

		if (p > wrk && *(p - 1) == '\\')
			p--;

		strcpy(p, "\\notepad.exe");

		m_LaunchFile = wrk;
	}
	else
		m_LaunchFile = lastEdit;		// User's last editor

	multiflag = multi;

	mrulist = mru;					// Point to MRU array

	dir_ptr = dirp;

	editMode = true;

	int rc = DoModal();				// Show the box

	if (rc != IDCANCEL)
	{
		appname = m_LaunchFile;
		lastEdit = m_LaunchFile;

		if (mrulist != NULL)
			RegIni::AddMRU(mru, appname, MAX_MRU);

		*skipFlag = m_SkipLaunch;
	}


return(rc);
}



//
// Warn before turning on the Skip function
//

void LaunchDialog::OnSkipLaunch() 
{

	if (c_SkipLaunch.GetCheck() == 0)
		return;				// Nothing to do -- turned off

	UINT rc;

	if (editMode)
		rc = MessageBox(
			"If you select this option, UUDeview will start\r\n"
			"the text editor for decode input files\r\n"
			"without prompting you for the editor you\r\n"
			"wish to use.\r\n\r\n"
			"To reactivate this dialog, go into \"Decode\r\n"
			"Options\" and clear the \"Edit without\r\n"
			"prompting\" option.", 
			"Edit decode input files",
			MB_OKCANCEL | MB_ICONEXCLAMATION);
	else
		rc = MessageBox(
			"If you select this option, UUDeview will launch\r\n"
			"the application that Windows associates with files\r\n"
			"in the decode input and decode output windows\r\n"
			"without prompting you for the application you\r\n"
			"wish to use.\r\n\r\n"
			"To reactivate this dialog, go into \"Decode\r\n"
			"Options\" and clear the \"Launch without\r\n"
			"prompting\" option.", 
			"Launch decode files",
			MB_OKCANCEL | MB_ICONEXCLAMATION);

	if (rc != IDOK)
		c_SkipLaunch.SetCheck(FALSE);

}
