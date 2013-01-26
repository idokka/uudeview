// Uud32Dlg.h : header file
//

#if !defined(AFX_UUD32DLG_H__43871087_F1A4_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUD32DLG_H__43871087_F1A4_11D0_8988_444553540000__INCLUDED_

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


#include "DecodeDlg.h"
#include "EncodeDlg.h"
#include "MikeNButton.h"
#include "RegIni.h"
#include "SizeDialog.h"


/////////////////////////////////////////////////////////////////////////////
// CUud32Dlg dialog

class CUud32Dlg : public CSizeDialog
{
// Construction
public:
	bool SetWait(bool on);
	BOOL toolTips;
	void SaveState(bool write = false);
	void SaveState();
	CUud32Dlg(CWnd* pParent = NULL); 	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUud32Dlg)
	enum { IDD = IDD_UUD32_DIALOG };
	CButton	m_ExitButton;
	MikeNButton	m_ClearFiles;
	CTabCtrl	m_Mode;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUud32Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HCURSOR nArrow;
	CRect ref_tabsize;
	CRect ref_wsize;
	HICON m_hIcon;

	RegIni ri;					// Registry information

	bool waitMode;
	HCURSOR hWait;

	// Generated message map functions
	//{{AFX_MSG(CUud32Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAboutbutton();
	virtual void OnCancel();
	afx_msg void OnClearFiles();
	afx_msg void OnClose();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnActivate( UINT nState, CWnd* pWndOther, BOOL bMinimized );
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg LONG OnSetWaitCursor(UINT on, LONG lParam);
	afx_msg LONG OnCmdLineNext(WPARAM offset, LONG lParam);

	afx_msg LONG OnGetDefID(WPARAM wParam, LPARAM uuptr);

	CUud32App *pApp;			// Pointer to the application

	int paramCount;				// Total number of parameters
	int currentParam;			// Current parameter
	
	char currentPMode;			// Current parameter "mode"

//
// My stuff
private:
	DecodeDlg decodeBox;
	EncodeDlg encodeBox;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUD32DLG_H__43871087_F1A4_11D0_8988_444553540000__INCLUDED_)
