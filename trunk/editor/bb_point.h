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
#ifndef BB_POINT_H
#define BB_POINT_H

#include "bb_drawobject.h"
#include "c2dvector.h"
#include <QStandardItemModel>
using namespace std;

class BB_Line;

/**
Klass zum Darstellen von einem Verbindungs-Punkt
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_Point : public BB_DrawObject
{
    public:
        /**
        Konstruktor ohne Parameter<br>
        Die Positionen werden auf (0;0) gesetzt
        @author Vaceslav Ustinov
        */
        BB_Point();
        /**
        Konstructor mit C2dVector<br>
        @param p Position auf die Karte
        @author Vaceslav Ustinov
         */
        BB_Point( C2dVector p );
        /**
        Konstructor mit QPoint
        @param p Position auf die Karte
        @author Vaceslav Ustinov
        */
        BB_Point( QPoint p );
        /**
        Dekonstruktor
        @author Vaceslav Ustinov
        */
        ~BB_Point();
        /**
        Verschiebt den Punkt um angegebenen Abstand
        @param pMove Ein Schiebe-Vector
        @author Vaceslav Ustinov
        */
        virtual void moveBy( C2dVector pMove );
        /**
        Funktion zum Zeichnen.
        @param transformer Transformation-Tool, damit es korrekt gezeichnet wird
        @param painter Werkzeug zum Zeichnen @see QT::QPainter
        @author Vaceslav Ustinov
        */
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
        /**
        Gibt das Radius von dem Punkt zurück
        @return double Radius in Pixel
        @author Vaceslav Ustinov
        */
        double getRadius();
        /**
        Setzt das Radius von dem Punkt fest ein
        @author Vaceslav Ustinov
        */
        void setRadius( double r );
        /**
        Funktion uberprüft ob der Punkt auf angegebene Position "hit" liegt
        @param hit Klick-Position
        @author Vaceslav Ustinov
        @return true falls Punkt und hit die gleiche Position haben, false falls nicht
        */
        virtual bool isHit( const C2dVector& hit );
        /**
        Funktion uberprüft ob der Punkt in angegebenen Rechteck "rect" liegt
        @param rect Ausgewählte Rechteck
        @author Vaceslav Ustinov
        */
        virtual bool isHit( const QRectF& rect );
        /**
        Setzt die Position von dem Punkt fest
        @param theValue neue Position
        @author Vaceslav Ustinov
        */
        void setPos( const C2dVector& theValue );
        /**
        Gibt die aktuelle Position zurück
        @return C2dVector aktuelle Position
        @author Vaceslav Ustinov
        */
        const C2dVector& getPos() const;
        /**
        Gibt alle Linien, die zu diesem Punkt gehören, zurück
        @return QVector<BB_Line*> Ein Vector mit Linien (BB_Line)
        @author Vaceslav Ustinov
        */
        QVector<BB_Line*>* getLines();
        /**
        Gibt die Name von Klasse zurück
        @return QString Name
        @author Vaceslav Ustinov
        */
        virtual const QString getClassName();
        /**
        setzt die position auf X-Achse fest
        @param value Neue X-Position
        @author Vaceslav Ustinov
        */
        void setX( double value );
        /**
        setzt die position auf Y-Achse fest
        @param value Neue Y-Position
        @author Vaceslav Ustinov
        */
        void setY( double value );
        /**
        Gibt die X-position zurück
        @return double X-Position
        @author Vaceslav Ustinov
        */
        double getX()
        {
            return m_Pos.x();
        };
        /**
        Gibt die Y-position zurück
        @return double Y-Position
        @author Vaceslav Ustinov
        */
        double getY()
        {
            return m_Pos.y();
        };
        /**
         * Schreibt das XML-Element des Punktes in den angegeben Stream. 
         * @param out Stream, in welchen geschrieben werden soll. 
         * @param depth Einrückung. 
         * @author Vaceslav Ustinov
        */
        virtual void generateXElement( QTextStream &out, int depth );
        /**
        Gibt das ItemModel des Punktes zurück
        @return QStandardItemModel
        @see QT::QStandardItemModel
        @author Vaceslav Ustinov
        */
        QStandardItemModel * getItemModel();
        /**
        Setzt die Skalierung von dem Punkt fest
        @param theValue Skalierung
        @author Vaceslav Ustinov
        */
        void setScale( double theValue )
        {
            m_scale = theValue;
        }

        /**
        Löscht vollständig ein Objekt aus dem Vektor.
        @date 14.11.2005
		@param object * zu löschende Objekt
        @return void
        @author Vaceslav Ustinov
        */
        void deleteLinkedObject( BB_DrawObject * object );
        /**
        Entfernt ein Objekt aus dem Vektor.<br>
        Instantz wird nicht gelöscht
        @author Vaceslav Ustinov
        @date 14.11.2005
		@param object * zu löschende Objekt
        @return BB_DrawObject wenn Ein Objekt aus dem Vektor entwernt wurde, wird ein Link auf diesen Objekt
        zurückgegeben. Wenn es nicht gelöscht wurde, wird ein Null - Pointer zurückgegeben.
        */
        void removeLinkedObject( BB_DrawObject * object );
        /**
        Entfernt ein Objekt aus dem Vektor.<br>
        Instantz wird auch gelöscht
        @author Vaceslav Ustinov
        @date 14.11.2005
        @return void
        */
        void deleteLinkedObjects( QVector< BB_DrawObject * >* objects );
        /**
        Fügt ein neues Objekt in Vector zu
		@param newObject Objekt, das hinzugefügt werden soll
        @author Vaceslav Ustinov
        */
        void BB_Point::addObject( BB_DrawObject * newObject );
        /**
        * Erzeugt von BB_Point ein QT-QPoint
        * @return QPoint
        * @date 20.12.2005
        * @author Vaceslav Ustinov
        */
        QPoint getQPoint();
        /**
        Richtet den Punkt mit angegebenen Punkt horizontal aus
		@param point Punkt zum Vergleichen
        @author Vaceslav Ustinov
        */
        void bringToLineHorizontal( BB_Point *point );
        /**
        Richtet den Punkt mit angegebenen Punkt vertikal aus
		@param point Punkt zum Vergleichen
        @author Vaceslav Ustinov
        */
        void bringToLineVertikal( BB_Point *point );
        /**
        Ein Erreignis, das aufgerufen wird, wenn das Objekt durch abhängige Objekte bewegt wird.
        @author Vaceslav Ustinov
        */
        virtual void moveEvent();

    private:
        /**
        Radius von dem Punkt
        */
        double m_Radius;
        /**
        Skalierung
        */
        double m_scale;
    protected:
        /**
        Position von dem Punkt
        @author Vaceslav Ustinov
        */
        C2dVector m_Pos;
        /**
        QVector mit allen Objekten, die zu diesem Punkt gehoeren.<br>
        z.B. BB_Line oder BB_Tiangle
        @author Vaceslav Ustinov
        @date 14.11.2005
        */
        QVector<BB_DrawObject*> m_Links;
};

#endif
