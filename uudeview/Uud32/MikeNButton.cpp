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


// MikeNButton.cpp : implementation file for a few simple Button extensions
//

#include "stdafx.h"
#include "Uud32.h"
#include "MikeNButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MikeNButton

#if SKIP
MikeNButton::MikeNButton()
{
}
#endif

MikeNButton::~MikeNButton()
{

#if SKIP
	Pop(false);			// Make sure it's gone from the button state stack, but don't restore
#endif

}


BEGIN_MESSAGE_MAP(MikeNButton, CButton)
	//{{AFX_MSG_MAP(MikeNButton)
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MikeNButton message handlers


//
// Enable, Disable
//

void MikeNButton::Enable()
{

	if (!Enabled())
		EnableWindow(TRUE);

}

void MikeNButton::Disable()
{

	if (Enabled())
		EnableWindow(FALSE);

}


//
// Set the label to a string resource
//

void MikeNButton::SetLabel(int msg_no)
{

	CString wrk;

	wrk.LoadString(msg_no);

	SetWindowText(wrk);

}



//
// Try fixing the highlighting problem
//

void MikeNButton::OnKillFocus(CWnd* pNewWnd) 
{
	CButton::OnKillFocus(pNewWnd);
	
	InvalidateRect(NULL, TRUE);
	
}
