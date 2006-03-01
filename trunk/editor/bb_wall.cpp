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

#include <c3dquad.h>

#include <iostream>

using namespace std;

int compare ( const void * a, const void * b )
{
    return ( *( int* ) a - *( int* ) b );
}


/**
Standart Konstruktor mit zwei Punkte als Parametern
@param BB_Point p1 Position 1
@param BB_Point p2 Position 2
@author Vaceslav Ustinov
*/
BB_Wall::BB_Wall( BB_Point* p1, BB_Point* p2 ) : BB_Line( p1, p2 )
{
    m_ShowDirection = true;

    //     m_Pen.setColor( Qt::red );
    m_Pen.setWidth( 3 );

    //     m_Brush.setColor( Qt::red );

    m_PenDirection.setWidth( 1 );
    m_PenDirection.setColor( Qt::red );

    moveEvent();

    m_Objects = new QVector <BB_DrawObject *>;
    m_Hight = 3.2;

    // 	setTextureFile(IMG_DIR() + SEPARATOR() +"brick.jpg");
}

/**
Dekonstruktor
@author Vaceslav Ustinov
*/
BB_Wall::~BB_Wall()
{}



/**
Gibt die Name von Klasse zurück
@return QString Name
@author Vaceslav Ustinov
*/
const QString BB_Wall::getClassName()
{
    return QString( "BB_Wall" );
}


/**
 * Schreibt das XML-Element von der Wand in den angegeben Stream. 
 * @param out Stream, in welchen geschrieben werden soll. 
 * @param depth Einrückung. 
 * @author Vaceslav Ustinov
*/
void BB_Wall::generateXElement( QTextStream &out, int depth )
{
    out << BB::indent( depth ) << "<bb_wall id=\"" << getObjectNr()
    << "\" p1=\"" << getPos1() ->getObjectNr()
    << "\" p2=\"" << getPos2() ->getObjectNr() << "\">\n";
    if ( !m_TextureFileName.isNull() )
    {
        out << BB::indent( depth + 1 ) << "<texture file=\"" << getTextureFileName() << "\" />\n";
    }
    //only BB_Windows
    for ( int i = 0;i < m_Objects->count() ;i++ )
    {
        if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Window ) )
        {
            m_Objects->at( i ) ->generateXElement( out, depth );
        }
    }
    //only BB_Doors
    for ( int i = 0;i < m_Objects->count() ;i++ )
    {
        if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Door ) )
        {
            m_Objects->at( i ) ->generateXElement( out, depth );
        }
    }
    //all others
    for ( int i = 0;i < m_Objects->count() ;i++ )
    {
        if ( typeid( *( m_Objects->at( i ) ) ) != typeid( BB_Window ) && typeid( *( m_Objects->at( i ) ) ) != typeid( BB_Door ) )
        {
            m_Objects->at( i ) ->generateXElement( out, depth );
        }
    }

    BB_Object::generateXElement( out, depth + 1 );
    out << BB::indent( depth ) << "</bb_wall>\n";
}

/**
Funktion zum Zeichnen.
@param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
@param QPainter Werkzeug zum Zeichnen @see QT::QPainter
@author Vaceslav Ustinov
*/
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
    //     painter.drawText( dest_Middle.x() , dest_Middle.y() , getName() );


    if ( m_ShowDirection )
    {
        showDirection( transformer, painter, dest_Middle );
    }
}


/**
Funktion startet ein Dialog zum Editieren von Wand-Eigenschften
@param BB_DocComponent Link auf eine Etage
@author Vaceslav Ustinov
*/
void BB_Wall::editDlg( BB_DocComponent * docComponent )
{
    BB_DlgWallEdit EditDlg( this, docComponent, m_Hight );
    EditDlg.exec();
}

/**
Gibt den Vector mit Objekten, die zu dieser Wand gehoeren, zurück.
z.B. Fenster und Türen
@return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
@author Vaceslav Ustinov
*/
QVector< BB_DrawObject * >* BB_Wall::getObjects() const
{
    return m_Objects;
}

/**
Gibt den Vector mit Positions-Punkten von Objekten, die zu dieser Wand gehoeren, zurück.
z.B. Position von Fenster und Position von Tür
@return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
@author Vaceslav Ustinov
*/
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

/**
Setzt ein Vector mit Objekten fest.
Die Objekte sin BB_Window oder BB_Door
@param QVector< BB_DrawObject * > * Zeiger auf ein Vector mit Objekten
@author Vaceslav Ustinov
*/
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
 * Berechnet die Mitte der Linie und speichert diese im m_Middle Vektor.
 * @author Alex Letkemann
 */
