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

//
// UUDCore --- Include functions needed by UUD Core files
//

/////////////////////////////////////////////////////////////////////////////
//
// Force correct order of Win32 libraries

#if !defined(LIB_ORDER_SET)

#ifndef _AFXDLL
	#ifndef _UNICODE
		#ifdef _DEBUG
			#pragma comment(lib, "nafxcwd.lib")
		#else
			#pragma comment(lib, "nafxcw.lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "uafxcwd.lib")
		#else
			#pragma comment(lib, "uafxcw.lib")
		#endif
	#endif
#else
	#ifndef _UNICODE
		#ifdef _DEBUG
			#pragma comment(lib, "mfc42d.lib")
			#pragma comment(lib, "mfcs42d.lib")
		#else
			#pragma comment(lib, "mfc42.lib")
			#pragma comment(lib, "mfcs42.lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "mfc42ud.lib")
			#pragma comment(lib, "mfcs42ud.lib")
		#else
			#pragma comment(lib, "mfc42u.lib")
			#pragma comment(lib, "mfcs42u.lib")
		#endif
	#endif
#endif

#ifdef _DLL
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "msvcrtd.lib")
	#else
		#pragma comment(lib, "msvcrt.lib")
	#endif
#else
#ifdef _MT
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "libcmtd.lib")
	#else
		#pragma comment(lib, "libcmt.lib")
	#endif
#else
	#if !defined(_AFX_NO_DEBUG_CRT) && defined(_DEBUG)
		#pragma comment(lib, "libcd.lib")
	#else
		#pragma comment(lib, "libc.lib")
	#endif
#endif
#endif

#pragma comment(lib, "kernel32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "comdlg32.lib")
#pragma comment(lib, "winspool.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "comctl32.lib")

#define LIB_ORDER_SET 1

#endif				// Lib order not set

//
//
/////////////////////////////////////////////////////////////////////////////

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <errno.h>
#include "time.h"
#include <io.h>
#include "ctype.h"

#include "uudcpp.h"

#define UUEXPORT UUDWrap::
#define TOOLEXPORT UUDWrap::



//
// ------------------------- UUINT.H ------------------------------------------
//

/*
 * Busy Polls will be made after processing ... lines
 */

#define BUSY_LINE_TICKS			50

/*
 * States of MIME scanner
 */

#define MS_HEADERS		1		/* still inside of headers		*/
#define MS_BODY			2		/* body of `simple' messages	*/
#define MS_PREAMBLE		3		/* preamble of Multipart/Mixed	*/
#define MS_SUBPART		4		/* within one of the Multiparts */
#define MS_EPILOGUE		5		/* epilogue of Multipart/Mixed	*/

/*
 * Number of subsequent encoded lines we require to believe this
 * is valid data.
 */

#define ELC_COUNT		4

/*
 * Flags a part may have. FL_PROPER means that we are sure about the file's
 * encoding, beginning and end, and don't have to use special care when de-
 * coding.
 */

#define FL_NONE			0		/* no flag, just plain normal	*/
#define FL_SINGLE		1		/* standalone MSG, do not mix	*/
#define FL_PARTIAL		2		/* from Message/Partial			*/
#define FL_PROPER		4		/* proper MIME part				*/
#define FL_TOEND		8		/* part continues to EOF		*/

/*
 * Auxiliary macro: compute the percentage of a against b.
 * The obvious answer is (100*a)/b, but this overflows for large a.
 * a/(b/100) is better; we use a/((b/100)+1) so that we don't divide
 * by zero for b<100 and the result doesn't become larger than 100%
 */

#define UUPERCENT(a,b)	((int) ((unsigned long)(a) / \
 								(((unsigned long)(b)/100)+1)))

/*
 * Make the Busy Callback easier. The macro returns true if the BusyCallback
 * wants us to terminate.
 */

#define UUBUSYPOLL(a,b) (((++uuyctr%BUSY_LINE_TICKS)==0) ? (progress.percent=UUPERCENT((a),(b)),UUBusyPoll()):0)

#define _ANSI_ARGS_(c)	c

 /*
 * Encoding/Decoding tables
 */

extern unsigned char UUEncodeTable[];
extern unsigned char XXEncodeTable[];
extern unsigned char B64EncodeTable[];
extern unsigned char BHEncodeTable[];

/*
 * String tables from uustring.c
 */

extern char *msgnames[];
extern char *codenames[];
extern char *uuretcodes[];

/* extracted from Id: uustring.c,v 1.8 2002/03/11 09:15:47 fp Exp  */
#define S_NOT_OPEN_SOURCE      1
#define S_NOT_OPEN_TARGET      2
#define S_NOT_OPEN_FILE        3
#define S_NOT_STAT_FILE        4
#define S_SOURCE_READ_ERR      5
#define S_READ_ERROR           6
#define S_IO_ERR_TARGET        7
#define S_WR_ERR_TARGET        8
#define S_WR_ERR_TEMP          9
#define S_TMP_NOT_REMOVED     10
#define S_OUT_OF_MEMORY       11
#define S_TARGET_EXISTS       12
#define S_NOT_RENAME          13
#define S_ERR_ENCODING        14
#define S_STAT_ONE_PART       15
#define S_PARM_CHECK          16
#define S_SHORT_BINHEX        17
#define S_DECODE_CANCEL       18
#define S_ENCODE_CANCEL       19
#define S_SCAN_CANCEL         20
#define S_SIZE_MISMATCH       21
#define S_PSIZE_MISMATCH      22
#define S_CRC_MISMATCH        23
#define S_PCRC_MISMATCH       24
#define S_LOADED_PART         25
#define S_NO_DATA_FOUND       26
#define S_NO_BIN_FILE         27
#define S_STRIPPED_SETUID     28
#define S_DATA_SUSPICIOUS     29
#define S_NO_TEMP_NAME        30
#define S_BINHEX_SIZES        31
#define S_BINHEX_BOTH         32
#define S_SMERGE_MERGED       33
#define S_MIME_NO_BOUNDARY    34
#define S_MIME_B_NOT_FOUND    35
#define S_MIME_MULTI_DEPTH    36
#define S_MIME_PART_MULTI     37
