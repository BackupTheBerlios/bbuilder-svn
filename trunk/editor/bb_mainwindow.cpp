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
#include <iostream>

#include "bb_mainwindow.h"
#include "bb_tabterrain.h"
#include "bb_tabbuilding.h"
#include "bb_tablevel.h"
#include "bb_dlgprojectnew.h"
#include "ui_fileOptions.h"


using namespace std;

BB_MainWindow::BB_MainWindow( QWidget* parent, Qt::WFlags flags ) : QMainWindow( parent, flags )
{
    m_Config.open();
    initActions();
    initMenus();
    initStatusBar();

//     initDoc();

    initMainWindow();

    if ( loadDoc() )
    {
//         m_TabBuilding->createBuildingList();
		m_TabTerrain->updateLists();
		m_TabBuilding->updateLists();
		m_TabLevel->updateLists();
    }

}


BB_MainWindow::~BB_MainWindow()
{

    if ( !m_Config.save() )
    {
        cout << "Konfigurationsdatei konnte nicht geschriebenwerden" << endl;
    }
}

/**
 * @author Alex Letkemann
 * @date 10.08.2005
 * Initialisiert alle MenusBars und Menus im Hauptfenster
 */
void BB_MainWindow::initMenus()
{
    m_MenuFile = new QMenu( QString::fromUtf8( "Datei" ) );

    m_MenuView = new QMenu( QString::fromUtf8( "Ansicht" ) );

    m_MenuProject = new QMenu( QString::fromUtf8( "Projekt" ) );

    m_MenuFile->addAction( m_aFileSave );
    m_MenuFile->addSeparator();
    m_MenuFile->addAction( m_aFileExit );

    m_MenuView->addAction( m_aViewOptions );

    m_MenuProject->addAction( m_aProjectNew );
    m_MenuProject->addAction( m_aProjectOpen );
    m_MenuProject->addAction( m_aProjectClose );

    m_MainMenuBar = new QMenuBar();

    m_MainMenuBar->addMenu( m_MenuFile );
    m_MainMenuBar->addMenu( m_MenuView );
    m_MainMenuBar->addMenu( m_MenuProject );


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
    setMinimumHeight( 400 );
    setMinimumWidth( 600 );

    // 	setWindowState(Qt::WindowMaximized);
    setWindowTitle( QString::fromUtf8( "glBuildingBuilder - Editor" ) );


    m_TabTerrain = new BB_TabTerrain( &m_Doc );
    m_TabBuilding = new BB_TabBuilding( &m_Doc );
    m_TabLevel = new BB_TabLevel( &m_Doc );

    m_TabWidget = new QTabWidget();
    m_TabWidget->addTab( m_TabTerrain, QString::fromUtf8( "Gelände" ) );	//TODO
    m_TabWidget->addTab( m_TabBuilding, QString::fromUtf8( "Gebäude" ) );	//TODO
    m_TabWidget->addTab( m_TabLevel, QString::fromUtf8( "Etagen" ) );

    m_TabWidget->setEnabled( false );

    setStatusBar( m_StatusBar );
    setMenuBar( m_MainMenuBar );
    setCentralWidget( m_TabWidget );
}


/**
 * Erstellt ein neues, leeres Projekt.
 * Der User kann im Dialog, der getsartet wird, den Pfad angeben, wo das neue Projekt erzeugt werden soll.
 * @author Alex Letkemann
 * @date 12.09.2005
 */
void BB_MainWindow::slotProjectNew()
{
    bool result;
    BB_DlgProjectNew dlg;
    do
    {
        result = dlg.exec();
        QString dir = dlg.getProjectDir();
        QDir path = dlg.getProjectPath();

        QString name = dlg.getProjectName();
        QString desc = dlg.getProjectDescription();

        if ( result == QDialog::Accepted )
        {
            m_Doc.close();

            m_TabTerrain->unsetDocComponent();
            m_TabBuilding->unsetDocComponent();
            m_TabLevel->unsetDocComponent();

            m_TabWidget->setEnabled( false );

            if ( path.mkdir( dir ) && path.cd( dir ) && m_Doc.createNew( name, desc, path ) )
            {
                m_TabWidget->setEnabled( true );
                m_Config.setCurrentProjectPath( path.path() + QDir::separator() + dir + ".glbb" );


                m_TabTerrain->updateWidget();

                m_TabBuilding->updateWidget();
                m_TabBuilding->clear();

                m_TabLevel->updateWidget();

                return ;
            }
            else
            {
                QMessageBox::critical( &dlg,
                                       QString::fromUtf8( "Fehler beim Erstellen des Projektes" ),
                                       QString::fromUtf8( "Projekt konnte nicht erstellt werden, bitte  überprüfen Sie die Pfade." )
                                     );
            }
        }
    }
    while ( result != QDialog::Rejected );





}


/**
 * Öffnet ein Projekt.
 * Der User muss in einem File-Dialog eine Projekt-Datei auswählen.
 * @author Alex Letkemann
 * @date 12.09.2005
 */
