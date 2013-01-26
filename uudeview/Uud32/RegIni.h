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


//////////////////////////////////////////////////////////////////////
//
// Allow access to the Registry as an INI file
//
// RegIni.h: interface for the RegIni class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_REGINI_H__EEE4A5E1_F272_11D0_8988_444553540000__INCLUDED_)
#define AFX_REGINI_H__EEE4A5E1_F272_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//
// ---------------------------------
//

#define MAX_MRU		9		// Use this to limit Most Recently Used lists

//
// ---------------------------------
//

class RegIni  
{
protected:
	bool OpenWrite();
	bool OpenRead();
	bool wmode;
	int vno;
	CString KBase;
	bool active;
	HKEY hk;
	CString keycache;

	struct wposn_s			// Structure to store window position
	{
		RECT coord;
		int version;
	};

public:
	static bool RestoreKey(HKEY orig_hkey, const char *orig_key, HKEY dest_hkey, const char *dest_key);
	static bool SetAssocOpen(const char *key, const char *exename, const char *appname);
	static bool SetAssocRedir(const char *key, const char *redirname);
	static bool GetAssoc(const char *ext, CString& appname);
	static bool BackupKey(HKEY orig_hkey, const char *orig_key, HKEY dest_hkey, const char *dest_key);
	//
	// MRU
	static void AddMRU(CString sa[], CString& str, int maxdepth = MAX_MRU);
	static void Array2MRU(CComboBox * cbp, CString sa[], int maxdepth = MAX_MRU);
	static void MRU2Array(CComboBox *cbp, CString sa[], int maxdepth = MAX_MRU);
	static void AddMRU(CComboBox *cbp, int maxdepth = MAX_MRU);
	bool ReadMRU(const char *key, CComboBox *cbp, int maxdepth = MAX_MRU);
	bool SaveMRU(const char *key, CComboBox *cbp, int maxdepth = MAX_MRU);
	bool BiDirMRU(const char *key, CComboBox *cbp, bool write, int maxdepth = MAX_MRU);

	//
	// Read
	bool Read(const char *key, CString sa[], int alen);
	bool Read(const char *keyname, void *p, DWORD size);
	bool Read(const char *key, int& ip);
	bool Read(const char *key, CString& str);

	//
	// Write
	bool Write(const char *key, CString sa[], int alen);
	bool Write(const char *key, void *p, DWORD size);
	bool Write(const char *key, int i);
	bool Write(const char *key, CString& str);

	//
	// BiDir
	bool BiDir(const char *key, CString sa[], int alen, bool write = false);
	bool BiDir(const char *key, void *p, DWORD size, bool write = false);
	bool BiDir(const char *key, int& i, bool write = false);
	bool BiDir(const char *key, CString& str, bool write = false);

	//
	// Window Position
	bool RestoreWindowPosn(const char *key, CRect& r);
	bool SaveWindowPosn(const char *key, CRect& r);
	bool RestoreWindowPosn(const char *key, CWnd *wp);
	bool SaveWindowPosn(const char *key, CWnd *wp);
	bool BiDirWindowPosn(const char *key, CRect& r, bool write);

	//
	// Other
	BOOL Delete(const char *key);
	bool SetSection(const char *section);
	bool Start(const char * keybase, int version, const char *section);
	bool Start(const char *keybase, int version);
	void Close();

	//
	// Construction
	RegIni();
	RegIni(const char *keybase, int version);
	~RegIni();

};

#endif // !defined(AFX_REGINI_H__EEE4A5E1_F272_11D0_8988_444553540000__INCLUDED_)
