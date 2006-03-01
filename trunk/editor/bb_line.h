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
Basis-Klass für folgende Objekte: BB_NavigationLine , BB_Rect , BB_Triangle , BB_Wall<br>
Eine Linie hat zwei Bezugspunkte. Das heisst die Linie hat kiene eigene Position<br>
Position wird durch verweise auf zwei Punkte (BB_point) bestimmt
@author Vaceslav Ustinov
*/
class BB_Line : public BB_DrawObject
{
    public:
        /**
        Standart Konstruktor mit zwei Punkte als Parametern
        @param BB_Point p1 Position 1
        @param BB_Point p2 Position 2
        @author Vaceslav Ustinov
        */
        BB_Line( BB_Point *p1, BB_Point *p2 );
        /**
        Dekonstruktor
        @author Vaceslav Ustinov
        */
        ~BB_Line();
        /**
        Funktion uberprüft ob der Punkt "hit" auf der Linie liegt
        @param C2dVector Klick-Position
        @author Vaceslav Ustinov
        */
        virtual bool isHit( const C2dVector& hit );
        /**
        Funktion uberprüft ob die Linie in angegebenen Rechteck "rect" liegt
        @param QRectF Ausgewählte Rechteck
        @author Vaceslav Ustinov
        */
        virtual bool isHit( const QRectF& rect );
        /**
        Funktion zum Zeichnen.
        @param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
        @param QPainter Werkzeug zum Zeichnen @see QT::QPainter
        @author Vaceslav Ustinov
        */
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
        /**
        Setzt Pointer "Value" auf Position 1
        @author Vacelav Ustinov
        @param BB_Point
        */
        bool setPos1( BB_Point* Value );
        /**
        Gibt Pointer von Position 1 zurück
        @author Vaceslav Ustinov
        @return BB_Point *
        */
        BB_Point* getPos1() const;
        /**
        Setzt Pointer "Value" auf Position 2
        @author Vacelav Ustinov
        @param BB_Point
        */
        bool setPos2( BB_Point* Value );

        /**
        Gibt Pointer Position 2 zurück
        @author Vaceslav Ustinov
        @return BB_Point *.
        */
        BB_Point* getPos2() const;
        /**
        Gibt die Name von Klasse zurück
        @return QString Name
        @author Vaceslav Ustinov
        */
        virtual const QString getClassName();
        /**
        Gibt die Länge von der Linie zurück
        */
        double getLength();
        /**
        * Gibt den Winkel zu x-Achse
        * @author Vaceslav Ustinov
        * @return double Winkel
        */
        double getWinkel() const;
        /**
        Ein Erreignis, das aufgerufen wird, wenn das Objekt durch abhängige Objekte bewegt wird.
        @author Vaceslav Ustinov
        */
        virtual void moveEvent();
        /**
         * Gibt die Mitte der Linie zurück
         * @return C2dVector Position von der Linien-Mitte
         * @author Alex Letkemann
         */
        const C2dVector& getMiddle();

    private:
        /**
         * Berechnet die Mitte der Linie und speichert diese im m_Middle Vektor.
         * @author Alex Letkemann
         */
        virtual void calculateMiddle();
    protected:
        /**
        Das ist die Position 1. Es ist ein Zeiger auf einen Punkt (BB_Point)
        */
        BB_Point * m_Pos1;
        /**
        Das ist die Position 2. Es ist ein Zeiger auf einen Punkt (BB_Point)
        */
        BB_Point * m_Pos2;
        /**
        *Ein Richtungs-Vector (also Pos2-Pos1)
        */
        C2dVector m_Richtung;

        /**
        Mitte der Linie 
        */
        C2dVector m_Middle;
};

#endif
