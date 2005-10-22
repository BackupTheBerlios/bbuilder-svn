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

#include "bb_dlgprojectnew.h"


using namespace std;

BB_MainWindow::BB_MainWindow(QWidget* parent, Qt::WFlags flags): QMainWindow(parent, flags)
{
	m_Config.open();
	initActions();
	initMenus();
	initStatusBar();
	
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
	
	if(!m_Config.save())
	{
		cout << "Konfigurationsdatei konnte nicht geschriebenwerden" << endl;
	}
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
	
	m_MenuProject = new QMenu(QString::fromUtf8("Projekt"));
	

	
	m_MenuProject->addAction(m_aProjectNew);
	m_MenuProject->addAction(m_aProjectOpen);
	m_MenuProject->addAction(m_aProjectClose);
	
	m_MainMenuBar = new QMenuBar();
	m_MainMenuBar->addMenu(m_MenuFile);
	m_MainMenuBar->addMenu(m_MenuView);
	m_MainMenuBar->addMenu(m_MenuProject);
	
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


/**
 * Erstellt ein neues, leeres Projekt.
 * Der User kann im Dialog, der getsartet wird, den Pfad angeben, wo das neue Projekt erzeugt werden soll.
 * @author Alex Letkemann
 * @date 12.09.2005
 */
void BB_MainWindow::slotProjectNew()
{	bool result;
	BB_DlgProjectNew dlg;	
	do
	{	
		result = dlg.exec();
		QString dir = dlg.projectDir();
		QDir path = dlg.projectPath();
		
		if(result == QDialog::Accepted)
		{
			m_Doc->close();
			m_TabWidget->setEnabled(false);
			
			if(path.mkdir(dir) && path.cd(dir) && m_Doc->createNew(path))
			{
				m_TabWidget->setEnabled(true);
				break;
			}
			else
			{
				QMessageBox::critical(	&dlg,
									   QString::fromUtf8("Fehler beim Erstellen des Projektes"),
									   QString::fromUtf8("Projekt konnte nicht erstellt werden, bitte  überprüfen Sie die Pfade.")
									 );
			}
		}
	}
	while(result != QDialog::Rejected);
	
}


/**
 * Öffnet ein Projekt.
 * Der User muss in einem File-Dialog eine Projekt-Datei auswählen.
 * @author Alex Letkemann
 * @date 12.09.2005
 */
void BB_MainWindow::slotProjectOpen()
{
	
	
	cout << "Projekt öffnen" << endl;
	
	QString filename;
	filename = QFileDialog::getOpenFileName(
			this,
			QString::fromUtf8("Öffnen"),
			m_Config.getCurrentProjectPath(),
			"glBB Projekt-Datei (*.glbb)");
	
	cout << "filename : " << filename.toStdString() << endl;
	
	if(!filename.isEmpty())
	{
		if(m_Doc->open(filename))
		{
			m_TabWidget->setEnabled(true);
			m_Config.setCurrentProjectPath(filename);
		}
		else
		{
			QMessageBox::critical(this,
								QString::fromUtf8("Fehler beim Öffnen des Projektes"),
								QString::fromUtf8("Projekt konnte nicht geöffnet werden"));
		}
	}
	
    /// @todo implement me
}


/**
 * Schliesst das aktuelle Projekt.
 * Das Tabwidget des Hauptfensters wird deaktiviert.
 * @author Alex Letkemann
 * @date 20.10.2005
 */
void BB_MainWindow::slotProjectClose()
{	
	m_Doc->close();
	m_TabWidget->setEnabled(false);
}


/**
 * Initialisiert die Aktionen des Haupfensters
 * @author Alex Letkemann
 * @date 07.09.2005
 */
void BB_MainWindow::initActions()
{
	m_aProjectNew = new QAction(QString::fromUtf8("Neues Projekt"),this);
	connect(m_aProjectNew,SIGNAL(triggered()),this,SLOT(slotProjectNew()));
	
	m_aProjectOpen = new QAction(QString::fromUtf8("Projekt öffnen"),this);
	connect(m_aProjectOpen,SIGNAL(triggered()),this,SLOT(slotProjectOpen()));
	
	m_aProjectClose = new QAction(QString::fromUtf8("Projekt schliessen"),this);
	connect(m_aProjectClose,SIGNAL(triggered()),this,SLOT(slotProjectClose()));
}
