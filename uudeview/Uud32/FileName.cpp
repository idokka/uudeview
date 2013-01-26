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


// FileName.cpp: implementation of the CFileName class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Uud32.h"
#include "FileName.h"

#if !defined(NO_STDIO)
#include "io.h"
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#if defined(FILENAME_CRC)
//
// CRC table
//
static unsigned long crc32tab[256] = { /* CRC polynomial 0xEDB88320  */
    0x00000000L, 0x77073096L, 0xEE0E612CL, 0x990951BAL, 0x076DC419L, 0x706AF48FL, 0xE963A535L, 0x9E6495A3L,
    0x0EDB8832L, 0x79DCB8A4L, 0xE0D5E91EL, 0x97D2D988L, 0x09B64C2BL, 0x7EB17CBDL, 0xE7B82D07L, 0x90BF1D91L,
    0x1DB71064L, 0x6AB020F2L, 0xF3B97148L, 0x84BE41DEL, 0x1ADAD47DL, 0x6DDDE4EBL, 0xF4D4B551L, 0x83D385C7L,
    0x136C9856L, 0x646BA8C0L, 0xFD62F97AL, 0x8A65C9ECL, 0x14015C4FL, 0x63066CD9L, 0xFA0F3D63L, 0x8D080DF5L,
    0x3B6E20C8L, 0x4C69105EL, 0xD56041E4L, 0xA2677172L, 0x3C03E4D1L, 0x4B04D447L, 0xD20D85FDL, 0xA50AB56BL,
    0x35B5A8FAL, 0x42B2986CL, 0xDBBBC9D6L, 0xACBCF940L, 0x32D86CE3L, 0x45DF5C75L, 0xDCD60DCFL, 0xABD13D59L,
    0x26D930ACL, 0x51DE003AL, 0xC8D75180L, 0xBFD06116L, 0x21B4F4B5L, 0x56B3C423L, 0xCFBA9599L, 0xB8BDA50FL,
    0x2802B89EL, 0x5F058808L, 0xC60CD9B2L, 0xB10BE924L, 0x2F6F7C87L, 0x58684C11L, 0xC1611DABL, 0xB6662D3DL,
    0x76DC4190L, 0x01DB7106L, 0x98D220BCL, 0xEFD5102AL, 0x71B18589L, 0x06B6B51FL, 0x9FBFE4A5L, 0xE8B8D433L,
    0x7807C9A2L, 0x0F00F934L, 0x9609A88EL, 0xE10E9818L, 0x7F6A0DBBL, 0x086D3D2DL, 0x91646C97L, 0xE6635C01L,
    0x6B6B51F4L, 0x1C6C6162L, 0x856530D8L, 0xF262004EL, 0x6C0695EDL, 0x1B01A57BL, 0x8208F4C1L, 0xF50FC457L,
    0x65B0D9C6L, 0x12B7E950L, 0x8BBEB8EAL, 0xFCB9887CL, 0x62DD1DDFL, 0x15DA2D49L, 0x8CD37CF3L, 0xFBD44C65L,
    0x4DB26158L, 0x3AB551CEL, 0xA3BC0074L, 0xD4BB30E2L, 0x4ADFA541L, 0x3DD895D7L, 0xA4D1C46DL, 0xD3D6F4FBL,
    0x4369E96AL, 0x346ED9FCL, 0xAD678846L, 0xDA60B8D0L, 0x44042D73L, 0x33031DE5L, 0xAA0A4C5FL, 0xDD0D7CC9L,
    0x5005713CL, 0x270241AAL, 0xBE0B1010L, 0xC90C2086L, 0x5768B525L, 0x206F85B3L, 0xB966D409L, 0xCE61E49FL,
    0x5EDEF90EL, 0x29D9C998L, 0xB0D09822L, 0xC7D7A8B4L, 0x59B33D17L, 0x2EB40D81L, 0xB7BD5C3BL, 0xC0BA6CADL,
    0xEDB88320L, 0x9ABFB3B6L, 0x03B6E20CL, 0x74B1D29AL, 0xEAD54739L, 0x9DD277AFL, 0x04DB2615L, 0x73DC1683L,
    0xE3630B12L, 0x94643B84L, 0x0D6D6A3EL, 0x7A6A5AA8L, 0xE40ECF0BL, 0x9309FF9DL, 0x0A00AE27L, 0x7D079EB1L,
    0xF00F9344L, 0x8708A3D2L, 0x1E01F268L, 0x6906C2FEL, 0xF762575DL, 0x806567CBL, 0x196C3671L, 0x6E6B06E7L,
    0xFED41B76L, 0x89D32BE0L, 0x10DA7A5AL, 0x67DD4ACCL, 0xF9B9DF6FL, 0x8EBEEFF9L, 0x17B7BE43L, 0x60B08ED5L,
    0xD6D6A3E8L, 0xA1D1937EL, 0x38D8C2C4L, 0x4FDFF252L, 0xD1BB67F1L, 0xA6BC5767L, 0x3FB506DDL, 0x48B2364BL,
    0xD80D2BDAL, 0xAF0A1B4CL, 0x36034AF6L, 0x41047A60L, 0xDF60EFC3L, 0xA867DF55L, 0x316E8EEFL, 0x4669BE79L,
    0xCB61B38CL, 0xBC66831AL, 0x256FD2A0L, 0x5268E236L, 0xCC0C7795L, 0xBB0B4703L, 0x220216B9L, 0x5505262FL,
    0xC5BA3BBEL, 0xB2BD0B28L, 0x2BB45A92L, 0x5CB36A04L, 0xC2D7FFA7L, 0xB5D0CF31L, 0x2CD99E8BL, 0x5BDEAE1DL,
    0x9B64C2B0L, 0xEC63F226L, 0x756AA39CL, 0x026D930AL, 0x9C0906A9L, 0xEB0E363FL, 0x72076785L, 0x05005713L,
    0x95BF4A82L, 0xE2B87A14L, 0x7BB12BAEL, 0x0CB61B38L, 0x92D28E9BL, 0xE5D5BE0DL, 0x7CDCEFB7L, 0x0BDBDF21L,
    0x86D3D2D4L, 0xF1D4E242L, 0x68DDB3F8L, 0x1FDA836EL, 0x81BE16CDL, 0xF6B9265BL, 0x6FB077E1L, 0x18B74777L,
    0x88085AE6L, 0xFF0F6A70L, 0x66063BCAL, 0x11010B5CL, 0x8F659EFFL, 0xF862AE69L, 0x616BFFD3L, 0x166CCF45L,
    0xA00AE278L, 0xD70DD2EEL, 0x4E048354L, 0x3903B3C2L, 0xA7672661L, 0xD06016F7L, 0x4969474DL, 0x3E6E77DBL,
    0xAED16A4AL, 0xD9D65ADCL, 0x40DF0B66L, 0x37D83BF0L, 0xA9BCAE53L, 0xDEBB9EC5L, 0x47B2CF7FL, 0x30B5FFE9L,
    0xBDBDF21CL, 0xCABAC28AL, 0x53B39330L, 0x24B4A3A6L, 0xBAD03605L, 0xCDD70693L, 0x54DE5729L, 0x23D967BFL,
    0xB3667A2EL, 0xC4614AB8L, 0x5D681B02L, 0x2A6F2B94L, 0xB40BBE37L, 0xC30C8EA1L, 0x5A05DF1BL, 0x2D02EF8DL
	};
