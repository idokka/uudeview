/*
 * This file is part of uudeview 32, a simple and friendly multi-part multi-
 * file uudecoder  program.
 *
 *	Copyright (c) 1997,1998 by:
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


// SizeDialog.cpp: implementation of the CSizeDialog class.
//
// Creates a dialog where all the controls can be moved and sized
//  automatically in response to changes in the parent dialog box's
//  size.  A table controls whether each control is moved, sized, or
//  both.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Uud32.h"
#include "SizeDialog.h"

//
// Stuff needed for modified context help
//

#define _AFX_NO_OLE_SUPPORT

#include "afxpriv.h"
#include "G:\Program Files\Microsoft Visual Studio\VC98\MFC\SRC\AFXIMPL.H"

#undef HELP_ACTIVE
#undef HELP_INACTIVE
#undef HELP_ENTERING

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//
// SizeDialog message map
//

BEGIN_MESSAGE_MAP(CSizeDialog, CDialog)
	//{{AFX_MSG_MAP(CSizeDialog)
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_DESTROY()
	ON_COMMAND(ID_CONTEXT_HELP, OnContextHelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSizeDialog::CSizeDialog() : CDialog()
{

	wSizep = NULL;
	iconID = 0;

	cdiv_x = 1;
	cdiv_y = 1;

	min_w = 0;
	min_h = 0;

	initlist = NULL;

	ctrList = NULL;

	enable_top = NULL;

}

CSizeDialog::CSizeDialog(struct DialogSizerInit *ilist, 
		UINT dlgID, CRect *rp, CWnd *parent, UINT icon, int mx, int my)
		: CDialog(dlgID, parent)
{

	wSizep = rp;
	iconID = icon;

	min_w = mx;
	min_h = my;

	initlist = ilist;

	ctrList = NULL;

	enable_top = NULL;

}

CSizeDialog::~CSizeDialog()
{

	if (ctrList != NULL)
		delete[] ctrList;

	struct SD_Enabled_s *c, *np;

	for (c=enable_top; c != NULL; c=np)
	{
		np = c->next;

		delete c;
	}

}


//
// Do the dialog setup
//

BOOL CSizeDialog::OnInitDialog()
{
	BOOL rc = CDialog::OnInitDialog();		// Do the parent setup

	tl_parent = GetTopLevelParent();

	if (tl_parent == GetDesktopWindow())
		tl_parent = NULL;

	if (iconID != 0)
	{
		HICON hi = AfxGetApp()->LoadIcon(IDI_INFOICON);

		ASSERT(hi != NULL);
		
		if (hi != NULL)
		{
			SetIcon(hi, TRUE);			// Set both icons
			SetIcon(hi, FALSE);
		}
	}

	Setup();		// Set up the Dialog Resizer

	if (wSizep != NULL && !wSizep->IsRectNull())
	{
		MoveWindow(*wSizep, FALSE);	// Move the window but don't repaint
		Adjust();
	}

	//
	// Context help setup
	//

	m_bHelpMode = HELP_INACTIVE;
	hArrow = hcurHelp = NULL;
	enable_top = NULL;

return(rc);
}


//
// Set up the dialog resizer
//

void CSizeDialog::Setup()
{
	struct DialogSizerInit *ip;

	if (ctrList != NULL)			// Make sure we don't reuse memory
		delete[] ctrList;

	CRect r;

	GetClientRect(&r);	// Store the window's reference size

	ref_height = r.Height();		// Read the original size (I know, top=left=0, but this makes me feel better)
	ref_width = r.Width();

	for (ip=initlist; ip->dlgID >= 0; ip++)
		;							// Count items

	count = ip - initlist;				// How many items?

	ctrList = new struct DialogSizerList[count + 1];	// Create the control list array

	ASSERT(ctrList != NULL);

	struct DialogSizerList *cp = ctrList;

	CWnd *wp;

	CRect ref_size;
	GetWindowRect(&ref_size);

	x_span_count = 0;				// Clear the span count

	for (ip=initlist; ip->dlgID >= 0; ip++, cp++)
	{
		cp->ii = *ip;				// Store initial information

		if (cp->ii.flags != DSZ_SET_D)
		{
			wp = GetDlgItem(ip->dlgID);

			ASSERT(wp != NULL);

			wp->GetWindowRect(&cp->ctrl_posn);	// Store the reference position

			ScreenToClient(&cp->ctrl_posn);	// Convert coordinates

			if (ip->flags == DSZ_SPANX)
				x_span_count++;			// Count x-spanned items
		}

	}
		
}


//
// Do the real work... Adjust!
//
// cdiv* are custom divisors for height and width
//

void CSizeDialog::Adjust()
{

	if (count == 0 || ctrList == NULL)
		return;							// Not set up yet

	CRect new_posn;

	GetClientRect(&new_posn);		// Read the window's new owner rectangle

	int dw = new_posn.Width() - ref_width;	// Change in width
	int dh = new_posn.Height() - ref_height;	// Change in height

	int xspan = 0;
	int xspan_step;

	if (x_span_count > 0)
		xspan_step = new_posn.Width() / x_span_count;

	struct DialogSizerList *cp = ctrList;

	CWnd *wp;
	CRect np;
	int flags;

	for (int cc=count; cc > 0; cc--, cp++)
	{
		flags = cp->ii.flags;				// Read the flags

		if (flags == DSZ_NONE)
			continue;						// Don't do anything

		np = cp->ctrl_posn;					// Copy the original rectangle

		if (flags == DSZ_SET_D)
		{
			cdiv_x = cp->ii.dlgID;				// Width divider
			cdiv_y = cp->ii.help_context;		// Height divider
			continue;
		}
		else if (flags == DSZ_SPANX)				// Spanning...
		{
			if (xspan == 0)
			{
				xspan = xspan_step;
				continue;					// Don't move the first one
			}

			int nw = (np.right - np.left) / 2;

			np.right = xspan + nw;
			np.left = xspan - nw;
			xspan += xspan_step;
		}
		else
		{
			//
			// X operations
			//

			if (flags & DSZ_MOVEX)
			{
				np.left += dw;
				np.right += dw;
			}

			if (flags & DSZ_MOVEX_D)
			{
				np.left += dw / cdiv_x;
				np.right += dw / cdiv_x;
			}

			//
			// Y operations
			//

			if (flags & DSZ_MOVEY)
			{
				np.top += dh;
				np.bottom += dh;
			}

			if (flags & DSZ_MOVEY_D)
			{
				np.top += dh / cdiv_y;
				np.bottom += dh / cdiv_y;
			}

			//
			// Height operations
			//

			if (flags & DSZ_SIZEH)
				np.bottom += dh;

			if (flags & DSZ_SIZEH_D)
				np.bottom += dh / cdiv_y;

			//
			// Width operations
			//

			if (flags & DSZ_SIZEW)
				np.right += dw;

			if (flags & DSZ_SIZEW_D)
				np.right += dw / cdiv_x;

			//
			// Center and align
			//

			if (flags & DSZ_CTRX)		// Center on another control
			{
				int ctr = posn_stack.left + posn_stack.Width() / 2;
				int w = np.Width() / 2;

				np.left = ctr - w;
				np.right = ctr + w;
			}

			if (flags & DSZ_RTX)		// Right-align on another control
			{
				int w = np.Width();

				np.right = posn_stack.right;
				np.left = posn_stack.right - w;
			}

			if (flags & DSZ_LFX)		// Left-align on another control
			{
				int w = np.Width();

				np.left = posn_stack.left;
				np.right = posn_stack.left + w;
			}

		}							// Not spanning

		wp = GetDlgItem(cp->ii.dlgID);		// Read the dialog item pointer

		ASSERT(wp != NULL);			// Trap failures here

		wp->MoveWindow(np, FALSE);		// Move but don't repaint

		if (flags & DSZ_STACK)
			posn_stack = np;		// Store the current control's position

	}

	RedrawWindow();				// Invalidate the whole window

}


void CSizeDialog::OnSize(UINT nType, int cx, int cy) 
{

	if (nType != SIZE_MINIMIZED)
		Adjust();

}


//
// Minimum size presenter
//
afx_msg void CSizeDialog::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI)
{

	ASSERT(lpMMI != NULL);

	if (min_h > 0 || min_w > 0)
	{
		lpMMI->ptMinTrackSize.x = min_w;
		lpMMI->ptMinTrackSize.y = min_h;
	}

}


//
// Get size before closing
//

void CSizeDialog::OnDestroy() 
{

	ASSERT(m_hWnd != NULL);

	if (wSizep != NULL)
		GetWindowRect(wSizep);		// Retrieve the window position

}


//
// Explicitly saves the current size
//

bool CSizeDialog::SaveSize(CRect *np)
{

	if (m_hWnd == NULL)
		return(false);

	if (np != NULL)
	{
		GetWindowRect(np);
		return(true);
	}
	else if (wSizep != NULL)
	{
		GetWindowRect(wSizep);
		return(true);
	}

return(false);
}


//
// On Notify handles tool tips
//

BOOL CSizeDialog::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	NMHDR *np = (LPNMHDR) lParam;

	if (np->code == TTN_NEEDTEXT)
	{
		TOOLTIPTEXT *tp = (LPTOOLTIPTEXT) lParam;
		struct DialogSizerList *cp = ctrList;
		int ctrlID = ::GetDlgCtrlID((HWND) tp->hdr.idFrom);

		for (int cc=count; cc > 0; cc--, cp++)
			if (cp->ii.dlgID == ctrlID)
			{
				tp->lpszText = (LPTSTR) cp->ii.tooltip;
				tp->hinst = AfxGetApp()->m_hInstance;
				return(TRUE);
			}
	}
	
return CDialog::OnNotify(wParam, lParam, pResult);
}


//
// My varargs implementation of messagebox
//

int CSizeDialog::ArgMessageBox(const char *label, UINT flags, const char *format, ...)
{
	va_list ap;
	char wrk[MAX_PATH + 256];

	va_start(ap, format);				// Point to first argument

#if defined(_DEBUG)
	int nc = vsprintf(wrk, format, ap);
	ASSERT(nc > 0 && nc < (MAX_PATH + 255));
#else
	vsprintf(wrk, format, ap);
#endif

	va_end(ap);

return(MessageBox(wrk, label, flags));
}


//
// Change the tool tip attached to a control
//

bool CSizeDialog::SetToolTip(int ctrlID, int tipString)
{
	struct DialogSizerList *cp = ctrList;

	for (int cc=count; cc > 0; cc--, cp++)
		if (cp->ii.dlgID == ctrlID)
		{
			cp->ii.tooltip = tipString;
			return(true);
		}

return(false);
}


//
// Dangerously entering into the world of context help
//
/////////////////////////////////////////////////////////////////////////////
// Context Help Mode support


//
// ---------------------------------------------
//

BOOL CSizeDialog::CanEnterHelpMode()
{
	ASSERT(m_bHelpMode != HELP_ACTIVE); // already in help mode?

	// unable to start help if the cursor cannot be loaded from the resources
	if (hcurHelp == NULL)
	{
		hcurHelp = AfxGetApp()->LoadCursor(IDC_MN_HELP);
	}

return(TRUE);
}

void CSizeDialog::OnContextHelp(/* DWORD *pContext */)
{
	TRACE("Enter Context Help\r\n");

	// don't enter twice, and don't enter if initialization fails
	if (m_bHelpMode == HELP_ACTIVE || !CanEnterHelpMode())
		return;

	// don't enter help mode with pending WM_EXITHELPMODE message
	MSG msg;
	if (PeekMessage(&msg, m_hWnd, WM_EXITHELPMODE, WM_EXITHELPMODE,
		PM_REMOVE|PM_NOYIELD))
	{
		return;
	}

	BOOL bHelpMode = m_bHelpMode;
	ASSERT(m_bHelpMode == HELP_INACTIVE || m_bHelpMode == HELP_ENTERING);
	m_bHelpMode = HELP_ACTIVE;

#ifndef _AFX_NO_OLE_SUPPORT
	// allow any in-place active servers to go into help mode
	if (bHelpMode != HELP_ENTERING && m_pNotifyHook != NULL &&
		!m_pNotifyHook->OnContextHelp(TRUE))
	{
		TRACE0("Error: an in-place server failed to enter context help mode.\n");
		m_pNotifyHook->OnContextHelp(FALSE);    // undo partial help mode
		m_bHelpMode = HELP_INACTIVE;
		return;
	}
#endif

	if (bHelpMode == HELP_INACTIVE)
	{
		// need to delay help startup until later
		PostMessage(WM_COMMAND, ID_CONTEXT_HELP);
		m_bHelpMode = HELP_ENTERING;
		return;
	}

	ASSERT(m_bHelpMode == HELP_ACTIVE);

	StackEnabled();

	DWORD   dwContext = 0;
	POINT   point;

	GetCursorPos(&point);
	SetHelpCapture(point, NULL);
	LONG lIdleCount = 0;
	CWinApp* pApp = AfxGetApp();

	while (m_bHelpMode)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (!ProcessHelpMsg(msg, &dwContext))
				break;
			ASSERT(dwContext == 0);
		}
		else if (!pApp->OnIdle(lIdleCount++))
		{
			lIdleCount = 0;
			WaitMessage();
		}
	}

	m_bHelpMode = HELP_INACTIVE;
	ReleaseCapture();

	// make sure the cursor is set appropriately
	SetCapture();
	ReleaseCapture();

	UnStackEnabled();

