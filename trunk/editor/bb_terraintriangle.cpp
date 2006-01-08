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

BB_TerrainTriangle::BB_TerrainTriangle(BB_Point* p1, BB_Point* p2, BB_Point* p3): BB_Triangle(p1, p2, p3)
{
}


BB_TerrainTriangle::~BB_TerrainTriangle()
{
}


void BB_TerrainTriangle::createGl(QVector< C3dTriangle >& triangles, C3dVector vector, double rotation, double scale, double height)
{
	C3dVector v1, v2, v3;

	v1.setX( m_Pos1->getPos().x() * scale );
	v1.setZ( m_Pos1->getPos().y() * scale );
	
	if( typeid(*m_Pos1) == typeid( BB_TerrainPoint ) )
	{
		v1.setY( (( BB_TerrainPoint* )( m_Pos1))->getHeight() );
	}
	else
	{
		v1.setY( height );
	}

	v2.setX( m_Pos2->getPos().x() * scale );
	v2.setZ( m_Pos2->getPos().y() * scale );
	if( typeid(*m_Pos2) == typeid( BB_TerrainPoint ) )
	{
		v2.setY( (( BB_TerrainPoint* )( m_Pos2))->getHeight() );
	}
	else
	{
		v2.setY( height );
	}

	v3.setX( m_Pos3->getPos().x() * scale );
	v3.setZ( m_Pos3->getPos().y() * scale );
	if( typeid(*m_Pos3) == typeid( BB_TerrainPoint ) )
	{
		v3.setY( (( BB_TerrainPoint* )( m_Pos3))->getHeight() );
	}
	else
	{
		v3.setY( height );
	}

	
// 	qDebug( "C3dTriangle: v1 %f|%f|%f v2 %f|%f|%f v3 %f|%f|%f ",v1.x(),v1.y(),v1.z(),v2.x(),v2.y(),v2.z(),v3.x(),v3.y(),v3.z() );
	
	C3dTriangle triangle ( v1, v2, v3, v_Zero,v_Zero,v_Zero, cl_Gray );
	
	if( !m_TextureFileName.isEmpty() )
	{
		C3dVector tV1,tV2,tV3;
		
		QImage img;
		qDebug() << PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName();
		if( img.load(PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName() ) &&
				  img.height() != 0 &&
				  img.width() != 0)
		{
	
// 			double x,y,l,h, factor;
// 			factor = 10;
			// 			
// 			x = img.width();
// 			y = img.height();
// 			l = getLength() * scale / factor;
// 			h = height / factor;
						
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
		else
		{
			qDebug() << "Textur " << PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName() + " konnte nicht geladen werden." << endl;
		}
	}
	
	
	triangles.append(triangle);
	
	
}



/*!
    \fn BB_TerrainTriangle::getClassName()
 */
const QString BB_TerrainTriangle::getClassName()
{
	return QString("BB_TerrainTriangle");
}
