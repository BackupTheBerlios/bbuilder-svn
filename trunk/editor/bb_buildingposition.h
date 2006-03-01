//
// C++ Interface: bb_buildingposition
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_BUILDINGPOSITION_H
#define BB_BUILDINGPOSITION_H

#include <bb_terrainpoint.h>
#include <bb_building.h>
#include <c2dvector.h>
#include <bb_doc.h>

/**
 * Klasse zur Speicherung und Darstellung der Gebäude auf dem Gelände.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_BuildingPosition : public BB_TerrainPoint
{
public:
	/**
	 * Konstrucktor. Erzeugt einene neuen Gebäudeposition.
	 * Falls nur die ID des Gebäudes übergebene wird, kann die ID mit Hilfe von resolveBuildingId() aufgelöst werden.
	 * @param building Das Gebäude
	 * @param buildingId Id des Gebäudes
	 * @param component Terrain
	 * @param pos Positin des gebäudes.
	 * @param height Höhe, in welcher das Gebäude dargestellt wird. Es is NICHT die Höhe des Gebäudes.
	 * @param angle Rotation des Gebäudes auf der Y-Achse in Grad
	 * @author Alex Letkemann
	 */
	BB_BuildingPosition( BB_Building* building, int buildingId , BB_DocComponent* component, C2dVector& pos, double height, double angle );


    /**
     * Destruktor
	 * @author Alex Letkemann
     */
    ~BB_BuildingPosition();

    /**
     * Zeichnet (2D) das Gebäude auf dem Gelände
     * @param transformer Transformer, welcher verwendet werden soll.
     * @param painter Painter, welcher verwendet werden soll.
	 * @author Alex Letkemann
     */
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    
	/**
	 * \fn BB_Object::getClassName() 
	 */
	virtual const QString getClassName();
	
    /**
	 * Erzeugt das 'bb_buildingposition' XML-Element
     * @param out Stream, in den geschrieben werden soll.
     * @param depth Einrückung
	 * @author Alex Letkemann
     */
    virtual void generateXElement(QTextStream& out, int depth);

	/**
	 * Setzt die Rotation des Gebäudes an der Y-Achse in Grad
	 * @param value Winkel zur Y-Achse
	 * @author Alex Letkemann
	 */
	void setRotation( double value );
	
	/**
	 * Gibt die Rotation des Gebäudes zurück.
	 * @return Rotation des Gebäudes in Grad.
	 * @author Alex Letkemann
	 */
	double getRotation() const;
	
	
    /**
     * Löst die ID des Gebäudes auf und übernimmt das Gebäude mit der bekannten ID.
     * @param doc Dokument, welches die Gebäude enthält.
	 * @author Alex Letkemann
     */
    void resolveBuildingId( BB_Doc * doc );

	/**
	 * Gibt das Gebäude zurück.
	 * @return Gebäude. Falls die ID noch nicht aufgelöst wurde, wird NULL zurückggeben.
	 * @author Alex Letkemann
	 */
	BB_Building* getBuilding() const;
	
	
    /**
	 * Erzeugt die 3D Ansicht des Gebäudes.<br>
	 * Die 3D Ansicht wird komplett aus Dreiecken erzeugt. Die Erzeugten Dreiecke werden an den üergeben Vektor 'triangles' angehängt.
	 * @param triangles Vektor, an den die Dreiecke angehängt werden.
	 * @param vector Vektor zur Positionierung des Gebäudes.
	 * @param rotation Hier keine Funktion
	 * @param scale Skalierung des Gebäudes
	 * @param height Hier keine Funktion
	 * @author Alex Letkemann
     */
	virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
	
	

protected:
	/** Rotation des Gebäudes in Grad */
    double m_Rotation;
	
	/** Gebäude-ID */
	int m_BuildingId;
	
	/** Das Gebäude */
	BB_Building* m_Building;
	
	/** Das Gelände */
	BB_DocComponent* m_ParentDocComponent;
};

#endif
