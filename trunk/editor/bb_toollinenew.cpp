/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   v.ustinov@web.de	   										*
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
 ***************************************************************************/
#include "bb_toollinenew.h"

#include <iostream>

using namespace std;

BB_ToolLineNew::BB_ToolLineNew()
        : BB_AbstractTool()
{}


BB_ToolLineNew::~BB_ToolLineNew()
{}


void BB_ToolLineNew::click(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
    // 	if(objects != NULL)
    // 	{
    // 		QPoint pScreen,pLogic;
    // 		pScreen.setX(me->x());
    // 		pScreen.setY(me->y());
    // 		transformer->screenToLogical(pLogic,pScreen);
    // 		BB_Point *point1 = new BB_Point(pLogic);
    // 		BB_Point *point2 = new BB_Point(QPoint(pLogic.x()+50, pLogic.y()));
    // 		BB_Line *line = new BB_Line(point1, point2);
    // 		objects->append(line);
    // 	}

    if(objects != NULL && me != NULL && transformer != NULL)
    {
        QPoint pScreen, pLogic;
        BB_DrawObject *object;
        pScreen = me->pos();
        transformer->screenToLogical(pLogic,pScreen);
        for(int i = 0; i < objects->count(); i++)
        {
            object = objects->at(i);
            if(object->isHit(pLogic))
            {
                QPoint fromhitobject = object->getP0();
			 cout << "New Line : Point :" << fromhitobject.x()   << endl;
                BB_Point *point2 = new BB_Point(QPoint(fromhitobject.x()+50, fromhitobject.y()));
                BB_Line *line = new BB_Line(object, point2);
                objects->append(line);
                return;
            }
        }
    }
}

void BB_ToolLineNew::move(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
    cout << "move" <<endl;
}

void BB_ToolLineNew::release(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{}

