//
// C++ Implementation: bb_toolterrainpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolterrainpointnew.h"
#include <bb_terrainpoint.h>
#include <bb_widgettoolterrainpointnew.h>

BB_ToolTerrainPointNew::BB_ToolTerrainPointNew(QWidget *parent)
 : BB_ToolPointNew(parent)
{
	m_Icon = QIcon ( IMG_DIR() + SEPARATOR() + "toolPoint.png" );
}


BB_ToolTerrainPointNew::~BB_ToolTerrainPointNew()
{
}


BB_AbstractToolWidget* BB_ToolTerrainPointNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = new BB_WidgetToolTerrainPointNew( this );
	}
	
	return m_ToolWidget;
}

BB_Point* BB_ToolTerrainPointNew::createNewPoint(C2dVector& pos)
{
	return new BB_TerrainPoint(pos);
}

BB_Point* BB_ToolTerrainPointNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_TerrainPoint ) );
}

