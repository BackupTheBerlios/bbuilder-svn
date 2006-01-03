/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                             *
*   v.ustinov@web.de                                                                                *
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
#include "bb_line.h"
#include <iostream>
#include <math.h>
#include <bb_point.h>

using namespace std;


BB_Line::BB_Line( BB_Point *p1, BB_Point *p2 )
{
    // Edit: Alex Letkemann
    // Positionen werden durch funktionen gesetzt
    //     m_Pos1 = p1;
    //     m_Pos2 = p2;


    // Mit NULL initialisieren
    m_Pos1 = NULL;
    m_Pos2 = NULL;

	// Positionen setzen
    setPos1( p1 );
    setPos2( p2 );
	
	// Sonstige Einstellungen
	m_Pen.setColor( Qt::red );
	m_PenSelected.setColor( Qt::red );
    m_hitRange = 3;
	


}


BB_Line::~BB_Line()
{
    m_Pos1->removeLinkedObject( this );
    m_Pos2->removeLinkedObject( this );
}

bool BB_Line::isHit( const C2dVector& hit )
{
    //Richtungsvektor von Pos1 zu Pos2
    m_Richtung = m_Pos2->getPos() - m_Pos1->getPos();
    //Richtungsvektor von Pos1 zu hit (also da wo mann mit muas klickt)
    C2dVector Pos1Tohit = hit - m_Pos1->getPos();
    //wenn der Abstand von Pos1 zu hit kleiner is als
    //Abstand von Pos1 zu Pos2, dann mache weiter
    //es heist also, dass Mausposition zwieschen den beiden Punkten ist
    if ( Pos1Tohit.getLength() < m_Richtung.getLength() )
    {
        //Normierte Vektor von m_Richtung, also Laenge = 1
        //dass brauchen wir um den Abstand von von hit zu Wand zu finden
        C2dVector norm_m_Richtung = m_Richtung.getNormalVector();
        //Normierte Vektor von Pos1Tohit
        C2dVector norm_Pos1Tohit = Pos1Tohit.getNormalVector();
        //Vektor zwieschen den beiden normierten Vektoren
        C2dVector differenz = norm_Pos1Tohit - norm_m_Richtung;

        //um den Maximalen erlaubten Abstand von einem Punkt zu einer Gerade
        //zu ermitteln, braucht man auch m_hitRange zu dividieren
        double nenner = Pos1Tohit.getLength() / norm_Pos1Tohit.getLength();
        //wenn jetzt den Abstand kleiner ist als erlaubt, dann return true
        if ( ( norm_Pos1Tohit - norm_m_Richtung ).getLength() < ( m_hitRange / nenner ) )
        {

            cout << "hitline true: diff: " << differenz.getLength() << "line lenght: " << m_Richtung.getLength() << endl;
            return true;
        }
    }
    cout << "hitline false" << endl;
    return false;
}

void BB_Line::show( BB_Transformer& transformer, QPainter& painter ) const
{
    //     BB_DrawObject::show(transformer, painter);

	if( m_Selected )
	{
		painter.setPen( m_PenSelected );
	}
	else
	{
		painter.setPen( m_Pen );
	}
	
    QPoint dest_Pos1, dest_Pos2;

    transformer.logicalToScreen( dest_Pos1, m_Pos1->getPos() );
    transformer.logicalToScreen( dest_Pos2, m_Pos2->getPos() );

    painter.setBrush( m_Brush );
    painter.drawLine( dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y() );
}




BB_Point* BB_Line::getPos1() const
{
    return m_Pos1;
}


bool BB_Line::setPos1( BB_Point* Value )
{
    if ( Value != NULL && Value != m_Pos2 )
    {
        // EDIT: Alex Letkemann
        // DATE: 07.12.2005
        // Links werden bei jedem Setzten des Punktes aktualisiert.
        if ( m_Pos1 != NULL )
            m_Pos1->removeLinkedObject( this );
        m_Pos1 = Value;
        m_Pos1->addObject( this );
        
		// Mitte neu berechnen
		moveEvent();
		
		return true;
    }
    return false;
}


BB_Point* BB_Line::getPos2() const
{
    return m_Pos2;
}


bool BB_Line::setPos2( BB_Point* Value )
{
    if ( Value != NULL && Value != m_Pos1)
    {

        // EDIT: Alex Letkemann
        // DATE: 07.12.2005
        // Links werden bei jedem Setzten des Punktes aktualisiert.
        if ( m_Pos2 != NULL )
            m_Pos2->removeLinkedObject( this );
        m_Pos2 = Value;
        m_Pos2->addObject( this );
		
		// Mitte neu berechnen
		moveEvent();
		
        return true;
    }
    return false;
}


/*!
    \fn BB_Line::delete(BB_Point * point)
 */
// void BB_Line::remove( BB_Point * point )
// {
// 
//     cout << "void BB_Line::remove( " << point << " )" << endl;
//     if ( m_Pos1 == point )
//         m_Pos2->deleteLinkedObject( this );
//     else
//         m_Pos1->deleteLinkedObject( this );
// }


/*!
    \fn BB_Line::getClassName()
 */
const QString BB_Line::getClassName()
{
    return QString( "BB_Line" );
}

bool BB_Line::isHit( const QRect& rect )
{
//	EDIT: Alex Letkemann
//	Die Linie wird selektiert, wenn die linie ganz im QRect ist
//     QRect normRect = rect;
//     if ( rect.x() > ( rect.x() + rect.width() ) )
//         normRect.setX( rect.x() + rect.width() );
//     if ( rect.y() < ( rect.y() + rect.height() ) )
//         normRect.setY( rect.y() + rect.height() );
// 
//     if ( m_Pos1->getX() > normRect.x() && m_Pos1->getX() < ( normRect.x() + normRect.width() ) )
//         if ( m_Pos2->getX() > normRect.x() && m_Pos2->getX() < ( normRect.x() + normRect.width() ) )
//             if ( m_Pos1->getY() < normRect.y() && m_Pos1->getY() > ( normRect.y() - normRect.height() ) )
//                 if ( m_Pos2->getY() < normRect.y() && m_Pos2->getY() > ( normRect.y() - normRect.height() ) )
//                     return true;
//     return false;
	return m_Pos1->isHit( rect ) && m_Pos2->isHit( rect );
}

double BB_Line::getLength()
{
    C2dVector tmp( ( m_Pos2->getX() - m_Pos1->getX() ), ( m_Pos2->getY() - m_Pos1->getY() ) );
    return tmp.getLength();
}

double BB_Line::getWinkel() const{
	return (m_Pos2->getPos() - m_Pos1->getPos()).getWinkel();
}


/**
 *  \fn BB_DrawObject::moveEvent()
 */
void BB_Line::moveEvent()
{
	calculateMiddle();
}


/**
 * Gibt die Mitte der Linie zurück
 * @author Alex Letkemann
 */
const C2dVector& BB_Line::getMiddle()
{
	return m_Middle;
}


/**
 * Berechnet die Mitte der Linie und speichert diese im m_Middle Vektor.
 * @author Alex Letkemann
 */
void BB_Line::calculateMiddle()
{
	if( m_Pos1 != NULL && m_Pos2 != NULL )
	{
		C2dVector v1,v2;
		
		v1 = m_Pos1->getPos();
		v2 = m_Pos2->getPos();
		
		m_Middle = v1 + ( v2 - v1 ) * 0.5;
	}
}
