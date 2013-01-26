//{{AFX_INCLUDES()
#include "uud32acxctl.h"
//}}AFX_INCLUDES
#if !defined(AFX_ENCODEDLG_H__E7BDFF62_F1A9_11D0_8988_444553540000__INCLUDED_)
#define AFX_ENCODEDLG_H__E7BDFF62_F1A9_11D0_8988_444553540000__INCLUDED_

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


// EncodeDlg.h : header file
//

#include "MikeNButton.h"
#include "RegIni.h"
#include "SizeDialog.h"
#include "engine.h"

/////////////////////////////////////////////////////////////////////////////
// EncodeDlg dialog

class EncodeDlg : public CSizeDialog
{
// Construction
public:
	void Activate();
	void OnDropFiles(HDROP hDropInfo);
	void Info(const char *newinfo);
	void SetETO();
	void SaveState(bool write = false);
	BOOL OnInitDialog();
	EncodeDlg(CWnd* pParent = NULL);   // standard constructor
	~EncodeDlg();

// Dialog Data
	//{{AFX_DATA(EncodeDlg)
	enum { IDD = IDD_ENCODE };
	CButton	m_GetHelp;
	MikeNButton	m_EncSrcBrowse;
	CEdit	m_EncInfoBox;
	CEdit	m_EncSrcBox;
	MikeNButton	m_EncPath;
	CEdit	m_EncDestBox;
	CEdit	m_EncLineCtrl;
	MikeNButton	m_EncodeGo;
	CProgressCtrl	m_ProgBar;
	int		m_EncScheme;
	int		m_OutMode;
	int		m_EncLines;
	CString	m_EncDest;
	CString	m_EncSrc;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EncodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool CLSetLines(const char *nLines);
	bool CLSetOptions(const char *oList);
	int oldPart;
	bool newStep;
	void HourGlass(bool on);

	RegIni ri;

	CString srcDir;				// Source directory
	CString destDir;			// Destination path

	Engine *encoder;
	struct Engine::EngineEncode ees;

	bool allowOverwrite;		// Allow overwrite mode (set through command line)

	bool EngineSetup();

	afx_msg LONG OnMessage(WPARAM Level, LPARAM Message);
	afx_msg LONG OnProgress(WPARAM wParam, LPARAM uuprogp);

	afx_msg LONG OnEngineDone(WPARAM rc, LPARAM action);
	afx_msg LONG OnInfoPaint(WPARAM w, LPARAM l);

	afx_msg LONG OnCommandLine(WPARAM wParam, LPARAM lParam);

	// Generated message map functions
	//{{AFX_MSG(EncodeDlg)
	afx_msg void OnEncodego();
	afx_msg void OnEncSingle();
	afx_msg void OnEncClip();
	afx_msg void OnEncBrk();
	afx_msg void OnSetfocusEncInfo();
	afx_msg void OnChangeEncSrc();
	afx_msg void OnEncUU();
	afx_msg void OnEncXX();
	afx_msg void OnEnc64();
	afx_msg void OnEncPath();
	afx_msg void OnChangeEncDest();
	afx_msg void OnEncSrcBrowse();
	afx_msg void OnEncGetHelp();
	afx_msg void OnDestroy();
	afx_msg void OnEncY();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCODEDLG_H__E7BDFF62_F1A9_11D0_8988_444553540000__INCLUDED_)
