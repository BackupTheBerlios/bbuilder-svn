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

BB_ToolTerrainTriangleNew::BB_ToolTerrainTriangleNew( QWidget* parent ):
BB_ToolTriangleNew( parent )
{
}


BB_ToolTerrainTriangleNew::~BB_ToolTerrainTriangleNew()
{
}


BB_AbstractToolWidget* BB_ToolTerrainTriangleNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = ( BB_AbstractToolWidget * ) new BB_WidgetToolTerrainTriangleNew(this);
	}
	
	return m_ToolWidget;
}

BB_Point* BB_ToolTerrainTriangleNew::getClickedPoint(C2dVector& pos)
{
	return ( BB_Point * ) getClickedObject(pos, typeid( BB_TerrainPoint ) );
}




/*!
    \fn BB_ToolTerrainTriangleNew::createNewSurface()
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
