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
#ifndef BB_TABTERRAIN_H
#define BB_TABTERRAIN_H

#include "bb_tab.h"
#include "bb_terrain.h"

#include "bb_abstracttool.h"

/**
 * Tab-Fenster, in dem das Gelände bearbeitet wird.
 * Links befinden sich die Werkzeuge und der Button für das Eingenschafts-Dialog des Geländes.
 * In der Mitte ist die Arbeitsfläche und rechts werden die Eigenschaftsfenter der Werkzeuge angezeigt.
 * @author Alex Letkemann
 */
class BB_TabTerrain : public BB_Tab
{
	Q_OBJECT
public:
	/**
	 * Konstruktor.
	 * Erstellt ein neues Gelände-Tab.
	 * @param doc Dokument, welches die Daten enthält.
	 * @param parent Das Parent-Fenster
	 * @param f QtWindowFlags
	 * @author Alex Letkemann
	 */
    BB_TabTerrain(BB_Doc* doc, QWidget* parent = 0, Qt::WFlags f = 0);

	/**
	 * Destruktor
	 */
    ~BB_TabTerrain();
	
	
	/**
	 * Aktualisiert die Arbeitfläche
	 * @author Alex Letkemann
	 */
	virtual void updateWidget();
	
protected:
	
	/* Werkzeuge */
	BB_AbstractTool* m_ToolZoom;
	BB_AbstractTool* m_ToolTerrainPointNew;
	BB_AbstractTool* m_ToolMove;
	BB_AbstractTool* m_ToolTriangleNew;
	BB_AbstractTool* m_ToolScale;
    
	/* Gelände */
	BB_Terrain* m_Terrain;

private:
    /**
     * Initialisiert die Werkzeuge
	 * @author Alex Letkemann
     */
    void initTools();

protected:
    /**
     * Speichert das Gelände
     * @return Erfolg des Speicherns
     */
    virtual bool saveCurrent();
    
private slots:
    
	/**
     * Ruft ein Dialog auf, mit die Eigenschaften des Geländes geändert werden können.
	 * @author Alex Letkemann
     */
    void slotTerrainEdit();
};

#endif
