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


// DecodeDlg.cpp : implementation file for Decode dialog
//

#include "stdafx.h"
#include "Uud32.h"
#include "DecodeDlg.h"
#include "uud32acx.h"			// Bring in UUD control defs
#include "InfoDialog.h"
#include "MikeNPopupMenu.h"
#include "LaunchDialog.h"

static char *ext_list[] ={		// List of extensions we associate with UUDeview
	".uue",
	".xxe",
	".b64",
	".mim",
	".uu",
	".xx",
	".hqx",
	NULL
	};

//
// CSizeTable table
//
#include "hlp\decode.hh"
#include "hlp\decopt.hh"

static struct CSizeDialog::DialogSizerInit ds_list[] ={
	{ 2,						DSZ_SET_D,					2	},	// Set dividers
	{ IDC_DECODEGO,				DSZ_MOVEX_D,				Decoding_Details,
		IDS_DECODEGO			},
	{ IDC_DECODEPATHBROWSE,		DSZ_MOVEX_D,				Decoding_Details,
		IDS_DECODEPATHBROWSE	},
	{ IDC_DECODEOPTIONS,		DSZ_MOVEX_D,				Decoding_Options,
		IDS_DECODEOPTIONS		},
	{ IDC_CLEARDECODE,			DSZ_MOVEX_D,				IM_Decode_Clear,
		IDS_CLEARDECODE		},
	{ IDC_DECODELIST,			DSZ_STACK | DSZ_SIZEW_D | DSZ_SIZEH, Decoding_Details,
		IDS_DECODELIST		},
	{ IDC_ADDDECODE,			DSZ_MOVEY | DSZ_LFX,		Adding_Files_To_Decode,
		IDS_ADDDECODE		},
	{ IDC_ADDCLIPBOARD,			DSZ_MOVEY | DSZ_CTRX,		Adding_Files_To_Decode,
		IDS_ADDCLIPBOARD	},
	{ IDC_REMOVEDECODE,			DSZ_MOVEY | DSZ_RTX,		Adding_Files_To_Decode,
		IDS_REMOVEDECODE	},
	{ IDC_DECODEOUTPUTLIST,		DSZ_STACK | DSZ_MOVEX_D | DSZ_SIZEW_D | DSZ_SIZEH,	
		Decode_Preview,		IDS_DECODEOUTPUTLIST	},
	{ IDC_REMOVEDECODEOUT,		DSZ_MOVEY | DSZ_RTX,		Decode_Remove_Definition,
		IDS_REMOVEDECODEOUT	},
	{ IDC_RENAMEDECODEOUT,		DSZ_MOVEY | DSZ_CTRX,		Decode_Rename_Definition,
		IDS_RENAMEDECODEOUT	},
	{ IDC_DECODEINFO,			DSZ_MOVEY | DSZ_LFX,		Decode_Info_Defn,
		IDS_DECODEINFO		},
	{ IDC_DECINFOBOX,			DSZ_MOVEY | DSZ_SIZEW,		0	},
	{ IDC_INFO1,				DSZ_MOVEY | DSZ_SIZEW,		0	},
	{ IDC_INFO2,				DSZ_MOVEY | DSZ_SIZEW,		0	},
	{ IDC_DECODEPROGRESS,		DSZ_MOVEY | DSZ_SIZEW,		0	},
	{ IDC_DECODEPATH,			DSZ_SIZEW_D | DSZ_MOVEX_D,	Decoding_Details,
		IDS_DECODEPATH		},
	{ IDC_TOLABEL,				DSZ_MOVEX_D,				0	},
	{ IDC_DEC_CH,				DSZ_MOVEX_D,				0,
		IDS_DEC_CH			},
	{ -1 }						// End of table marker
	};
//
// --------------------------------------------
//

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
// AFX tables
//

BEGIN_MESSAGE_MAP(DecodeDlg, CSizeDialog)
	//{{AFX_MSG_MAP(DecodeDlg)
	ON_BN_CLICKED(IDC_ADDDECODE, OnAdddecode)
	ON_LBN_SELCHANGE(IDC_DECODELIST, OnSelchangeDecodelist)
	ON_BN_CLICKED(IDC_CLEARDECODE, OnClearDecode)
	ON_BN_CLICKED(IDC_REMOVEDECODE, OnRemoveDecode)
	ON_BN_CLICKED(IDC_DECODEGO, OnDecodeGo)
	ON_BN_CLICKED(IDC_DECODEPATHBROWSE, OnDecodePathBrowse)
	ON_BN_CLICKED(IDC_DECODEOPTIONS, OnDecodeOptions)
	ON_NOTIFY(NM_CLICK, IDC_DECODEOUTPUTLIST, OnClickDecodeOutputList)
	ON_NOTIFY(NM_SETFOCUS, IDC_DECODEOUTPUTLIST, OnSetfocusDecodeOutputList)
	ON_BN_CLICKED(IDC_RENAMEDECODEOUT, OnRenameDecodeOut)
	ON_BN_CLICKED(IDC_REMOVEDECODEOUT, OnRemoveDecodeOut)
	ON_NOTIFY(LVN_ENDLABELEDIT, IDC_DECODEOUTPUTLIST, OnEndLabelEditDecodeOutputList)
	ON_BN_CLICKED(IDC_DECODEINFO, OnDecodeInfo)
	ON_NOTIFY(LVN_KEYDOWN, IDC_DECODEOUTPUTLIST, OnKeydownDecodeOutputList)
	ON_BN_CLICKED(IDC_ADDCLIPBOARD, OnAddClipboard)
	ON_BN_CLICKED(IDC_DEC_CH, OnStartContextHelp)
	ON_WM_SIZE()
	ON_WM_ACTIVATE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_MESSAGE(ENG_DONE, OnEngineDone)
	ON_MESSAGE(ENG_ROWCHG, OnEngineRowChange)
	ON_MESSAGE(ENG_UPDICO, OnUpdateIcon)
	ON_MESSAGE(ENG_UPDNAME, OnUpdateName)
	ON_MESSAGE(ENG_MESSAGE, OnMessage)
	ON_MESSAGE(ENG_PROGRESS, OnProgress)
	ON_MESSAGE(ENG_SETAUTO, OnSetAuto)
	ON_MESSAGE(MSG_CMDLINE, OnCommandLine)
	ON_MESSAGE(ENG_RENAME, OnRenameOutput)
	ON_MESSAGE(DM_GETDEFID, OnGetDefID)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DecodeDlg dialog


