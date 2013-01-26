// MikeNPopupMenu.h: interface for the MikeNPopupMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIKENPOPUPMENU_H__48328DE1_F36A_11D0_8988_444553540000__INCLUDED_)
#define AFX_MIKENPOPUPMENU_H__48328DE1_F36A_11D0_8988_444553540000__INCLUDED_

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


class MikeNPopupMenu : public CMenu  
{
public:
	struct PopMenu
	{
		char *str;				// Text to put up (NULL = Separator)
		int id;					// Command ID (-1 is end)
	};

public:
	bool EnableList(bool enable, UINT id0, ...);
	bool EnableItem(UINT id, bool enable);
	BOOL PopIt(CPoint& pt, CWnd *owner);
	bool Load(struct PopMenu *mp);
	MikeNPopupMenu();
	MikeNPopupMenu(struct PopMenu *mp);
	virtual ~MikeNPopupMenu();

};

#endif // !defined(AFX_MIKENPOPUPMENU_H__48328DE1_F36A_11D0_8988_444553540000__INCLUDED_)
