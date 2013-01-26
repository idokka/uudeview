uudeview
========

Multipart UU, XX, and Base64 encoding and decoding for Windows

UUDeview is a program that will help you to transmit and receive
binary files over the Net. It includes both an encoder and a decoder.
The decoder automatically detects the type of encoding used, offering
MIME Base64, yEnc, and BinHex as well as the popular uuencoding and
the less frequently used xxencoding methods. The encoder runs the
other way around and encodes a binary file for transmission by e-mail
or over the newsgroups. 

The decoder is particularly powerful; it was designed to fit the needs
of news readers. To be precise, it is a smart multi-part multi-file
decoder. You simply save a bunch of articles from your newsreader into
a single or into multiple files, and then fire up UUDeview. You do not
need to edit the article files at all.  


The source
==========

The repository is broken down into three source trees:

- linux: Frank Pilhofer's original UUDeview command line source. This
         was the basis of all the other UUDeview variants
         
- uudeview: The 32-bit UUDeview Windows application, the "heavy" UUDeview
            ActiveX control, and the "lightweight" UUDeview ATL COM control
            
- uudeview_dll: 16- and 32-bit Windows ports of the UUDeview engine in a DLL

There are dependencies between the subfolders in both of the Windows trees, so
it's probably best to stick with the directory layout in the repository.

For more information please visit the UUDeview web site:

http://www.miken.com/uud

and the UUDeview Developers page:

http://www.miken.com/uud/developer/index.htm
