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
#ifndef BB_STAIR_H
#define BB_STAIR_H

#include <bb_rect.h>

/**
Implementation von Treppe

	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_Stair : public BB_Rect
{
public:
    BB_Stair();

    ~BB_Stair();

	virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
	void generateXElement( QTextStream &out, int depth );

};

#endif
