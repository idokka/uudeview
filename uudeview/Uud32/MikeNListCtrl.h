#if !defined(AFX_MIKENLISTCTRL_H__48328DE3_F36A_11D0_8988_444553540000__INCLUDED_)
#define AFX_MIKENLISTCTRL_H__48328DE3_F36A_11D0_8988_444553540000__INCLUDED_

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


// MikeNListCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MikeNListCtrl window

class MikeNListCtrl : public CListCtrl
{
// Construction
public:
	MikeNListCtrl() { }

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MikeNListCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	int GetSelectedList(int slist[], int maxsize);
	BOOL SetImage(int nItem, int nImage);
	int GetImage(int nItem);
	CPoint clickAddr;
	virtual ~MikeNListCtrl() { }
	inline bool GetSel(int index) 
		{ return(GetItemState(index, LVIS_SELECTED) != 0); }
	inline BOOL SetSel(int index, bool selected)
		{ return(SetItemState(index, 
			(selected) ? LVIS_SELECTED : 0, LVIS_SELECTED)); }

	// Generated message map functions
protected:
	NMHDR nmh;
	//{{AFX_MSG(MikeNListCtrl)
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIKENLISTCTRL_H__48328DE3_F36A_11D0_8988_444553540000__INCLUDED_)
