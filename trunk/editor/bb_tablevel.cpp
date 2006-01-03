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
#include "bb_tablevel.h"
#include "bb_globals.h"

#include <bb_tools.h>

BB_TabLevel::BB_TabLevel( BB_Doc * doc, QWidget* parent, Qt::WFlags f )
        : BB_Tab( doc, parent, f )
{

    m_Buildings = m_Doc->getBuildings();
    m_ListWidgetBuildings = NULL;

    m_Levels = NULL;
    m_ListWidgetLevels = NULL;

    initWidgetLeft();

    initTools();
}


BB_TabLevel::~BB_TabLevel()
{}




/*!
    \fn BB_TabLevel::slotLevelNew()
 */
void BB_TabLevel::slotLevelNew()
{
    cout << "Neu!!" << endl;

}


/*!
    \fn BB_TabLevel::slotLevelProperties()
 */
void BB_TabLevel::slotLevelProperties()
{
    cout << "Eigenschaften!!" << endl;
}


/*!
    \fn BB_TabLevel::slotLevelDelete()
 */
void BB_TabLevel::slotLevelDelete()
{
    cout << "Löschen? ... ";
    if ( QMessageBox::question( this, "Frage?", "sicher?", QMessageBox::Yes, QMessageBox::No ) == QMessageBox::Yes )
        cout << "Gelöscht!" << endl;
    else
        cout << "Abgebrochen" << endl;
}


/**
 * TODO
 */
void BB_TabLevel::slotZoomTool( QAction* action )
{
    unsetToolButton( action );
    action->setChecked( true );
    m_Center->setTool( m_ToolZoom );
    cout << "m_ToolZoom:" << m_ToolZoom << endl;
}


/*!
    \fn BB_TabLevel::initWidgetLeft()
 */
void BB_TabLevel::initWidgetLeft()
{
    QGroupBox * gB_Buildings = new QGroupBox();
    gB_Buildings->setTitle( QString::fromUtf8( "Gebäude" ) );
    gB_Buildings->setFlat( true );

    m_ListWidgetBuildings = new QListWidget();
	connect( m_ListWidgetBuildings, SIGNAL( currentRowChanged ( int ) ), this, SLOT( slotBuildingChanged( int ) ) );
	
    QVBoxLayout *gBL_Building = new QVBoxLayout();
    gBL_Building->setMargin( 0 );
    gBL_Building->setSpacing( 2 );
    gBL_Building->addWidget( m_ListWidgetBuildings, Qt::AlignTop );

    gB_Buildings->setLayout( gBL_Building );
    addWidgetLeft( gB_Buildings, 0 );

    QGroupBox *gB_Levels = new QGroupBox();
    gB_Levels->setTitle( QString::fromUtf8( "Etagen" ) );
    gB_Levels->setFlat( true );

    m_ListWidgetLevels = new QListWidget();
    m_ListWidgetLevels->addItem( "Etage 1" );
    m_ListWidgetLevels->addItem( "Etage 2" );
    m_ListWidgetLevels->addItem( "Etage 3" );
    m_ListWidgetLevels->addItem( "Etage 4" );
    m_ListWidgetLevels->addItem( "Etage 5" );
    m_ListWidgetLevels->addItem( "Etage 6" );
    m_ListWidgetLevels->addItem( "Etage 7" );
    m_ListWidgetLevels->addItem( "Etage 8" );
    m_ListWidgetLevels->addItem( "Etage 9" );
    m_ListWidgetLevels->addItem( "Etage 10" );
    m_ListWidgetLevels->addItem( "Etage 11" );



    QVBoxLayout *gBL_Levels = new QVBoxLayout();
    gBL_Levels->setMargin( 0 );
    gBL_Levels->setSpacing( 2 );
    gBL_Levels->addWidget( m_ListWidgetLevels, Qt::AlignTop );

    m_ButtonLevelNew = new QPushButton( QString::fromUtf8( "Hinzufügen" ) );

    m_ButtonLevelDelete = new QPushButton( QString::fromUtf8( "Löschen" ) );
    // 	m_ButtonLevelDelete->setEnabled(false);

    m_ButtonLevelProperties = new QPushButton( QString::fromUtf8( "Eigenschaften" ) );
    // 	m_ButtonLevelProperties->setEnabled(false);

    connect( m_ButtonLevelNew, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelNew() ) );
    connect( m_ButtonLevelDelete, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelDelete() ) );
    connect( m_ButtonLevelProperties, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelProperties() ) );

    gBL_Levels->addWidget( m_ButtonLevelNew, Qt::AlignTop );
    gBL_Levels->addWidget( m_ButtonLevelDelete, Qt::AlignTop );
    gBL_Levels->addWidget( m_ButtonLevelProperties, Qt::AlignTop );


    gB_Levels->setLayout( gBL_Levels );

    addWidgetLeft( gB_Levels, 1 );
}


