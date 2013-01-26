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


// RegIni.cpp: implementation of the RegIni class.  Quick and easy access
//  to the Registry... make it act like an INI file
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Uud32.h"
#include "RegIni.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

static char *rpt_key = "%s%02d";		// Format used with repeating values

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RegIni::RegIni()
{

	active = false;

}

RegIni::RegIni(const char *keybase, int version)
{

	active = false;

	Start(keybase, version);

}

RegIni::~RegIni()
{

	Close();

}


//
// Disconnect from the Registry
//

void RegIni::Close()
{

	if (active)
	{
		RegCloseKey(hk);
		active = false;
	}

}


//
// Connect to the Registry
//

bool RegIni::Start(const char * keybase, int version)
{

	Close();				// Make sure nothing is open

	KBase = "Software\\";
	KBase += keybase;

	keycache = KBase;

	vno = version;

return(true);
}


bool RegIni::Start(const char *keybase, int version, const char *section)
{
	Close();				// Make sure nothing is open

	KBase = "Software\\";
	KBase += keybase;

	keycache = KBase + '\\' + section;

	vno = version;

return(true);
}


//
// Alter the current section
//
bool RegIni::SetSection(const char * section)
{

	Close();				// Disconnect

	keycache = KBase + '\\' + section;

return(true);
}


//
// Open the Registry key for Reading
//

bool RegIni::OpenRead()
{

	if (!active && KBase.IsEmpty()) 
	{
		::MessageBox(NULL, "RegINI not started!", "RegINI", MB_ICONEXCLAMATION | MB_OK);
		return(false);
	}

	if (active && !wmode)
		return(true);				// Already open

	Close();						// Have to open or reopen

	if (RegOpenKeyEx(HKEY_CURRENT_USER, keycache, 0, KEY_READ, &hk) == ERROR_SUCCESS)
	{
		wmode = false;
		active = true;
		return(true);
	}

return(false);
}



//
// Open the Registry key for Writing
//

bool RegIni::OpenWrite()
{

	if (!active && KBase.IsEmpty()) 
	{
		MessageBox(NULL, "RegINI not started!", "RegINI", MB_ICONEXCLAMATION | MB_OK);
		return(false);
	}

	if (active && wmode)
		return(true);				// Already open

	Close();						// Have to open or reopen

	DWORD vtype;

	if (RegCreateKeyEx(HKEY_CURRENT_USER, keycache, 0, "Class", 
			0, KEY_WRITE, 0, &hk, &vtype) == ERROR_SUCCESS)
	{
		wmode = true;
		active = true;
		return(true);
	}

return(false);
}


//
// Read functions
//

bool RegIni::Read(const char *key, CString & str)
{

	if (!OpenRead())
		return(false);

	DWORD vtype = REG_SZ, dsize = 0;

	int rc = RegQueryValueEx(hk, key, NULL, &vtype, 0, &dsize);

	if (rc != ERROR_SUCCESS && rc != ERROR_MORE_DATA || vtype != REG_SZ)
		return(false);

	rc = RegQueryValueEx(hk, key, NULL, &vtype, (LPBYTE) str.GetBuffer(dsize + 1), &dsize);

	str.ReleaseBuffer();

return(rc == ERROR_SUCCESS);
}



bool RegIni::Read(const char * key, int& ip)
{
	if (!OpenRead())
		return(false);

	DWORD vtype = REG_DWORD, dsize = sizeof(int);

	int rc = RegQueryValueEx(hk, key, NULL, &vtype, (LPBYTE) &ip, &dsize);

return(rc == ERROR_SUCCESS);
}



bool RegIni::Read(const char *key, void *p, DWORD size)
{
	if (!OpenRead())
		return(false);

	DWORD vtype = REG_BINARY;

	int rc = RegQueryValueEx(hk, key, NULL, &vtype, (LPBYTE) p, &size);

return(rc == ERROR_SUCCESS);
}



bool RegIni::Read(const char *key, CString sa[], int alen)
{

	CString *sap = sa;

	int vct = 0;

	bool gotone = false;

	CString wrk;

	while (vct < alen)
	{
		wrk.Format(rpt_key, key, vct++);
		if (Read(wrk, *sap++))
			gotone = true;
		else
			break;
	}

return(gotone);
}


//
// Write functions
//


