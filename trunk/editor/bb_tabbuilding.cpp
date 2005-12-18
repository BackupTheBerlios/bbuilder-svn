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
 * Konstrucktor.
 * Erstellt ein neues Gebäude.
 * @param doc Doc, welches die Daten enthält.
 * @param parent Das Parent-Fenster
 * @param f QtWindowFlags
 */
BB_TabBuilding::BB_TabBuilding( BB_Doc * doc, QWidget* parent, Qt::WFlags f )
        : BB_Tab( doc, true, true, parent, f )
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


/** Destrucktor */
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
	///@todo Auf QListWidgetItem umstellen
    BB_Building * building;
    int row = m_BuildingsListWidget->currentRow();
    if ( row != -1 )
    {
        building = m_Buildings->at( row );
        if ( QMessageBox::question( this,
                                    QString::fromUtf8( "Bestätigung" ),
                                    QString::fromUtf8( "Möchten Sie das Gebäude " )
                                    + building->getName()
                                    + QString::fromUtf8( " wirklich löschen?" ),
                                    QMessageBox::Yes,
                                    QMessageBox::No ) == QMessageBox::Yes )
        {
            m_BuildingsListWidget->takeItem( row );

            building = m_Buildings->at( row );
            m_Buildings->remove
            ( row );
            building->remove
            ();
            delete building;
            building = NULL;

            m_Doc->save();


            unsetDrawObjects();
            m_Center->setEnabled( false );

            m_BuildingsListWidget->setCurrentRow( row - 1 );


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
        building->save();

    }

}


/*!
    \fn BB_TabBuilding::mousePressEvent ( QMouseEvent * e )
 */
void BB_TabBuilding::mouseReleaseEvent ( QMouseEvent * e )
{
    // TODO
    e->ignore();

//     cout << "BB_TabBuilding -> " << m_Selection.count() << " Objekte slektiert" << endl;


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

    /* Tool zum Selektieren */
    m_ToolSelect = new BB_ToolSelect();
    QAction *toolSelect = new QAction( QIcon( IMG_DIR() + SEPARATOR() + "toolSelect.png" ), "Auswahl", this );
    toolSelect->setStatusTip( "Auswahl Werkzeug" );
    createToolButton( toolSelect, m_ToolSelect );


    /* Zoomtool */
    m_ToolZoom = new BB_ToolZoom( m_Center );
    QIcon zoom( IMG_DIR() + SEPARATOR() + "toolZoom.png" );
    QAction *toolZoom = new QAction( zoom, "Zoom", this );
    toolZoom->setStatusTip( "Zoom Werkzeug" );
    createToolButton( toolZoom, m_ToolZoom );


    /* Tool zum Erstellen neuer Knoten */
    m_ToolPointNew = new BB_ToolPointNew();
    QIcon knote( IMG_DIR() + SEPARATOR() + "toolPoint.png" );
    // 	QAction *toolPointNew = new QAction("Point",this);
    QAction *toolPointNew = new QAction( knote, "Point", this );
    toolPointNew->setStatusTip( "Point Werkzeug" );
    createToolButton( toolPointNew, m_ToolPointNew );


    /* Tool zum Erstellen neuer Linien */
    m_ToolLineNew = new BB_ToolLineNew( m_Center );
    QAction *toolLineNew = new QAction( QIcon( IMG_DIR() + SEPARATOR() + "toolWall.png" ), "Wand", this );
    toolPointNew->setStatusTip( "Line Werkzeug" );
    createToolButton( toolLineNew, m_ToolLineNew );


    /* Tool zum Bewegen der Objekte */
    m_ToolMove = new BB_ToolMove();
    QAction *toolMove = new QAction( QIcon( IMG_DIR() + SEPARATOR() + "toolMove.png" ), "Move", this );
    toolMove->setStatusTip( "Move Werkzeug" );
    createToolButton( toolMove, m_ToolMove );

	
	/* Tool zum Setzen der Maßstab-Punkte */
	m_ToolScale = new BB_ToolScale( this );
	QAction *toolScale = new QAction( QIcon( IMG_DIR() + SEPARATOR() + "toolScale.png" ), "Maßstab", this );
	toolScale->setStatusTip( QString::fromUtf8("Maßstab Werkzeug") );
	createToolButton( toolScale, m_ToolScale );


    /* Das Selektionstool alst Standard wählen */
    toolChanged( toolSelect );


}


/**
 * Initialisiert das rechte Fenster
 */
void BB_TabBuilding::initWidgetRight()
{
    m_PropertyWidget = new BB_PropertyWidget();

    addWidgetRight( m_PropertyWidget );
}


/**
 * Verarbeitet die Tools von BB_TabBuilding und übergibt diese weiter an die Arbeitfläche.
 * @param action Aktion des Tools, welches Betätigt wurde.
 */
void BB_TabBuilding::toolChanged( QAction* action )
{

    if ( m_ToolSelect->getAction() == action )
    {
        unsetToolButton( action );
        action->setChecked( true );
        m_Center->setTool( m_ToolSelect );
    }
    else if ( m_ToolMove->getAction() == action )
    {
        unsetToolButton( action );
        action->setChecked( true );
        m_Center->setTool( m_ToolMove );
    }
    else if ( m_ToolZoom->getAction() == action )
    {
        unsetToolButton( action );
        action->setChecked( true );
        m_Center->setTool( m_ToolZoom );
    }
    else if ( m_ToolPointNew->getAction() == action )
    {
        unsetToolButton( action );
        action->setChecked( true );
        m_Center->setTool( m_ToolPointNew );
    }
    else if ( m_ToolLineNew->getAction() == action )
    {
        unsetToolButton( action );
        action->setChecked( true );
        m_Center->setTool( m_ToolLineNew );
    }
	else if( m_ToolScale->getAction() == action)
	{
		unsetToolButton( action );
		action->setChecked( true );
		m_Center->setTool( m_ToolScale );
	}
    else
    {
		qDebug() << "Unbekanntes Tool" << endl;
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
		qDebug() << "Kann die Liste nicht nochmal erstellen." << endl;
    }
}


/*!
    \fn BB_TabBuilding::clear()
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
    BB_Building * building;
    building = m_Doc->getBuilding( current );
    if ( building != NULL )
    {

		m_Center->setDocComponent(building);
		m_Center->setEnabled( true );
//         m_Center->setDrawDevice( building );
//        
//         m_Center->setMap( building );
    }
    if ( previous != NULL )
    {
        building = m_Doc->getBuilding( previous );
        if ( building != NULL )
        {
            building->save();
        }
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
        cout << "Kein Gebäude ausgewählt" << endl;
    }

    return false;
}
