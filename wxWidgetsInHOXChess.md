

# Introduction #

This page describes how to build [wxWidgets](http://www.wxwidgets.org/) libraries to be used by HOXChess.
Starting from version _0.6.0.0_, HOXChess needs on the _to-be-released_ **2.9.0** branch of wxWidgets in order to handle Unicode characters (in Chinese, Vietnamese, etc).

# Instructions under Linux #

On Linux distributions, I use the **GTK** based port of wxWidgets.

This following procedure has been test under the following Linux distributions:
  * **Ubuntu / Kubuntu 8.10, 9.04** (both 64 and 32-bit)
  * **Gentoo 2008.0** (32-bit)

  * Required packages before building wxWidgets 2.9.0
```
  $ sudo apt-get install libgtk2.0-dev
```
  * Download the source code for wxWidgets-2.9.0 from **WX\_2\_9\_0\_BRANCH**:
```
  $ sudo apt-get install subversion
  $ svn co http://svn.wxwidgets.org/svn/wx/wxWidgets/branches/WX_2_9_0_BRANCH wxWidgets-2.9.0
  $ cd wxWidgets-2.9.0
  $ mkdir build-release
  $ cd build-release
  $ ../configure --prefix=/opt/wxGTK-2.9.0 --disable-compat28 --without-libtiff --disable-shared
    # Note: For debug build, add the option [--enable-debug] 
  $ make
  $ sudo make install
```
  * In the end, you would have the GTK-based port of wxWidgets under **/opt/wxGTK-2.9.0**

# Instructions under Mac OS X 10.5 #
The process is very similar to Linux:
```
  $ svn co http://svn.wxwidgets.org/svn/wx/wxWidgets/branches/WX_2_9_0_BRANCH wxWidgets-2.9.0
  $ cd wxWidgets-2.9.0
  $ mkdir build-release
  $ cd build-release
  $ ../configure --prefix=/opt/wxGTK-2.9.0 --disable-compat28 --without-libtiff --disable-shared
    # Note: For debug build, add the option [--enable-debug] 
  $ make
  $ sudo make install
```

To build under **Snow Leopard (10.6.2)** , use the older gcc-4.0 (instead of the system default gcc-4.2) as follows:
```
  $ ../configure CC=gcc-4.0 CXX=g++-4.0 LD=g++-4.0 --prefix=/opt/wxWidgets-2.9.0 --with-osx_carbon \
     --with-macosx-version-min=10.5 --disable-compat28 --without-libtiff --disable-shared
```

More more information, see: [Development: wxMac](http://wiki.wxwidgets.org/Development:_wxMac)

# Instructions under Windows #

The procedure is much easier under Windows (XP or Vista). Simply open the _solution_ file **.../build/msw/wx\_vc9.sln** using the free Visual C++ 2008 Express edition, and build
  * See the other HowToBuild wiki page for more details.