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
#include "bb_tab.h"

#include <QHBoxLayout>
#include "bb_workarea.h"


BB_Tab::BB_Tab( BB_Doc* doc, QWidget* parent, Qt::WFlags f ) : QWidget( parent, f )
{
    setDoc( doc );

    initTab();


    m_DrawObjects = NULL;
}

// BB_Tab::BB_Tab( BB_Doc* doc, bool leftFrame, bool rightFrame, QWidget* parent, Qt::WFlags f ) : QWidget( parent, f )
// {
//     setDoc( doc );
//
//     initTab();
//     initLayout( leftFrame, rightFrame );
// }


BB_Tab::~BB_Tab()
{
    m_Doc = NULL;

    //     delete m_ToolButtonActions;
    delete m_Center;
    if ( m_LeftFrame != NULL )
        delete m_LeftFrame;
    if ( m_RightFrame != NULL )
        delete m_RightFrame;

    // TODO m_ToolsGridLayout lässt sich nicht löschen
    // 	if(m_ToolsGridLayout != NULL)
    // 		delete m_ToolsGridLayout;
}

/*
 * Initialisiert alle wichtigen Einstellungen des Tabs.
 * Wird als Erstes in jedem Konstruktor aufgerufen werden.
 */
void BB_Tab::initTab()
{
    m_ToolButtonCount = 0;
    //     m_ToolButtonActions = new QList<QAction*>();

    m_ToolsGridLayout = NULL;
    m_LeftFrame = NULL;
    m_RightFrame = NULL;

    initLayout( true, true );
}



/**
 * Erzeugt das Layout für das Tab-Fenster
 */
void BB_Tab::initLayout( bool leftFrame, bool rightFrame )
{
    int iFrames = 0;

    QSplitter *splitter = new QSplitter( this );
    if ( leftFrame )
    {
        m_LeftFrame = new QFrame();
        m_LeftFrame->setFrameShape( QFrame::Box );
        m_LeftFrame->setFrameShadow( QFrame::Sunken );

        m_LeftFrame->setFixedWidth( 160 );

        QVBoxLayout *leftLayout = new QVBoxLayout();
        leftLayout->setMargin( 0 );
        leftLayout->setSpacing( 5 );

        /* GroupBox für die ToolButtons */
        QGroupBox *groupBox = new QGroupBox( NULL );
        groupBox->setObjectName( QString::fromUtf8( "leftFrameTools" ) );
        groupBox->setFlat( true );
        groupBox->setTitle( QString::fromUtf8( "Tools" ) );

        m_ToolsGridLayout = new QGridLayout();
        m_ToolsGridLayout->setMargin( 2 );

        groupBox->setLayout( m_ToolsGridLayout );


        leftLayout->addWidget( groupBox );
        leftLayout->setStretchFactor( groupBox, 0 );

        m_LeftFrame->setLayout( leftLayout );

        splitter->addWidget( m_LeftFrame );
        splitter->setCollapsible( iFrames, true );
        splitter->setStretchFactor( iFrames, 0 );
        iFrames++;

        m_LeftFrame->setGeometry(
            m_LeftFrame->x(),
            m_LeftFrame->y(),
            160,
            m_LeftFrame->height() );
    }
    else
        m_LeftFrame = NULL;

    m_Center = new BB_WorkArea( &m_Selection );
    m_Center->setFrameShape( QFrame::Box );
    m_Center->setFrameShadow( QFrame::Sunken );

    splitter->addWidget( m_Center );
    splitter->setCollapsible( iFrames, false );
    splitter->setStretchFactor( iFrames, 1 );

    iFrames++;

    if ( rightFrame )
    {
        m_RightFrame = new QStackedWidget();
        m_RightFrame->setFrameShape( QFrame::Box );
        m_RightFrame->setFrameShadow( QFrame::Sunken );
        m_RightFrame->setFixedWidth( 160 );

        splitter->addWidget( m_RightFrame );
        splitter->setCollapsible( iFrames, true );
        splitter->setStretchFactor( iFrames, 0 );
        iFrames++;

        m_RightFrame->setGeometry(
            m_RightFrame->x(),
            m_RightFrame->y(),
            160,
            m_RightFrame->height() );

        splitter->refresh();
    }
    else
    {
        m_RightFrame = NULL;
    }

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget( splitter );
    setLayout( layout );
}



/**
 * Erzeugt einen QToolButton und plaziert diesen im linken Frame.
 * Der QToolButton übernimmt die Eigenschaften von action wie Text, Icon usw. von action und wird 'connected' zu method.
 * @param action Die QAction, aus der der QToolButton erzeugt werden soll.
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 21.08.2005
 */
bool BB_Tab::createToolButton( QAction* action, BB_AbstractTool* tool )
{
    if ( action != NULL && tool != NULL )
    {
        action->setCheckable( true );
        action->setIcon( tool->getIcon() );
        tool->setAction( action );
        //         m_ToolButtonActions->append( action );

        QToolButton *button = new QToolButton();
        button->setToolButtonStyle( Qt::ToolButtonIconOnly );
        button->setFixedSize( 24, 24 );
        button->setDefaultAction( action );

        m_ToolsGridLayout->addWidget( button, m_ToolButtonCount / 5, m_ToolButtonCount % 5 );
        m_ToolButtonCount++;
        return connect( button, SIGNAL( triggered( QAction* ) ), this, SLOT( slotToolChanged( QAction* ) ) );
    }
    else
    {
        return false;
    }
}