#endif


//
// The master temporary file list
//

struct TempFileList
{
	CString tfname;
	struct TempFileList *next;
};

static struct TempFileList *tf_list = NULL;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFileName::CFileName()
{

	ClearVars();

}

CFileName::CFileName(CString& sfn)
{

	ClearVars();					// Do basic setup

	fn = sfn;

}

CFileName::CFileName(const char *sfn)
{

	ClearVars();					// Do basic setup

	fn = sfn;

}


CFileName::~CFileName()
{

	if (locked)
		fn.ReleaseBuffer();

	Close();						// Close the CFile

#if !defined(NO_STDIO)
	if (fp != NULL)
		::fclose(fp);
#endif

	if (bstr_buf != NULL)
		delete[] bstr_buf;			// Delete the bstring conversion buffer

}


//
// Initialize the Filename variables
//

void CFileName::ClearVars()
{

	split = false;					// No split yet
	locked = false;
	xfile = false;

	bstr_buf = NULL;

#if !defined(NO_STDIO)
	fp = NULL;
#endif

	mf_fhd = mf_fmap = NULL;
	mf_buf = NULL;

}


//
// Read a filename's path
//

CString& CFileName::Path()
{

	if (!split)
		Dice();

	wrk = drive;
	wrk += dir;

return(wrk);
}


//
// Split up the filename
//

void CFileName::Dice()
{

	_splitpath(fn, drive, dir, name, ext);

	split = true;

}


