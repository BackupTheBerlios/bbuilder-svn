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
#ifndef BB_TABLEVEL_H
#define BB_TABLEVEL_H

#include "bb_tab.h"
#include "bb_toolzoom.h"

/**
@author Alex Letkemann
*/
class BB_TabLevel : public BB_Tab
{
Q_OBJECT
public:
	BB_TabLevel(BB_Doc * doc, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_TabLevel();
    

protected:
    QPushButton* m_ButtonLevelProperties;
    QPushButton* m_ButtonLevelDelete;
    QPushButton* m_ButtonLevelNew;
    BB_AbstractTool* m_ToolZoom;
private slots:
    void test(QAction* action);
    void slotZoomTool(QAction* action);
	void slotLevelNew();
	void slotLevelProperties();
	void slotLevelDelete();


};

#endif
