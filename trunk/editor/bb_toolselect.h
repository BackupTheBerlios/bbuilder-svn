//
// C++ Interface: bb_toolselect
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLSELECT_H
#define BB_TOOLSELECT_H

#include <bb_abstracttool.h>
#include <bb_point.h>
#include <bb_rect.h>
#include <c2dvector.h>

/**
Tool, mit dem es möglich ist mehrere Objekte auszuwählen.


@author Alex Letkemann
*/
class BB_ToolSelect : public BB_AbstractTool
{
public:
    BB_ToolSelect();

    ~BB_ToolSelect();
    virtual void click(QMouseEvent* me);
    virtual void release(QMouseEvent* me);
    virtual void move(QMouseEvent* me);

protected:
    BB_Point m_Point2;
    BB_Point m_Point1;
	BB_Rect m_Rect;
    C2dVector m_ClickPos;
};

#endif
