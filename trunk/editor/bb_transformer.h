/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov   						*
*   v.ustinov@web.de   											*
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
#ifndef BB_TRANSFORMER_H
#define BB_TRANSFORMER_H

#include <QPoint>
#include "c2dvector.h"

/**
eine Klasse zum konvertieren von logischen ins Bildschirmkoordinate und umgekehrt
<br>Die y Achse wird gespiegelt (y=-y), und x wird mit offset addiert
@author Vaceslav Ustinov
*/
class BB_Transformer
{
    public:
        /**
        Standart Konstruktor
        @author Vaceslav Ustinov
        */
        BB_Transformer();
        /**
        Standart Dekonstruktor
        @author Vaceslav Ustinov
        */
        ~BB_Transformer();
        /**
        Setzt den Offset ein<br>
        Offset ist der Abstand von Obere Linke Ecke
        @param value Neues Wert für Offset
        @author Vaceslav Ustinov
        */
        void setOffset( const C2dVector& value );
        /**
        Gibt den Offset zurück
        @return C2dVector der Offset
        @author Vaceslav Ustinov
        */
        C2dVector getOffset() const;
        /**
        Setzt Skalierung
        @param value neues Wert für Skalierung
        @author Vaceslav Ustinov
        */
        void setScale( double value );
        /**
        Gibt aktuelle Skalierung zurück
        @return double m_Scale
        @author Vaceslav Ustinov
        */
        double getScale() const;

        /** diese Funktion convertiert von bildschirmkoordinaten ins logische Koordinate
        @param dest ein Vektor mit Bildschirmkoordinaten
        @param source Ein punkt mit logischen koordinaten
        @author Vaceslav Ustinov
        */
        void screenToLogical( C2dVector & dest, const QPoint & source ) const;


        /** diese Funktion convertiert von logischen ins Bildschirmkoordinate
        @param dest ein Vektor mit Bildschirmkoordinaten
        @param source Ein punkt mit logischen koordinaten
        @author Vaceslav Ustinov
         */
        void logicalToScreen( QPoint & dest, const C2dVector & source ) const;


    private:
        /** Skalierung: Wert || Mastab*/
        double m_Scale;
        /** Offset: Abstand von Obere-linke Ecke*/
        C2dVector m_Offset;
};

#endif
