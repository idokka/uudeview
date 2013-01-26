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

//
// Mapped File Class
//
#include "windows.h"
#include "mapdfile.h"
#pragma hdrstop

#define SKIP 0

//
// Constructor
//

MappedFile::MappedFile()
{

fhd = NULL;				// File handle
fmap = NULL;			// File map handle
buf = NULL;				// Pointer to memory buffer

mapsize = 0;

}



//
// Open Existing file for reading
//

bool MappedFile::ReadExisting(const char *FileName)
{
	BY_HANDLE_FILE_INFORMATION fi;

Close();						// Make sure there's nothing already open

if ((fhd = CreateFile(FileName, GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, 0)) == INVALID_HANDLE_VALUE)
	return(false);					// File couldn't be opened

if (GetFileInformationByHandle(fhd, &fi) == FALSE) {	// Read information about file
	CloseHandle(fhd);			// Close the open file
	return(false);
	}

if (fi.nFileSizeHigh != 0) {	// Can't process files greater than 4GB
	CloseHandle(fhd);
	return(false);
	}

if ((fmap = CreateFileMapping(fhd, NULL, PAGE_READONLY, 0, 0, NULL)) == NULL) {
	CloseHandle(fhd);			// Close the open file
	return(false);
	}

if ((buf = (byte *) MapViewOfFile(fmap, FILE_MAP_READ, 0, 0, 0)) == NULL) {
	CloseHandle(fmap);			// Destroy the file mapping object
	CloseHandle(fhd);			// Close the open file
	return(false);
	}

mapsize = fi.nFileSizeLow;		// This is also the map size

return(true);
}



//
// Destructor
//

MappedFile::~MappedFile()
{

Close();				// Wipe it out

}



//
// Close it
//

void MappedFile::Close()
{

if (buf != NULL)
	UnmapViewOfFile(buf);			// Do the cleanup

if (fmap != NULL)
	CloseHandle(fmap);

if (fhd != NULL)
	CloseHandle(fhd);

fhd = NULL;				// File handle
fmap = NULL;			// File map handle
buf = NULL;				// Pointer to memory buffer

}



//
// Get the current file size
//

unsigned long MappedFile::GetFileSize()
{
	BY_HANDLE_FILE_INFORMATION fi;

if (GetFileInformationByHandle(fhd, &fi) == FALSE)	// Read information about file
	return(0);			// Unknown...

return(fi.nFileSizeLow);
}



#if SKIP
//
// OpenRW grabs a map for "all access"
//
// Returns true for OK
//

bool MappedFile::OpenRW(
const char *FileName,							// File to open/create
DWORD offset,									// Offset into file of map (0xF --> End of file)
DWORD msize)									// Size of the map to create (0 -> whole file)
{
	BY_HANDLE_FILE_INFORMATION fi;

Close();						// Make sure there's nothing already open

if ((fhd = CreateFile(FileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, 0)) == INVALID_HANDLE_VALUE)
	return(false);					// File couldn't be opened

if (GetFileInformationByHandle(fhd, &fi) == FALSE) {	// Read information about file
	CloseHandle(fhd);			// Close the open file
	return(false);
	}

if (fi.nFileSizeHigh != 0) {	// Can't process files greater than 4GB
	CloseHandle(fhd);
	return(false);
	}

if (offset == 0xFFFFFFFF)		// End of file
	offset = fi.nFileSizeLow;		// Use the file size...

if (msize == 0)
	msize = fi.nFileSizeLow;	// Map whole file

if ((fmap = CreateFileMapping(fhd, NULL, PAGE_READWRITE, 0, msize, NULL)) == NULL) {
	CloseHandle(fhd);			// Close the open file
	return(false);
	}

if ((buf = (byte *) MapViewOfFile(fmap, FILE_MAP_READ, 0, 0, 0)) == NULL) {
	CloseHandle(fmap);			// Destroy the file mapping object
	CloseHandle(fhd);			// Close the open file
	return(false);
	}


return(true);
}
#endif



//
// Create a mapped file for writing
//

bool MappedFile::CreateW(
const char *fileName,
DWORD nfSize)
{

	Close();						// Make sure there's nothing already open

	if ((fhd = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS, 0)) == INVALID_HANDLE_VALUE)
		return(false);					// File couldn't be opened

	if ((fmap = CreateFileMapping(fhd, NULL, PAGE_READWRITE, 0, nfSize, NULL)) == NULL) 
	{
		CloseHandle(fhd);			// Close the open file
		return(false);
	}

	if ((buf = (byte *) MapViewOfFile(fmap, FILE_MAP_WRITE, 0, 0, nfSize)) == NULL) 
	{
		CloseHandle(fmap);			// Destroy the file mapping object
		CloseHandle(fhd);			// Close the open file
		return(false);
	}

return(true);
}

