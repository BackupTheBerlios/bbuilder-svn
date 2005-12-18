//
// C++ Implementation: bb_toolscale
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolscale.h"
#include "bb_line.h"
#include <bb_dlgtoolscaleedit.h>

#include <iostream>

using namespace std;

BB_ToolScale::BB_ToolScale( QWidget * parent )
        : BB_AbstractTool()
{
	m_Parent = parent;
    m_MovePoint = NULL;
}


BB_ToolScale::~BB_ToolScale()
{}


void BB_ToolScale::click( QMouseEvent* me )
{
	
	if ( me != NULL && me->buttons() == Qt::LeftButton )
    {
        m_Transformer->screenToLogical( m_pLogic, me->pos() );
		
		if( m_Component->getScalePoint_1()->isHit( m_pLogic ) )
		{
			m_MovePoint = m_Component->getScalePoint_1();
		}
		else if(m_Component->getScalePoint_2()->isHit( m_pLogic ) )
		{
			m_MovePoint = m_Component->getScalePoint_2();
		}
		else if(m_ScaleLine != NULL && m_ScaleLine->isHit( m_pLogic ) )
		{
			
			C2dVector v1,v2;
			
			v1 = m_Component->getScalePoint_2()->getPos();
			v2 = m_Component->getScalePoint_1()->getPos();
			double logicScale = (v2 - v1).getLength();
			
			BB_DlgToolScaleEdit dlg( m_Parent );
			
			dlg.setScaleLogic( logicScale );
			dlg.setScaleReal( m_Component->getScaleReal() );
			
			if( dlg.exec() == QDialog::Accepted )
			{
				m_Component->setScaleReal( dlg.getScaleReal() );
			}
		}
		
    }

}

void BB_ToolScale::move( QMouseEvent* me, bool overX, bool overY )
{
    if ( me != NULL && m_MovePoint != NULL && !overX && !overY )
    {
        m_Transformer->screenToLogical( m_pLogic, me->pos() );
		m_MovePoint->setPos( m_pLogic );
    }
}

void BB_ToolScale::release( QMouseEvent* me )
{
    m_MovePoint = NULL;
    me->ignore();
}



/*!
    \fn BB_ToolScale::setDocComponent( BB_DocComponent* component )
 */
void BB_ToolScale::setDocComponent( BB_DocComponent* component )
{
	BB_AbstractTool::setDocComponent( component );
	
	if( m_Component != NULL )
	{
		if( m_ScaleLine == NULL)
		{
			m_ScaleLine = new BB_Line( m_Component->getScalePoint_1(), m_Component->getScalePoint_2() );
		}
		else
		{
			m_ScaleLine->setPos1( m_Component->getScalePoint_1() );
			m_ScaleLine->setPos2( m_Component->getScalePoint_2() );
		}
		
		m_ToolObjects->clear();
		
		m_ToolObjects->append( m_Component->getScalePoint_1() );
		m_ToolObjects->append( m_Component->getScalePoint_2() );
		m_ToolObjects->append( m_ScaleLine );
	}
	else
	{
		m_ToolObjects->clear();
		delete m_ScaleLine;
	}
}
