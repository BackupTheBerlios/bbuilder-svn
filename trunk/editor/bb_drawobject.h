/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann                                  *
 *   alex@letkemann.de                                                     *
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
#ifndef BB_DRAWOBJECT_H
#define BB_DRAWOBJECT_H

#include <QPoint>
#include <QPainter>
#include <QColor>

#include "bb_object.h"
#include "bb_transformer.h"


/**
Template-Klasse fuer weitere Objekte in diesem Projekt (z.B point, Wand, Fenster, etc)
Die Klasse beeinhaelt grundlegende Funktionen.

@author Alex Letkemann
*/
class BB_DrawObject : public BB_Object 
{
public:
    BB_DrawObject();
    BB_DrawObject(QPoint p);

    virtual ~BB_DrawObject();
    virtual void moveBy(QPoint pMove);
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    virtual const QColor & getColor()const;
    virtual void setColor(const QColor& _newVal = "Green");
    void setP0(const QPoint& theValue){m_P0 = theValue;}
    QPoint getP0() const{return m_P0;}
    virtual bool isHit(QPoint hit);
protected:
    QPoint m_P0;
    QColor m_Color;
    int m_hitRange;
};

#endif
