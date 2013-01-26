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

// UudEng.h: interface for the UudEng class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UUDENG_H__292CC402_02FA_40AF_82C8_18FDB7563379__INCLUDED_)
#define AFX_UUDENG_H__292CC402_02FA_40AF_82C8_18FDB7563379__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../uud32acx/uudcpp.h"
#include "mstring.h"

class UudEng : public UUDWrap  
{
public:
	HRESULT DRemove(short row);
	UudEng();
	virtual ~UudEng();

	inline uulist *GetUulp(short row) 		// Get a uulist pointer
	{
		if (!uCacheValid)
			uCacheBuild();

	return((row < 0 || row >= uCacheCount) ? NULL : uCache[row]);
	}

	inline short GetCacheCount()			// Read the number of items
	{
		if (!uCacheValid)
			uCacheBuild();

		return(uCacheCount);
	}

	inline void Invalidate()
	{
		uCacheValid = false;		// Cached pointer array no longer valid

		infovalid = false;				// Info becomes invalid with every load
	}

	void InfoClear();		// Dump out the info list

	HRESULT GetInfo(short row, MString &retVal);	// Get information about a row

	int UUInfoHandler(void *opaque, char *uugen_inbuffer);

	void SetCallbacks(void *opaque,
		void (*Msg)(void *, const char *, int),
		int (*Prog)(void *, uuprogress *u));			// Set the the callbacks

	MString temp_folder;		// Storage for temporary folder name

	char *tempnam(const char *dir, const char *prefix) const; 	// Create a temporary filename


protected:

	void MessageHandler(char *message, int level);		// Callbacks from the decoder

	int BusyCallback(uuprogress *);

	bool uCacheValid;
	uulist **uCache;		// Array of cached uulist pointers
	short uCacheSize;		// Current size of cache array
	short uCacheCount;		// Number of items in array

	void uCacheBuild(void);	// Create the UUlist * cache

	bool infovalid;			// Info list is valid

	char *info_buffer;		// Info accumulator
	char *info_pointer;		// Point into the accumulator buffer

	class InfoClass 		// Master Information List
	{
		public:
			InfoClass()
			{
				state = ILS_UNK;
				next = NULL;
				row = -1;
			}

			InfoClass(short newRow)
			{
				state = ILS_UNK;
				next = NULL;
				row = newRow;
			}

			MString info;

			enum 
			{
				ILS_UNK,			// Info unknown
				ILS_NO,				// No info
				ILS_YES				// Yes, there is info
			} state;

			InfoClass *next;

			short row;			// Row this is associated with

			InfoClass *SearchAndAdd(short toFind)
			{
				InfoClass *sp;

				for (sp=this; sp != NULL; sp=sp->next)
					if (sp->row == toFind)
						return(sp);

				sp = new InfoClass();

				sp->next = next;

				next = sp;

				sp->row = toFind;

				return(sp);
			}

	};

	InfoClass *ICList;			// Info class list

	void *callbackPtr;				// Opaque pointer for callbacks

	void (*MsgCallback)(void *opaque, const char *message, int level);
	int (*ProgCallback)(void *opaque, uuprogress *u);

};

#endif // !defined(AFX_UUDENG_H__292CC402_02FA_40AF_82C8_18FDB7563379__INCLUDED_)