DecodeDlg::DecodeDlg(CWnd* pParent /*=NULL*/)
	: CSizeDialog(ds_list, DecodeDlg::IDD, NULL, pParent, 0, 0 /* MINW */, 0 /* Minh */)
{
	//{{AFX_DATA_INIT(DecodeDlg)
	//}}AFX_DATA_INIT

	State = MS_UNKNOWN;

	DStatusIcons.Create(IDB_STATUSBLOTS, 21, 5, RGB(255,255,255));

	ri.Start(REG_BASE, REG_VNO, "decode");		// Set up RegINI

	inproc = false;

	clipboardSet = false;

	decoder = NULL;

}


DecodeDlg::~DecodeDlg()
{

	if (decoder != NULL)
		delete decoder;

}


//
// Shutdown dialog
//

void DecodeDlg::SaveState(bool write)
{
	CString OutputPath;

	if (write)
	{									// Direction-sensitive stuff
		m_DecodePath.GetWindowText(OutputPath);
		deBox.SaveSize();
	}
	else
		ZeroMemory(options, sizeof(options));	// Start with options empty

	ri.BiDir("OutputPath", OutputPath, write);		// Output Path

	ri.BiDir("Options", options, sizeof(options), write);

	ri.BiDirMRU("OutPath", &m_DecodePath, write);	// Output Path MRU list

	ri.BiDirWindowPosn("InfoPosn", infoPosn, write);	// Info box position

	ri.BiDirWindowPosn("DebugPosn", debugPosn, write);	// Debug box position

	ri.BiDir("AddDir", addDir, write);		// Default add decode files dir
	ri.BiDir("AddFilter", addFilter, write);	// Select filter in Add box

	ri.BiDir("Launch", launchList, MAX_MRU, write);	// Read the Decode These launch MRU list
	ri.BiDir("LaunchDir", launchDir, write);

	ri.BiDir("LaunchOut", launchOutList, MAX_MRU, write);
	ri.BiDir("LaunchOutDir", launchOutDir, write);

	ri.BiDir("Assoc", assoc, write);		// Association state

	ri.BiDir("Edit", editList, MAX_MRU, write);		// Edit state
	ri.BiDir("EditDir", editDir, write);
	ri.BiDir("EditLast", editLast, write);

	ri.BiDir("TempFolder", tempFolder, write);		// Where to put working files

	ri.Close();

	if (!write)
	{
		if (OutputPath.IsEmpty())
		{
			GetCurrentDirectory(MAX_PATH, OutputPath.GetBuffer(MAX_PATH + 1));
			OutputPath.ReleaseBuffer();
		}

		m_DecodePath.SetWindowText(OutputPath);

		EnableToolTips(!options[OPT_HIDETIPS]);

		OptionButtonSet();
	}

}


//
// Initial setup just before box appears
//

BOOL DecodeDlg::OnInitDialog()
{
	BOOL rc = CSizeDialog::OnInitDialog();

	EnableToolTips(TRUE);

	m_DecodeOut.SetImageList(&DStatusIcons, LVSIL_SMALL);

	RECT r;
	m_DecodeOut.GetClientRect(&r);

	m_DecodeOut.InsertColumn(0, "Output File", LVCFMT_LEFT, 
		r.right - r.left - 20, -1);

	m_DecodePath.GetWindowRect(&r);
	ScreenToClient(&r);
	r.bottom += 150;
	m_DecodePath.MoveWindow(&r, FALSE);

	CUud32App *pApp = (CUud32App *) AfxGetApp();

	if (pApp->GetCLMode())			// Command line mode
	{
		ZeroMemory(options, sizeof(options));		// Set all options to defaults
		options[OPT_OWMODE] = OPT_OW_AUTO;		// Except default to autonumber mode

		OptionButtonSet();			// Show option button as indicated

		char wrk[_MAX_PATH + 16];

		GetCurrentDirectory(_MAX_PATH, wrk);

		m_DecodePath.SetWindowText(wrk);
	}
	else
		SaveState(false);					// Read in the current state

	if (State == MS_UNKNOWN)
		SetState(MS_CLEAR);				// If we got this far without a state set, do the default

	dlgName = "Decode";

	m_CHelp.SetIcon(pApp->LoadIcon(IDI_QMARK));

return(rc);
}


void DecodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DecodeDlg)
	DDX_Control(pDX, IDC_DECINFOBOX, m_InfoBox);
	DDX_Control(pDX, IDC_DEC_CH, m_CHelp);
	DDX_Control(pDX, IDC_DECODEPATHBROWSE, m_DPathBrowse);
	DDX_Control(pDX, IDC_ADDCLIPBOARD, m_AddClipboard);
	DDX_Control(pDX, IDC_ADDDECODE, m_AddDecode);
	DDX_Control(pDX, IDC_DECODEPROGRESS, ProgBar);
	DDX_Control(pDX, IDC_CLEARDECODE, m_ClearDecode);
	DDX_Control(pDX, IDC_RENAMEDECODEOUT, m_RenameDecodeOut);
	DDX_Control(pDX, IDC_REMOVEDECODEOUT, m_RemoveDecodeOut);
	DDX_Control(pDX, IDC_INFO2, m_Info2);
	DDX_Control(pDX, IDC_INFO1, m_Info1);
	DDX_Control(pDX, IDC_DECODEPATH, m_DecodePath);
	DDX_Control(pDX, IDC_DECODEOUTPUTLIST, m_DecodeOut);
	DDX_Control(pDX, IDC_DECODEOPTIONS, m_DecodeOptions);
	DDX_Control(pDX, IDC_DECODEINFO, m_DecodeInfo);
	DDX_Control(pDX, IDC_DECODEGO, m_DecodeGo);
	DDX_Control(pDX, IDC_REMOVEDECODE, m_RemoveDecode);
	DDX_Control(pDX, IDC_DECODELIST, m_DecodeList);
	//}}AFX_DATA_MAP
}


