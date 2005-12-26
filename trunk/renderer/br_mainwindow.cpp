//
// C++ Implementation: br_mainwindow
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "br_mainwindow.h"

#include <iostream>

#include <QtGui>


using namespace std;

/**
 * Konstruktor
 */
BR_MainWindow::BR_MainWindow( QWidget* parent, Qt::WFlags flags )
        : QMainWindow( parent, flags )
{

    m_InfoWidget = NULL;
    m_ViewWidget = NULL;

    m_MainMenuBar = NULL;
    m_StatusBar = NULL;

    m_MenuFile = NULL;
    m_MenuNavi = NULL;
    m_MenuView = NULL;

    m_TimerAnimate = NULL;
    m_TimerFPS = NULL;

    initActions();
    initMenus();
    initStatusBar();
    initMainWindow();

    m_aFileExit = NULL;
    m_aViewFullScreen = NULL;

    initTimer();
}


/**
 * Destruktor
 */
BR_MainWindow::~BR_MainWindow()
{}




/**
 * Initialisiert alle Aktionen des Hauptfensters
 */
void BR_MainWindow::initActions()
{
    /// @todo implement me: Aktionen
    m_aFileExit = new QAction( QString::fromUtf8( "Beenden" ), this );
    m_aFileExit->setShortcut( QKeySequence( tr( "Ctrl+Q", "Datei|Beenden" ) ) );
    m_aFileExit->setStatusTip( tr( "Programm beenden" ) );
    connect( m_aFileExit, SIGNAL( triggered() ), this, SLOT( slotFileExit() ) );


    m_aViewFullScreen = new QAction( QString::fromUtf8( "Full-Screen modus" ), this );
    m_aViewFullScreen->setCheckable ( true );
    m_aViewFullScreen->setChecked ( false );
    m_aViewFullScreen->setShortcut( QKeySequence( tr( "Shift+Ctrl+F", "Ansicht|Full-Screen" ) ) );
    m_aViewFullScreen->setStatusTip( tr( "Zeigt das Bild auf dem gesammten Bildschirm" ) );
    connect( m_aViewFullScreen, SIGNAL( toggled ( bool ) ), this, SLOT( slotViewFullScreen ( bool ) ) );

}


/**
 * Initialisiert das Hauptfenster
 */
void BR_MainWindow::initMainWindow()
{
    setMinimumHeight( 400 );
    setMinimumWidth( 600 );

    setWindowTitle( QString::fromUtf8( "glBuildingRenderer - Renderer" ) );

    setMenuBar( m_MainMenuBar );
    setStatusBar( m_StatusBar );

    /* Das View-Fenster erzeugen und deaktivieren.
     * Wird erst aktiviert, wenn ein Projekt geladen wird. */

    QSplitter *splitter = new QSplitter( this );

    m_InfoWidget = new BR_InfoWidget( &m_Doc, this );
	
	m_InfoWidget->setFixedWidth(200);
	
    m_ViewWidget = new BR_View( &m_Doc, m_InfoWidget, this );
	
	
    ///@todo Wieder Deaktivieren
    // 	m_ViewWidget->setEnabled( false );

    splitter->addWidget( m_ViewWidget );
    splitter->setCollapsible( 0, false );
    splitter->setStretchFactor( 0, 0 );

    splitter->addWidget( m_InfoWidget );
    splitter->setCollapsible( 1, true );
    splitter->setStretchFactor( 1, 0 );


    setCentralWidget( splitter );
}


/**
 * Initialisiert die Menus des Hauptfensters
 */
void BR_MainWindow::initMenus()
{
    /* Neue Menubar erzeugen */
    m_MainMenuBar = new QMenuBar();

    /* Neues Menu 'Datei' erzeugen */
    m_MenuFile = new QMenu( QString::fromUtf8( "&Datei" ) );

    /* Menu 'Datei' füllen */
    m_MenuFile->addAction( m_aFileExit );


    /* Neues Menu 'Ansicht' erzeugen */
    m_MenuView = new QMenu( QString::fromUtf8( "&Ansicht" ) );
    m_MenuView->addAction( m_aViewFullScreen );


    /* Neues Menu 'Navigation' erzeugen*/
    m_MenuNavi = new QMenu( QString::fromUtf8( "&Navigation" ) );

    /* Menu 'Navigation' deaktivieren, da es erst beim Laden eines Projektes gefüllt wird */
    m_MenuNavi->setEnabled( false );

    /* Menus in die Menubar einhängen */
    m_MainMenuBar->addMenu( m_MenuFile );
    m_MainMenuBar->addMenu( m_MenuView );
    m_MainMenuBar->addMenu( m_MenuNavi );
}


/**
 * Initialisiert die Statusbar des Hauptfensters
 */
void BR_MainWindow::initStatusBar()
{
    m_StatusBar = new QStatusBar();
}


/**
 * Beendet das Programm
 * Wird durch die Aktion m_aFileExit aufgeruffen.
 */
void BR_MainWindow::slotFileExit()
{
    close();
}


/*!
    \fn BR_MainWindow::slotViewFullScreen ( bool value )
 */
void BR_MainWindow::slotViewFullScreen ( bool value )
{
    if ( value )
    {
        showFullScreen();
    }
    else
    {
        showNormal();
    }
}


/**
 * Initialisiert die Timer
 */
void BR_MainWindow::initTimer()
{
    m_TimerAnimate = new QTimer( this );
    m_TimerAnimate->setSingleShot ( false );
    connect( m_TimerAnimate, SIGNAL( timeout() ), this, SLOT( slotTimerAnimation() ) );
    m_TimerAnimate->start( 10 );

    m_TimerFPS = new QTimer( this );
    m_TimerFPS->setSingleShot ( false );
    connect( m_TimerFPS, SIGNAL( timeout() ), this, SLOT( slotTimerFPS() ) );
    m_TimerFPS->start( 1000 );
}


/*!
    \fn BR_MainWindow::slotTimerAnimation()
 */
void BR_MainWindow::slotTimerAnimation()
{
    m_ViewWidget->update();
}


/*!
    \fn BR_MainWindow::slotTimerFPS()
 */
void BR_MainWindow::slotTimerFPS()
{
    m_ViewWidget->showCurrentFPS();
}


