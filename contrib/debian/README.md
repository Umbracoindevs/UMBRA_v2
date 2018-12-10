
Debian
====================
This directory contains files used to package umbrad/umbra-qt
for Debian-based Linux systems. If you compile umbrad/umbra-qt yourself, there are some useful files here.

## umbra: URI support ##


umbra-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install umbra-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your umbraqt binary to `/usr/bin`
and the `../../share/pixmaps/umbra128.png` to `/usr/share/pixmaps`

umbra-qt.protocol (KDE)

