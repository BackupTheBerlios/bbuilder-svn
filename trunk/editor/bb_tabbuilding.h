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
#ifndef BB_TABBUILDING_H
#define BB_TABBUILDING_H

#include "bb_tab.h"
#include "bb_building.h"

#include "bb_toolzoom.h"
#include "bb_toolpointnew.h"
#include "bb_toollinenew.h"
#include "bb_toolmove.h"
#include "bb_toolselect.h"
#include "bb_toolscale.h"


#include "bb_propertywidget.h"

/**
@author Alex Letkemann
*/
class BB_TabBuilding : public BB_Tab
{
	Q_OBJECT
public:
    BB_TabBuilding(BB_Doc * doc, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_TabBuilding();
//     void updateBuildingList();
    virtual void mouseReleaseEvent ( QMouseEvent * e );
	virtual void updateWidget();
	void createBuildingList();
    virtual void clear();
	
private slots:
    void slotBuildingProperties();
    void slotBuildingDelete();
    void slotBuildingNew();
//     void slotBuildingChanged(int index);    
	void slotBuildingChanged(QListWidgetItem * current, QListWidgetItem * previous);
protected:
    BB_AbstractTool* m_ToolZoom;
    BB_AbstractTool* m_ToolPointNew;
    BB_AbstractTool* m_ToolMove;
    BB_AbstractTool* m_ToolLineNew;
	BB_AbstractTool* m_ToolSelect;	
		
    QVector<BB_Building*>* m_Buildings;
    QListWidget* m_BuildingsListWidget;
    QPushButton* m_ButtonBuildingDelete;
    QPushButton* m_ButtonBuildingNew;
    QPushButton* m_ButtonBuildingProperties;
    BB_PropertyWidget* m_PropertyWidget;
    bool m_BuildingsListCreated;
    BB_AbstractTool* m_ToolScale;
    
protected:
    
    virtual void toolChanged(QAction* action);
private:
    void initTools();
    void initWidgetLeft();
    void initWidgetRight();
    virtual bool saveCurrent();
    
private slots:

};

#endif
