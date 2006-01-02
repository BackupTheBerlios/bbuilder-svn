//
// C++ Implementation: bb_rect
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_rect.h"
#include "bb_point.h"

#include <iostream>

using namespace std;

BB_Rect::BB_Rect()
        : BB_Line( NULL, NULL )
{
    m_Pos1 = NULL;
    m_Pos2 = NULL;
}

/**
 * Konstruktor
 * Erstellt einen <i>dynamischen</i> Rechteck. D.h. wenn sich die Positionen der übergeben Punkte ändern,
 * ändert sich auch die Position bzw. die Größe des Rechtecks.
 * @param p1 Position des ersten Punktes.
 * @param p2 Position des zweiten, <b>quer gegenüber liegenden</b> Punktes.
 */
BB_Rect::BB_Rect( BB_Point* p1, BB_Point* p2 )
        : BB_Line( p1, p2 )
{}


/** Destruktor */
BB_Rect::~BB_Rect()
{}




/*!
    \fn BB_Rect::getClassName()
 */
const QString BB_Rect::getClassName()
{
    return QString( "BB_Rect" );
}


void BB_Rect::show( BB_Transformer& transformer, QPainter& painter ) const
{
    if ( &transformer != NULL && &painter != NULL && m_Pos1 != NULL && m_Pos2 != NULL )
    {
        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );

        QRect rect( ( int ) m_Pos1->getX(),
                    ( int ) m_Pos1->getY(),
                    ( int ) ( m_Pos2->getX() - m_Pos1->getX() ),
                    ( int ) ( m_Pos2->getY() - m_Pos1->getY() ) );

        painter.drawRect( rect );
    }
}


/*!
    \fn BB_Rect::isHit(const C2dVector &hit)
 */
bool BB_Rect::isHit( const C2dVector &hit )
{
    QRect rect( ( int ) m_Pos1->getX(),
                ( int ) m_Pos1->getY(),
                ( int ) ( m_Pos2->getX() - m_Pos1->getX() ),
                ( int ) ( m_Pos2->getY() - m_Pos1->getY() ) );
    rect = rect.normalized();
	
	if ( hit.x() > rect.left() && hit.x() < rect.right() )
		if ( hit.y() > rect.top() && hit.y() < rect.bottom() )
            return true;
    return false;
}

void BB_Rect::moveBy( C2dVector pMove )
{
	m_Pos1->setX( m_Pos1->getX() + pMove.x() );
	m_Pos1->setY( m_Pos1->getY() + pMove.y() );
	m_Pos2->setX( m_Pos2->getX() + pMove.x() );
	m_Pos2->setY( m_Pos2->getY() + pMove.y() );
}
