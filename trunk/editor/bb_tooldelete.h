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
#ifndef BB_TOOLDELETE_H
#define BB_TOOLDELETE_H

#include <bb_abstracttool.h>

/**
Tool zum Loschen von Objekten

	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ToolDelete : public BB_AbstractTool
{
public:
	BB_ToolDelete(QWidget * parent);

    ~BB_ToolDelete();

    virtual void click(QMouseEvent* me);

};

#endif
