
UudATLps.dll: dlldata.obj UudATL_p.obj UudATL_i.obj
	link /dll /out:UudATLps.dll /def:UudATLps.def /entry:DllMain dlldata.obj UudATL_p.obj UudATL_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del UudATLps.dll
	@del UudATLps.lib
	@del UudATLps.exp
	@del dlldata.obj
	@del UudATL_p.obj
	@del UudATL_i.obj
