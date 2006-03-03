//
// C++ Implementation: bb_terraintriangle
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_terraintriangle.h"
#include <bb_terrainpoint.h>
#include <bb_globals.h>

/**
 * Erstellt einen Dreieck aus den drei übergebenen Punkten
 * @author Alex Letkemann
 */
BB_TerrainTriangle::BB_TerrainTriangle( BB_Point* p1, BB_Point* p2, BB_Point* p3 ) : BB_Triangle( p1, p2, p3 )
{}

/** Destruktor */
BB_TerrainTriangle::~BB_TerrainTriangle()
{}


/**
 * Erstellt einen 3D-Dreieck und hängt diesen an den übergebenen Vektor 'triangles' an.
 * @param triangles Vektor mit 3D Dreiecken
 * @param vector Position des Dreiecks
 * @param rotation Rotation des Dreiecks
 * @param scale Maßstab des Dreiecks
 * @param height Hier keine Funktion
 */
void BB_TerrainTriangle::createGl( QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height )
{
    C3dVector v1, v2, v3;

    v1.setX( m_Pos1->getPos().x() * scale );
    v1.setZ( m_Pos1->getPos().y() * scale );
    if ( typeid( *m_Pos1 ) == typeid( BB_TerrainPoint ) )
    {
        v1.setY( ( ( BB_TerrainPoint* ) ( m_Pos1 ) ) ->getHeight() );
    }
    else
    {
        v1.setY( height );
    }

    v2.setX( m_Pos2->getPos().x() * scale );
    v2.setZ( m_Pos2->getPos().y() * scale );
    if ( typeid( *m_Pos2 ) == typeid( BB_TerrainPoint ) )
    {
        v2.setY( ( ( BB_TerrainPoint* ) ( m_Pos2 ) ) ->getHeight() );
    }
    else
    {
        v2.setY( height );
    }

    v3.setX( m_Pos3->getPos().x() * scale );
    v3.setZ( m_Pos3->getPos().y() * scale );
    if ( typeid( *m_Pos3 ) == typeid( BB_TerrainPoint ) )
    {
        v3.setY( ( ( BB_TerrainPoint* ) ( m_Pos3 ) ) ->getHeight() );
    }
    else
    {
        v3.setY( height );
    }

    C3dTriangle triangle ( v1, v2, v3, v_Zero, v_Zero, v_Zero, cl_Gray );

    QImage img;
//     qDebug() << PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName();
    if ( ( img.load( PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName() ) &&
            img.height() != 0 &&
            img.width() != 0 ) ||
            img.load( IMG_DIR() + SEPARATOR() + "terrain.png" ) )
    {
        C3dVector tV1, tV2, tV3;


        tV1.setX( m_Pos1->getX() * 0.5 );
        tV1.setY( m_Pos1->getY() * 0.5 );
        tV1.setZ( 0.0 );

        tV2.setX( m_Pos2->getX() * 0.5 );
        tV2.setY( m_Pos2->getY() * 0.5 );
        tV2.setZ( 0.0 );

        tV3.setX( m_Pos3->getX() * 0.5 );
        tV3.setY( m_Pos3->getY() * 0.5 );
        tV3.setZ( 0.0 );


        triangle.setVTex0( tV1 );
        triangle.setVTex1( tV2 );
        triangle.setVTex2( tV3 );


        triangle.createTexture( img );
    }

    triangles.append( triangle );

}



/*!
    \fn BB_TerrainTriangle::getClassName()
 */
const QString BB_TerrainTriangle::getClassName()
{
    return QString( "BB_TerrainTriangle" );
}
