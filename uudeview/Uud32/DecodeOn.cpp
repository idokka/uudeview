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


//
// Decode dialog box "on" event handlers
//
#include "stdafx.h"
#include "Uud32.h"
#include "DecodeDlg.h"
#include "uud32acx.h"			// Bring in UUD control defs
#include "InfoDialog.h"
#include "MikeNPopupMenu.h"
#include "RenOutFile.h"
#include "LaunchDialog.h"

#include "hlp\decode.hh"

#define STD_UUFILES		"L:\\No Backup\\UU"			// Source of decode files

//
// Add to the list of files to decode
//
void DecodeDlg::OnAdddecode() 
{

#if defined(_DEBUG)
if (m_DecodeList.GetCount() == 0) {		// Add the default list
	CFileFind ff;
	CString wrk;

	m_DecodeList.SetRedraw(FALSE);

	BOOL loop = ff.FindFile(STD_UUFILES "\\*.*", 0); 
	while (loop)
	{
		loop = ff.FindNextFile();
		if (!ff.IsDirectory())
		{ 
			wrk = ff.GetFilePath();
			wrk.MakeLower();
			m_DecodeList.AddString(wrk);
		}
	}

	m_DecodeList.SetRedraw(TRUE);

	ff.Close();

	if (m_DecodeList.GetCount() > 0)
	{
		SetState(MS_PREVIEW);		// There's something to decode
		return;
	}
	else
		MessageBox("Standard list " STD_UUFILES " is unavailable",
			"Add Files", MB_OK);

	}
#endif

	CFileDialog openFile(
		TRUE,					// OPEN
		NULL,					// Default extension
		NULL,					// Initial filename
		OFN_ALLOWMULTISELECT | OFN_EXPLORER | OFN_FILEMUSTEXIST |
		  OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_SHOWHELP,		// Flags
		"Decodable Files|*.uue; *.xxe; *.hqx; *.mim; *.b64|"
		  "UU-Encoded Files|*.uue|"
		  "XX-Encoded Files|*.xxe|"
		  "BinHex Files|*.hqx|"
		  "MIME Files|*.mim|"
		  "Numbered Files|*.0*; *.1*; *.2*; *.3*; *.4*; *.5*; *.6*; *.7*; *.8*; *.9*|"
		  "All Files|*.*||",
		this);				// Owner is ME

	openFile.m_ofn.lpstrTitle = "Add Files to Decode";

	if (!addDir.IsEmpty())
		openFile.m_ofn.lpstrInitialDir = (const char *) addDir;

	CString fileName;

	openFile.m_ofn.lpstrFile = fileName.GetBuffer(8192);
	openFile.m_ofn.nMaxFile = 8192;

	openFile.m_ofn.nFilterIndex = addFilter;	// Retrieve preset filter

	int dm = openFile.DoModal();

	fileName.ReleaseBuffer();

	openFile.DestroyWindow();

	GetTopLevelParent()->RedrawWindow();

	if (dm == IDCANCEL)
		return;					// User cancelled

	addFilter = openFile.m_ofn.nFilterIndex;	// Storepreset filter

	POSITION posn = openFile.GetStartPosition(); 

	CFileName wrk;

	bool first = true;

	m_DecodeList.SetRedraw(FALSE);

	while (posn != NULL)
	{
		wrk = openFile.GetNextPathName(posn);
		wrk.GetStr().MakeLower();
		m_DecodeList.AddString(wrk.GetStr());

		if (first)
		{
			addDir = wrk.Path();			// Adjust the parent's initial dir
			first = false;
		}
	}

	m_DecodeList.SetRedraw(TRUE);

	if (m_DecodeList.GetCount() > 0)
		SetState(MS_PREVIEW);		// There's something to decode

}


