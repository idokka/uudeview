#if !defined(AFX_RENOUTFILE_H__9B973AA1_F507_11D0_8988_444553540000__INCLUDED_)
#define AFX_RENOUTFILE_H__9B973AA1_F507_11D0_8988_444553540000__INCLUDED_

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


// RenOutFile.h : header file
//

#include "MikeNButton.h"
#include "Uud32acxctl.h"			// Needed for Prompt

// The other buttons
#define RENOUT_RENAME 3
#define RENOUT_OWRITE 4
#define RENOUT_SKIP   5
#define RENOUT_AUTO	  6

/////////////////////////////////////////////////////////////////////////////
// RenOutFile dialog

class RenOutFile : public CDialog
{
// Construction
public:
	int Prompt(CString *path, CString& lfn, CUud32acxCtrl *UD);
	RenOutFile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RenOutFile)
	enum { IDD = IDD_RENAMEDIALOG };
	MikeNButton	c_ResetButton;
	MikeNButton	m_Skip;
	MikeNButton	m_OWrite;
	CEdit	m_FileName;
	MikeNButton	m_Rename;
	CString	m_FileNameVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RenOutFile)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CUud32acxCtrl * UDp;
	CString * pathPointer;
	CString origValue;

	// Generated message map functions
	//{{AFX_MSG(RenOutFile)
	afx_msg void OnRenButton();
	afx_msg void OnOwritwButton();
	afx_msg void OnSkipButton();
	afx_msg void OnChangeRenFileName();
	afx_msg void OnUpdateRenFileName();
	afx_msg void OnRenOutCancel();
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg void OnANumber();
	afx_msg void OnRenReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RENOUTFILE_H__9B973AA1_F507_11D0_8988_444553540000__INCLUDED_)
