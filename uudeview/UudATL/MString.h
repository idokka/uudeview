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

// MString.h: interface for the MString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSTRING_H__C89830AC_C13A_406B_BA78_5A3450B78BFC__INCLUDED_)
#define AFX_MSTRING_H__C89830AC_C13A_406B_BA78_5A3450B78BFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MSTRING_DLEN 256			// Default length for strings

class MString  
{
public:
	int ToBSTR(VARIANT *vdest);
	int ToBSTR(BSTR *dest);
	char * GetBuffer(int minLen = 0);
	MString();
	MString(const char *startVal);
	MString(const MString &src);
	MString(const BSTR src);
	virtual ~MString();

	inline operator const char *()
	{ return(buf); }

	MString & operator =(const char *newVal);		// Straight assignment, LPCSTR
	MString & operator =(const BSTR src);		// Straight assignment, BSTR
	MString & operator =(const MString &src);		// Copy

	MString & operator +=(const char *append);	// Append LPCSTR

	inline bool operator==(const char *cmp) const
	{ return(lstrcmp(buf, cmp) == 0); }

	inline char operator[](int offset) const
	{ return(buf[offset]); }

	inline bool IsEmpty() const				// Is the string empty?
	{ return(buf[0] == EOS); }

	inline int GetLength() const		// Read the string's length
	{ return(lstrlen(buf)); }

	inline void Empty()				// Empty out the string
	{ buf[0] = EOS; }

	inline operator const char *() const		// Just return the buffer
	{ return((const char *) buf); }

protected:
	void Init();
	bool EnsureLen(int minLen, bool replace = false);	// Make sure the string is long enough

	char sbuf[MSTRING_DLEN + 2];	// Default buffer

	int allocLen;			// Allocated length, 0 for none

	char *buf;				// Pointer to the buffer

};

#endif // !defined(AFX_MSTRING_H__C89830AC_C13A_406B_BA78_5A3450B78BFC__INCLUDED_)
