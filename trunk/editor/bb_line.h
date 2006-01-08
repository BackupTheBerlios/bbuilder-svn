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
***************************************************************************/
#ifndef BB_LINE_H
#define BB_LINE_H

#include <bb_drawobject.h>


class BB_Point;

/**
Klasse zum Darstellen von Wänden und Fenstern
 
@author Vaceslav Ustinov
*/
class BB_Line : public BB_DrawObject
{
    public:
        BB_Line( BB_Point *p1, BB_Point *p2 );
        //     BB_Line();

        ~BB_Line();

        virtual bool isHit( const C2dVector& hit );
        virtual bool isHit( const QRectF& rect );
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;

        /**
        Setzt Pointer auf Position 1
        @author Vacelav Ustinov
        @param BB_Point
        */
        bool setPos1( BB_Point* Value );

        /**
        gibt Pointer auf Punkt 1 zurück
        @author Vaceslav Ustinov
        @return BB_Point*
        */
        BB_Point* getPos1() const;

        /**
        Setzt Pointer auf Position 2
        @author Vacelav Ustinov
        @param BB_Point
        */
        bool setPos2( BB_Point* Value );

        /**
        gibt Pointer auf Punkt 2 zurück
        @author Vaceslav Ustinov
        @return BB_Point *.
        */
        BB_Point* getPos2() const;

        //         virtual void remove( BB_Point * point );
        virtual const QString getClassName();

        double getLength();
        /**
        * Winkel zu x-Achse
        * @author Vaceslav Ustinov
        * @return double Winkel
        */
        double getWinkel() const;
        virtual void moveEvent();
        const C2dVector& getMiddle();

    private:
        /**
         * Berechnet die Mitte der Linie und speichert diese im m_Middle Vektor.
         * @author Alex Letkemann
         */
        virtual void calculateMiddle();




    protected:
        BB_Point * m_Pos1;
        BB_Point * m_Pos2;
        /**
        *Ein Richtungs-Vector (also Pos2-Pos1)
        */
        C2dVector m_Richtung;

        /** Mitte der Linie */
        C2dVector m_Middle;
};

#endif
