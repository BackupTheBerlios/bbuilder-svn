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
#include <br_doc.h>


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
	BR_MainWindow(QWidget* parent = 0, Qt::WFlags flags = 0);

    ~BR_MainWindow();


protected:

	
protected:
	
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
	
	QAction* m_aViewFullScreen;
    QTimer* m_TimerAnimate;
    QTimer* m_TimerFPS;
    BR_Doc m_Doc;
    BR_InfoWidget* m_InfoWidget;
	
	
private slots:
    void slotFileExit();
    void slotViewFullScreen ( bool value );
    void slotTimerAnimation();
    void slotTimerFPS();
private:
	void initActions();
	void initMainWindow();
	void initMenus();
	void initStatusBar();
    void initTimer();
};

#endif
