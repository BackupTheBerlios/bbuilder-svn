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

// TESTEST

/**
  @author Alex Letkemann
*/
class BB_MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	
	/**
	 * @see QMainWindow
	 */
    BB_MainWindow(QWidget* parent = 0, Qt::WFlags flags = 0);

	/**
	 * Destrucktor
	 */
    ~BB_MainWindow();
	
private:
	void initMenus();
	void initStatusBar();
	void initActions();
	void initMainWindow();
    void initDoc();
    
	
protected:
	/** Menubar des Hauptfensters */
	QMenuBar *m_MainMenuBar;
	
	/** 'Datei'-Menu der Menubar */
	QMenu *m_MenuFile;
	
	/** 'Ansicht-Menu der Menubar'*/
	QMenu *m_MenuView;
	
	/** Statusbar der Hauptfensters */
	QStatusBar *m_StatusBar;
	
	/** Haupt-Tabwidget des Hauptfensters */
    QTabWidget *m_TabWidget;
	bool m_Keys[256];
    BB_Doc* m_Doc;
	
protected:
	virtual void keyPressEvent ( QKeyEvent * e );
    virtual void keyReleaseEvent ( QKeyEvent * e );
};

#endif