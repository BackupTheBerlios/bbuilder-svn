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
#include "bb_toolpointnew.h"

#include <iostream>

using namespace std;

BB_ToolPointNew::BB_ToolPointNew()
 : BB_AbstractTool()
{
}


BB_ToolPointNew::~BB_ToolPointNew()
{
}


void BB_ToolPointNew::click(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
	cout << "New Point" << endl;
	if(objects != NULL)
	{	
		QPoint pScreen,pLogic;
		pScreen.setX(me->x());
		pScreen.setY(me->y());
		transformer->screenToLogical(pLogic,pScreen);
		BB_Point *point = new BB_Point(pLogic);
		objects->append(point);
	}
}

void BB_ToolPointNew::move(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
}

void BB_ToolPointNew::release(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
}

