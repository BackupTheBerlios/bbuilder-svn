//
// C++ Implementation: bb_toolbuildingtrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolbuildingtrianglenew.h"
#include <bb_buildingtriangle.h>

BB_ToolBuildingTriangleNew::BB_ToolBuildingTriangleNew(QWidget* parent): BB_ToolTriangleNew(parent)
{
}


BB_ToolBuildingTriangleNew::~BB_ToolBuildingTriangleNew()
{
}


BB_Triangle* BB_ToolBuildingTriangleNew::createNewSurface()
{
	return ( BB_Triangle* ) new BB_BuildingTriangle(m_P1, m_P2, m_P3);
}

