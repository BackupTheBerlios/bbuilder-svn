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
#ifndef BB_TOOLDOORNEW_H
#define BB_TOOLDOORNEW_H

#include <bb_abstracttoolwalledit.h>

/**
* tool zum erstellen von neuen T&uuml;ren
* @author Vaceslav Ustinov <v.ustinov@web.de>
* @date 21-12-2005
*/
class BB_ToolDoorNew : public BB_AbstractTool
{
    public:
        BB_ToolDoorNew();

        ~BB_ToolDoorNew();
	protected:
		void click( QMouseEvent* me );
		 void move( QMouseEvent* me, bool overX, bool overY );
		 void release( QMouseEvent* me ) ;

};

#endif
