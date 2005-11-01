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
#include "c2dvector.h"
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
	if(me->button() == Qt::LeftButton)
	{
		clearSelection();
		
		m_pScreen = me->pos();
		m_Transformer->screenToLogical(m_pLogic,m_pScreen);
		m_ClickPos = m_pLogic;
		
		m_Point1.setX(me->x());
		m_Point1.setY(me->y());
		
		m_Point2.setX(me->x());
		m_Point2.setY(me->y());
		
		m_ToolObjects->append(&m_Rect);
	}
	else if(me->button() == Qt::RightButton)
	{
		clearSelection();
	}
}


/*!
    \fn BB_ToolSelect::release(QMouseEvent* me)
 */
void BB_ToolSelect::release(QMouseEvent* me)
{
	
	if(me->button() == Qt::LeftButton)
	{
		BB_DrawObject* object;
		
		m_pScreen = me->pos();
		m_Transformer->screenToLogical(m_pLogic,m_pScreen);
		
		if(m_ClickPos == m_pLogic)
		{		
			for(int i = 0; i < m_Objects->count(); i++)
			{
				object = m_Objects->at(i);
				if(object->isHit(m_pLogic))
				{
					object->setSelected(true);
					m_Selection->append(object);
					cout << "(" << object << ")hinzugefügt" << endl;
					break;
				}
			}
		}
		else
		{
			
			
			QRect rect(	(int) m_ClickPos.x(),
						(int) m_ClickPos.y(),
						(int) (m_pLogic.x() - m_ClickPos.x()),
						//(int) (m_ClickPos.y() - m_pLogic.y()));
						(int) (m_pLogic.y() - m_ClickPos.y()));
						
// 			cout << "rect: x=" << rect.x() << " y=" << rect.y() << " w=" << rect.width() << " h=" << rect.height() << endl;
			
			for(int i = 0; i < m_Objects->count(); i++)
			{
				object = m_Objects->at(i);
				if(object->isHit(rect))
				{
					object->setSelected(true);
					m_Selection->append(object);
					cout << "(" << object << ")hinzugefügt" << endl;
				}
			}
		}
		
		m_ToolObjects->clear();
		cout << "Objects selected: " << m_Selection->count() << endl;
	}
}



/**
 * Setzt die neue Position des zweite Punktes des Auswahlrechtecks,
 * wenn die Maus mit gedrückter Taste bewegt wird.
 * @param me Mausevent
 * @param overX Unbenutzt
 * @param overY Unbenutzt
 */
void BB_ToolSelect::move(QMouseEvent* me, bool overX, bool overY)
{
// 	cout << "move: " << me->buttons() << " - " << Qt::LeftButton << endl;
	if(me->buttons() == Qt::LeftButton)
	{
		m_Point2.setX(me->x());
		m_Point2.setY(me->y());	
		
	}
}
