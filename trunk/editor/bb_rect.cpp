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

/**
 * Konstruktor
 * Erstellt ein leeres Rechteck, welchem die beiden Punkte erst noch zugewiesen werden müssen.
 * @author Alex Letkemann
 */
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
 * @author Alex Letkemann
 */
BB_Rect::BB_Rect( BB_Point* p1, BB_Point* p2 )
        : BB_Line( p1, p2 )
{}


/** Destruktor */
BB_Rect::~BB_Rect()
{}




/**
 *  \fn BB_Object::getClassName()
 */
const QString BB_Rect::getClassName()
{
    return QString( "BB_Rect" );
}


/**
 * Zeichnet den Rechteck auf der Arbeitsfläche
 * @param transformer Transformer, welcher benutzt werden soll.
 * @param painter Painter, mit welchem gezeichnet werden soll.
 */
void BB_Rect::show( BB_Transformer& transformer, QPainter& painter ) const
{
    if ( &transformer != NULL && &painter != NULL && m_Pos1 != NULL && m_Pos2 != NULL )
    {
        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );

        QRectF rect( m_Pos1->getX(),
                     m_Pos1->getY(),
                    ( m_Pos2->getX() - m_Pos1->getX() ),
                    ( m_Pos2->getY() - m_Pos1->getY() ) );

        painter.drawRect( rect );
    }
}


/**
 * Prüft, ob der Rechteck angeclickt wurde.
 * @param hit Position, an der geprüft werden soll.
 * @return Wenn angeclickt true, sonst false.
 * @author Alex Letkemann
 */
bool BB_Rect::isHit( const C2dVector &hit )
{
    QRectF rect( m_Pos1->getX(),
                 m_Pos1->getY(),
                ( m_Pos2->getX() - m_Pos1->getX() ),
                ( m_Pos2->getY() - m_Pos1->getY() ) );
    rect = rect.normalized();
	
	if ( hit.x() > rect.left() && hit.x() < rect.right() )
		if ( hit.y() > rect.top() && hit.y() < rect.bottom() )
            return true;
    return false;
}

/**
 * Bewegt den Rechteck um den übergebenen Vektor
 * @param pMove Vektor, um den der Rechteck bewegt werden soll.
 * @author Alex Letkemann
 */
void BB_Rect::moveBy( C2dVector pMove )
{
	m_Pos1->setX( m_Pos1->getX() + pMove.x() );
	m_Pos1->setY( m_Pos1->getY() + pMove.y() );
	m_Pos2->setX( m_Pos2->getX() + pMove.x() );
	m_Pos2->setY( m_Pos2->getY() + pMove.y() );
}
