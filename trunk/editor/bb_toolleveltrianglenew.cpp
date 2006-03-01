//
// C++ Implementation: bb_toolleveltrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolleveltrianglenew.h"
#include <bb_leveltriangle.h>

/**
 * Konstruktor
 */
BB_ToolLevelTriangleNew::BB_ToolLevelTriangleNew(QWidget* parent): BB_ToolTriangleNew(parent)
{
	m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolTriangle.png" );
}

/**
 * Destruktor
 */
BB_ToolLevelTriangleNew::~BB_ToolLevelTriangleNew()
{
}

/**
 * Erstellt ein neues Dreieck und gibt dieses zurück.
 * @return neues Dreieck
 */
BB_Triangle* BB_ToolLevelTriangleNew::createNewSurface()
{
	return ( BB_Triangle* ) new BB_LevelTriangle(m_P1, m_P2, m_P3); 
}

