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
***************************************************************************/
#include "bb_point.h"

#include <iostream>
#include <math.h>
#include "bb_line.h"

using namespace std;

/**
Konstruktor ohne Parameter<br>
Die Positionen werden auf (0;0) gesetzt
@author Vaceslav Ustinov
*/
BB_Point::BB_Point()
        : BB_DrawObject()
{
    m_Radius = 7;
    m_hitRange = 2;
    m_scale = 1.0;
    m_Links.clear();
    m_Pos.setX( 0.0 );
    m_Pos.setY( 0.0 );

}

/**
Konstructor mit C2dVector<br>
@param C2dVector Position auf die Karte
@author Vaceslav Ustinov
 */
BB_Point::BB_Point( C2dVector p )
        : BB_DrawObject()
{
    m_Pos = p;
    m_Radius = 7;
    m_hitRange = 2;
    m_Selected = false;


    // 	m_Pen.setColor( Qt::red );
    // 	m_Brush.setColor( Qt::red );

    m_scale = 1.0;
}

/**
Konstructor mit QPoint
@param QPoint Position auf die Karte
@author Vaceslav Ustinov
*/
BB_Point::BB_Point( QPoint p )
        : BB_DrawObject()
{
    m_Pos.setX( p.x() );
    m_Pos.setY( p.y() );
    m_Radius = 7;
    m_hitRange = 2;
    m_Selected = false;



    // 	m_Pen.setColor( Qt::red );
    // 	m_Brush.setColor( Qt::red );
    m_scale = 1.0;
}

/**
Dekonstruktor
@author Vaceslav Ustinov
*/
BB_Point::~BB_Point()
{
    if ( m_Links.count() > 0 )
    {
        qDebug( "Warnung: Der zu löschende Punkt enthält noch Links" );
    }
}

/**
Verschiebt den Punkt um angegebenen Abstand
@param C2dVector Ein Schiebe-Vector
@author Vaceslav Ustinov
*/
void BB_Point::moveBy( C2dVector vMove )
{
    m_Pos = m_Pos + vMove;
    moveEvent();

}

/**
Funktion zum Zeichnen.
@param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
@param QPainter Werkzeug zum Zeichnen @see QT::QPainter
@author Vaceslav Ustinov
*/
void BB_Point::show( BB_Transformer& transformer, QPainter& painter ) const
{
    QPoint dest;
    int breite = ( int ) m_Radius / 3;

    transformer.logicalToScreen( dest, m_Pos );

    if ( m_Selected )
    {
        painter.setPen( m_PenSelected );
        painter.setBrush( m_BrushSelected );
    }
    else
    {
        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );
    }

    // 	painter.setBrush( m_Brush );

    //painter.drawEllipse(dest.x() - m_Radius, dest.y() - m_Radius, m_Radius*2, m_Radius*2);
    painter.drawRect( dest.x() - m_Radius, dest.y() - m_Radius, m_Radius * 2, breite );
    painter.drawRect( dest.x() - m_Radius, dest.y() + m_Radius - breite, m_Radius * 2, breite );
    painter.drawRect( dest.x() - m_Radius, dest.y() - m_Radius + breite, breite, m_Radius * 2 - breite * 2 );
    painter.drawRect( dest.x() + m_Radius - breite, dest.y() - m_Radius + breite, breite, m_Radius * 2 - breite * 2 );
    //     painter.setBrush( QColor( 0, 200, 0 ) );
    //     painter.setPen( QColor( 0, 200, 0 ) );
    painter.drawRect( dest.x() - breite, dest.y() - breite,
                      breite * 2, breite * 2 );

    //  EDIT: Alex Letkemann: Andere Selektionsmarkierung implementiert
    //     if ( m_Selected )
    //     {
    //         painter.setBrush( QColor( 0, 0, 200 ) );
    //         painter.setPen( QColor( 0, 0, 200 ) );
    //         painter.drawText( dest.x() - m_Radius - breite, dest.y() - m_Radius - breite, "->" );
    //         painter.drawRect( dest.x() - m_Radius - breite, dest.y() - m_Radius - breite,
    //                           breite, breite );
    //         painter.drawRect( dest.x() - m_Radius - breite, dest.y() + m_Radius,
    //                           breite, breite );
    //         painter.drawRect( dest.x() + m_Radius, dest.y() - m_Radius - breite,
    //                           breite, breite );
    //         painter.drawRect( dest.x() + m_Radius, dest.y() + m_Radius,
    //                           breite, breite );
    //     }
}



