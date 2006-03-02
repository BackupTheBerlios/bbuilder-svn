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


/**
 * Konstruktor. Erstellt ein neues Werkzeug zur Markieren von Dächern und Gründen.
 */
BB_ToolBuildingTriangleNew::BB_ToolBuildingTriangleNew(QWidget* parent): BB_ToolTriangleNew(parent)
{
	m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolTriangle.png" );
}


/**
 * Destruktor
 */
BB_ToolBuildingTriangleNew::~BB_ToolBuildingTriangleNew()
{
}

/**
 * Erzeugt ein neues Dreieck und gibt dieses zurück.
 * @return Neues Dreieck.
 */
BB_Triangle* BB_ToolBuildingTriangleNew::createNewSurface()
{
	return ( BB_Triangle* ) new BB_BuildingTriangle(m_P1, m_P2, m_P3);
}