/////////////////////////////////////////////////////////////////////////////
// DecodeDlg message handlers


//
// Alter the buttons states, etc.
//
void DecodeDlg::SetState(enum MachineState ns, bool force)
{

	if (ns == State && !force)
		return;				// State is already set

	switch (ns) {
		case MS_CLEAR:
			m_DecodeGo.SetLabel(IDS_PREVIEW);
			SetToolTip(IDC_DECODEGO, IDS_DIS_CLEAR);
			m_DecodeGo.Disable();
			m_ClearDecode.Disable();
			m_RemoveDecode.Disable();
			m_DecodeInfo.Disable();
			m_RenameDecodeOut.Disable();
			m_RemoveDecodeOut.Disable();

			InfoClear();

			ClipboardKill();

			m_DecodeList.ResetContent();
			m_DecodeOut.DeleteAllItems();
			break;

		case MS_PREVIEW:
			m_DecodeGo.SetLabel(IDS_PREVIEW);
			SetToolTip(IDC_DECODEGO, IDS_DIS_PREVIEW);
			m_DecodeGo.Enable();
			m_ClearDecode.Enable();
			m_RemoveDecode.Disable();
			m_DecodeInfo.Disable();
			m_RenameDecodeOut.Disable();
			m_RemoveDecodeOut.Disable();

			InfoClear();

			m_DecodeOut.DeleteAllItems();
			break;

		case MS_GO:
			m_DecodeGo.SetLabel(IDS_GO);
			SetToolTip(IDC_DECODEGO, IDS_DIS_GO);
			m_DecodeGo.Enable();
			m_ClearDecode.Enable();
			m_RemoveDecode.Disable();
			m_DecodeInfo.Disable();
			m_RenameDecodeOut.Disable();
			m_RemoveDecodeOut.Disable();
			break;

		case MS_DONE:
			m_DecodeGo.SetLabel(IDS_PREVIEW);
			SetToolTip(IDC_DECODEGO, IDS_DIS_DONE);
			m_DecodeGo.Disable();
			m_ClearDecode.Enable();
			m_RemoveDecode.Disable();
			m_DecodeInfo.Disable();
			m_RenameDecodeOut.Disable();
			m_RemoveDecodeOut.Disable();
			break;

		}

	State = ns;

}


//
// Clear the Info fields
//
void DecodeDlg::InfoClear()
{

	Info1((const char *) NULL);
	Info2(NULL);

}


void DecodeDlg::Info1(				// Set the Info 1 text
const char *nstr)
{

	m_Info1.SetWindowText((nstr == NULL) ? "" : nstr);

}


void DecodeDlg::Info1(				// Set the Info 1 text
UINT msg_no)
{

	CString msg;
	
	msg.LoadString(msg_no);

	m_Info1.SetWindowText(msg);

}


void DecodeDlg::Info2(				// Set the Info 2 text
const char *nstr)
{

	m_Info2.SetWindowText((nstr == NULL) ? "" : nstr);

}


//
// Clipboard cleanup
//
void DecodeDlg::ClipboardKill()
{

	clipboardSet = false;
	cFile.Kill();					// Delete the temp file if any
	clipboardString.Empty();

}


//
// Hourglass (working)... turns on progress bar too
//

void DecodeDlg::HourGlass(bool on)
{

	if (on) 
	{
		ProgBar.SetPos(0);						// Always start at 0
		m_Info2.ShowWindow(SW_HIDE);
		ProgBar.ShowWindow(SW_SHOW);

		EnablePushExcept(FALSE,  
			IDC_DECODEGO,
			IDC_DECINFOBOX,
			IDC_INFO1,
			IDC_DECODEPROGRESS,
			IDC_TOLABEL,
			0);

		OnCommand(DT_NONE, 0);		// Unselect all in both lists
		OnCommand(DO_NONE, 0);

		GetParent()->PostMessage(WAIT_CURSOR, TRUE, 0);		// Turn on the wait cursor
	}
	else 
	{
		ProgBar.ShowWindow(SW_HIDE);
		m_Info2.ShowWindow(SW_SHOW);
		UnStackEnabled(TRUE);

		GetParent()->PostMessage(WAIT_CURSOR, FALSE, 0);		// Turn off the wait cursor
	}

}


//
// User Clicked the Preview button
//

void DecodeDlg::DecodePreview() 
{
	CString lfn;

	EngineSetup();

	decoder->PostThreadMessage(ENG_CLEAR, 1, 0);	// Clear any existing list (and reset control)

	m_DecodeGo.SetLabel(IDS_CANCELBUTTON);

	InfoClear();

	HourGlass(true);

	m_DecodeList.SetSel(-1, FALSE);			// Clear all selections

	int rmax = m_DecodeList.GetCount();

	if (rmax == 0)
		return;

	TransferOptions(&decoder->UD);						// Copy options to the control

	CWaitCursor wai;

	if (SHOW_DEBUG)
		deBox.Init(&debugPosn);

	CString cpath = CurrentOutput();

	for (int row=0; row < rmax; row++)		// Step through the whole list
	{
		m_DecodeList.GetText(row, lfn);		// Read the filename

		if (clipboardSet && lfn == clipboardString)
		{
			cFile.Close();				// Make sure the temp is closed

			decoder->PostThreadMessage(ENG_DECODE, row,
				(LPARAM) (strdup((const char *) cFile)));
		}
		else
			decoder->PostThreadMessage(ENG_DECODE, row,
				(LPARAM) (strdup((const char *) lfn)));
	}

	decoder->PostThreadMessage(ENG_LOAD, 0, 0);

}


//
// The decode preview is done
//

