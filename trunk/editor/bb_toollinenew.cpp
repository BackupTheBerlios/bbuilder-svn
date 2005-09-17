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
{
     	m_movedPoint = NULL;
}

BB_ToolLineNew::BB_ToolLineNew(QWidget *parent)
	: BB_AbstractTool()
{
	parentWidget = parent;
	m_movedPoint = NULL;
}


BB_ToolLineNew::~BB_ToolLineNew()
{}


void BB_ToolLineNew::click(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
    if(objects != NULL && me != NULL && transformer != NULL)
    {
        BB_DrawObject *object;
        m_pScreen = me->pos();
        transformer->screenToLogical(m_pLogic,m_pScreen);
        for(int i = 0; i < objects->count(); i++)
        {
            object = objects->at(i);
            if(object->isHit(m_pLogic) && (object->getClassName() == "BB_Point"))
            {
			  C2dVector fromhitobject = ((BB_Point*)object)->getPos();
                cout << "New Line : Point :" << fromhitobject.x()<<endl;
                BB_Point *tmpPoint = new BB_Point(m_pLogic);
                m_movedPoint = tmpPoint;
                BB_Wall *wall = new BB_Wall((BB_Point*)object, tmpPoint);
			 tmpWall = wall;
                objects->append(wall);
                m_LastLogicMouseClick = m_pLogic;
                return;
            }
        }
    }
}

void BB_ToolLineNew::move(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
    if(objects != NULL && me != NULL && transformer != NULL && m_movedPoint != NULL)
    {
        C2dVector moveTmp;
        transformer->screenToLogical(m_pLogic,me->pos());
        moveTmp.setX(m_pLogic.x() - m_LastLogicMouseClick.x());
        moveTmp.setY(m_pLogic.y() - m_LastLogicMouseClick.y());

        // 		    cout << "m_LastLogicMouseClick.x:" << m_LastLogicMouseClick.x();
        // 		    cout << "m_LastLogicMouseClick.y:" << m_LastLogicMouseClick.y()<<endl;
        //
        // 		    cout << "m_pLogic.x:" << m_pLogic.x();
        // 		    cout << "m_pLogic.y:" << m_pLogic.y()<<endl;
        //
        // 		    cout << "moveTmp.x:" << moveTmp.x();
        // 		    cout << "moveTmp.y:" << moveTmp.y()<<endl;

        m_movedPoint->moveBy(moveTmp);
        m_LastLogicMouseClick = m_pLogic;
    }
}

void BB_ToolLineNew::release(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{		
		if(objects != NULL && me != NULL && transformer != NULL && m_movedPoint != NULL)
		{
			BB_DrawObject *object;
			m_pScreen = me->pos();
			transformer->screenToLogical(m_pLogic,m_pScreen);
			for(int i = 0; i < objects->count(); i++)
			{
				object = objects->at(i);
				if(object->isHit(m_pLogic) && (object->getClassName() == "BB_Point"))
				{
					C2dVector fromhitobject = ((BB_Point*)object)->getPos();
					cout << "Old Line : Point :" << fromhitobject.x()<<endl;
					if (!tmpWall->setPos2((BB_Point*)object))
						remove(objects, tmpWall);
					tmpWall = NULL;
					m_movedPoint = NULL;
					return;
				}
			}
			remove(objects, tmpWall);
			tmpWall = NULL;
			m_movedPoint = NULL;
		}
}

