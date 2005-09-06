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
#include "bb_point.h"

#include <iostream>

using namespace std;

BB_Point::BB_Point()
        : BB_DrawObject()
{
    m_Radius = 10;
}

BB_Point::BB_Point(QPoint p)
        : BB_DrawObject(p)
{
    m_Radius = 10;
    m_Color.setNamedColor("Red");
    m_hitRange = 2;
}


BB_Point::~BB_Point()
{}


void BB_Point::moveBy(QPoint pMove)
{
    m_P0.setX(m_P0.x() + pMove.x());
    m_P0.setY(m_P0.y() + pMove.y());
}

void BB_Point::show(BB_Transformer& transformer, QPainter& painter) const
{
    QPoint dest;

    transformer.logicalToScreen(dest, m_P0);

    painter.setPen(m_Color);
    painter.setBrush(m_Color);
    painter.drawEllipse(dest.x() - m_Radius, dest.y() - m_Radius, m_Radius*2, m_Radius*2);
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

bool BB_Point::isHit(QPoint hit)
{

double abstand = sqrt((double)((m_P0.x() - hit.x()) * (m_P0.x() - hit.x())) + ((m_P0.y() - hit.y()) * (m_P0.y() - hit.y())));
if(abstand <= (m_Radius + m_hitRange))
   return true;
return false;
}
