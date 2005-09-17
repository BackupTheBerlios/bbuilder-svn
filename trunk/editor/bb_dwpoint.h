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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_DWPOINT_H
#define BB_DWPOINT_H

#include "bb_wall.h"

/**
BB_DWPoint - Door or Window Point

@author Vaceslav Ustinov
*/
class BB_DWPoint{
public:
    BB_DWPoint(BB_Wall * wall);

    ~BB_DWPoint();
private:
	BB_Wall * m_wall;
	double m_Pos;

};

#endif
