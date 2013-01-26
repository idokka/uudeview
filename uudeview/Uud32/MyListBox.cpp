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


// MyListBox.cpp : implementation file
//

#include "stdafx.h"
#include "Uud32.h"
#include "MyListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MyListBox

#if SKIP
MyListBox::MyListBox()
{
}

MyListBox::~MyListBox()
{
}
#endif


BEGIN_MESSAGE_MAP(MyListBox, CListBox)
	//{{AFX_MSG_MAP(MyListBox)
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MyListBox message handlers

void MyListBox::OnRButtonUp(UINT nFlags, CPoint point) 
{

	clickAddr = point;						// Store the mouse location
	ClientToScreen(&clickAddr);				// Reformat to screen coordinates
	
	CListBox::OnRButtonUp(nFlags, point);

	CWnd *p = GetParent();

	if (p != NULL)
		p->PostMessage(WM_COMMAND, 
			(WPARAM) GetDlgCtrlID(), (LPARAM) m_hWnd);

}


//
// Return the first selected item or -1 if none
//

int MyListBox::GetFirstSel()
{

	int row, rmax = GetCount();

	for (row=0; row < rmax; row++)		// Find out what is selected (where the problem is)
		if (GetSel(row))
			return(row);			// Got it

return(-1);
}
