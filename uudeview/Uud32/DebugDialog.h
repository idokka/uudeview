#if !defined(AFX_DEBUGDIALOG_H__747AD841_F43B_11D0_8988_444553540000__INCLUDED_)
#define AFX_DEBUGDIALOG_H__747AD841_F43B_11D0_8988_444553540000__INCLUDED_

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


// DebugDialog.h : header file
//

#include "MikeNButton.h"
#include "SizeDialog.h"
#include "RegIni.h"

//
// A user message...
#define DEBOX_ADD	(WM_APP + 0)


/////////////////////////////////////////////////////////////////////////////
// DebugDialog dialog

class DebugDialog : public CSizeDialog
{
// Construction
public:
	void Add(const char *str);
	void AddCR();
	void Add(CString& addstr);
	void Ready();
	void Init(CRect *rp = NULL);
	DebugDialog(CRect *rp = NULL, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DebugDialog)
	enum { IDD = IDD_DEBUGDIALOG };
	MikeNButton	m_Close;
	MikeNButton	m_ToClip;
	MikeNButton	m_Clear;
	CEdit	m_Info;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DebugDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DebugDialog)
	afx_msg void OnClearDebug();
	afx_msg void OnDeb2Clip();
	afx_msg void OnInfoHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg LONG OnAdd(UINT level, LONG message);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDIALOG_H__747AD841_F43B_11D0_8988_444553540000__INCLUDED_)
