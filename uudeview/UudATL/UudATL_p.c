
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AXP64)
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "UudATL.h"

#define TYPE_FORMAT_STRING_SIZE   1033                              
#define PROC_FORMAT_STRING_SIZE   1983                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IUUEngine, ver. 0.0,
   GUID={0x60100074,0x531F,0x4D3A,{0xA2,0xB1,0x39,0x41,0xBE,0x58,0x28,0xB0}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUUEngine_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IUUEngine_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56,
    84,
    112,
    140,
    168,
    196,
    224,
    252,
    280,
    308,
    336,
    364,
    392,
    420,
    448,
    476,
    504,
    532,
    560,
    588,
    616,
    644,
    672,
    700,
    728,
    762,
    796,
    824,
    852,
    886,
    920,
    954,
    994,
    1022,
    1050,
    1084,
    1118,
    1152,
    1198,
    1220,
    1254,
    1288,
    1316,
    1398,
    1432,
    1460,
    1488,
    1516,
    1556,
    1596,
    1642,
    1688,
    1734,
    1768,
    1802,
    1830,
    1858,
    1886,
    1926,
    1954
    };

static const MIDL_SERVER_INFO IUUEngine_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IUUEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IUUEngine_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IUUEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(69) _IUUEngineProxyVtbl = 
{
    &IUUEngine_ProxyInfo,
    &IID_IUUEngine,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IUUEngine::get_BracketPolicy */ ,
    (void *)-1 /* IUUEngine::put_BracketPolicy */ ,
    (void *)-1 /* IUUEngine::get_Desperate */ ,
    (void *)-1 /* IUUEngine::put_Desperate */ ,
    (void *)-1 /* IUUEngine::get_Dumb */ ,
    (void *)-1 /* IUUEngine::put_Dumb */ ,
    (void *)-1 /* IUUEngine::get_FastMode */ ,
    (void *)-1 /* IUUEngine::put_FastMode */ ,
    (void *)-1 /* IUUEngine::get_IgnoreReply */ ,
    (void *)-1 /* IUUEngine::put_IgnoreReply */ ,
    (void *)-1 /* IUUEngine::get_Overwrite */ ,
    (void *)-1 /* IUUEngine::put_Overwrite */ ,
    (void *)-1 /* IUUEngine::get_RemoveAfter */ ,
    (void *)-1 /* IUUEngine::put_RemoveAfter */ ,
    (void *)-1 /* IUUEngine::get_StrictMIME */ ,
    (void *)-1 /* IUUEngine::put_StrictMIME */ ,
    (void *)-1 /* IUUEngine::get_UseText */ ,
    (void *)-1 /* IUUEngine::put_UseText */ ,
    (void *)-1 /* IUUEngine::get_Verbose */ ,
    (void *)-1 /* IUUEngine::put_Verbose */ ,
    (void *)-1 /* IUUEngine::get_XFileAuto */ ,
    (void *)-1 /* IUUEngine::put_XFileAuto */ ,
    (void *)-1 /* IUUEngine::get_OutputPath */ ,
    (void *)-1 /* IUUEngine::put_OutputPath */ ,
    (void *)-1 /* IUUEngine::get_LibVersion */ ,
    (void *)-1 /* IUUEngine::put_LibVersion */ ,
    (void *)-1 /* IUUEngine::get_DFile */ ,
    (void *)-1 /* IUUEngine::put_DFile */ ,
    (void *)-1 /* IUUEngine::get_DFCount */ ,
    (void *)-1 /* IUUEngine::put_DFCount */ ,
    (void *)-1 /* IUUEngine::get_DFileFlags */ ,
    (void *)-1 /* IUUEngine::put_DFileFlags */ ,
    (void *)-1 /* IUUEngine::DLoad */ ,
    (void *)-1 /* IUUEngine::DFileTo */ ,
    (void *)-1 /* IUUEngine::get_LastMessage */ ,
    (void *)-1 /* IUUEngine::put_LastMessage */ ,
    (void *)-1 /* IUUEngine::get_DFileStatus */ ,
    (void *)-1 /* IUUEngine::put_DFileStatus */ ,
    (void *)-1 /* IUUEngine::FileFilter */ ,
    (void *)-1 /* IUUEngine::QuickDecode */ ,
    (void *)-1 /* IUUEngine::Reset */ ,
    (void *)-1 /* IUUEngine::get_DFileInfo */ ,
    (void *)-1 /* IUUEngine::put_DFileInfo */ ,
    (void *)-1 /* IUUEngine::DRemove */ ,
    (void *)-1 /* IUUEngine::Encode */ ,
    (void *)-1 /* IUUEngine::XFileAdd */ ,
    (void *)-1 /* IUUEngine::XFileDel */ ,
    (void *)-1 /* IUUEngine::get_TempFolder */ ,
    (void *)-1 /* IUUEngine::put_TempFolder */ ,
    (void *)-1 /* IUUEngine::LastOSError */ ,
    (void *)-1 /* IUUEngine::CRC32 */ ,
    (void *)-1 /* IUUEngine::ClipboardFile */ ,
    (void *)-1 /* IUUEngine::get_DFileDetail */ ,
    (void *)-1 /* IUUEngine::put_DFileDetail */ ,
    (void *)-1 /* IUUEngine::get_XFile */ ,
    (void *)-1 /* IUUEngine::put_XFile */ ,
    (void *)-1 /* IUUEngine::get_XFileCount */ ,
    (void *)-1 /* IUUEngine::put_XFileCount */ ,
    (void *)-1 /* IUUEngine::CreateTempName */ ,
    (void *)-1 /* IUUEngine::LoadBuffer */ ,
    (void *)-1 /* IUUEngine::get_StrictFilenames */ ,
    (void *)-1 /* IUUEngine::put_StrictFilenames */
};


static const PRPC_STUB_FUNCTION IUUEngine_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IUUEngineStubVtbl =
{
    &IID_IUUEngine,
    &IUUEngine_ServerInfo,
    69,
    &IUUEngine_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x5030118, /* MIDL Version 5.3.280 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_BracketPolicy */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x10 ),	/* 16 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BracketPolicy */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 36 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 38 */	NdrFcShort( 0x8 ),	/* 8 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 44 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Desperate */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 64 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0xe ),	/* 14 */
/* 70 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 72 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 76 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Desperate */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 94 */	NdrFcShort( 0x6 ),	/* 6 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 102 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 104 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Dumb */

/* 112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 120 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 126 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 128 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 130 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Dumb */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 148 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 152 */	NdrFcShort( 0x8 ),	/* 8 */
/* 154 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 158 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 164 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FastMode */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x10 ),	/* 16 */
/* 182 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 186 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 192 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FastMode */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 204 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 212 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 220 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IgnoreReply */

/* 224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x10 ),	/* 16 */
/* 238 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 240 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IgnoreReply */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 260 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 266 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 268 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 270 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 276 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Overwrite */

/* 280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 288 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x10 ),	/* 16 */
/* 294 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 296 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 298 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 304 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Overwrite */

/* 308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 316 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 322 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 326 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RemoveAfter */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 344 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x10 ),	/* 16 */
/* 350 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 352 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 354 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 360 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RemoveAfter */

/* 364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 372 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 374 */	NdrFcShort( 0x8 ),	/* 8 */
/* 376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 378 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 380 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 382 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 386 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 388 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StrictMIME */

/* 392 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 394 */	NdrFcLong( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x15 ),	/* 21 */
#ifndef _ALPHA_
/* 400 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x10 ),	/* 16 */
/* 406 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 408 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 410 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 416 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StrictMIME */

/* 420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x16 ),	/* 22 */
#ifndef _ALPHA_
/* 428 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 434 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 438 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 444 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UseText */

/* 448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x17 ),	/* 23 */
#ifndef _ALPHA_
/* 456 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x10 ),	/* 16 */
/* 462 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 464 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 466 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 472 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UseText */

/* 476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x18 ),	/* 24 */
#ifndef _ALPHA_
/* 484 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 490 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 492 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 494 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 498 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 500 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Verbose */

/* 504 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 506 */	NdrFcLong( 0x0 ),	/* 0 */
/* 510 */	NdrFcShort( 0x19 ),	/* 25 */
#ifndef _ALPHA_
/* 512 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x10 ),	/* 16 */
/* 518 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 520 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 522 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 528 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Verbose */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x1a ),	/* 26 */
#ifndef _ALPHA_
/* 540 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 546 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 548 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 550 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 556 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFileAuto */

/* 560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x1b ),	/* 27 */
#ifndef _ALPHA_
/* 568 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x10 ),	/* 16 */
/* 574 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 576 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 578 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 584 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFileAuto */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x1c ),	/* 28 */
#ifndef _ALPHA_
/* 596 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 604 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 606 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 610 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 612 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 614 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OutputPath */

/* 616 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 618 */	NdrFcLong( 0x0 ),	/* 0 */
/* 622 */	NdrFcShort( 0x1d ),	/* 29 */
#ifndef _ALPHA_
/* 624 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 632 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 634 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 636 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 640 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputPath */

/* 644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 650 */	NdrFcShort( 0x1e ),	/* 30 */
#ifndef _ALPHA_
/* 652 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 658 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 660 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 662 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 664 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 668 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LibVersion */

