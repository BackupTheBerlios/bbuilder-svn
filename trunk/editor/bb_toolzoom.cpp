/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
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
***************************************************************************/
#include "bb_toolzoom.h"

#include <iostream>

using namespace std;

BB_ToolZoom::BB_ToolZoom( BB_WorkArea* area )
        : BB_AbstractTool()
{
    if ( area == NULL )
    {
        qDebug( "BB_ToolZoom: Fehler beim setzen der WorkArea.\nNull-Pointer erhalten" );
        exit( 1 );
    }

    m_WorkArea = area;
    m_ToolWidget = new BB_WidgetToolZoom();
}


BB_ToolZoom::~BB_ToolZoom()
{}


void BB_ToolZoom::click( QMouseEvent* me )
{
    if ( me->button() == Qt::LeftButton )
    {
        m_WorkArea->zoom( 1.25 );
    }
    else if ( me->button() == Qt::RightButton )
    {
        m_WorkArea->zoom( 0.75 );
    }
    else if ( me->button() == Qt::MidButton )
    {
        m_WorkArea->setZoomFaktor( 1.0 );
    }

	( ( BB_WidgetToolZoom* ) ( m_ToolWidget ) ) -> setZoomFaktor( m_Component->getZoom() );
}

void BB_ToolZoom::move( QMouseEvent* me, bool overX, bool overY )
{
    if ( overX || overY )
    {
        me->ignore();
    }
}

void BB_ToolZoom::release( QMouseEvent* me )
{
    me->ignore();
}



/*!
    \fn BB_ToolZoom::setDocComponent( BB_DocComponent* component )
 */
void BB_ToolZoom::setDocComponent( BB_DocComponent* component )
{
	BB_AbstractTool::setDocComponent( component );
	
	if( m_Component != NULL )
	{
		( ( BB_WidgetToolZoom* ) ( m_ToolWidget ) ) -> setZoomFaktor( m_Component->getZoom() );
	}
}
