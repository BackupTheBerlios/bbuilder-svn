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

BB_Window::BB_Window( C2dVector v1, C2dVector v2)
        : BB_ConstructionElement(v1, v2)
{;
}


BB_Window::~BB_Window()
{}

// void BB_Window::show( BB_Transformer& transformer, QPainter& painter ) const
// {
//     if ( &transformer != NULL && &painter != NULL && m_Pos1 != NULL && m_Pos2 != NULL )
//     {
//         painter.setPen( m_Pen );
//         painter.setBrush( m_Brush );
// 
//         QPoint dest1;
//         QPoint dest2;
// 
//         transformer.logicalToScreen( dest1, m_Pos1->getPos() );
//         transformer.logicalToScreen( dest2, m_Pos2->getPos() );
// 
//         QRect rect( dest1.x(),
//                     dest1.y(),
//                     ( dest2.x() - dest1.x() ),
//                     ( dest2.y() - dest1.y() ) );
//         rect = rect.normalized();
//         painter.drawRect( rect );
// 
//         painter.drawImage( rect, m_Image );
// 
//         if ( m_Selected )
//         {
// 	    double r1 = m_Pos1->getRadius();
// 	    double r2 = m_Pos2->getRadius();
// 		m_Pos1->setRadius(7.0);
// 		m_Pos2->setRadius(7.0);
//             m_Pos1->show( transformer, painter );
//             m_Pos2->show( transformer, painter );
// 		m_Pos1->setRadius(r1);
// 		m_Pos2->setRadius(r2);
//         }
//     }
// }

// bool BB_Window::isHit( QRect rect )
// {
//     if ( rect.x() > m_Pos1->getX() && rect.y() > m_Pos2->getY() )
//     {
// 		qDebug("BB_Window::isHit = true");
//         return true;
//     }
//     return false;
// }

void BB_Window::generateXElement( QTextStream &out, int depth )
{
    QFileInfo myFile( getTextureFileName() );
    out << BB::indent( depth + 1 ) << "<bb_window id=\"" << getObjectNr() << "\""
	<< " x1=\"" << getPos1() ->getX()
	<< "\" y1=\"" << getPos1() ->getY()
	<< "\" px1=\"" << (int)getWallPosition1().x()
	<< "\" py1=\"" << (int)getWallPosition1().y()
	<< "\" cx1=\"" << getCoefficientPos1().x()
	<< "\" cy1=\"" << getCoefficientPos1().y()
	<< "\" x2=\"" << getPos2() ->getX()
	<< "\" y2=\"" << getPos2() ->getY()
	<< "\" px2=\"" << (int)getWallPosition2().x()
	<< "\" py2=\"" << (int)getWallPosition2().y()
	<< "\" cx2=\"" << getCoefficientPos2().x()
	<< "\" cy2=\"" << getCoefficientPos2().y() << "\">\n"
    << BB::indent( depth + 2 ) << "<texture file=\"" << myFile.fileName() << "\"/>\n"
    << BB::indent( depth + 1 ) << "</bb_window>\n";
}

