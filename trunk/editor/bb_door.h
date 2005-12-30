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
#ifndef BB_DOOR_H
#define BB_DOOR_H

#include <bb_constructionelement.h>

/**
Eine Klasse zum Darstellen von einer T&uuml;r

	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_Door : public BB_ConstructionElement
{
public:
    BB_Door();
	BB_Door(C2dVector v);

    ~BB_Door();

	/**
	Abgeleitete Funktion zum Zeichnen von einer T&uuml;r
	@param BB_Transformer
	@param QPainter von QT
	 */
	virtual void show( BB_Transformer& transformer, QPainter& painter ) const;

};

#endif
