//
// C++ Interface: bb_triangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TRIANGLE_H
#define BB_TRIANGLE_H

#include <bb_point.h>
#include <bb_line.h>

/**
@author Alex Letkemann
*/
class BB_Triangle : public BB_Line
{
public:
    BB_Triangle(BB_Point* p1, BB_Point* p2, BB_Point* p3 );

    ~BB_Triangle();

    bool isHit(QRect rect);
    virtual bool isHit(C2dVector hit);
    virtual const QString getClassName();
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    void remove(BB_Point* point);

	bool setPos3(BB_Point* theValue);
	

	BB_Point* getPos3() const;
	
	
	BB_Point* m_Pos3;
};

#endif
