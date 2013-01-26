#if !defined(AFX_UUD32ACXPPG_H__6FC838B6_A54A_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUD32ACXPPG_H__6FC838B6_A54A_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/*
 * This file is part of the UUDeview ActiveX Control, a powerful,
 * simple and friendly multi-part multi-file encoder/decoder
 * software component.
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

#if OCX
// Uud32acxPpg.h : Declaration of the CUud32acxPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CUud32acxPropPage : See Uud32acxPpg.cpp.cpp for implementation.

class CUud32acxPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CUud32acxPropPage)
	DECLARE_OLECREATE_EX(CUud32acxPropPage)

// Constructor
public:
	CUud32acxPropPage();

// Dialog Data
	//{{AFX_DATA(CUud32acxPropPage)
	enum { IDD = IDD_PROPPAGE_UUD32ACX };
	BOOL	m_brack;
	BOOL	m_desp;
	BOOL	m_dumbmode;
	BOOL	m_fmode;
	BOOL	m_ign;
	CString	m_opp;
	BOOL	m_ovw;
	BOOL	m_verb;
	BOOL	m_xfa;
	BOOL	m_UseText;
	BOOL	m_rmvafter;
	BOOL	m_strict;
	BOOL	m_strictFn;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CUud32acxPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUD32ACXPPG_H__6FC838B6_A54A_11D0_8988_444553540000__INCLUDED)
