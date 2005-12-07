//
// C++ Interface: bb_tooltrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTRIANGLENEW_H
#define BB_TOOLTRIANGLENEW_H

#include <bb_abstracttool.h>
#include <bb_triangle.h>

/**
Tool zum Erzeugen von Triangles

@author Alex Letkemann
*/
class BB_ToolTriangleNew : public BB_AbstractTool
{
public:
    BB_ToolTriangleNew();

    ~BB_ToolTriangleNew();
	
	virtual void move(QMouseEvent* me, bool overX, bool overY);
	virtual void release(QMouseEvent* me);
	virtual void click(QMouseEvent* me);
    virtual void reset();

protected:
    BB_Triangle* m_Triangle;
};

#endif