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
 ***************************************************************************/
#include "bb_toolmove.h"
#include <iostream.h>
#include "bb_point.h"

BB_ToolMove::BB_ToolMove()
                : BB_AbstractTool()
{}


BB_ToolMove::~BB_ToolMove()
{}


void BB_ToolMove::click(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
        if(objects != NULL && me != NULL && transformer != NULL) {
                m_Selection.clear();
                BB_DrawObject *object;


                m_pScreen = me->pos();
                transformer->screenToLogical(m_pLogic,m_pScreen);
                m_LastLogicMouseClick = m_pLogic;


                for(int i = 0; i < objects->count(); i++) {
                        object = objects->at(i);
                        if(object->isHit(m_pLogic)) {
                                if (me->button () ==  Qt::RightButton) {
                                        remove (objects, object);
                                        ((BB_Point *)object)->deleteLines(objects);
                                        delete object;
                                        return;
                                }
                                m_Selection.append(object);
                        }
                }
        }
}

void BB_ToolMove::move(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{

        if(objects != NULL && me != NULL && transformer != NULL) {

                for(int i = 0; i < m_Selection.count(); i++) {
                        C2dVector moveTmp;
                        transformer->screenToLogical(m_pLogic,me->pos());
                        moveTmp.setX(m_pLogic.x() - m_LastLogicMouseClick.x());
                        moveTmp.setY(m_pLogic.y() - m_LastLogicMouseClick.y());

                        m_Selection.at(i)->moveBy(moveTmp);
                }

                transformer->screenToLogical(m_LastLogicMouseClick,me->pos());
        }
}

void BB_ToolMove::release(QMouseEvent* me, QVector< BB_DrawObject * >* objects, BB_Transformer* transformer)
{
	/* Übergebene Varieblen, die nicht verwendet werden */	
	me = NULL;
	objects = NULL;
	transformer = NULL;
}


