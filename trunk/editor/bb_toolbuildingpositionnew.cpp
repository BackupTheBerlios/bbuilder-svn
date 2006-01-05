//
// C++ Implementation: bb_toolbuildingpositionnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolbuildingpositionnew.h"
#include <bb_widgettoolbuildingpositionnew.h>
#include <bb_buildingposition.h>

BB_ToolBuildingPositionNew::BB_ToolBuildingPositionNew( BB_Doc * doc, QWidget* parent): BB_ToolPointNew(parent)
{
	if( doc == NULL )
	{
		qDebug("BB_ToolBuildingPositionNew kann nicht ohne BB_Doc initialisiert werden:");
		exit(1);
	}
	m_Doc = doc;
	m_Building = NULL;
}


BB_ToolBuildingPositionNew::~BB_ToolBuildingPositionNew()
{
}


BB_AbstractToolWidget* BB_ToolBuildingPositionNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = (BB_AbstractToolWidget *) new BB_WidgetToolBuildingPositionNew(m_Doc, this);
	}
	return m_ToolWidget;
}

BB_Point* BB_ToolBuildingPositionNew::createNewPoint(C2dVector& pos)
{
	BB_Point* point = NULL;
	
	if( m_Building != NULL )
	{
		point = (BB_Point*) new BB_BuildingPosition( m_Building,0,m_Doc->getTerrain(), pos, 0.0, 0.0 );
	}
	
	return point;
}

BB_Point* BB_ToolBuildingPositionNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_BuildingPosition )  );
}



BB_Building* BB_ToolBuildingPositionNew::getBuilding() const
{
    return m_Building;
}


void BB_ToolBuildingPositionNew::setBuilding( BB_Building* value )
{
    m_Building = value;
}
