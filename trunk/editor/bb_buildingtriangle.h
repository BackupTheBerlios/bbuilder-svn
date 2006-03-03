//
// C++ Interface: bb_buildingtriangle
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_BUILDINGTRIANGLE_H
#define BB_BUILDINGTRIANGLE_H

#include <bb_triangle.h>

/**
 * Dreick, der das Dach und den Grund bei einem Gebäude Markiert
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_BuildingTriangle : public BB_Triangle
{
    public:
        /**
        * Konstrucktor.<br>
        * Erszeugt ein neues Dreieck aus drei übergebenen Punkten
        * @author Alex Letkemann
        */
        BB_BuildingTriangle( BB_Point* p1, BB_Point* p2, BB_Point* p3 );

        /**
        * Destruktor
        * @author Alex Letkemann
        */
        ~BB_BuildingTriangle();

        /**
		 * Gibt den Klassennamen zurück
		 * @return Klassenname
		 */
        virtual const QString getClassName();

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
        virtual void createGl( QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height );

};

#endif