//
// The selection has changed in the Decode List
//
void DecodeDlg::OnSelchangeDecodelist() 
{
	int nsel = m_DecodeList.GetSelCount();

	if (nsel > 0)
		m_RemoveDecode.Enable();
	else
		m_RemoveDecode.Disable();

	if (nsel != 1) 		// Show info for 1 file only
	{
		InfoClear();
		return;
	}

	int row = m_DecodeList.GetFirstSel();

	CFileName fileName;

	m_DecodeList.GetText(row, fileName.GetStr());		// Read the filename

	CFileStatus fstat;

	CString wrk;

	Info2(NULL);

	if (clipboardSet && fileName.GetStr() == clipboardString)
	{
		wrk.Format("(Accumulated Clipboard contents, %d bytes)",
			cFile.GetFileSize());
		Info1(wrk);
		return;
	}
	else if (fileName.GetStatus(fstat)) 
	{
		wrk.Format("%s --> %d bytes, %s", (const char *) fileName,
			fstat.m_size, 
			(const char *) fstat.m_mtime.Format("%m/%d/%y %H:%M:%S"));
		Info1(wrk);
	}
	else 
	{
		Info1("(Could not read file information)");
		return;
	}

	if (fileName.fopen("rt") == NULL) 
	{
		Info1("(Could not read file info)");
		return;
	}

	char inbuf[256];
	inbuf[sizeof(inbuf) - 1] = EOS;

	int llim = 50;					// Read at most 50 lines

	while (llim-- > 0 && fileName.fgets(inbuf, sizeof(inbuf)-1)) 
	{

		if (strnicmp(inbuf, "SUBJECT:", 8) == 0) 
		{
			for (char *p = inbuf; *p != EOS; p++)
				if (*p < ' ')
					*p = ' ';

			Info2(inbuf);
			break;
		}
	}

	fileName.Close();
	
}

//
// Clear all?
//

void DecodeDlg::OnClearDecode() 
{

if (MessageBox("Are you sure you want to Clear?", "Clear", 
	 MB_ICONQUESTION | MB_YESNO /* | MB_DEFBUTTON2 */) == IDYES)
	SetState(MS_CLEAR);				// Waste everything...

ClipboardKill();					// Make sure the clipboard's empty
	
}


//
// Remove file(s) from Decode
//

void DecodeDlg::OnRemoveDecode() 
{
	CString wrk;

	for (int row = m_DecodeList.GetCount() - 1; row >= 0; row--)
		if (m_DecodeList.GetSel(row))
		{
			if (clipboardSet)
			{
				m_DecodeList.GetText(row, wrk);
				if (wrk == clipboardString)
					ClipboardKill();			// User removed the clipboard listing
			}
			m_DecodeList.DeleteString(row);
		}

	if (m_DecodeList.GetCount() <= 0)
		SetState(MS_CLEAR);				// User deleted everything
	else
	{
		m_RemoveDecode.Disable();		// Can't remove any more, all selected are gone
		SetState(MS_PREVIEW);
	}
	
}


//
// User Clicked the GO button
//

void DecodeDlg::OnDecodeGo() 
{

	if (decoder != NULL && (decoder->State == Engine::ENG_READING 
		|| decoder->State == Engine::ENG_DECODING))
	{
		decoder->PostThreadMessage(ENG_CANCEL, 0, 0);		// Tell the engine to stop
		decoder->UD.cancelFlag = TRUE;
		return;
	}

	if (State == MS_PREVIEW)
		DecodePreview();
	else if (State == MS_GO)
		DecodeGo();
	
}



//
// Try to get the output path...
//

void DecodeDlg::OnDecodePathBrowse() 
{
	CString dname;

if (BrowseForDir(dname, "Select Output Directory", this))
	m_DecodePath.SetWindowText(dname);		// Copy to list box

}


//
// User wants to set Decode Options
//