void BB_Wall::calculateDirection()
{

    m_Direction = ( m_Pos2->getPos() - m_Pos1->getPos() );
    // Länge der Markierunglinie auf 10 setzen.
    m_Direction = m_Direction.unitVector() * 10.0;
    m_Direction = m_Direction.rotate( 90.0 );
    m_Direction = m_Direction + m_Middle;
}


/**
Ein Erreignis, das aufgerufen wird, wenn das Objekt durch abhängige Objekte bewegt wird.
@author Vaceslav Ustinov
*/
void BB_Wall::moveEvent()
{
    BB_Line::moveEvent();
    calculateDirection();
}


/**
Ändert die Richtung von der Wand
@author Vaceslav Ustinov
*/
void BB_Wall::swap()
{
    BB_Point * tmp;

    tmp = m_Pos1;
    m_Pos1 = m_Pos2;
    m_Pos2 = tmp;

    calculateDirection();
}

/**
Gibt den Vector mit Objekten, die zu dieser Wand gehoeren, zurück.<br>
Hier gehören auch die Positions-Punkte von einzelnen Objekten dazu<br>
z.B. Fenster und Türen, Position von Fenster, Position von Tür
@return QVector< BB_DrawObject * >* Vector mit BB_DrawObject ´s
@author Vaceslav Ustinov
*/
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

/**
Diese Funktion öffnet ein kleines Dialog.<br>
In diesem Dialog kann man dann die Textur fuer die Wand auswählen.
@author Vaceslav Ustinov
*/
void BB_Wall::openTextureDlg()
{
    BB_DlgOpenTexture dlg;
    dlg.setTextureFile( PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName );
    dlg.exec();
    setTextureAbsoluteFileName( dlg.getTextureFile() );
}

/**
 * Erzeugt die Dreiecke für das Dach und den Grund des Gebäudes.<br>
 * Die Erzeugten Dreiecke werden an den übergebenen Vektor 'triangles' angehängt.
 * @param triangles Vektor, an den die Dreiecke angehängt werden.
 * @param vector Positionsektor
 * @param rotation Rotation der Dreiecke
 * @param scale Skalierung der Dreiecke
 * @param height Hier keine Funktion
 * @author Alex Letkemann
 */
