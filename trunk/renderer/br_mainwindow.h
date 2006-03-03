//
// C++ Interface: br_mainwindow
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BR_MAINWINDOW_H
#define BR_MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>

#include <br_view.h>
#include <br_infowidget.h>

#include <bb_doc.h>


/**
 * Haupfenster des Renderers.
 * Verwaltet die Menubar und die Statusbar und das zentrale Fenster,
 * in welchem die eigendliche Darstellung stattfindet.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BR_MainWindow : public QMainWindow
{
        Q_OBJECT
    public:
		/**
		 * Konstruktor
		 */
        BR_MainWindow( QWidget* parent = 0, Qt::WFlags flags = 0 );

		/**
		 * Destruktor
		 */
        ~BR_MainWindow();



    protected:


    protected:

        /** Informationsfenster */
        BR_View* m_ViewWidget;

        /** 'Datei'-Menu der Menubar */
        QMenu *m_MenuFile;

        /** 'Ansicht'-Menu der Menubar*/
        QMenu *m_MenuView;

        /** 'Navigations'-Menu des Haupfensters */
        QMenu *m_MenuNavi;

        /** Statusbar des Haupfensters */
        QStatusBar* m_StatusBar;

        /** Menubar des Haupfensters */
        QMenuBar* m_MainMenuBar;

        /** Aktion zum Beenden */
        QAction* m_aFileExit;

		/** Aktion für das Vollbild */
        QAction* m_aViewFullScreen;
		
		/** Animationstimer */
        QTimer* m_TimerAnimate;
		
		/** Timer zum zählen der FPS */
        QTimer* m_TimerFPS;
		
		/** Dokument */
        BB_Doc m_Doc;
		
		/** Informationsfenster */
        BR_InfoWidget* m_InfoWidget;
		
		/** Aktion zum Schliessen des Projektes */
        QAction* m_aProjectClose;
		
		/** Aktion zum Öffnen eines Projektes */
        QAction* m_aProjectOpen;
		
		/** Aktion für den Wireframe-Modus */
        QAction* m_aViewWireFrame;
		
		/** Aktion für der Geist-Modus */
        QAction* m_aViewGhostMode;


    private slots:
        /**
         * Schliesst das Programm
	     * @author Alex Letkemann
         */
        void slotFileExit();
		
        /**
         * Aktiviert / Deaktiviert Vollbild
         * @param value True: Activiert, False: Deaktiviert
		 * @author Alex Letkemann
         */
        void slotViewFullScreen ( bool value );
		
		/**
		 * Führ die Animation aus
		 * @author Alex Letkemann
		 */
        void slotTimerAnimation();
		
		/**
		 * Sendet die FPS an das Informationsfenster
		 * @author Alex Letkemann
		 */
        void slotTimerFPS();
		
		
        /**
		 * Startet ein Dialog zu Öffnen eines Projektes
		 * @author Alex Letkemann
         */
        void slotProjectOpen();
		
        /**
         * Schliesst das Projekt
		 * @author Alex Letkemann
         */
        void slotProjectClose();
		
		
        /**
         * Aktiviert / Deaktiviert den Geist-Modus
		 * @param value True: Activiert, False: Deaktiviert
		 * @author Alex Letkemann
         */
        void slotViewGhostMode( bool value );
		
        /**
         * Aktiviert / Deaktiviert den Wireframe-Modus
		 * @param value True: Activiert, False: Deaktiviert
		 * @author Alex Letkemann
         */
        void slotViewWireFrame( bool value );
		
    private:
		
        /**
        * Initialisiert alle Aktionen des Hauptfensters
        */
        void initActions();

        /**
         * Initialisiert das Hauptfenster
         */
        void initMainWindow();

        /**
         * Initialisiert die Menus des Hauptfensters
         */
        void initMenus();

        /**
         * Initialisiert die Statusbar des Hauptfensters
         */
        void initStatusBar();

        /**
         * Initialisiert die Timer
         */
        void initTimer();
};

#endif