/* 672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x1f ),	/* 31 */
#ifndef _ALPHA_
/* 680 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 686 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 688 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 690 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 692 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 696 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LibVersion */

/* 700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x20 ),	/* 32 */
#ifndef _ALPHA_
/* 708 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 714 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 716 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 718 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 720 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 724 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFile */

/* 728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 734 */	NdrFcShort( 0x21 ),	/* 33 */
#ifndef _ALPHA_
/* 736 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 738 */	NdrFcShort( 0x6 ),	/* 6 */
/* 740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 742 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 746 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 748 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 750 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 752 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 754 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 758 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFile */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x22 ),	/* 34 */
#ifndef _ALPHA_
/* 770 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 772 */	NdrFcShort( 0x6 ),	/* 6 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 778 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 780 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 782 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 784 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 786 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 788 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 792 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFCount */

/* 796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x23 ),	/* 35 */
#ifndef _ALPHA_
/* 804 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0xe ),	/* 14 */
/* 810 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 812 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 814 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 816 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 820 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFCount */

/* 824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x24 ),	/* 36 */
#ifndef _ALPHA_
/* 832 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 834 */	NdrFcShort( 0x6 ),	/* 6 */
/* 836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 838 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 840 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 842 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 844 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 848 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileFlags */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x25 ),	/* 37 */
#ifndef _ALPHA_
/* 860 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 862 */	NdrFcShort( 0x6 ),	/* 6 */
/* 864 */	NdrFcShort( 0x10 ),	/* 16 */
/* 866 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 868 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 870 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 872 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 874 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 876 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 882 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileFlags */

/* 886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 892 */	NdrFcShort( 0x26 ),	/* 38 */
#ifndef _ALPHA_
/* 894 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 896 */	NdrFcShort( 0xe ),	/* 14 */
/* 898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 900 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 904 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 906 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 910 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 916 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DLoad */

/* 920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 926 */	NdrFcShort( 0x27 ),	/* 39 */
#ifndef _ALPHA_
/* 928 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x10 ),	/* 16 */
/* 934 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter toLoad */

/* 936 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 938 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 940 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter retVal */

/* 942 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 944 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 950 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DFileTo */

/* 954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x28 ),	/* 40 */
#ifndef _ALPHA_
/* 962 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 964 */	NdrFcShort( 0x6 ),	/* 6 */
/* 966 */	NdrFcShort( 0x10 ),	/* 16 */
/* 968 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter row */

/* 970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 972 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 974 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter outname */

/* 976 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 978 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 980 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter retVal */

/* 982 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 984 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 990 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LastMessage */

/* 994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x29 ),	/* 41 */
#ifndef _ALPHA_
/* 1002 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1008 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1010 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1012 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1014 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1018 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LastMessage */

/* 1022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x2a ),	/* 42 */
#ifndef _ALPHA_
/* 1030 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1036 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1038 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1040 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1042 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 1044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1046 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileStatus */

/* 1050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x2b ),	/* 43 */
#ifndef _ALPHA_
/* 1058 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1060 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1064 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1068 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1070 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1072 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1074 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1076 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1078 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1080 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileStatus */

/* 1084 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1086 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x2c ),	/* 44 */
#ifndef _ALPHA_
/* 1092 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1094 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1096 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1098 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1102 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1104 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1106 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1108 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1110 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 1112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1114 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FileFilter */

/* 1118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0x2d ),	/* 45 */
#ifndef _ALPHA_
/* 1126 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1132 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inFile */

/* 1134 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1136 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1138 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter outFile */

/* 1140 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1142 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1144 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1148 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QuickDecode */

/* 1152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x2e ),	/* 46 */
#ifndef _ALPHA_
/* 1160 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1166 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter File2Decode */

/* 1168 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1170 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1172 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter OutputPath */

/* 1174 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1176 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1178 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter XFile */

/* 1180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1182 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 1186 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1188 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1194 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1204 */	NdrFcShort( 0x2f ),	/* 47 */
#ifndef _ALPHA_
/* 1206 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1212 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 1214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1216 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileInfo */

/* 1220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x30 ),	/* 48 */
#ifndef _ALPHA_
/* 1228 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1230 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1234 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1236 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1238 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1240 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1242 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1244 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1246 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1250 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileInfo */

/* 1254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x31 ),	/* 49 */
#ifndef _ALPHA_
/* 1262 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1264 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1266 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1268 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1270 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1272 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1274 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1276 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1278 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1280 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 1282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1284 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DRemove */

/* 1288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x32 ),	/* 50 */
#ifndef _ALPHA_
/* 1296 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1298 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1302 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter row */

/* 1304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1306 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1308 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1312 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Encode */

/* 1316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x33 ),	/* 51 */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1324 */	NdrFcShort( 0x54 ),	/* x86 Stack size/offset = 84 */
#else
			NdrFcShort( 0x58 ),	/*  MIPS Stack size/offset = 88 */
#endif
#else
			NdrFcShort( 0x58 ),	/* PPC Stack size/offset = 88 */
#endif
#else
			NdrFcShort( 0x78 ),	/* Alpha Stack size/offset = 120 */
#endif
/* 1326 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1328 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1330 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0xb,		/* 11 */

	/* Parameter iname */

/* 1332 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1334 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1336 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter oname */

/* 1338 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1340 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1342 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter nameinfile */

/* 1344 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1346 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1348 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter encoding */

/* 1350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1352 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lines */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1358 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter headers */

/* 1362 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1364 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter destvar */

/* 1368 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1370 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/*  MIPS Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x20 ),	/* PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 1372 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter fromvar */

/* 1374 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1376 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
#else
			NdrFcShort( 0x30 ),	/*  MIPS Stack size/offset = 48 */
#endif
#else
			NdrFcShort( 0x30 ),	/* PPC Stack size/offset = 48 */
#endif
#else
			NdrFcShort( 0x48 ),	/* Alpha Stack size/offset = 72 */
#endif
/* 1378 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter subjectvar */

/* 1380 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1382 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
#else
			NdrFcShort( 0x40 ),	/*  MIPS Stack size/offset = 64 */
#endif
#else
			NdrFcShort( 0x40 ),	/* PPC Stack size/offset = 64 */
#endif
#else
			NdrFcShort( 0x58 ),	/* Alpha Stack size/offset = 88 */
#endif
/* 1384 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter retVal */

/* 1386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1388 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
#else
			NdrFcShort( 0x50 ),	/*  MIPS Stack size/offset = 80 */
#endif
#else
			NdrFcShort( 0x50 ),	/* PPC Stack size/offset = 80 */
#endif
#else
			NdrFcShort( 0x68 ),	/* Alpha Stack size/offset = 104 */
#endif
/* 1390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1394 */	NdrFcShort( 0x50 ),	/* x86 Stack size/offset = 80 */
#else
			NdrFcShort( 0x54 ),	/*  MIPS Stack size/offset = 84 */
#endif
#else
			NdrFcShort( 0x54 ),	/* PPC Stack size/offset = 84 */
#endif
#else
			NdrFcShort( 0x70 ),	/* Alpha Stack size/offset = 112 */
#endif
/* 1396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure XFileAdd */

/* 1398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1404 */	NdrFcShort( 0x34 ),	/* 52 */
#ifndef _ALPHA_
/* 1406 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1412 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter toAdd */

/* 1414 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1416 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1418 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter retVal */

/* 1420 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1422 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1426 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1428 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure XFileDel */

/* 1432 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1434 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1438 */	NdrFcShort( 0x35 ),	/* 53 */
#ifndef _ALPHA_
/* 1440 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1446 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter retVal */

/* 1448 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1450 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1454 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1456 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1458 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TempFolder */

/* 1460 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1462 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1466 */	NdrFcShort( 0x36 ),	/* 54 */
#ifndef _ALPHA_
/* 1468 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1472 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1474 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1476 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1478 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1480 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1482 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1484 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TempFolder */

/* 1488 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1490 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1494 */	NdrFcShort( 0x37 ),	/* 55 */
#ifndef _ALPHA_
/* 1496 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1502 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1504 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1506 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1508 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 1510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1512 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LastOSError */

/* 1516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x38 ),	/* 56 */
#ifndef _ALPHA_
/* 1524 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1528 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1530 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x4,		/* 4 */

	/* Parameter errNo */

/* 1532 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1534 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errText */

/* 1538 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 1540 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1542 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter gotErr */

/* 1544 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1546 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1552 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CRC32 */

/* 1556 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1558 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x39 ),	/* 57 */
#ifndef _ALPHA_
/* 1564 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1570 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter fileName */

/* 1572 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1574 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1576 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter crc */

/* 1578 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1580 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1582 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 1584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1586 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1592 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClipboardFile */

/* 1596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x3a ),	/* 58 */
#ifndef _ALPHA_
/* 1604 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1606 */	NdrFcShort( 0xe ),	/* 14 */
/* 1608 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1610 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter hWnd */

/* 1612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1614 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Filename */

/* 1618 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1620 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1622 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Parameter CFMode */

/* 1624 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1626 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1628 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 1630 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1632 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1638 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileDetail */

/* 1642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1648 */	NdrFcShort( 0x3b ),	/* 59 */
#ifndef _ALPHA_
/* 1650 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1652 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1656 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x5,		/* 5 */

	/* Parameter row */

/* 1658 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1660 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1662 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter itemno */

/* 1664 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1666 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1668 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter subscr */

/* 1670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1672 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1674 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1676 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 1678 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1680 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Return value */

/* 1682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1684 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileDetail */

/* 1688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x3c ),	/* 60 */
#ifndef _ALPHA_
/* 1696 */	NdrFcShort( 0x24 ),	/* x86, MIPS, PPC Stack size/offset = 36 */
#else
			NdrFcShort( 0x38 ),	/* Alpha Stack size/offset = 56 */
#endif
/* 1698 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1702 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter row */

/* 1704 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1706 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1708 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter itemno */

/* 1710 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1712 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1714 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter subscr */

/* 1716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1718 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1720 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1722 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1724 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1726 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 1728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1730 */	NdrFcShort( 0x20 ),	/* x86, MIPS, PPC Stack size/offset = 32 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFile */

/* 1734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x3d ),	/* 61 */
#ifndef _ALPHA_
/* 1742 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1744 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1752 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1754 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1756 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1758 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1760 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1764 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFile */

/* 1768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x3e ),	/* 62 */
#ifndef _ALPHA_
/* 1776 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1778 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1782 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter row */

/* 1784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1786 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1788 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1790 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1792 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1794 */	NdrFcShort( 0x34 ),	/* Type Offset=52 */

	/* Return value */

/* 1796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1798 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFileCount */

/* 1802 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1808 */	NdrFcShort( 0x3f ),	/* 63 */
#ifndef _ALPHA_
/* 1810 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0xe ),	/* 14 */
/* 1816 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1818 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1820 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1822 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1824 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1826 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFileCount */

/* 1830 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1832 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1836 */	NdrFcShort( 0x40 ),	/* 64 */
#ifndef _ALPHA_
/* 1838 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1840 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1844 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1848 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1850 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1854 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTempName */

/* 1858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1864 */	NdrFcShort( 0x41 ),	/* 65 */
#ifndef _ALPHA_
/* 1866 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1872 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter tempFilename */

/* 1874 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1876 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1878 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1882 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadBuffer */

/* 1886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1892 */	NdrFcShort( 0x42 ),	/* 66 */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1894 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
#else
			NdrFcShort( 0x24 ),	/*  MIPS Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x24 ),	/* PPC Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1900 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter buffer */

/* 1902 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/*  MIPS Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1906 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter tempName */

/* 1908 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1910 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/*  MIPS Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1912 */	NdrFcShort( 0x3fe ),	/* Type Offset=1022 */

	/* Parameter retVal */

/* 1914 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1916 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/*  MIPS Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x1c ),	/* PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#ifndef _PPC_
#if !defined(_MIPS_)
/* 1922 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/*  MIPS Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x20 ),	/* PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StrictFilenames */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x43 ),	/* 67 */
#ifndef _ALPHA_
/* 1934 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1940 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 1942 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1944 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1950 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StrictFilenames */

/* 1954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x44 ),	/* 68 */
#ifndef _ALPHA_
/* 1962 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 1964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1968 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 1970 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 1972 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 1974 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1978 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 1980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 12 */	NdrFcShort( 0x1a ),	/* Offset= 26 (38) */
/* 14 */	
			0x13, 0x0,	/* FC_OP */
/* 16 */	NdrFcShort( 0xc ),	/* Offset= 12 (28) */
/* 18 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 20 */	NdrFcShort( 0x2 ),	/* 2 */
/* 22 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 24 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 26 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 28 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 30 */	NdrFcShort( 0x8 ),	/* 8 */
/* 32 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (18) */
/* 34 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 36 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 38 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 40 */	NdrFcShort( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x0 ),	/* 0 */
/* 46 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (14) */
/* 48 */	
			0x12, 0x0,	/* FC_UP */
/* 50 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (28) */
/* 52 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x4 ),	/* 4 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (48) */
/* 62 */	
			0x12, 0x0,	/* FC_UP */