bool RegIni::Write(const char *key, CString & str)
{

	if (!OpenWrite())
		return(false);

return(RegSetValueEx(hk, key, NULL, REG_SZ, 
	   (LPBYTE) ((const char *) str), str.GetLength()) == ERROR_SUCCESS);
}


bool RegIni::Write(const char *key, int i)
{
	if (!OpenWrite())
		return(false);

return(RegSetValueEx(hk, key, NULL, REG_DWORD, 
	   (LPBYTE) &i, sizeof(int)) == ERROR_SUCCESS);
}


bool RegIni::Write(const char *key, void *p, DWORD size)
{
	if (!OpenWrite())
		return(false);

return(RegSetValueEx(hk, key, NULL, REG_BINARY, 
	   (LPBYTE) p, size) == ERROR_SUCCESS);
}


bool RegIni::Write(const char *key, CString sa[], int alen)
{

	CString *sap = sa;

	int vct = 0;

	CString wrk;

	for (int row=0; row < alen; row++, sap++)
		if (!sap->IsEmpty())
		{
			wrk.Format(rpt_key, key, vct++);
			if (!Write(wrk, *sap))
				return(false);
		}

	while (vct < alen)				// Delete any excess keys
	{
		wrk.Format(rpt_key, key, vct++);
		Delete(wrk);
	}

return(true);
}

//
// Save the position of a Window
//

bool RegIni::SaveWindowPosn(const char *key, CWnd *wp)
{
	if (!OpenWrite())
		return(false);

	struct wposn_s wps;

	wp->GetWindowRect(&wps.coord);
	wps.version = vno;

return(RegSetValueEx(hk, key, NULL, REG_BINARY, 
	   (LPBYTE) &wps, sizeof(struct wposn_s)) == ERROR_SUCCESS);
}


bool RegIni::SaveWindowPosn(const char *key, CRect& r)
{
	if (!OpenWrite())
		return(false);

	struct wposn_s wps;

	wps.coord = r;
	wps.version = vno;

return(RegSetValueEx(hk, key, NULL, REG_BINARY, 
	   (LPBYTE) &wps, sizeof(struct wposn_s)) == ERROR_SUCCESS);
}


bool RegIni::BiDirWindowPosn(const char *key, CRect& r, bool write)
{

	if (write)
		return(SaveWindowPosn(key, r));

	bool rc = RestoreWindowPosn(key, r);

	if (!rc)
		r.SetRectEmpty();

return(rc);
}


//
// Restore a previously-saved position
//

bool RegIni::RestoreWindowPosn(const char *key, CWnd *wp)
{
	if (!OpenRead())
		return(false);

	struct wposn_s wps;

	DWORD vtype = REG_BINARY, dsize = sizeof(struct wposn_s);

	if (RegQueryValueEx(hk, key, NULL, &vtype, (LPBYTE) &wps, &dsize) != ERROR_SUCCESS ||
			wps.version < vno)
		return(false);

	wp->MoveWindow(&wps.coord, TRUE);

return(true);
}


bool RegIni::RestoreWindowPosn(const char *key, CRect& r)
{
	if (!OpenRead())
		return(false);

	struct wposn_s wps;

	DWORD vtype = REG_BINARY, dsize = sizeof(struct wposn_s);

	if (RegQueryValueEx(hk, key, NULL, &vtype, (LPBYTE) &wps, &dsize) != ERROR_SUCCESS ||
			wps.version < vno)
		return(false);

	r = wps.coord;

return(true);
}


//
// Write a MRU list to the Registry
//

bool RegIni::SaveMRU(const char *key, CComboBox *cbp, int maxdepth)
{

	if (!OpenWrite())
		return(false);

	int lc = cbp->GetCount();			// Read the current list length

	if (lc == 0)
		return(true);					// Nothing to do, just return OK

	if (lc > maxdepth)
		lc = maxdepth;					// Limit the number of items

	CString wrk, export;
	int row;

	for (row=0; row < lc; row++)
	{
		cbp->GetLBText(row, wrk);		// Read the item

		export.Format(rpt_key, key, row);	// Create the key

		if (!Write(export, wrk))
			return(false);				// Writing failed
	}

	for (; row < lc; row++)
	{
		export.Format(rpt_key, key, row);	// Create the key

		Delete(export);				// Waste any extra keys
	}

return(true);
}


//
// Delete a value
//

BOOL RegIni::Delete(const char * key)
{

	if (!OpenWrite())			// Make sure we have access
		return(false);

return(::RegDeleteValue(hk, key));		// Delete values
}


