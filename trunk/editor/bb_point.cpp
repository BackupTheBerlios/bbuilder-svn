/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                             *
 *   v.ustinov@web.de                                                                                           *
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
#include "bb_point.h"

#include <iostream>
#include <math.h>
#include "bb_line.h"

using namespace std;


BB_Point::BB_Point()
                : BB_DrawObject()
{
        m_Radius = 10;
        m_hitRange = 2;
}

BB_Point::BB_Point(C2dVector p)
{
        m_Pos = p;
        m_Radius = 7;
        m_Color.setNamedColor("Red");
        m_hitRange = 2;
}


BB_Point::~BB_Point()
{}


// void BB_Point::moveBy(QPoint pMove)
// {
//     m_P0.setX(m_P0.x() + pMove.x());
//     m_P0.setY(m_P0.y() + pMove.y());
// }

void BB_Point::moveBy(C2dVector vMove)
{
        m_Pos = m_Pos + vMove;
}

void BB_Point::show(BB_Transformer& transformer, QPainter& painter) const
{
        QPoint dest;
        double breite = m_Radius / 3;

        transformer.logicalToScreen(dest, m_Pos);

        painter.setPen(m_Color);
        painter.setBrush(m_Color);
        //painter.drawEllipse(dest.x() - m_Radius, dest.y() - m_Radius, m_Radius*2, m_Radius*2);
        painter.drawRect(dest.x() - m_Radius, dest.y() - m_Radius,
                         m_Radius*2, breite);
        painter.drawRect(dest.x() - m_Radius, dest.y() + m_Radius - breite,
                         m_Radius*2, breite);
        painter.drawRect(dest.x() - m_Radius, dest.y() - m_Radius + breite,
                         breite, m_Radius * 2 - breite * 2);
        painter.drawRect(dest.x() + m_Radius -breite, dest.y() - m_Radius + breite,
                         breite, m_Radius * 2 - breite * 2);
        painter.setBrush(QColor(0,200,0));
        painter.setPen(QColor(0,200,0));
        painter.drawRect(dest.x() - breite, dest.y() - breite,
                         breite * 2, breite * 2);
}



/*!
    \fn BB_Point::getRadius()
 */
int BB_Point::getRadius()
{
        return m_Radius;
}


/*!
    \fn BB_Point::setRadius(int r)
 */
void BB_Point::setRadius(int r)
{
        m_Radius = r;
}

bool BB_Point::isHit(C2dVector hit)
{
  //isHit von Kreis
//         double abstand = m_Pos.getAbstand(hit);
//         if(abstand <= (m_Radius + m_hitRange))
//                 return true;
//         return false;

  //isHit von Viereck
  double abstandX = abs ((int) (hit.x() - m_Pos.x()));
  double abstandY = abs ((int) (hit.y() - m_Pos.y()));
  if (abstandX <= m_Radius && abstandY <= m_Radius)
    return true;
  return false;
}




C2dVector BB_Point::getPos() const
{
        return m_Pos;
}


void BB_Point::setPos(const C2dVector& theValue)
{
        m_Pos = theValue;
}


/*!
    \fn BB_Point::deleteLines()
 */
void BB_Point::deleteLines(QVector< BB_DrawObject * >* objects)
{
        BB_Line * tmp;
        for (int i = 0; i < m_Lines.count(); i++) {
                tmp = m_Lines.at(i);
                BB_DrawObject * tmp_object;
                for (int j = 0; j < objects->count(); j++) {
                        tmp_object = objects->at(j);
                        if(tmp_object == tmp)
                                objects->remove(j);
                }
                //m_Lines.remove(i);
                cout <<"linie nummer "<< i << ":" << tmp <<endl;
                tmp->remove(this);
                cout <<"linie nummer(delete) "<< i << ":" << tmp <<endl;
        }
        m_Lines.clear();
}


/*!
    \fn BB_Point::removeMe(BB_Line * line)
 */
void BB_Point::removeLine(BB_Line * line)
{
        BB_Line * tmp;
        for (int i = 0; i<m_Lines.count(); i++) {
                tmp = m_Lines.at(i);
                if (tmp == line) {
                        m_Lines.remove(i);
                        delete line;
                }
        }
}


/*!
    \fn BB_Point::addLine()
 */
void BB_Point::addLine(BB_Line * line)
{
        m_Lines.insert(m_Lines.count(), line);
}

/*!
    \fn BB_Point::getClassName()
 */
const QString BB_Point::getClassName()
{
	return QString("BB_Point");
}
void BB_Point::setX(double value){
  m_Pos.setX(value);
}
void BB_Point::setY(double value){
  m_Pos.setY(value);
}