void CFileName::UnDice()
{

	ReleaseBuffer();			// Make sure there's no existing lock

	_makepath(fn.GetBuffer(MAX_PATH+1), drive, dir, name, ext);

	fn.ReleaseBuffer();

	split = true;				// Since it's built from parts, it's already split

}


//
// Retrieve the executable for a filename
//
// Returns the empty string if none.
//

CString CFileName::FindExec()
{
	CString exec;

	unsigned int rc = (unsigned int) FindExecutable(
		fn, Path(), exec.GetBuffer(MAX_PATH));

	exec.ReleaseBuffer();

	if (rc <= 32)
		exec.Empty();		// Failed

return(exec);
}


//
// Return the extension, if any
//
const char *CFileName::Ext()
{
	if (!split)
		Dice();

return(ext);
}


//
// Launches the file.  If the app name is not specified,
//  it will be looked up.
//

int CFileName::Exec(const char *appname, const char *args, int w_flags)
{

	CString cmdline;
	CFileName app;

	if (appname == NULL)
		app = FindExec();		// Look up the executable
	else
		app = appname;			// Store the app name

	cmdline.Format("%s %s %s",
		(const char *) app.ShortName(), 
		(args == NULL) ? "" : args, (const char *) ShortName());

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(STARTUPINFO));

	si.cb = sizeof(STARTUPINFO);

	if (w_flags != 0)
	{
		si.dwFlags = STARTF_USESHOWWINDOW;
		si.wShowWindow = w_flags;
	}

#if SKIP
	CString wrk;
	
	wrk.Format("Command line:\r\n[%s]", (const char *) cmdline);

	::MessageBox(NULL, wrk, "Launch", MB_OK);
#endif

	BOOL rc = CreateProcess(
		NULL,						// Application name
		cmdline.GetBuffer(10),		// Command line
		NULL,						// Process attributes
		NULL,						// Thread attributes
		FALSE,						// Inherit handles
		CREATE_DEFAULT_ERROR_MODE | NORMAL_PRIORITY_CLASS,	// Mode flags
		NULL,						// Environment
		app.Path(),					// Default directory
		&si,						// Startup info
		&pi);						// Process Info

	int err = GetLastError();

	cmdline.ReleaseBuffer();

return((!rc) ? err : 0);	// Return GetLastError if it failed
}

//
// A couple of quick operators
//

CFileName& CFileName::operator=(CString& str)
{

	Close();
	fn = str;
	split = false;

return(*this);
}

CFileName& CFileName::operator=(const char *str)
{

	Close();
	fn = str;
	split = false;

return(*this);
}


char *CFileName::GetBuffer(int minsize)
{

	locked = true;

return(fn.GetBuffer(minsize));
}


void CFileName::ReleaseBuffer()
{

	if (locked)
	{
		fn.ReleaseBuffer();
		locked = false;
	}

}


//
// Tests to see if a file is a 32-bit executable
//

bool CFileName::Is32bit()
{
	DWORD atype;

return(GetBinaryType(fn, &atype) != 0 && (atype & SCS_32BIT_BINARY) != 0);
}


//
// Returns the short name of an executable
//

CString& CFileName::ShortName()
{

	DWORD rc = GetShortPathName(fn, wrk.GetBuffer(MAX_PATH + 1), MAX_PATH);

	wrk.ReleaseBuffer();

	if (rc == 0)
		wrk.Empty();			// It didn't work

return(wrk);
}


//
// Creates a temporary name
//
// With the given prefix and extension
//
CString& CFileName::Temp(const char *prefix, const char *newext, const char *tempPath)
{

	wrk.Empty();

	CString tpath;

	if (tempPath == NULL || tempPath[0] == EOS)		// Caller wants to use std temporary path
	{
		int rc = GetTempPath(MAX_PATH, tpath.GetBuffer(MAX_PATH + 1));

		tpath.ReleaseBuffer();

		if (rc == 0)
			return(wrk);			// No temporary path?
	}
	else
	{
		tpath = tempPath;

		if (tpath[tpath.GetLength() - 1] != '\\')
			tpath += '\\';			// Add a trailing backslash
	}

	if (GetTempFileName(tpath, prefix, 0, fn.GetBuffer(MAX_PATH + 1)) == 0)
		return(wrk);				// No temp path (!)

	fn.ReleaseBuffer();

	if (newext != NULL)
	{
		Dice();						// Break up the name into fragments
		strncpy(ext, newext, _MAX_EXT);
		ext[_MAX_EXT] = EOS;
		UnDice();
	}

return(fn);
}


