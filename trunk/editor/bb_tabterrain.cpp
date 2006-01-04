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
#include "bb_tabterrain.h"

#include "bb_globals.h"
#include "bb_toolselect.h"
#include "bb_toolscale.h"
#include "bb_toolzoom.h"
#include "bb_toolmove.h"
#include "bb_toolterrainpointnew.h"
#include "bb_tooltrianglenew.h"

#include <QtGui>


BB_TabTerrain::BB_TabTerrain( BB_Doc* doc, QWidget* parent, Qt::WFlags f )
        : BB_Tab( doc, parent, f )
{

    if ( m_Doc != NULL && m_Doc->getTerrain() != NULL )
    {
        m_Terrain = m_Doc->getTerrain();

        m_Center->setDocComponent( m_Terrain );
        // 		m_Center->setDrawDevice(m_Terrain);
        // 		m_Center->setMap(m_Terrain);
    }

    initTools();

    /***** <Debug> *****/

    QGroupBox* box = new QGroupBox();
    box->setFlat( true );
    box->setTitle( "Optionen" );

    QPushButton * button = new QPushButton( "Eigenschaften" );

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget( button );
    box->setLayout( layout );

    addWidgetLeft( box, 1 );

    connect( button, SIGNAL( clicked( bool ) ), this, SLOT( slotTerrainEdit() ) );

    /***** </Debug> *****/

}


BB_TabTerrain::~BB_TabTerrain()
{}



/**
 * Initialisiert alle Tools
 */
void BB_TabTerrain::initTools()
{
	
	QAction* initTool;
	
	/* Tools initialisieren */
	m_ToolMove = new BB_ToolMove(this);
	m_ToolScale = new BB_ToolScale( this );
	m_ToolZoom = new BB_ToolZoom( m_Center, this );
	m_ToolTerrainPointNew = new BB_ToolTerrainPointNew(this);
	m_ToolTriangleNew = new BB_ToolTriangleNew(this);
			
	initTool = addTool( m_ToolMove, "Move", "Bewegungs Werkzeug" );
	addTool( m_ToolScale, QString::fromUtf8("Maßstab"), QString::fromUtf8("Maßstab Werkzeug") );
	addTool( m_ToolZoom, "Zoom", QString::fromUtf8("Zoom Werkzeug") );
	addTool( m_ToolTerrainPointNew, QString::fromUtf8("Geländepunkt-Werkzeug"), QString::fromUtf8("Werkzeug zum Erstellen von Geländeknoten") );
	addTool( m_ToolTriangleNew, QString::fromUtf8("Gelände-Flächen"), QString::fromUtf8("Werkzeug zum Erstellen von Geländeflächen") );
	
	toolChanged( initTool );
}

/* *
 * Verarbeitet die Tools von BB_TabTerrain und übergibt diese weiter an die Arbeitfläche.
 * @param action Aktion des Tools, welches Betätigt wurde.
 */
// void BB_TabTerrain::toolChanged( QAction* action )
// {
// 
// 	if ( m_ToolMove->getAction() == action )
//     {
// 		setTool( m_ToolMove );
//     }
// 	else if( m_ToolScale->getAction() == action )
// 	{
// 		setTool( m_ToolScale );
// 	}
//     else if ( m_ToolZoom->getAction() == action )
//     {
// 		setTool( m_ToolZoom );
//     }
//     else if ( m_ToolTerrainPointNew->getAction() == action )
//     {
// 		setTool( m_ToolTerrainPointNew );
//     }
//     else if ( m_ToolTriangleNew->getAction() == action )
//     {
// 		setTool( m_ToolTriangleNew );
//     }
//     else
//     {
//         cout << "Unbekanntes Tool" << endl;
//     }
// }


/**
 * Editiert das Gelände
 */
void BB_TabTerrain::slotTerrainEdit()
{
    m_Terrain = m_Doc->getTerrain();

    if ( m_Terrain != NULL )
    {
        m_Terrain->keyBoardEdit( this );

        m_Center->setDocComponent( m_Terrain );
    }
}


/**
 * Speichert das Gelände
 */
bool BB_TabTerrain::saveCurrent()
{
    m_Terrain = m_Doc->getTerrain();

    if ( m_Terrain != NULL )
    {
		return m_Terrain->save() && BB_Tab::saveCurrent();
    }

    return false;
}


/**
 *
 */
void BB_TabTerrain::updateWidget()
{
    m_Terrain = m_Doc->getTerrain();

    if ( m_Terrain != NULL )
    {
        m_Center->setDocComponent( m_Terrain );
        // 		m_Center->setMap(m_Terrain);
        // 		m_Center->setDrawDevice(m_Terrain);
    }
    else
    {
        m_Center->setDocComponent( m_Terrain );
        // 		m_Center->setMap(NULL);
        // 		m_Center->setDrawDevice(NULL);
    }

}
