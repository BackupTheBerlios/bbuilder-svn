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
Die Klasse beeinhält grundlegende Funktionen.Die meisten sind virtuel
@author Vaceslav Ustinov
*/
class BB_DrawObject : public BB_Object
{
    public:
        /**
        Standart Konstruktor
        @param name Dieses und alle abgeleitete Klassen können mit diesem Parameter benannt werden. default ist ""
        @author Vaceslav Ustinov
        */
        BB_DrawObject( QString name = "" );
        /**
        Dekonstruktor
        @author Vaceslav Ustinov
        */
        virtual ~BB_DrawObject();
        /**
        Funktion zum Verschieben<br>
        Pure Virtual
        @author Vaceslav Ustinov
        */
        virtual void moveBy( C2dVector pMove );
        /**
        Funktion zum Zeichnen.<b>Pure Virtual</b>
        @param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
        @param QPainter Werkzeug zum Zeichnen @see QT::QPainter
        @author Vaceslav Ustinov
        */
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const = 0;
        //         virtual const QColor & getColor() const;
        //         virtual void setColor( const QColor& _newVal = "Green" );
        //void setP0(const QPoint& theValue){m_P0 = theValue;}
        //QPoint getP0() const{return m_P0;}
        /**
        <b>Pure Virtual</b> Uberprüft, ob der Punkt in abgeleitetem Objekt liegt
        @param hit Klick-Position
        @author Vaceslav Ustinov
        */
        virtual bool isHit( const C2dVector& hit ) = 0;
        /**
        <b>Pure Virtual</b> Uberprüft, ob der abgeleitete Objekt im Rechteck liegt
        @param rect Auswahlrecheck
        @author Vaceslav Ustinov
        */
        virtual bool isHit( const QRectF& rect );
        /**
        Gibt die Name von Klasse zurück
        @return QString Name
        @author Vaceslav Ustinov
        */
        virtual const QString getClassName();
        /**
        Setz das Eigenschft m_selected auf true. Bei dieser Option wird der Objekt anders gezeichnet
        @param theValue false oder true
        @author Vaceslav Ustinov
        */
        void setSelected( bool theValue );
        /**
        Gibt true falls Objekt selectiert ist, sonst false
        @return true oder false
        @author Vaceslav Ustinov
        */
        virtual bool isSelected() const;
        /**
        Setzt die Eigenschaften von Brush ein
        @see QT::QBrush
        @param theValue neues Wert für Brush
        @author Vaceslav Ustinov
        */
        void setBrush( const QBrush& theValue );
        /**
        Setzt die Eigenschaften von Pen ein
        @see QT::QPen
        @param theValue neues Wert für PEN
        @author Vaceslav Ustinov
        */
        void setPen( const QPen& theValue );
        /**
        <b>Pure Virtual</b><br>
        Wird aufgerufen, falls dieser Objekt von anderen Objekten bewegt wird
        @author Vaceslav Ustinov
        */
        virtual void moveEvent();
        /**
        * Virtuelle Funktion für weitere abgeleitete Klassen.
        * @param triangles Vektor, an den die Dreiecke angehängt werden.
        * @param vector Positionsektor
        * @param rotation Rotation der Dreiecke
        * @param scale Skalierung der Dreiecke
        * @param height Hier keine Funktion
        * @author Alex Letkemann
        */
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
        /**
        Setzt Texture-dateiname ein
        @param Value relative Pfadangabe
        @author Vaceslav Ustinov
        */
        void setTextureFileName( const QString& Value );
        /**
        Gibt relative Bild-Dateiname zurück
        @return relative Bild-Dateiname
        @author Vaceslav Ustinov
        */
        QString getTextureFileName() const;
        /**
        Setzt Texture-dateiname ein
        @param Value absolute Pfadangabe
        @author Vaceslav Ustinov
        */
        void setTextureAbsoluteFileName( const QString& Value );
    protected:
        /** Abstand von dem Punkt, in dem isHit immer noch true zurückliefert*/
        int m_hitRange;
        /** Gibt an ob ein Objekt selektiert ist oder nicht*/
        bool m_Selected;
        /** Farbe für Stift @see QT::QPen*/
        QPen m_Pen;
        /** Farbe für Stift, wenn ein Objekt selektiert ist @see QT::QPen*/
        QPen m_PenSelected;
        /** Fühl-Farbe @see QT::QBrush*/
        QBrush m_Brush;
        /** Fühl-Farbe,  wenn ein Objekt selektiert ist @see QT::QBrush*/
        QBrush m_BrushSelected;
        /** Textur-Dateiname*/
        QString m_TextureFileName;
};

#endif
