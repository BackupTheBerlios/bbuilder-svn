//
// C++ Interface: bb_toolbuildingpositionnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLBUILDINGPOSITIONNEW_H
#define BB_TOOLBUILDINGPOSITIONNEW_H

#include <bb_toolpointnew.h>
#include <bb_building.h>
#include <bb_buildingposition.h>
#include <bb_doc.h>

/**
 * Werkzeug zur Plazierung von Gebäuden auf dem Gelände.
 * Ein Gebäude kann mehrmals auf dem Gelände plaziert werden.
 * Durch das Werkzeug-Fenster lässt sich das Gebäude auswählen und rotieren.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolBuildingPositionNew : public BB_ToolPointNew
{
public:
	/**
	 * Konstruktor.
	 * Erzeugt ein neues Gebäudepositionierung-Werkzeug
	 * @param doc Dokument, welches die Gebäude und das Gelände enthält
	 * @param parent Parent-Fenter
     * @author Alex Letkemann
	 */
	BB_ToolBuildingPositionNew( BB_Doc * doc, QWidget* parent);

	
	/**
	 * Destruktor
	 */
	~BB_ToolBuildingPositionNew();

	
    /**
     * \fn BB_AbstractTool::getToolWidget()
     */
    virtual BB_AbstractToolWidget* getToolWidget();
	
	
    /**
     * Erzeugt eine neue Gebäudeposition und Gibt diese zurück.
     * @param pos Position an der das Gebäude erstellt positioniert werden soll.
     * @return Gebäudeposition
	 * @author Alex Letkemann
     */
    virtual BB_Point* createNewPoint(C2dVector& pos);
	
    /**
     * Gibt die angeclickte Gebäudeposition, an der übergebenen Position.
	 * Falls kein Gebäude an dieser Position existiert, wird NULL zurückgegeben.
	 * @return Gebäudeposition oder NULL;
	 * @author Alex Letkemann
     */
    virtual BB_Point* getClickedPoint(C2dVector& pos);

	/**
	 * Setzt das Gebäude, welches Positioniert werden soll.
	 * @param value Gebäude, welches Positioniert werden soll.
	 * @author Alex Letkemann
	 */
	void setBuilding( BB_Building* value );
	

	/**
	 * Gibt das Gebäude zurück, welche gerade eingestellt ist.
	 * @return Gebäude
	 * @author Alex Letkemann
	 */
	BB_Building* getBuilding() const;
	

	/** Dokument */
	BB_Doc* m_Doc;
	
	/** Gebäude, welches Plaziert werden soll */
	BB_Building* m_Building;
	
};

#endif