//
// Creates a filename in the temporary directory
//

CString& CFileName::InTemp(const char *name, const char *tempPath)
{

	wrk.Empty();

	CString tpath;

	if (tempPath == NULL || tempPath[0] == EOS)		// Caller wants to use std temporary path
	{
		int rc = GetTempPath(MAX_PATH, tpath.GetBuffer(MAX_PATH + 1));

		tpath.ReleaseBuffer();

		if (rc == 0)
			return(wrk);			// No temporary path?
	}
	else
		tpath = tempPath;

	char last = tpath[tpath.GetLength() - 1];

	if (last != ':' && last != '\\')
		tpath += '\\';				// Make sure it ends in a backslash

	fn = tpath + name;				// Return the new name
	split = false;

return(fn);
}


//
// Read the file's attributes
//
// Returns true if OK
//

bool CFileName::GetAttr(BYTE *attrp)
{
	CFileStatus fstat;

	if (CFile::GetStatus(fn, fstat))
	{
		*attrp = fstat.m_attribute;
		return(true);
	}

return(false);
}


//
// Find out if a file is a directory
//
// Also returns false if the thing doesn't exist
//

bool CFileName::IsDir()
{
	BYTE attr;

return(GetAttr(&attr) && (attr & CFile::directory));
}


//
// Finds out if the thing exists
//

bool CFileName::Exists()
{

	if (GetFileAttributes(fn) == 0xFFFFFFFF &&	// Couldn't read attributes (good!)
			GetLastError() == ERROR_FILE_NOT_FOUND)
		return(false);					// File doesn't exist

return(true);
}


//
// Set the filename.  Returns a reference to the object (for chaining)
//

CFileName& CFileName::SetFilename(const char *newfn)
{

	if (!split)
		Dice();

	char local_name[_MAX_FNAME + 1];
	char local_ext[_MAX_EXT + 1];

	_splitpath(newfn, NULL, NULL, local_name, local_ext);

	strcpy(name, local_name);
	strcpy(ext, local_ext);

	UnDice();						// Get back the real filename

return(*this);
}


//
// Set the extension
//

CFileName& CFileName::SetExt(const char * newext)
{
	if (!split)
		Dice();

	strncpy(ext, newext, _MAX_EXT);			// Add new extension...

	ext[_MAX_EXT] = EOS;

	UnDice();						// Get back the real filename

return(*this);
}


//
// Retrieve the filename only
//

CString& CFileName::Filename()
{

	if (!split)
		Dice();

	wrk = name;
	wrk += ext;

return(wrk);
}

//
// Find out if the current path is a directory.
//
// If so, move the filename/ext to the dir variable
//
// Returns true if this happened
//

bool CFileName::DirCheck()
{

	if (!split)
		Dice();

	if (IsDir())
	{
		strcat(dir, name);
		name[0] = EOS;
		if (ext[0] != EOS)
		{
			strcat(dir, ".");
			strcat(dir, ext);
		}

		return(true);
	}

return(false);
}


//
// Stdio implementation
//
#if !defined(NO_STDIO)

FILE *CFileName::fopen(const char *mode)
{	
	ASSERT(!fn.IsEmpty()); 
	fclose();

return(fp = ::fopen((const char *) fn, mode));	
}

void CFileName::fclose()
{
	if (fp != NULL)
	{
		::fclose(fp);
		fp = NULL;
	}

}
#endif


//
// X file implementation
//


//
// Add a file to the temporary list
//

void CFileName::XFileAdd(const char *ftoadd)
{
	struct TempFileList *ntp = new struct TempFileList;		// Create a new entry

	ntp->tfname = ftoadd;
	ntp->next = tf_list;
	tf_list = ntp;					// Link it in

}


//
// Add _yourself_ to the X File list
//

void CFileName::XFile()
{

	if (!fn.IsEmpty() && !xfile)
		XFileAdd(fn);

}


//
// Delete all the files on the list
//

void CFileName::KillXFiles()
{
	struct TempFileList *ntp, *n;

	for (ntp=tf_list; ntp != NULL; ntp=n)
	{
		::DeleteFile(ntp->tfname);
		n = ntp->next;
		delete ntp;
	}

	tf_list = NULL;

}


//
// CFile implementation
//


//
// Write out some stuff
//
// Returns false for errors, rather than throwing irritating exceptions
//
bool CFileName::Write(const void *buf, UINT len)
{

	if (!IsOpen())
		return(false);			// Tried to write, but couldn't open

	try {
		cf.Write(buf, len);
	} catch (CFileException e) {
		ASSERT(0);				// If we get here, throw a flag
		return(false);
		}

return(true);
}



