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
#include "bb_toolwindownew.h"
#include "bb_window.h"

BB_ToolWindowNew::BB_ToolWindowNew()
	: BB_AbstractTool()
{
}


BB_ToolWindowNew::~BB_ToolWindowNew()
{
}


void BB_ToolWindowNew::click(QMouseEvent* me)
{
	m_pScreen = me->pos();
	m_Transformer->screenToLogical( m_pLogic, m_pScreen );
	m_LastLogicMouseClick = m_pLogic;
	m_Objects->append(new BB_Window(m_pLogic));
}

void BB_ToolWindowNew::move(QMouseEvent* me, bool overX, bool overY)
{
}

void BB_ToolWindowNew::release(QMouseEvent* me)
{
}

