_All releases can be found from_ [this Downloads page](http://code.google.com/p/hoxchess/downloads/list)

  * **Dec 23, 2009**
    * Released version **1.0.0** with binary packages for Windows, Mac OS X, and Linux
    * The _new features_ are:
      * Implement a new Click-N-Click move mode
      * Implement the 'highlight' of a next position when moving a Piece
      * Implement a Popup Private Chat window
      * Enable Copy/Paste option with the Chat window
      * Add a new 3D Piece set from [Eurasia-Chess](http://www.eurasia-chess.com)
    * Some fixes are:
      * Fix the King-facing-King bug in the Referee
      * Fix the crash if an AI Plugin 's name is invalid
    * The Linux binary package has been tested on the following distributions:
      * **CentOS 5.4** (32-bit)
      * **Ubuntu/Kubuntu 9.10** (32-bit and 64-bit)
      * **Fedora 12** (32-bit)
      * **openSUSE 11.2** (32-bit)
      * **Debian 5.0.3** (32-bit)
      * **Mandriva 2010.0**
      * **Gentoo 2008.0** (32-bit)

  * **Jul 25, 2009**
    * Released version **0.8.0.0** with binary packages for Windows, Mac OS X, and Linux
    * The _new features_ are:
      * Add **Play with youself** (or _Human vs. Human_) feature
      * Support **Difficulty Level** when playing against AI
      * Add **Author**-name and Web site of the AI's author on the Practice table
      * Add the basic **Check for Updates** feature
      * AI **Folium**: synced up the source code with http://folium.googlecode.com
      * Add the **Clear** button in both the _Activities_ and _Messages_ dialogs
      * Improved localization in Chinese, French, and Vietnamese with help from native speakers
    * Some fixes are:
      * Mac OS X: Optimize the Move-handling code to speed up image drawing.
      * Allow to open the Practice table from everywhere
      * Fix the message-being-cut-off issue when _username_ contains a space
      * Fixed the _blank-Chat-window_ issue when  the window is full
      * Fix the crash when a _List-of-tables_ is displayed while the Site is closed

  * **Jun 20, 2009**
    * Released version **0.7.6.0** just for **Mac OS X** to fix the wrong _Company Name_ in the last submission to [Apple - Downloads](http://www.apple.com/downloads/)
    * The only major change is the ability to change the **Difficulty Level** of AI Engines in the Practice Table.
      * See [the screenshot here...](http://www.playxiangqi.com/cchess/screenshots/0.7.6.0/HOXChess-0.7.6.0_MacOSX.png)

  * **Jun 09, 2009**
    * Released version **0.7.5.0** with binary packages for Windows, **Mac OS X**, and Linux
    * Some of the _new features_ are:
      * Support for _Mac OS X Leopard 10.5_
      * Implement Board Background using _pre-made_ images
      * Support **Review** Moves when loading a previously saved game from disk
      * Support the review of Board and Pieces inside the **Options** dialog
      * Add a very good AI engine called [HaQiKi D](http://home.hccnet.nl/h.g.muller/XQhaqikid.html) created by **H.G. Muller**
      * Include a new _western_ piece set **Alfaerie** from http://www.chessvariants.com
      * Localization: add the initial support for French language (50% translation done)
    * The Linux binary package has been tested on the following distributions:
      * **Ubuntu/Kubuntu-8.10, 9.04** (32-bit and 64-bit)
      * **Fedora-10**   (32-bit)
      * **openSUSE 11** (32-bit)
      * **Debian 5.0.1** (32-bit)
      * **CentOS 5.3** (32-bit)
      * **Gentoo 2008.0** (32-bit)
    * **Note:** To player on [PlayXiangqi.com](http://www.playxiangqi.com), you play as a **guest** or create an account [at this page...](http://www.playxiangqi.com/index.php?page=register)

  * **Mar 29, 2009**
    * Released version **0.7.0.0** of the _source_ code and Windows Binary _Installer_
    * The main _new features_ are:
      * Localization: English, Chinese (Simplified), Vietnamese
        * For both the program itself and the Installer.
      * AI Plugin Framework: embedded 4 engines (TSITO, Folium, XQWLight, and MaxQi)
        * AI Engines are separated into different dynamic libraries (.dll on Windows and .so on Linux)
      * Added the option to change Piece-Set.
      * Fixed the disconnect problem in Linux (Ubuntu, CentOS,...)
        * This is done by replacing wxSocket with the **Asio** network library.
      * Implemented a private/instant message for Chesscape and PlayXiangqi servers.
      * Ability to resume games with AI Engines using Forsyth-Edwards Notation (FEN) format
      * Change the default PlayXiangqi 's port from 8000 to 80.
      * Display the Getting Started dialog upon startup to help novice users.

  * **Jan 21, 2009**
    * Released version **0.6.0.0** of the _source_ code and Windows Binary _Installer_
    * The main _new features_ are:
      * Support **Guest** Login for both [Chesscape.com](http://www.chesscape.com) and [PlayXiangqi.com](http://www.playxiangqi.com)
      * Display _Unicode_ characters (Chinese, Vietnamese,…)
      * Chesscape: Implement the Player-Status (with LED images = GREEN/RED).
      * Implemented (by _darickdle_) the new feature to SAVE and RESTORE a table to allow resuming a Practice game.
      * Chesscape: Implement Instant (or Private) message.
    * To build this release, we need to latest **trunk** version of wxWidgets 2.9.0

  * **Oct 24, 2008**
    * Released **HOXChess 0.5.1.0** of the _source_ code and Windows Binary _Installer_
    * The main _new features_ are:
      * Use **XQWLight** at http://www.elephantbase.net as the default AI Xiangqi Engine
      * Support _MOVE_ sound
      * Added Tools->Options for Sound, Background/Foreground for Board
      * Make [PlayXiangqi.com](http://www.playxiangqi.com) the default site since Chesscape.com has been discontinued.
      * Updated Makefile to compile under Ubuntu 8.04 using the ANSI build wxGTK 2.8.9
      * Restrict HOXChess to allow only one Practice Table at a time.
      * Upgraded to wxWidgets 2.8.9
      * Upgraded **boost** libraries to 1\_36\_0

  * **Sept 20, 2008**
    * Released **HOXChess 0.5.0.0** of the _source_ code and Windows Binary _Installer_
    * Major changes are:
      * Added support for _Artificial Intelligent_ (AI) Players
        * I included the open source Xiangqi AI project called [TSITO Chinese Chess Engine](http://xiangqi-engine.sourceforge.net/tsito.html) written by Noah Roberts
      * Upgraded to wxWidgets 2.8.8

  * **May 03, 2008**
    * Released **HOXChess 0.4.4.0** of the _source_ code and Windows Binary _Installer_
    * Major changes are:
      * Improved the JOIN/UNJON action inside the Board
        * Added two buttons: **Play-RED** and **Play-BLACK** in addition to **Unsit**
      * Supported **REVIEW** mode while accepting incoming Moves from the network.
      * Table-List Dialog: Implemented _double-click_ to join a table.
      * Fixed the issue that new chat messages are hidden when the Window is full.
      * Changed the shortcut key of Toggle-Board-View from Ctrl+T to Ctrl+V
        * This is done to avoid conflict with that of getting the list of Tables
      * [PlayXiangqi.com](http://www.playxiangqi.com): Partially support LOGIN/LOGOUT events.
      * Performed a lot of code cleanup

  * **April 22, 2008**
    * Released **HOXChess 0.4.3.0** of the _source_ code and Windows Binary _Installer_
    * Major changes are:
      * Supported Player-INFO and INVITE features
        * Player-Info can be obtained by double-clicking on the Player
      * Implemented the LIST-of-ACTIVE-PLAYERS window
      * Chesscape: Improved the user-playing experience by allowing JOIN/CREATE a different Table while observing another
      * Supported JOIN/LEAVE (a table) events with the correct player-SCORE
      * Chesscape: Auto disconnect from the server if failing to login.

  * **April 17, 2008**
    * Released **HOXChess 0.4.2.0** of the _source_ code and Windows Binary _Installer_
    * Major changes are:
      * Chesscape: Support RESIGN button within the Board
      * Support Rated/Non-Rated Game option in both Chesscape and HOXServer
      * Added two new tool bar icons for _Connect_ and _Disconnect_
      * Added the **System-Message Area** in the Board
      * HOXServer: Replaced the static IP with **games.playxiangqi.com**
      * Resized the Piece Images from 50 x 50 to 45 x 45 (in pixels)
      * Changed the look of the core Board:
        * Draw mirror lines around the initial positions of Cannons and Pawns
        * Change the Board's foreground and background colors
      * Removed support for HTTP-Polling site

  * **April 08, 2008**
    * Released **HOXChess 0.4.1.0** of the _source_ code.
    * Xiangqi fans now have the option to connect to my _new_ Xiangqi server at **games.playxiangqi.com** (with the static IP _209.20.66.220_)
      * To play on this server, you need to create _a Blog account_ at [this page](http://www.playxiangqi.com/blog/wp-login.php?action=register)
    * Major changes are:
      * Support JOIN and UNJOIN event for _Chesscape_ server
      * Remove the SERVER component from this Application.
      * Enable/Disable DRAW/RESIGN action based on the Player's role
      * Using the static IP **209.20.66.220** as the default IP for my _HOXServer_ server in the Login dialog (**games.playxiangqi.com** may now be used instead).

  * **April 03, 2008**
    * Released **HOXChess 0.4.0.0** of the _source_ code.
    * The major feature introduced in this release is the ability to connect to my _upcoming_ Xiangqi server.
    * Other noticeable changes:
      * Improved the Login-Dialog to make it more user friendly.
      * Added the Options-Dialog to change a Table's Timers (Game/Move/Free).
      * Rewrote the Connection-derived classes to use TWO-THREAD (per connection) model.
      * Included _boost::shared\_ptr_ to help managing memory.
      * Added the RESET and RESIGN actions to the Table's Board.
    * The list of features that are disabled/removed:
      * Disabled the (local) server component - I am thinking about removing this feature completely in the subsequent releases.
      * Disabled the HTTP-Polling site.

  * **January 03, 2008**
    * Released **HOXChess 0.3.0.0** of the _source_ code.
    * The major change in this release is the ability to _connect to the free_ [Chesscape server](http://www.chesscape.com)
      * Support Join, Drawing, Resign (by closing the Table).
      * Support Chat Message within a Table.
      * Support Timer (both Game and Increment timers).
      * Support Responding-to-Invite request.
    * Other noticeable changes:
      * Added a new Login Dialog.
      * Redid the Tables Listing Dialog to make it user friendlier.
      * Added Action-Buttons (**Draw**, **Join**) inside the _core_ Board.

  * **December 04, 2007**
    * Released **HOXChess 0.2.0.0** of the _source_ code.
    * Here are some of the major changes:
      * Introduced a concept of a _Site_ that represents either a _local_ server or a _remote_ server.
      * Fixed a number of crashes related to closing the App.
      * Updated the project to use the latest _wxWidgets 2.8.7_.
      * Updated the project to use the _Visual C++ 2008 Express Edition_.

  * **November 17, 2007**
    * Released **HOXChess 0.1.0.0** of the _source_ code.
    * This release is a major milestone for HOXChess because all the _core_ features have been implemented and are ready to be tested by the end users.
      * In other words, this is the _Alpha_ release of the project.
      * Please start filling issues, if you find any, at the [Issues page](http://code.google.com/p/hoxchess/issues/list)
    * The two main features introduced in this release are:
      1. Game-Review (i.e., backward/forward old Moves).
      1. Game-Ending (i.e., the Board can detect and print "Game Over" message).

  * **November 14, 2007**
    * Released the third version **0.0.3.0** of the source code.
    * Mostly, this release includes GNUv3 Copyright notices.
    * Also, the archive includes a simple Linux Makefile.

  * **November 10, 2007**
    * Released the second version **0.0.2.0** of the source code.
    * The version of source code can _also_ be compiled under Linux.
      * CentOS 4.5 using Eclipse CDT 3.3.
      * Ubuntu 7.10 using KDevelop 3.5 (as a C++ Automake project).

  * **October 26, 2007**
    * Released the first version **0.0.1.0** (Windows only).
    * You need Visual C++ 2005 Express Edition and wxWidgets library 2.8.6 to compile this release.