void DecodeDlg::DecodePreviewDone(int rc)
{
	bool clmode = ((CUud32App *) AfxGetApp())->GetCLMode();

	if (SHOW_DEBUG)
	{
		deBox.Ready();					// OK to interact with debug box
		decoder->UD.SetLastMessage("");			// Messages already retrieved
	}

	if (rc == CUud32acxCtrl::uudRetCancel)		// Cancel.
	{
		HourGlass(false);
		m_DecodeGo.SetLabel(IDS_PREVIEW);
		Info1(IDS_CANCEL);
		return;
	}
	else if (rc != CUud32acxCtrl::uudRetOK)
	{
		CString emsg(decoder->UD.GetLastMessage());

		CString lfn;

		int row = m_DecodeList.GetFirstSel();

		if (row >= 0)
			m_DecodeList.GetText(row, lfn);
		else
			lfn = "(Unknown?)";

		if (ArgMessageBox("Load Encoded Files", MB_OKCANCEL | MB_ICONQUESTION,
				"Error loading file:\r\n%s\r\nCode: %d [%s]\r\nContinue?",
				(const char *) lfn, rc, (const char *) emsg) == IDOK)
			decoder->PostThreadMessage(ENG_LOAD, 0, 0);		// Restart the engine with next file
		else
		{
			HourGlass(false);
			Info1(IDS_CANCEL);
			m_DecodeGo.SetLabel(IDS_PREVIEW);
		}

		return;
	}

	Info1("Done loading.");
	CString lfn(decoder->UD.GetLastMessage());
	Info2(lfn);			// Messages already routed

	m_DecodeList.SetSel(-1, FALSE);			// Clear all selections
	m_DecodeList.SetCaretIndex(0, FALSE);	// Scroll list back to top

	int row, rmax = decoder->UD.GetDFCount();					// Read maximum file count
	CString cpath(CurrentOutput());

	if (rmax == 0) 
	{
		Info1(IDS_NOTHING_DECODE);

		if (!clmode)
		{
			CString msg;
			msg.LoadString(IDS_NOFIND_DECODE);
			MessageBox(msg, "Decode",
				MB_ICONEXCLAMATION | MB_OK);
		}

		m_DecodeGo.SetLabel(IDS_PREVIEW);
		HourGlass(false);
		SetState(MS_PREVIEW);
		return;
	}

	m_DecodeOut.SetRedraw(FALSE);

	m_DecodeOut.SetItemCount(rmax + 1);		// Maximum items to add...

	for (row=0; row < rmax; row++)
		if (!(decoder->UD.GetDFileFlags(row) & CUud32acxCtrl::uudFileNoData)) 
		{
			lfn = decoder->UD.GetDFile(row);
			lfn = decoder->UD.FileFilter(lfn);
			if (!options[OPT_PCASE])		// Preserve case on output
				lfn.MakeLower();
			m_DecodeOut.InsertItem(LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM, 0, lfn, 0, 0, DecIcon(row, cpath + lfn), row);
		}

	m_DecodeOut.SetRedraw(TRUE);

	HourGlass(false);

	if (m_DecodeOut.GetItemCount() == 0)
	{
		Info1(IDS_NOTHING_DECODE);

		CString msg;
		msg.LoadString(IDS_NOTHING_DECODE);

		m_DecodeGo.SetLabel(IDS_PREVIEW);

		if (!clmode)
			MessageBox(msg, "Decode",
				MB_ICONEXCLAMATION | MB_OK);

		SetState(MS_PREVIEW);
		return;
	}

	DupCheck();
	SetState(MS_GO);

	if (options[OPT_DNOPROMPT])		// Decode without prompting
	{
		CWnd *go = GetDlgItem(IDC_DECODEGO);

		ASSERT(go != NULL);

		if (!clmode && go != NULL)			// Not command line mode
			PostMessage(WM_COMMAND, IDC_DECODEGO, (LPARAM) go->m_hWnd);
	}

}


//
// Copy the options to the UUDeview control
//

void DecodeDlg::TransferOptions(CUud32acxCtrl *UDp)
{

	UDp->m_bracketPolicy = options[OPT_BRACK];
	UDp->m_verbose = options[OPT_DEBUG];
	UDp->m_dumb = options[OPT_DUMB];
	UDp->m_useText = options[OPT_ETEXT];
	UDp->m_fastMode = options[OPT_FASTMODE];
	UDp->m_ignoreReply = options[OPT_IGNREPLY];
	UDp->m_desperate = options[OPT_DESPERATE];
	UDp->m_strictMime = options[OPT_STRICT];
	UDp->m_strictFilenames = options[OPT_STRICTFN];
	UDp->m_removeAfter = 0;		// Don't allow it to recycle

}



//
// Turn the Font button to Italic if any options are set...
//

void DecodeDlg::OptionButtonSet()
{
	BOOL *bp = options;

	for (int i=OPT_MAX+1; i > 0; i--)
		if (*bp++)						// Options are set...
		{
			m_DecodeOptions.SetLabel("¤ &Options...");
			return;
		}

	m_DecodeOptions.SetLabel("&Options...");

}


//
// Figure out what the current directory is
//

CString DecodeDlg::CurrentOutput()
{
	CString op;

	op.Empty();

	m_DecodePath.GetWindowText(op);		// Read current output dir

	if (op.IsEmpty())				// Default to current dir
	{
		GetCurrentDirectory(MAX_PATH, op.GetBuffer(MAX_PATH + 1));
		m_DecodePath.SetWindowText(op);		// Also set it
		op.ReleaseBuffer();
	}

	int l = op.GetLength();

	if (l > 0 && op[l - 1] != '\\')
		op += '\\';				// Make sure there's a trailing backslash

return(op);
}



//
// Figure out the icon for a file
//

