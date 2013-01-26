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

// UudEng.cpp: implementation of the UudEng class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UudEng.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UudEng::UudEng()
{
	uCache = NULL;
	uCacheValid = false;

	infovalid = false;

	info_buffer = NULL;

	ICList = NULL;

	callbackPtr = NULL;

	MsgCallback = NULL;
	ProgCallback = NULL;

}

UudEng::~UudEng()
{

	if (uCache != NULL)
		delete [] uCache;

	if (info_buffer != NULL)
		free(info_buffer);			// Destroy the info_buffer

	InfoClear();

}


//
// uCacheBuild creates the array of uulist *'s
//

void UudEng::uCacheBuild(void)
{
	uulist *up, **cp;

uCacheCount = 0;

for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
	uCacheCount++;					// Count the number of files

if (uCacheCount == 0) {			// Nothing in list, no point in building cache
	uCacheValid = true;
	return;
	}

if (uCache == NULL || uCacheCount >= uCacheSize) {
	if (uCache != NULL)
		delete [] uCache;			// Get rid of the old array

	uCache = new uulist *[uCacheCount + 1];	// Create the array
	uCacheSize = uCacheCount;
	}

cp = uCache;					// Point to the array of cached pointers

for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
	*cp++ = up;

uCacheValid = true;

}



//
// Clear the Info list
//

void UudEng::InfoClear()
{

	InfoClass *icp, *icn;

	for (icp=ICList; icp != NULL; icp=icn)
	{
		icn = icp->next;

		delete icp;
	}

	ICList = NULL;

	infovalid = false;

}



//
// Read the info for a row
//

HRESULT UudEng::GetInfo(short row, MString &ret)
{
	int listlen = 0;
	uulist *up;

	if (!infovalid)
		InfoClear();				// The information isn't valid

	for (up=UUGlobalFileList; up != NULL; up=up->NEXT)
		listlen++;

	if (row >= listlen)				// Index must be less than list length
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	InfoClass *ip;

	if (ICList == NULL)
		ip = ICList = new InfoClass(row);
	else
		ip = ICList->SearchAndAdd(row);

	if (ip->state == InfoClass::ILS_UNK) {		// Need to load the info
		up = GetUulp(row);	// Point to the structure
		if (up->filename == NULL || (up->state & UUFILE_NODATA) || up->uudet == PT_ENCODED)
			ip->state = InfoClass::ILS_NO;		// No info
		else { 
			if (info_buffer == NULL && (info_buffer = (char *) malloc(INFO_BUFFER_SZ)) == NULL)
				return(CTL_E_OUTOFMEMORY);	// Couldn't allocate info buffer

			info_pointer = info_buffer;		// Point to the information buffer
			*info_pointer = EOS;	// Empty buffer

			ip->info.Empty();		// Make sure this list item is empty

			if (UUInfoFile(up, NULL) != UURET_OK)
				ip->state = InfoClass::ILS_NO;	// Info function failed
			else {
				if (info_pointer > info_buffer) {	// Something was retrieved
					ip->info = info_buffer;		// Copy the stored information
					ip->state = InfoClass::ILS_YES;
					}
				else
					ip->state = InfoClass::ILS_NO;
				}
			}
		}

	if (ip->state == InfoClass::ILS_YES)
		ret = ip->info;				// Got some info
	else
		ret.Empty();				// Return the empty string

	infovalid = true;			// If we get here at least some info is valid

return(S_OK);
}



//
// Handle info reads
//

int UudEng::UUInfoHandler(
void *opaque, 
char *inbuf)
{

	int len = strlen(inbuf);		// How long is the add?

	int ttl = (info_pointer - info_buffer) + len;

	if (ttl > (INFO_BUFFER_SZ - 16))
		return(1);							// Just stop

	lstrcpy(info_pointer, inbuf);	// Append the info line

	info_pointer += len;					// Point to next target

	if (ttl > 2 && *(info_pointer - 1) == '\n' && *(info_pointer - 2) != '\r') {	// Unix EOL conversion
		*(info_pointer - 1) = '\r';
		*info_pointer++ = '\n';
		*info_pointer = EOS;
		}

return(0);
}



//
// Message handler
//

void UudEng::MessageHandler(char *message, int level)
{

	if (MsgCallback != NULL)
		(*MsgCallback)(callbackPtr, message, level);

}


//
// Progress Handler
//

int UudEng::BusyCallback(uuprogress *u)
{
	int cflag = FALSE;

	if (ProgCallback != NULL)
		cflag = (*ProgCallback)(callbackPtr, u);

return(cflag); 
}



//
// Set message callbacks
//

void UudEng::SetCallbacks(void *opaque,
void (*Msg)(void *, const char *, int),
int (*Prog)(void *, uuprogress *u))			// Set the the callbacks
{

	callbackPtr = opaque;

	MsgCallback = Msg;

	ProgCallback = Prog;

}



//
// Remove a row
//

HRESULT UudEng::DRemove(short row)
{
	uulist *todel = GetUulp(row);

	if (todel == NULL)
		return(CTL_E_INVALIDPROPERTYARRAYINDEX);

	if (todel == UUGlobalFileList) {	// First item in list!
		UUGlobalFileList = todel->NEXT;	// Delink top...
		if (todel->NEXT != NULL)
			(todel->NEXT)->PREV = NULL;	// Nothing above the next
		}
	else {								// Prev can't be null...
		(todel->PREV)->NEXT = todel->NEXT;	// Shunt previous past delete target
		if (todel->NEXT != NULL)		// There's something after this...
			(todel->NEXT)->PREV = todel->PREV;	// Next bypasses target
		}

	todel->NEXT = NULL;					// Artificial end-of-list for killlist
	UUkilllist(todel);					// Delete the item and its dependants

	uCacheValid = false;					// Cache not set

	return S_OK;
}



//
// Create a temporary filename -- override of base class
//

char *UudEng::tempnam(const char *dir, const char *prefix) const 	// Create a temporary filename
{
	char wrk[MAX_PATH], opp[MAX_PATH];
	UINT rc;

	if (dir != NULL && *dir != EOS)
		rc = GetTempFileName(dir, prefix, 0, opp);
	else if (!temp_folder.IsEmpty())
		rc = GetTempFileName(temp_folder, prefix, 0, opp);
	else
	{
		wrk[0] = EOS;
		GetTempPath(sizeof(wrk), wrk);
		rc = GetTempFileName(wrk, prefix, 0, opp);
	}

return((rc == 0) ? NULL : strdup(opp));
}