void BB_MainWindow::slotProjectOpen()
{

    m_TabTerrain->unsetDocComponent();
    m_TabBuilding->unsetDocComponent();
    m_TabLevel->unsetDocComponent();

    m_TabWidget->setEnabled( false );
    // 	cout << "Projekt öffnen" << endl;

    QString filename;
    filename = QFileDialog::getOpenFileName(
                   this,
                   QString::fromUtf8( "Öffnen" ),
                   m_Config.getCurrentProjectPath(),
                   "glBB Projekt-Datei (*.glbb)" );

    // 	cout << "filename : " << filename.toStdString() << endl;

    if ( !filename.isEmpty() )
    {
        m_TabBuilding->clear();
        if ( m_Doc.open( filename ) )
        {
            m_TabBuilding->createBuildingList();

            // 			cout << "test1" << endl;
            m_TabWidget->setEnabled( true );
            // 			cout << "test2" << endl;
            m_Config.setCurrentProjectPath( filename );
        }
        else
        {
            QMessageBox::critical( this,
                                   QString::fromUtf8( "Fehler beim Öffnen des Projektes" ),
                                   QString::fromUtf8( "Projekt konnte nicht geöffnet werden" ) );
        }
    }


    m_TabTerrain->updateWidget();
    m_TabBuilding->updateWidget();
    m_TabLevel->updateWidget();

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
	/* Alle Tools zurüksetzten damit die DocComponents 'freiggeben' werden */
	m_TabTerrain->resetTool();
	m_TabBuilding->resetTool();
	m_TabLevel->resetTool();
	
	/* Dokument schliessen */
    m_Doc.close();

    m_TabTerrain->clear();
    m_TabBuilding->clear();
    m_TabLevel->clear();

    m_TabWidget->setEnabled( false );


}

void BB_MainWindow::slotViewOptions()
{
    Ui_fileOptionsDialog dlg;

    QDialog dialog;

    dlg.setupUi( &dialog );
    dialog.exec();
}


/**
 * Initialisiert die Aktionen des Haupfensters
 * @author Alex Letkemann
 * @date 07.09.2005
 */
void BB_MainWindow::initActions()
{
    m_aFileSave = new QAction( QString::fromUtf8( "Datei speichern" ), this );
    m_aFileSave->setShortcut( QKeySequence( tr( "Ctrl+S", "File|Save" ) ) );
    connect( m_aFileSave, SIGNAL( triggered() ), this, SLOT( slotFileSave() ) );

    m_aFileExit = new QAction( QString::fromUtf8( "Beenden" ), this );
    connect( m_aFileExit, SIGNAL( triggered() ), this, SLOT( slotFileExit() ) );

    m_aProjectNew = new QAction( QString::fromUtf8( "Neues Projekt" ), this );
    connect( m_aProjectNew, SIGNAL( triggered() ), this, SLOT( slotProjectNew() ) );

    m_aProjectOpen = new QAction( QString::fromUtf8( "Projekt öffnen" ), this );
    connect( m_aProjectOpen, SIGNAL( triggered() ), this, SLOT( slotProjectOpen() ) );

    m_aProjectClose = new QAction( QString::fromUtf8( "Projekt schliessen" ), this );
    connect( m_aProjectClose, SIGNAL( triggered() ), this, SLOT( slotProjectClose() ) );

    m_aViewOptions = new QAction( QString::fromUtf8( "Einstellungen" ), this );
    connect( m_aViewOptions, SIGNAL( triggered() ), this, SLOT( slotViewOptions() ) );
}


/**
 * 
 */
void BB_MainWindow::slotFileSave()
{
    if ( ( ( BB_Tab* ) m_TabWidget->currentWidget() ) ->saveCurrent() )
    {
        statusBar() ->showMessage( trUtf8( "Detei erfolgreich gespeichert." ), 2000 );
    }
    else
    {
        statusBar() ->showMessage( trUtf8( "Detei konnte nicht gespeichert werden." ), 2000 );
    }
}


/*!
    \fn BB_MainWindow::slotFileExit()
 */
void BB_MainWindow::slotFileExit()
{
    close();
}


/*!
    \fn BB_MainWindow::closeEvent ( QCloseEvent * e )
 */
void BB_MainWindow::closeEvent ( QCloseEvent * e )
{

    e->accept();
    cout << "Fenster wird geschlossen" << endl;
}


/**
 * Versucht das zuletzt geöffnete Projekt zu laden.
 * @return <i>true</i>, falls das Projekt geladen werden konnte, sonst <i>false</i>.
 * @author Alex Letkemann
 * @date 30.10.2005
 */
bool BB_MainWindow::loadDoc()
{
    if ( !m_Config.getCurrentProjectPath().isEmpty() && m_Doc.open( m_Config.getCurrentProjectPath() ) )
    {
        m_TabWidget->setEnabled( true );

        cout << "Projekt geladen: " << m_Config.getCurrentProjectPath().toStdString() << endl;

        m_TabTerrain->updateWidget();
        m_TabBuilding->updateWidget();
        m_TabLevel->updateWidget();

        return true;
    }
    else
    {
        m_Doc.close();
        m_TabWidget->setEnabled( false );

        cout << "Projekt konnte nicht geladen werden: " << m_Config.getCurrentProjectPath().toStdString() << endl;

        m_Config.setCurrentProjectPath( "" );
        return false;
    }
}
