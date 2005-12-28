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
#ifndef BB_CONSTRUCTIONELEMENT_H
#define BB_CONSTRUCTIONELEMENT_H

#include <bb_rect.h>

/**
Eine Basis-Klasse fuer allle Konstruktion-Elemente z.B: Fenster oder T&uuml;r
In Zukunft auch m&ouml;glicherweise Bilder und Poster

	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ConstructionElement : public BB_Rect
{
public:
	BB_ConstructionElement();

    ~BB_ConstructionElement();

};

#endif
