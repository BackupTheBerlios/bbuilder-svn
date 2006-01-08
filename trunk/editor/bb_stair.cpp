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
#include "bb_stair.h"
#include "bb_point.h"

BB_Stair::BB_Stair()
        : BB_Rect()
{
    m_Pen.setColor( Qt::black );
	m_Brush.setColor( Qt::transparent );
	m_PenSelected.setColor(Qt::black);
}


BB_Stair::~BB_Stair()
{}


void BB_Stair::show( BB_Transformer& transformer, QPainter& painter ) const
{
	if ( m_Selected )
	{
		painter.setPen( m_PenSelected );
	}
	else
	{
		painter.setPen( m_Pen );
	}
    // 	painter.setPen( m_Pen );
    	painter.setBrush( m_Brush );
//     QBrush brush;
//     brush.setColor( Qt::blue );
//     painter.setBrush( m_Brush );
//     QPen pen;
//     pen.setColor( Qt::black );
//     painter.setPen( m_Pen );

    QPoint dest1;
    QPoint dest2;

    transformer.logicalToScreen( dest1, m_Pos1->getPos() );
    transformer.logicalToScreen( dest2, m_Pos2->getPos() );

    QRect rect( dest1.x(),
                dest1.y(),
                ( dest2.x() - dest1.x() ),
                ( dest2.y() - dest1.y() ) );
    rect = rect.normalized();
    painter.drawRect( rect );

    int abstand = rect.height() / 10;
    for ( int i = 1;i <= 10 ;i++ )
    {
        painter.drawLine( rect.left(), rect.top() + abstand * i, rect.right(), rect.top() + abstand * i );
    }

    ///@todo Test löschen
    // NUR TEST
    painter.drawText( dest1.x() , dest1.y() , getName() );

}

void BB_Stair::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_stair id=\"" << getObjectNr()
    << "\" p1=\"" << getPos1() ->getObjectNr()
    << "\" p2=\"" << getPos2() ->getObjectNr() << "\">\n";
    BB_Object::generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</bb_stair>\n";
}

bool BB_Stair::isHit( const C2dVector& hit ){
	return false;
}