/**
 * Hängt ein QWidget im linken Frame an
 * @param widget Das QWidget, dass angehängt werden soll
 * @param stretchFaktor Gibt an, ob und wie stark sich das Widget streckt wenn die Größe des Fensters verändert wird. Default ist 0
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 18.08.2005
 */
bool BB_Tab::addWidgetLeft( QWidget *widget, int stretchFaktor )
{
    if ( widget != NULL && m_LeftFrame != NULL )
    {
        widget->setFixedWidth( 156 );
        m_LeftFrame->layout() ->addWidget( widget );
        ( ( QVBoxLayout* ) m_LeftFrame->layout() ) ->setStretchFactor( widget, stretchFaktor );
        return true;
    }
    return false;
}

/**
 * Fügt ein Fenster zum StackWidget hinzu
 * @param widget Das QWidget, das im rechten StackWidget hinzugefügt werden soll
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 18.08.2005
 */
bool BB_Tab::addWidgetRight( QWidget *widget )
{
    if ( m_RightFrame != NULL && widget != NULL )
    {
        widget->setFixedWidth( 156 );
        m_RightFrame->addWidget( widget );



        return true;
    }

    return false;
}


/**
 * Setzt alle Actions der Toolbuttons außer 'action' auf unchecked.
 * @param action Aktion, welche nicht auf unchecked gesetzt werden soll. 
 */
void BB_Tab::unsetToolButton( QAction *action )
{
    for ( int i = 0; i < m_Tools.count(); i++ )
    {
        if ( m_Tools.at( i )->getAction() != action )
			 m_Tools.at( i )->getAction()->setChecked( false );
    }
}


/**
 * Prüft und setzt das Doc, welches verwendet wird.
 * Meldet sich als Observer beim Dokument an.
 * @param doc Doc, welches verwendet wird.
 * @author Alex Letkemann
 * @date 22.10.2005
 */
void BB_Tab::setDoc( BB_Doc* doc )
{
    if ( doc != NULL )
    {
        m_Doc = doc;
		m_Doc->addObserver( this );
    }
    else
    {
        qDebug( "BB_Tab(BB_Doc* doc, QWidget* parent, Qt::WFlags f): NULL-Pointer erhalten" );
        exit( 0 );
    }
}

/**
 * Setzt den DocComponent der Arbeitsfl&auml;che auf null und
 * deaktiviert diese damit;
 */
void BB_Tab::unsetDocComponent()
{
    m_Center->setDocComponent( NULL );
}


/**
 * Zeichnet das Fenster neu
 */
void BB_Tab::updateWidget()
{
    update();
}


/**
 * Wird aufgerufen, wenn ein Toolbutton angeclickt wird.
 * Ruft die Funktion toolChanged(..) auf.
 * @param action Aktion des ToolButtons
 */
void BB_Tab::slotToolChanged( QAction* action )
{
    toolChanged( action );

}



void BB_Tab::toolChanged( QAction* action )
{
    //     qDebug( "toolChanged(QAction* action) nicht implementiert (action: %p)\n", action );
    if ( m_Center->getTool() != NULL )
    {
        m_Center->getTool() ->reset();
    }
    setTool( action );
    updateWidget();
}


void BB_Tab::clear()
{
    unsetDocComponent();
}


/**
 * Die Funktion soll das aktuelle DocComponent des abgeleiteten Tabs speichern.
 * Diese funktion muss in jedem abgeleiteten Tab überladen werden, sonst erschein immer die Meldung: <br />
 * "BB_Tab::saveCurrent(): Funktion wurde nicht überladen" und es wird immer false zurückgegeben.
 * @return Erfolg des Speicherns; true = erfolgreich, false = erfolglos
 */
bool BB_Tab::saveCurrent()
{
    qDebug( "BB_Tab::saveCurrent(): Funktion wurde nicht überladen\n" );
    return false;
}


/**
 * Setzt das aktuelle Tool des Tabs zurück
 */
void BB_Tab::resetTool()
{
    if ( m_Center != NULL && m_Center->getTool() != NULL )
    {
        m_Center->getTool() ->reset();
    }
}


/*!
    \fn BB_Tab::addTool( BB_AbstractTool& tool, QIcon& icon, QString& name, QString& info )
 */
QAction* BB_Tab::addTool( BB_AbstractTool* tool, const QString& name, const QString& info )
{
    if ( &tool != NULL && &name != NULL && &info != NULL )
    {

        QAction * toolAction = new QAction( name, this );

        toolAction->setStatusTip( info );
        addWidgetRight( tool->getToolWidget() );
        createToolButton( toolAction, tool );

        m_Tools.append( tool );

        return toolAction;
    }

    return NULL;
}


/*!
    \fn BB_Tab::setTool( BB_AbstractTool* tool )
 */
void BB_Tab::setTool( BB_AbstractTool* tool )
{
    unsetToolButton( tool->getAction() );
    tool->getAction() ->setChecked( true );
    m_RightFrame->setCurrentWidget( tool->getToolWidget() );
    m_Center->setTool( tool );
}


/*!
    \fn BB_Tab::setTool( QAction * action )
 */
void BB_Tab::setTool( QAction * action )
{
    BB_AbstractTool * tool;
    for ( int i = 0; i < m_Tools.count() ; i++ )
    {
        tool = m_Tools.at( i );

        if ( tool->getAction() == action )
        {
            setTool( tool );
            return ;
        }
    }
    qDebug( "Tool nicht gefunden." );
}


/*!
    \fn BB_Tab::documentChanged()
 */
void BB_Tab::documentChanged()
{
	updateWidget();
}


/*!
    \fn BB_Tab::updateLists()
 */
void BB_Tab::updateLists()
{
    /// @todo implement me
}
