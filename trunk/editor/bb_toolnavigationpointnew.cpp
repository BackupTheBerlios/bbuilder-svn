//
// C++ Implementation: bb_toolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolnavigationpointnew.h"
#include <bb_widgettoolnavigationpointnew.h>

/**
 * Konstruktor. Erzeugt ein neues Werkzeug zur Erstellung von Navigationsknoten.
 * @param parent Parent-Fenster
 * @author Alex Letkemann
 */
BB_ToolNavigationPointNew::BB_ToolNavigationPointNew(QWidget *parent)
 : BB_ToolPointNew(parent)
{
}


/**
 * Destruktor
 */
BB_ToolNavigationPointNew::~BB_ToolNavigationPointNew()
{
}

/**
 * Erstellund und gibt einen neuen Navigationsknoten an der übergebenen Position.
 * @param pos Position, an der der Knoten erstellt werden soll.
 * @return Neuer Navigationsknoten.
 * @author Alex Letkemann
 */
BB_Point* BB_ToolNavigationPointNew::createNewPoint( C2dVector& pos )
{
	return new BB_NavigationPoint( pos );
}


/**
 * Sucht und gibt den zuerst gefundenen Knoten an der übergebenen Position zurück.
 * Falls kein Knoten an der übergebenen Position gefundenen wird, wird NULL zurückgegeben.
 * @param pos Position, an der gesucht werden soll.
 * @return Navigationsknoten oder NULL.
 * @author Alex Letkemann
 */
BB_Point* BB_ToolNavigationPointNew::getClickedPoint( C2dVector& pos )
{
	return (BB_Point *) getClickedObject( pos, typeid( BB_NavigationPoint ) );
}


/**
 * @fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolNavigationPointNew::getToolWidget()
{
	if( m_ToolWidget == NULL )
	{
		m_ToolWidget = new BB_WidgetToolNavigationPointNew( this );
	}
	
	return m_ToolWidget;
}
