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


// SizeDialog.h: interface for the CSizeDialog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIZEDIALOG_H__BF7F37E3_F5D1_11D0_8988_444553540000__INCLUDED_)
#define AFX_SIZEDIALOG_H__BF7F37E3_F5D1_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//
// Motion flags
//
#define DSZ_NONE		0x00000000			// Do nothing

#define DSZ_MOVEX		0x00000001
#define DSZ_MOVEY		0x00000002
#define DSZ_MOVEX_D		0x00000004			// Custom divisor
#define DSZ_MOVEY_D		0x00000008
#define DSZ_SPANX		0x00000010			// Drape across the whole box
#define DSZ_CTRX		0x00000020			// Center across stacked control
#define DSZ_RTX			0x00000040			// Right-align the control
#define DSZ_LFX			0x00000080			// Left align the control

#define DSZ_SIZEW		0x00010000
#define DSZ_SIZEH		0x00020000
#define DSZ_SIZEW_D		0x00040000			// Custom divisor
#define DSZ_SIZEH_D		0x00080000

#define DSZ_SET_D		0x80000000			// Set the custom divisor
#define DSZ_STACK		0x40000000			// Stack the last control's dimensions
#define DSZ_NOCTRL		0xB0000000			// Check for "not a control"

//
// -----------------------------------
//

class CSizeDialog : public CDialog  
{
public:
	struct DialogSizerInit			// Used to set up dialog sizer
	{
		int dlgID;					// The ID of the control (-1 -> End of list)
		int flags;					// Motions to do
		int help_context;			// Support for help context reflection
		int tooltip;				// Tool tips number
	};

public:
	bool SetToolTip(int ctrlID, int tipString);
	int ArgMessageBox(const char *label, UINT flags, const char *format, ...);
//	int GetToolTip(int ctrlID);
	bool SaveSize(CRect *rp = NULL);
	void Adjust();
	BOOL OnInitDialog();
	CSizeDialog();
	CSizeDialog(struct DialogSizerInit *ilist, 
		UINT dlgID,	CRect *rp = NULL, 
		CWnd *parent = NULL, UINT icon = 0, int min_w = 0, int min_h = 0);
	~CSizeDialog();

protected:
	void Setup();
	CRect *wSizep;
	UINT iconID;
	int count;						// Number of items in list

	struct DialogSizerInit *initlist;

	CWnd *tl_parent;

	int ref_height;					// Original height
	int ref_width;					// Original width

	int min_h;						// Minimum size
	int min_w;

	int cdiv_x, cdiv_y;

	int x_span_count;					// Number of items being spanned across x

	CRect posn_stack;				// Stack the position

	struct DialogSizerList			// The internal list of controls
	{
		struct DialogSizerInit ii;	// Initial information
		CRect ctrl_posn;				// Original window position
	} *ctrList;

	// Generated message map functions
	//{{AFX_MSG(CSizeDialog)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnDestroy();
	afx_msg BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	protected:
		struct SD_Enabled_s {
			int ctrlID;
			struct SD_Enabled_s *next;
			} *enable_top;

		void UnStackEnabled(BOOL oldsta = FALSE);
		void StackEnabled();
		void EnablePushExcept(BOOL newsta, ...);

		enum SD_Helpmode {
			HELP_INACTIVE,
			HELP_ACTIVE,
			HELP_ENTERING
			} m_bHelpMode;

		HCURSOR hcurHelp;
		HCURSOR hArrow;

		const char *dlgName;

		BOOL CanEnterHelpMode();
		void OnContextHelp();
		void AfxContextHelp(DWORD *pContext);
		HWND SetHelpCapture(POINT point, BOOL* pbDescendant);
		BOOL CSizeDialog::ProcessHelpMsg(MSG& msg, DWORD* pContext);
};

#endif // !defined(AFX_SIZEDIALOG_H__BF7F37E3_F5D1_11D0_8988_444553540000__INCLUDED_)
