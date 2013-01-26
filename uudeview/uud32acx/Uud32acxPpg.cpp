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

// Uud32acxPpg.cpp : Implementation of the UUDeview ActiveX property page class.

#include "stdafx.h"
#include "uud32acx.h"
#include "Uud32acxPpg.h"
#pragma hdrstop

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CUud32acxPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CUud32acxPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CUud32acxPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CUud32acxPropPage, "UUD32ACX.Uud32acxPropPage.1",
	0x6fc838a7, 0xa54a, 0x11d0, 0x89, 0x88, 0x44, 0x45, 0x53, 0x54, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// CUud32acxPropPage::CUud32acxPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CUud32acxPropPage

BOOL CUud32acxPropPage::CUud32acxPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_UUD32ACX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CUud32acxPropPage::CUud32acxPropPage - Constructor

CUud32acxPropPage::CUud32acxPropPage() :
	COlePropertyPage(IDD, IDS_UUD32ACX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CUud32acxPropPage)
	m_brack = FALSE;
	m_desp = FALSE;
	m_dumbmode = FALSE;
	m_fmode = FALSE;
	m_ign = FALSE;
	m_opp = _T("");
	m_ovw = FALSE;
	m_verb = FALSE;
	m_xfa = FALSE;
	m_UseText = FALSE;
	m_rmvafter = FALSE;
	m_strict = FALSE;
	m_strictFn = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CUud32acxPropPage::DoDataExchange - Moves data between page and properties

void CUud32acxPropPage::DoDataExchange(CDataExchange* pDX)
{

	//{{AFX_DATA_MAP(CUud32acxPropPage)
	DDP_Check(pDX, IDC_BRACK, m_brack, _T("BracketPolicy") );
	DDX_Check(pDX, IDC_BRACK, m_brack);
	DDP_Check(pDX, IDC_DESP, m_desp, _T("Desperate") );
	DDX_Check(pDX, IDC_DESP, m_desp);
	DDP_Check(pDX, IDC_DUMB, m_dumbmode, _T("Dumb") );
	DDX_Check(pDX, IDC_DUMB, m_dumbmode);
	DDP_Check(pDX, IDC_FAST, m_fmode, _T("FastMode") );
	DDX_Check(pDX, IDC_FAST, m_fmode);
	DDP_Check(pDX, IDC_IGNREPLY, m_ign, _T("IgnoreReply") );
	DDX_Check(pDX, IDC_IGNREPLY, m_ign);
	DDP_Text(pDX, IDC_OPEDIT, m_opp, _T("OutputPath") );
	DDX_Text(pDX, IDC_OPEDIT, m_opp);
	DDP_Check(pDX, IDC_OVERWRITE, m_ovw, _T("Overwrite") );
	DDX_Check(pDX, IDC_OVERWRITE, m_ovw);
	DDP_Check(pDX, IDC_VERBOSE, m_verb, _T("Verbose") );
	DDX_Check(pDX, IDC_VERBOSE, m_verb);
	DDP_Check(pDX, IDC_XFAUTO, m_xfa, _T("XFileAuto") );
	DDX_Check(pDX, IDC_XFAUTO, m_xfa);
	DDP_Check(pDX, IDC_USETEXT, m_UseText, _T("UseText") );
	DDX_Check(pDX, IDC_USETEXT, m_UseText);
	DDP_Check(pDX, IDC_REMOVEAFTER, m_rmvafter, _T("RemoveAfter") );
	DDX_Check(pDX, IDC_REMOVEAFTER, m_rmvafter);
	DDP_Check(pDX, IDC_STRICTMIME, m_strict, _T("StrictMIME") );
	DDX_Check(pDX, IDC_STRICTMIME, m_strict);
	DDP_Check(pDX, IDC_STRICTFN, m_strictFn, _T("StrictFilenames") );
	DDX_Check(pDX, IDC_STRICTFN, m_strictFn);
	//}}AFX_DATA_MAP

	DDP_PostProcessing(pDX);

}


/////////////////////////////////////////////////////////////////////////////
// CUud32acxPropPage message handlers
