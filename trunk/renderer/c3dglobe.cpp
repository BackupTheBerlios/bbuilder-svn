/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann                                  *
 *   alex@linux                                                            *
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
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "c3dglobe.h"
#include "qwidget.h"
#include <math.h>
#include <qimage.h>
#include <iostream>
// #include <QtOpenGL>
using namespace std;

/**
 * Kontsrucktor
 * Erzeugt eine Kugel
 * @param pos Position des Mittelpunktes der Kugel
 * @param Radius Radius der Kugel
 * @param Longitudes Anzahl der Längengrade
 * @param Latitudes anzahl der Breitengrade
 */
C3dGlobe::C3dGlobe(C3dVector& pos, double Radius, int Longitudes=10, int Latitudes=10, CColorRGBA& color = cl_Blue)
{
	m_Position = pos;
	m_Radius = Radius;
	m_Longitudes = Longitudes;
	m_Latitudes = Latitudes;
	m_Color = color;
	m_Quads.resize(m_Longitudes * m_Latitudes);
	m_Triangles.resize(m_Longitudes * m_Latitudes);
	makeSurface();

}


C3dGlobe::~C3dGlobe()
{
}






/**
 * Zeichnet die Kugel
 */

void C3dGlobe::makeSurface()
{

	int quadsCount = 0;
	int triCount = 0;
	C3dVector v0;
	C3dVector v1;
	C3dVector v2;
	C3dVector v3;
	
	double latitude, longitude, sideLatitude, sideLongitude;
	
	long quads = (m_Longitudes - 2) * m_Latitudes;
	long quad = 0;
	
	sideLatitude = 360.0 / (double)m_Latitudes;
	sideLongitude = 180.0 / (double)m_Longitudes;
	
	for(int i = 0; i < m_Latitudes; i++)
	{
		latitude = ((360.0 / (double)m_Latitudes) * i) - 180.0;
		
		//m_Vector.setRadiusLongitudeLatitude(m_Radius, latitude, M_PI);
	
	
		for(int j = 1; j < m_Longitudes - 1 ; j++)
		{  
			longitude = ((180.0 / (double)m_Longitudes) * j)-90.0;
			
			//cout << "Generating Quad " << ++quad << " of " << quads << endl;
			
			v0.setRadiusLongitudeLatitude(m_Radius, latitude, longitude);
			v1.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude);
			v2.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude + sideLongitude);
			v3.setRadiusLongitudeLatitude(m_Radius, latitude, longitude + sideLongitude);
			
			m_Quads.insert(quadsCount++, new C3dQuad(v0+m_Position,v1+m_Position,v2+m_Position,v3+m_Position,
						   v0.unitVector(),v1.unitVector(),v2.unitVector(),v3.unitVector(),
						   v_X,v_X,v_X,v_X,m_Color));
	
		}
	}

	
	
	for(int i = 0; i < m_Latitudes; i++)
	{
		latitude = ((360.0 / (double)m_Latitudes) * i) - 180.0;
	
	

		longitude = ((180.0 / (double)m_Longitudes) * (m_Longitudes-1))-90.0;
			
		v0.setRadiusLongitudeLatitude(m_Radius, latitude, longitude);
		v1.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude);
		v2.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude + sideLongitude);
		v3.setRadiusLongitudeLatitude(m_Radius, latitude, longitude + sideLongitude);
		
		m_Triangles.insert(triCount++, new C3dTriangle(v0+m_Position,v1+m_Position,v3+m_Position,
					   v0.unitVector(),v1.unitVector(),v3.unitVector(),
					   v_X,v_X,v_X,m_Color));
		
		
		
		longitude = -90.0;
		
		v0.setRadiusLongitudeLatitude(m_Radius, latitude, longitude);
		v1.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude);
		v2.setRadiusLongitudeLatitude(m_Radius, latitude + sideLatitude, longitude + sideLongitude);
		v3.setRadiusLongitudeLatitude(m_Radius, latitude, longitude + sideLongitude);
		
		m_Triangles.insert(triCount++, new C3dTriangle(v0+m_Position,v2+m_Position,v3+m_Position,
						   v0.unitVector(),v2.unitVector(),v3.unitVector(),
						   v_X,v_X,v_X,m_Color));
	}

}



/**
 * Gibt die Position der Kugel zurück
 */
C3dVector& C3dGlobe::getPosition( void )
{
	return m_Position;
}


/** 
 * 
 */
void C3dGlobe::setPosition(C3dVector& _pos)
{
	if(&_pos != NULL)
	{
		m_Position = _pos;
	}
	else
	{
		cout << "NUll-Pointer bei C3dGlobe::setPosition()" << endl;
	}
}
