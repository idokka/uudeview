; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=EncodeDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Uud32.h"

ClassCount=16
Class1=CUud32App
Class2=CUud32Dlg
Class3=CAboutDlg

ResourceCount=11
Resource1=IDD_DECODEOPT
Resource2=IDR_MAINFRAME
Resource3=IDD_DEBUGDIALOG
Class4=DecodeDlg
Resource4=IDD_UUD32_DIALOG
Class5=EncodeDlg
Resource5=IDD_LAUNCHDIALOG
Class6=GetOutputPath
Class7=DecodeOptions
Resource6=IDD_ENCODE
Class8=InfoDialog
Class9=MyListBox
Class10=MikeNButton
Class11=MikeNListCtrl
Resource7=IDD_INFODIALOG
Class12=DebugDialog
Resource8=IDD_DECODE
Class13=RenOutFile
Resource9=IDD_RENAMEDIALOG
Class14=LaunchDialog
Class15=CSizeDialog
Resource10=IDD_ABOUTBOX
Class16=Engine
Resource11=IDR_ACCEL

[CLS:CUud32App]
Type=0
HeaderFile=Uud32.h
ImplementationFile=Uud32.cpp
Filter=N
LastObject=CUud32App
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CUud32Dlg]
Type=0
HeaderFile=Uud32Dlg.h
ImplementationFile=Uud32Dlg.cpp
Filter=D
LastObject=CUud32Dlg
BaseClass=CSizeDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=aboutbox.h
ImplementationFile=aboutbox.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_UUD32ACXCTRL

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDOK,button,1342373889
Control2=IDC_ABOUTBMP,static,1342177294
Control3=IDC_ABOUTDLL,static,1342308353

[DLG:IDD_UUD32_DIALOG]
Type=1
Class=CUud32Dlg
ControlCount=5
Control1=IDC_TAB2,SysTabControl32,1342242816
Control2=IDC_GETHELP,button,1342242816
Control3=IDC_ABOUTBUTTON,button,1342242816
Control4=IDCANCEL,button,1342242816
Control5=IDC_DEBUGCLEARBUTTON,button,1073807360

[DLG:IDD_DECODE]
Type=1
Class=DecodeDlg
ControlCount=20
Control1=IDC_STATIC,static,1342308352
Control2=IDC_DECODELIST,listbox,1352730883
Control3=IDC_DECODEPATHBROWSE,button,1342242816
Control4=IDC_TOLABEL,static,1342308352
Control5=IDC_DECODEPATH,combobox,1344340034
Control6=IDC_DECODEGO,button,1342242816
Control7=IDC_DECODEOUTPUTLIST,SysListView32,1350648593
Control8=IDC_DECODEOPTIONS,button,1342242816
Control9=IDC_CLEARDECODE,button,1342242816
Control10=IDC_ADDDECODE,button,1342242816
Control11=IDC_ADDCLIPBOARD,button,1342242816
Control12=IDC_REMOVEDECODE,button,1342242816
Control13=IDC_DECODEINFO,button,1342242816
Control14=IDC_RENAMEDECODEOUT,button,1342242816
Control15=IDC_REMOVEDECODEOUT,button,1342242816
Control16=IDC_DECINFOBOX,button,1342177287
Control17=IDC_INFO1,edit,1350633600
Control18=IDC_INFO2,edit,1350633600
Control19=IDC_DECODEPROGRESS,msctls_progress32,1082130432
Control20=IDC_DEC_CH,button,1342242880

[CLS:DecodeDlg]
Type=0
HeaderFile=DecodeDlg.h
ImplementationFile=DecodeDlg.cpp
BaseClass=CSizeDialog
Filter=D
LastObject=DecodeDlg
VirtualFilter=dWC

[DLG:IDD_ENCODE]
Type=1
Class=EncodeDlg
ControlCount=22
Control1=IDC_ENCSRC,edit,1350631552
Control2=IDC_ENCSRCBROWSE,button,1342242816
Control3=IDC_ENC64,button,1342308361
Control4=IDC_ENCUU,button,1342177289
Control5=IDC_ENCXX,button,1342177289
Control6=IDC_ENCYY,button,1342177289
Control7=IDC_ENCODEGO,button,1342242816
Control8=IDC_ENCSINGLE,button,1342308361
Control9=IDC_ENCBRK,button,1342177289
Control10=IDC_ENCCLIP,button,1342177289
Control11=IDC_ENCDEST,edit,1350631552
Control12=IDC_ENCPATH,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_ENCINFOFRAME,button,1342177287
Control15=IDC_ENCINFO,edit,1350633600
Control16=IDC_ENCPROG,msctls_progress32,1350565888
Control17=IDC_SCHEMEFRAME,button,1342177287
Control18=IDC_OMFRAME,button,1342177287
Control19=IDC_ENCLINES,edit,1350639744
Control20=IDC_LABELLINES,static,1342177280
Control21=IDC_STATIC,static,1342308352
Control22=IDC_ENCGETHELP,button,1342242880

[CLS:EncodeDlg]
Type=0
HeaderFile=EncodeDlg.h
ImplementationFile=EncodeDlg.cpp
BaseClass=CSizeDialog
Filter=D
LastObject=IDC_ENCYY
VirtualFilter=dWC

[CLS:GetOutputPath]
Type=0
HeaderFile=GetOutputPath.h
ImplementationFile=GetOutputPath.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_DLCOMBO

