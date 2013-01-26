#if !defined(AFX_LAUNCHDIALOG_H__BF7F37E1_F5D1_11D0_8988_444553540000__INCLUDED_)
#define AFX_LAUNCHDIALOG_H__BF7F37E1_F5D1_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

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


// LaunchDialog.h : header file
//

//
// -------------------------------------------
//

// Return Codes
#define LDIAG_ALL		3				// Launch all

#include "MikeNButton.h"
#include "FileName.h"
#include "RegIni.h"

/////////////////////////////////////////////////////////////////////////////
// LaunchDialog dialog

class LaunchDialog : public CDialog
{
// Construction
public:
	int GetEFN(CFileName &fname, bool multi, CString &appname, 
		CString mru[MAX_MRU], CString *dirp, 
		CString &lastEdit, BOOL *skipFlag);		// Get Editor filename
	BOOL OnInitDialog();
	int GetLFN(CFileName& here, bool multi, 
		CString& appname, CString mru[MAX_MRU], CString *dirp, BOOL *skipFlag);
	LaunchDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LaunchDialog)
	enum { IDD = IDD_LAUNCHDIALOG };
	CButton	c_SkipLaunch;
	MikeNButton	m_LaunchAll;
	CComboBox	m_LaunchBox;
	CString	m_LaunchFile;
	CString	m_LName;
	BOOL	m_SkipLaunch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LaunchDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool multiflag;
	CString *mrulist;			// Parent's Most Recently Used CString array
	CString *dir_ptr;			// Default FileOpen directory

	bool editMode;				// Launching the text editor

	// Generated message map functions
	//{{AFX_MSG(LaunchDialog)
	afx_msg void OnLaunchAll();
	afx_msg void OnLaunchBrowse();
	afx_msg void OnLaunchHelp();
	afx_msg void OnSkipLaunch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAUNCHDIALOG_H__BF7F37E1_F5D1_11D0_8988_444553540000__INCLUDED_)
