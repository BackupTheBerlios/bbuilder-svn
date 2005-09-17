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
#include <bb_point.h>

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

//     QPoint getP0() const;
    virtual bool isHit(C2dVector hit);
    virtual const QColor& getColor() const;
    virtual void moveBy(QPoint pMove);
    virtual void setColor(const QColor& _newVal);
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
//     void setP0(const QPoint& theValue);

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
    @return BB_Point*
    */
    BB_Point* getPos2() const;
    
    const char * getClassName() const;
    double getLaenge();




protected:
    BB_Point * m_Pos1;
    BB_Point * m_Pos2;
    C2dVector m_Richtung;
private:
	static const char * ClassName;
};

#endif
