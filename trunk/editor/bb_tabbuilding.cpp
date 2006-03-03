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
#include "bb_globals.h"

#include "bb_tabbuilding.h"

#include <iostream>

#include "bb_point.h"

#include <bb_tools.h>

using namespace std;


/**
 * Konstruktor.
 * Erstellt ein neues Gebäude.
 * @param doc Doc, welches die Daten enthält.
 * @param parent Das Parent-Fenster
 * @param f QtWindowFlags
 */
BB_TabBuilding::BB_TabBuilding( BB_Doc * doc, QWidget* parent, Qt::WFlags f )
        : BB_Tab( doc, parent, f )
{

    if ( m_Doc->getBuildings() != NULL )
        m_Buildings = m_Doc->getBuildings();
    else
    {
        cout << "BB_TabBuilding::BB_TabBuilding(): Ungültiger Vector (NULL)" << endl;
    }

    m_BuildingsListCreated = false;

    initWidgetLeft();
    initWidgetRight();

    initTools();

}


/** Destruktor */
BB_TabBuilding::~BB_TabBuilding()
{}


/**
 * Initialisiert das linke Tool-Fenster
 */
void BB_TabBuilding::initWidgetLeft()
{
    QGroupBox * gB_Buildings = new QGroupBox();
    gB_Buildings->setTitle( QString::fromUtf8( "Gebäude" ) );
    gB_Buildings->setFlat( true );

    m_BuildingsListWidget = new QListWidget();
    connect( m_BuildingsListWidget,
             SIGNAL( currentItemChanged( QListWidgetItem *, QListWidgetItem * ) ),
             this,
             SLOT( slotBuildingChanged( QListWidgetItem *, QListWidgetItem * ) ) );

    QVBoxLayout *gBL_Buildings = new QVBoxLayout();
    gBL_Buildings->setMargin( 0 );
    gBL_Buildings->setSpacing( 2 );
    gBL_Buildings->addWidget( m_BuildingsListWidget, Qt::AlignTop );

    m_ButtonBuildingNew = new QPushButton( QString::fromUtf8( "Hinzufügen" ) );

    m_ButtonBuildingDelete = new QPushButton( QString::fromUtf8( "Löschen" ) );
    // 	m_ButtonLevelDelete->setEnabled(false);

    m_ButtonBuildingProperties = new QPushButton( QString::fromUtf8( "Eigenschaften" ) );
    // 	m_ButtonLevelProperties->setEnabled(false);

    connect( m_ButtonBuildingNew, SIGNAL( clicked( bool ) ), this, SLOT( slotBuildingNew() ) );
    connect( m_ButtonBuildingDelete, SIGNAL( clicked( bool ) ), this, SLOT( slotBuildingDelete() ) );
    connect( m_ButtonBuildingProperties, SIGNAL( clicked( bool ) ), this, SLOT( slotBuildingProperties() ) );

    gBL_Buildings->addWidget( m_ButtonBuildingNew, Qt::AlignTop );
    gBL_Buildings->addWidget( m_ButtonBuildingDelete, Qt::AlignTop );
    gBL_Buildings->addWidget( m_ButtonBuildingProperties, Qt::AlignTop );


    gB_Buildings->setLayout( gBL_Buildings );

    addWidgetLeft( gB_Buildings, 1 );
}


/**
 * Wird aufgerufen, wenn der Button 'Löschen' auf der linken Seite gedrückt wird.
 * Löscht das aüsgewählte Gebäude.
 * @author Alex Letkemann
 */
void BB_TabBuilding::slotBuildingDelete()
{

    BB_Building * building = m_Doc->getBuilding( m_BuildingsListWidget->currentItem() );

    if ( building != NULL )
    {
        if ( QMessageBox::question( this,
                                    QString::fromUtf8( "Bestätigung" ),
                                    QString::fromUtf8( "Möchten Sie das Gebäude " )
                                    + building->getName()
                                    + QString::fromUtf8( " wirklich löschen?" ),
                                    QMessageBox::Yes,
                                    QMessageBox::No ) == QMessageBox::Yes )
        {


            unsetDocComponent();

            // Gebäude aus der Liste entfernen
            m_BuildingsListWidget->takeItem( m_BuildingsListWidget->row( building->getListWidgetItem() ) );

            // Gebäude löschen
            m_Doc->deleteBuilding( building->getListWidgetItem() );
            building = NULL;

            // Änderung speichern
            m_Doc->save();

        }
    }
}


/**
 * Wird aufgerufen, wenn der Button 'Neu' auf der linken Seite gedrückt wird.
 * Lässt ein neues Gebäude erstellen.
 * @author Alex Letkemann
 */
