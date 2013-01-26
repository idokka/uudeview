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


// DecodeOptions.cpp : implementation file for Decode Options
//

#include "stdafx.h"
#include "Uud32.h"
#include "DecodeOptions.h"

#include "hlp\decopt.hh"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DecodeOptions dialog


DecodeOptions::DecodeOptions(CWnd* pParent /*=NULL*/)
	: CDialog(DecodeOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(DecodeOptions)
	m_BrackPol = FALSE;
	m_Debug = FALSE;
	m_DumbMode = FALSE;
	m_EText = FALSE;
	m_FastMode = FALSE;
	m_IgnReply = FALSE;
	m_POE = FALSE;
	m_Desperate = FALSE;
	m_Assoc = FALSE;
	m_HideTips = FALSE;
	m_OutputFileMode = -1;
	m_RecycleInput = FALSE;
	m_StrictMime = FALSE;
	m_PreserveCase = FALSE;
	m_LNoPrompt = FALSE;
	m_ENoPrompt = FALSE;
	m_TempFolder = _T("");
	m_WinTemp = -1;
	m_DNoPrompt = FALSE;
	m_StrictFilenames = FALSE;
	//}}AFX_DATA_INIT
}


void DecodeOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DecodeOptions)
	DDX_Control(pDX, IDC_TEMPFOLDER, m_TempFolderControl);
	DDX_Control(pDX, IDC_BROWSETEMP, m_BrowseTemp);
	DDX_Control(pDX, IDC_ASSOC, m_AssocButton);
	DDX_Check(pDX, IDC_BRACKPOL, m_BrackPol);
	DDX_Check(pDX, IDC_DEBUG, m_Debug);
	DDX_Check(pDX, IDC_DUMBMODE, m_DumbMode);
	DDX_Check(pDX, IDC_ETEXT, m_EText);
	DDX_Check(pDX, IDC_FASTMODE, m_FastMode);
	DDX_Check(pDX, IDC_IGNREPLY, m_IgnReply);
	DDX_Check(pDX, IDC_POE, m_POE);
	DDX_Check(pDX, IDC_DESP, m_Desperate);
	DDX_Check(pDX, IDC_ASSOC, m_Assoc);
	DDX_Check(pDX, IDC_HIDETOOLTIPS, m_HideTips);
	DDX_Radio(pDX, IDC_OUTFMODEP, m_OutputFileMode);
	DDX_Check(pDX, IDC_RECYCLEINP, m_RecycleInput);
	DDX_Check(pDX, IDC_STRICT, m_StrictMime);
	DDX_Check(pDX, IDC_PRESERVECASE, m_PreserveCase);
	DDX_Check(pDX, IDC_LNOPROMPT, m_LNoPrompt);
	DDX_Check(pDX, IDC_ENOPROMPT, m_ENoPrompt);
	DDX_Text(pDX, IDC_TEMPFOLDER, m_TempFolder);
	DDX_Radio(pDX, IDC_WINTEMP, m_WinTemp);
	DDX_Check(pDX, IDC_DNOPROMPT, m_DNoPrompt);
	DDX_Check(pDX, IDC_STRICTFILENAMES, m_StrictFilenames);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DecodeOptions, CDialog)
	//{{AFX_MSG_MAP(DecodeOptions)
	ON_BN_CLICKED(IDC_DECOPTDEFAULT, OnDecoptDefault)
	ON_BN_CLICKED(IDC_ASSOC, OnAssoc)
	ON_BN_CLICKED(IDC_DECOPTHELP, OnDecOptHelp)
	ON_BN_CLICKED(IDC_RECYCLEINP, OnRecycleInp)
	ON_BN_CLICKED(IDC_OUTFMODEO, OnOutFModeOWrite)
	ON_BN_CLICKED(IDC_ENOPROMPT, OnEditNoPrompt)
	ON_BN_CLICKED(IDC_LNOPROMPT, OnLaunchNoPrompt)
	ON_BN_CLICKED(IDC_OTHERTEMP, OnOtherTemp)
	ON_BN_CLICKED(IDC_WINTEMP, OnWinTemp)
	ON_BN_CLICKED(IDC_BROWSETEMP, OnBrowseTemp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DecodeOptions message handlers

void DecodeOptions::OnDecoptDefault() 
{

	m_BrackPol = FALSE;
	m_Debug = FALSE;
	m_DumbMode = FALSE;
	m_EText = FALSE;
	m_FastMode = FALSE;
	m_IgnReply = FALSE;
	m_POE = FALSE;
	m_Desperate = FALSE;
	m_HideTips = FALSE;
	m_OutputFileMode = 0;
	m_RecycleInput = FALSE;
	m_StrictMime = FALSE;
	m_PreserveCase = FALSE;
	m_LNoPrompt = FALSE;
	m_ENoPrompt = FALSE;
	m_DNoPrompt = FALSE;
	m_WinTemp = 0;				// Temporary file mode is 0
	m_StrictFilenames = FALSE;

	UpdateData(FALSE);

	OnWinTemp();
	
}



//
// Prevent selecting the tri-state mode..
//

void DecodeOptions::OnAssoc() 
{

	if (m_AssocButton.GetCheck() == 2)
		m_AssocButton.SetCheck(0);
	
}


//
// Trip the Options help
//

void DecodeOptions::OnDecOptHelp() 
{

	AfxGetApp()->WinHelp(Decoding_Options, HELP_CONTEXT);
	
}



//
// Warn about Recycle option
//

void DecodeOptions::OnRecycleInp() 
{

	ProtectedCheck(IDC_RECYCLEINP, 
		"If you select this option, UUDeview will send\r\n"
		"all files from which it retrieves data during\r\n"
		"a decode operation to the Recycle Bin at the end\r\n"
		"of the operation.", 
		"Recycle input files");
	
}



//
// Warn about Overwrite mode
//

void DecodeOptions::OnOutFModeOWrite() 
{

	if (MessageBox("If you select this option, UUDeview will\r\n"
			"write output files to disk even if they\r\n"
			"replace existing files.", 
		"Output overwrite mode", MB_ICONEXCLAMATION | MB_OKCANCEL) != IDOK)
	{
		GetDlgItem(IDC_OUTFMODEO)->SendMessage(BM_SETCHECK, BST_UNCHECKED);
		GetDlgItem(IDC_OUTFMODEP)->SendMessage(BM_SETCHECK, BST_CHECKED);
	}
	
}



//
// Show a prompt before allowing a box to be checked
//

void DecodeOptions::ProtectedCheck(UINT ctlID, const char *prompt, const char *title)
{
	CButton *ctl = (CButton *) GetDlgItem(ctlID);

	ASSERT(ctl != NULL);

	if (ctl->GetCheck() &&
		MessageBox(prompt, 
			title, MB_ICONEXCLAMATION | MB_OKCANCEL) != IDOK)
		ctl->SetCheck(FALSE);

}



//
// Edit without prompting
//

void DecodeOptions::OnEditNoPrompt() 
{

	ProtectedCheck(IDC_ENOPROMPT, 
		"If you select this option, UUDeview will start\r\n"
		"the text editor for decode input files\r\n"
		"without prompting you for the editor you\r\n"
		"wish to use.", 
		"Edit input files");	
}



//
// Launch without prompting
//

void DecodeOptions::OnLaunchNoPrompt() 
{

	ProtectedCheck(IDC_LNOPROMPT, 
		"If you select this option, UUDeview will launch\r\n"
		"the application that Windows associates with files\r\n"
		"in the decode input and decode output windows\r\n"
		"without prompting you for the application you\r\n"
		"wish to use.", 
		"Launch decode files");	
	
}



//
// User wants some other temporary folder
//

void DecodeOptions::OnOtherTemp() 
{

	m_BrowseTemp.EnableWindow();

	m_TempFolderControl.EnableWindow();

	if (!nonWTemp.IsEmpty())
		m_TempFolderControl.SetWindowText(nonWTemp);

}


//
// User wants Windows temporary folder
//

void DecodeOptions::OnWinTemp() 
{
	
	m_BrowseTemp.EnableWindow(FALSE);

	m_TempFolderControl.EnableWindow(FALSE);

	char tFolder[MAX_PATH];

	GetTempPath(sizeof(tFolder) - 1, tFolder);

	m_TempFolderControl.SetWindowText(tFolder);

}



//
// Browse for temporary folder
//

void DecodeOptions::OnBrowseTemp() 
{
	CString tName;

	if (BrowseForDir(tName, "Select Temporary Directory", this))
		m_TempFolderControl.SetWindowText(tName);

}



//
// Set up the annoying temp stuff
//

BOOL DecodeOptions::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_WinTemp)
		OnOtherTemp();
	else
		OnWinTemp();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
