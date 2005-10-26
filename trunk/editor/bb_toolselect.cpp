//
// C++ Implementation: bb_toolselect
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolselect.h"
#include <iostream>

using namespace std;

BB_ToolSelect::BB_ToolSelect()
 : BB_AbstractTool()
{
	m_Rect.setPos1(&m_Point1);
	m_Rect.setPos2(&m_Point2);
	
	QPen pen;
	QBrush brush;
	
	pen.setStyle(Qt::DotLine);
	brush.setStyle(Qt::Dense4Pattern);
	brush.setColor(Qt::yellow);
	
	m_Rect.setPen(pen);
	m_Rect.setBrush(brush);
	
}


BB_ToolSelect::~BB_ToolSelect()
{
}




/*!
    \fn BB_ToolSelect::click(QMouseEvent* me)
 */
void BB_ToolSelect::click(QMouseEvent* me)
{
	m_Point1.setX(me->x());
	m_Point1.setY(me->y());
	
	m_Point2.setX(me->x());
	m_Point2.setY(me->y());
	
	m_Selection->append(&m_Rect);
}


/*!
    \fn BB_ToolSelect::release(QMouseEvent* me)
 */
void BB_ToolSelect::release(QMouseEvent* me)
{
	
	// TODO isHit(QRect);
	
	m_Selection->clear();
}


/*!
    \fn BB_ToolSelect::move(QMouseEvent* me)
 */
void BB_ToolSelect::move(QMouseEvent* me)
{
	m_Point2.setX(me->x());
	m_Point2.setY(me->y());	
}
