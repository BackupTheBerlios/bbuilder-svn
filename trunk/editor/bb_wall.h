/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   v.ustinov@web.de   											*
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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_WALL_H
#define BB_WALL_H

#include <bb_line.h>

/**
Diese Klasse representiert eine Wand,
sie hat zwei pointer auf BB_WallPoint.
Eigene Pinkten hat sie nicht

@author Vaceslav Ustinov
*/
class BB_Wall : public BB_Line
{
public:
    BB_Wall(BB_DrawObject* p1, BB_DrawObject* p2);

    ~BB_Wall();

    const char* getClassName() const;
    
private:
	static const char * ClassName;

};

#endif
