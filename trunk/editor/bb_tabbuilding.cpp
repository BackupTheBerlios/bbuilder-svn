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

    // 	updateBuildingList();
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

			
//             m_Center->setEnabled( false );
			if( m_BuildingsListWidget->count() > 0 )
			{
// 				m_BuildingsListWidget->setCurrentRow( - 1 );	
			}
        }
    }
}


/**
 * Wird aufgerufen, wenn der Button 'Neu' auf der linken Seite gedrückt wird.
 * Lässt ein neues Gebäude erstellen.
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
 * Updated das Fenster.
 */
void BB_TabBuilding::updateWidget()
{
    //     updateBuildingList();
}


/**
 * Initialisiert alle Tools
 */
void BB_TabBuilding::initTools()
{

	QAction* initTool;
    
	/* Tools erzeugen */
    m_ToolMove = new BB_ToolMove(this);
	m_ToolScale = new BB_ToolScale( this );
	m_ToolZoom = new BB_ToolZoom( m_Center );
	m_ToolPointNew = new BB_ToolPointNew(this);
	m_ToolWallNew = new BB_ToolWallNew( m_Center );
	
	
	/* Tools dem Tab hinzufügen */
	initTool = addTool( m_ToolMove, "Move", "Bewegungs Werkzeug" );
	addTool( m_ToolScale, QString::fromUtf8("Maßstab"), QString::fromUtf8("Maßstab Werkzeug") );
	addTool( m_ToolZoom, "Zoom", QString::fromUtf8("Zoom Werkzeug") );
	addTool( m_ToolPointNew, "Knoten-Werkzeug", "Werkzeug zum Erstellen von Knoten");
	addTool( m_ToolWallNew, "Wand-Werkzeug", QString::fromUtf8("Werkzeug zum Erstellen von Wänden") );
	

	/* Ein Tool als Standard festlegen */
    toolChanged( initTool );
}


/**
 * Initialisiert das rechte Fenster
 */
void BB_TabBuilding::initWidgetRight()
{
    //     m_PropertyWidget = new BB_PropertyWidget();

    //     addWidgetRight( m_PropertyWidget );
}


/**
 * Verarbeitet die Tools von BB_TabBuilding und übergibt diese weiter an die Arbeitfläche.
 * @param action Aktion des Tools, welches Betätigt wurde.
 */
void BB_TabBuilding::toolChanged( QAction* action )
{

    if ( m_ToolMove->getAction() == action )
    {
		setTool( m_ToolMove );
    }
    else if ( m_ToolZoom->getAction() == action )
    {
		setTool( m_ToolZoom );
    }
    else if ( m_ToolPointNew->getAction() == action )
    {
		setTool( m_ToolPointNew );
    }
    else if ( m_ToolWallNew->getAction() == action )
    {
		setTool( m_ToolWallNew );
    }
    else if ( m_ToolScale->getAction() == action )
    {
		setTool( m_ToolScale );
    }
    else
    {
		qDebug( "Unbekanntes Tool\n" );
    }

    m_Center->update();
}


/**
 * Erzeugt die Gebäude-Liste. 
 */
void BB_TabBuilding::createBuildingList()
{
    if ( !m_BuildingsListCreated )
    {
        cout << m_Buildings->count() << endl;
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
 */
void BB_TabBuilding::clear()
{
    m_BuildingsListWidget->clear();
    m_BuildingsListCreated = false;
}


/**
 ///@todo ???
 */
void BB_TabBuilding::slotBuildingChanged( QListWidgetItem * current, QListWidgetItem * previous )
{
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
 */
bool BB_TabBuilding::saveCurrent()
{
    BB_Building * building;

    building = m_Doc->getBuilding( m_BuildingsListWidget->currentItem () );
    if ( building != NULL )
    {
        return building->save();
    }
    else
    {
        qDebug( "Kein Gebäude ausgewählt\n" );
    }

    return false;
}
