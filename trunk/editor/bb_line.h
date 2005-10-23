/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
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
    BB_Line(BB_Point *p1, BB_Point *p2);
    BB_Line();

    ~BB_Line();

    virtual bool isHit(C2dVector hit);
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;

    /**
    Setzt Pointer auf Position 1
    @author Vacelav Ustinov
    @param BB_Point 
    */
    bool setPos1(BB_Point* Value);

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
    bool setPos2(BB_Point* Value);

    /**
    gibt Pointer auf Punkt 2 zurück
    @author Vaceslav Ustinov
    @return BB_Point *.
    */
    BB_Point* getPos2() const;

    void remove(BB_Point * point);
    virtual const QString getClassName();




protected:
    BB_Point * m_Pos1;
    BB_Point * m_Pos2;
    C2dVector m_Richtung;
};

#endif
