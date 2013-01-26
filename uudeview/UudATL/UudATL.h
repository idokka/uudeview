
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Sat Jun 15 18:27:24 2002
 */
/* Compiler settings for H:\My Documents\Utilities\Vc\UudATL\UudATL.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __UudATL_h__
#define __UudATL_h__

/* Forward Declarations */ 

#ifndef __IUUEngine_FWD_DEFINED__
#define __IUUEngine_FWD_DEFINED__
typedef interface IUUEngine IUUEngine;
#endif 	/* __IUUEngine_FWD_DEFINED__ */


#ifndef ___IUUEngineEvents_FWD_DEFINED__
#define ___IUUEngineEvents_FWD_DEFINED__
typedef interface _IUUEngineEvents _IUUEngineEvents;
#endif 	/* ___IUUEngineEvents_FWD_DEFINED__ */


#ifndef __UUEngine_FWD_DEFINED__
#define __UUEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class UUEngine UUEngine;
#else
typedef struct UUEngine UUEngine;
#endif /* __cplusplus */

#endif 	/* __UUEngine_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IUUEngine_INTERFACE_DEFINED__
#define __IUUEngine_INTERFACE_DEFINED__

/* interface IUUEngine */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IUUEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60100074-531F-4D3A-A2B1-3941BE5828B0")
    IUUEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_BracketPolicy( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_BracketPolicy( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Desperate( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Desperate( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dumb( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Dumb( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_FastMode( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_FastMode( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_IgnoreReply( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_IgnoreReply( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Overwrite( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Overwrite( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoveAfter( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoveAfter( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_StrictMIME( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_StrictMIME( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_UseText( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_UseText( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_Verbose( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_Verbose( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_XFileAuto( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_XFileAuto( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_OutputPath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_OutputPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_LibVersion( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_LibVersion( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFile( 
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DFile( 
            /* [in] */ short row,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFCount( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DFCount( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFileFlags( 
            /* [in] */ short row,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DFileFlags( 
            /* [in] */ short row,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE DLoad( 
            /* [in] */ BSTR toLoad,
            /* [retval][out] */ long __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE DFileTo( 
            /* [in] */ short row,
            /* [in] */ BSTR outname,
            /* [retval][out] */ long __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_LastMessage( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_LastMessage( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFileStatus( 
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DFileStatus( 
            /* [in] */ short row,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE FileFilter( 
            /* [in] */ BSTR inFile,
            /* [retval][out] */ BSTR __RPC_FAR *outFile) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE QuickDecode( 
            /* [in] */ BSTR File2Decode,
            /* [in] */ BSTR OutputPath,
            /* [in] */ BOOL XFile,
            /* [retval][out] */ long __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFileInfo( 
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_DFileInfo( 
            /* [in] */ short row,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE DRemove( 
            short row) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE Encode( 
            /* [in] */ BSTR iname,
            /* [in] */ BSTR oname,
            /* [in] */ BSTR nameinfile,
            /* [in] */ long encoding,
            /* [in] */ long lines,
            /* [in] */ long headers,
            /* [in] */ VARIANT destvar,
            /* [in] */ VARIANT fromvar,
            /* [in] */ VARIANT subjectvar,
            /* [retval][out] */ long __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE XFileAdd( 
            /* [in] */ BSTR toAdd,
            /* [retval][out] */ BOOL __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE XFileDel( 
            /* [retval][out] */ BOOL __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TempFolder( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TempFolder( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LastOSError( 
            /* [out] */ long __RPC_FAR *errNo,
            /* [out] */ VARIANT __RPC_FAR *errText,
            /* [retval][out] */ BOOL __RPC_FAR *gotErr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CRC32( 
            /* [in] */ BSTR fileName,
            /* [out] */ long __RPC_FAR *crc,
            /* [retval][out] */ BOOL __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClipboardFile( 
            /* [in] */ long hWnd,
            /* [in] */ BSTR Filename,
            /* [in] */ short CFMode,
            /* [retval][out] */ BOOL __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_DFileDetail( 
            short row,
            short itemno,
            short subscr,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DFileDetail( 
            short row,
            short itemno,
            short subscr,
            /* [in] */ VARIANT newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_XFile( 
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_XFile( 
            /* [in] */ short row,
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE get_XFileCount( 
            /* [retval][out] */ short __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE put_XFileCount( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateTempName( 
            /* [retval][out] */ BSTR __RPC_FAR *tempFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadBuffer( 
            /* [in] */ VARIANT buffer,
            /* [out] */ VARIANT __RPC_FAR *tempName,
            /* [retval][out] */ BOOL __RPC_FAR *retVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StrictFilenames( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StrictFilenames( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUUEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IUUEngine __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IUUEngine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IUUEngine __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BracketPolicy )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BracketPolicy )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Desperate )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Desperate )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Dumb )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Dumb )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FastMode )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FastMode )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IgnoreReply )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IgnoreReply )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Overwrite )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Overwrite )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RemoveAfter )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RemoveAfter )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StrictMIME )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StrictMIME )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_UseText )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_UseText )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Verbose )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Verbose )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_XFileAuto )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_XFileAuto )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OutputPath )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OutputPath )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LibVersion )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LibVersion )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFile )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFile )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFCount )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFCount )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFileFlags )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFileFlags )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ long newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DLoad )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR toLoad,
            /* [retval][out] */ long __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DFileTo )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ BSTR outname,
            /* [retval][out] */ long __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LastMessage )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LastMessage )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFileStatus )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFileStatus )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FileFilter )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR inFile,
            /* [retval][out] */ BSTR __RPC_FAR *outFile);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QuickDecode )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR File2Decode,
            /* [in] */ BSTR OutputPath,
            /* [in] */ BOOL XFile,
            /* [retval][out] */ long __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IUUEngine __RPC_FAR * This);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFileInfo )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFileInfo )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DRemove )( 
            IUUEngine __RPC_FAR * This,
            short row);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Encode )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR iname,
            /* [in] */ BSTR oname,
            /* [in] */ BSTR nameinfile,
            /* [in] */ long encoding,
            /* [in] */ long lines,
            /* [in] */ long headers,
            /* [in] */ VARIANT destvar,
            /* [in] */ VARIANT fromvar,
            /* [in] */ VARIANT subjectvar,
            /* [retval][out] */ long __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *XFileAdd )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR toAdd,
            /* [retval][out] */ BOOL __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *XFileDel )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *retVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TempFolder )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TempFolder )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LastOSError )( 
            IUUEngine __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *errNo,
            /* [out] */ VARIANT __RPC_FAR *errText,
            /* [retval][out] */ BOOL __RPC_FAR *gotErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CRC32 )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BSTR fileName,
            /* [out] */ long __RPC_FAR *crc,
            /* [retval][out] */ BOOL __RPC_FAR *retVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClipboardFile )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ long hWnd,
            /* [in] */ BSTR Filename,
            /* [in] */ short CFMode,
            /* [retval][out] */ BOOL __RPC_FAR *retVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DFileDetail )( 
            IUUEngine __RPC_FAR * This,
            short row,
            short itemno,
            short subscr,
            /* [retval][out] */ VARIANT __RPC_FAR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DFileDetail )( 
            IUUEngine __RPC_FAR * This,
            short row,
            short itemno,
            short subscr,
            /* [in] */ VARIANT newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_XFile )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_XFile )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short row,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][helpcontext][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_XFileCount )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ short __RPC_FAR *pVal);
        
        /* [helpstring][helpcontext][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_XFileCount )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateTempName )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *tempFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadBuffer )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ VARIANT buffer,
            /* [out] */ VARIANT __RPC_FAR *tempName,
            /* [retval][out] */ BOOL __RPC_FAR *retVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_StrictFilenames )( 
            IUUEngine __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_StrictFilenames )( 
            IUUEngine __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } IUUEngineVtbl;

    interface IUUEngine
    {
        CONST_VTBL struct IUUEngineVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUUEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUUEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUUEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUUEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUUEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUUEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUUEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUUEngine_get_BracketPolicy(This,pVal)	\
    (This)->lpVtbl -> get_BracketPolicy(This,pVal)

#define IUUEngine_put_BracketPolicy(This,newVal)	\
    (This)->lpVtbl -> put_BracketPolicy(This,newVal)

#define IUUEngine_get_Desperate(This,pVal)	\
    (This)->lpVtbl -> get_Desperate(This,pVal)

#define IUUEngine_put_Desperate(This,newVal)	\
    (This)->lpVtbl -> put_Desperate(This,newVal)

#define IUUEngine_get_Dumb(This,pVal)	\
    (This)->lpVtbl -> get_Dumb(This,pVal)

#define IUUEngine_put_Dumb(This,newVal)	\
    (This)->lpVtbl -> put_Dumb(This,newVal)

#define IUUEngine_get_FastMode(This,pVal)	\
    (This)->lpVtbl -> get_FastMode(This,pVal)

#define IUUEngine_put_FastMode(This,newVal)	\
    (This)->lpVtbl -> put_FastMode(This,newVal)

#define IUUEngine_get_IgnoreReply(This,pVal)	\
    (This)->lpVtbl -> get_IgnoreReply(This,pVal)

#define IUUEngine_put_IgnoreReply(This,newVal)	\
    (This)->lpVtbl -> put_IgnoreReply(This,newVal)

#define IUUEngine_get_Overwrite(This,pVal)	\
    (This)->lpVtbl -> get_Overwrite(This,pVal)

#define IUUEngine_put_Overwrite(This,newVal)	\
    (This)->lpVtbl -> put_Overwrite(This,newVal)

#define IUUEngine_get_RemoveAfter(This,pVal)	\
    (This)->lpVtbl -> get_RemoveAfter(This,pVal)

#define IUUEngine_put_RemoveAfter(This,newVal)	\
    (This)->lpVtbl -> put_RemoveAfter(This,newVal)

#define IUUEngine_get_StrictMIME(This,pVal)	\
    (This)->lpVtbl -> get_StrictMIME(This,pVal)

#define IUUEngine_put_StrictMIME(This,newVal)	\
    (This)->lpVtbl -> put_StrictMIME(This,newVal)

#define IUUEngine_get_UseText(This,pVal)	\
    (This)->lpVtbl -> get_UseText(This,pVal)

#define IUUEngine_put_UseText(This,newVal)	\
    (This)->lpVtbl -> put_UseText(This,newVal)

#define IUUEngine_get_Verbose(This,pVal)	\
    (This)->lpVtbl -> get_Verbose(This,pVal)

#define IUUEngine_put_Verbose(This,newVal)	\
    (This)->lpVtbl -> put_Verbose(This,newVal)

#define IUUEngine_get_XFileAuto(This,pVal)	\
    (This)->lpVtbl -> get_XFileAuto(This,pVal)

#define IUUEngine_put_XFileAuto(This,newVal)	\
    (This)->lpVtbl -> put_XFileAuto(This,newVal)

#define IUUEngine_get_OutputPath(This,pVal)	\
    (This)->lpVtbl -> get_OutputPath(This,pVal)

#define IUUEngine_put_OutputPath(This,newVal)	\
    (This)->lpVtbl -> put_OutputPath(This,newVal)

#define IUUEngine_get_LibVersion(This,pVal)	\
    (This)->lpVtbl -> get_LibVersion(This,pVal)

#define IUUEngine_put_LibVersion(This,newVal)	\
    (This)->lpVtbl -> put_LibVersion(This,newVal)

#define IUUEngine_get_DFile(This,row,pVal)	\
    (This)->lpVtbl -> get_DFile(This,row,pVal)

#define IUUEngine_put_DFile(This,row,newVal)	\
    (This)->lpVtbl -> put_DFile(This,row,newVal)

#define IUUEngine_get_DFCount(This,pVal)	\
    (This)->lpVtbl -> get_DFCount(This,pVal)

#define IUUEngine_put_DFCount(This,newVal)	\
    (This)->lpVtbl -> put_DFCount(This,newVal)

#define IUUEngine_get_DFileFlags(This,row,pVal)	\
    (This)->lpVtbl -> get_DFileFlags(This,row,pVal)

#define IUUEngine_put_DFileFlags(This,row,newVal)	\
    (This)->lpVtbl -> put_DFileFlags(This,row,newVal)

#define IUUEngine_DLoad(This,toLoad,retVal)	\
    (This)->lpVtbl -> DLoad(This,toLoad,retVal)

#define IUUEngine_DFileTo(This,row,outname,retVal)	\
    (This)->lpVtbl -> DFileTo(This,row,outname,retVal)

#define IUUEngine_get_LastMessage(This,pVal)	\
    (This)->lpVtbl -> get_LastMessage(This,pVal)

#define IUUEngine_put_LastMessage(This,newVal)	\
    (This)->lpVtbl -> put_LastMessage(This,newVal)

#define IUUEngine_get_DFileStatus(This,row,pVal)	\
    (This)->lpVtbl -> get_DFileStatus(This,row,pVal)

#define IUUEngine_put_DFileStatus(This,row,newVal)	\
    (This)->lpVtbl -> put_DFileStatus(This,row,newVal)

#define IUUEngine_FileFilter(This,inFile,outFile)	\
    (This)->lpVtbl -> FileFilter(This,inFile,outFile)

#define IUUEngine_QuickDecode(This,File2Decode,OutputPath,XFile,retVal)	\
    (This)->lpVtbl -> QuickDecode(This,File2Decode,OutputPath,XFile,retVal)

#define IUUEngine_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IUUEngine_get_DFileInfo(This,row,pVal)	\
    (This)->lpVtbl -> get_DFileInfo(This,row,pVal)

#define IUUEngine_put_DFileInfo(This,row,newVal)	\
    (This)->lpVtbl -> put_DFileInfo(This,row,newVal)

#define IUUEngine_DRemove(This,row)	\
    (This)->lpVtbl -> DRemove(This,row)

#define IUUEngine_Encode(This,iname,oname,nameinfile,encoding,lines,headers,destvar,fromvar,subjectvar,retVal)	\
    (This)->lpVtbl -> Encode(This,iname,oname,nameinfile,encoding,lines,headers,destvar,fromvar,subjectvar,retVal)

#define IUUEngine_XFileAdd(This,toAdd,retVal)	\
    (This)->lpVtbl -> XFileAdd(This,toAdd,retVal)

#define IUUEngine_XFileDel(This,retVal)	\
    (This)->lpVtbl -> XFileDel(This,retVal)

#define IUUEngine_get_TempFolder(This,pVal)	\
    (This)->lpVtbl -> get_TempFolder(This,pVal)

#define IUUEngine_put_TempFolder(This,newVal)	\
    (This)->lpVtbl -> put_TempFolder(This,newVal)

#define IUUEngine_LastOSError(This,errNo,errText,gotErr)	\
    (This)->lpVtbl -> LastOSError(This,errNo,errText,gotErr)

#define IUUEngine_CRC32(This,fileName,crc,retVal)	\
    (This)->lpVtbl -> CRC32(This,fileName,crc,retVal)

#define IUUEngine_ClipboardFile(This,hWnd,Filename,CFMode,retVal)	\
    (This)->lpVtbl -> ClipboardFile(This,hWnd,Filename,CFMode,retVal)

#define IUUEngine_get_DFileDetail(This,row,itemno,subscr,pVal)	\
    (This)->lpVtbl -> get_DFileDetail(This,row,itemno,subscr,pVal)

#define IUUEngine_put_DFileDetail(This,row,itemno,subscr,newVal)	\
    (This)->lpVtbl -> put_DFileDetail(This,row,itemno,subscr,newVal)

#define IUUEngine_get_XFile(This,row,pVal)	\
    (This)->lpVtbl -> get_XFile(This,row,pVal)

#define IUUEngine_put_XFile(This,row,newVal)	\
    (This)->lpVtbl -> put_XFile(This,row,newVal)

#define IUUEngine_get_XFileCount(This,pVal)	\
    (This)->lpVtbl -> get_XFileCount(This,pVal)

#define IUUEngine_put_XFileCount(This,newVal)	\
    (This)->lpVtbl -> put_XFileCount(This,newVal)

#define IUUEngine_CreateTempName(This,tempFilename)	\
    (This)->lpVtbl -> CreateTempName(This,tempFilename)

#define IUUEngine_LoadBuffer(This,buffer,tempName,retVal)	\
    (This)->lpVtbl -> LoadBuffer(This,buffer,tempName,retVal)

#define IUUEngine_get_StrictFilenames(This,pVal)	\
    (This)->lpVtbl -> get_StrictFilenames(This,pVal)

#define IUUEngine_put_StrictFilenames(This,newVal)	\
    (This)->lpVtbl -> put_StrictFilenames(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_BracketPolicy_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_BracketPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_BracketPolicy_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_BracketPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_Desperate_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_Desperate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_Desperate_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IUUEngine_put_Desperate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_Dumb_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_Dumb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_Dumb_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_Dumb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_FastMode_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_FastMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_FastMode_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_FastMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_IgnoreReply_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_IgnoreReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_IgnoreReply_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_IgnoreReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_Overwrite_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_Overwrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_Overwrite_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_Overwrite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_RemoveAfter_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_RemoveAfter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_RemoveAfter_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_RemoveAfter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_StrictMIME_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_StrictMIME_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_StrictMIME_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_StrictMIME_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_UseText_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_UseText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_UseText_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_UseText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_Verbose_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_Verbose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_Verbose_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_Verbose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_XFileAuto_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_XFileAuto_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_XFileAuto_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_XFileAuto_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_OutputPath_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_OutputPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_OutputPath_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_OutputPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_LibVersion_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_LibVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_LibVersion_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_LibVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFile_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFile_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_DFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFCount_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFCount_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IUUEngine_put_DFCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFileFlags_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFileFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFileFlags_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ long newVal);


void __RPC_STUB IUUEngine_put_DFileFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_DLoad_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR toLoad,
    /* [retval][out] */ long __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_DLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_DFileTo_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ BSTR outname,
    /* [retval][out] */ long __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_DFileTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_LastMessage_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_LastMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_LastMessage_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_LastMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFileStatus_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFileStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFileStatus_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_DFileStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_FileFilter_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR inFile,
    /* [retval][out] */ BSTR __RPC_FAR *outFile);