int DecodeDlg::DecIcon(
int row,						// Row in UD.DFile
const char *cs)					// Calculated output filename
{
	int rc;
	int f = decoder->UD.GetDFileFlags(row);

	if (decoder->UD.GetDFileInfo(row).IsEmpty())		// No Info
	{
		if (f & CUud32acxCtrl::uudFileDecoded)
			rc = SI_DECODEDOK;
		else if (f & CUud32acxCtrl::uudFileError)
			rc = SI_DECODEFAILED;
		else if (f & CUud32acxCtrl::uudFileOK)
		{
			if (cs != NULL && cs[0] != EOS && FExist(cs))
				rc = SI_CONFLICT;
			else
				rc = SI_OK;
		}
		else if (f & CUud32acxCtrl::uudFileNoEnd)
			rc = SI_QUESTION;
		else if (f & (CUud32acxCtrl::uudFileNoBegin | CUud32acxCtrl::uudFileMisPart | CUud32acxCtrl::uudFileNoData))
			rc = SI_BAD;
		else
			rc = SI_QUESTION;
	} else {								// There IS info
		if (f & CUud32acxCtrl::uudFileDecoded)
			rc = SI_DECODEDOK;
		else if (f & CUud32acxCtrl::uudFileError)
			rc = SI_DECODEFAILED;
		else if (f & CUud32acxCtrl::uudFileOK)
		{
			if (cs != NULL && cs[0] != EOS && FExist(cs))
				rc = SII_CONFLICT;
			else
				rc = SII_OK;
		}
		else if (f & CUud32acxCtrl::uudFileNoEnd)
			rc = SII_QUESTION;
		else if (f & (CUud32acxCtrl::uudFileNoBegin | CUud32acxCtrl::uudFileMisPart | CUud32acxCtrl::uudFileNoData))
			rc = SII_BAD;
		else
			rc = SII_QUESTION;
	}

return(rc);
}



//
// Pop up the Decode menu
//

void DecodeDlg::ShowDecodeMenu()
{
	static struct MikeNPopupMenu::PopMenu menul[] ={
		"&Remove",				DT_REMOVE,
		NULL,					0,
		"Select &None",			DT_NONE,
		"Select &All",			DT_ALL,
		"&Invert Selection",	DT_INV,
		NULL,					0,
		"&Launch",				DT_LAUNCH,
		"&Edit",				DT_EDIT,
		NULL,					0,
		"&Help",				DT_HELP,
		NULL,					-1
	};

	if (m_DecodeList.GetCount() == 0)
		return;							// Nothing to do

	MikeNPopupMenu m(menul);

	m.EnableList((m_DecodeList.GetSelCount() > 0),
		DT_REMOVE, DT_LAUNCH, DT_NONE, DT_EDIT, 0);

	m.PopIt(m_DecodeList.clickAddr, this);

}


//
// Show the Decode Output menu
//

void DecodeDlg::ShowDecodeOutMenu()
{
	static struct MikeNPopupMenu::PopMenu menul[] ={
		"&Info",				DO_INFO,
		"&Remove",				DO_REMOVE,
		"&Rename",				DO_RENAME,
		NULL,					0,
		"Select &None",			DO_NONE,
		"Select &All",			DO_ALL,
		"&Invert Selection",	DO_INV,
		NULL,					0,
		"&Decode && Launch",	DO_LAUNCH,
		NULL,					0,
		"&Help",				DO_HELP,
		NULL,					 -1
	};

	if (m_DecodeOut.GetItemCount() == 0)
		return;							// Nothing to do

	int ns = m_DecodeOut.GetSelectedCount();

	MikeNPopupMenu m(menul);

	m.EnableList((ns == 1),
		DO_INFO, DO_RENAME, 0);

	m.EnableList((ns > 0),
		DO_REMOVE, DO_LAUNCH, 0);

	m.PopIt(m_DecodeOut.clickAddr, this);

}


//
// Launch files from the Decode These Files list
//

void DecodeDlg::DecodeLaunch()
{
	LaunchDialog ld;

	int rmax = m_DecodeList.GetCount();

	if (rmax == 0)
		return;					// Nothing to do

	int scount = m_DecodeList.GetSelCount();	// Read number of selected items

	int *slist = (int *) _alloca(sizeof(int) * (scount + 1));	// Create the selection list
	int *eos = slist + scount;			// End

	m_DecodeList.GetSelItems(scount, slist);	// Read the selected items

	int *slp = slist;			// Point into the item list
	int *srchp;

	CFileName here, search, appname;

	CString here_ext;

	bool multi;					// Multiple

	int rc;

	if (!options[OPT_LNOPROMPT])
		while (scount > 0)
		{
			while (*slp == -1)		// Already handled
				slp++;				// Skip

			m_DecodeList.GetText(*slp, here.GetStr());	// Read a selected item's text

			here_ext = here.Ext();	// Read the extension

			multi = false;			// Start with multi off

			for (srchp=slp+1; srchp < eos; srchp++)
				if (*srchp != -1)
				{
					m_DecodeList.GetText(*srchp, search.GetStr());
					if (here_ext.CompareNoCase(search.Ext()) == 0)
					{
						multi = true;	// We've got more than one...
						break;
					}
				}

			rc = ld.GetLFN(here, multi, appname.GetStr(), launchList, &launchDir,
				&options[OPT_LNOPROMPT]);

			if (options[OPT_LNOPROMPT])
			{
				OptionButtonSet();
				break;				// User switched to no-prompt mode
			}

			switch (rc)
			{
				case IDCANCEL:		// Jump out
					return;

				case IDOK:
					multi = false;		// Only handle one
					break;

				case LDIAG_ALL:
					multi = true;		// Handle all
					break;
			}

			if (!EngineSetup())
				return;

			for (srchp=slp; srchp < eos; srchp++)
				if (*srchp != -1)
				{
					m_DecodeList.GetText(*srchp, search.GetStr());
					if (here_ext.CompareNoCase(search.Ext()) == 0)
					{
						struct Engine::EngineLaunch *ep = new struct Engine::EngineLaunch;
						MSG msg;

						ASSERT(ep != NULL);

						ep->app = appname;
						ep->filen = search;

						decoder->PostThreadMessage(ENG_LAUNCH, 0, (LPARAM) ep);

						m_DecodeList.SetSel(*srchp, FALSE);
						*srchp = -1;		// This one's been done
						scount--;			// One less selected

						if (!multi)			// Caller only wanted one 
							break;

						if (::PeekMessage(&msg, m_hWnd, ENG_DONE, ENG_DONE, PM_REMOVE)
								&& msg.wParam)
							break;			// Launch error
					}						// Ext match
				}							// Not already done

			slp++;							// At a minimum, advance 1
		}									// scount > 0, prompt mode

	if (options[OPT_LNOPROMPT] && EngineSetup())		// No prompt mode either initially or broke out from loop
		for (; slp < eos; slp++)
			if (*slp != -1)			// Hasn't been processed yet
			{
				m_DecodeList.GetText(*slp, search.GetStr());

				struct Engine::EngineLaunch *ep = new struct Engine::EngineLaunch;
				MSG msg;

				ASSERT(ep != NULL);

//				ep->app = appname;			// Don't set app name for straight launch
				ep->filen = search;

				decoder->PostThreadMessage(ENG_LAUNCH, 0, (LPARAM) ep);

				m_DecodeList.SetSel(*slp, FALSE);

				if (::PeekMessage(&msg, m_hWnd, ENG_DONE, ENG_DONE, PM_REMOVE)
						&& msg.wParam)
					break;			// Launch error

			}

}