void DecodeDlg::OnDecodeOptions() 
{
	DecodeOptions o;

	o.m_BrackPol = options[OPT_BRACK];
	o.m_Debug = options[OPT_DEBUG];
	o.m_DumbMode = options[OPT_DUMB];
	o.m_EText = options[OPT_ETEXT];
	o.m_FastMode = options[OPT_FASTMODE];
	o.m_IgnReply = options[OPT_IGNREPLY];
	o.m_POE = options[OPT_POE];
	o.m_Desperate = options[OPT_DESPERATE];
	o.m_HideTips = options[OPT_HIDETIPS];
	o.m_StrictMime = options[OPT_STRICT];
	o.m_RecycleInput = options[OPT_RECYCLE];
	o.m_OutputFileMode = options[OPT_OWMODE];
	o.m_PreserveCase = options[OPT_PCASE];
	o.m_ENoPrompt = options[OPT_ENOPROMPT];
	o.m_LNoPrompt = options[OPT_LNOPROMPT];
	o.m_WinTemp = options[OPT_TEMPS];
	o.m_DNoPrompt = options[OPT_DNOPROMPT];
	o.m_StrictFilenames = options[OPT_STRICTFN];

	o.nonWTemp = tempFolder;

	if (assoc)					// Set the tri-state button
		o.m_Assoc = (IsAssociated()) ? 1 : 2;
	else
		o.m_Assoc = 0;

	BOOL old_assoc = o.m_Assoc;

	if (o.DoModal() != IDOK)
		return;							// Done

	options[OPT_BRACK] = o.m_BrackPol;
	options[OPT_DEBUG] = o.m_Debug;
	options[OPT_DUMB] = o.m_DumbMode;
	options[OPT_ETEXT] = o.m_EText;
	options[OPT_FASTMODE] = o.m_FastMode;
	options[OPT_IGNREPLY] = o.m_IgnReply;
	options[OPT_POE] = o.m_POE;
	options[OPT_DESPERATE] = o.m_Desperate;
	options[OPT_HIDETIPS] = o.m_HideTips;
	options[OPT_STRICT] = o.m_StrictMime;
	options[OPT_RECYCLE] = o.m_RecycleInput;
	options[OPT_OWMODE] = o.m_OutputFileMode;
	options[OPT_PCASE] = o.m_PreserveCase;
	options[OPT_ENOPROMPT] = o.m_ENoPrompt;
	options[OPT_LNOPROMPT] = o.m_LNoPrompt;
	options[OPT_TEMPS] = o.m_WinTemp;
	options[OPT_DNOPROMPT] = o.m_DNoPrompt;
	options[OPT_STRICTFN] = o.m_StrictFilenames;

	if (o.m_WinTemp)
		tempFolder = o.m_TempFolder;

	EnableToolTips(!o.m_HideTips);

	OptionButtonSet();

	if (o.m_Assoc != old_assoc && 
			SetAssoc(old_assoc, o.m_Assoc))	// Change value
		assoc = o.m_Assoc;			// Update the associated value
	
	if (decoder != NULL)
		EngineSetup();			// Update flags in decoder engine
}

//
// Handle Info for output list
//

void DecodeDlg::OnClickDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult) 
{

	*pResult = 0;

	int sc = m_DecodeOut.GetSelectedCount();

	if (sc > 1)
	{
		m_DecodeInfo.Disable();
		m_RenameDecodeOut.Disable();
		m_RemoveDecodeOut.Enable();
		InfoClear();
		return;
	}
	else if (sc == 0)					// Nothing selected
	{
		m_DecodeInfo.Disable();
		m_RenameDecodeOut.Disable();
		m_RemoveDecodeOut.Disable();
		InfoClear();
		return;
	}

	int seli = m_DecodeOut.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	int row = m_DecodeOut.GetItemData(seli);

	if (decoder->UD.GetDFileInfo(row).IsEmpty())
		m_DecodeInfo.Disable();
	else
		m_DecodeInfo.Enable();

	if (State == MS_GO)
		m_RenameDecodeOut.Enable();
	else
		m_RenameDecodeOut.Disable();

	m_RemoveDecodeOut.Enable();

	Info1(CurrentOutput() + m_DecodeOut.GetItemText(seli, 0));
	Info2(decoder->UD.GetDFileStatus(row));
	
}



//
// Update the info AFTER the control has handled the key
//

