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


// UUDCommand.cpp: implementation of the UUDCommand class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Uud32.h"
#include "UUDCommand.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#if SKIP
UUDCommand::UUDCommand()
{

}

UUDCommand::~UUDCommand()
{

}
#endif

//
// Parse the commands
//

void UUDCommand::ParseParam(LPCTSTR lpszParam, BOOL bFlag, BOOL bLast)
{

	((CUud32App *) AfxGetApp())->AddParam(bFlag, lpszParam);

}
