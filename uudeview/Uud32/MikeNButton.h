#if !defined(AFX_MIKENBUTTON_H__48328DE2_F36A_11D0_8988_444553540000__INCLUDED_)
#define AFX_MIKENBUTTON_H__48328DE2_F36A_11D0_8988_444553540000__INCLUDED_

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


// MikeNButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MikeNButton window

class MikeNButton : public CButton
{
// Construction
public:
	MikeNButton() { }

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MikeNButton)
	//}}AFX_VIRTUAL

// Implementation
public:
#if SKIP
	static void PushList(BOOL newstate, CWnd *w, ...);
	static void Push(CWnd *w, BOOL newstate = FALSE);
	static void PopAll(bool restore = true);
	void Push(bool enabled = false);
	bool Pop(bool restore = true);
#endif
	void Disable();
	void Enable();
	inline void SetLabel(const char *label)
		{ SetWindowText(label); }
	void SetLabel(int msg_no);
	inline bool Enabled()
		{ return(IsWindowEnabled() != 0); }
	virtual ~MikeNButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(MikeNButton)
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIKENBUTTON_H__48328DE2_F36A_11D0_8988_444553540000__INCLUDED_)
