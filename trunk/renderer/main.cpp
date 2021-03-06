/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann   *
 *   alex@letkemann.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/


#include <QApplication>
#include <QString>

#include "bb_globals.h"
#include "br_mainwindow.h"



int main(int argc, char *argv[])
{
 	setDirs(argv[0]);
	
	QApplication app(argc,argv);
	
	app.setQuitOnLastWindowClosed(true);
	
	QFont f;
	f.setStyleHint(QFont::System, QFont::PreferDefault);
			
	app.setFont(f);

	BR_MainWindow MainWindow;
	MainWindow.show();
	
	return app.exec();
}
