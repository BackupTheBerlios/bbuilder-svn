//
// C++ Interface: bb_leveltriangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_LEVELTRIANGLE_H
#define BB_LEVELTRIANGLE_H

#include <bb_triangle.h>

/**
 * Triangle, die die Böden und Decken in einer Etage markiert.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_LevelTriangle : public BB_Triangle
{
public:
	/**
	 * Konstruktor. Erstellt ein 3D-Dreieck aus drei übergebenen Punkten. 
	 */
    BB_LevelTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3);

	/**
	 * Destruktor
	 */
    ~BB_LevelTriangle();

	/**
	 * Erzeugt zwei Dreiecke für die Decke und den Boden 
	 * @param triangles Vektor, an die neuen Dreiecke angehängt werden
	 * @param vector Positionsvektor, 
	 * @param rotation Rotation
	 * @param scale 
	 * @param height 
	 */
    virtual void createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height);
	
	/**
	 * \fn BB_Object::getClassName()
	 */
    virtual const QString getClassName();

};

#endif