void DecodeDlg::OnKeydownDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN *pLVKeyDow = (LV_KEYDOWN*)pNMHDR;

	if (pLVKeyDow->wVKey == VK_NONAME)
		OnClickDecodeOutputList(pNMHDR, pResult);
	else
	{
		m_DecodeOut.PostMessage(WM_KEYDOWN, VK_NONAME, 1);
		m_DecodeOut.PostMessage(WM_KEYUP, VK_NONAME, 1 | (1 << 30) | (1 << 31));
	}

	*pResult = 0;
}


//
// Unselect --- Switching focus to Tree control

void DecodeDlg::OnSetfocusDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult) 
{

	int lc = m_DecodeList.GetCount();

	if (lc > 0)
		m_DecodeList.SelItemRange(FALSE, 0, lc - 1);
	
	*pResult = 0;

}


//
// User clicked the Output List Rename button
//

void DecodeDlg::OnRenameDecodeOut() 
{

	if (m_DecodeOut.GetSelectedCount() == 1)
	{
		m_DecodeOut.SetFocus();
		m_DecodeOut.EditLabel(m_DecodeOut.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED));
	}

}


//
// Edit is finished
//

void DecodeDlg::OnEndLabelEditDecodeOutputList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO *pDispInfo = (LV_DISPINFO*)pNMHDR;

	CString wrk(pDispInfo->item.pszText);	// Grab the edited filename

	if (wrk.IsEmpty())
		return;								// Cancelled or other problem

	int posn_sl = wrk.ReverseFind('\\');	// Look for path elements
	int posn_c = wrk.ReverseFind(':');

	if (posn_c > posn_sl)
		posn_sl = posn_c;					// The LAST char

	if (posn_sl >= 0)
		wrk = wrk.Mid(posn_sl + 1);

	wrk = decoder->UD.FileFilter(wrk);				// Remove weird chars
	wrk.MakeLower();						// Force lowercase

	if (!wrk.IsEmpty())
	{
		LV_ITEM item;
		item.iItem = pDispInfo->item.iItem;
		item.iSubItem = 0;
		item.mask = (LVIF_PARAM | LVIF_STATE | LVIF_IMAGE);
		m_DecodeOut.GetItem(&item);			// Read _all_ the item's current info (except string)

		m_DecodeOut.DeleteItem(pDispInfo->item.iItem);

		item.mask = (LVIF_TEXT | LVIF_PARAM | LVIF_STATE | LVIF_IMAGE);		// Set all
		item.pszText = (LPSTR) ((LPCTSTR) wrk);

		int ni = m_DecodeOut.InsertItem(&item);		// Add the item back

		ASSERT(ni >= 0);			// Tell me if the insert failed

		if (ni >= 0)			// Insert went OK
		{
			m_DecodeOut.SetItemState(ni, LVIS_SELECTED, LVIS_SELECTED);
			m_DecodeOut.EnsureVisible(ni, FALSE);	// Alter the item
		}

		DupCheck();				// Update duplicate status
	}

	*pResult = 0;
}


//
// User clicked the Output list Remove button
//

void DecodeDlg::OnRemoveDecodeOut() 
{

	for (int rmax = m_DecodeOut.GetItemCount() - 1; rmax >= 0; rmax--)
		if (m_DecodeOut.GetItemState(rmax, LVIS_SELECTED))
			m_DecodeOut.DeleteItem(rmax);

	if (m_DecodeOut.GetItemCount() <= 0)
		SetState(MS_PREVIEW);			// Jump back one... user deleted all
	else
		m_RemoveDecodeOut.Disable();			// Can't remove any more... all selected are gone
	
}


//
// User clicked the Info button
//

void DecodeDlg::OnDecodeInfo() 
{

	if (m_DecodeOut.GetSelectedCount() != 1)
		return;							// Nothing to do

	m_DecodeOut.SetFocus();

	int row = m_DecodeOut.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);

	InfoDialog id(&infoPosn);

	id.m_Title = CurrentOutput() + m_DecodeOut.GetItemText(row, 0);

	id.m_Text = decoder->UD.GetDFileInfo((short) m_DecodeOut.GetItemData(row));

	if (!id.m_Text.IsEmpty())
		id.DoModal();

	if (id.m_hWnd != NULL)
		id.DestroyWindow();			// Explicit destroy gets rid of warning in debug mode

	GetTopLevelParent()->RedrawWindow();	// Got to repaint, the output list will be messed up

}



