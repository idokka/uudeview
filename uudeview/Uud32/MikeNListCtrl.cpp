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


// MikeNListCtrl.cpp : implementation file; slightly modified list control
//

#include "stdafx.h"
#include "Uud32.h"
#include "MikeNListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MikeNListCtrl

#if SKIP
MikeNListCtrl::MikeNListCtrl()
{
}

MikeNListCtrl::~MikeNListCtrl()
{
}
#endif

BEGIN_MESSAGE_MAP(MikeNListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(MikeNListCtrl)
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MikeNListCtrl message handlers

void MikeNListCtrl::OnRButtonUp(UINT nFlags, CPoint point) 
{

	clickAddr = point;						// Store the mouse location
	ClientToScreen(&clickAddr);				// Reformat to screen coordinates
	
// Doing our own processing
//	CListCtrl::OnRButtonUp(nFlags, point);

	CWnd *p = GetParent();

	ASSERT(p != NULL);				// Flag me if parent is null

	if (p != NULL)
		p->PostMessage(WM_COMMAND, 
			(WPARAM) GetDlgCtrlID(), (LPARAM) m_hWnd);
	
}


//
// Allow the button-down message to go through unmolested
//

void MikeNListCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	
// Prevent the control from processing the R_BUTTONDOWN message
//	CListCtrl::OnRButtonDown(nFlags, point);

}


//
// Retrieve the icon used by an item
//
// Returns -1 if something goes wrong
//

int MikeNListCtrl::GetImage(int nItem)
{
	LV_ITEM item;

	item.iItem = nItem;
	item.iSubItem = 0;
	item.mask = LVIF_IMAGE;

return((GetItem(&item)) ? item.iImage : -1);
}


//
// Sets the icon used by an item
//

BOOL MikeNListCtrl::SetImage(int nItem, int nImage)
{
	LV_ITEM item;

	item.iItem = nItem;
	item.iSubItem = 0;
	item.mask = LVIF_IMAGE;

	item.iImage = nImage;

return(SetItem(&item));
}


//
// Return the list of selected items to an integer array
//
// At most maxsize items will be copied
//

int MikeNListCtrl::GetSelectedList(int slist[], int maxsize)
{

	int rmax = GetItemCount();

	int *sl = slist;

	for (int row=0; row < rmax; row++)
		if (GetSel(row))
		{
			if (maxsize-- > 0)
				*sl++ = row;
			else
				break;				// Out of space in array
		}

return(sl - slist);					// Return the number of items found
}
