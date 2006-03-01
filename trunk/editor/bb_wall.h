/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                             *
*   v.ustinov@web.de                                                                                           *
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
#ifndef BB_WALL_H
#define BB_WALL_H

#include "bb_line.h"
#include "bb_doccomponent.h"
#include "bb_door.h"

#include <QPixmap>

/**
Dieses Klass representiert eine Wand.
@see BB_Line
@author Vaceslav Ustinov
*/
class BB_Wall : public BB_Line
{
    public:
        /**
        Standart Konstruktor mit zwei Punkte als Parametern
        @param BB_Point p1 Position 1
        @param BB_Point p2 Position 2
        @author Vaceslav Ustinov
        */
        BB_Wall( BB_Point* p1, BB_Point* p2 );
        /**
        Dekonstruktor
        @author Vaceslav Ustinov
        */
        ~BB_Wall();
        /**
        Gibt die Name von Klasse zurück
        @return QString Name
        @author Vaceslav Ustinov
        */
        virtual const QString getClassName();
        /**
         * Schreibt das XML-Element von der Wand in den angegeben Stream. 
         * @param out Stream, in welchen geschrieben werden soll. 
         * @param depth Einrückung. 
         * @author Vaceslav Ustinov
        */
        virtual void generateXElement( QTextStream &out, int depth );
        /**
        Funktion zum Zeichnen.
        @param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
        @param QPainter Werkzeug zum Zeichnen @see QT::QPainter
        @author Vaceslav Ustinov
        */
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
        /**
        Funktion startet ein Dialog zum Editieren von Wand-Eigenschften
        @param BB_DocComponent Link auf eine Etage
        @author Vaceslav Ustinov
        */
        void editDlg( BB_DocComponent * docComponent );
        /**
        Ein Erreignis, das aufgerufen wird, wenn das Objekt durch abhängige Objekte bewegt wird.
        @author Vaceslav Ustinov
        */
        virtual void moveEvent();
        /**
        Setzt ein Vector mit Objekten fest.
        Die Objekte sin BB_Window oder BB_Door
        @param QVector< BB_DrawObject * > * Zeiger auf ein Vector mit Objekten
        @author Vaceslav Ustinov
        */
        void setObjects( QVector< BB_DrawObject * >* Value );
        /**
        Gibt den Vector mit Objekten, die zu dieser Wand gehoeren, zurück.
        z.B. Fenster und Türen
        @return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
        @author Vaceslav Ustinov
        */
        QVector< BB_DrawObject * >* getObjects() const;
        /**
        Gibt den Vector mit Objekten, die zu dieser Wand gehoeren, zurück.<br>
        Hier gehören auch die Positions-Punkte von einzelnen Objekten dazu<br>
        z.B. Fenster und Türen, Position von Fenster, Position von Tür
        @return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
        @author Vaceslav Ustinov
        */
        QVector< BB_DrawObject * >* getObjectsWithPoints() const;
        /**
        Gibt den Vector mit Positions-Punkten von Objekten, die zu dieser Wand gehoeren, zurück.
        z.B. Position von Fenster und Position von Tür
        @return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
        @author Vaceslav Ustinov
        */
        QVector< BB_DrawObject * >* getPoints() const;
        /**
        Diese Funktion öffnet ein kleines Dialog.<br>
        In diesem Dialog kann man dann die Textur fuer die Wand auswählen.
        @author Vaceslav Ustinov
        */
        void openTextureDlg();
        /**
        Ändert die Richtung von der Wand
        @author Vaceslav Ustinov
        */
        virtual void swap();
        /**
        Gibt die erste im Vector stehende Tür zurück<br>
        Falls es uberhaupt keine Türen gibts, wird ein NULL-Pointer zurückgegeben,
        @return BB_Door
        @author Vaceslav Ustinov
        */
        BB_Door * hastDoor();
    private:
        /**
         * Markiert die 'Richtung' der Wand. 
         * Die Seite der Wand, die Später angezeigt werden soll wird markiert.
         * @param transformer Transformer, mit dessen Einstellungen gezeichnet wird.
         * @param painter Painter, mit welchem gezeichnet wird.
         * @param middle Ein bereits mit dem Transformer konvertierter Mittelpunkt der Linie
         * @author Alex Letkemann
         */
        virtual void showDirection( BB_Transformer& transformer, QPainter& painter, QPoint& middle ) const;
        /**
         * Berechnet die Mitte der Linie und speichert diese im m_Middle Vektor.
         * @author Alex Letkemann
         */
        void calculateDirection();
        /**
         * Erzeugt die Dreiecke für das Dach und den Grund des Gebäudes.<br>
         * Die Erzeugten Dreiecke werden an den übergebenen Vektor 'triangles' angehängt.
         * @param triangles Vektor, an den die Dreiecke angehängt werden.
         * @param vector Positionsektor
         * @param rotation Rotation der Dreiecke
         * @param scale Skalierung der Dreiecke
         * @param height Hier keine Funktion
         * @author Alex Letkemann
         */
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );

    protected:
        /** Richtung, in die die Wang steht */
        C2dVector m_Direction;
        /** Ob die Richtung mitgezeigt werden soll */
        bool m_ShowDirection;
        /**  QPen Klasse für m_Direction @see QT::QPen*/
        QPen m_PenDirection;
        /** Vector mit Objekten, z.B. Fenster, Türe */
        QVector <BB_DrawObject *> * m_Objects;
        /** Hohe in meter*/
        double m_Hight;
};

#endif
