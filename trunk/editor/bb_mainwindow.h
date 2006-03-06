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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_MAINWINDOW_H
#define BB_MAINWINDOW_H

#include <qmainwindow.h>
#include <QtGui>

#include "bb_doc.h"
#include "bb_config.h"

#include "bb_tabterrain.h"
#include "bb_tabbuilding.h"
#include "bb_tablevel.h"

/**
 * Das Hauptfenster des Editors.
 * Steuert die Menus und die Aktionen des Hauptfensters.
 * Das Fenster besitzt eine Menubar mit drei Menus (Datei, Ansicht und Projekt).
 * Die Menupunkte der einzelnen Menus sind:
 * @author Alex Letkemann 
 */
class BB_MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	
	/**
	 * Konstruktor
	 * @see QMainWindow
	 */
    BB_MainWindow(QWidget* parent = 0, Qt::WFlags flags = 0);

	/**
	 * Destruktor
	 */
    ~BB_MainWindow();
   
	
private:
	/**
     * Initialisiert die Aktionen des Haupfensters
     * @author Alex Letkemann
     * @date 07.09.2005
	 */
	void initActions();
	
	/**
	 * @author Alex Letkemann
	 * @date 10.08.2005
	 * Initialisiert alle MenusBars und Menus im Hauptfenster
	 */
	void initMenus();
	
	/**
	 * @author Alex Letkemann
	 * @version 0.1
	 * @date 10.08.2005
	 * Initialisiert die Statusbar des Hauptfensters
	 */
	void initStatusBar();
	
	/**
	 * @author Alex Letkemann
	 * @version 0.1
	 * @date 10.08.2005
	 * Setzt die Attribute des Hauptfensters und Erzeugt weitere Fenster
	 */
	void initMainWindow();

	/**
	 * Wird aufgerufen, wenn das Fenster geschlossen wird.
	 * Schliesst das Projekt.
	 * @param e QCloseEvent
	 * @author Alex Letkemann
	 */
    virtual void closeEvent ( QCloseEvent * e );
    
	
protected:

	
	/** Statusbar der Hauptfensters */
	QStatusBar *m_StatusBar;
	
	/** Haupt-Tabwidget des Hauptfensters */
    QTabWidget *m_TabWidget;

	/** Konfigurationsklasse */
	BB_Config m_Config;
	
	/** Dokument */
	BB_Doc m_Doc;
	
	/** Menubar des Hauptfensters */
	QMenuBar *m_MainMenuBar;
	
	/** 'Datei'-Menu der Menubar */
	QMenu *m_MenuFile;
	
	/** 'Ansicht'-Menu der Menubar*/
// 	QMenu *m_MenuView;
	
	/** 'Projekt'-Menu der Menubar */
    QMenu* m_MenuProject;
	
	/* Aktionen der Menus*/
    QAction* m_aProjectClose;
    QAction* m_aProjectNew;
    QAction* m_aProjectOpen;
//     QAction* m_aViewOptions;
	QAction* m_aFileSave;
	QAction* m_aFileExit;
	
	/** Tabs des Hauptfensters */
	BB_TabBuilding* m_TabBuilding;
    BB_TabTerrain* m_TabTerrain;
    BB_TabLevel* m_TabLevel;
    
    
private slots:
	
	/* Slots der Menus */
    void slotProjectNew();
    void slotProjectOpen();
    void slotProjectClose();
	void slotViewOptions();
    void slotFileSave();
    void slotFileExit();
private:
	
	/**
	 * Versucht das zuletzt geöffnete Projekt zu laden.
	 * @return <i>true</i>, falls das Projekt geladen werden konnte, sonst <i>false</i>.
	 * @author Alex Letkemann
	 * @date 30.10.2005
	 */
    bool loadDoc();
};

#endif
