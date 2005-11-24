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
#include <iostream>
#include <math.h>

using namespace std;

BB_ToolMove::BB_ToolMove()
        : BB_AbstractTool()
{
    comparePoint = NULL;
}


BB_ToolMove::~BB_ToolMove()
{}


void BB_ToolMove::click(QMouseEvent* me)
{
    if(m_Objects != NULL && me != NULL && m_Transformer != NULL)
    {
                if(m_Selection->count() == 1)
                {
                        m_Selection->clear();
                        for(int i = 0; i < m_Selection->count(); i++)
                        {
                                m_Selection->at(i)->setSelected(false);
                        }
                }

        BB_DrawObject *object;


        m_pScreen = me->pos();
        m_Transformer->screenToLogical(m_pLogic,m_pScreen);
        m_LastLogicMouseClick = m_pLogic;

                if(m_Selection->count() == 0)
                {
                        for(int i = 0; i < m_Objects->count(); i++)
                        {
                                object = m_Objects->at(i);
                                //--------zur presentation
                                if (object->getClassName() == "BB_Point")
                                ((BB_Point *)object)->setScale(m_Transformer->getScale());
                                //---------ende-----------
                                if(object->isHit(m_pLogic))
                                {
                                //punkt loeschen
                                        if (me->button () ==  Qt::RightButton && object->getClassName() == "BB_Point")
                                        {
                                                BB_AbstractTool::remove(object);
//                                              ((BB_Point *)object)->deleteLines(m_Objects);
                                                ((BB_Point *)object)->deleteLinkedObjects(m_Objects);
                                                delete object;
                                                return;
                                        }
                                        //Punkten ausrichten
                                        if (me->button() == Qt::MidButton && object->getClassName() == "BB_Point")
                                        {
                                        bringToLine((BB_Point *)object);
                                        //if(tabCreator != NULL)
                                        // tabCreator->createProperties(((BB_Point *)object)->getItemModel());
                                        }
                                        m_Selection->append(object);
                                }
                        }
                }
    }
}

void BB_ToolMove::move(QMouseEvent* me, bool overX, bool overY)
{

    if(m_Objects != NULL && me != NULL && m_Transformer != NULL)
    {

        for(int i = 0; i < m_Selection->count(); i++)
        {
            C2dVector moveTmp;
            m_Transformer->screenToLogical(m_pLogic,me->pos());
            moveTmp.setX(m_pLogic.x() - m_LastLogicMouseClick.x());
            moveTmp.setY(m_pLogic.y() - m_LastLogicMouseClick.y());

                        if(overX)
                        {
                                moveTmp.setX(0);
                        }

                        if(overY)
                        {
                                moveTmp.setY(0);
                        }

            m_Selection->at(i)->moveBy(moveTmp);
        }

        m_Transformer->screenToLogical(m_LastLogicMouseClick,me->pos());
    }
}

void BB_ToolMove::release(QMouseEvent* me)
{
    /* Übergebene Variablen, die nicht verwendet werden */
        me->ignore();
//     if (comparePoint != NULL){
//       comparePoint->setSelected(false);
//       comparePoint = NULL;
//     }
}





void BB_ToolMove::bringToLine(BB_Point *point)
{
  if(comparePoint!=NULL)
  {
    if (comparePoint == point){
      comparePoint->setSelected(false);
      comparePoint = NULL;
      return;
    }
    double x = point->getX() - comparePoint->getX();
    double y = point->getY() - comparePoint->getY();
    double winkel = atan((y / x));//radiant
    winkel = winkel * 180.0  / M_PI; //gradient
    winkel = abs ((int) winkel);
    cout << "Winkel"<< winkel <<endl;
    if (winkel <= 45)
      point->setY(comparePoint->getY());
    else
      point->setX(comparePoint->getX());
    comparePoint->setSelected(false);
    comparePoint = NULL;
//                       cout << "ausrichten"<<endl;
  }else{
    comparePoint = (BB_Point *) point;
    point->setSelected(true);
                      cout << "setzen von bringToLinePoint"<<endl;
  }
}