/* 64 */	NdrFcShort( 0x398 ),	/* Offset= 920 (984) */
/* 66 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 68 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 70 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 72 */	NdrFcShort( 0x2 ),	/* Offset= 2 (74) */
/* 74 */	NdrFcShort( 0x10 ),	/* 16 */
/* 76 */	NdrFcShort( 0x2b ),	/* 43 */
/* 78 */	NdrFcLong( 0x3 ),	/* 3 */
/* 82 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 84 */	NdrFcLong( 0x11 ),	/* 17 */
/* 88 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 90 */	NdrFcLong( 0x2 ),	/* 2 */
/* 94 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 96 */	NdrFcLong( 0x4 ),	/* 4 */
/* 100 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 102 */	NdrFcLong( 0x5 ),	/* 5 */
/* 106 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 108 */	NdrFcLong( 0xb ),	/* 11 */
/* 112 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 114 */	NdrFcLong( 0xa ),	/* 10 */
/* 118 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 120 */	NdrFcLong( 0x6 ),	/* 6 */
/* 124 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (338) */
/* 126 */	NdrFcLong( 0x7 ),	/* 7 */
/* 130 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 132 */	NdrFcLong( 0x8 ),	/* 8 */
/* 136 */	NdrFcShort( 0xffffffa8 ),	/* Offset= -88 (48) */
/* 138 */	NdrFcLong( 0xd ),	/* 13 */
/* 142 */	NdrFcShort( 0xca ),	/* Offset= 202 (344) */
/* 144 */	NdrFcLong( 0x9 ),	/* 9 */
/* 148 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (362) */
/* 150 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 154 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (380) */
/* 156 */	NdrFcLong( 0x24 ),	/* 36 */
/* 160 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (912) */
/* 162 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 166 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (912) */
/* 168 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 172 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (916) */
/* 174 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 178 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (920) */
/* 180 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 184 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (924) */
/* 186 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 190 */	NdrFcShort( 0x2e2 ),	/* Offset= 738 (928) */
/* 192 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 196 */	NdrFcShort( 0x2e0 ),	/* Offset= 736 (932) */
/* 198 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 202 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (920) */
/* 204 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 208 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (924) */
/* 210 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 214 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (936) */
/* 216 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 220 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (932) */
/* 222 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 226 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (940) */
/* 228 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 232 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (944) */
/* 234 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 238 */	NdrFcShort( 0x2c6 ),	/* Offset= 710 (948) */
/* 240 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 244 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (952) */
/* 246 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 250 */	NdrFcShort( 0x2c2 ),	/* Offset= 706 (956) */
/* 252 */	NdrFcLong( 0x10 ),	/* 16 */
/* 256 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 258 */	NdrFcLong( 0x12 ),	/* 18 */
/* 262 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 264 */	NdrFcLong( 0x13 ),	/* 19 */
/* 268 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 270 */	NdrFcLong( 0x16 ),	/* 22 */
/* 274 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 276 */	NdrFcLong( 0x17 ),	/* 23 */
/* 280 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 282 */	NdrFcLong( 0xe ),	/* 14 */
/* 286 */	NdrFcShort( 0x2a6 ),	/* Offset= 678 (964) */
/* 288 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 292 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (976) */
/* 294 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 298 */	NdrFcShort( 0x2aa ),	/* Offset= 682 (980) */
/* 300 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 304 */	NdrFcShort( 0x268 ),	/* Offset= 616 (920) */
/* 306 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 310 */	NdrFcShort( 0x266 ),	/* Offset= 614 (924) */
/* 312 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 316 */	NdrFcShort( 0x260 ),	/* Offset= 608 (924) */
/* 318 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 322 */	NdrFcShort( 0x25a ),	/* Offset= 602 (924) */
/* 324 */	NdrFcLong( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* Offset= 0 (328) */
/* 330 */	NdrFcLong( 0x1 ),	/* 1 */
/* 334 */	NdrFcShort( 0x0 ),	/* Offset= 0 (334) */
/* 336 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (335) */
/* 338 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 342 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 344 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 356 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 358 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 360 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 362 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 364 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 376 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 380 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 382 */	NdrFcShort( 0x2 ),	/* Offset= 2 (384) */
/* 384 */	
			0x12, 0x0,	/* FC_UP */
/* 386 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (894) */
/* 388 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 390 */	NdrFcShort( 0x18 ),	/* 24 */
/* 392 */	NdrFcShort( 0xa ),	/* 10 */
/* 394 */	NdrFcLong( 0x8 ),	/* 8 */
/* 398 */	NdrFcShort( 0x58 ),	/* Offset= 88 (486) */
/* 400 */	NdrFcLong( 0xd ),	/* 13 */
/* 404 */	NdrFcShort( 0x78 ),	/* Offset= 120 (524) */
/* 406 */	NdrFcLong( 0x9 ),	/* 9 */
/* 410 */	NdrFcShort( 0x94 ),	/* Offset= 148 (558) */
/* 412 */	NdrFcLong( 0xc ),	/* 12 */
/* 416 */	NdrFcShort( 0xbc ),	/* Offset= 188 (604) */
/* 418 */	NdrFcLong( 0x24 ),	/* 36 */
/* 422 */	NdrFcShort( 0x114 ),	/* Offset= 276 (698) */
/* 424 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 428 */	NdrFcShort( 0x130 ),	/* Offset= 304 (732) */
/* 430 */	NdrFcLong( 0x10 ),	/* 16 */
/* 434 */	NdrFcShort( 0x148 ),	/* Offset= 328 (762) */
/* 436 */	NdrFcLong( 0x2 ),	/* 2 */
/* 440 */	NdrFcShort( 0x160 ),	/* Offset= 352 (792) */
/* 442 */	NdrFcLong( 0x3 ),	/* 3 */
/* 446 */	NdrFcShort( 0x178 ),	/* Offset= 376 (822) */
/* 448 */	NdrFcLong( 0x14 ),	/* 20 */
/* 452 */	NdrFcShort( 0x190 ),	/* Offset= 400 (852) */
/* 454 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (453) */
/* 456 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 458 */	NdrFcShort( 0x4 ),	/* 4 */
/* 460 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 466 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x1 ),	/* 1 */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	0x12, 0x0,	/* FC_UP */
/* 480 */	NdrFcShort( 0xfffffe3c ),	/* Offset= -452 (28) */
/* 482 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 484 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 486 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 490 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 492 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 494 */	NdrFcShort( 0x4 ),	/* 4 */
/* 496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 498 */	0x11, 0x0,	/* FC_RP */
/* 500 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (456) */
/* 502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 504 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 506 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 510 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 518 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 520 */	NdrFcShort( 0xffffff50 ),	/* Offset= -176 (344) */
/* 522 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 524 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x6 ),	/* Offset= 6 (536) */
/* 532 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 534 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 536 */	
			0x11, 0x0,	/* FC_RP */
/* 538 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (506) */
/* 540 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 552 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0xffffff40 ),	/* Offset= -192 (362) */
/* 556 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x6 ),	/* Offset= 6 (570) */
/* 566 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 568 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 570 */	
			0x11, 0x0,	/* FC_RP */
/* 572 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (540) */
/* 574 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 576 */	NdrFcShort( 0x4 ),	/* 4 */
/* 578 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 584 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 586 */	NdrFcShort( 0x4 ),	/* 4 */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	0x12, 0x0,	/* FC_UP */
/* 598 */	NdrFcShort( 0x182 ),	/* Offset= 386 (984) */
/* 600 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 602 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 604 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x6 ),	/* Offset= 6 (616) */
/* 612 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 614 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 616 */	
			0x11, 0x0,	/* FC_RP */
/* 618 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (574) */
/* 620 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 622 */	NdrFcLong( 0x2f ),	/* 47 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 632 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 634 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 636 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 638 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 640 */	NdrFcShort( 0x1 ),	/* 1 */
/* 642 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 644 */	NdrFcShort( 0x4 ),	/* 4 */
/* 646 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 648 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 650 */	NdrFcShort( 0x10 ),	/* 16 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	NdrFcShort( 0xa ),	/* Offset= 10 (664) */
/* 656 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 658 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 660 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (620) */
/* 662 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 664 */	
			0x12, 0x0,	/* FC_UP */
/* 666 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (638) */
/* 668 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 670 */	NdrFcShort( 0x4 ),	/* 4 */
/* 672 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 678 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 680 */	NdrFcShort( 0x4 ),	/* 4 */
/* 682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 684 */	NdrFcShort( 0x1 ),	/* 1 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	0x12, 0x0,	/* FC_UP */
/* 692 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (648) */
/* 694 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 696 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 698 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x6 ),	/* Offset= 6 (710) */
/* 706 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 708 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 710 */	
			0x11, 0x0,	/* FC_RP */
/* 712 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (668) */
/* 714 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0x8 ),	/* 8 */
/* 718 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 720 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x10 ),	/* 16 */
/* 724 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 726 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 728 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (714) */
			0x5b,		/* FC_END */
/* 732 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 734 */	NdrFcShort( 0x18 ),	/* 24 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0xa ),	/* Offset= 10 (748) */
/* 740 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 742 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 744 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (720) */
/* 746 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 748 */	
			0x11, 0x0,	/* FC_RP */
/* 750 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (506) */
/* 752 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 754 */	NdrFcShort( 0x1 ),	/* 1 */
/* 756 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 762 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 768 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 770 */	NdrFcShort( 0x4 ),	/* 4 */
/* 772 */	NdrFcShort( 0x4 ),	/* 4 */
/* 774 */	0x12, 0x0,	/* FC_UP */
/* 776 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (752) */
/* 778 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 780 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 782 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 784 */	NdrFcShort( 0x2 ),	/* 2 */
/* 786 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 792 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 796 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 798 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 800 */	NdrFcShort( 0x4 ),	/* 4 */
/* 802 */	NdrFcShort( 0x4 ),	/* 4 */
/* 804 */	0x12, 0x0,	/* FC_UP */
/* 806 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (782) */
/* 808 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 810 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 812 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 814 */	NdrFcShort( 0x4 ),	/* 4 */
/* 816 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 822 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 826 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 828 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 830 */	NdrFcShort( 0x4 ),	/* 4 */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	0x12, 0x0,	/* FC_UP */
/* 836 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (812) */
/* 838 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 840 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 842 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 846 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 852 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 858 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 860 */	NdrFcShort( 0x4 ),	/* 4 */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	0x12, 0x0,	/* FC_UP */
/* 866 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (842) */
/* 868 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 870 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 872 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 876 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 878 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 880 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 882 */	NdrFcShort( 0x8 ),	/* 8 */
/* 884 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 886 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 888 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 890 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (872) */
/* 892 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 894 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x28 ),	/* 40 */
/* 898 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (880) */
/* 900 */	NdrFcShort( 0x0 ),	/* Offset= 0 (900) */
/* 902 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 904 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 906 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 908 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffdf7 ),	/* Offset= -521 (388) */
			0x5b,		/* FC_END */
/* 912 */	
			0x12, 0x0,	/* FC_UP */
/* 914 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (648) */
/* 916 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 918 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 920 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 922 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 924 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 926 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 928 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 930 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 932 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 934 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 936 */	
			0x12, 0x0,	/* FC_UP */
/* 938 */	NdrFcShort( 0xfffffda8 ),	/* Offset= -600 (338) */
/* 940 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 942 */	NdrFcShort( 0xfffffc82 ),	/* Offset= -894 (48) */
/* 944 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 946 */	NdrFcShort( 0xfffffda6 ),	/* Offset= -602 (344) */
/* 948 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 950 */	NdrFcShort( 0xfffffdb4 ),	/* Offset= -588 (362) */
/* 952 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 954 */	NdrFcShort( 0xfffffdc2 ),	/* Offset= -574 (380) */
/* 956 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 958 */	NdrFcShort( 0x2 ),	/* Offset= 2 (960) */
/* 960 */	
			0x12, 0x0,	/* FC_UP */
/* 962 */	NdrFcShort( 0x16 ),	/* Offset= 22 (984) */
/* 964 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 966 */	NdrFcShort( 0x10 ),	/* 16 */
/* 968 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 970 */	0x1,		/* FC_BYTE */
			0x38,		/* FC_ALIGNM4 */
/* 972 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 974 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 976 */	
			0x12, 0x0,	/* FC_UP */
/* 978 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (964) */
/* 980 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 982 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 986 */	NdrFcShort( 0x20 ),	/* 32 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x0 ),	/* Offset= 0 (990) */
/* 992 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 994 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 996 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 998 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1000 */	NdrFcShort( 0xfffffc5a ),	/* Offset= -934 (66) */
/* 1002 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1004 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1006 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0xfffffc4a ),	/* Offset= -950 (62) */
/* 1014 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1016 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1022) */
/* 1018 */	
			0x13, 0x0,	/* FC_OP */
/* 1020 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (984) */
/* 1022 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1024 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1026 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1030 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1018) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _UudATL_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IUUEngineProxyVtbl,
    0
};

const CInterfaceStubVtbl * _UudATL_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IUUEngineStubVtbl,
    0
};

PCInterfaceName const _UudATL_InterfaceNamesList[] = 
{
    "IUUEngine",
    0
};

const IID *  _UudATL_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _UudATL_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _UudATL, pIID, n)

int __stdcall _UudATL_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_UudATL_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo UudATL_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _UudATL_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _UudATL_StubVtblList,
    (const PCInterfaceName * ) & _UudATL_InterfaceNamesList,
    (const IID ** ) & _UudATL_BaseIIDList,
    & _UudATL_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};


#endif /* !defined(_M_IA64) && !defined(_M_AXP64)*/


#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Sat Jun 15 18:27:24 2002
 */
/* Compiler settings for H:\My Documents\Utilities\Vc\UudATL\UudATL.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win64 (32b run,appending), ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AXP64)
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "UudATL.h"

#define TYPE_FORMAT_STRING_SIZE   1015                              
#define PROC_FORMAT_STRING_SIZE   2603                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IUUEngine, ver. 0.0,
   GUID={0x60100074,0x531F,0x4D3A,{0xA2,0xB1,0x39,0x41,0xBE,0x58,0x28,0xB0}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUUEngine_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IUUEngine_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    38,
    76,
    114,
    152,
    190,
    228,
    266,
    304,
    342,
    380,
    418,
    456,
    494,
    532,
    570,
    608,
    646,
    684,
    722,
    760,
    798,
    836,
    874,
    912,
    950,
    988,
    1032,
    1076,
    1114,
    1152,
    1196,
    1240,
    1284,
    1334,
    1372,
    1410,
    1454,
    1498,
    1542,
    1598,
    1630,
    1674,
    1718,
    1756,
    1848,
    1892,
    1930,
    1968,
    2006,
    2056,
    2106,
    2162,
    2218,
    2274,
    2318,
    2362,
    2400,
    2438,
    2476,
    2526,
    2564
    };

static const MIDL_SERVER_INFO IUUEngine_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IUUEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IUUEngine_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IUUEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(69) _IUUEngineProxyVtbl = 
{
    &IUUEngine_ProxyInfo,
    &IID_IUUEngine,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IUUEngine::get_BracketPolicy */ ,
    (void *)-1 /* IUUEngine::put_BracketPolicy */ ,
    (void *)-1 /* IUUEngine::get_Desperate */ ,
    (void *)-1 /* IUUEngine::put_Desperate */ ,
    (void *)-1 /* IUUEngine::get_Dumb */ ,
    (void *)-1 /* IUUEngine::put_Dumb */ ,
    (void *)-1 /* IUUEngine::get_FastMode */ ,
    (void *)-1 /* IUUEngine::put_FastMode */ ,
    (void *)-1 /* IUUEngine::get_IgnoreReply */ ,
    (void *)-1 /* IUUEngine::put_IgnoreReply */ ,
    (void *)-1 /* IUUEngine::get_Overwrite */ ,
    (void *)-1 /* IUUEngine::put_Overwrite */ ,
    (void *)-1 /* IUUEngine::get_RemoveAfter */ ,
    (void *)-1 /* IUUEngine::put_RemoveAfter */ ,
    (void *)-1 /* IUUEngine::get_StrictMIME */ ,
    (void *)-1 /* IUUEngine::put_StrictMIME */ ,
    (void *)-1 /* IUUEngine::get_UseText */ ,
    (void *)-1 /* IUUEngine::put_UseText */ ,
    (void *)-1 /* IUUEngine::get_Verbose */ ,
    (void *)-1 /* IUUEngine::put_Verbose */ ,
    (void *)-1 /* IUUEngine::get_XFileAuto */ ,
    (void *)-1 /* IUUEngine::put_XFileAuto */ ,
    (void *)-1 /* IUUEngine::get_OutputPath */ ,
    (void *)-1 /* IUUEngine::put_OutputPath */ ,
    (void *)-1 /* IUUEngine::get_LibVersion */ ,
    (void *)-1 /* IUUEngine::put_LibVersion */ ,
    (void *)-1 /* IUUEngine::get_DFile */ ,
    (void *)-1 /* IUUEngine::put_DFile */ ,
    (void *)-1 /* IUUEngine::get_DFCount */ ,
    (void *)-1 /* IUUEngine::put_DFCount */ ,
    (void *)-1 /* IUUEngine::get_DFileFlags */ ,
    (void *)-1 /* IUUEngine::put_DFileFlags */ ,
    (void *)-1 /* IUUEngine::DLoad */ ,
    (void *)-1 /* IUUEngine::DFileTo */ ,
    (void *)-1 /* IUUEngine::get_LastMessage */ ,
    (void *)-1 /* IUUEngine::put_LastMessage */ ,
    (void *)-1 /* IUUEngine::get_DFileStatus */ ,
    (void *)-1 /* IUUEngine::put_DFileStatus */ ,
    (void *)-1 /* IUUEngine::FileFilter */ ,
    (void *)-1 /* IUUEngine::QuickDecode */ ,
    (void *)-1 /* IUUEngine::Reset */ ,
    (void *)-1 /* IUUEngine::get_DFileInfo */ ,
    (void *)-1 /* IUUEngine::put_DFileInfo */ ,
    (void *)-1 /* IUUEngine::DRemove */ ,
    (void *)-1 /* IUUEngine::Encode */ ,
    (void *)-1 /* IUUEngine::XFileAdd */ ,
    (void *)-1 /* IUUEngine::XFileDel */ ,
    (void *)-1 /* IUUEngine::get_TempFolder */ ,
    (void *)-1 /* IUUEngine::put_TempFolder */ ,
    (void *)-1 /* IUUEngine::LastOSError */ ,
    (void *)-1 /* IUUEngine::CRC32 */ ,
    (void *)-1 /* IUUEngine::ClipboardFile */ ,
    (void *)-1 /* IUUEngine::get_DFileDetail */ ,
    (void *)-1 /* IUUEngine::put_DFileDetail */ ,
    (void *)-1 /* IUUEngine::get_XFile */ ,
    (void *)-1 /* IUUEngine::put_XFile */ ,
    (void *)-1 /* IUUEngine::get_XFileCount */ ,
    (void *)-1 /* IUUEngine::put_XFileCount */ ,
    (void *)-1 /* IUUEngine::CreateTempName */ ,
    (void *)-1 /* IUUEngine::LoadBuffer */ ,
    (void *)-1 /* IUUEngine::get_StrictFilenames */ ,
    (void *)-1 /* IUUEngine::put_StrictFilenames */
};