#ifndef _AFX_NO_OLE_SUPPORT
	// tell in-place servers to exit Shift+F1 help mode
	if (m_pNotifyHook != NULL)
		m_pNotifyHook->OnContextHelp(FALSE);
#endif

	if (dwContext == 0)
		pApp->WinHelp(0, HELP_CONTENTS);
	else if (dwContext != -1)
	{
		struct DialogSizerList *cp = ctrList;
		int ctrlID = ::GetDlgCtrlID((HWND) dwContext);
		int hc = 0;

		for (int cc=count; cc > 0; cc--, cp++)
			if (cp->ii.dlgID == ctrlID)
			{
				hc = cp->ii.help_context;
				break;
			}

		if (hc == 0)
			pApp->WinHelp(0, HELP_CONTENTS);
		else
			pApp->WinHelp(cp->ii.help_context, HELP_CONTEXT);
	}

	PostMessage(WM_KICKIDLE);    // trigger idle update
}

/////////////////////////////////////////////////////////////////////////////
// OnContextHelp helpers.

HWND CSizeDialog::SetHelpCapture(POINT point, BOOL* pbDescendant)
	// set or release capture, depending on where the mouse is
	// also assign the proper cursor to be displayed.
{
	if (!m_bHelpMode)
		return NULL;

	HWND hWndCapture = ::GetCapture();
	CWnd* pWndHit = WindowFromPoint(point);
	HWND hWndHit = pWndHit->GetSafeHwnd();
	CWnd* pTopHit = pWndHit->GetTopLevelParent();
	CWnd* pTopActive = GetActiveWindow()->GetTopLevelParent();
	BOOL bDescendant = FALSE;
	HTASK hCurTask = (HTASK)GetCurrentThreadId();
	HTASK hTaskHit = hWndHit != NULL ? ::GetWindowTask(hWndHit) : NULL;

	if (pTopActive == NULL || hWndHit == ::GetDesktopWindow())
	{
		if (hWndCapture == m_hWnd)
			ReleaseCapture();
		if (hArrow == NULL)
			hArrow = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		SetCursor(hArrow);
	}
	else if (pTopActive == NULL ||
		hWndHit == NULL || hCurTask != hTaskHit ||
		!AfxIsDescendant(m_hWnd, hWndHit))
	{
		if (hCurTask != hTaskHit)
			hWndHit = NULL;
		if (hWndCapture == m_hWnd)
			ReleaseCapture();
	}
	else
	{
		bDescendant = TRUE;
		if (pTopActive != pTopHit)
			hWndHit = NULL;
		else
		{
			if (hWndCapture != m_hWnd)
				::SetCapture(m_hWnd);
			SetCursor(hcurHelp);
		}
	}
	if (pbDescendant != NULL)
		*pbDescendant = bDescendant;
	return hWndHit;
}


