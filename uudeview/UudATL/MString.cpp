/*
 * This file is part of the UUDeview ActiveX Control, a powerful,
 * simple and friendly multi-part multi-file encoder/decoder
 * software component.
 *
 *	Copyright (c) 1997, 2001 by:
 *		Michael Newcomb <miken@miken.com>
 *		Frank Pilhofer	<fp@informatik.uni-frankfurt.de>
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

// MString.cpp: implementation of the MString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MString.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MString::MString()
{

	Init();

}

MString::MString(const char *startVal)
{

	Init();

	*this = startVal;

}

MString::MString(const BSTR startVal)
{

	Init();

	*this = startVal;

}

MString::MString(const MString &src)
{

	Init();

	if (src.allocLen != 0)
	{
		buf = new char[src.allocLen];

		allocLen = src.allocLen;
	}

	lstrcpy(buf, src.buf);

}

MString::~MString()
{

	if (allocLen != 0)			// We have an allocated length
		delete[] buf;

}


//
// Make sure the internal string is long enough to add or replace
//  the indicated length
//

bool MString::EnsureLen(int minLen, bool replace)
{
	int ml = (replace) ? 0 : lstrlen(buf);

	minLen += ml;

	if (allocLen != 0)
	{
		if (minLen < allocLen)		// Long enough
			return(true);

		minLen *= 2;		// Make it much bigger

		char *nbuf = new char[minLen];

		if (nbuf == NULL)
			return(false);

		CopyMemory(nbuf, buf, ml + 1);

		delete[] buf;

		buf = nbuf;

		allocLen = minLen;
	}
	else if (minLen >= MSTRING_DLEN)
	{
		minLen *= 2;

		char *nbuf = new char[minLen];

		if (nbuf == NULL)
			return(false);

		if (ml == 0)
			nbuf[0] = EOS;
		else
			CopyMemory(nbuf, sbuf, ml + 1);

		buf = nbuf;

		allocLen = minLen;
	}

return(true);
}


//
// Assignment from LPCSTR
//

MString & MString::operator =(const char *newVal)
{
	int l = lstrlen(newVal);

	EnsureLen(l, true);

	CopyMemory(buf, newVal, l + 1);

	return(*this);
}



//
// Assignment from MString
//

MString & MString::operator =(const MString &newVal)
{
	int l = newVal.GetLength() + 1;

	EnsureLen(l, true);

	CopyMemory(buf, newVal.buf, l);

	return(*this);
}


//
// Set up the structure
//

void MString::Init()
{

	allocLen = 0;

	buf = sbuf;			// Default pointer

	buf[0] = EOS;

}



//
// Assignment from BSTR
//

MString & MString::operator =(const BSTR src)
{
	int l = WideCharToMultiByte(CP_ACP,
		0, src, -1, NULL, 0, NULL, NULL) + 4;		// Figure out new length

	EnsureLen(l, true);			// Make sure buffer is big enough

	WideCharToMultiByte(CP_ACP,
		0, src, -1, buf, l, NULL, NULL);

return(*this);
}


//
// Retrieve the raw buffer, optionally with a mininum length
//

char * MString::GetBuffer(int minLen)
{

	if (minLen > 0)
		EnsureLen(minLen, true);

return(buf);
}



//
// Convert a string to wide chars
//

int MString::ToBSTR(BSTR *dest)
{

	int l = MultiByteToWideChar(CP_ACP,
		0, buf, -1, NULL, 0);			// Read needed length

	if (l > 0)
		l--;

	if (*dest != NULL)
		SysReAllocStringLen(dest, NULL, l);
	else
		*dest = SysAllocStringLen(NULL, l);

return(MultiByteToWideChar(CP_ACP, 0, buf, -1, *dest, l));
}


//
// Append something to the string
//

MString & MString::operator +=(const char *append)
{

	EnsureLen(lstrlen(append));

	lstrcat(buf, append);

return(*this);
}


//
// Convert string to a BSTR in a Variant
//

int MString::ToBSTR(VARIANT *vdest)
{
	VariantClear(vdest);

	vdest->vt = VT_BSTR;

	return(ToBSTR(&vdest->bstrVal));
}
