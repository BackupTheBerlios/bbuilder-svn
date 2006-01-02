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
#include "bb_window.h"
#include "bb_point.h"
#include "bb_globals.h"

#include <iostream>

using namespace std;

BB_Window::BB_Window()
        : BB_ConstructionElement()
{
    setPos1( new BB_Point( QPoint( 0, 0 ) ) );
    setPos2( new BB_Point( QPoint( 50, -50 ) ) );
    setTextureFileName( IMG_DIR() + SEPARATOR() + "Fenster.jpg" );
}

BB_Window::BB_Window( C2dVector v )
        : BB_ConstructionElement()
{
    setPos1( new BB_Point( v ) );
    setPos2( new BB_Point( QPoint( v.x() + 200, v.y() - 200 ) ) );
    setTextureFileName( IMG_DIR() + SEPARATOR() + "Fenster.jpg" );
}


BB_Window::~BB_Window()
{}

void BB_Window::show( BB_Transformer& transformer, QPainter& painter ) const
{
    if ( &transformer != NULL && &painter != NULL && m_Pos1 != NULL && m_Pos2 != NULL )
    {
        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );

        QPoint dest1;
        QPoint dest2;

        transformer.logicalToScreen( dest1, m_Pos1->getPos() );
        transformer.logicalToScreen( dest2, m_Pos2->getPos() );

        QRect rect( ( int ) dest1.x(),
                    ( int ) dest1.y(),
                    ( int ) ( dest2.x() - dest1.x() ),
                    ( int ) ( dest2.y() - dest1.y() ) );
        rect = rect.normalized();
        painter.drawRect( rect );

        painter.drawImage( rect, m_Image );

        if ( m_Selected )
        {
            m_Pos1->show( transformer, painter );
            m_Pos2->show( transformer, painter );
        }
    }
}

bool BB_Window::isHit( QRect rect )
{
    if ( rect.x() > m_Pos1->getX() && rect.y() > m_Pos2->getY() )
    {
        return true;
    }
    return false;
}