[DLG:IDD_DECODEOPT]
Type=1
Class=DecodeOptions
ControlCount=35
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_FASTMODE,button,1342242819
Control4=IDC_POE,button,1342242819
Control5=IDC_DUMBMODE,button,1342242819
Control6=IDC_DEBUG,button,1342242819
Control7=IDC_BRACKPOL,button,1342242819
Control8=IDC_HIDETOOLTIPS,button,1342242819
Control9=IDC_DESP,button,1342242819
Control10=IDC_ASSOC,button,1342242822
Control11=IDC_IGNREPLY,button,1342242819
Control12=IDC_ETEXT,button,1342242819
Control13=IDC_ENOPROMPT,button,1342242819
Control14=IDC_STRICT,button,1342242819
Control15=IDC_LNOPROMPT,button,1342242819
Control16=IDC_PRESERVECASE,button,1342242819
Control17=IDC_DNOPROMPT,button,1342242819
Control18=IDC_OUTFMODEP,button,1342308361
Control19=IDC_OUTFMODEO,button,1342177289
Control20=IDC_OUTFMODEA,button,1342177289
Control21=IDC_RECYCLEINP,button,1342242819
Control22=IDC_DECOPTDEFAULT,button,1342242816
Control23=IDC_DECOPTHELP,button,1342242816
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,button,1342177287
Control26=IDC_STATIC,button,1342177287
Control27=IDC_STATIC,button,1342177287
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,button,1342177287
Control31=IDC_WINTEMP,button,1342308361
Control32=IDC_OTHERTEMP,button,1342177289
Control33=IDC_TEMPFOLDER,edit,1484849280
Control34=IDC_BROWSETEMP,button,1476460544
Control35=IDC_STRICTFILENAMES,button,1342242819

[CLS:DecodeOptions]
Type=0
HeaderFile=DecodeOptions.h
ImplementationFile=DecodeOptions.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=DecodeOptions

[DLG:IDD_INFODIALOG]
Type=1
Class=InfoDialog
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDC_INFOHELP,button,1342242816
Control3=IDC_INFOTITLE,edit,1350633600
Control4=IDC_INFOEDIT,edit,1352730628

[CLS:InfoDialog]
Type=0
HeaderFile=InfoDialog.h
ImplementationFile=InfoDialog.cpp
BaseClass=CSizeDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_INFOHELP

[CLS:MyListBox]
Type=0
HeaderFile=MyListBox.h
ImplementationFile=MyListBox.cpp
BaseClass=CListBox
Filter=W
VirtualFilter=bWC
LastObject=CMD_ALL

[CLS:MikeNButton]
Type=0
HeaderFile=MikeNButton.h
ImplementationFile=MikeNButton.cpp
BaseClass=CButton
Filter=W
LastObject=MikeNButton
VirtualFilter=BWC

[CLS:MikeNListCtrl]
Type=0
HeaderFile=MikeNListCtrl.h
ImplementationFile=MikeNListCtrl.cpp
BaseClass=CListCtrl
Filter=W
VirtualFilter=FWC
LastObject=MikeNListCtrl

[DLG:IDD_DEBUGDIALOG]
Type=1
Class=DebugDialog
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_CLEARDEBUG,button,1342242816
Control3=IDC_DEB2CLIP,button,1342242816
Control4=IDC_INFOHELP,button,1342242816
Control5=IDC_INFODEBUG,edit,1353779204

[CLS:DebugDialog]
Type=0
HeaderFile=DebugDialog.h
ImplementationFile=DebugDialog.cpp
BaseClass=CSizeDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_INFOHELP

[DLG:IDD_RENAMEDIALOG]
Type=1
Class=RenOutFile
ControlCount=8
Control1=IDC_RENFILENAME,edit,1350631552
Control2=IDC_ANUMBER,button,1342242816
Control3=IDC_RENBUTTON,button,1476460544
Control4=IDC_RENOWBUTTON,button,1342242817
Control5=IDC_RENSKIPBUTTON,button,1342242816
Control6=IDC_RENREST,button,1476460544
Control7=IDC_RENOUTCANCEL,button,1342242816
Control8=IDC_STATIC,static,1342177281

[CLS:RenOutFile]
Type=0
HeaderFile=RenOutFile.h
ImplementationFile=RenOutFile.cpp
BaseClass=CDialog
Filter=W
LastObject=ID_CONTEXT_HELP
VirtualFilter=dWC

[DLG:IDD_LAUNCHDIALOG]
Type=1
Class=LaunchDialog
ControlCount=10
Control1=IDC_LAUNCHLIST,combobox,1344339970
Control2=IDC_LAUNCHBROWSE,button,1342177280
Control3=IDC_SKIPLAUNCH,button,1342242819
Control4=IDOK,button,1342177280
Control5=IDC_LAUNCHALL,button,1342177280
Control6=IDCANCEL,button,1342177280
Control7=IDC_LAUNCHHELP,button,1342177280
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_LAUNCHNAME,edit,1350633600

[CLS:LaunchDialog]
Type=0
HeaderFile=LaunchDialog.h
ImplementationFile=LaunchDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SKIPLAUNCH

[CLS:CSizeDialog]
Type=0
HeaderFile=SizeDialog.h
ImplementationFile=SizeDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CSizeDialog

[ACL:IDR_ACCEL]
Type=1
Class=?
Command1=ID_HELP
Command2=ID_CONTEXT_HELP
CommandCount=2

[CLS:Engine]
Type=0
HeaderFile=Engine.h
ImplementationFile=Engine.cpp
BaseClass=CWinThread
Filter=N
LastObject=Engine

