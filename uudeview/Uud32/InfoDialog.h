#if !defined(AFX_INFODIALOG_H__EEE4A5E3_F272_11D0_8988_444553540000__INCLUDED_)
#define AFX_INFODIALOG_H__EEE4A5E3_F272_11D0_8988_444553540000__INCLUDED_

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


// InfoDialog.h : header file
//

//#include "DialogSizer.h"
#include "SizeDialog.h"		// CSizeDialog

/////////////////////////////////////////////////////////////////////////////
// InfoDialog dialog

class InfoDialog : public CSizeDialog
{
// Construction
public:
	InfoDialog(CRect *rp = NULL, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InfoDialog)
	enum { IDD = IDD_INFODIALOG };
	CString	m_Text;
	CString	m_Title;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InfoDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
//	DialogSizer dsz;

	// Generated message map functions
	//{{AFX_MSG(InfoDialog)
	afx_msg void OnInfoHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFODIALOG_H__EEE4A5E3_F272_11D0_8988_444553540000__INCLUDED_)
