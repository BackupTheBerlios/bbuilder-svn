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
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_BuildingTriangle : public BB_Triangle
{
public:
    BB_BuildingTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3);

    ~BB_BuildingTriangle();

    virtual const QString getClassName();
    virtual void createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height);

};

#endif
