/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   V.Ustinov@web.de                                                      *
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
#include "bb_wall.h"

#include "bb_point.h"
#include "bb_dlgwalledit.h"
#include "bb_window.h"

BB_Wall::BB_Wall( BB_Point* p1, BB_Point* p2 ) : BB_Line( p1, p2 )
{
    m_Objects = new QVector <BB_DrawObject *>;
    // 	m_Objects->resize(100);
}


BB_Wall::~BB_Wall()
{}



/*!
    \fn BB_Wall::getClassName()
 */
const QString BB_Wall::getClassName()
{
    return QString( "BB_Wall" );
}


/*!
    \fn BB_Wall::generateXElement(QTextStream &out, int depth)
 */
void BB_Wall::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_wall id=\"" << getObjectNr()
    << "\" p1=\"" << getPos1() ->getObjectNr()
    << "\" p2=\"" << getPos2() ->getObjectNr() << "\">\n";

    BB_Object::generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</bb_wall>\n";
}

void BB_Wall::show( BB_Transformer& transformer, QPainter& painter ) const
{
    //     BB_DrawObject::show(transformer, painter);

    QPoint dest_Pos1, dest_Pos2;

    transformer.logicalToScreen( dest_Pos1, m_Pos1->getPos() );
    transformer.logicalToScreen( dest_Pos2, m_Pos2->getPos() );

    painter.setPen( m_Color );
    painter.setBrush( m_Color );
    QPen pen;
    pen.setColor( m_Color );
    pen.setWidth( 3 );
    painter.setPen( pen );
    painter.drawLine( dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y() );
}



void BB_Wall::editDlg( BB_DocComponent * docComponent )
{
    BB_DlgWallEdit EditDlg( this, docComponent );
    EditDlg.exec();
}


QVector< BB_DrawObject * >* BB_Wall::getObjects() const
{
    return m_Objects;
}

QVector< BB_DrawObject * >* BB_Wall::getPoints() const
{
    BB_Rect * tmpObject;
	QVector<BB_DrawObject * > * vectorMitpoints = new QVector<BB_DrawObject *>;
    for ( int i = 0; i < m_Objects->count(); i++ )
    {
        if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Window ) )
        {
            vectorMitpoints->append( tmpObject->getPos1() );
            vectorMitpoints->append( tmpObject->getPos2() );
        }
    }
	int test = vectorMitpoints->count();
	return vectorMitpoints;
}


void BB_Wall::setObjects( QVector< BB_DrawObject * >* Value )
{
    m_Objects = Value;
}
