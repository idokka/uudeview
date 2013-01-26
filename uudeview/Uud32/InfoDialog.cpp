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


// InfoDialog.cpp : implementation file for Information dialog box
//

#include "stdafx.h"
#include "Uud32.h"
#include "InfoDialog.h"

#include "hlp\decode.hh"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
// -------------------------------------
//
//
// Dialog autosizer info
//

static struct CSizeDialog::DialogSizerInit ds_list[] ={
	{ IDOK,				DSZ_NONE,					0	},
	{ IDC_INFOHELP,		DSZ_NONE,					0	},
	{ IDC_INFOTITLE,	DSZ_SIZEW,					0	},
	{ IDC_INFOEDIT,		DSZ_SIZEH | DSZ_SIZEW,		0	},
	{ -1 }						// End of table marker
	};

/////////////////////////////////////////////////////////////////////////////
// InfoDialog dialog


InfoDialog::InfoDialog(CRect *rp, CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, InfoDialog::IDD, rp, pParent, IDI_INFOICON, 0, 0)
{
	//{{AFX_DATA_INIT(InfoDialog)
	m_Text = _T("");
	m_Title = _T("");
	//}}AFX_DATA_INIT

	LONG dbu = GetDialogBaseUnits();
	int hdbu = (dbu & 0xFFFF);			// Horiz dialog base units
	int vdbu = (dbu >> 16) & 0xFFFF;	// Vert dialog base units

	if (vdbu == 20 && hdbu == 10)		// Large fonts
	{
		min_w = 300;
		min_h = 150;
	}
	else if (vdbu = 16 && hdbu == 8)	// Small fonts
	{
		min_w = 268;
		min_h = 111;
	}
	else 								// Calculate size
	{
		// pixelX = (templateunitX * baseunitX) / 4 
		// pixelY = (templateunitY * baseunitY) / 8

		min_w = (120 * hdbu) / 4;
		min_h = (60 * vdbu) / 8;
	}
}


void InfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InfoDialog)
	DDX_Text(pDX, IDC_INFOEDIT, m_Text);
	DDX_Text(pDX, IDC_INFOTITLE, m_Title);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InfoDialog, CSizeDialog)
	//{{AFX_MSG_MAP(InfoDialog)
	ON_BN_CLICKED(IDC_INFOHELP, OnInfoHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//
// Trip the help
//

void InfoDialog::OnInfoHelp() 
{

	AfxGetApp()->WinHelp(Decode_Info_Defn, HELP_CONTEXT);
	
}