/**
Gibt das Radius von dem Punkt zurück
@return double Radius in Pixel
@author Vaceslav Ustinov
*/
double BB_Point::getRadius()
{
    return m_Radius;
}


/**
Setzt das Radius von dem Punkt fest ein
@author Vaceslav Ustinov
*/
void BB_Point::setRadius( double r )
{
    m_Radius = r;
}

/**
Funktion uberprüft ob der Punkt auf angegebene Position "hit" liegt
@param C2dVector Klick-Position
@author Vaceslav Ustinov
*/
bool BB_Point::isHit( const C2dVector& hit )
{
    //isHit von Kreis
    //         double abstand = m_Pos.getAbstand(hit);
    //         if(abstand <= (m_Radius + m_hitRange))
    //                 return true;
    //         return false;

    //isHit von Viereck
    if ( m_scale > 20 )
    {
        m_scale = 1;
        qDebug( "Scale wurede auf eins gesetzt" );
    }
    cout << "hit: x-> " << hit.x() << " y-> " << hit.y() << endl;
    double abstandX = fabs ( ( hit.x() - m_Pos.x() ) );
    double abstandY = fabs ( ( hit.y() - m_Pos.y() ) );
    cout << "abstandX: " << abstandX << "abstandY : " << abstandY << endl;
    //   cout << "scale:" << m_scale<<endl;
    if ( abstandX <= ( m_Radius / m_scale ) && abstandY <= ( m_Radius / m_scale ) )
    {
        cout << "point hittrue " << m_scale << endl;
        return true;
    }
    return false;
}


/**
Funktion uberprüft ob der Punkt in angegebenen Rechteck "rect" liegt
@param QRectF Ausgewählte Rechteck
@author Vaceslav Ustinov
*/
bool BB_Point::isHit( const QRectF& rect )
{
    QRectF normRect = rect.normalized();
    cout << "rect: top" << normRect.top() << endl;
    if ( ( getX() > normRect.x() ) && ( getX() < normRect.right() ) )
    {
        if ( ( getY() > normRect.top() ) && ( getY() < normRect.bottom() ) )
        {
            return true;
        }
    }
    return false;
}

/**
Gibt die aktuelle Position zurück
@return C2dVector aktuelle Position
@author Vaceslav Ustinov
*/
const C2dVector& BB_Point::getPos() const
{
    return m_Pos;
}

/**
Setzt die Position von dem Punkt fest
@param C2dVector neue Position
@author Vaceslav Ustinov
*/
void BB_Point::setPos( const C2dVector& theValue )
{
    m_Pos = theValue;
}

/**
Gibt die Name von Klasse zurück
@return QString Name
@author Vaceslav Ustinov
*/
const QString BB_Point::getClassName()
{
    return QString( "BB_Point" );
}
/**
setzt die position auf X-Achse fest
@param double Neue X-Position
@author Vaceslav Ustinov
*/
void BB_Point::setX( double value )
{
    m_Pos.setX( value );
    moveEvent();
}

/**
setzt die position auf Y-Achse fest
@param double Neue Y-Position
@author Vaceslav Ustinov
*/
void BB_Point::setY( double value )
{
    m_Pos.setY( value );
    moveEvent();
}


/**
 * Schreibt das XML-Element des Punktes in den angegeben Stream. 
 * @param out Stream, in welchen geschrieben werden soll. 
 * @param depth Einrückung. 
 * @author Vaceslav Ustinov
*/
void BB_Point::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_point id=\"" << getObjectNr() << "\" x=\"" << getX() << "\" y=\"" << getY() << "\">\n";
    BB_Object::generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</bb_point>\n";
}


/**
Gibt das ItemModel des Punktes zurück
@return QStandardItemModel
@see QT::QStandardItemModel
@author Vaceslav Ustinov
*/
QStandardItemModel * BB_Point::getItemModel()
{
    QStandardItemModel * model = new QStandardItemModel( 4, 2 );
    QModelIndex index = model->index( 0, 0, QModelIndex() );
    //model->setData(index, QVariant((row+1) * (column+1)));
    model->setData( index, QVariant( "m_Color" ) );
    index = model->index( 0, 1, QModelIndex() );
    model->setData( index, QVariant( "Red" ) );

    return model;
}