static DWORD AFXAPI MapNonClientArea(int iHit)
{
	ASSERT(iHit != HTCLIENT);

	if (iHit < 0 || iHit > HTBORDER)
		return (DWORD)-1;

	return HID_BASE_NCAREAS+iHit;
}

BOOL CSizeDialog::ProcessHelpMsg(MSG& msg, DWORD* pContext)
{
	ASSERT(pContext != NULL);

	if (msg.message == WM_EXITHELPMODE ||
		(msg.message == WM_KEYDOWN && msg.wParam == VK_ESCAPE))
	{
		*pContext = -1;
		PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);
		return FALSE;
	}

	CPoint point;
	if ((msg.message >= WM_MOUSEFIRST && msg.message <= WM_MOUSELAST) ||
		(msg.message >= WM_NCMOUSEFIRST && msg.message <= WM_NCMOUSELAST))
	{
		BOOL bDescendant;
		HWND hWndHit = SetHelpCapture(msg.pt, &bDescendant);
		if (hWndHit == NULL)
			return TRUE;

		if (bDescendant)
		{
			if (msg.message != WM_LBUTTONDOWN)
			{
				// Hit one of our owned windows -- eat the message.
				PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);
				return TRUE;
			}
			int iHit = (int)::SendMessage(hWndHit, WM_NCHITTEST, 0,
				MAKELONG(msg.pt.x, msg.pt.y));
			if (iHit == HTMENU || iHit == HTSYSMENU)
			{
				ASSERT(::GetCapture() == m_hWnd);
				ReleaseCapture();
				// the message we peeked changes into a non-client because
				// of the release capture.
				GetMessage(&msg, NULL, WM_NCLBUTTONDOWN, WM_NCLBUTTONDOWN);
				DispatchMessage(&msg);
				GetCursorPos(&point);
				SetHelpCapture(point, NULL);
			}
			else if (iHit == HTCLIENT)
			{
				*pContext = (DWORD) hWndHit;
				PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);
				return FALSE;
			}
			else
			{
				*pContext = 0;
				PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);
				return FALSE;
			}
		}
		else
		{
			// Hit one of our apps windows (or desktop) -- dispatch the message.
			PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE);

			// Dispatch mouse messages that hit the desktop!
			DispatchMessage(&msg);
		}
	}
	else if (msg.message == WM_SYSCOMMAND ||
			 (msg.message >= WM_KEYFIRST && msg.message <= WM_KEYLAST))
	{
		if (::GetCapture() != NULL)
		{
			ReleaseCapture();
			MSG msg;
			while (PeekMessage(&msg, NULL, WM_MOUSEFIRST,
				WM_MOUSELAST, PM_REMOVE|PM_NOYIELD));
		}
		if (PeekMessage(&msg, NULL, msg.message, msg.message, PM_NOREMOVE))
		{
			GetMessage(&msg, NULL, msg.message, msg.message);
			if (!PreTranslateMessage(&msg))
			{
				TranslateMessage(&msg);
				if (msg.message == WM_SYSCOMMAND ||
				  (msg.message >= WM_SYSKEYFIRST &&
					msg.message <= WM_SYSKEYLAST))
				{
					// only dispatch system keys and system commands
					ASSERT(msg.message == WM_SYSCOMMAND ||
						 (msg.message >= WM_SYSKEYFIRST &&
						  msg.message <= WM_SYSKEYLAST));
					DispatchMessage(&msg);
				}
			}
		}
		GetCursorPos(&point);
		SetHelpCapture(point, NULL);
	}
	else
	{
		// allow all other messages to go through (capture still set)
		if (PeekMessage(&msg, NULL, msg.message, msg.message, PM_REMOVE))
			DispatchMessage(&msg);
	}

	return TRUE;
}


