//
// C++ Interface: bb_toolterrainpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTERRAINPOINTNEW_H
#define BB_TOOLTERRAINPOINTNEW_H

#include <bb_toolpointnew.h>

/**
 * Werkzeug zum Erstellen von Geländepunkten.<br>
 * Die Geländepunkte werde durch clicken mit der Linken Mauststaste auf die entsprechende Position auf der Arbeitsfläche erstellt.
 *
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolTerrainPointNew : public BB_ToolPointNew
{
public:
	/**
	 * Konstruktor
	 */
	BB_ToolTerrainPointNew(QWidget *parent);

	/**
	 * Destruktor
	 */ 
    ~BB_ToolTerrainPointNew();

    /**
     * \fn getToolWidget()
     */
    virtual BB_AbstractToolWidget* getToolWidget();

protected:
    
	/**
	 * Erzeugt einen neuen Geländepunkt an der Übergebenen Position und git diesen zurück.
	 * @param pos Position, an der der Geländepunkt erzeugt werden soll.
	 * @return Neuer Geländepunkt.
	 */
	virtual BB_Point* createNewPoint(C2dVector& pos);
	
    /**
     * Sucht und gibt den zuerst gefunden, Geländepunkt an der übergebenen Position zurück.
	 * Falls kein Geländepunkt, an der Position exitiert, wird NULL zurückgegeben.
     * @param pos Position, an der gesucht werden soll.
     * @return Geländepunkt oder NULL
     */
    virtual BB_Point* getClickedPoint(C2dVector& pos);

};

#endif