void __RPC_STUB IUUEngine_FileFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_QuickDecode_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR File2Decode,
    /* [in] */ BSTR OutputPath,
    /* [in] */ BOOL XFile,
    /* [retval][out] */ long __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_QuickDecode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_Reset_Proxy( 
    IUUEngine __RPC_FAR * This);


void __RPC_STUB IUUEngine_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFileInfo_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFileInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFileInfo_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_DFileInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_DRemove_Proxy( 
    IUUEngine __RPC_FAR * This,
    short row);


void __RPC_STUB IUUEngine_DRemove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_Encode_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR iname,
    /* [in] */ BSTR oname,
    /* [in] */ BSTR nameinfile,
    /* [in] */ long encoding,
    /* [in] */ long lines,
    /* [in] */ long headers,
    /* [in] */ VARIANT destvar,
    /* [in] */ VARIANT fromvar,
    /* [in] */ VARIANT subjectvar,
    /* [retval][out] */ long __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_Encode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_XFileAdd_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR toAdd,
    /* [retval][out] */ BOOL __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_XFileAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_XFileDel_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_XFileDel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_TempFolder_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_TempFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_TempFolder_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_TempFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_LastOSError_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *errNo,
    /* [out] */ VARIANT __RPC_FAR *errText,
    /* [retval][out] */ BOOL __RPC_FAR *gotErr);


