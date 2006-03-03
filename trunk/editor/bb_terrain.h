/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann   *
 *   alex@letkemann.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 ***************************************************************************/
#ifndef BB_TERRAIN_H
#define BB_TERRAIN_H

#include "bb_doccomponent.h"

#include <QTextStream>
#include <bb_building.h>

class BB_Doc;

/**
 * Stellt ein Gelände dar, auf dem mehrere Gebäude plaziert werden können.
 * Das Gelände wird durch Dreiecke, die durch Verbinden von drei Konten entstehen, aufgebaut.
 * @author Alex Letkemann
 */
class BB_Terrain : public BB_DocComponent
{
public:
	/**
	 * Konstruktor
     * @param path Verzeichnis, in dem gespeichert wird 
     * @param fileName  Dateiname, unter welchem gepeichert wird
     * @param name Geländename
	 * @author Alex Letkemann 
	 */
	BB_Terrain(const QDir& path, const QString &fileName, const QString &name = QString(""));

    virtual ~BB_Terrain();
	
	/** 
	 * \fn write(QTextStream &out) 
	 */
	virtual bool write(QTextStream &out);
	
	/**
	 * \fn keyBoardEdit(QWidget* parent)
	 */
	virtual int keyBoardEdit(QWidget* parent);
	
	/**
	 * \fn open()
	 */
    virtual bool open();
    
	/**
	 * Gibt den Klassennamen zurück
	 * @return Klassenname
	 */
	virtual const QString getClassName();
    
	/**
	 * Löst die Gebäude IDs auf
	 * @param doc Dokument, welches alle Gebäude enthält
	 * @author Alex Letkemann
	 */
	void resolveBuildingIds( BB_Doc* doc );
	
	/**
	 * Wird aufgerufen, wenn ein Gebäude gelöscht wurde.
	 * Entfern das übergebene Gebäude vom Gelände.
	 * @param building Das gelöschte Gebäude
	 * @author Alex Letkemann
	 */
    void buildingDeleted( BB_Building* building );
	
	/**
	 * \fn createGl( QVector<C3dTriangle>& triangles, double scale )
	 */
    virtual void createGl( QVector<C3dTriangle>& triangles, double scale );

};

#endif
