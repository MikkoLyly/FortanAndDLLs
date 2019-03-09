# FortanAndDLLs

This is a small educational project which I wrote for my self to remember all the dirty details related to mixing F90 programs and DLLs written in C (or in any language able to create libraries with C interface). If you find the stuff useful, use it as you wish.

Linux
-----
You will need a working build environment and libuuid installed on your machine (libuuid is needed here for demonstration purposes only). On Debian based systems you can install these packages as

     $ sudo apt install build-essential uuid-dev

Build the project as follows (edit Makefile to check how things are done under the hood):

     $ cp Makefile.linux Makefile
     $ make

Run the test programs by defining the load library path in front of the executable name:

     $ LD_LIBRARY_PATH=. ./main.exe
     $ LD_LIBRARY_PATH=. ./prog.exe

Finally, you can generate Doxygen style documentaion by typing

     $ make docs

Install doxygen if needed:

     $ sudo apt install doxygen

Windows
-------
The project is written for MSYS2 build environment. Make sure that you have MSYS2, make, gcc, gfortran, and all related stuff installed on your machine. If not, go to www.msys2.org and get the installer. Then open a Mingw64 shell and type in the following commands:

     $ pacman -S msys/make
     $ pacman -S mingw64/mingw-w64-x86_64-gcc
     $ pacman -S mingw64/mingw-w64-x86_64-gcc-fortran

Build the project as follows:

     $ cp Makefile.windows Makefile
     $ make

Run the test programs (make sure that utils.dll is found from the same folder as the executales, or update your PATH variable to contain the folder where utils.dll is actually located):

     $ ./main.exe
     $ ./prog.exe

You can list all dependencies on system DLLs by using the commands

     $ ldd ./main.exe
     $ ldd ./prog.exe

Finally, it is possible to generate Doxygen style documentation for the project:

     $ make docs

If you don't have doxygen installed, you can install it by typing

     $ pacman -S mingw64/mingw-w64-x86_64-doxygen