void BB_TabBuilding::slotBuildingNew()
{
    BB_Building * building = m_Doc->newBuilding( this );
    if ( building != NULL )
    {
        m_BuildingsListWidget->addItem( building->getListWidgetItem() );
        m_BuildingsListWidget->setCurrentItem( building->getListWidgetItem() );
    }
}


/**
 * Startet einen Dialog zum Bearbeiten der Eigenschaften eines Gebäudes
 * @author Alex Letkemann
 */
void BB_TabBuilding::slotBuildingProperties()
{
    BB_Building * building = m_Doc->getBuilding( m_BuildingsListWidget->currentItem() );

    if ( building != NULL )
    {
        building->keyBoardEdit( this );
    }
}

/**
 * Initialisiert alle Tools
 */
void BB_TabBuilding::initTools()
{

    QAction * initTool;


    /* Tools dem Tab hinzufügen */
	initTool = addTool( new BB_ToolMove( this ), "Move", "Bewegungs Werkzeug" );
	addTool( new BB_ToolScale( this ), QString::fromUtf8( "Maßstab" ), QString::fromUtf8( "Maßstab Werkzeug" ) );
	addTool( new BB_ToolZoom( m_Center, this ), "Zoom", QString::fromUtf8( "Zoom Werkzeug" ) );
	addTool( new BB_ToolPointNew( this ), "Knoten-Werkzeug", "Werkzeug zum Erstellen von Knoten" );
	addTool( new BB_ToolWallNew( this ), "Wand-Werkzeug", QString::fromUtf8( "Werkzeug zum Erstellen von Wänden" ) );
// 	addTool( new BB_ToolNavigationPointNew( this ), "Navigationsknoten", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationsknoten" ) );
// 	addTool( new BB_ToolNavigationLineNew( this ), "Navigationslinien", QString::fromUtf8( "Werkzeug zur Erstellung von Navigationslinien" ) );
	addTool( new BB_ToolBuildingTriangleNew(this), QString::fromUtf8( "Fläche"), QString::fromUtf8( "Werkzeug zum markieren von Flächen, wo das Dach un der Grund eines Gebäudes dargestellt werden soll" ));
	addTool( new BB_ToolStair(this), "Treppe", QString::fromUtf8("Werkzeug zur Erstellung von Treppen"));

    /* Ein Tool als Standard festlegen */
    toolChanged( initTool );
}


/**
 * Initialisiert das rechte Fenster
 */
void BB_TabBuilding::initWidgetRight()
{
	
}



/**
 * Erzeugt die Gebäude-Liste.
 * @author Alex Letkemann
 */
void BB_TabBuilding::createBuildingList()
{
    if ( !m_BuildingsListCreated )
    {
        for ( int i = 0; i < m_Buildings->count(); i++ )
        {
            m_BuildingsListWidget->addItem( m_Buildings->at( i ) ->getListWidgetItem() );
        }
        m_BuildingsListCreated = true;
    }
    else
    {
        qDebug( "Kann die Liste nicht nochmal erstellen.\n" );
    }
}


/**
 * Leert die aktuelle Liste und löscht das 'Luste-Erstellt'-Flag,
 * damit eine neue Liste erstellt werden kann.
 * @author Alex Letkemann
 */
void BB_TabBuilding::clear()
{
    m_BuildingsListWidget->clear();
    m_BuildingsListCreated = false;
}


/**
 * Wird aufgerufen, wenn der User ein anderes Gebäude in der Liste auswählt.
 * Setzt das neue DocComponent in die Arbeitsfläche.
 * @param current Das QListWidgetItem des neuen Gebäudes.
 * @param previous Das QListWidgetItem des letzen Gebäudes.
 * @author Alex Letkemann
 */
void BB_TabBuilding::slotBuildingChanged( QListWidgetItem * current, QListWidgetItem * previous )
{
	
	previous = NULL;
    BB_Building * building = m_Doc->getBuilding( current );

    // Das Tool zurücksetzen
    if ( m_Center->getTool() != NULL )
    {
        m_Center->getTool() ->reset();
    }

    if ( building != NULL )
    {
        m_Center->setDocComponent( building );
        m_Center->setEnabled( true );
    }
}


/**
 * Speichert das aktuelle Gebäude
 * @return Erfolg des Speicherns. True im Erfolg, sonst false.
 * @author Alex Letkemann
 */
bool BB_TabBuilding::saveCurrent()
{
    BB_Building * building;

    building = m_Doc->getBuilding( m_BuildingsListWidget->currentItem () );
    if ( building != NULL )
    {
		return ( building->save() && BB_Tab::saveCurrent() );
    }
    else
    {
        qDebug( "Kein Gebäude ausgewählt" );
    }

    return false;
}


/**
 * Aktualisiert die Gebäudeliste
 * @author Alex Letkemann
 */
void BB_TabBuilding::updateLists()
{
	createBuildingList();
}
