//{{AFX_INCLUDES()
#include "uud32acxctl.h"
//}}AFX_INCLUDES
#if !defined(AFX_DECODEDLG_H__E7BDFF61_F1A9_11D0_8988_444553540000__INCLUDED_)
#define AFX_DECODEDLG_H__E7BDFF61_F1A9_11D0_8988_444553540000__INCLUDED_

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


// DecodeDlg.h : header file
//

#include "regini.h"
#include "DecodeOptions.h"		// Handle the Decode Options dialog
#include "MyListBox.h"
#include "MikeNButton.h"
#include "MikeNListCtrl.h"
#include "FileName.h"
#include "DebugDialog.h"
#include "SizeDialog.h"

#include "engine.h"

//
// --------------------------------------
//
// My additions
//

#define SHOW_DEBUG options[OPT_DEBUG]

// Status Icon mapping constants
#define SI_OK				 0
#define SII_OK				 1
#define SI_CONFLICT			 2
#define SI_DECODEFAILED		 3
#define SI_DECODEDOK		 4
#define SI_DUPLICATE		 5
#define SI_QUESTION			 6
#define SI_BAD				 7
#define SII_DUPLICATE		 8
#define SII_CONFLICT		 9
#define SII_BAD				10
#define SII_QUESTION		11

//
// "Decode These Files" Menu Commands
//

#define DT_REMOVE		201
#define DT_NONE			202
#define DT_ALL			203
#define DT_INV			204
#define DT_LAUNCH		205
#define DT_EDIT			206
#define DT_HELP			299

//
// "Decode Output" Menu Commands
//

#define DO_INFO			101
#define DO_REMOVE		102
#define DO_RENAME		103
#define DO_NONE			104
#define DO_ALL			105
#define DO_INV			106
#define DO_LAUNCH		108
#define DO_HELP			199

//
// --------------------------------------
//

/////////////////////////////////////////////////////////////////////////////
// DecodeDlg dialog

class DecodeDlg : public CSizeDialog
{
// Construction
public:
	DecodeDlg(CWnd* pParent = NULL);   // standard constructor
	~DecodeDlg();
	BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(DecodeDlg)
	enum { IDD = IDD_DECODE };
	CButton	m_InfoBox;
	CButton	m_CHelp;
	MikeNButton	m_DPathBrowse;
	MikeNButton	m_AddClipboard;
	MikeNButton	m_AddDecode;
	CProgressCtrl	ProgBar;
	MikeNButton	m_ClearDecode;
	MikeNButton	m_RenameDecodeOut;
	MikeNButton	m_RemoveDecodeOut;
	CEdit	m_Info2;
	CEdit	m_Info1;
	CComboBox	m_DecodePath;
	MikeNListCtrl	m_DecodeOut;
	MikeNButton	m_DecodeOptions;
	MikeNButton	m_DecodeInfo;
	MikeNButton	m_DecodeGo;
	MikeNButton	m_RemoveDecode;
	MyListBox	m_DecodeList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DecodeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool SetAssoc(int oldmode, int newmode);
	bool IsAssociated();
	int oldPart;
	bool newStep;
	CRect infoPosn;
	CRect debugPosn;
	void DupCheck();
	void TransferOptions(CUud32acxCtrl *UDp);
	void DecodeOutLaunch();
	void ShowDecodeMenu();
	void DecodeLaunch();
	void ShowDecodeOutMenu();
	int DecIcon(int row, const char *cs);
	CString CurrentOutput();
	void OptionButtonSet();

	CImageList DStatusIcons;		// Status Icons image list
	RegIni ri;

	CString clipboardString;		// The current clipboard string in the list box
	bool clipboardSet;				// Clipboard is set
	CFileName cFile;				// Clipboard file

	CString launchList[MAX_MRU];	// Decode List launch save MRU
	CString launchDir;				// Decode list launch initial dir

	CString editList[MAX_MRU];		// Decode List Edit save MRU
	CString editDir;				// Decode list Edit initial dir
	CString editLast;				// Last editor used

	CString launchOutList[MAX_MRU];	// Decode Output List launch save MRU
	CString launchOutDir;			// Decode Output List launch initial dir

	CString addDir;					// Add files default directory
	int addFilter;					// Which select filter is on in the Add box

	CString tempFolder;				// Where should the system put its temporary files

	DebugDialog deBox;				// Debug info box

	volatile bool cancelFlag;

	// Clipboard functions
	void ClipboardKill();

	// Info functions
	void InfoClear();
	void Info1(const char *nstr);
	void Info1(UINT msg_no);
	void Info2(const char *nstr);

	// Decode functions
	void DecodePreview();
	void DecodeGo();
	void HourGlass(bool on);

	// State of UUDeview's File Association...
	BOOL assoc;

	// Generated message map functions
	//{{AFX_MSG(DecodeDlg)
	afx_msg void OnAdddecode();
	afx_msg void OnSelchangeDecodelist();
	afx_msg void OnClearDecode();
	afx_msg void OnRemoveDecode();
	afx_msg void OnDecodeGo();
	afx_msg void OnDecodePathBrowse();
	afx_msg void OnDecodeOptions();
	afx_msg void OnClickDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRenameDecodeOut();
	afx_msg void OnRemoveDecodeOut();
	afx_msg void OnEndLabelEditDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDecodeInfo();
	afx_msg void OnKeydownDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAddClipboard();
	afx_msg void OnStartContextHelp();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg LONG OnMessage(WPARAM Level, LPARAM Message);
	afx_msg LONG OnProgress(WPARAM wParam, LPARAM uuprogp);

	afx_msg LONG OnEngineDone(WPARAM Percent, LPARAM lParam);
	afx_msg LONG OnEngineRowChange(WPARAM row, LPARAM lParam);

	afx_msg LONG OnSetAuto(WPARAM wParam, LPARAM uuptr);

	afx_msg LONG OnGetDefID(WPARAM wParam, LPARAM uuptr);

//
// My stuff
private:
	bool inproc;

public:
	BOOL options[OPT_MAX + 1];		// Storage for options

	BOOL * toolTipPointer;
	void OnDropFiles(HDROP hDropInfo);
	void Activate();
	void SaveState(bool write = false);		// Save positions, etc.

	enum MachineState {				// What state is the dialog in
		MS_UNKNOWN,
		MS_CLEAR,
		MS_PREVIEW,
		MS_GO,
		MS_DONE 
		} State;

	void SetState(enum MachineState ns, bool force = false);

protected:
	bool CLSetOptions(const char *oList);
	bool CLAddFiles(const char *fMask);
	void DecodeEdit(void);
	afx_msg LONG OnUpdateName(WPARAM row, LPARAM newname);
	afx_msg LONG OnUpdateIcon(WPARAM row, LPARAM lp);
	afx_msg LONG OnCommandLine(WPARAM wParam, LPARAM lParam);
	bool EngineSetup();
	void DecodeGoDone(int rc);
	void DecodePreviewDone(int rc);
	Engine *decoder;
	afx_msg LONG OnRenameOutput(WPARAM wParam, LPARAM engRenamePtr);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECODEDLG_H__E7BDFF61_F1A9_11D0_8988_444553540000__INCLUDED_)
