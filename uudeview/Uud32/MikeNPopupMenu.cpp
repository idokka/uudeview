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


// MikeNPopupMenu.cpp: implementation of the MikeNPopupMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Uud32.h"
#include "MikeNPopupMenu.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MikeNPopupMenu::MikeNPopupMenu()
{

	CreatePopupMenu();

}

MikeNPopupMenu::MikeNPopupMenu(struct PopMenu *mp)
{

	CreatePopupMenu();
	Load(mp);

}

MikeNPopupMenu::~MikeNPopupMenu()
{

	DestroyMenu();

}


//
// Populate the popup menu
//

bool MikeNPopupMenu::Load(struct PopMenu * mp)
{

	ASSERT(mp != NULL);				// Flag null pointer

	while (mp->id >= 0)
	{
		if (!((mp->str == NULL) ? 
				AppendMenu(MF_SEPARATOR, 0, (LPCTSTR) NULL) :
				AppendMenu(MF_STRING, mp->id, mp->str)))
			return(false);			// Error!

		mp++;
	}

return(true);
}


//
// Actually display the menu
//

BOOL MikeNPopupMenu::PopIt(CPoint& pt, CWnd * owner)
{

return(TrackPopupMenu(
		TPM_LEFTBUTTON | TPM_LEFTALIGN,
		pt.x, pt.y,
		owner, NULL));

}


//
// Enables or disables an item
//
// Returns the new state
//

bool MikeNPopupMenu::EnableItem(UINT id, bool enable)
{

	EnableMenuItem(id, 
		(enable) ? (MF_BYCOMMAND | MF_ENABLED) : (MF_BYCOMMAND | MF_GRAYED));

return(enable);
}


//
// Handle a whole list of enables or disables
//

bool MikeNPopupMenu::EnableList(bool enable, UINT id0, ...)
{
	va_list vap;
	UINT id;

	va_start(vap, enable);		// Point to first omittable argument

	while ((id = va_arg(vap, UINT)) > 0)
		EnableItem(id, enable);

	va_end(vap);

return(enable);
}
