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
#include "bb_toolzoom.h"

#include <iostream>

using namespace std;

BB_ToolZoom::BB_ToolZoom(BB_WorkArea* area)
 : BB_AbstractTool()
{
	if(area != NULL)
	{
		m_WorkArea = area;
	}
	else
	{
		cout << "BB_ToolZoom: Fehler beim setzen der WorkArea.\nNull-Pointer erhalten";

	}
}


BB_ToolZoom::~BB_ToolZoom()
{
}


void BB_ToolZoom::click(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
	if(me->button() == Qt::LeftButton)
	{
		m_WorkArea->zoom(0.25);
	}
	else if(me->button() == Qt::RightButton)
	{
		m_WorkArea->zoom(-0.25);
	}
	else if(me->button() == Qt::MidButton)
	{
		m_WorkArea->setZoomFaktor(1.0);
	}
}

void BB_ToolZoom::move(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
}

void BB_ToolZoom::release(QMouseEvent* me, QVector<BB_DrawObject*>* objects, BB_Transformer* transformer)
{
}

