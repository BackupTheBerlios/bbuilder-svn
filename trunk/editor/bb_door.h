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
Dieses Class dient zum Darstellen von einer T&uuml;r<br>
@author Vaceslav Ustinov <v.ustinov@web.de>
@see BB_ConstructionElement
*/
class BB_Door : public BB_ConstructionElement
{
    public:
        /**
        Standart Konstruktor
        @param v1 Position von obere-linke Ecke
        @param v2 Position von untere-rechte Ecke
        @author Vaceslav Ustinov
        */
        BB_Door( C2dVector v1, C2dVector v2 );
        /**
        Dekonstruktor
        */
        ~BB_Door();
        /**
         * Schreibt das XML-Element des Construktionselementes in den angegeben Stream. 
         * @param out Stream, in welchen geschrieben werden soll. 
         * @param depth Einrückung. 
         * @author Vaceslav Ustinov 
        */
        void generateXElement( QTextStream &out, int depth );

};

#endif
