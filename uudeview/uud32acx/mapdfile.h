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
// Mapped File class header
//

class MappedFile {
	private:
		HANDLE fhd;				// File handle
		HANDLE fmap;			// File map handle
		byte *buf;				// Pointer to memory buffer
		unsigned long mapsize;	// Size of the map

	public:
		MappedFile();
		~MappedFile();

		bool ReadExisting(const char *FileName);	// Open and map in existing file for read only
		unsigned long GetFileSize();	// Read the file size
		void Close();

		bool CreateW(const char *fileName, DWORD nfSize);	// Create a presized file for writing

		//
		// Some predefined quickies
		//
		void *GetBuffer() { return((void *) buf); }
		operator void*() { return((void *) buf); }
		unsigned long GetMapSize() { return(mapsize); }

	};

