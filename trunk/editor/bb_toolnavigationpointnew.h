//
// C++ Interface: bb_toolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLNAVIGATIONPOINTNEW_H
#define BB_TOOLNAVIGATIONPOINTNEW_H

#include <bb_toolpointnew.h>
#include <bb_navigationpoint.h>

/**
 * Werkzeug zum Erstellen von Naviationspunkten.
 * Ein Punkt wird mit einem Click mit der linken Maustaste auf die Arbeitsfläche erzeugt.
 * Mit einem Click der rechten Maustaste auf einen Navigationsknoten, lösst sich der Knoten wieder löschen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolNavigationPointNew : public BB_ToolPointNew
{
public:
	
	/**
	 * Konstruktor. Erzeugt ein neues Werkzeug zur Erstellung von Navigationsknoten.
	 * @param parent Parent-Fenster
	 * @author Alex Letkemann
	 */
	BB_ToolNavigationPointNew(QWidget *parent);

	/**
	 * Destruktor
	 */
    ~BB_ToolNavigationPointNew();
	
	/**
	 * @fn getToolWidget()
	 */
    virtual BB_AbstractToolWidget* getToolWidget();

protected:
	
	/**
	 * Erstellund und gibt einen neuen Navigationsknoten an der übergebenen Position.
	 * @param pos Position, an der der Knoten erstellt werden soll.
	 * @return Neuer Navigationsknoten.
	 * @author Alex Letkemann
	 */
    virtual BB_Point* createNewPoint( C2dVector& pos );
	
    /**
     * Sucht und gibt den zuerst gefundenen Knoten an der übergebenen Position zurück.
	 * Falls kein Knoten an der übergebenen Position gefundenen wird, wird NULL zurückgegeben.
     * @param pos Position, an der gesucht werden soll.
     * @return Navigationsknoten oder NULL.
	 * @author Alex Letkemann
     */
    virtual BB_Point* getClickedPoint( C2dVector& pos );
};

#endif
