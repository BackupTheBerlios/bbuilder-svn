//
// C++ Interface: bb_terraintriangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TERRAINTRIANGLE_H
#define BB_TERRAINTRIANGLE_H

#include <bb_triangle.h>

/**
 * Stellt eine Geländefläche in Form eines Freiecks dar, die durch drei Gelände-Punte beschrieben wird.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_TerrainTriangle : public BB_Triangle
{
public:
    /**
     * Erstellt einen Dreieck aus den drei übergebenen Punkten
	 * @author Alex Letkemann
     */
    BB_TerrainTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3);

	/**
	 * Destruktor
	 */
    ~BB_TerrainTriangle();

    /**
     * Erstellt einen 3D-Dreieck und hängt diesen an den übergebenen Vektor 'triangles' an.
     * @param triangles Vektor mit 3D Dreiecken
     * @param vector Position des Dreiecks
     * @param rotation Rotation des Dreiecks
     * @param scale Maßstab des Dreiecks
     * @param height Hier keine Funktion
     */
    virtual void createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height);
	
    /**
     * \fn BB_OBject::getClassName()
     */
    virtual const QString getClassName();

};

#endif
