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
#include "bb_mainwindow.h"
#include "iostream"

#include "bb_tabterrain.h"
#include "bb_tabbuilding.h"
#include "bb_tablevel.h"


using namespace std;

BB_MainWindow::BB_MainWindow(QWidget* parent, Qt::WFlags flags): QMainWindow(parent, flags)
{
	
	
	initMenus();
	initStatusBar();
	initActions();
	
	initDoc();
	
	initMainWindow();
	
	
	
	/* Status aller Tasten auf false setzen */
	for(int i = 0; i < 256; i++)
	{
		m_Keys[i] = false;
	}
	
}


BB_MainWindow::~BB_MainWindow()
{
}

/**
 * @author Alex Letkemann
 * @version 0.1
 * @date 10.08.2005
 * Initialisiert alle MenusBars und Menus im Hauptfenster
 */
void BB_MainWindow::initMenus()
{
	m_MenuFile = new QMenu(QString::fromUtf8("Datei"));
	
	m_MenuView = new QMenu(QString::fromUtf8("Ansicht"));
	
	m_MainMenuBar = new QMenuBar();
	m_MainMenuBar->addMenu(m_MenuFile);
	m_MainMenuBar->addMenu(m_MenuView);
	
	setMenuBar(m_MainMenuBar);
}


/**
 * @author Alex Letkemann
 * @version 0.1
 * @date 10.08.2005
 * Initialisiert die Statusbar des Hauptfensters
 */
void BB_MainWindow::initStatusBar()
{
	m_StatusBar = new QStatusBar();
}


/**
 * @author Alex Letkemann
 * @version 0.1
 * @date 10.08.2005
 * Initialisiert alle Aktionen des Haupfensters
 */
void BB_MainWindow::initActions()
{

}


/**
 * @author Alex Letkemann
 * @version 0.1
 * @date 10.08.2005
 * Setzt die Attribute des Hauptfensters und Erzeugt weitere Fenster
 */
void BB_MainWindow::initMainWindow()
{
	
	setMinimumHeight(400);
	setMinimumWidth(600);
	
// 	setWindowState(Qt::WindowMaximized);
	setWindowTitle(QString::fromUtf8("glBuildingBuilder - Editor"));
	setStatusBar(m_StatusBar);
	
	BB_Tab *tabTerrain = new BB_TabTerrain(m_Doc->getTerrain());
	BB_Tab *tabBuilding = new BB_TabBuilding(m_Doc->getBuildings());
	BB_Tab *tabLevel = new BB_TabLevel();
	
	m_TabWidget = new QTabWidget();
	m_TabWidget->addTab(tabTerrain,QString::fromUtf8("Gelände"));	//TODO
	m_TabWidget->addTab(tabBuilding,QString::fromUtf8("Gebäude"));	//TODO
	m_TabWidget->addTab(tabLevel,QString::fromUtf8("Etagen"));
	
	setCentralWidget(m_TabWidget);
}


/**
 * KeyPressEvent setzt den Status einer Taste auf true, falls diese gedrückt wird
 */
void BB_MainWindow::keyPressEvent ( QKeyEvent * e )
{
	cout << "Press! (" << e->key() << ")" << endl;
	if(e->key() < 256 && e->key() >= 0)
	{
		m_Keys[e->key()] = true;
	}
}


/**
 *
 */
void BB_MainWindow::keyReleaseEvent ( QKeyEvent * e )
{
	cout << "Release! (" << e->key() << ")" << endl;
	if(e->key() < 256 && e->key() >= 0)
	{
		m_Keys[e->key()] = false;
	}
}


/*!
    \fn BB_MainWindow::initData()
 */
void BB_MainWindow::initDoc()
{
	m_Doc = new BB_Doc();
}
