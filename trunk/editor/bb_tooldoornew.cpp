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
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <iostream>
 
#include "bb_tooldoornew.h"

using namespace std;

BB_ToolDoorNew::BB_ToolDoorNew()
 : BB_AbstractTool()
{
}


BB_ToolDoorNew::~BB_ToolDoorNew()
{
}

void BB_ToolDoorNew::click( QMouseEvent* me )
{
	cout <<"BB_ToolDoorNew::click( QMouseEvent* me )"<<endl;
}

void BB_ToolDoorNew::move( QMouseEvent* me, bool overX, bool overY ){
	cout <<"::move( QMouseEvent* me, bool overX, bool overY )"<<endl;
}

void BB_ToolDoorNew::release( QMouseEvent* me ) {
	cout <<"BB_ToolDoorNew::release( QMouseEvent* me ) "<<endl;
}