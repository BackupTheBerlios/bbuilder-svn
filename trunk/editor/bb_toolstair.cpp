/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                      *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "bb_toolstair.h"

BB_ToolStair::BB_ToolStair( QWidget* parent ) : BB_AbstractTool( parent )
{
    m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolWindow.png" );
    m_Rect.setPos1( &m_Point1 );
    m_Rect.setPos2( &m_Point2 );

    QPen pen;
    QColor p( 255, 221, 118, 210 );
    pen.setBrush( p );

    m_Rect.setPen( pen );

    QColor b( 255, 221, 118, 150 );
    m_Rect.setBrush( b );

// 	m_Stair = new BB_Stair();
}


BB_ToolStair::~BB_ToolStair()
{}


void BB_ToolStair::click( QMouseEvent* me )
{
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL | me == NULL | m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        return ;
    }
    //Behandlung von linke Maustaste
    if ( me->button() == Qt::LeftButton )
    {
        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );
        m_LastLogicMouseClick = m_pLogic;

        //beim ersten click markieren und verschiebne
		BB_Point * point = ( BB_Point* ) getClickedObject( m_pLogic, typeid( BB_Point ) );
        if ( point == NULL )
        {
            return ;
        }
		m_Stair = new BB_Stair();
		m_Stair->setPos1( point);
		
        //clearSelection();
        m_ClickPos = m_pLogic;

        m_Point1.setX( me->x() );
        m_Point1.setY( me->y() );

        m_Point2.setX( me->x() );
        m_Point2.setY( me->y() );

        if ( m_ToolObjects != NULL )
        {
            m_ToolObjects->append( &m_Rect );
        }
    }
}

void BB_ToolStair::move( QMouseEvent* me, bool overX, bool overY )
{
    //Behandlung von Linke-maustaste
    if ( me->buttons() == Qt::LeftButton )
    {
        //wenn Slected-mode ausgewaehlt, dann einfach viereck weiter schieben
        m_Point2.setX( me->x() );
        m_Point2.setY( me->y() );
    }
}

void BB_ToolStair::release( QMouseEvent* me )
{
	//alle Objekte desektieren
	if ( m_ToolObjects != NULL )
	{
		m_ToolObjects->clear();
	}
    //wenn die noetigen objekte nicht da sind, sofort abbrechen
    if ( m_Objects == NULL | me == NULL | m_Transformer == NULL )
    {
        qDebug( "BB_ToolMove::click()->Nicht alle objecte sind da!!!! m_Objects: %p \tme: %p\tm_Transformer: %p", m_Objects, me, m_Transformer );
        m_ToolWidget->updateWidget();
        return ;
    }
    //Behandlung nur von Linke-Maustaste
    if ( me->button() == Qt::LeftButton )
    {

		m_pScreen = me->pos();
		m_Transformer->screenToLogical( m_pLogic, m_pScreen );
		m_LastLogicMouseClick = m_pLogic;

        //beim ersten click markieren und verschiebne
		BB_Point * point = ( BB_Point * ) getClickedObject( m_pLogic, typeid( BB_Point ) );
		if ( point == NULL )
		{
			return ;
			delete m_Stair;
		}
		m_Stair->setPos2( point);
		m_Objects->append(m_Stair);
		m_Stair = NULL;
    }
    updateWidget();
}

BB_AbstractToolWidget* BB_ToolStair::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_AbstractToolWidget( this );
    }
    return m_ToolWidget;
}


