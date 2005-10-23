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
#include "bb_abstracttool.h"

#include <iostream>

using namespace std;

BB_AbstractTool::BB_AbstractTool()
{
}

BB_AbstractTool::~BB_AbstractTool()
{
}

bool BB_AbstractTool::remove(QVector<BB_DrawObject*>* objects, BB_DrawObject * delObject)
{
	BB_DrawObject * tmpObject;
	int objectPosition;
	objectPosition = -1;
	for (int i=0; i<objects->count(); i++)
	{
		tmpObject = objects->at(i);
		if (tmpObject == delObject)
		{
			objectPosition = i;
		}
	}
	cout << objectPosition <<endl;
	objects->remove(objectPosition);
	
	if(objectPosition == -1) 
		return false;
	else
		return true;
}

