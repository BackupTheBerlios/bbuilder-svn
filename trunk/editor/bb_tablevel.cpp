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


/**
 * Konstruktor.
 * Erstellt ein neues Etagen-Tab.
 * @param doc Dokument, welches die Daten enthält.
 * @param parent Das Parent-Fenster
 * @param f QtWindowFlags
 * @author Alex Letkemann
 */
BB_TabLevel::BB_TabLevel( BB_Doc * doc, QWidget* parent, Qt::WFlags f )
        : BB_Tab( doc, parent, f )
{

    m_Building = NULL;
    m_Buildings = m_Doc->getBuildings();
    m_ComboBoxBuildings = NULL;

    m_Levels = NULL;
    m_ListWidgetLevels = NULL;

    initWidgetLeft();

    initTools();
}

/**
 * Destruktor
 */
BB_TabLevel::~BB_TabLevel()
{}




/**
 * Startet ein Dialog zum erstellen einer neuen Etage
 * @author Alex Letkemann
 */
void BB_TabLevel::slotLevelNew()
{
    if ( m_Building != NULL )
    {
        m_Doc->newLevel( m_Building, this );
        updateLevelList();

        m_ListWidgetLevels->setCurrentRow( -1 );

    }
}


/**
 * Startet ein Dialog zum Bearbeiten der aktuellen Etage
 * @author Alex Letkemann
 */
void BB_TabLevel::slotLevelProperties()
{
    if ( m_Building != NULL )
    {
        BB_Level * level = m_Building->getLevel( m_ListWidgetLevels->currentRow() );
        if ( level != NULL )
        {
            level->keyBoardEdit( this );
        }
    }
}


/**
 * Löscht die Aktuelle Etage
 * @author Alex Letkemann
 */
void BB_TabLevel::slotLevelDelete()
{
    if ( m_Building != NULL )
    {
        BB_Level * level = m_Building->getLevel( m_ListWidgetLevels->currentRow() );
        if ( level != NULL )
        {
            m_Doc->deleteLevel( level );
			m_Center->setDocComponent( NULL );
        }
    }
}



/**
 * Initialisiert das linke Fenster
 * @author Alex Letkemann
 */
void BB_TabLevel::initWidgetLeft()
{
    QGroupBox * gB_Buildings = new QGroupBox();
    gB_Buildings->setTitle( QString::fromUtf8( "Gebäude" ) );
    gB_Buildings->setFlat( true );

    m_ComboBoxBuildings = new QComboBox();
	connect( m_ComboBoxBuildings, SIGNAL( currentIndexChanged ( int ) ), this, SLOT( slotBuildingChanged( int ) ) );


    QVBoxLayout *gBL_Building = new QVBoxLayout();
    gBL_Building->setMargin( 0 );
    gBL_Building->setSpacing( 2 );
    gBL_Building->addWidget( m_ComboBoxBuildings, Qt::AlignTop );

    gB_Buildings->setLayout( gBL_Building );
    addWidgetLeft( gB_Buildings, 0 );

    QGroupBox *gB_Levels = new QGroupBox();
    gB_Levels->setTitle( QString::fromUtf8( "Etagen" ) );
    gB_Levels->setFlat( true );

    m_ListWidgetLevels = new QListWidget();

    connect( m_ListWidgetLevels, SIGNAL( currentRowChanged ( int ) ), this, SLOT( slotLevelChanged( int ) ) );

    QVBoxLayout *gBL_Levels = new QVBoxLayout();
    gBL_Levels->setMargin( 0 );
    gBL_Levels->setSpacing( 2 );
    gBL_Levels->addWidget( m_ListWidgetLevels, Qt::AlignTop );

    m_ButtonLevelNew = new QPushButton( QString::fromUtf8( "Hinzufügen" ) );

    m_ButtonLevelDelete = new QPushButton( QString::fromUtf8( "Löschen" ) );

    m_ButtonLevelProperties = new QPushButton( QString::fromUtf8( "Eigenschaften" ) );

    connect( m_ButtonLevelNew, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelNew() ) );
    connect( m_ButtonLevelDelete, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelDelete() ) );
    connect( m_ButtonLevelProperties, SIGNAL( clicked( bool ) ), this, SLOT( slotLevelProperties() ) );

    gBL_Levels->addWidget( m_ButtonLevelNew, Qt::AlignTop );
    gBL_Levels->addWidget( m_ButtonLevelDelete, Qt::AlignTop );
    gBL_Levels->addWidget( m_ButtonLevelProperties, Qt::AlignTop );


    gB_Levels->setLayout( gBL_Levels );

    addWidgetLeft( gB_Levels, 1 );
}


/**
 * Initialisiert die Tools
 * @author Alex Letkemann
 */
