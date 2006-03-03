//
// C++ Interface: bb_toolterraintrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTERRAINTRIANGLENEW_H
#define BB_TOOLTERRAINTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
 * Werkzeug zum Erstellen von Geländeflächen.<br>
 * Die Geländefläche wird durch mehrere Dreiecke markiert.<br>
 * Diese Geländefläche-Dreiecke werden durch Anclicken von drei verschiedenen Geländepunkten erstellt.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolTerrainTriangleNew : public BB_ToolTriangleNew
{
public:
	/**
	 * Konstruktor
	 */
    BB_ToolTerrainTriangleNew(QWidget* parent);

	/**
	 * Destruktor
	 */
    ~BB_ToolTerrainTriangleNew();

	/**
	 * @fn getToolWidget()
	 */
    virtual BB_AbstractToolWidget* getToolWidget();
	
    /**
	 * Sucht und gibt den zuerst gefunden, Geländepunkt an der übergebenen Position zurück.
	 * Falls kein Geländepunkt, an der Position exitiert, wird NULL zurückgegeben.
	 * @param pos Position, an der gesucht werden soll.
	 * @return Geländepunkt oder NULL
	 */
    virtual BB_Point* getClickedPoint(C2dVector& pos);
	
	
    /**
     * Erstellt und gibt ein neues Gelände-Dreieck zurück
	 * @return neues Gelände-Dreieck
     */
    virtual BB_Triangle* createNewSurface();

};

#endif
