/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                     *
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
#include <c3dtriangle.h>

/**
Template-Klasse fuer weitere Objekte in diesem Projekt (z.B point, Wand, Fenster, etc)
Die Klasse beinhaltet grundlegende Funktionen.
 
@author Vaceslav Ustinov
*/
class BB_DrawObject : public BB_Object
{
    public:
        BB_DrawObject( QString name = "" );

        virtual ~BB_DrawObject();
        virtual void moveBy( C2dVector pMove );
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const = 0;
        //         virtual const QColor & getColor() const;
        //         virtual void setColor( const QColor& _newVal = "Green" );
        //void setP0(const QPoint& theValue){m_P0 = theValue;}
        //QPoint getP0() const{return m_P0;}
        virtual bool isHit( const C2dVector& hit ) = 0;
        virtual bool isHit( const QRect& rect );
        virtual const QString getClassName();

        void setSelected( bool theValue );
        virtual bool isSelected() const;

        void setBrush( const QBrush& theValue );
        void setPen( const QPen& theValue );
        virtual void moveEvent();
		virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
    protected:
        //QPoint m_P0;
        //         QColor m_Color;
        int m_hitRange;
        bool m_Selected;
        QPen m_Pen;
        QPen m_PenSelected;
        QBrush m_Brush;
        QBrush m_BrushSelected;
/*		
		C3dPoint* m_GlObject;*/
    
};

#endif