static const PRPC_STUB_FUNCTION IUUEngine_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IUUEngineStubVtbl =
{
    &IID_IUUEngine,
    &IUUEngine_ServerInfo,
    69,
    &IUUEngine_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x5030118, /* MIDL Version 5.3.280 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_BracketPolicy */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x10 ),	/* 16 */
/* 14 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 26 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 30 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_BracketPolicy */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 64 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 66 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 68 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Desperate */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x9 ),	/* 9 */
/* 84 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0xe ),	/* 14 */
/* 90 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 106 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Desperate */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 124 */	NdrFcShort( 0x6 ),	/* 6 */
/* 126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 142 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 144 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 148 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Dumb */

/* 152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0xb ),	/* 11 */
/* 160 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 166 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 178 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 180 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 184 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 186 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Dumb */

/* 190 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 192 */	NdrFcLong( 0x0 ),	/* 0 */
/* 196 */	NdrFcShort( 0xc ),	/* 12 */
/* 198 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 202 */	NdrFcShort( 0x8 ),	/* 8 */
/* 204 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 206 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 216 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 218 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 220 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FastMode */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0xd ),	/* 13 */
/* 236 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x10 ),	/* 16 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 244 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 254 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 256 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 262 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FastMode */

/* 266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0xe ),	/* 14 */
/* 274 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 282 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 292 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 294 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 300 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IgnoreReply */

/* 304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0xf ),	/* 15 */
/* 312 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x10 ),	/* 16 */
/* 318 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 320 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IgnoreReply */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x10 ),	/* 16 */
/* 350 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 358 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 368 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 370 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 374 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 376 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Overwrite */

/* 380 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 382 */	NdrFcLong( 0x0 ),	/* 0 */
/* 386 */	NdrFcShort( 0x11 ),	/* 17 */
/* 388 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 392 */	NdrFcShort( 0x10 ),	/* 16 */
/* 394 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 396 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */
/* 402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 406 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 408 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 414 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Overwrite */

/* 418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x12 ),	/* 18 */
/* 426 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 432 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 434 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 452 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_RemoveAfter */

/* 456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x13 ),	/* 19 */
/* 464 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x10 ),	/* 16 */
/* 470 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 472 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 484 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 490 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_RemoveAfter */

/* 494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x14 ),	/* 20 */
/* 502 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 510 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 520 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 522 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 528 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StrictMIME */

/* 532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x15 ),	/* 21 */
/* 540 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x10 ),	/* 16 */
/* 546 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 548 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 558 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 560 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 566 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StrictMIME */

/* 570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x16 ),	/* 22 */
/* 578 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 584 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 586 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 596 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 598 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 602 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 604 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 606 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UseText */

/* 608 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 610 */	NdrFcLong( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x17 ),	/* 23 */
/* 616 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x10 ),	/* 16 */
/* 622 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 624 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 634 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 636 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 642 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UseText */

/* 646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x18 ),	/* 24 */
/* 654 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 658 */	NdrFcShort( 0x8 ),	/* 8 */
/* 660 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 662 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 672 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 674 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 678 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 680 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Verbose */

/* 684 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 686 */	NdrFcLong( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x19 ),	/* 25 */
/* 692 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x10 ),	/* 16 */
/* 698 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 700 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 710 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 712 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 716 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 718 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Verbose */

/* 722 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 724 */	NdrFcLong( 0x0 ),	/* 0 */
/* 728 */	NdrFcShort( 0x1a ),	/* 26 */
/* 730 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 736 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 738 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 748 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 750 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 754 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 756 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFileAuto */

/* 760 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 762 */	NdrFcLong( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x1b ),	/* 27 */
/* 768 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0x10 ),	/* 16 */
/* 774 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 776 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 786 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 788 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFileAuto */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x1c ),	/* 28 */
/* 806 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 814 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 824 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 826 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 828 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 830 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 832 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 834 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OutputPath */