void __RPC_STUB IUUEngine_LastOSError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_CRC32_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BSTR fileName,
    /* [out] */ long __RPC_FAR *crc,
    /* [retval][out] */ BOOL __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_CRC32_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_ClipboardFile_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ long hWnd,
    /* [in] */ BSTR Filename,
    /* [in] */ short CFMode,
    /* [retval][out] */ BOOL __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_ClipboardFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_DFileDetail_Proxy( 
    IUUEngine __RPC_FAR * This,
    short row,
    short itemno,
    short subscr,
    /* [retval][out] */ VARIANT __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_DFileDetail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_DFileDetail_Proxy( 
    IUUEngine __RPC_FAR * This,
    short row,
    short itemno,
    short subscr,
    /* [in] */ VARIANT newVal);


void __RPC_STUB IUUEngine_put_DFileDetail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_XFile_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_XFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_XFile_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short row,
    /* [in] */ BSTR newVal);


void __RPC_STUB IUUEngine_put_XFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_XFileCount_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ short __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_XFileCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][helpcontext][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_XFileCount_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ short newVal);


void __RPC_STUB IUUEngine_put_XFileCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_CreateTempName_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *tempFilename);


void __RPC_STUB IUUEngine_CreateTempName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IUUEngine_LoadBuffer_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ VARIANT buffer,
    /* [out] */ VARIANT __RPC_FAR *tempName,
    /* [retval][out] */ BOOL __RPC_FAR *retVal);


