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


/**
 * Konstruktor
 */
BB_ToolTerrainPointNew::BB_ToolTerrainPointNew(QWidget *parent)
 : BB_ToolPointNew(parent)
{
	m_Icon = QIcon ( IMG_DIR() + SEPARATOR() + "toolPoint.png" );
}

/**
 * Destruktor
 */
BB_ToolTerrainPointNew::~BB_ToolTerrainPointNew()
{
}

/**
 * \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolTerrainPointNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = new BB_WidgetToolTerrainPointNew( this );
	}
	
	return m_ToolWidget;
}

/**
 * Erzeugt einen neuen Geländepunkt an der Übergebenen Position und git diesen zurück.
 * @param pos Position, an der der Geländepunkt erzeugt werden soll.
 * @return Neuer Geländepunkt.
 */
BB_Point* BB_ToolTerrainPointNew::createNewPoint(C2dVector& pos)
{
	return new BB_TerrainPoint(pos);
}

/**
 * Sucht und gibt den zuerst gefunden, Geländepunkt an der übergebenen Position zurück.
 * Falls kein Geländepunkt, an der Position exitiert, wird NULL zurückgegeben.
 * @param pos Position, an der gesucht werden soll.
 * @return Geländepunkt oder NULL
 */
BB_Point* BB_ToolTerrainPointNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_TerrainPoint ) );
}