//
// Turning controls on for Context Help
//

void CSizeDialog::StackEnabled()
{
	struct SD_Enabled_s *np;

	if (enable_top != NULL)
		return;							// Already stacked

	struct DialogSizerList *cp = ctrList;
	CWnd *ctrlp;

	for (int cc=count; cc > 0; cc--, cp++)
		if (!(cp->ii.flags & DSZ_NOCTRL))
		{
			ctrlp = GetDlgItem(cp->ii.dlgID);

			if (ctrlp != NULL && !ctrlp->IsWindowEnabled())
			{
				ctrlp->EnableWindow(TRUE);

				np = new struct SD_Enabled_s;

				np->ctrlID = cp->ii.dlgID;
				np->next = enable_top;
				enable_top = np;
			}
		}

}


//
// Restore the status of any controls on the stack
//

void CSizeDialog::UnStackEnabled(BOOL oldsta)
{
	if (enable_top == NULL)
		return;							// Nothing stacked

	struct SD_Enabled_s *c, *np;
	CWnd *ctrlp;

	for (c=enable_top; c != NULL; c=np)
	{
		np = c->next;

		ctrlp = GetDlgItem(c->ctrlID);

		if (ctrlp != NULL)
			ctrlp->EnableWindow(oldsta);		// Set the control back to its original status

		delete c;
	}

	enable_top = NULL;

}



//
// PushExcept sets the status of all listed controls EXCEPT
//  those on the parameter list
//

void CSizeDialog::EnablePushExcept(BOOL newsta, ...)
{

	va_list ap, top;

	va_start(top, newsta);

	struct SD_Enabled_s *np;
	struct DialogSizerList *cp = ctrList;
	CWnd *ctrlp;
	int id, tid;

	for (int cc=count; cc > 0; cc--, cp++)
		if (!(cp->ii.flags & DSZ_NOCTRL))
		{
			tid = cp->ii.dlgID;
			ap = top;
			do {
				id = va_arg(ap, int);
			} while (id != tid && id != 0);

			if (id != 0)
				continue;				// No match

			ctrlp = GetDlgItem(tid);

			if (ctrlp != NULL && ctrlp->IsWindowEnabled() != newsta)
			{
				ctrlp->EnableWindow(newsta);

				np = new struct SD_Enabled_s;

				np->ctrlID = cp->ii.dlgID;
				np->next = enable_top;
				enable_top = np;
			}
		}

	va_end(ap);

}
