/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                *
 *   v.ustinov@web.de                                                      *
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
#include "bb_dwpoint.h"

BB_DWPoint::BB_DWPoint(BB_Wall * wall, bool first)
{
	m_wall = wall;
	m_first = first;
}


BB_DWPoint::~BB_DWPoint()
{
}



bool BB_DWPoint::isFirst()
{
	return m_first;
}


/*!
    \fn BB_DWPoint::getClassName()
 */
const QString BB_DWPoint::getClassName()
{
	return QString("BB_DWPoint");
}