//
// Read a Most-Recently-Used list from the Registry
//

bool RegIni::ReadMRU(const char *key, CComboBox *cbp, int maxdepth)
{

	if (!OpenRead())
		return(false);

	bool first = true;

	CString wrk, import;

	for (int row=0; row < maxdepth; row++)
	{
		import.Format(rpt_key, key, row);	// Create the key

		if (!Read(import, wrk))
			return(!first);					// If still the first, we had no read

		if (first)
		{
			CString temp;

			cbp->GetWindowText(temp);		// Store the old edit string
			cbp->ResetContent();
			cbp->SetWindowText(temp);

			first = false;
		}

		cbp->AddString(wrk);				// Add to the list box
	}

return(!first);							// If not first, we've got something
}


//
// Add a most-recently-used string
//

void RegIni::AddMRU(CComboBox *cbp, int maxdepth)
{

	CString ntext, item;

	cbp->GetWindowText(ntext);		// Read the new string

	ntext.TrimLeft();
	ntext.TrimRight();

	for (int row=cbp->GetCount() - 1; row >= 0; row--)
	{
		cbp->GetLBText(row, item);		// Read the item

		if (item.CompareNoCase(ntext) == 0)
			cbp->DeleteString(row);		// This is a duplicate
	}

	cbp->InsertString(0, ntext);		// Add the new item

}


void RegIni::AddMRU(CString sa[], CString& str, int maxdepth)
{

	CString *local = new CString[maxdepth];		// Create sorting array

	CString *lp = local, *rp = sa;

	*lp++ = str;			// First element is always the new string

	int row;

	for (row=1; row < maxdepth; row++, rp++)
		if (!rp->IsEmpty() && str.CompareNoCase(*rp) != 0)
			*lp++ = *rp;	// Copy the string

	rp = sa;

	CString *cp = local;

	for (row=0; row < maxdepth; row++, cp++, rp++)
		if (cp < lp)
			*rp = *cp;
		else
			rp->Empty();		// Clear all the other strings

	delete[] local;

}


//
// Copy an MRU list from a combo box to a string array
//

void RegIni::MRU2Array(CComboBox *cbp, CString sa[], int maxdepth)
{

	int rmax = cbp->GetCount();

	CString *sap = sa;
	CString wrk;

	for (int row=0; row < maxdepth; row++, sap++)
		if (row < rmax)
			cbp->GetLBText(row, *sap);
		else
			sap->Empty();

}


//
// Copy a string array to a combo box MRU list
//

void RegIni::Array2MRU(CComboBox *cbp, CString sa[], int maxdepth)
{
	CString temp;

	cbp->GetWindowText(temp);		// Store the old edit string
	cbp->ResetContent();		// Reset list box but save text
	cbp->SetWindowText(temp);

	CString *sap = sa;

	for (int row=0; row < maxdepth; row++, sap++)
		if (!sap->IsEmpty())
			cbp->AddString(*sap);

}



//
// Bi-directional functions
//


bool RegIni::BiDir(const char *key, CString &str, bool write)
{

	if (write)
		return(Write(key, str));

	bool rc = Read(key, str);

	if (!rc)
		str.Empty();			// Make sure string is dead

return(rc);
}


bool RegIni::BiDir(const char *key, int& i, bool write)
{

	if (write)
		return(Write(key, i));

	bool rc = Read(key, i);

	if (!rc)
		i = 0;					// Clear variable

return(rc);
}


bool RegIni::BiDir(const char *key, void *p, DWORD size, bool write)
{

	if (write)
		return(Write(key, p, size));

	bool rc = Read(key, p, size);

	if (!rc)
		ZeroMemory(p, size);		// Clear memory if no read

return(rc);
}


bool RegIni::BiDir(const char *key, CString sa[], int alen, bool write)
{

	if (write)
		return(Write(key, sa, alen));

	bool rc = Read(key, sa, alen);

	if (!rc)
	{
		CString *sap = sa;

		for (int row=0; row < alen; row++)
			sap++->Empty();				// Clear all strings if no read
	}


return(rc);
}


bool RegIni::BiDirMRU(const char *key, CComboBox *cbp, bool write, int maxdepth)
{

	if (write)
		return(SaveMRU(key, cbp, maxdepth));

	bool rc = ReadMRU(key, cbp, maxdepth);

	if (!rc)
	{
		CString temp;

		cbp->GetWindowText(temp);		// Store the old edit string
		cbp->ResetContent();			// Clear list without erasing text box
		cbp->SetWindowText(temp);
	}

return(rc);
}