//
// Handle commands sent from menus and list boxes
//

BOOL DecodeDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	int lc;

	switch (wParam) 
	{
		case IDC_DECODELIST:
			ShowDecodeMenu();
			break;

		case IDC_DECODEOUTPUTLIST:
			ShowDecodeOutMenu();
			break;

		//
		// Decode These Files list commands
		//

		case DT_REMOVE:
			OnRemoveDecode();
			break;

		case DT_NONE:				// Select None
			if ((lc = m_DecodeList.GetCount()) > 0)
				m_DecodeList.SelItemRange(FALSE, 0, lc - 1);
			break;

		case DT_ALL:				// Select All
			if ((lc = m_DecodeList.GetCount()) > 0)
				m_DecodeList.SelItemRange(TRUE, 0, lc - 1);
			break;

		case DT_INV:				// Invert selection
			for (lc = m_DecodeList.GetCount() - 1; lc >= 0; lc--)
				m_DecodeList.SetSel(lc, !m_DecodeList.GetSel(lc));
			break;

		case DT_LAUNCH:				// Launch
			DecodeLaunch();
			break;

		case DT_EDIT:				// Edit file(s)
			DecodeEdit();
			break;

		case DT_HELP:				// Context menu help
			AfxGetApp()->WinHelp(Context_Menu_to_decode_list, HELP_CONTEXT);
			break;

		//
		// Decode Output list commands
		//

		case DO_INFO:
			OnDecodeInfo();
			break;

		case DO_REMOVE:
			OnRemoveDecodeOut();
			break;

		case DO_RENAME:
			OnRenameDecodeOut();
			break;

		case DO_NONE:
			for (lc = m_DecodeOut.GetItemCount() - 1; lc >= 0; lc--)
				m_DecodeOut.SetSel(lc, false);
			break;

		case DO_ALL:
			for (lc = m_DecodeOut.GetItemCount() - 1; lc >= 0; lc--)
				m_DecodeOut.SetSel(lc, true);
			break;

		case DO_INV:
			for (lc = m_DecodeOut.GetItemCount() - 1; lc >= 0; lc--)
				m_DecodeOut.SetSel(lc, !m_DecodeOut.GetSel(lc));
			break;

		case DO_LAUNCH:
			DecodeOutLaunch();
			break;

		case DO_HELP:
			AfxGetApp()->WinHelp(Context_Menu_decode_preview_list, HELP_CONTEXT);
			break;

		default:				// Handle messages I don't do
#if defined(_DEBUG)				// Warn of unimplemented commands in Debug mode
			if (wParam < 1000)
			{
				CString wrk;

				wrk.Format("Unhandled Command %d", wParam);

				MessageBox(wrk, "Decode OnCommand", MB_OK);
			}
#endif
			return(CDialog::OnCommand(wParam, lParam));		// Call super for messages not handled here

	}

return(TRUE);					// If we get this far, the message is handled
}


//
// Add the Clipboard to what's already on the menu
//

