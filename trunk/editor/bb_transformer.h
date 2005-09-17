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
    BB_Transformer();

    ~BB_Transformer();

    void setOffset(const QPoint& theValue);


    QPoint getOffset() const;

    void setScale(double theValue);


    double getScale() const;

    /** diese Funktion convertiert von bildschirmkoordinaten ins logische Koordinate
    @param dest ein Vektor mit Bildschirmkoordinaten
    @param source Ein punkt mit logischen koordinaten
    */
    void screenToLogical(C2dVector & dest, const QPoint & source) const;
    
    
    /** diese Funktion convertiert von logischen ins Bildschirmkoordinate
    @param dest ein Vektor mit Bildschirmkoordinaten
    @param source Ein punkt mit logischen koordinaten
     */
    void logicalToScreen(QPoint & dest, const C2dVector & source) const;


private:
    double m_Scale;
    QPoint m_Offset;
};

#endif
