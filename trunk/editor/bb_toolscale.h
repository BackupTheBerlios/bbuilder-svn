//
// C++ Interface: bb_toolscale
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLSCALE_H
#define BB_TOOLSCALE_H

#include <bb_abstracttool.h>
#include <QWidget> 

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolScale : public BB_AbstractTool
{
public:
    BB_ToolScale(QWidget* parent = 0);

    ~BB_ToolScale();

    virtual void click(QMouseEvent* me);
    virtual void move(QMouseEvent* me, bool overX, bool overY);
    virtual void release(QMouseEvent* me);
    virtual void setDocComponent( BB_DocComponent* component );

protected:
    BB_Point* m_MovePoint;
    BB_Line* m_ScaleLine;
	
	QWidget* m_Parent;
};

#endif
