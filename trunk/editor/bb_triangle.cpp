//
// C++ Implementation: bb_triangle
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_triangle.h"
#include "c3dvector.h"
#include <bb_terrainpoint.h>
#include <c3dtriangle.h>

#include <QBrush>
#include <iostream>
#include <bb_globals.h>

using namespace std;

/**
 * Erstellt einen Dreieck aus den angegeben Eckpunkten.
 * @param p1 Position der ersten Ecke
 * @param p2 Position der zweiten Ecke
 * @param p3 Position der dritten Ecke
 */
BB_Triangle::BB_Triangle( BB_Point* p1, BB_Point* p2, BB_Point* p3 ) : BB_Line( p1, p2 )
{
    // Mit NULL initialisieren
    m_Pos3 = NULL;

    if ( p3 != NULL )
    {
        setPos3( p3 );
        m_Brush.setColor( QColor( 255, 221, 118 ) );
        m_Brush.setStyle( Qt::Dense4Pattern );
    }
    else
    {
        // TODO
        cout << "BB_Triangle::BB_Triangle(): NULL-Ponter ehalten" << endl;
        exit( 0 );
    }
}


BB_Triangle::~BB_Triangle()
{
    m_Pos1->removeLinkedObject( this );
    m_Pos2->removeLinkedObject( this );
    m_Pos3->removeLinkedObject( this );
}


/**
 * Prüft, ob der Dreieck sich komplett im angegeben Rechteck befindet.
 * @param rect Recheck
 * @return True falls sich der Dreieck komplett im Rechteck befindet, sonst false.
 */
bool BB_Triangle::isHit( const QRectF& rect )
{
    return BB_Line::isHit( rect ) && m_Pos3->isHit( rect );
}

bool BB_Triangle::isHit( const C2dVector& hit )
{

    ///@todo isHit für Triangle
    return BB_Line::isHit( hit );
}

/**
 * Gibt den Klassennamen zurück
 */
const QString BB_Triangle::getClassName()
{
    return "BB_Triangle";
}


void BB_Triangle::show( BB_Transformer& transformer, QPainter& painter ) const
{
    if ( m_Pos1 != NULL && m_Pos2 != NULL && m_Pos3 != NULL )
    {
        // 	cout << "Triangle::show() - start" << endl;
        // 	QPoint dest_Pos1, dest_Pos2;
        QPoint point[ 3 ];

        transformer.logicalToScreen( point[ 0 ], m_Pos1->getPos() );
        transformer.logicalToScreen( point[ 1 ], m_Pos2->getPos() );
        transformer.logicalToScreen( point[ 2 ], m_Pos3->getPos() );

        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );

        // 	painter.drawLine(dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y());
        painter.drawPolygon( point, 3 );

        // 	cout << "Triangle::show() - end" << endl;
    }
}

/*
void BB_Triangle::remove(BB_Point* point)
{
	cout << "void BB_Triangle::remove(" << point << ")" << endl;
	
	if (m_Pos1 == point)
	{
		cout << "m_Pos2( " << m_Pos2 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos2->deleteLinkedObject( this );
		
		cout << "m_Pos3( " << m_Pos3 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos3->deleteLinkedObject( this );
	}
	else if(m_Pos2 == point)
	{
		cout << "m_Pos1( " << m_Pos1 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos1->deleteLinkedObject( this );
		
		cout << "m_Pos3( " << m_Pos3 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos3->deleteLinkedObject( this );
	}
	else if(m_Pos3 == point)
	{
		cout << "m_Pos1( " << m_Pos1 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos1->deleteLinkedObject( this );
		
		cout << "m_Pos2( " << m_Pos2 << " )->deleteLinkedObject( " << this << " );" << endl;
		m_Pos2->deleteLinkedObject( this );
	}
 
}
 
*/

/**
 * Gibt die Position der dritten Ecke des Dreiecks zurück
 * @return Die Position der dritten Ecke des Dreiecks
 */
BB_Point* BB_Triangle::getPos3() const
{
    return m_Pos3;
}


/**
 * Setzt die Position der dritten Ecke des Dreiecks
 * @param point Position der dritten Ecke
 */
bool BB_Triangle::setPos3( BB_Point* value )
{
    if ( value != NULL && value != m_Pos1 && value != m_Pos2 )
    {

        // EDIT: Alex Letkemann
        // DATE: 07.12.2005
        // Links werden bei jedem Setzten des Punktes aktualisiert.
        if ( m_Pos3 != NULL )
            m_Pos3->removeLinkedObject( this );
        m_Pos3 = value;
        m_Pos3->addObject( this );

        // Mitte neu berechnen
        moveEvent();

        return true;
    }
    return false;
}


/**
 * Erstellt ein BB_Triangle XML-Element und schreibt dieses in den out-Stream
 * @param out Stream, in welchen das Element geschrieben wird.
 * @param depth Tiefe der Einrückung
 * @author Alex Letkemann
 * @date 11.12.2005
 */
void BB_Triangle::generateXElement( QTextStream &out, int depth )
{
	out << BB::indent( depth ) << "<" << getClassName().toLower() << " id=\"" << getObjectNr()
    << "\" p1=\"" << getPos1() ->getObjectNr()
    << "\" p2=\"" << getPos2() ->getObjectNr()
    << "\" p3=\"" << getPos3() ->getObjectNr() << "\">\n";

    BB_Object::generateXElement( out, depth + 1 );
	if( !m_TextureFileName.isEmpty() )
	{
		out << BB::indent( depth + 1 ) << "<texture file=\"" << getTextureFileName() << "\" />\n";
	}
	
	out << BB::indent( depth ) << "</" << getClassName().toLower() << ">\n";
}


void BB_Triangle::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
	/* Hier keine Implementation */    
	
}

void BB_Triangle::normalize(){
	
	//Positionsvectoren
	C3dVector p1(m_Pos1->getX(), m_Pos1->getY(), 0.0);
	C3dVector p2(m_Pos2->getX(), m_Pos2->getY(), 0.0);
	C3dVector p3(m_Pos3->getX(), m_Pos3->getY(), 0.0);
	
	//Richtungsvektoren
	C3dVector vr1 =p1 - p2;
	C3dVector vr2 =p1 - p3;
	
	//NormalVektor
	C3dVector n= vr1.getNormalVector( vr2);
	if (n.z() > 0){
		qDebug("Falsche Richtung beim Dreieck");
		BB_Point * tmp =m_Pos2;
		m_Pos2 = m_Pos3;
		m_Pos3 = tmp;
		

	}
}
void BB_Triangle::moveEvent(){
// 	BB_Line::moveEvent();
	normalize();
}
