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
Klasse zur Speicherung und Darstellung der Gebäude auf dem Gelände

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_BuildingPosition : public BB_TerrainPoint
{
public:
	BB_BuildingPosition( BB_Building* building, int buildingId , BB_DocComponent* component, C2dVector& pos, double height, double angle );


    ~BB_BuildingPosition();

    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    virtual const QString getClassName();
    virtual void generateXElement(QTextStream& out, int depth);

	void setRotation( double value );
	

	double getRotation() const;
    void resolveBuildingId( BB_Doc * doc );

	BB_Building* getBuilding() const;
	virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
	
	

protected:
    double m_Rotation;
	int m_BuildingId;
	BB_Building* m_Building;
	BB_DocComponent* m_ParentDocComponent;
};

#endif
