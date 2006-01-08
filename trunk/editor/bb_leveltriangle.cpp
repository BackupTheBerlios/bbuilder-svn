//
// C++ Implementation: bb_leveltriangle
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_leveltriangle.h"
#include <bb_globals.h>

BB_LevelTriangle::BB_LevelTriangle( BB_Point* p1, BB_Point* p2, BB_Point* p3 ) : BB_Triangle( p1, p2, p3 )
{}


BB_LevelTriangle::~BB_LevelTriangle()
{}


/**
 * Erzeugt zwei Dreiecke für die Decke und den Boden 
 * @param triangles Vektor, an die neuen Dreiecke angehängt werden
 * @param vector Positionsvektor, 
 * @param rotation Rotation
 * @param scale 
 * @param height 
 */
void BB_LevelTriangle::createGl( QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height )
{
    C3dVector v1, v2, v3;

	double textureFactor = 0.1 * scale;



	// Textur-Vektore einstellen
    C3dVector tV1, tV2, tV3;
	tV1.setX( m_Pos1->getX() * textureFactor );
	tV1.setY( m_Pos1->getY() * textureFactor );
    tV1.setZ( 0.0 );

	tV2.setX( m_Pos2->getX() * textureFactor );
	tV2.setY( m_Pos2->getY() * textureFactor );
    tV2.setZ( 0.0 );

	tV3.setX( m_Pos3->getX() * textureFactor );
	tV3.setY( m_Pos3->getY() * textureFactor );
    tV3.setZ( 0.0 );

	
	// Positions-Vektoren für die Untere Fläche einstellen
    v1.setX( m_Pos1->getPos().x() * scale );
    v1.setZ( m_Pos1->getPos().y() * scale );
    v1.setY( 0.0 );

    v2.setX( m_Pos2->getPos().x() * scale );
    v2.setZ( m_Pos2->getPos().y() * scale );
    v2.setY( 0.0 );

    v3.setX( m_Pos3->getPos().x() * scale );
    v3.setZ( m_Pos3->getPos().y() * scale );
    v3.setY( 0.0 );

    v1 = v1.rotateVector( v_Y, rotation );
    v2 = v2.rotateVector( v_Y, rotation );
    v3 = v3.rotateVector( v_Y, rotation );
    // 	v4 = v4.rotateVector( v_Y, rotation );

    v1 = v1 + vector;
    v2 = v2 + vector;
    v3 = v3 + vector;
    // 	v4 = v4 + vector;

    C3dTriangle triangleBottom ( v1, v2, v3, tV1, tV2, tV3, cl_White );


    v1.setY( ( height * scale ) + vector.y() );
    v2.setY( ( height * scale ) + vector.y() );
    v3.setY( ( height * scale ) + vector.y() );

    QImage texture;

    if ( texture.load( IMG_DIR() + SEPARATOR() + "levelBottom.png" ) &&
		 texture.height() != 0 &&
		 texture.width() != 0 )
    {
        triangleBottom.createTexture( texture );
    }
    else
    {
		qDebug() << "Textur (" << IMG_DIR() + SEPARATOR() + "levelBottom.png" + ") konnte nicht geladen werden.";
    }



    C3dTriangle triangleTop ( v3, v2, v1, tV3, tV2, tV1, cl_White );

    if ( texture.load( IMG_DIR() + SEPARATOR() + "levelTop.png" ) &&
		 texture.height() != 0 &&
		 texture.width() != 0 )
    {
        triangleTop.createTexture( texture );
    }
    else
    {
		qDebug() << "Textur (" << IMG_DIR() + SEPARATOR() + "levelTop.png" + ") konnte nicht geladen werden.";
    }


    triangles.append( triangleBottom );
    triangles.append( triangleTop );


}



/*!
    \fn BB_LevelTriangle::getClassName()
 */
const QString BB_LevelTriangle::getClassName()
{
    return QString( "BB_LevelTriangle" );
}