/*!
    \fn BB_TabLevel::initWidgetRight()
 */
void BB_TabLevel::initWidgetRight()
{
    /// @todo implement me
}


/*!
    \fn BB_TabLevel::initTools()
 */
void BB_TabLevel::initTools()
{
    QAction * initTool;

    initTool = addTool( new BB_ToolMove( this ), "Move", "Bewegungs Werkzeug" );
    addTool( new BB_ToolScale( this ), QString::fromUtf8( "Maßstab" ), QString::fromUtf8( "Maßstab Werkzeug" ) );
    addTool( new BB_ToolZoom( m_Center, this ), "Zoom", QString::fromUtf8( "Zoom Werkzeug" ) );
    addTool( new BB_ToolPointNew( this ), "Knoten-Werkzeug", "Werkzeug zum Erstellen von Knoten" );
    addTool( new BB_ToolWallNew( this ), "Wand-Werkzeug", QString::fromUtf8( "Werkzeug zum Erstellen von Wänden" ) );
    addTool( new BB_ToolNavigationPointNew( this ), "Navigationsknoten", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationsknoten" ) );
    addTool( new BB_ToolNavigationLineNew( this ), "Navigationslinien", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationslinien" ) );

    setTool( initTool );
}


/*!
    \fn BB_TabLevel::updateBuildingList()
 */
void BB_TabLevel::updateBuildingList()
{
    m_ListWidgetBuildings->clear();

    if ( m_Buildings != NULL )
    {
        for ( int i = 0; i < m_Buildings->count(); i++ )
        {
            m_ListWidgetBuildings->addItem( m_Buildings->at( i ) ->getName() );
        }
    }
}


/*!
    \fn BB_TabLevel::updateLevelList()
 */
void BB_TabLevel::updateLevelList()
{
    m_ListWidgetLevels->clear();

    if ( m_ListWidgetLevels != NULL )
    {
        for ( int i = 0; i < m_ListWidgetLevels->count(); i++ )
        {
            m_ListWidgetLevels->addItem( m_Buildings->at( i ) ->getName() );
        }
    }
}


/*!
    \fn BB_TabLevel::documentChanged()
 */
void BB_TabLevel::documentChanged()
{
    updateBuildingList();
    updateLevelList();
}


/*!
    \fn BB_TabLevel::updateLists()
 */
void BB_TabLevel::updateLists()
{
    updateBuildingList();
    updateLevelList();
}


/*!
    \fn BB_TabLevel::slotBuildingChanged( int row )
 */
void BB_TabLevel::slotBuildingChanged( int row )
{
	qDebug("dslkfjlsdkföj");
}


/*!
    \fn BB_TabLevel::setBuilding()
 */
void BB_TabLevel::setBuilding( BB_Building* building )
{
	if( building != NULL )
	{
		m_Building = building;
		m_Levels = building->getLevels();
	}
	else
	{
		m_Building = NULL;
		m_Levels = NULL;
	}
	
	updateLists();
}
