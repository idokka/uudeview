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

/**
*
* miken.h contains useful things private to my code
*
**/

#define EOS '\0'				// The ever-popular end-of-string

#define SKIP 0					// Cutting out code...

// VB uses mutant TRUE and FALSE...
#define VBTRUE  (-1)
#define VBFALSE (0)

typedef short VBoolean;			// VB can't use a byte like normal people

//
// String Pointers
//

#if !defined(_WIN32)
#define VBSTRP		HLSTR
#define VBSTR		LPSTR
typedef unsigned char boolean;
#define MAKEVBSTR	VBCreateHlstr
#define RETVBSTR	HLSTR
#define MAKERETSTR	VBCreateTempHlstr		// Create string for return
#else
#define VBSTRP		BSTR *
#define VBSTR		BSTR
#define MAKEVBSTR	SysAllocStringByteLen
#define RETVBSTR	BSTR
#define MAKERETSTR	SysAllocStringByteLen
#endif

extern void SETSTR(VBSTRP dest, char *source);	// Set a string
extern void SETSTRL(VBSTRP dest, char *source, unsigned int len);	// Set a string knowing length


//
// Other utility functions
//

extern boolean FExist(const char *filename);	// Tells you if a file exists
extern boolean ListPointerCheck(uulist *u);		// Make sure a list pointer is valid
extern boolean OwriteOK(void);					// Overwriting is OK
extern void UUMCapture(void *opaque, char *message, int level);		// Capture an error message

extern char *last_message;			// Last message from UU library
extern int last_severity;			// Severity of last message

extern void TOOLEXPORT _FP_free (void *ptr);	// Frank's version of free
