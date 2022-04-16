# TerrainGenerator

This is a sample program using Qt, VTK and Cmake, to demonstrate the Diamond-Square algorithm.

(To try this program, just run the 'Terrain Generator.exe' in the build folder.)

instalation instructions for mingw/cmake/vtk/qt toolchain:

download cmake "cmake-3.7.0-rc2-win64-x64" installer package 
	- follow basic installation 
	- select add to path radio button
	
download Qt "qt-opensource-windows-x86-mingw492-5.5.1" installer package
	- follow basic installation 
	- make sure it is added to your path as "C:\Qt\Qt5.5.1\5.5\mingw492_32\bin" (or where that is inatalled)
	
download zipped "VTK-6.3.0" files
	- unzip and place in location with no spaces in filepath
	- create a build folder in the VTK-6.3.0 directory "~\VTK-6.3.0\VTK-6.3.0\VTKBuild"
	
Use the MinGW included with Qt (C:\Qt\Qt5.5.1\Tools\mingw492_32)

(you also need python installed, either 2 or 3)(also have it in your path)

open cmake

	in the "Where to build your binaries" field, enter the filepath of the build folder you created in VTK
	in the "Where is the source code" field enter the unzipped VTK folder with the Accelerators, Charts, Cmake, ... folders in it.

	press configure

	select "MinGW Makefiles", and "Use default native compilers"

	press configure
	
		uncheck "build shared libs"
		change cmake build type to "Release"
		check "VTK group Qt"
		make sure thread model is win32 (if this doesn't work you may have to remove this value and leave it blank)
		
	press configure
	
		change "qt version" 4 to "qt version" 5

	press configure	untill you have no errors or warnings then press generate

open your mingw-64 shortcut

	go to your VTK build folder directory (in the mingw-64 terminal) and enter the command "mingw32-make -j8" (j is the number of threads to use with the make command)

	this takes 15-45 minutes depending on cpu speed

add vtk build file to path
	- "C:\VTK-6.3.0\VTK-6.3.0\VTKBuildStatic"

-- that should be everything. To build a project:

generate a makefile for your project with cmake, then use "mingw32-make" to build it.  