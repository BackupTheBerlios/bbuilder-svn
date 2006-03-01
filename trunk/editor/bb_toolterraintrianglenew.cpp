//
// C++ Implementation: bb_toolterraintrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolterraintrianglenew.h"
#include <bb_widgettoolterraintrianglenew.h>
#include <bb_terrainpoint.h>
#include <bb_terraintriangle.h>

/**
 * Konstruktor
 */
BB_ToolTerrainTriangleNew::BB_ToolTerrainTriangleNew( QWidget* parent ):
	BB_ToolTriangleNew( parent )
{
	m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolTriangle.png" );
}

/**
 * Destruktor
 */
BB_ToolTerrainTriangleNew::~BB_ToolTerrainTriangleNew()
{
}

/**
 * @fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolTerrainTriangleNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = ( BB_AbstractToolWidget * ) new BB_WidgetToolTerrainTriangleNew(this);
	}
	
	return m_ToolWidget;
}

/**
 * Sucht und gibt den zuerst gefunden, Geländepunkt an der übergebenen Position zurück.
 * Falls kein Geländepunkt, an der Position exitiert, wird NULL zurückgegeben.
 * @param pos Position, an der gesucht werden soll.
 * @return Geländepunkt oder NULL
 */
BB_Point* BB_ToolTerrainTriangleNew::getClickedPoint(C2dVector& pos)
{
	return ( BB_Point * ) getClickedObject(pos, typeid( BB_TerrainPoint ) );
}




/**
 * Erstellt und gibt ein neues Gelände-Dreieck zurück
 * @return neues Gelände-Dreieck
 */
BB_Triangle* BB_ToolTerrainTriangleNew::createNewSurface()
{
	BB_Triangle* triangle = NULL;
	
	if ( m_P1 != NULL && m_P2 != NULL && m_P3 != NULL )
	{
		triangle = new BB_TerrainTriangle( m_P1, m_P2, m_P3 );
		QString texture = (( BB_WidgetToolTerrainTriangleNew * )(getToolWidget()))->getTextureFileName();
		triangle->setTextureFileName( texture );
	}
	return triangle;
}
