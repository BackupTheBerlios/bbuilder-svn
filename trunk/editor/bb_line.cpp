/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   v.ustinov@web.de										     *
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

const char * BB_Line::ClassName = "BB_Line";

BB_Line::BB_Line(BB_DrawObject *p1, BB_DrawObject *p2)
{
	m_Pos1 = p1;
	m_Pos2 = p2;
	m_Color.setNamedColor("Red");
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
	return false;
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
    
    QPoint dest_Pos1;
    QPoint dest_Pos2;

    transformer.logicalToScreen(dest_Pos1, m_Pos1->getP0());
    transformer.logicalToScreen(dest_Pos2, m_Pos2->getP0());

    painter.setPen(m_Color);
    painter.setBrush(m_Color);
    painter.drawLine(dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y());
}

void BB_Line::setP0(const QPoint& theValue)
{
    BB_DrawObject::setP0(theValue);
}



BB_DrawObject* BB_Line::getPos1() const
{
    return m_Pos1;
}


void BB_Line::setPos1(BB_DrawObject* Value)
{
    m_Pos1 = Value;
}


BB_DrawObject* BB_Line::getPos2() const
{
    return m_Pos2;
}


void BB_Line::setPos2(BB_DrawObject* Value)
{
    m_Pos2 = Value;
}


const char * BB_Line::getClassName() const
{
	return BB_Line::ClassName;
}
