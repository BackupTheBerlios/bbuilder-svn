//
// C++ Implementation: bb_buildingtriangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_buildingtriangle.h"
#include <bb_globals.h>


/**
 * Konstrucktor.<br>
 * Erszeugt ein neues Dreieck aus drei übergebenen Punkten
 * @author Alex Letkemann
 */
BB_BuildingTriangle::BB_BuildingTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3): BB_Triangle(p1, p2, p3)
{
}

/**
 * Destruktor
 * @author Alex Letkemann
 */
BB_BuildingTriangle::~BB_BuildingTriangle()
{
}

/**
 * \fn BB_Object::getClassName()
 */
const QString BB_BuildingTriangle::getClassName()
{
	return QString( "BB_BuildingTriangle" );
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
void BB_BuildingTriangle::createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height)
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

	C3dTriangle triangleGround ( v3, v2, v1, tV3, tV2, tV1, cl_White ); 

	v1.setY( ( height * scale ) + vector.y() );
	v2.setY( ( height * scale ) + vector.y() );
	v3.setY( ( height * scale ) + vector.y() );

	QImage texture;

	if ( texture.load( IMG_DIR() + SEPARATOR() + "buildingGround.png" ) &&
			texture.height() != 0 &&
			texture.width() != 0 )
	{
		triangleGround.createTexture( texture );
	}
	else
	{
		qDebug() << "Textur (" << IMG_DIR() + SEPARATOR() + "buildingGround.png" + ") konnte nicht geladen werden.";
	}



	C3dTriangle triangleRoof ( v1, v2, v3, tV1, tV2, tV3, cl_White );

	if ( texture.load( IMG_DIR() + SEPARATOR() + "buildingRoof.png" ) &&
			texture.height() != 0 &&
			texture.width() != 0 )
	{
		triangleRoof.createTexture( texture );
	}
	else
	{
		qDebug() << "Textur (" << IMG_DIR() + SEPARATOR() + "buildingRoof.png" + ") konnte nicht geladen werden.";
	}

	// Dreiecke an Vektor anhängen
	triangles.append( triangleGround );
	triangles.append( triangleRoof );

}

