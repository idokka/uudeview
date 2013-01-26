#if !defined(AFX_UUD32ACX_H__6FC838AC_A54A_11D0_8988_444553540000__INCLUDED_)
#define AFX_UUD32ACX_H__6FC838AC_A54A_11D0_8988_444553540000__INCLUDED_

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

// uud32acx.h : main header file for UUD32ACX.DLL

#if !defined(OCX)
#if defined(_USRDLL)
#define OCX 1
#define STRING BSTR
#else
#define OCX 0
#define STRING CString
#endif
#endif

#if OCX
#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#define SKIP 0

#define EOS '\0'

#if !defined(OCX)
#if defined(_USRDLL)
#define OCX 1
#else
#define OCX 0
#endif
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUud32acxApp : See uud32acx.cpp for implementation.

class CUud32acxApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;
#endif								// OCX

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UUD32ACX_H__6FC838AC_A54A_11D0_8988_444553540000__INCLUDED)