void __RPC_STUB IUUEngine_LoadBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IUUEngine_get_StrictFilenames_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IUUEngine_get_StrictFilenames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IUUEngine_put_StrictFilenames_Proxy( 
    IUUEngine __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IUUEngine_put_StrictFilenames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUUEngine_INTERFACE_DEFINED__ */



#ifndef __UUDATLLib_LIBRARY_DEFINED__
#define __UUDATLLib_LIBRARY_DEFINED__

/* library UUDATLLib */
/* [helpstring][version][uuid] */ 

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("971609AE-2325-4905-89FD-11976AE6644E") 
enum __MIDL___MIDL_itf_UudATL_0244_0001
    {	uudMsgMessage	= 0,
	uudMsgNote	= 1,
	uudMsgWarning	= 2,
	uudMsgError	= 3,
	uudMsgFatal	= 4,
	uudMsgPanic	= 5
    }	Messages;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("7B396FA0-66CF-4373-B0D6-1E278D5D96B6") 
enum __MIDL___MIDL_itf_UudATL_0244_0002
    {	uudRetOK	= 0,
	uudRetIOErr	= 1,
	uudRetNoMem	= 2,
	uudRetIllVal	= 3,
	uudRetNoData	= 4,
	uudRetNoEnd	= 5,
	uudRetUnsup	= 6,
	uudRetExists	= 7,
	uudRetCancel	= 9
    }	ReturnCodes;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("6BF727DD-E0B7-4dac-BFA5-77C54FA74633") 
enum __MIDL___MIDL_itf_UudATL_0244_0003
    {	uudFileRead	= 0,
	uudFileMisPart	= 1,
	uudFileNoBegin	= 2,
	uudFileNoEnd	= 4,
	uudFileNoData	= 8,
	uudFileOK	= 16,
	uudFileError	= 32,
	uudFileDecoded	= 64,
	uudFileTmpFile	= 128,
	uudFileGenFn	= 256
    }	DFileStatus;

typedef /* [public][public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("CD6E061A-9C35-434f-9272-62B857667DBE") 
enum __MIDL___MIDL_itf_UudATL_0244_0004
    {	uudActIdle	= 0,
	uudActScanning	= 1,
	uudActDecoding	= 2,
	uudActCopying	= 3,
	uudActEncoding	= 4,
	uudActNewStep	= 9
    }	ProgressCodes;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("4EEC4515-7153-43e8-852F-69F27B8C47EC") 
enum __MIDL___MIDL_itf_UudATL_0244_0005
    {	uudLDState	= 0,
	uudLDMode	= 1,
	uudLDBegin	= 2,
	uudLDEnd	= 3,
	uudLDUuDet	= 4,
	uudLDFlags	= 5,
	uudLDSize	= 6,
	uudLDFileName	= 7,
	uudLDSubF	= 8,
	uudLDMIMEID	= 9,
	uudLDMIMEType	= 10,
	uudLDBinFile	= 11,
	uudLDHavePart	= 12,
	uudLDMissPart	= 13,
	uudLDUFPart	= 14,
	uudLDUFrSubj	= 15,
	uudLDUFrOrg	= 16,
	uudLDUFrSFN	= 17,
	uudLDUFrStart	= 18,
	uudLDUFrLength	= 19,
	uudLDUFrCount	= 20
    }	DFileDetailItems;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("C65096E7-361A-424a-8C24-EF312F6AA03D") 
enum __MIDL___MIDL_itf_UudATL_0244_0006
    {	uudEncUU	= 1,
	uudEncB64	= 2,
	uudEncXX	= 3,
	uudEncBinHex	= 4,
	uudEncPlainText	= 5,
	uudEncQuotedPrintable	= 6,
	uudEncyEnc	= 7
    }	EncodeModes;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("66979A5C-8BCC-4e32-ACB5-4B1C74A79099") 
enum __MIDL___MIDL_itf_UudATL_0244_0007
    {	uudEncHUud	= 0,
	uudEncHSimple	= 1,
	uudEncHMail	= 2,
	uudEncHNews	= 3
    }	EncodeHeaders;

typedef /* [public][helpstring][helpcontext][uuid] */  DECLSPEC_UUID("2E45475E-7F1C-427b-9E57-D2578F099D2F") 
enum __MIDL___MIDL_itf_UudATL_0244_0008
    {	uudCFcff	= 0,
	uudCFc2nf	= 1,
	uudCFac2f	= 2
    }	ClipFileOperations;


EXTERN_C const IID LIBID_UUDATLLib;

#ifndef ___IUUEngineEvents_DISPINTERFACE_DEFINED__
#define ___IUUEngineEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IUUEngineEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IUUEngineEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("18C87066-DCE9-4E71-837C-C9ACB521BE32")
    _IUUEngineEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IUUEngineEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IUUEngineEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IUUEngineEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IUUEngineEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IUUEngineEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IUUEngineEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IUUEngineEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IUUEngineEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IUUEngineEventsVtbl;

    interface _IUUEngineEvents
    {
        CONST_VTBL struct _IUUEngineEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IUUEngineEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IUUEngineEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IUUEngineEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IUUEngineEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IUUEngineEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IUUEngineEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IUUEngineEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IUUEngineEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_UUEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("B0C48BEA-ABEE-4105-8BB1-24D4970C39D8")
UUEngine;
#endif
#endif /* __UUDATLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


