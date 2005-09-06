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
#include "bb_transformer.h"

BB_Transformer::BB_Transformer()
{
	m_Scale = 1.0;
	m_Offset.setX(1);
	m_Offset.setY(1);
}


BB_Transformer::~BB_Transformer()
{}




QPoint BB_Transformer::getOffset() const
{
    return m_Offset;
}


void BB_Transformer::setOffset(const QPoint& theValue)
{
    m_Offset = theValue;
}


double BB_Transformer::getScale() const
{
    return m_Scale;
}


void BB_Transformer::setScale(double theValue)
{
    m_Scale = theValue;
}

void BB_Transformer::screenToLogical(QPoint & dest, const QPoint & source) const
{
	dest.setX((int)(source.x() - m_Offset.x()) / m_Scale);
	dest.setY((int)-((source.y() - m_Offset.y()) / m_Scale));
}

void BB_Transformer::logicalToScreen(QPoint & dest, const QPoint & source) const
{
	dest.setX((int) (source.x() * m_Scale) + m_Offset.x());
	dest.setY((int) (-source.y() * m_Scale) + m_Offset.y());
}
