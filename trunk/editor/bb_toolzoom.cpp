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

/**
 * Konstruktor. Erzeugt ein neues Zoomwerkzeug für die angegebene Arbeitsfläche. 
 * @param area Arbeitsfläche, mit der geareitet Wird.
 * @param paret Parent-Fenster
 * @author Alex Letkemann
 */
BB_ToolZoom::BB_ToolZoom( BB_WorkArea* area, QWidget* parent )
        : BB_AbstractTool( parent )
{
    if ( area == NULL )
    {
        qDebug( "BB_ToolZoom: Fehler beim setzen der WorkArea.\nNull-Pointer erhalten" );
        exit( 1 );
    }

    m_WorkArea = area;
    m_Icon = QIcon ( IMG_DIR() + SEPARATOR() + "toolZoom.png" );
}

/**
 * Destruktor
 */
BB_ToolZoom::~BB_ToolZoom()
{}

/**
 * Mit der linken Maustaste wird die Arbeitsfläche um 25% vergrößert.
 * Die mittlere Maustaste setzt die Arbeitsfläche zurück auf die Originalgröße.
 * Mir der rechten Maustaste wird die Arbeitsfläche um 25% verkleinert.
 */
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


/**
 * @fn BB_AbstractTool::setDocComponent( BB_DocComponent* component )
 * Setzt zusätzlich den Zoomfaktor der Arbeitsfläche.
 * @author Alex Letkemann
 */
void BB_ToolZoom::setDocComponent( BB_DocComponent* component )
{
    BB_AbstractTool::setDocComponent( component );

    if ( m_Component != NULL && m_ToolWidget != NULL )
    {
        ( ( BB_WidgetToolZoom* ) ( m_ToolWidget ) ) -> setZoomFaktor( m_Component->getZoom() );
    }
}


/**
 * @fn BB_AbstractTool::getToolWidget() 
 */
BB_AbstractToolWidget* BB_ToolZoom::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolZoom( this );
    }
    return m_ToolWidget;
}
