// Uud32.h : main header file for the UUD32 application
//

#if !defined(AFX_UUD32_H__43871085_F1A4_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUD32_H__43871085_F1A4_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

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


// Browse for directories
extern bool BrowseForDir(CString& dirname, const char *lpPrompt, CWnd *owner);


// Other Global functions
extern bool FExist(const char *filename);
extern int TrundleMessages(HWND hw);


// Registry INI path
#define REG_BASE	"MikeN\\Uud32"
#define REG_VNO		101

//
// Wait cursor on and off message
#define WAIT_CURSOR	(WM_USER + 1)

//
// Page numbers for dialogs
#define DECODE_PAGE		0
#define ENCODE_PAGE		1


//
// Command line messages
#define MSG_CMDLINE	(WM_USER + 150)			// This is a command line parameter to be processed
#define MSG_CMDNEXT (WM_USER + 151)			// Process next command-line parameter


/////////////////////////////////////////////////////////////////////////////
// CUud32App:
// See Uud32.cpp for the implementation of this class
//

class CUud32Dlg;			// Forward declare the dialog box

class CUud32App : public CWinApp
{
public:
	inline int GetParamCount()
	{	return(paramCount);		}

	inline bool GetCLMode()
	{	return(CLMode);			}

	bool GetParam(int index, BOOL& flg, CString& parm);
	void AddParam(BOOL bFlag, LPCTSTR param);
	CUud32App();

protected:
	struct UUDParams 
	{
		BOOL flag;
		CString param;
		struct UUDParams *next;
	} *paramList, *paramLast;

	CUud32Dlg *pDialog;		// Convenience pointer to the dialog box

	int paramCount;			// Total number of parameters

	bool CLMode;			// Command line mode

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUud32App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUud32App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUD32_H__43871085_F1A4_11D0_8988_444553540000__INCLUDED_)
