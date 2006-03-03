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
Objekt zum Darstellen von Treppen
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_Stair : public BB_Rect
{
    public:
        /**
        Konstruktor ohne Parameter<br>
        Die Positionen werden auf (0;0) gesetzt
        @author Vaceslav Ustinov
        */
        BB_Stair();
        /**
        Dekonstruktor
        @author Vaceslav Ustinov
        */
        ~BB_Stair();
        /**
        Funktion zum Zeichnen.
        @param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
        @param QPainter Werkzeug zum Zeichnen @see QT::QPainter
        @author Vaceslav Ustinov
        */
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
        /**
        Funktion uberprüft ob der Punkt auf angegebene Position "hit" liegt
        @param hit Klick-Position
        @author Vaceslav Ustinov
        @return true falls Hit in Treppe liegt, false falls nicht
        */
        virtual bool isHit( const C2dVector& hit );
        /**
         * Schreibt das XML-Element von der Treppe in den angegeben Stream. 
         * @param out Stream, in welchen geschrieben werden soll. 
         * @param depth Einrückung. 
         * @author Vaceslav Ustinov
        */
        void generateXElement( QTextStream &out, int depth );

};

#endif
