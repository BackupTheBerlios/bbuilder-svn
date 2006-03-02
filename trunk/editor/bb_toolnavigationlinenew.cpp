//
// C++ Implementation: bb_toolnavigationlinenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolnavigationlinenew.h"
#include <bb_navigationline.h>

/**
 * Erstellt ein neues Navigationslinien-Werkzeug
 * @param parent Parent-Fenster
 * @author Alex Letkemann 
 */
BB_ToolNavigationLineNew::BB_ToolNavigationLineNew(QWidget* parent): BB_ToolLineNew(parent)
{
}


/**
 * Destruktor
 */
BB_ToolNavigationLineNew::~BB_ToolNavigationLineNew()
{
}


/**
 * Erstellt eine neue Linie zwischen den beiden, übergebenen Punkten p1 und p2 und gibt diese zurück.
 * @param p1 Punkt 1
 * @param p2 Punkt 2
 * @return Erstellte Navigationslinie.
 * @author Alex Letkemann
 */
BB_Line* BB_ToolNavigationLineNew::createNewLine(BB_Point* p1, BB_Point* p2)
{
	return (BB_Line*) new BB_NavigationLine(p1, p2);
}

/**
 * Such und gibt die zuerst gefundene Linie an der übergebenen Position zurück.
 * Falls keine Linie an der übergebenen Position existiert, wird NULL zurückgegeben.
 * @param pos Position an der gesucht werden soll.
 * @return Linie oder NULL
 * @author Alex Letkemann
 */
BB_Line* BB_ToolNavigationLineNew::getClickedLine(C2dVector& pos)
{
	return (BB_Line*) getClickedObject( pos, typeid( BB_NavigationLine ) );
}

/**
 * Sucht und gibt den zuerst gefundenen Punkt an der übergebenen Position zurück.
 * Wird kein Punkt an der angegebenen Position gefudnen, so wird NULL zurückgegeben.
 * @param pos Position, an der gesucht werden soll.
 * @return Punkt oder NULL
 * @author Alex Letkemann
 */
BB_Point* BB_ToolNavigationLineNew::getClickedPoint(C2dVector& pos)
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_NavigationPoint ));
}

