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

    slotProjectClose();
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
	
	
	m_aViewGhostMode = new QAction( QString::fromUtf8( "Geist-Modus" ), this );
	m_aViewGhostMode->setCheckable( true );
	m_aViewGhostMode->setChecked( false );
	m_aViewGhostMode->setShortcut( QKeySequence( tr( "Ctrl+G", "Ansicht|Geist-Modus" ) ) );
	m_aViewFullScreen->setStatusTip( tr( "Ermöglich das Durchfliegen der Wände" ) );
	connect( m_aViewGhostMode, SIGNAL( toggled(bool) ), this, SLOT( slotViewGhostMode( bool) ) );
	
	
	m_aViewWireFrame = new QAction( QString::fromUtf8( "WireFrame-Modus" ), this );
	m_aViewWireFrame->setCheckable( true );
	m_aViewWireFrame->setChecked( false );
	m_aViewWireFrame->setShortcut( QKeySequence( tr( "Ctrl+W", "Ansicht|WireFrame-Modus" ) ) );
	m_aViewWireFrame->setStatusTip( tr( "Zeichnet nur die Kanten" ) );
	connect( m_aViewWireFrame, SIGNAL( toggled(bool) ), this, SLOT( slotViewWireFrame( bool) ) );

    m_aProjectOpen = new QAction( QString::fromUtf8( "Projekt öffnen" ), this );
    m_aFileExit->setStatusTip( QString::fromUtf8( "Eine Projekt öffnen" ) );
    connect( m_aProjectOpen, SIGNAL( triggered() ), this, SLOT( slotProjectOpen() ) );

    m_aProjectClose = new QAction ( QString::fromUtf8( "Projekt schliessen" ), this );
    m_aProjectClose->setStatusTip( QString::fromUtf8( "Das geladene Projekt schliessen" ) );
    connect( m_aProjectClose, SIGNAL( triggered() ), this, SLOT( slotProjectClose() ) );
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

    m_InfoWidget->setFixedWidth( 200 );

    m_ViewWidget = new BR_View( &m_Doc, m_InfoWidget, this );


    ///@todo Wieder Deaktivieren
    m_ViewWidget->setEnabled( false );

    splitter->addWidget( m_ViewWidget );
    splitter->setCollapsible( 0, false );
    splitter->setStretchFactor( 0, 0 );

    splitter->addWidget( m_InfoWidget );
    splitter->setCollapsible( 1, true );
    splitter->setStretchFactor( 1, 0 );


    setCentralWidget( splitter );
    // 	setCentralWidget( m_ViewWidget );
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
    m_MenuFile->addAction( m_aProjectOpen );
    m_MenuFile->addAction( m_aProjectClose );
    m_MenuFile->addSeparator();
    m_MenuFile->addAction( m_aFileExit );


    /* Neues Menu 'Ansicht' erzeugen */
    m_MenuView = new QMenu( QString::fromUtf8( "&Ansicht" ) );
	m_MenuView->addAction( m_aViewGhostMode );
	m_MenuView->addAction( m_aViewWireFrame );
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




/*!
    \fn BR_MainWindow::slotProjectOpen()
 */
void BR_MainWindow::slotProjectOpen()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(
                   this,
                   QString::fromUtf8( "Öffnen" ),
				   QDir::homePath(),
                   "glBB Projekt-Datei (*.glbb)" );

    // 	cout << "filename : " << filename.toStdString() << endl;


    if ( !filename.isEmpty() )
    {
        slotProjectClose();
        if ( !m_Doc.open( filename ) )

        {
            QMessageBox::critical( this,
                                   QString::fromUtf8( "Fehler beim Öffnen des Projektes" ),
                                   QString::fromUtf8( "Projekt konnte nicht geöffnet werden" ) );
        }
        else
        {
			m_Doc.createGlObjects();
            m_ViewWidget->setEnabled( true );
			
			QString info = m_Doc.getName() + "\n\n\n" + m_Doc.getDescription();
			
			m_InfoWidget->setText( info );
        }
    }
}


/*!
    \fn BR_MainWindow::slotProjectClose()
 */
void BR_MainWindow::slotProjectClose()
{
    m_Doc.close();
    m_ViewWidget->setEnabled( false );
	QString info("Kein Projekt geladen.");
	m_InfoWidget->setText( info );
}


/*!
    \fn BR_MainWindow::slotViewGhostMode( bool value )
 */
void BR_MainWindow::slotViewGhostMode( bool value )
{
	QString info;
	if( value )
	{
		info = "Geist-Modus eingeschaltet";
	}
	else
	{
		info = "Geist-Modus ausgeschaltet";
	}
	m_StatusBar->showMessage( info, 2000);
	m_ViewWidget->setGhostMode( value );
}


/*!
    \fn BR_MainWindow::slotViewWireFrame( bool value )
 */
void BR_MainWindow::slotViewWireFrame( bool value )
{
	QString info;
	if( value )
	{
		info = "WireFrame-Modus eingeschaltet";
	}
	else
	{
		info = "WireFrame-Modus ausgeschaltet";
	}
	m_StatusBar->showMessage( info, 2000);
	m_ViewWidget->setWireFrame( value );
}