void BB_Wall::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
    C3dVector v1, v2, v3, v4;

    BB_ConstructionElement * myElement;
    C2dVector richtung = ( m_Pos2->getPos() - m_Pos1->getPos() );

    C2dVector pos1, pos2;
    C3dTriangle t1, t2;
    C3dTriangle tr1, tr2;
    myElement = hastDoor();
    //Wenn eine Tuer vorhanden ist, dann mache 3 Vierecke
    if ( myElement != NULL )
    {
        tr1.setVisible( false );
        tr2.setVisible( false );
        pos1 = m_Pos1->getPos() + ( richtung * myElement->getCoefficientPos1().x() );
        pos2 = m_Pos1->getPos() + ( richtung * myElement->getCoefficientPos2().x() );


        //--------------------erste Viereck
        v1.setX( m_Pos1->getPos().x() * scale );
        v1.setZ( m_Pos1->getPos().y() * scale );
        v1.setY( 0.0 );

        v2.setX( pos1.x() * scale );
        v2.setZ( pos1.y() * scale );
        v2.setY( 0.0 );

        v3.setX( pos1.x() * scale );
        v3.setZ( pos1.y() * scale );
        v3.setY( height * scale );

        v4.setX( m_Pos1->getPos().x() * scale );
        v4.setZ( m_Pos1->getPos().y() * scale );
        v4.setY( height * scale );

        v1 = v1.rotateVector( v_Y, rotation );
        v2 = v2.rotateVector( v_Y, rotation );
        v3 = v3.rotateVector( v_Y, rotation );
        v4 = v4.rotateVector( v_Y, rotation );

        v1 = v1 + vector;
        v2 = v2 + vector;
        v3 = v3 + vector;
        v4 = v4 + vector;

        //         triangles.append( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        //         triangles.append( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );

        tr1.copy( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        tr2.copy( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        triangles.append( tr1 );
        triangles.append( tr2 );

        //-------------------- zweite Viereckt  "mit Tuer"

        v1.setX( pos1.x() * scale );
        v1.setZ( pos1.y() * scale );
        v1.setY( 0.0 );

        v2.setX( pos2.x() * scale );
        v2.setZ( pos2.y() * scale );
        v2.setY( 0.0 );

        v3.setX( pos2.x() * scale );
        v3.setZ( pos2.y() * scale );
        v3.setY( height * scale );

        v4.setX( pos1.x() * scale );
        v4.setZ( pos1.y() * scale );
        v4.setY( height * scale );

        v1 = v1.rotateVector( v_Y, rotation );
        v2 = v2.rotateVector( v_Y, rotation );
        v3 = v3.rotateVector( v_Y, rotation );
        v4 = v4.rotateVector( v_Y, rotation );

        v1 = v1 + vector;
        v2 = v2 + vector;
        v3 = v3 + vector;
        v4 = v4 + vector;

        tr1.copy( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Red ) );
        tr1.setCollision( false );
        // 		tr1.setVisible( true );
        tr2.copy( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Red ) );
        tr2.setCollision( false );
        // 		tr2.setVisible( true );
        triangles.append( tr1 );
        triangles.append( tr2 );
        tr1.setCollision( true );
        tr2.setCollision( true );

        //-------------------- dritte Viereckt

        v1.setX( pos2.x() * scale );
        v1.setZ( pos2.y() * scale );
        v1.setY( 0.0 );

        v2.setX( m_Pos2->getPos().x() * scale );
        v2.setZ( m_Pos2->getPos().y() * scale );
        v2.setY( 0.0 );

        v3.setX( m_Pos2->getPos().x() * scale );
        v3.setZ( m_Pos2->getPos().y() * scale );
        v3.setY( height * scale );

        v4.setX( pos2.x() * scale );
        v4.setZ( pos2.y() * scale );
        v4.setY( height * scale );

        v1 = v1.rotateVector( v_Y, rotation );
        v2 = v2.rotateVector( v_Y, rotation );
        v3 = v3.rotateVector( v_Y, rotation );
        v4 = v4.rotateVector( v_Y, rotation );

        v1 = v1 + vector;
        v2 = v2 + vector;
        v3 = v3 + vector;
        v4 = v4 + vector;

        //         triangles.append( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        //         triangles.append( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );

        tr1.copy( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        tr2.copy( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );
        triangles.append( tr1 );
        triangles.append( tr2 );


        //Grosse Dreiecke auf notCollision setzen
        t1.setCollision( false );
        t2.setCollision( false );
    }
    //Zwei Dreiecke fuer die Ganze wand
    //-------------------------------------
    v1.setX( m_Pos1->getPos().x() * scale );
    v1.setZ( m_Pos1->getPos().y() * scale );
    v1.setY( 0.0 );

    v2.setX( m_Pos2->getPos().x() * scale );
    v2.setZ( m_Pos2->getPos().y() * scale );
    v2.setY( 0.0 );

    v3.setX( m_Pos2->getPos().x() * scale );
    v3.setZ( m_Pos2->getPos().y() * scale );
    v3.setY( height * scale );

    v4.setX( m_Pos1->getPos().x() * scale );
    v4.setZ( m_Pos1->getPos().y() * scale );
    v4.setY( height * scale );

    v1 = v1.rotateVector( v_Y, rotation );
    v2 = v2.rotateVector( v_Y, rotation );
    v3 = v3.rotateVector( v_Y, rotation );
    v4 = v4.rotateVector( v_Y, rotation );

    v1 = v1 + vector;
    v2 = v2 + vector;
    v3 = v3 + vector;
    v4 = v4 + vector;

    /** Cod von Alex*/
    t1.copy( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
    t2.copy( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );
    /** Ende Code Von Alex*/

    //         triangles.append( C3dTriangle( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Blue ) );
    //         triangles.append( C3dTriangle( v3, v4, v1, v_Zero, v_Zero, v_Zero, cl_Blue ) );


    //Texture laden, es wird nur eine Textur fuer die Ganze Wand erzeugt
    //     if ( !m_TextureFileName.isEmpty() )
    //     {



    QImage img;
    //         qDebug() << PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName();
    if ( ( img.load( PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName() ) &&
           img.height() != 0 &&
           img.width() != 0 ) ||
         img.load( IMG_DIR() + SEPARATOR() + "building.png" ) )
    {
        C3dVector tV1, tV2, tV3, tV4;


        double x, y, l, h, factor;
        factor = 10;

        x = img.width();
        y = img.height();
        l = getLength() / factor * scale;
        h = height / factor;

        tV1.setX( 0.0 );
        tV1.setY( y / h );
        tV1.setZ( 0.0 );

        tV2.setX( x / l );
        tV2.setY( y / h );
        tV2.setZ( 0.0 );

        tV3.setX( x / l );
        tV3.setY( 1.0 );
        tV3.setZ( 0.0 );

        tV4.setX( 0.0 );
        tV4.setY( 1.0 );
        tV4.setZ( 0.0 );

        t1.setVTex0( tV4 );
        t1.setVTex1( tV3 );
        t1.setVTex2( tV2 );

        t2.setVTex0( tV2 );
        t2.setVTex1( tV1 );
        t2.setVTex2( tV4 );

        t1.createTexture( img );
        t2.createTexture( img );
    }
    else
    {
        qDebug() << "Textur " << PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName() + " konnte nicht geladen werden." << endl;
    }

    //     }
    //Dreiecke fuer Wand einfuegen
    triangles.append( t1 );
    triangles.append( t2 );

    //Tueren und Fenster
    tr1.setVisible( true );
    tr2.setVisible( true );
    for ( int i = 0;i < m_Objects->count() ;i++ )
    {

        myElement = ( BB_ConstructionElement * ) m_Objects->at( i );

        pos1 = m_Pos1->getPos() + ( richtung * myElement->getCoefficientPos1().x() );
        pos2 = m_Pos1->getPos() + ( richtung * myElement->getCoefficientPos2().x() );

        v1.setX( pos1.x() * scale );
        v1.setZ( pos1.y() * scale );
        // 		v1.setY( 0.0 );
        v1.setY( height * myElement->getCoefficientPos2().y() * scale );

        v2.setX( pos2.x() * scale );
        v2.setZ( pos2.y() * scale );
        // 		v2.setY( 0.0 );
        v2.setY( height * myElement->getCoefficientPos2().y() * scale );

        v3.setX( pos2.x() * scale );
        v3.setZ( pos2.y() * scale );
        // 		v3.setY( height * scale );
        v3.setY( height * myElement->getCoefficientPos1().y() * scale );

        v4.setX( pos1.x() * scale );
        v4.setZ( pos1.y() * scale );
        // 		v4.setY( height * scale );
        v4.setY( height * myElement->getCoefficientPos1().y() * scale );

        v1 = v1.rotateVector( v_Y, rotation );
        v2 = v2.rotateVector( v_Y, rotation );
        v3 = v3.rotateVector( v_Y, rotation );
        v4 = v4.rotateVector( v_Y, rotation );

        C3dVector normal = v1.getNormalVector( v2 );
        normal = normal.unitVector() / 10;


        v1 = v1 + vector - normal;
        v2 = v2 + vector - normal;
        v3 = v3 + vector - normal;
        v4 = v4 + vector - normal;

        C3dVector tV1( 0.0, 0.0, 0.0 ), tV2( 1.0, 0.0, 0.0 ), tV3( 0.0, 1.0, 0.0 ), tV4( 1.0, 1.0, 0.0 );




        tr1 = C3dTriangle( v1, v2, v3, tV2, tV1, tV3, cl_White );
        tr1.setCollision( false );
        // 		tr1.setVisible( true );
        tr2 = C3dTriangle( v3, v4, v1, tV4, tV3, tV1, cl_Blue );
        tr2.setCollision( false );
        // 		tr2.setVisible( true );

        //         tr1.setCollision( true );
        //         tr2.setCollision( true );


        if ( !myElement->getTextureFileName().isEmpty() )
        {
            QImage img;
            // 			qDebug()  << PRO_TEXTURES_DIR() + SEPARATOR() + myElement->getTextureFileName();
            if ( ( img.load( PRO_TEXTURES_DIR() + SEPARATOR() + myElement->getTextureFileName() ) &&
                   img.height() != 0 &&
                   img.width() != 0 ) )
            {
                tr1.createTexture( img );
                tr2.createTexture( img );
            }

        }
        triangles.append( tr1 );
        triangles.append( tr2 );
    }

}

/**
Gibt die erste im Vector stehende Tür zurück<br>
Falls es uberhaupt keine Türen gibts, wird ein NULL-Pointer zurückgegeben,
@return BB_Door
@author Vaceslav Ustinov
*/
BB_Door * BB_Wall::hastDoor()
{
    for ( int i = 0;i < m_Objects->count() ;i++ )
    {
        if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Door ) )
        {
            return ( BB_Door * ) m_Objects->at( i );
        }
    }
    return NULL;
}
