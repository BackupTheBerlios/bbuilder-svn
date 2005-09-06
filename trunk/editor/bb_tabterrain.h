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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_TABTERRAIN_H
#define BB_TABTERRAIN_H

#include "bb_tab.h"
#include "bb_terrain.h"

/**
@author Alex Letkemann
*/
class BB_TabTerrain : public BB_Tab
{
	Q_OBJECT
public:
    BB_TabTerrain(BB_Terrain* terrain, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_TabTerrain();

};

#endif