//
// Read some stuff
//
// Returns the number of bytes read
//

UINT CFileName::Read(void *buf, UINT len)
{

	if (!IsOpen())
		return(0);				// Nothing to do

	UINT rl;

	try {
		rl = cf.Read(buf, len);
	} catch (CFileException e) {
		rl = 0;					// Just return 0 for errors
		}

return(rl);
}


//
// Get the file size
//

unsigned long CFileName::GetFileSize()
{

#if !defined(NO_STDIO)
	if (fp != NULL)
		return(_filelength(_fileno(fp)));
#endif

	CFileStatus cfs;

	if (IsOpen())
		return(cf.GetStatus(cfs) ? cfs.m_size : 0);

return(CFile::GetStatus(fn, cfs) ? cfs.m_size : 0);
}


BOOL CFileName::GetStatus(CFileStatus & fstat)
{

	return((IsOpen()) ? cf.GetStatus(fstat) : CFile::GetStatus(fn, fstat));

}


//
// Open sets up the file if it hasn't been set up (using C-style file modes)
//
// Opens the file if it's not already open.
//
// Returns a pointer to the CFile member, or NULL for failure
//

CFile *CFileName::Open(const char *mode)
{
	if (IsOpen())
		return(&cf);					// Already open

	UINT flags = 0;

	if (fn.IsEmpty())
	{
		Temp();							// Create a temporary name

		flags |= CFile::modeCreate;		// Make sure we create a new file
	}

	CString fm(mode);

	fm.MakeLower();

	if (fm.Find('r') >= 0)
		flags |= CFile::modeRead;
	else if (fm.Find('w') >= 0)
		flags |= CFile::modeCreate;		// Make sure we create a new file
	else if (fm.Find('a') >= 0)			// Append means open existing or create new...
		flags |= CFile::modeCreate | CFile::modeNoTruncate;

	if (fm.Find('w') >= 0 || fm.Find('a') >= 0 || fm.Find('+') >= 0)
		flags |= CFile::modeWrite;

	flags |= (fm.Find('t') >= 0) ? CFile::typeText : CFile::typeBinary;

	if (cf.Open(fn, flags, NULL) == 0)
	{
		TRACE("Open %s -> Error = %d\r\n",
			(const char *) fn, GetLastError());
		return(NULL);
	}

	if (fm.Find('a') >= 0)				// Caller wants append mode
		cf.SeekToEnd();
	
return(&cf);
}


//
// Close the file if it's open
//

void CFileName::Close()
{

#if !defined(NO_STDIO)
	fclose();
#endif

	if (IsOpen())
		cf.Close();

	if (mf_buf != NULL)				// Do memory file cleanup
	{
		UnmapViewOfFile(mf_buf);
		mf_buf = NULL;
	}

	if (mf_fmap != NULL)
	{
		CloseHandle(mf_fmap);
		mf_fmap = NULL;
	}

	if (mf_fhd != NULL)
	{
		CloseHandle(mf_fhd);
		mf_fhd = NULL;
	}

}


//
// Closes and kills a file
//

void CFileName::Kill()
{

	Close();

	::DeleteFile(fn);

}



#if !defined(NO_STDIO)
//
// Process BStrings for output
//

bool CFileName::fputbstr(BSTR string)
{

	int len = WideCharToMultiByte(CP_OEMCP, 0, string, -1, NULL, 0, NULL, NULL);

	if (bstr_buf == NULL)		// Have to create it...
	{
		bstr_len = (len > 1024) ? len + 32 : 1024;
		bstr_buf = new char[bstr_len];
	}
	else if (len > bstr_len)
	{
		delete[] bstr_buf;
		bstr_len = len + 32;
		bstr_buf = new char[bstr_len];
	}

	WideCharToMultiByte(CP_OEMCP, 0, string, -1, bstr_buf, len, NULL, NULL);
//	CharToOemBuff((const char *) string, bstr_buf, len);
	bstr_buf[len] = EOS;

return fputs(bstr_buf);			// Write it out...
}
#endif



#if defined(FILENAME_CRC)
/**/
/**
*
* crc32 calculates the crc of a buffer
*
**/
#pragma warning(disable : 4035)

