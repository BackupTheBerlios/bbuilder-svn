//
// C++ Implementation: bb_terraintriangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_terraintriangle.h"

BB_TerrainTriangle::BB_TerrainTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3): BB_Triangle(p1, p2, p3)
{
}


BB_TerrainTriangle::~BB_TerrainTriangle()
{
}


void BB_TerrainTriangle::createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height)
{
    BB_Triangle::createGl(triangles, vector, rotation, scale, height);
}



/*!
    \fn BB_TerrainTriangle::getClassName()
 */
const QString BB_TerrainTriangle::getClassName()
{
	return QString("BB_TerrainTriangle");
}