//
// Launch files from Decode Out list
//

void DecodeDlg::DecodeOutLaunch()
{
	LaunchDialog ld;

	int rmax = m_DecodeOut.GetItemCount();

	if (rmax == 0)
		return;					// Nothing to do

	int scount = m_DecodeOut.GetSelectedCount();	// Read number of selected items

	int *slist = (int *) _alloca(sizeof(int) * (scount + 1));	// Create the selection list
	int *eos = slist + scount;			// End

	m_DecodeOut.GetSelectedList(slist, scount);	// Read the selected items

	int *slp = slist;			// Point into the item list
	int *srchp;

	CFileName here, search, appname;

	CString here_ext, temp;
	CString unsafe(".lnk.exe.com.bat.pif.vbs");

	bool multi;					// Multiple

	int rc, flags;
	short row;

	CFileName tname;			// Will be used for temporary names

	decoder->UD.m_overwrite = TRUE;

	while (scount > 0)
	{
		while (*slp == -1)		// Already handled
			slp++;				// Skip

		here = m_DecodeOut.GetItemText(*slp, 0);	// Read a selected item's text

		here_ext = here.Ext();	// Read the extension
		here_ext.MakeLower();

		if (unsafe.Find(here_ext) >= 0)
		{
			if (ArgMessageBox("Decode & Launch", 
					MB_ICONINFORMATION | MB_OKCANCEL,
					"%s\r\nFor your protection, UUDeview won't\r\nLaunch executable files.",
					(const char *) here) == IDCANCEL)
				break;			// User decided to stop
			else
			{
				slp++;			// Move on to the next item
				scount--;
				continue;
			}
		}

		multi = false;			// Start with multi off

		for (srchp=slp+1; srchp < eos; srchp++)
			if (*srchp != -1)
			{
				search = m_DecodeOut.GetItemText(*srchp, 0);
				if (here_ext.CompareNoCase(search.Ext()) == 0)
				{
					multi = true;	// We've got more than one...
					break;
				}
			}

		row = (short) m_DecodeOut.GetItemData(*slp);	// Read row number

		flags = decoder->UD.GetDFileFlags(row);	// Store old flags

		rc = decoder->UD.DFileTo(row,		// Decode it
			tname.InTemp(m_DecodeOut.GetItemText(*slp, 0), tempFolder));	// To "real" name in temp directory

		decoder->UD.SetDFileFlags(row, flags);	// Restore old flags

		if (rc != CUud32acxCtrl::uudRetOK)
		{
			ArgMessageBox("Decode & Launch", MB_ICONEXCLAMATION | MB_OK,
				"Error decoding:\r\n%s", (const char *) tname);
			break;
		}

		CFileName::XFileAdd(tname);		// Delete it later

		if (options[OPT_LNOPROMPT])
		{
			rc = LDIAG_ALL;			// Always do all

			appname = tname.FindExec();	// Read the app from association
		}
		else
		{
			rc = ld.GetLFN(tname, multi, appname.GetStr(), 
				launchOutList, &launchOutDir, &options[OPT_LNOPROMPT]);

			GetTopLevelParent()->RedrawWindow();

			if (options[OPT_LNOPROMPT])
			{
				rc = LDIAG_ALL;
				OptionButtonSet();
			}
		}

		switch (rc)
		{
			case IDCANCEL:		// Jump out
				goto emex;

			case IDOK:
				multi = false;		// Only handle one
				break;

			case LDIAG_ALL:
				multi = true;		// Handle all
				break;
		}

		if ((rc = tname.Exec(appname)) != 0)		// Always do the first one if we get here
		{
			ArgMessageBox("Launch", MB_ICONEXCLAMATION | MB_OK,
				"Error %d executing:\r\n%s",
				rc, (const char *) tname);
			break;
		}

		m_DecodeOut.SetSel(*slp, FALSE);
		*slp++ = -1;		// This one's been done
		scount--;			// One less selected

		if (!multi)		// One only
			continue;

		for (srchp=slp; srchp < eos; srchp++)
			if (*srchp != -1)
			{
				search = m_DecodeOut.GetItemText(*srchp, 0);
				if (here_ext.CompareNoCase(search.Ext()) == 0)
				{
					if (decoder->UD.DFileTo((short) m_DecodeOut.GetItemData(*srchp), 
						tname.InTemp(m_DecodeOut.GetItemText(*srchp, 0), tempFolder)) != CUud32acxCtrl::uudRetOK)
					{
						ArgMessageBox("Decode & Launch", MB_ICONEXCLAMATION | MB_OK,
							"Error decoding:\r\n%s", (const char *) tname);
						break;
					}

					CFileName::XFileAdd(tname);		// Delete it later

					if ((rc = tname.Exec(appname)) != 0)
					{
						ArgMessageBox("Launch", MB_ICONEXCLAMATION | MB_OK,
							"Error %d executing:\r\n%s",
							rc, (const char *) tname);
						goto emex;
					}
					m_DecodeOut.SetSel(*srchp, FALSE);
					*srchp = -1;		// This one's been done
					scount--;			// One less selected
				}						// Ext match
			}							// Not already done

	}									// scount > 0

emex:

	if (ld.m_hWnd != NULL)
		ld.DestroyWindow();

	GetTopLevelOwner()->RedrawWindow();

}