/**
Löscht vollständig ein Objekt aus dem Vektor.
@date 14.11.2005
@param BB_DrawObject * zu löschende Objekt
@return void
@author Vaceslav Ustinov
*/
void BB_Point::deleteLinkedObject( BB_DrawObject * object )
{
    cout << "deleteLinkedObject( " << object << " )" << endl;

    if ( object == NULL )
    {
        cout << "Null Pointer an Funktion 'BB_Point::deleteLinkedObject(BB_DrawObject * object)' ubergeben" << endl;
        return ;
    }
    //     if ( removeLinkedObject( object ) != NULL )
    //     {
    cout << "delete " << object << ";" << endl;
    delete object;
    //     }
}


/**
Entfernt ein Objekt aus dem Vektor.<br>Instantz wird nicht gelöscht
@author Vaceslav Ustinov
@param BB_DrawObject ein Object, der vom dem Vector entfernt werden soll
@return pointer auf der Object der aus Vector entwert wurde
@date 14.11.2005
*/
void BB_Point::removeLinkedObject( BB_DrawObject * object )
{
    //     cout << "BB_Point::removeLinkedObject( " << object << " )" << endl;
    if ( object == NULL )
    {
        cout << "Null Pointer an Funktion 'BB_Point::removeLinkedObject(BB_DrawObject * object)' ubergeben" << endl;
        return ;
    }

    BB_DrawObject * tmp;
    for ( int i = 0;i < m_Links.count() ;i++ )
    {
        tmp = m_Links.at( i );
        if ( tmp == object )
        {
            m_Links.remove( i );
            return ;
        }
    }
    tmp = NULL;
    return ;
}

/**
Entfernt ein Objekt aus dem Vektor.<br>
Instantz wird auch gelöscht
@author Vaceslav Ustinov
@date 14.11.2005
@return void
*/
void BB_Point::deleteLinkedObjects( QVector< BB_DrawObject * >* objects )
{

    BB_DrawObject * tmp;
    BB_DrawObject * tmp_object;

    for ( int i = m_Links.count() - 1; i >= 0; i-- )
    {
        tmp = m_Links.at( i );

        for ( int j = objects->count() - 1; j >= 0; j-- )
        {
            tmp_object = objects->at( j );
            if ( tmp_object == tmp )
            {
                // 				cout << "delete " << tmp << endl;
                objects->remove( j );
                delete tmp;
            }
        }
    }

    m_Links.clear();
}
/**
Fügt ein neues Objekt in Vector zu
@param BB_DrawObject Objekt, das hinzugefügt werden soll
@author Vaceslav Ustinov
*/
void BB_Point::addObject( BB_DrawObject * newObject )
{
    m_Links.insert( m_Links.count(), newObject );
}

/**
* Erzeugt von BB_Point ein QT-QPoint
* @return QPoint
* @date 20.12.2005
* @author Vaceslav Ustinov
*/
QPoint BB_Point::getQPoint()
{
    return QPoint( m_Pos.x(), m_Pos.y() );
}

/**
Richtet den Punkt mit angegebenen Punkt horizontal aus
@param BB_Point Punkt zum Vergleichen
@author Vaceslav Ustinov
*/
void BB_Point::bringToLineHorizontal( BB_Point *point )
{
    if ( point != NULL )
    {
        setY( point->getY() );
    }
}

/**
Richtet den Punkt mit angegebenen Punkt vertikal aus
@param BB_Point Punkt zum Vergleichen
@author Vaceslav Ustinov
*/
void BB_Point::bringToLineVertikal( BB_Point *point )
{
    if ( point != NULL )
    {
        setX( point->getX() );
    }
}

/**
Ein Erreignis, das aufgerufen wird, wenn das Objekt durch abhängige Objekte bewegt wird.
@author Vaceslav Ustinov
*/
void BB_Point::moveEvent()
{
    for ( int i = 0; i < m_Links.count(); i++ )
    {
        m_Links.at( i ) ->moveEvent();
    }
}
