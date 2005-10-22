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

#include "bb_point.h"

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


/*!
    \fn BB_Wall::generateXElement(QTextStream &out, int depth)
 */
void BB_Wall::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<bb_wall id=\"" << getObjectNr() 
			<< "\" p1=\"" << getPos1()->getObjectNr() 
			<< "\" p2=\"" << getPos2()->getObjectNr() << "\">\n";
	
	BB_Object::generateXElement(out,depth+1);
	out << BB::indent(depth) << "</bb_wall>\n";
}
