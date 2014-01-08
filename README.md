ofDxSharedTextureExample
========================

This example shows how to use the the WGL_NV_DX_interop extension (see [here](http://developer.download.nvidia.com/opengl/specs/WGL_NV_DX_interop.txt)) to share the content of a D3D texture with openFrameworks.
This is not an end in itself but should be seen as a stepping stone to achieve more advanced goals (accelerated rendering using  windows technology, hardware video decoding using Media Foundation, ...). Indeed most of the time the proper way of accessing hardware accelerated capabilities (DXVA, Windows H264 decoder, ...) you need to go through a Direct3D surface which has hindered the development of hardware accelerated path for openGL applications in Windows.

#Prerequisites 

This extension is supported by the latest release of GLEW but not the one shipped with openFrameworks.
Prior to compiling this example you need to replace the GLEW headers and libraries from your of\libs foler by the one present in the lib folder of this repository.

On top of that this addon is built against the Direct X SDK of June 2010. You'll need to install it to have the headers required for compiling the example. At the time of writing, you can download it on the [Microsoft website](http://www.microsoft.com/en-us/download/details.aspx?id=6812)


#Description of the example

This application first creates a D3D window in a spearate thread, and ensure synchronization between the two threads.
To share and object you need to :

- Get a shared handle for the D3DDevice (in your openGL context) using `wglDXOpenDeviceNV`
- Get a shared handle on the ressource you want to use, through `wglDXRegisterObjectNV`
- Lock and Unlock the ressource when you use it  with `wglDXLockObjectsNV` and `wglDXLockObjectsNV`
- Cleanup when you're done with `wglDXUnregisterObjectNV` and `wglDXCloseDeviceNV`

This extension can be used with D3D9, D3D10 and D3D11.


#Compatibility 

This is an NVIDIA extension but AMD/ATI cards claims they support it was well, even though sometimes it gets more finicky.
Feedbacks on working/not working cards and drivers are more than welcomed.




