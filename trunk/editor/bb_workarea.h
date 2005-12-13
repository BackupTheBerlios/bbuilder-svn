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
#ifndef BB_WORKAREA_H
#define BB_WORKAREA_H

#include <QScrollArea>
#include "bb_workframe.h"
#include "bb_tab.h"

#include "bb_drawdevice.h"

/**
@author Alex Letkemann
*/
class BB_WorkArea : public QScrollArea
{
Q_OBJECT
public:
        BB_WorkArea(QVector<BB_DrawObject*>* selectVector, QWidget *parent = 0);

    ~BB_WorkArea();
    void zoom(double faktor);
    BB_AbstractTool* getTool();
    void setTool(BB_AbstractTool* tool);
    void setZoomFaktor(double zoom);
	
	/*	Edit: Alex umstellung auf BB_DocComponent
     *	bool setMap(BB_Map* map);
     *	void setDrawDevice(BB_DrawDevice * device);
     *	BB_Map* getMap() const;
	 */
    BB_DocComponent* getDocComponent();
    void setDocComponent(BB_DocComponent* component);


protected:
    BB_WorkFrame *m_WorkFrame;
    BB_Map* m_Map;
};

#endif