/* 836 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 838 */	NdrFcLong( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x1d ),	/* 29 */
/* 844 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 848 */	NdrFcShort( 0x8 ),	/* 8 */
/* 850 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 852 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 854 */	NdrFcShort( 0x1 ),	/* 1 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 862 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 864 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 866 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 868 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 870 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 872 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OutputPath */

/* 874 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 876 */	NdrFcLong( 0x0 ),	/* 0 */
/* 880 */	NdrFcShort( 0x1e ),	/* 30 */
/* 882 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 888 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 890 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 894 */	NdrFcShort( 0x1 ),	/* 1 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 900 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 902 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 904 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LibVersion */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x1f ),	/* 31 */
/* 920 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 928 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 930 */	NdrFcShort( 0x1 ),	/* 1 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 938 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 940 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 942 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 944 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 946 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 948 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LibVersion */

/* 950 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 952 */	NdrFcLong( 0x0 ),	/* 0 */
/* 956 */	NdrFcShort( 0x20 ),	/* 32 */
/* 958 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 964 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 966 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x1 ),	/* 1 */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 976 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 978 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 980 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 982 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 984 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFile */

/* 988 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 990 */	NdrFcLong( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0x21 ),	/* 33 */
/* 996 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 998 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1000 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1002 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1004 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1006 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1014 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1016 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1018 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1020 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1022 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1024 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1028 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFile */

/* 1032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1040 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1042 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1046 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1048 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1060 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1062 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1064 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1066 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1068 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 1070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1072 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFCount */

/* 1076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x23 ),	/* 35 */
/* 1084 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0xe ),	/* 14 */
/* 1090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1092 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1104 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1106 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1110 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFCount */

/* 1114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1122 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1124 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1126 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1130 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1142 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1144 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1148 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileFlags */

/* 1152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1158 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1160 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1162 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1164 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1166 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1168 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1178 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1180 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1182 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1184 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1186 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1188 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1192 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileFlags */

/* 1196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1202 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1204 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1206 */	NdrFcShort( 0xe ),	/* 14 */
/* 1208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1222 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1224 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1226 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1228 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1230 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1236 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DLoad */

/* 1240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1248 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1252 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1254 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1256 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1260 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter toLoad */

/* 1266 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1268 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1270 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retVal */

/* 1272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1274 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1280 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DFileTo */

/* 1284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1292 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 1294 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1296 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1298 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 1300 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1304 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1312 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1314 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter outname */

/* 1316 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1318 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1320 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retVal */

/* 1322 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1324 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1330 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_LastMessage */

/* 1334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1340 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1342 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1348 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1350 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1352 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1360 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1362 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1364 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1368 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_LastMessage */

/* 1372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1378 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1380 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1386 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1388 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1398 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1400 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1402 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 1404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1406 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileStatus */

/* 1410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1418 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1420 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1424 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1426 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1428 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1438 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1440 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1442 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1444 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1446 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1450 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileStatus */

/* 1454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1462 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1464 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1468 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1470 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1482 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1484 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1486 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1488 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1490 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 1492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1494 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FileFilter */

/* 1498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1504 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1506 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1512 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1514 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 1516 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1518 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter inFile */

/* 1524 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1526 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1528 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter outFile */

/* 1530 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1532 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1534 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1536 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1538 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1540 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure QuickDecode */

/* 1542 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1544 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1548 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1550 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 1552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1554 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1556 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 1558 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1562 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter File2Decode */

/* 1568 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1570 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1572 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter OutputPath */

/* 1574 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1576 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1578 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter XFile */

/* 1580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1582 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 1586 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1588 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1592 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1594 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 1596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Reset */

/* 1598 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1600 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x2f ),	/* 47 */
/* 1606 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1610 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1612 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1614 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1622 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1626 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileInfo */

/* 1630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1638 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1640 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1646 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1656 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1658 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1660 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1662 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1664 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1666 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1668 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1670 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileInfo */

/* 1674 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1676 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1680 */	NdrFcShort( 0x31 ),	/* 49 */
/* 1682 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1684 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1686 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1688 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1690 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1694 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1700 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1702 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1704 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 1706 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1708 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1710 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 1712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1714 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DRemove */

/* 1718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x32 ),	/* 50 */
/* 1726 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1728 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1730 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1732 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1734 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 1744 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1746 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1748 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1752 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Encode */

/* 1756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x33 ),	/* 51 */
#ifndef _ALPHA_
/* 1764 */	NdrFcShort( 0xa8 ),	/* ia64 Stack size/offset = 168 */
#else
			NdrFcShort( 0x90 ),	/* axp64 Stack size/offset = 144 */
#endif
/* 1766 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1768 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1770 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0xb,		/* 11 */
/* 1772 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x63 ),	/* 99 */
/* 1778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter iname */

/* 1782 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1784 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1786 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter oname */

/* 1788 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1790 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1792 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter nameinfile */

/* 1794 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1796 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1798 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter encoding */

/* 1800 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1802 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1804 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter lines */

/* 1806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1808 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter headers */

/* 1812 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1814 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter destvar */

/* 1818 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1820 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
#else
			NdrFcShort( 0x38 ),	/* axp64 Stack size/offset = 56 */
#endif
/* 1822 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Parameter fromvar */

/* 1824 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1826 */	NdrFcShort( 0x60 ),	/* ia64 Stack size/offset = 96 */
#else
			NdrFcShort( 0x50 ),	/* axp64 Stack size/offset = 80 */
#endif
/* 1828 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Parameter subjectvar */

/* 1830 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 1832 */	NdrFcShort( 0x80 ),	/* ia64 Stack size/offset = 128 */
#else
			NdrFcShort( 0x68 ),	/* axp64 Stack size/offset = 104 */
#endif
/* 1834 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Parameter retVal */

/* 1836 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 1838 */	NdrFcShort( 0x98 ),	/* ia64 Stack size/offset = 152 */
#else
			NdrFcShort( 0x80 ),	/* axp64 Stack size/offset = 128 */
#endif
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 1844 */	NdrFcShort( 0xa0 ),	/* ia64 Stack size/offset = 160 */
#else
			NdrFcShort( 0x88 ),	/* axp64 Stack size/offset = 136 */
#endif
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure XFileAdd */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x34 ),	/* 52 */
/* 1856 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 1858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1862 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1864 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter toAdd */

/* 1874 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1876 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1878 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter retVal */

/* 1880 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1882 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1888 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure XFileDel */

/* 1892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x35 ),	/* 53 */
/* 1900 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1904 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1906 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1908 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retVal */

/* 1918 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1920 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1922 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1926 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_TempFolder */

/* 1930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x36 ),	/* 54 */
/* 1938 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1944 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1946 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1948 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1956 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1958 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1960 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_TempFolder */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x37 ),	/* 55 */
/* 1976 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1982 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1984 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1994 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1996 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 1998 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 2000 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2002 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2004 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LastOSError */

/* 2006 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2008 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2012 */	NdrFcShort( 0x38 ),	/* 56 */
/* 2014 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2018 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2020 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2022 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2024 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2030 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter errNo */

/* 2032 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2034 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter errText */

/* 2038 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 2040 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2042 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter gotErr */

/* 2044 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2046 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2050 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2052 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CRC32 */

/* 2056 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2058 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x39 ),	/* 57 */
/* 2064 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2068 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2070 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2072 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileName */

/* 2082 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2084 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2086 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter crc */

/* 2088 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2090 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 2094 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2096 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2100 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2102 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ClipboardFile */

/* 2106 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2108 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x3a ),	/* 58 */
/* 2114 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2116 */	NdrFcShort( 0xe ),	/* 14 */
/* 2118 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2120 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2122 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2126 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter hWnd */

/* 2132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2134 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Filename */

/* 2138 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2140 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2142 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Parameter CFMode */

/* 2144 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2146 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2148 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter retVal */

/* 2150 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2152 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2158 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DFileDetail */

/* 2162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2168 */	NdrFcShort( 0x3b ),	/* 59 */
/* 2170 */	NdrFcShort( 0x30 ),	/* ia64, axp64 Stack size/offset = 48 */
/* 2172 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2176 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 2178 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2180 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 2188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2190 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2192 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter itemno */

/* 2194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2196 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2198 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter subscr */

/* 2200 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2202 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2204 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2206 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
/* 2208 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2210 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 2212 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2214 */	NdrFcShort( 0x28 ),	/* ia64, axp64 Stack size/offset = 40 */
/* 2216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DFileDetail */

/* 2218 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2220 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2224 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2226 */	NdrFcShort( 0x40 ),	/* ia64, axp64 Stack size/offset = 64 */
/* 2228 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2230 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2232 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 2234 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 2244 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2246 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2248 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter itemno */

/* 2250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2252 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2254 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter subscr */

/* 2256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2258 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2260 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2262 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2264 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2266 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Return value */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0x38 ),	/* ia64, axp64 Stack size/offset = 56 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFile */

/* 2274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x3d ),	/* 61 */
/* 2282 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2284 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2288 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2290 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 2300 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2302 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2304 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 2306 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2308 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2310 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2314 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFile */

/* 2318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2324 */	NdrFcShort( 0x3e ),	/* 62 */
/* 2326 */	NdrFcShort( 0x20 ),	/* ia64, axp64 Stack size/offset = 32 */
/* 2328 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2332 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2334 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2338 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter row */

/* 2344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2346 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2348 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter newVal */

/* 2350 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2352 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2354 */	NdrFcShort( 0x36 ),	/* Type Offset=54 */

	/* Return value */

/* 2356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2358 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_XFileCount */

/* 2362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2368 */	NdrFcShort( 0x3f ),	/* 63 */
/* 2370 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2374 */	NdrFcShort( 0xe ),	/* 14 */
/* 2376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2378 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2388 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2390 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2392 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_XFileCount */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2408 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2410 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2414 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2416 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 2426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2428 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2430 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2434 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateTempName */

/* 2438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x41 ),	/* 65 */
/* 2446 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2452 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2454 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2456 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter tempFilename */

/* 2464 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 2466 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2468 */	NdrFcShort( 0x28 ),	/* Type Offset=40 */

	/* Return value */

/* 2470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2472 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadBuffer */

/* 2476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x42 ),	/* 66 */
#ifndef _ALPHA_
/* 2484 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
#else
			NdrFcShort( 0x38 ),	/* axp64 Stack size/offset = 56 */
#endif
/* 2486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2488 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2490 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2492 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2494 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2496 */	NdrFcShort( 0x20 ),	/* 32 */
/* 2498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter buffer */

/* 2502 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 2504 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
#else
			NdrFcShort( 0x8 ),	/* axp64 Stack size/offset = 8 */
#endif
/* 2506 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Parameter tempName */