static unsigned long ll_crc32(
void * buf,
int len)
{

_asm {
	push	esi
	push	edi

	lea		edi, crc32tab		// Point to CRC table
	mov		esi, [buf]			// Point to buffer
	sub		eax, eax			// Clear accumulator
	mov		ecx, [len]			// Read count

	mov		edx, -1				// Start with all f's

cloop:
	lodsb						// *bp++
	xor		al, dl				// (*bp++ ^ (BYTE) crc)

	shr		edx, 8				// Shift right one byte
	xor		edx, [edi+eax*4]	// XOR in value from table
	loop	cloop				// Power through the whole buffer

	pop		edi
	pop		esi

	mov		eax, edx			// Copy the return value
	not		eax
	}

}

#pragma warning(default : 4035)



/**/
/**
*
* file_crc32 calculates the CRC of a file
*
* Returns true for OK
*
**/

bool CFileName::crc32(unsigned long *crcp)
{
	HANDLE fhd, fmap;
	byte *buf;
	BY_HANDLE_FILE_INFORMATION fi;

// MessageBox(NULL, fname, "Filename", MB_OK);

if ((fhd = CreateFile(fn, GENERIC_READ, 0, NULL, OPEN_EXISTING,
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

*crcp = ll_crc32(buf, fi.nFileSizeLow);		// Compute the CRC

UnmapViewOfFile(buf);			// Do the cleanup
CloseHandle(fmap);
CloseHandle(fhd);

return(true);
}
#endif


//
// Open the file as a Memory File
//

bool CFileName::MFRead(void * *bufp, long *sizep)
{
	BY_HANDLE_FILE_INFORMATION fi;

	if ((mf_fhd = CreateFile(fn, GENERIC_READ, 0, NULL, OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, 0)) == INVALID_HANDLE_VALUE)
		return(false);					// File couldn't be opened

	if (GetFileInformationByHandle(mf_fhd, &fi) == FALSE) {	// Read information about file
		Close();
		return(false);
		}

	if (fi.nFileSizeHigh != 0) {	// Can't process files greater than 4GB
		Close();
		return(false);
		}

	if ((mf_fmap = CreateFileMapping(mf_fhd, NULL, PAGE_READONLY, 0, 0, NULL)) == NULL) {
		Close();
		return(false);
		}

	if ((mf_buf = MapViewOfFile(mf_fmap, FILE_MAP_READ, 0, 0, 0)) == NULL) {
		Close();
		return(false);
		}

	*bufp = mf_buf;					// Return the info
	*sizep = fi.nFileSizeLow;

return(true);
}



//
// MakeUnique adds a number to the end of a filename and keeps incrementing it
//  until the result no longer exists
//
// Returns True for success
//

bool CFileName::MakeUnique()
{
	if (!Exists())
		return(true);			// Already unique

	char gen_name[_MAX_FNAME + 1 + 4];

	Dice();			// Break up the filename

	strcpy(gen_name, name);		// Grab just the filename portion

#if SKIP					// This code looks for an existing trailing number
	char *p = strrchr(gen_name, '_');		// Look for an underscore

	if (p != NULL)			// Got at least one underscore
	{
		char *q;

		for (q=p+1; *q != EOS; q++)		// Make sure it's all digits
			if (*q < '0' || *q > '9')
			{
				p = NULL;		// Non digit, start over
				break;
			}
	}

	int ann = 1;		// Auto number number

	if (p != NULL)			// We found an existing number
		if ((ann = atoi(p+1)) < 1 || ann > 999)		// The existing number isn't acceptable
		{
			p = NULL;
			ann = 1;
		}
		else
			ann++;			// We know we've got this far

	if (p == NULL)
	{
		p = gen_name + strlen(gen_name);		// Point to end of string
		*p++ = '_';
	}
	else
		p++;				// Skip the underscore
#endif

	char *p = gen_name + strlen(gen_name);		// Point to end of string

	*p++ = '_';

	char wrkname[_MAX_PATH + 1 + 4];		// Place to put assembled name

	int ann;

	for (ann=1; ann < 999; ann++)			// Limit this to a reasonable number
	{
		sprintf(p, "%03d", ann);		// Add the numbers

		_makepath(wrkname, drive, dir, gen_name, ext);

		if (GetFileAttributes(wrkname) == 0xFFFFFFFF &&	// Couldn't read attributes (good!)
			GetLastError() == ERROR_FILE_NOT_FOUND)		// File is not found, name OK
		{
			strcpy(name, gen_name);		// Replace the generated numbers

			UnDice();

			return(true);
		}
	}

	UnDice();

return(false);
}