void BB_TabLevel::initTools()
{
    QAction * initTool;

    initTool = addTool( new BB_ToolMove( this ), "Move", "Bewegungs Werkzeug" );
    addTool( new BB_ToolScale( this ), QString::fromUtf8( "Maßstab" ), QString::fromUtf8( "Maßstab Werkzeug" ) );
    addTool( new BB_ToolZoom( m_Center, this ), "Zoom", QString::fromUtf8( "Zoom Werkzeug" ) );
    addTool( new BB_ToolPointNew( this ), "Knoten-Werkzeug", "Werkzeug zum Erstellen von Knoten" );
    addTool( new BB_ToolWallNew( this ), "Wand-Werkzeug", QString::fromUtf8( "Werkzeug zum Erstellen von Wänden" ) );
//     addTool( new BB_ToolNavigationPointNew( this ), "Navigationsknoten", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationsknoten" ) );
//     addTool( new BB_ToolNavigationLineNew( this ), "Navigationslinien", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationslinien" ) );
	addTool( new BB_ToolLevelTriangleNew(this), QString::fromUtf8("Flächen-Werkzeug"), QString::fromUtf8( "Werkzeug zum erstellen von Böden unde Decken " ));

    setTool( initTool );
}


/**
 * Aktualisert die Gebäudeliste
 * @author Alex Letkemann
 */
void BB_TabLevel::updateBuildingList()
{	
//     qDebug( "Updating BuildingList ... " );
    m_ComboBoxBuildings->blockSignals( true );
	
	int index = m_ComboBoxBuildings->currentIndex();

    m_ComboBoxBuildings->clear();

    if ( m_Buildings != NULL )
    {
        for ( int i = 0; i < m_Buildings->count(); i++ )
        {
            m_ComboBoxBuildings->addItem( m_Buildings->at( i ) ->getName() );
        }
    }

	m_ComboBoxBuildings->setCurrentIndex( index );
	setBuilding( m_Doc->getBuilding( index ) );
    m_ComboBoxBuildings->blockSignals( false );
//     qDebug( "OK" );

}


/**
 * Aktualisert die Etagenliste
 * @author Alex Letkemann
 */
void BB_TabLevel::updateLevelList()
{
//     qDebug( "Updating LevelList ... " );
    m_ListWidgetLevels->blockSignals( true );

    m_ListWidgetLevels->clear();

    if ( m_Building != NULL )
    {
        for ( int i = 0; i < m_Building->getLevelCount(); i++ )
        {
            m_ListWidgetLevels->addItem( m_Building->getLevel( i ) ->getName() );
        }
    }

    m_ListWidgetLevels->blockSignals( false );
//     qDebug( "OK" );
}


/**
 * Wird aufgerufen, wenn das Dokument (m_Doc) sich ändert.
 * @author Alex Letkemann
 */
void BB_TabLevel::documentChanged()
{
	setBuilding( NULL );
	
    updateBuildingList();
    updateLevelList();
	
	if( m_Buildings->count() == 1 )
	{
		setBuilding( m_Buildings->at(0) );
	}
}


/**
 * Aktualisert die Listen
 * @author Alex Letkemann
 */
void BB_TabLevel::updateLists()
{
    updateBuildingList();
    updateLevelList();
}


/**
 * Wird aufgerufen, wenn das Geböude geändert wird.
 * Aktualisert die Listen.
 * @param row Index des Gebäudes.
 * @author Alex Letkemann
 */
void BB_TabLevel::slotBuildingChanged( int row )
{
//     qDebug() << "Setting building ... ";
    setBuilding( m_Doc->getBuilding( row ) );
//     qDebug() << "OK";
	
}


/**
 * Setzt das Gebäude, dessen Etagen bearbeitet werden sollen.
 * @param building Gebäude, dessen Etagen bearbeitet werden sollen
 * @author Alex Letkemann
 */
void BB_TabLevel::setBuilding( BB_Building* building )
{
    if ( building != NULL )
    {
        m_Building = building;
        m_Levels = building->getLevels();

        setWidgetEnabled( true );
    }
    else
    {
        m_Building = NULL;
        m_Levels = NULL;
        setWidgetEnabled( false );
    }
    updateLevelList();
}


/**
 * Setzt die Etage, die Bearbeitet werden soll.
 * @param level Etage, die Bearbeitet werden soll
 * @author Alex Letkemann
 */
void BB_TabLevel::setLevel( BB_Level* level )
{
    qDebug() << "Setting level ... ";
    m_Center->setDocComponent( level );
    qDebug() << "OK";
}


/**
 * Aktiviert oder Deaktiviert das Tab-Fenster
 * @param value True: Aktiviert, False: Deaktiviert
 * @author Alex Letkemann
 */
void BB_TabLevel::setWidgetEnabled( bool value )
{
    m_ButtonLevelDelete->setEnabled( value );
    m_ButtonLevelProperties->setEnabled( value );
    m_ButtonLevelNew->setEnabled( value );

    m_ListWidgetLevels->setEnabled( value );
    m_Center->setEnabled( value );
}


 /**
 * Wird aufgerufen, wenn die Etage geändert wird.
 * Aktualisert die Arbeitsfläche.
 * @param row Index der Etage.
 * @author Alex Letkemann
  */
void BB_TabLevel::slotLevelChanged( int row )
{
    if ( m_Building != NULL )
    {
        setLevel( m_Building->getLevel( row ) );
    }
}


/**
 * Speichert die Aktuelle Etage
 * @return Erfolg des Seicherns. True im Erfolg, sonst false
 * @author Alex Letkemann
 */
bool BB_TabLevel::saveCurrent()
{
    BB_Level * level = m_Building->getLevel( m_ListWidgetLevels->currentRow( ) );

    if ( level != NULL )
    {
        return level->save() && BB_Tab::saveCurrent();
    }

    return false;
}