//
// Check the list for duplicates
//

void DecodeDlg::DupCheck()
{
	int rmax = m_DecodeOut.GetItemCount() - 1;

	char last_text[MAX_PATH];		// Last text...
	char current_text[MAX_PATH];

	LV_ITEM item;
	int newicon;
	CString cpath;

	item.iItem = 0;
	item.iSubItem = 0;
	item.mask = (LVIF_TEXT | LVIF_IMAGE);
	item.pszText = last_text;
	item.cchTextMax = MAX_PATH - 1;

	m_DecodeOut.GetItem(&item);

	item.pszText = current_text;

	for (int row=1; row <= rmax; row++)
	{
		item.iItem = row;
		m_DecodeOut.GetItem(&item);
		newicon = item.iImage;

		if (!strcmp(last_text, current_text))		// Two members are equal
			newicon = 
					(item.iImage == SII_DUPLICATE ||	// Item has info
					 item.iImage == SII_CONFLICT ||
					 item.iImage == SII_BAD ||
					 item.iImage == SII_QUESTION) ? SII_DUPLICATE : SI_DUPLICATE;
		else if (item.iImage == SII_DUPLICATE || item.iImage == SI_DUPLICATE)
		{
			if (cpath.IsEmpty())
				cpath = CurrentOutput();

			newicon = DecIcon(m_DecodeOut.GetItemData(row), cpath + current_text);
		}

		if (item.iImage != newicon)				// There's been a change
			m_DecodeOut.SetImage(row, newicon);

		strcpy(last_text, current_text);
	}

}


//
// User Clicked the GO button (Decode Files)
//

void DecodeDlg::DecodeGo() 
{

	if (m_DecodeOut.GetItemCount() == 0)
		return;

	InfoClear();

	CString cpath = CurrentOutput();
	int errct = 0;

	TransferOptions(&decoder->UD);

	decoder->UD.m_overwrite = TRUE;				// Force overwrite mode

	decoder->POE = (options[OPT_POE] != 0);		// Set Pause on Errors flag
//	decoder->OWrite = (options[OPT_OWRITE] != 0);	// Set Overwrite OK flag

	OnCommand(DO_NONE, 0);				// Unselect everything

	if (cpath.GetLength() > 3)			// More than just a drive spec
	{
		CString fname(cpath);

		if (fname[fname.GetLength() - 1] == '\\')
			fname = fname.Left(fname.GetLength() - 1);		// Remove trailing backslash

		CFileStatus fsta;

		if (!CFile::GetStatus(fname, fsta))
		{
			ArgMessageBox("Decode Files", MB_ICONEXCLAMATION | MB_OK,
				"Output directory:\r\n%s\r\ndoes not exist.", 
				(const char *) fname);
			return;
		}

		if (!(fsta.m_attribute & CFile::directory))
		{
			ArgMessageBox("Decode Files", MB_ICONEXCLAMATION | MB_OK,
				"Output path:\r\n%s\r\nis in use as a filename or is not a directory.",
				(const char *) fname);
			return;
		}
	}										// Directory test if

	int rmax = m_DecodeOut.GetItemCount();
	CString lfn;
	int ud_row;

	ri.AddMRU(&m_DecodePath, MAX_MRU);

	CWaitCursor wai;
	HourGlass(true);

	m_DecodeGo.SetLabel(IDS_CANCELBUTTON);

	cancelFlag = false;

	if (SHOW_DEBUG)
		deBox.Init(&debugPosn);

	decoder->PostThreadMessage(ENG_CLEAR, 0, 0);	// Waste any existing list, but don't reset

	for (int row=0; !cancelFlag && row < rmax; row++)		// Actually decode the files
	{
		ud_row = m_DecodeOut.GetItemData(row);	// The UUDeview row number

		if (decoder->UD.GetDFileFlags(ud_row) & 
				(CUud32acxCtrl::uudFileError | CUud32acxCtrl::uudFileDecoded))
			continue;					// Already processed

		lfn = cpath + m_DecodeOut.GetItemText(row, 0);		// The output filename

		decoder->PostThreadMessage(ENG_DECODE, (WPARAM) ud_row, (LPARAM) strdup(lfn));	// Add the file to decode
	}

	m_DecodeOut.ModifyStyle(0, LVS_SHOWSELALWAYS);

	decoder->PostThreadMessage(ENG_DECLIST, 0, 0);	// Start decoding....

}


//
// Decode is done
//

void DecodeDlg::DecodeGoDone(int rc)
{

	HourGlass(false);

	m_DecodeOut.ModifyStyle(LVS_SHOWSELALWAYS, 0);

	if (rc < 0)
	{
		SetState(MS_GO, true);		// Force back to Go state
		Info1(IDS_CANCEL);
	}
	else								// Not cancelled, set to DONE, etc.
	{
		int r = m_DecodeOut.GetItemCount() - 1;

		m_DecodeOut.SetImage(r, 
			DecIcon(m_DecodeOut.GetItemData(r), NULL));	// Update the last icon

		SetState(MS_DONE);

		Info1("Done decoding.");

		if (rc != 0)
		{
			CString wrk;

			wrk.Format("%d errors found.", rc);

			Info2(wrk);
		}
		else
			Info2("No errors.");
	}

	if (SHOW_DEBUG)
		deBox.Ready();

}


//
// Called from top-level dialog to repaint during activation
//

void DecodeDlg::Activate()
{

	if (decoder != NULL && (decoder->State > Engine::ENG_IDLE))
	{
		CRect r;
		m_InfoBox.GetWindowRect(&r);
		ScreenToClient(&r);
		InvalidateRect(&r);
	}

}



//
// Figure out if UUDeview is currently associated with the decodable
//  extensions
//

bool DecodeDlg::IsAssociated()
{
	CString wrk;

	for (char **q=ext_list; *q != NULL; q++)
		if (!RegIni::GetAssoc(*q, wrk) || wrk != "UUD32")
			return(false);

return(true);
}


