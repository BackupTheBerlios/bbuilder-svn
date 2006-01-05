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
Werkzeug zur Plazierung von Gebäuden auf dem Gelände

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolBuildingPositionNew : public BB_ToolPointNew
{
public:
	BB_ToolBuildingPositionNew( BB_Doc * doc, QWidget* parent);

	~BB_ToolBuildingPositionNew();

    virtual BB_AbstractToolWidget* getToolWidget();
    virtual BB_Point* createNewPoint(C2dVector& pos);
    virtual BB_Point* getClickedPoint(C2dVector& pos);

	void setBuilding( BB_Building* value );
	

	BB_Building* getBuilding() const;
	

	BB_Doc* m_Doc;
	BB_Building* m_Building;
	
};

#endif
