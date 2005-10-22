/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                *
 *   V.Ustinov@web.de                                                      *
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
#include "bb_wall.h"

BB_Wall::BB_Wall(BB_Point* p1, BB_Point* p2): BB_Line(p1, p2)
{
}


BB_Wall::~BB_Wall()
{
}



/*!
    \fn BB_Wall::getClassName()
 */
const QString BB_Wall::getClassName()
{
	return QString("BB_Wall");
}
