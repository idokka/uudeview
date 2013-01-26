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


// UUDCommand.h: interface for the UUDCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UUDCOMMAND_H__F80F5F41_F919_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUDCOMMAND_H__F80F5F41_F919_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class UUDCommand : public CCommandLineInfo  
{
public:
	void ParseParam( LPCTSTR lpszParam, BOOL bFlag, BOOL bLast );
	UUDCommand() { }
	~UUDCommand() { }

};

#endif // !defined(AFX_UUDCOMMAND_H__F80F5F41_F919_11D0_8988_444553540000__INCLUDED_)