//
// Alter the associations
//

bool DecodeDlg::SetAssoc(int oldmode, int newmode)
{
	CString wrk;
	char **q;
	static char *dlgtitle = "UUDeview Associations";
	static char *uuredir = "UUD32";
	static char *backup = "Software\\MikeN\\Uud32\\assoc";		// Backup path

	if (oldmode == 2 && newmode == 1)		// Partial to full
	{
		if (MessageBox("Reset decodable file associations to UUDeview?",
				dlgtitle, MB_ICONQUESTION | MB_OKCANCEL) == IDCANCEL)
			return(false);

		for (q=ext_list; *q != NULL; q++)
			if (!RegIni::SetAssocRedir(*q, uuredir))		// Set the redirects
				return(false);
	}										// Partial to all
	else if (oldmode == 0 && newmode == 1)	// None to full
	{
		if (MessageBox("Set decodable file associations to UUDeview?",
				dlgtitle, MB_ICONQUESTION | MB_OKCANCEL) == IDCANCEL)
			return(false);

		for (q=ext_list; *q != NULL; q++)
		{
			RegIni::BackupKey(HKEY_CLASSES_ROOT, *q, 
				HKEY_CURRENT_USER, backup);

			if (!RegIni::SetAssocRedir(*q, uuredir))		// Set the redirects
				return(false);
		}

		CString test;
		HMODULE hm = GetModuleHandle("UUD32.EXE");

		if (hm != NULL)
		{
			GetModuleFileName(hm, test.GetBuffer(MAX_PATH+1), MAX_PATH);
			test.ReleaseBuffer();
		}

		if (!RegIni::SetAssocOpen(uuredir, test, "UUDeview File"))
		{
			MessageBox("Error creating association.", dlgtitle, 
				MB_ICONEXCLAMATION | MB_OK);
			return(false);
		}

	}								// None to all
	else if (newmode == 0)			// Remove
	{
		if (MessageBox("Restore original decodable file associations?",
				dlgtitle, MB_ICONQUESTION | MB_OKCANCEL) == IDCANCEL)
			return(false);

		for (q=ext_list; *q != NULL; q++)
		{
			wrk = backup;		// Create a path...
			wrk += '\\';
			wrk += *q;

			if (!RegIni::RestoreKey(
					HKEY_CURRENT_USER, wrk,
					HKEY_CLASSES_ROOT, *q))
				RegDeleteKey(HKEY_CLASSES_ROOT, *q);		// There was no original key
		}

		RegDeleteKey(HKEY_CLASSES_ROOT, uuredir);		// Blow away the association
		RegDeleteKey(HKEY_CURRENT_USER, backup);
	}

	MessageBox("File associations updated.", dlgtitle, 
		MB_ICONINFORMATION | MB_OK);

return(true);
}


//
// Make sure the engine thread is killed
//

void DecodeDlg::PostNcDestroy() 
{
	if (decoder != NULL && decoder->m_hThread != NULL && decoder->State != Engine::ENG_DYING)
	{
		decoder->PostThreadMessage(ENG_CANCEL, 0, 0);	// Make sure it stops
		decoder->PostThreadMessage(ENG_STOP, 0, 0);

		WaitForSingleObject(decoder->m_hThread, 5000);
	}
	
	CSizeDialog::PostNcDestroy();
}


//
// Set up the decoder engine
//

bool DecodeDlg::EngineSetup()
{

	if (decoder == NULL)
	{
		decoder = new Engine(this, UD_ID);

		if (decoder == NULL ||						// No allocation
			decoder->State != Engine::ENG_IDLE)		// Spin-up failed
		{
			ArgMessageBox("UUDeview Go", MB_ICONSTOP | MB_OK,
				"Could not create engine thread, error=%d",
				GetLastError());
			return(false);
		}
	}

	decoder->OWrite = (options[OPT_OWMODE] == OPT_OW_OW);
	decoder->ANumber = (options[OPT_OWMODE] == OPT_OW_AUTO);

	decoder->IFRecycle = (options[OPT_RECYCLE] != 0);

	if (options[OPT_TEMPS])
		decoder->SetTemp(tempFolder);
	else
		decoder->WinTemp();

return(true);
}



//
// Send file(s) to the user's editor
//

void DecodeDlg::DecodeEdit()
{
	LaunchDialog ld;

	int rmax = m_DecodeList.GetCount();

	if (rmax == 0)
		return;					// Nothing to do

	int scount = m_DecodeList.GetSelCount();	// Read number of selected items

	int *slist = (int *) _alloca(sizeof(int) * (scount + 1));	// Create the selection list
	int *eos = slist + scount;			// End

	m_DecodeList.GetSelItems(scount, slist);	// Read the selected items

	int *slp;			// Point into the item list

	CFileName here, appname;

	int rc;

	bool multi = false;
	
	if (options[OPT_ENOPROMPT] != 0 &&
		!editLast.IsEmpty())		// If "skip" is set and app is set, don't prompt
	{
		appname = editLast;
		multi = true;
	}

	for (slp=slist; slp < eos; slp++)
	{
		m_DecodeList.GetText(*slp, here.GetStr());	// Read a selected item's text

		if (!multi)			// Prompt for an app
		{
			switch (ld.GetEFN(here, (eos - slp) > 1, appname.GetStr(), 
				editList, &editDir, editLast, &options[OPT_ENOPROMPT]))
			{
				case IDCANCEL:		// Jump out
					return;

				case IDOK:		// This is what happens, not needed because of default
					multi = (options[OPT_ENOPROMPT] != 0);		// Only handle one unless Skip turned on
					break;

				case LDIAG_ALL:
					multi = true;		// Handle all
					break;
			}

			SetState(MS_PREVIEW);		// Unload any files
		}

		if ((rc = here.Exec(appname)) != 0 &&
			ArgMessageBox("Edit source files", MB_OKCANCEL | MB_ICONEXCLAMATION,
				"Error %d launching %s.\r\n\r\nContinue?", rc, (const char *) appname) != IDOK)
				break;

	}

}
