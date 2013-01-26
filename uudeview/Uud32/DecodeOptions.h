#if !defined(AFX_DECODEOPTIONS_H__EEE4A5E2_F272_11D0_8988_444553540000__INCLUDED_)
#define AFX_DECODEOPTIONS_H__EEE4A5E2_F272_11D0_8988_444553540000__INCLUDED_

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


// DecodeOptions.h : header file
//

// Match Options to master Option array
#define OPT_MAX			 18

#define OPT_BRACK		 0
#define OPT_DEBUG		 1
#define OPT_DUMB		 2
#define OPT_ETEXT		 3
#define OPT_FASTMODE	 4
#define OPT_IGNREPLY	 5
// define OPT_OWRITE		 6		// No longer in use
#define OPT_POE			 7
#define OPT_DESPERATE	 8
#define OPT_HIDETIPS	 9
#define OPT_STRICT		10
#define OPT_RECYCLE		11
#define OPT_OWMODE		12
#define OPT_PCASE		13			// Preserve output filename case
#define OPT_ENOPROMPT	14			// Edit without prompting
#define OPT_LNOPROMPT	15			// Launch without prompting
#define OPT_TEMPS		16			// Temporary file mode
#define OPT_DNOPROMPT	17			// Decode without prompting
#define OPT_STRICTFN	18			// Strict filenames

//
// Overwrite modes
//
#define OPT_OW_PROMPT	 0			// Normal mode (prompt)
#define OPT_OW_OW		 1			// Overwrite mode
#define OPT_OW_AUTO		 2			// Autonumber mode


/////////////////////////////////////////////////////////////////////////////
// DecodeOptions dialog

class DecodeOptions : public CDialog
{
// Construction
public:
	DecodeOptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DecodeOptions)
	enum { IDD = IDD_DECODEOPT };
	CEdit	m_TempFolderControl;
	CButton	m_BrowseTemp;
	CButton	m_AssocButton;
	BOOL	m_BrackPol;
	BOOL	m_Debug;
	BOOL	m_DumbMode;
	BOOL	m_EText;
	BOOL	m_FastMode;
	BOOL	m_IgnReply;
	BOOL	m_POE;
	BOOL	m_Desperate;
	int		m_Assoc;
	BOOL	m_HideTips;
	int		m_OutputFileMode;
	BOOL	m_RecycleInput;
	BOOL	m_StrictMime;
	BOOL	m_PreserveCase;
	BOOL	m_LNoPrompt;
	BOOL	m_ENoPrompt;
	CString	m_TempFolder;
	int		m_WinTemp;
	BOOL	m_DNoPrompt;
	BOOL	m_StrictFilenames;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DecodeOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ProtectedCheck(UINT ctlID, const char *prompt, const char *title);	// Prompt before checkbox

	// Generated message map functions
	//{{AFX_MSG(DecodeOptions)
	afx_msg void OnDecoptDefault();
	afx_msg void OnAssoc();
	afx_msg void OnDecOptHelp();
	afx_msg void OnRecycleInp();
	afx_msg void OnOutFModeOWrite();
	afx_msg void OnEditNoPrompt();
	afx_msg void OnLaunchNoPrompt();
	afx_msg void OnOtherTemp();
	afx_msg void OnWinTemp();
	afx_msg void OnBrowseTemp();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CString nonWTemp;			// Windows temporary folder set by user

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECODEOPTIONS_H__EEE4A5E2_F272_11D0_8988_444553540000__INCLUDED_)
