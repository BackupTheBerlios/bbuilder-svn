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
#include "bb_door.h"
#include "bb_dlgopentexture.h"
#include "bb_globals.h"

#include <iostream>

using namespace std;

BB_Wall::BB_Wall( BB_Point* p1, BB_Point* p2 ) : BB_Line( p1, p2 )
{
    m_ShowDirection = true;

    m_Pen.setColor( m_Color );
    m_Pen.setWidth( 3 );

    m_Brush.setColor( m_Color );

    m_PenDirection.setWidth( 1 );
    m_PenDirection.setColor( m_Color );

    moveEvent();

    m_Objects = new QVector <BB_DrawObject *>;

// 	setTextureFile(IMG_DIR() + SEPARATOR() +"brick.jpg");
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
    if ( m_Selected )
    {
        painter.setPen( m_PenSelected );
    }
    else
    {
        painter.setPen( m_Pen );
    }
    painter.setBrush( m_Brush );

    QPoint dest_Pos1, dest_Pos2, dest_Middle;

    transformer.logicalToScreen( dest_Pos1, m_Pos1->getPos() );
    transformer.logicalToScreen( dest_Pos2, m_Pos2->getPos() );
    transformer.logicalToScreen( dest_Middle, m_Middle );



    painter.drawLine( dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y() );

    // 	cout 	<< "P1: " << m_Pos1->getPos().x() << "|" << m_Pos1->getPos().y() << " - "
    // 			<< "P2: " << m_Pos2->getPos().x() << "|" << m_Pos2->getPos().y() << " - "
    // 			<< "M:" << m_Middle.x() << "|" << m_Middle.y() << endl;

    ///@todo Test löschen
    // NUR TEST
    painter.drawText( dest_Middle.x() , dest_Middle.y() , getName() );


    if ( m_ShowDirection )
    {
        showDirection( transformer, painter, dest_Middle );
    }
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
        if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Window ) || typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Door ) )
        {
            tmpObject = ( BB_Rect * ) m_Objects->at( i );
            vectorMitpoints->append( tmpObject->getPos1() );
            vectorMitpoints->append( tmpObject->getPos2() );
        }
    }
    return vectorMitpoints;
}


void BB_Wall::setObjects( QVector< BB_DrawObject * >* Value )
{
    m_Objects = Value;
}

/**
 * Markiert die 'Richtung' der Wand. 
 * Die Seite der Wand, die Später angezeigt werden soll wird markiert.
 * @param transformer Transformer, mit dessen Einstellungen gezeichnet wird.
 * @param painter Painter, mit welchem gezeichnet wird.
 * @param middle Ein bereits mit dem Transformer konvertierter Mittelpunkt der Linie
 * @author Alex Letkemann
 */
void BB_Wall::showDirection( BB_Transformer& transformer, QPainter& painter, QPoint& middle ) const
{
    QPoint dest_Direction;


    transformer.logicalToScreen( dest_Direction, m_Direction );
    painter.setPen( m_PenDirection );
    painter.drawLine( middle, dest_Direction );

}


/**
 * Berechnet die 'Richtung' der Wand
 */
void BB_Wall::calculateDirection()
{

    m_Direction = ( m_Pos2->getPos() - m_Pos1->getPos() );
    // Länge der Markierunglinie auf 10 setzen.
    m_Direction = m_Direction.unitVector() * 10.0;
    m_Direction = m_Direction.rotate( 90.0 );
    m_Direction = m_Direction + m_Middle;
}


/*!
    \fn BB_Line::moveEvent()
 */
void BB_Wall::moveEvent()
{
    BB_Line::moveEvent();
    calculateDirection();

}


/*!
    \fn BB_Wall::swap()
 */
void BB_Wall::swap()
{
    BB_Point * tmp;

    tmp = m_Pos1;
    m_Pos1 = m_Pos2;
    m_Pos2 = tmp;

    calculateDirection();
}

QVector< BB_DrawObject * >* BB_Wall::getObjectsWithPoints() const
{
    QVector< BB_DrawObject * >* points = getPoints();;
    ///@todo zeiger muss geloescht werden, wie!!!!
    QVector< BB_DrawObject * >* objectsWithPoints = new QVector< BB_DrawObject * >;

    for ( int i = 0; i < m_Objects->count() ;i++ )
    {
        objectsWithPoints->append( m_Objects->at( i ) );
    }
    for ( int i = 0; i < points->count() ;i++ )
    {
        objectsWithPoints->append( points->at( i ) );
    }
    return objectsWithPoints;
}

void BB_Wall::openTextureDlg()
{
	BB_DlgOpenTexture dlg;
	dlg.setTextureFile( m_TextureFile);
	dlg.exec();
	m_TextureFile = dlg.getTextureFile();
}


QString BB_Wall::getTextureFile() const
{
    return m_TextureFile;
}


void BB_Wall::setTextureFile( const QString& Value )
{
    m_TextureFile = Value;
}
