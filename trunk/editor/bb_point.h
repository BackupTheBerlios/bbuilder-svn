/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   alex@letkemann.de   										*
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
#ifndef BB_POINT_H
#define BB_POINT_H

#include <bb_drawobject.h>
using namespace std;

/**
Klasse zum darstellen von einem verbindungs-Punkt

@author Vaceslav Ustinov
*/
class BB_Point : public BB_DrawObject
{
public:
    BB_Point();
    BB_Point(QPoint p);

    ~BB_Point();


    virtual void moveBy( QPoint pMove);
	virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    int getRadius();
    void setRadius(int r);
    virtual bool isHit(QPoint hit);
    const char * getClassName() const;

private:
    int m_Radius;
    static const char * ClassName;
};

#endif
