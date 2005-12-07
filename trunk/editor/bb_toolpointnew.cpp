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


void BB_ToolPointNew::click(QMouseEvent* me)
{
	
	if(m_Objects != NULL && me != NULL)
	{	
		m_pScreen = me->pos();
		m_Transformer->screenToLogical(m_pLogic,m_pScreen);
// 		cout << "New Point (" << pLogic.x() << "|" << pLogic.y() << ")" << endl;
		BB_Point *point = new BB_Point(m_pLogic);
		m_Objects->append(point);
	}
}

void BB_ToolPointNew::move(QMouseEvent* me, bool overX, bool overY)
{
	if(overX || overY)
	{
		me->ignore();
	}
}

void BB_ToolPointNew::release(QMouseEvent* me)
{
	me->ignore();
}

