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
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_TerrainTriangle : public BB_Triangle
{
public:
    BB_TerrainTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3);

    ~BB_TerrainTriangle();

    virtual void createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height);
    virtual const QString getClassName();

};

#endif
