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
#include "c3dcylinder.h"

/**
 * Erzeugt einen Zylinder
 * @param pos des Anfanges der Achse des Zylinders. Der Zylinder wird wird in richtung Z-Achse geziechnet
 * @param radius Radius des Zylinders
 * @param height Höhe des Zylinders in die Z-Richtung
 * @param sides Anzahl der Seitenlächen
 *
 */
C3dCylinder::C3dCylinder(double radius, double height, unsigned int sides)
 : C3dBody()
{

	m_Radius = radius;
	m_Height = height;
	m_Sides = sides;
	
	makeSurface();
}
 

C3dCylinder::~C3dCylinder()
{
}

void C3dCylinder::makeSurface()
{
	int triCount = 0;
	int quadCount = 0;
	C3dVector tmp;
	
	C3dVector v0;
	C3dVector v1;
	C3dVector v2;
	C3dVector v3;
	C3dVector v4;
	C3dVector n0;
	C3dVector n1;
	
	double side = 360.0 / (double)m_Sides;
	
	for(unsigned int i = 0; i < m_Sides; i++)
	{
		tmp.setRadiusLongitudeLatitude(m_Radius, side * i, 0 );
		v1.setX(tmp.x());
		v1.setY(tmp.z());
		
		tmp.setRadiusLongitudeLatitude(m_Radius, side * (i + 1), 0);
		v2.setX(tmp.x());
		v2.setY(tmp.z());
		
		v4 = v1;
		v3 = v2;
		v0.setZ(0.0);
		
		m_Triangles.insert(triCount++, new C3dTriangle(v0,v1,v2,v_X,v_X,v_X,cl_Blue));
		
		v3.setZ(v3.z() + m_Height);
		v4.setZ(v4.z() + m_Height);
		v0.setZ(m_Height);
		m_Triangles.insert(triCount++, new C3dTriangle(v3,v4,v0,v_X,v_X,v_X,cl_Blue));
		
		n0 = (v1);
		n1 = (v2);
		
		m_Quads.insert(quadCount++,new C3dQuad(v4,v3,v2,v1,n0.unitVector(),n1.unitVector(),n1.unitVector(),n0.unitVector(),v_X,v_X,v_X,v_X,cl_Blue));
		
	}
}