//
// Backs up a key tree from one location in the Registry to another
//

bool RegIni::BackupKey(
HKEY orig_hkey, const char *orig_key, 
HKEY dest_hkey, const char *dest_key)
{
	HKEY h_org, h_dest;

	if (RegOpenKeyEx(orig_hkey, orig_key, 0, KEY_READ, &h_org) != ERROR_SUCCESS)
		return(false);

	CString dest;
	DWORD type;

	if (dest_key != NULL)
	{
		dest = dest_key;
		dest += '\\';
	}

	dest += orig_key;			// Create subkey name

	if (RegCreateKeyEx(
		dest_hkey,				// Hkey
		dest,					// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h_dest,				// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create key \"%s\"\r\n", (const char *) dest);
		RegCloseKey(h_org);
		return(false);
	}

	int sk_ind = 0;

	CString keyname;
	DWORD keysz, data_size;
	BOOL rc;

	byte *databuf = new byte[256];
	DWORD db_size = 256;

	do
	{

		keysz = MAX_PATH;

		rc = RegEnumValue(h_org, sk_ind, keyname.GetBuffer(MAX_PATH + 1),
			&keysz, NULL, &type, NULL, &data_size);

		keyname.ReleaseBuffer();

		if (rc == ERROR_SUCCESS)
		{
			if (data_size > db_size)		// Need to re-allocate buffer
			{
				delete[] databuf;
				databuf = new byte[data_size + 10];
				db_size = data_size + 10;
			}

			keysz = MAX_PATH;

			rc = RegEnumValue(h_org, sk_ind++, keyname.GetBuffer(MAX_PATH + 1),
				&keysz, NULL, &type, databuf, &data_size);

			keyname.ReleaseBuffer();

			if (RegSetValueEx(h_dest, keyname, 0, type, databuf, data_size) != ERROR_SUCCESS)
			{
				TRACE("Could not set key \"%s\"\r\n", (const char *) keyname);
				break;
			}

		}

	} while (rc == ERROR_SUCCESS);

	FILETIME ft;

	sk_ind = 0;

	do 
	{
		keysz = MAX_PATH;

		rc = RegEnumKeyEx(h_org, sk_ind++, keyname.GetBuffer(MAX_PATH + 1),
			&keysz, 0, NULL, NULL, &ft);

		keyname.ReleaseBuffer();

		if (rc == ERROR_SUCCESS)
			rc = BackupKey(h_org, keyname, h_dest, NULL);

	} while (rc == ERROR_SUCCESS);

	RegCloseKey(h_org);
	RegCloseKey(h_dest);

	delete[] databuf;

return(true);
}


//
// Read back the association for a given extension
//  or "redirect"
//

bool RegIni::GetAssoc(const char *ext, CString& appname)
{
	HKEY h;

	if (RegOpenKeyEx(HKEY_CLASSES_ROOT, ext, 0, KEY_READ, &h) != ERROR_SUCCESS)
		return(false);

	DWORD d_size, type;

	BOOL rc = RegQueryValueEx(h, "", 0, &type, NULL, &d_size);

	if (rc == ERROR_SUCCESS && type == REG_SZ)
	{
		rc = RegQueryValueEx(h, "", 0, &type, 
			(byte *) appname.GetBuffer(d_size + 1), &d_size);
		appname.ReleaseBuffer();
	}
	else
		rc = ERROR_SUCCESS + 1;

	RegCloseKey(h);

return(rc == ERROR_SUCCESS);
}


//
// Set an association redirection
//

bool RegIni::SetAssocRedir(const char *key, const char *redir_name)
{
	HKEY h;
	DWORD type;

	if (RegCreateKeyEx(
		HKEY_CLASSES_ROOT,		// Hkey
		key,					// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h,						// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create key\r\n");
		return(false);
	}

	BOOL rc;
	
	if ((rc = RegSetValueEx(h, "", 0, REG_SZ, (byte *) redir_name, strlen(redir_name))) != ERROR_SUCCESS)
		TRACE("Could not set key \"%s\"\r\n", redir_name);

	RegDeleteKey(h, "DefaultIcon");		// Remove any existing icon

	RegDeleteKey(h, "shell");			// Remove any existing shell association

	RegCloseKey(h);

return(rc == ERROR_SUCCESS);
}


//
// Set an "open" association
//

bool RegIni::SetAssocOpen(const char *key, const char *exename, const char *appname)
{
	HKEY h;
	DWORD type;

	if (RegCreateKeyEx(
		HKEY_CLASSES_ROOT,		// Hkey
		key,					// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h,						// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create key \"%s\"\r\n", key);
		return(false);
	}

	BOOL rc;
	
	// Create the "app name text"
	if ((rc = RegSetValueEx(h, "", 0, REG_SZ, (const byte *) 
			appname, strlen(appname))) != ERROR_SUCCESS)
		TRACE("Could not set key base\r\n");

	HKEY h1;

	if (RegCreateKeyEx(
		h,						// Hkey
		"DefaultIcon",			// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h1,						// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create DefaultIcon subkey\r\n");
		RegCloseKey(h);
		return(false);
	}

	CString wrk(exename);
	wrk += ",0";

	// Set the Default Icon
	if ((rc = RegSetValueEx(h1, "", 0, REG_SZ, 
			(const byte *) ((const char *) wrk), wrk.GetLength())) != ERROR_SUCCESS)
		TRACE("Could not set key\r\n");

	RegCloseKey(h1);

	if (RegCreateKeyEx(
		h,						// Hkey
		"shell\\open\\command",		// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h1,						// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create open subkey\r\n");
		RegCloseKey(h);
		return(false);
	}

	wrk = exename;
	wrk += " \"%1\"";

	// Set the command
	if ((rc = RegSetValueEx(h1, "", 0, REG_SZ, 
			(byte *) ((const char *) wrk), wrk.GetLength())) != ERROR_SUCCESS)
		TRACE("Could not set command key\r\n");

	RegCloseKey(h1);
	RegCloseKey(h);

return(true);
}


//
// Restore a key from a backup
//

bool RegIni::RestoreKey(
HKEY orig_hkey, const char *orig_key,		// Source
HKEY dest_hkey, const char *dest_key)		// Destination
{
	HKEY h_org, h_dest;

	if (RegOpenKeyEx(orig_hkey, orig_key, 0, KEY_READ, &h_org) != ERROR_SUCCESS)
		return(false);

	DWORD type;

	if (RegCreateKeyEx(
		dest_hkey,				// Hkey
		dest_key,				// Subkey
		0,						// Reserved
		"",						// Class name
		0,						// Options
		KEY_WRITE,				// Access
		NULL,					// Security
		&h_dest,				// Key back
		&type) != ERROR_SUCCESS)
	{
		TRACE("Could not create key\r\n");
		RegCloseKey(h_org);
		return(false);
	}

	int sk_ind = 0;

	CString keyname;
	DWORD keysz, data_size;
	BOOL rc;

	byte *databuf = new byte[256];
	DWORD db_size = 256;

	do
	{

		keysz = MAX_PATH;

		rc = RegEnumValue(h_org, sk_ind, keyname.GetBuffer(MAX_PATH + 1),
			&keysz, NULL, &type, NULL, &data_size);

		keyname.ReleaseBuffer();

		if (rc == ERROR_SUCCESS)
		{
			if (data_size > db_size)		// Need to re-allocate buffer
			{
				delete[] databuf;
				databuf = new byte[data_size + 10];
				db_size = data_size + 10;
			}

			keysz = MAX_PATH;

			rc = RegEnumValue(h_org, sk_ind++, keyname.GetBuffer(MAX_PATH + 1),
				&keysz, NULL, &type, databuf, &data_size);

			keyname.ReleaseBuffer();

			if (RegSetValueEx(h_dest, keyname, 0, type, databuf, data_size) != ERROR_SUCCESS)
			{
				TRACE("Could not set key \"%s\"\r\n", (const char *) keyname);
				break;
			}

		}

	} while (rc == ERROR_SUCCESS);

	FILETIME ft;

	sk_ind = 0;

	do 
	{
		keysz = MAX_PATH;

		rc = RegEnumKeyEx(h_org, sk_ind++, keyname.GetBuffer(MAX_PATH + 1),
			&keysz, 0, NULL, NULL, &ft);

		keyname.ReleaseBuffer();

		if (rc == ERROR_SUCCESS)
			rc = BackupKey(h_org, keyname, h_dest, NULL);

	} while (rc == ERROR_SUCCESS);

	RegCloseKey(h_org);
	RegCloseKey(h_dest);

	delete[] databuf;

return(true);
}
