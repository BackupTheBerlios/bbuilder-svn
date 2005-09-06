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
#include "bb_toolmove.h"

/**
@author Alex Letkemann
*/
class BB_TabBuilding : public BB_Tab
{
	Q_OBJECT
public:
    BB_TabBuilding(QVector<BB_Building*>* buildings, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_TabBuilding();
    void updateBuildingList();
private slots:
    void slotZoomTool(QAction* action);
    void slotBuildingProperties();
    void slotBuildingDelete();
    void slotBuildingNew();
    void slotBuildingChanged(int index);
    void slotToolPointNew(QAction* action);
    void slotToolMove(QAction* action);
protected:
    BB_AbstractTool* m_ToolZoom;
	BB_AbstractTool* m_ToolPointNew;
	BB_AbstractTool* m_ToolMove;
			
    QVector<BB_Building*>* m_Buildings;
    QListWidget* m_BuildingsListWidget;
    QPushButton* m_ButtonBuildingDelete;
    QPushButton* m_ButtonBuildingNew;
    QPushButton* m_ButtonBuildingProperties;
	
};

#endif