void DecodeDlg::OnAddClipboard() 
{

	if (!::IsClipboardFormatAvailable(CF_TEXT))
	{
		MessageBox("No text on the clipboard.", "Add Clipboard",
			MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	if (!OpenClipboard())
	{
		MessageBox("Could not open Clipboard.", "Add Clipboard",
			MB_ICONEXCLAMATION | MB_OK);
		return;
	}

	HANDLE ch = ::GetClipboardData(CF_TEXT);

	if (ch == NULL)
	{
		MessageBox("Could not retrieve clipboard data.", "Add Clipboard",
			MB_ICONEXCLAMATION | MB_OK);
		CloseClipboard();
		return;
	}

	long bsize = GlobalSize(ch);

	byte *bp = (byte *) GlobalLock(ch);

	ASSERT(bp != NULL);

	byte *ep = (byte *) memchr(bp, 0, bsize);	// Look for the end marker

	if (ep != NULL)
		bsize = ep - bp;			// Reset the length to the NUL

	if (cFile.IsEmpty())
		cFile.Temp("uudeview", NULL, tempFolder);		// Create temporary clipboard name

	bool rc = 
		(cFile.IsOpen() || cFile.Open("ab"))	// File is open, or open for append
		&& cFile.Write(bp, bsize);	// Do the write

	GlobalUnlock(ch);				// Release the memory handle

	if (rc)							// OK
		EmptyClipboard();
	else
		MessageBox("Could not write clipboard data.", "Add Clipboard",
			MB_ICONEXCLAMATION | MB_OK);

	CloseClipboard();

	if (clipboardSet)				// There's already something there
	{
		int rmax = m_DecodeList.GetCount() - 1;
		int row;
		CString item;

		for (row=0; row <= rmax; row++)
		{
			m_DecodeList.GetText(row, item);
			if (item == clipboardString)
			{
				m_DecodeList.DeleteString(row);		// Delete the existing string
				break;
			}
		}
	}
	else
		cFile.XFile();			// Mark the file for deletion later

	clipboardString.Format("(Clipboard %dK)", cFile.GetFileSize() / 1024);

	m_DecodeList.AddString(clipboardString);	// Add the clipboard string

	clipboardSet = true;

	SetState(MS_PREVIEW);			// Got to switch into preview mode
		
}


//
// Handle files dropped from Explorer
//

void DecodeDlg::OnDropFiles(HDROP hDropInfo)
{
	char fbuf[MAX_PATH + 1];
	CFileStatus fsta;

	int fmax = ::DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);	// Read count
	int addct = 0;

	m_DecodeList.SetRedraw(FALSE);

	for (int row=0; row < fmax; row++)
	{
		::DragQueryFile(hDropInfo, row, fbuf, MAX_PATH);

		if (CFile::GetStatus(fbuf, fsta) && (fsta.m_attribute & CFile::directory))
			continue;				// This is a directory...

		strlwr(fbuf);
		m_DecodeList.AddString(fbuf);
		addct++;
	}

	m_DecodeList.SetRedraw(TRUE);

	if (addct > 0)
		SetState(MS_PREVIEW);

}


//
// Trip the context help
//

void DecodeDlg::OnStartContextHelp() 
{

	OnContextHelp();
	
}


//
// Handle resizing the output list
//
void DecodeDlg::OnSize(UINT nType, int cx, int cy) 
{
	CSizeDialog::OnSize(nType, cx, cy);

	if (m_DecodeOut.m_hWnd != NULL)
	{
		CRect ol;

		m_DecodeOut.GetClientRect(&ol);		// Read the client rectangle

		m_DecodeOut.SetColumnWidth(0, ol.right - ol.left - 20);
	}
	
}


//
// Handle Progress messages
//

afx_msg LONG DecodeDlg::OnProgress(WPARAM wParam, LPARAM uuptr)
{
	uuprogress *up = (uuprogress *) uuptr;

	if (decoder->StopMessage())				// There's a STOP or CANCEL in the queue
	{
//		*Cancel = TRUE;
		return(TRUE);
	}

	switch (up->action)
	{
		case CUud32acxCtrl::uudActNewStep:
			newStep = true;
			break;

		case CUud32acxCtrl::uudActScanning:
			if (newStep)
			{
				if (clipboardSet && !stricmp(up->curfile, cFile))
					Info1("Reading (Clipboard)");
				else
				{
					CString cf;

					cf.Format("Reading %s", strlwr(up->curfile));

					Info1(cf);
				}

				newStep = false;
			}
			break;

		case CUud32acxCtrl::uudActDecoding:
			if (newStep || up->partno != oldPart)
			{
				CString wrk;

				strlwr(up->curfile);

				wrk.Format("Decoding %s [Part %d/%d]",
					up->curfile, up->partno, up->numparts);

				Info1(wrk);

				newStep = false;
				oldPart = up->partno;
			}
			break;
	}

	ProgBar.SetPos(up->percent);

	delete up;						// Done with info structure

return(TRUE);
}


//
// Message pass on
//

afx_msg LONG DecodeDlg::OnMessage(WPARAM Level, LPARAM np)
{

	if (SHOW_DEBUG && deBox.m_hWnd != NULL)
		deBox.PostMessage(DEBOX_ADD, Level, np);
	else
		delete (CString *) np;

return(TRUE);
}



//
// Threaded operation done
//
afx_msg LONG DecodeDlg::OnEngineDone(UINT rc, LONG operation)
{

	switch (operation)
	{
		case ENG_LOAD:
			DecodePreviewDone((int) rc);
			break;

		case ENG_DECLIST:
			DecodeGoDone((int) rc);
			break;
	}

	GetParent()->PostMessage(MSG_CMDNEXT);			// Handle next command line option if any

return(TRUE);
}



//
// Row has changed
//
afx_msg LONG DecodeDlg::OnEngineRowChange(UINT row, LONG lParam)
{

	switch (decoder->State)
	{
		case Engine::ENG_READING:
			m_DecodeList.SetCaretIndex(row, FALSE);
			if (row > 0)
				m_DecodeList.SetSel(row - 1, FALSE);
			m_DecodeList.SetSel(row, TRUE);

			if (SHOW_DEBUG)
			{
				CString item, wrk;

				m_DecodeList.GetText(row, item);

				wrk.Format("\r\nReading %s:",
					(const char *) item);

				deBox.Add(wrk);
			}
			break;

		case Engine::ENG_DECODING:
			LV_FINDINFO lvf;
			lvf.flags = LVFI_PARAM;
			lvf.lParam = row;

			if ((row = m_DecodeOut.FindItem(&lvf)) == -1)
				break;				// Couldn't convert

			if (row > 0) 
				m_DecodeOut.SetSel(row - 1, false);	// Unselect previous

			m_DecodeOut.SetSel(row, true);		// Select current
			m_DecodeOut.EnsureVisible(row, FALSE);
			m_DecodeOut.UpdateWindow();

			if (SHOW_DEBUG)
			{
				CString item, wrk;

				item = m_DecodeOut.GetItemText(row, 0);

				wrk.Format("\r\nDecoding %s:",
					(const char *) item);

				deBox.Add(wrk);
			}
			break;

	}

return(TRUE);
}



//
// First pass at destroying background thread
//

void DecodeDlg::OnDestroy() 
{
	if (decoder != NULL && decoder->m_hThread != NULL && decoder->State != Engine::ENG_DYING)
	{
		decoder->PostThreadMessage(ENG_CANCEL, 0, 0);	// Make sure it stops
		decoder->PostThreadMessage(ENG_STOP, 0, 0);

		WaitForSingleObject(decoder->m_hThread, 5000);
	}

	if (deBox.m_hWnd != NULL)
		deBox.DestroyWindow();
	
	CSizeDialog::OnDestroy();
	
}


//
// Want to update an icon
//

afx_msg LONG DecodeDlg::OnUpdateIcon(WPARAM row, LPARAM lp)
{
	LV_FINDINFO lvf;
	lvf.flags = LVFI_PARAM;
	lvf.lParam = row;

	if ((row = m_DecodeOut.FindItem(&lvf)) != -1)
		m_DecodeOut.SetImage(row, 
			DecIcon(m_DecodeOut.GetItemData(row), NULL));	// Update the icon

return(TRUE);
}


//
// Want to update a name
//
afx_msg LONG DecodeDlg::OnUpdateName(WPARAM row, LPARAM newname)
{
	CString *sp = (CString *) newname;

	LV_FINDINFO lvf;
	lvf.flags = LVFI_PARAM;
	lvf.lParam = row;

	if ((row = m_DecodeOut.FindItem(&lvf)) != -1)
		m_DecodeOut.SetItemText(row, 0, (const char *) *sp);	// Update the icon

	delete sp;

return(TRUE);
}



//
// Handle Progress messages
//

afx_msg LONG DecodeDlg::OnSetAuto(WPARAM wParam, LPARAM uuptr)
{

	options[OPT_OWMODE] = (wParam) ? OPT_OW_AUTO : OPT_OW_PROMPT;

	OptionButtonSet();

return(TRUE);
}



//
// Handle Command Line messages
//

afx_msg LONG DecodeDlg::OnCommandLine(WPARAM wParam, LPARAM lParam)
{
	CString *param = (CString *) lParam;

	bool rc = true;

	int offset = 0;

	if (param->IsEmpty())			// This is a flag by itself
		switch (wParam)
		{
			case 'g':				// Go!
				if (State == MS_PREVIEW)
				{
					DecodePreview();
					offset = -1;		// Bump the parameter to cause a repeat
				}
				else if (State == MS_GO)
					DecodeGo();
				break;
		}
	else							// Not a flag but a parameter
		switch (wParam)
		{
			case 'a':				// Explicit "add" mode
			case 'd':				// After /d enter Add mode
				rc = CLAddFiles(*param);
				break;

			case 'o':				// Options
				param->MakeLower();	// Force lowercase
				rc = CLSetOptions(*param);
				break;

			case 'p':				// Path
				m_DecodePath.SetWindowText(*param);
				break;
		}

	delete param;			// Always delete the string sent from the parent window

	if (rc)
		GetParent()->PostMessage(MSG_CMDNEXT, offset);	// Move on to next item

return(TRUE);
}



//
// Add files
//

bool DecodeDlg::CLAddFiles(const char *fMask)
{
	CFileFind ff;
	CString wrk;
	BOOL loop;

	loop = ff.FindFile(fMask, 0); 
	while (loop)
	{
		loop = ff.FindNextFile();
		if (!ff.IsDirectory())
		{ 
			wrk = ff.GetFilePath();
			wrk.MakeLower();
			m_DecodeList.AddString(wrk);
		}
	}

	if (m_DecodeList.GetCount() > 0)
		SetState(MS_PREVIEW);		// There's something to decode

return(true);
}



//
// Set options from command line
//


bool DecodeDlg::CLSetOptions(const char *oList)
{
	const char *p;

	for (p=oList; *p != EOS; p++)
		switch (*p)
		{
			case 'b':
				options[OPT_BRACK] = TRUE;
				break;

			case 'd':
				options[OPT_DUMB] = TRUE;
				break;

			case 'e':
				options[OPT_ETEXT] = TRUE;
				break;

			case 'f':
				options[OPT_FASTMODE] = TRUE;
				break;

			case 'i':
				options[OPT_IGNREPLY] = TRUE;
				break;

			case 'm':
				options[OPT_STRICT] = TRUE;
				break;

			case 'n':
				options[OPT_OWMODE] = OPT_OW_AUTO;
				break;

			case 'o':
				options[OPT_OWMODE] = OPT_OW_OW;
				break;

			case 'p':
				options[OPT_OWMODE] = OPT_OW_PROMPT;
				break;

			case 'r':
				options[OPT_RECYCLE] = TRUE;
				break;

			case 's':
				options[OPT_DESPERATE] = TRUE;
				break;

			case 'v':
				options[OPT_PCASE] = TRUE;
				break;
		}

return(true);
}



//
// Handle Rename messages
//

afx_msg LONG DecodeDlg::OnRenameOutput(WPARAM wParam, LPARAM engRenamePtr)
{
	Engine::EngineRename *er = (Engine::EngineRename *) engRenamePtr;

	RenOutFile rfBox;

	decoder->PostThreadMessage(ENG_RENRES, 
		rfBox.Prompt(&er->path, er->nameOnly, er->UD), 0);

	if (rfBox.m_hWnd != NULL)
		rfBox.DestroyWindow();		// Make sure it's dead to prevent annoying debugger messages

return(TRUE);
}



//
// Handle Default Request ID
//

afx_msg LONG DecodeDlg::OnGetDefID(WPARAM wParam, LPARAM uuptr)
{

	return(MAKELONG(0, DC_HASDEFID));

}
