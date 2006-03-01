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

/**
 * Konstruktor.
 * Erzeugt ein neues Gebäudepositionierung-Werkzeug
 * @param doc Dokument, welches die Gebäude und das Gelände enthält
 * @param parent Parent-Fenter
 * @author Alex Letkemann
 */
BB_ToolBuildingPositionNew::BB_ToolBuildingPositionNew( BB_Doc * doc, QWidget* parent): BB_ToolPointNew(parent)
{
	if( doc == NULL )
	{
		qDebug("BB_ToolBuildingPositionNew kann nicht ohne BB_Doc initialisiert werden:");
		exit(1);
	}
	m_Doc = doc;
	m_Building = NULL;
	
	m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolBuildingPosition.png" );
}

/**
 * Destruktor
 */
BB_ToolBuildingPositionNew::~BB_ToolBuildingPositionNew()
{
}

/**
 * \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolBuildingPositionNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = (BB_AbstractToolWidget *) new BB_WidgetToolBuildingPositionNew(m_Doc, this);
	}
	return m_ToolWidget;
}

/**
 * Erzeugt eine neue Gebäudeposition und Gibt diese zurück.
 * @param pos Position an der das Gebäude erstellt positioniert werden soll.
 * @return Gebäudeposition
 * @author Alex Letkemann
 */
BB_Point* BB_ToolBuildingPositionNew::createNewPoint(C2dVector& pos)
{
	BB_Point* point = NULL;
	
	if( m_Building != NULL )
	{
		point = (BB_Point*) new BB_BuildingPosition( m_Building,m_Building->getObjectNr(),m_Doc->getTerrain(), pos, 0.0, 0.0 );
	}
	
	return point;
}

/**
 * Gibt die angeclickte Gebäudeposition, an der übergebenen Position.
 * Falls kein Gebäude an dieser Position existiert, wird NULL zurückgegeben.
 * @return Gebäudeposition oder NULL;
 * @author Alex Letkemann
 */
BB_Point* BB_ToolBuildingPositionNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_BuildingPosition )  );
}


/**
 * Gibt das Gebäude zurück, welche gerade eingestellt ist.
 * @return Gebäude
 * @author Alex Letkemann
 */
BB_Building* BB_ToolBuildingPositionNew::getBuilding() const
{
    return m_Building;
}

/**
 * Setzt das Gebäude, welches Positioniert werden soll.
 * @param value Gebäude, welches Positioniert werden soll.
 * @author Alex Letkemann
 */
void BB_ToolBuildingPositionNew::setBuilding( BB_Building* value )
{
    m_Building = value;
}
