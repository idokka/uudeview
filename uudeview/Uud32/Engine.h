#if !defined(AFX_ENGINE_H__379F9E21_FC82_11D0_8988_444553540000__INCLUDED_)
#define AFX_ENGINE_H__379F9E21_FC82_11D0_8988_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

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


// Engine.h : header file
//

#include "filename.h"
#include "uud32acxctl.h"
#include <afxmt.h>

//
// My messages
//
#define ENG_STOP	(WM_APP + 0)		// Shut down thread
#define ENG_CANCEL	(WM_APP + 1)		// Stop what you're doing
#define ENG_LOAD	(WM_APP + 3)		// Start the decoder (scan mode)
										//  on the list added with ENG_DECODE
#define ENG_NEWSTEP	(WM_APP + 3)		// Starting new step
// #define ENG_INFOCHG	(WM_APP + 4)		// Info has changed
// #define ENG_PERCENT	(WM_APP + 5)		// Percent done
#define ENG_DONE	(WM_APP + 6)		// The engine thread is done doing something
#define ENG_DECODE	(WM_APP + 7)		// Send a file to decode
#define ENG_ROWCHG	(WM_APP + 8)		// Row has changed
#define ENG_CLEAR	(WM_APP + 9)		// Clear the Decode list
#define ENG_LAUNCH	(WM_APP + 10)		// Launch a file
#define ENG_DLAUNCH	(WM_APP + 11)		// Decode and launch a file
#define ENG_DECLIST	(WM_APP + 12)		// Decode the list of files
										//  added with ENG_DECODE
#define ENG_UPDICO	(WM_APP + 13)		// Update icon for an item (decode output)
#define ENG_UPDNAME	(WM_APP + 14)		// Update the name of an item (decode output)
#define ENG_ENCODE	(WM_APP + 15)		// Encode a file
#define ENG_INFOPAINT (WM_APP + 16)		// Used by engine apps to handle activate conditions
#define ENG_MESSAGE (WM_APP + 17)		// Message from engine to debug box
#define ENG_PROGRESS (WM_APP + 18)		// Progress message from Engine
#define ENG_SETAUTO (WM_APP + 19)		// Set AutoNumber mode in owner
#define ENG_RENAME	(WM_APP + 20)		// Prompt for rename operation
#define ENG_RENRES	(WM_APP + 21)		// Rename result

#define ENG_FIRST	ENG_STOP			// First message in use
#define ENG_LAST	ENG_RENRES			// Last message in use

//
// Some control IDs
//
#define UD_ID		0x1001
#define UD_EID		0x1002


/////////////////////////////////////////////////////////////////////////////
// Engine thread

class Engine : public CWinThread
{

// Attributes
public:
	CUud32acxCtrl UD;
	Engine();
	Engine(CWnd *owner, UINT ctrl_id);
	~Engine();

// Operations
public:
	void WinTemp();
	void SetTemp(CString& newTFolder);
	bool OWrite;			// Overwrite output files
	bool ANumber;			// Autonumber output files
	bool IFRecycle;			// Input file recycle

	bool GetMessage(CString &s);
	int SetMessage(char *format, ...);
//	bool SetParent(CWnd *owner, UINT id);
	bool StopMessage();		// Test to see if a Stop or Cancel is in the queue

	volatile enum EngineState 
	{
		ENG_UNINIT,
		ENG_IDLE,
		ENG_READING,
		ENG_DECODING,
		ENG_ENCODING,
		ENG_DYING
	} State;

	struct EngineLaunch				// Used with ENG_LAUNCH and ENG_DLAUNCH
	{
		CString app;				// Application
		CFileName filen;			// File to launch
		int row;
	};

	struct EngineEncode
	{
		CString inFileName;
		CString outFileName;
		CString nameInFile;
		long encodeMode;
		long linesPerFile;
	};

	struct EngineRename
	{
		CString path;
		CString nameOnly;
		CUud32acxCtrl *UD;
	};

	bool POE;						// Pause on errors...

private:
	void ClearVars();
	bool cancelFlag;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Engine)
	public:
	virtual BOOL InitInstance();
//	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	int RenamePrompt(CString *path, CString& lfn);
	void DoRecycle();
//	virtual ~Engine();

	char messagebuffer[MAX_PATH + 80];

	CMutex *msg_lock, *queue_lock;

	struct decode_queue_s {
		const char *fname;
		int row;
		struct decode_queue_s *next;
		} *d_top, *d_next;

	CWnd *owner;

	// Generated message map functions
	//{{AFX_MSG(Engine)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	afx_msg LONG OnLoad(UINT wParam, LONG lParam);
	afx_msg LONG OnStop(UINT wParam, LONG lParam);
	afx_msg LONG OnDecode(UINT row, LONG fname);
	afx_msg LONG OnCancel(UINT wParam, LONG lParam);
	afx_msg LONG OnClear(UINT wParam, LONG lParam);
	afx_msg LONG OnLaunch(UINT wParam, LONG elsp);
	afx_msg LONG OnDLaunch(UINT wParam, LONG elsp);
	afx_msg LONG OnDecList(UINT wParam, LONG lParam);
	afx_msg LONG OnEncode(UINT wParam, LONG encsp);
	afx_msg LONG MsgSink(UINT wParam, LONG lParam);

	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENGINE_H__379F9E21_FC82_11D0_8988_444553540000__INCLUDED_)
