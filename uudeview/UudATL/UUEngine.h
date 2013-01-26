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

// UUEngine.h : Declaration of the CUUEngine

#ifndef __UUENGINE_H_
#define __UUENGINE_H_

#include "resource.h"       // main symbols
#include "UudEng.h"
#include "mstring.h"
#include "UudATLCP.h"

/////////////////////////////////////////////////////////////////////////////
// CUUEngine
class ATL_NO_VTABLE CUUEngine : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUUEngine, &CLSID_UUEngine>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CUUEngine>,
	public IDispatchImpl<IUUEngine, &IID_IUUEngine, &LIBID_UUDATLLib>,
	public CProxy_IUUEngineEvents< CUUEngine >
{
public:
	CUUEngine();
	~CUUEngine();

DECLARE_REGISTRY_RESOURCEID(IDR_UUENGINE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CUUEngine)
	COM_INTERFACE_ENTRY(IUUEngine)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CUUEngine)
CONNECTION_POINT_ENTRY(DIID__IUUEngineEvents)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IUUEngine
public:
	STDMETHOD(get_StrictFilenames)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_StrictFilenames)(/*[in]*/ BOOL newVal);
	STDMETHOD(LoadBuffer)(VARIANT buffer, VARIANT *tempName, BOOL *retVal);
	STDMETHOD(CreateTempName)(BSTR *tempFilename);
	STDMETHOD(get_XFileCount)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_XFileCount)(/*[in]*/ short newVal);
	STDMETHOD(get_XFile)(short row, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_XFile)(short row, /*[in]*/ BSTR newVal);
	STDMETHOD(get_DFileDetail)(short row, short itemno, short subscr, /*[out, retval]*/ VARIANT *pVal);
	STDMETHOD(put_DFileDetail)(short row, short itemno, short subscr, /*[in]*/ VARIANT newVal);
	STDMETHOD(ClipboardFile)(long hWnd, BSTR Filename, short CFMode, BOOL *retVal);
	STDMETHOD(CRC32)(BSTR fileName, long *crc, BOOL *retVal);
	STDMETHOD(LastOSError)(long *errNo, VARIANT *errText, BOOL *gotErr);
	STDMETHOD(get_TempFolder)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_TempFolder)(/*[in]*/ BSTR newVal);
	STDMETHOD(XFileDel)(BOOL *retVal);
	STDMETHOD(XFileAdd)(BSTR toAdd, BOOL *retVal);
	STDMETHOD(Encode)(BSTR iname, BSTR oname, BSTR nameinfile, long encoding, long lines, long headers, VARIANT destvar, VARIANT fromvar, VARIANT subjectvar, long *retVal);
	STDMETHOD(DRemove)(short row);
	STDMETHOD(get_DFileInfo)(short row, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DFileInfo)(short row, /*[in]*/ BSTR newVal);
	STDMETHOD(Reset)();
	STDMETHOD(QuickDecode)(BSTR File2Decode, BSTR OutputPath, BOOL XFile, long *retVal);
	STDMETHOD(FileFilter)(BSTR inFile, BSTR *outFile);
	STDMETHOD(get_DFileStatus)(short row, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DFileStatus)(short row, /*[in]*/ BSTR newVal);
	STDMETHOD(get_LastMessage)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_LastMessage)(/*[in]*/ BSTR newVal);
	STDMETHOD(DFileTo)(short row, BSTR outname, long *retVal);
	STDMETHOD(DLoad)(BSTR toLoad, long *retVal);
	STDMETHOD(get_DFileFlags)(short row, /*[out, retval]*/ long *pVal);
	STDMETHOD(put_DFileFlags)(short row, /*[in]*/ long newVal);
	STDMETHOD(get_DFCount)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_DFCount)(/*[in]*/ short newVal);
	STDMETHOD(get_DFile)(short row, /*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DFile)(short row, /*[in]*/ BSTR newVal);
	STDMETHOD(get_LibVersion)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_LibVersion)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_OutputPath)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_OutputPath)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_XFileAuto)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_XFileAuto)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_Verbose)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_Verbose)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_UseText)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_UseText)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_StrictMIME)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_StrictMIME)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_RemoveAfter)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_RemoveAfter)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_Overwrite)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_Overwrite)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_IgnoreReply)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_IgnoreReply)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_FastMode)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_FastMode)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_Dumb)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_Dumb)(/*[in]*/ BOOL newVal);
	STDMETHOD(get_Desperate)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Desperate)(/*[in]*/ short newVal);
	STDMETHOD(get_BracketPolicy)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_BracketPolicy)(/*[in]*/ BOOL newVal);

protected:
	void MessageHandler(const char *message, int level);
	void NewStep();
	UudEng ue;

	inline BOOL GetBoolProp(int option)		// Read a BOOL property from the engine
	{
		int iVal;

		ue.UUGetOption(option, &iVal, NULL, 0);

		return(iVal != 0);
	}

	inline int SetBoolProp(int option, BOOL val)	// Set a BOOL property to the engine
	{	return(ue.UUSetOption(option, val, NULL)); 	}

	MString LastMessage;

	bool OWriteOK;		// OK to overwrite
	bool XF_AutoDel;		// Delete X Files automatically

	class XFL
	{
	public:
		XFL()
		{
			next = NULL;
		}

		XFL(const BSTR src)
		{
			fName = src;

			next = NULL;
		}

		CComBSTR fName;

		XFL *next;

		void AddTail(const BSTR newItem)
		{
			XFL *ip = this;

			while (ip->next != NULL)
				ip = ip->next;

			ip->next = new XFL(newItem);
		}

	} *XFList;

};

#endif //__UUENGINE_H_
