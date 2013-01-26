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


// FileName.h: interface for the CFileName class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILENAME_H__C82E2A21_F5EC_11D0_8988_444553540000__INCLUDED_)
#define AFX_FILENAME_H__C82E2A21_F5EC_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//
// Note: #define NO_STDIO to block out the STDIO members
//

class CFileName
{
public:
	CFile *CFileName::Open(const char *mode);
	unsigned long GetFileSize();
	UINT Read(void *buf, UINT len);
	bool Write(const void *buf, UINT len);
	static void KillXFiles();
	void XFile();
	static void XFileAdd(const char *ftoadd);
	bool DirCheck();
	CFileName& SetExt(const char *newext);
	CString& Filename();			// Just the filename
	CFileName& SetFilename(const char *newfn);
	bool Exists();
	bool IsDir();
	bool GetAttr(BYTE *attrp);
	CString& InTemp(const char *name, const char *tempPath = NULL);
	CString& Temp(const char *prefix = "CFN", const char *ext = NULL, const char *tempPath = NULL);
	CString& ShortName();
	bool Is32bit();
	CFileName& operator=(const char *str);
	CFileName& operator=(CString& str);
	int Exec(const char *appname = NULL, const char *args = NULL, int w_flags = 0);
	const char *Ext();
	CString FindExec();
	CString& Path();
	CFileName();
	CFileName(CString& sfn);
	CFileName(const char *sfn);
	~CFileName();

	//
	// Inlines
	//
	inline operator const char *()
	{ 	return((const char *) fn);	}
	inline CString& GetStr()
	{	split = false;	return(fn);	}
	inline bool IsOpen()				// CFile is open
	{	return(cf.m_hFile != CFile::hFileNull);	}
	inline BOOL IsEmpty()
	{	return(fn.IsEmpty());		}


#if !defined(NO_STDIO)
	//
	// Stdio
	//
protected:
	FILE *fp;
	char *bstr_buf;
	long bstr_len;

public:
	bool MakeUnique();
	bool MFRead(void **bufp, long *sizep);
	void ReleaseBuffer();
	char * GetBuffer(int minsize);
	BOOL GetStatus(CFileStatus& fstat);
	void Kill();
	void Close();
	FILE *fopen(const char *mode);
	void fclose();
	inline size_t fwrite(void *buf, size_t size, size_t count)
	{	ASSERT(fp != NULL);
		return(::fwrite(buf, size, count, fp));		}

	inline size_t fread(void *buf, size_t size, size_t count)
	{	ASSERT(fp != NULL);
		return(::fread(buf, size, count, fp));		}

	inline bool fseek(long offset, int origin)
	{	ASSERT(fp != NULL);
		return(::fseek(fp, offset, origin) == 0);	}

	inline bool fgets(char *buf, size_t size)		// Watch the return type!
	{	ASSERT(fp != NULL);
		return(::fgets(buf, size, fp) != NULL);		}

	inline long ftell()
	{	ASSERT(fp != NULL);
		return(::ftell(fp));						}

	inline bool fputs(const char *buf)
	{	ASSERT(fp != NULL);
		return(::fputs(buf, fp) >= 0);					}

	inline bool fputs_cr(const char *buf)
	{	ASSERT(fp != NULL);
		return(::fputs(buf, fp) >= 0 && ::fputc('\n', fp) == '\n');	}

	inline bool fcr()							// Insert a CR/LF
	{	ASSERT(fp != NULL);
		return(::fputc('\n', fp) == '\n');				}

	inline bool stdioOpen()
	{	return(fp != NULL);							}

	bool fputbstr(BSTR string);	// Write out a BSTR
#endif

#if defined(FILENAME_CRC)
	bool crc32(unsigned long *crcp);	// Calculate a CRC32
#endif


protected:
	void UnDice();
	void Dice();
	bool split;					// Path has been split
	char drive[_MAX_DRIVE + 1];
	char dir[_MAX_DIR + 1];
	char name[_MAX_FNAME + 1];
	char ext[_MAX_EXT + 1];

	CString wrk;
	CString fn;

	bool locked;				// Path is locked (GetBuffer)

	bool xfile;					// This is an X file

	CFile cf;					// Access via CFile

	HANDLE mf_fhd;				// Memory file mode handle
	HANDLE mf_fmap;				// Memory file map
	void *mf_buf;				// Memory file buffer pointer
	long mf_size;				// Size of memory file buffer
	
private:
	void ClearVars();
};

#endif // !defined(AFX_FILENAME_H__C82E2A21_F5EC_11D0_8988_444553540000__INCLUDED_)