/* 2508 */	NdrFcShort( 0x6113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=24 */
#ifndef _ALPHA_
/* 2510 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
#else
			NdrFcShort( 0x20 ),	/* axp64 Stack size/offset = 32 */
#endif
/* 2512 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Parameter retVal */

/* 2514 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 2516 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
#else
			NdrFcShort( 0x28 ),	/* axp64 Stack size/offset = 40 */
#endif
/* 2518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 2522 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
#else
			NdrFcShort( 0x30 ),	/* axp64 Stack size/offset = 48 */
#endif
/* 2524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_StrictFilenames */

/* 2526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x43 ),	/* 67 */
/* 2534 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2540 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2542 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 2552 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2554 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2560 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_StrictFilenames */

/* 2564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2570 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2572 */	NdrFcShort( 0x18 ),	/* ia64, axp64 Stack size/offset = 24 */
/* 2574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2578 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2580 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 2590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2592 */	NdrFcShort( 0x8 ),	/* ia64, axp64 Stack size/offset = 8 */
/* 2594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2598 */	NdrFcShort( 0x10 ),	/* ia64, axp64 Stack size/offset = 16 */
/* 2600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 12 */	NdrFcShort( 0x1c ),	/* Offset= 28 (40) */
/* 14 */	
			0x13, 0x0,	/* FC_OP */
/* 16 */	NdrFcShort( 0xe ),	/* Offset= 14 (30) */
/* 18 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 20 */	NdrFcShort( 0x2 ),	/* 2 */
/* 22 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 24 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 26 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 28 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 30 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 32 */	NdrFcShort( 0x8 ),	/* 8 */
/* 34 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (18) */
/* 36 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 38 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 40 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 42 */	NdrFcShort( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (14) */
/* 50 */	
			0x12, 0x0,	/* FC_UP */
/* 52 */	NdrFcShort( 0xffffffea ),	/* Offset= -22 (30) */
/* 54 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x8 ),	/* 8 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (50) */
/* 64 */	
			0x12, 0x0,	/* FC_UP */
/* 66 */	NdrFcShort( 0x384 ),	/* Offset= 900 (966) */
/* 68 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 70 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 72 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 74 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 76 */	NdrFcShort( 0x2 ),	/* Offset= 2 (78) */
/* 78 */	NdrFcShort( 0x10 ),	/* 16 */
/* 80 */	NdrFcShort( 0x2b ),	/* 43 */
/* 82 */	NdrFcLong( 0x3 ),	/* 3 */
/* 86 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 88 */	NdrFcLong( 0x11 ),	/* 17 */
/* 92 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 94 */	NdrFcLong( 0x2 ),	/* 2 */
/* 98 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 100 */	NdrFcLong( 0x4 ),	/* 4 */
/* 104 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 106 */	NdrFcLong( 0x5 ),	/* 5 */
/* 110 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 112 */	NdrFcLong( 0xb ),	/* 11 */
/* 116 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 118 */	NdrFcLong( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 124 */	NdrFcLong( 0x6 ),	/* 6 */
/* 128 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (342) */
/* 130 */	NdrFcLong( 0x7 ),	/* 7 */
/* 134 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 136 */	NdrFcLong( 0x8 ),	/* 8 */
/* 140 */	NdrFcShort( 0xffffffa6 ),	/* Offset= -90 (50) */
/* 142 */	NdrFcLong( 0xd ),	/* 13 */
/* 146 */	NdrFcShort( 0xca ),	/* Offset= 202 (348) */
/* 148 */	NdrFcLong( 0x9 ),	/* 9 */
/* 152 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (366) */
/* 154 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 158 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (384) */
/* 160 */	NdrFcLong( 0x24 ),	/* 36 */
/* 164 */	NdrFcShort( 0x2da ),	/* Offset= 730 (894) */
/* 166 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 170 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (894) */
/* 172 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 176 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (898) */
/* 178 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 182 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (902) */
/* 184 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 188 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (906) */
/* 190 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 194 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (910) */
/* 196 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 200 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (914) */
/* 202 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 206 */	NdrFcShort( 0x2b8 ),	/* Offset= 696 (902) */
/* 208 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 212 */	NdrFcShort( 0x2b6 ),	/* Offset= 694 (906) */
/* 214 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 218 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (918) */
/* 220 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 224 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (914) */
/* 226 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 230 */	NdrFcShort( 0x2b4 ),	/* Offset= 692 (922) */
/* 232 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 236 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (926) */
/* 238 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 242 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (930) */
/* 244 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 248 */	NdrFcShort( 0x2ae ),	/* Offset= 686 (934) */
/* 250 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 254 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (938) */
/* 256 */	NdrFcLong( 0x10 ),	/* 16 */
/* 260 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 262 */	NdrFcLong( 0x12 ),	/* 18 */
/* 266 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 268 */	NdrFcLong( 0x13 ),	/* 19 */
/* 272 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 274 */	NdrFcLong( 0x16 ),	/* 22 */
/* 278 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 280 */	NdrFcLong( 0x17 ),	/* 23 */
/* 284 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 286 */	NdrFcLong( 0xe ),	/* 14 */
/* 290 */	NdrFcShort( 0x290 ),	/* Offset= 656 (946) */
/* 292 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 296 */	NdrFcShort( 0x296 ),	/* Offset= 662 (958) */
/* 298 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 302 */	NdrFcShort( 0x294 ),	/* Offset= 660 (962) */
/* 304 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 308 */	NdrFcShort( 0x252 ),	/* Offset= 594 (902) */
/* 310 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 314 */	NdrFcShort( 0x250 ),	/* Offset= 592 (906) */
/* 316 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 320 */	NdrFcShort( 0x24a ),	/* Offset= 586 (906) */
/* 322 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 326 */	NdrFcShort( 0x244 ),	/* Offset= 580 (906) */
/* 328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* Offset= 0 (332) */
/* 334 */	NdrFcLong( 0x1 ),	/* 1 */
/* 338 */	NdrFcShort( 0x0 ),	/* Offset= 0 (338) */
/* 340 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (339) */
/* 342 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 346 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 348 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 360 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 362 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 364 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 366 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 368 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 380 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 382 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 384 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 386 */	NdrFcShort( 0x2 ),	/* Offset= 2 (388) */
/* 388 */	
			0x12, 0x0,	/* FC_UP */
/* 390 */	NdrFcShort( 0x1e6 ),	/* Offset= 486 (876) */
/* 392 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 394 */	NdrFcShort( 0x20 ),	/* 32 */
/* 396 */	NdrFcShort( 0xa ),	/* 10 */
/* 398 */	NdrFcLong( 0x8 ),	/* 8 */
/* 402 */	NdrFcShort( 0x50 ),	/* Offset= 80 (482) */
/* 404 */	NdrFcLong( 0xd ),	/* 13 */
/* 408 */	NdrFcShort( 0x70 ),	/* Offset= 112 (520) */
/* 410 */	NdrFcLong( 0x9 ),	/* 9 */
/* 414 */	NdrFcShort( 0x90 ),	/* Offset= 144 (558) */
/* 416 */	NdrFcLong( 0xc ),	/* 12 */
/* 420 */	NdrFcShort( 0xb0 ),	/* Offset= 176 (596) */
/* 422 */	NdrFcLong( 0x24 ),	/* 36 */
/* 426 */	NdrFcShort( 0x104 ),	/* Offset= 260 (686) */
/* 428 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 432 */	NdrFcShort( 0x120 ),	/* Offset= 288 (720) */
/* 434 */	NdrFcLong( 0x10 ),	/* 16 */
/* 438 */	NdrFcShort( 0x13a ),	/* Offset= 314 (752) */
/* 440 */	NdrFcLong( 0x2 ),	/* 2 */
/* 444 */	NdrFcShort( 0x150 ),	/* Offset= 336 (780) */
/* 446 */	NdrFcLong( 0x3 ),	/* 3 */
/* 450 */	NdrFcShort( 0x166 ),	/* Offset= 358 (808) */
/* 452 */	NdrFcLong( 0x14 ),	/* 20 */
/* 456 */	NdrFcShort( 0x17c ),	/* Offset= 380 (836) */
/* 458 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (457) */
/* 460 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 470 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 474 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 476 */	
			0x12, 0x0,	/* FC_UP */
/* 478 */	NdrFcShort( 0xfffffe40 ),	/* Offset= -448 (30) */
/* 480 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 482 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 484 */	NdrFcShort( 0x10 ),	/* 16 */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x6 ),	/* Offset= 6 (494) */
/* 490 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 492 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 494 */	
			0x11, 0x0,	/* FC_RP */
/* 496 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (460) */
/* 498 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 508 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 512 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 514 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 516 */	NdrFcShort( 0xffffff58 ),	/* Offset= -168 (348) */
/* 518 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 520 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 522 */	NdrFcShort( 0x10 ),	/* 16 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x6 ),	/* Offset= 6 (532) */
/* 528 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 530 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 532 */	
			0x11, 0x0,	/* FC_RP */
/* 534 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (498) */
/* 536 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 540 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 546 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 550 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 552 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 554 */	NdrFcShort( 0xffffff44 ),	/* Offset= -188 (366) */
/* 556 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 558 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 560 */	NdrFcShort( 0x10 ),	/* 16 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x6 ),	/* Offset= 6 (570) */
/* 566 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 568 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 570 */	
			0x11, 0x0,	/* FC_RP */
/* 572 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (536) */
/* 574 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 578 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 584 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 588 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 590 */	
			0x12, 0x0,	/* FC_UP */
/* 592 */	NdrFcShort( 0x176 ),	/* Offset= 374 (966) */
/* 594 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 596 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 598 */	NdrFcShort( 0x10 ),	/* 16 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x6 ),	/* Offset= 6 (608) */
/* 604 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 606 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 608 */	
			0x11, 0x0,	/* FC_RP */
/* 610 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (574) */
/* 612 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 614 */	NdrFcLong( 0x2f ),	/* 47 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 622 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 624 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 626 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 628 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 630 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 632 */	NdrFcShort( 0x1 ),	/* 1 */
/* 634 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 636 */	NdrFcShort( 0x4 ),	/* 4 */
/* 638 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 640 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 642 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 644 */	NdrFcShort( 0x18 ),	/* 24 */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	NdrFcShort( 0xc ),	/* Offset= 12 (660) */
/* 650 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 652 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 654 */	NdrFcShort( 0xffffffd6 ),	/* Offset= -42 (612) */
/* 656 */	0x39,		/* FC_ALIGNM8 */
			0x36,		/* FC_POINTER */
/* 658 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 660 */	
			0x12, 0x0,	/* FC_UP */
/* 662 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (630) */
/* 664 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 674 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 678 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 680 */	
			0x12, 0x0,	/* FC_UP */
/* 682 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (642) */
/* 684 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 686 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 688 */	NdrFcShort( 0x10 ),	/* 16 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	NdrFcShort( 0x6 ),	/* Offset= 6 (698) */
/* 694 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 696 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 698 */	
			0x11, 0x0,	/* FC_RP */
/* 700 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (664) */
/* 702 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 706 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 708 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 710 */	NdrFcShort( 0x10 ),	/* 16 */
/* 712 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 714 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 716 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (702) */
			0x5b,		/* FC_END */
/* 720 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x20 ),	/* 32 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0xa ),	/* Offset= 10 (736) */
/* 728 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 730 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 732 */	0x0,		/* 0 */
			NdrFcShort( 0xffffffe7 ),	/* Offset= -25 (708) */
			0x5b,		/* FC_END */
/* 736 */	
			0x11, 0x0,	/* FC_RP */
/* 738 */	NdrFcShort( 0xffffff10 ),	/* Offset= -240 (498) */
/* 740 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 742 */	NdrFcShort( 0x1 ),	/* 1 */
/* 744 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 750 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 752 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 754 */	NdrFcShort( 0x10 ),	/* 16 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x6 ),	/* Offset= 6 (764) */
/* 760 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 762 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 764 */	
			0x12, 0x0,	/* FC_UP */
/* 766 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (740) */
/* 768 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 770 */	NdrFcShort( 0x2 ),	/* 2 */
/* 772 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 778 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 780 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 782 */	NdrFcShort( 0x10 ),	/* 16 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x6 ),	/* Offset= 6 (792) */
/* 788 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 790 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 792 */	
			0x12, 0x0,	/* FC_UP */
/* 794 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (768) */
/* 796 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 798 */	NdrFcShort( 0x4 ),	/* 4 */
/* 800 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 806 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 808 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 810 */	NdrFcShort( 0x10 ),	/* 16 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x6 ),	/* Offset= 6 (820) */
/* 816 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 818 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 820 */	
			0x12, 0x0,	/* FC_UP */
/* 822 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (796) */
/* 824 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 834 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 836 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 838 */	NdrFcShort( 0x10 ),	/* 16 */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	NdrFcShort( 0x6 ),	/* Offset= 6 (848) */
/* 844 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 846 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 848 */	
			0x12, 0x0,	/* FC_UP */
/* 850 */	NdrFcShort( 0xffffffe6 ),	/* Offset= -26 (824) */
/* 852 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 858 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 860 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 862 */	NdrFcShort( 0x8 ),	/* 8 */
/* 864 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 866 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 868 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 870 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 872 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (852) */
/* 874 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 876 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x38 ),	/* 56 */
/* 880 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (860) */
/* 882 */	NdrFcShort( 0x0 ),	/* Offset= 0 (882) */
/* 884 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 886 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 888 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 890 */	0x4,		/* 4 */
			NdrFcShort( 0xfffffe0d ),	/* Offset= -499 (392) */
			0x5b,		/* FC_END */
/* 894 */	
			0x12, 0x0,	/* FC_UP */
/* 896 */	NdrFcShort( 0xffffff02 ),	/* Offset= -254 (642) */
/* 898 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 900 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 902 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 904 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 906 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 908 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 910 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 912 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 914 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 916 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 918 */	
			0x12, 0x0,	/* FC_UP */
/* 920 */	NdrFcShort( 0xfffffdbe ),	/* Offset= -578 (342) */
/* 922 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 924 */	NdrFcShort( 0xfffffc96 ),	/* Offset= -874 (50) */
/* 926 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 928 */	NdrFcShort( 0xfffffdbc ),	/* Offset= -580 (348) */
/* 930 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 932 */	NdrFcShort( 0xfffffdca ),	/* Offset= -566 (366) */
/* 934 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 936 */	NdrFcShort( 0xfffffdd8 ),	/* Offset= -552 (384) */
/* 938 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 940 */	NdrFcShort( 0x2 ),	/* Offset= 2 (942) */
/* 942 */	
			0x12, 0x0,	/* FC_UP */
/* 944 */	NdrFcShort( 0x16 ),	/* Offset= 22 (966) */
/* 946 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 948 */	NdrFcShort( 0x10 ),	/* 16 */
/* 950 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 952 */	0x1,		/* FC_BYTE */
			0x38,		/* FC_ALIGNM4 */
/* 954 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 956 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 958 */	
			0x12, 0x0,	/* FC_UP */
/* 960 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (946) */
/* 962 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 964 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 966 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 968 */	NdrFcShort( 0x20 ),	/* 32 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x0 ),	/* Offset= 0 (972) */
/* 974 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 976 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 978 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 980 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 982 */	NdrFcShort( 0xfffffc6e ),	/* Offset= -914 (68) */
/* 984 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 986 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 988 */	NdrFcShort( 0x1 ),	/* 1 */
/* 990 */	NdrFcShort( 0x18 ),	/* 24 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0xfffffc5e ),	/* Offset= -930 (64) */
/* 996 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 998 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1004) */
/* 1000 */	
			0x13, 0x0,	/* FC_OP */
/* 1002 */	NdrFcShort( 0xffffffdc ),	/* Offset= -36 (966) */
/* 1004 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1006 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1000) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _UudATL_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IUUEngineProxyVtbl,
    0
};

const CInterfaceStubVtbl * _UudATL_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IUUEngineStubVtbl,
    0
};

PCInterfaceName const _UudATL_InterfaceNamesList[] = 
{
    "IUUEngine",
    0
};

const IID *  _UudATL_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _UudATL_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _UudATL, pIID, n)

int __stdcall _UudATL_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_UudATL_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo UudATL_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _UudATL_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _UudATL_StubVtblList,
    (const PCInterfaceName * ) & _UudATL_InterfaceNamesList,
    (const IID ** ) & _UudATL_BaseIIDList,
    & _UudATL_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};


#endif /* defined(_M_IA64) || defined(_M_AXP64)*/

