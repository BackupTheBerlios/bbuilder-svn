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
#include "bb_line.h"

BB_Line::BB_Line(QPoint p): BB_DrawObject(p)
{
}


BB_Line::~BB_Line()
{
}


QPoint BB_Line::getP0() const
{
    return BB_DrawObject::getP0();
}

bool BB_Line::isHit(QPoint hit)
{
    return BB_DrawObject::isHit(hit);
}

const QColor& BB_Line::getColor() const
{
    return BB_DrawObject::getColor();
}

void BB_Line::moveBy(QPoint pMove)
{
    BB_DrawObject::moveBy(pMove);
}

void BB_Line::setColor(const QColor& _newVal)
{
    BB_DrawObject::setColor(_newVal);
}

void BB_Line::show(BB_Transformer& transformer, QPainter& painter) const
{
    BB_DrawObject::show(transformer, painter);
}

void BB_Line::setP0(const QPoint& theValue)
{
    BB_DrawObject::setP0(theValue);
}

