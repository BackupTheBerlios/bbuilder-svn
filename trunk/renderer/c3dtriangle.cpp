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
#include "c3dtriangle.h"

 
/**
 * Standard Konstruktor
 * Erstellt einen Dreieck mit den Eckkoordinaten 0|0|0 - 1|1|1 - 1|0|1
 */
C3dTriangle::C3dTriangle(): C3dLine()
{
	m_V2.setX(1.0);
	m_V2.setY(0.0);
	m_V2.setZ(1.0);
	
	m_VN0 = (m_V0 - m_V1).getNormalVector(m_V1 - m_V2).unitVector();
	m_VN1 = (m_V1 - m_V2).getNormalVector(m_V2 - m_V0).unitVector();
	m_VN2 = (m_V2 - m_V0).getNormalVector(m_V0 - m_V1).unitVector();
	
	m_ClassEnum = GL_TRIANGLES;
}

/**
 * Konstruktor
 * Erstellt einen Dreieck aus den angegebenen Parametern
 */
C3dTriangle::C3dTriangle(	const C3dVector& v0,
							const C3dVector& v1,
							const C3dVector& v2,
							const C3dVector& t0,
							const C3dVector& t1,
							const C3dVector& t2,
							const CColorRGBA& color): C3dLine(v0, v1, v_X, v_X, t0, t1, color)
{
	if(	&v2 != NULL &&
	  	&t2 != NULL)
	{
		m_V2 = v2;
		
		m_VN0 = (m_V0 - m_V1).getNormalVector(m_V1 - m_V2);
		m_VN1 = (m_V1 - m_V2).getNormalVector(m_V2 - m_V0);
		m_VN2 = (m_V2 - m_V0).getNormalVector(m_V0 - m_V1);
		m_VTex2 = t2;
		
		m_ClassEnum = GL_TRIANGLES;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::C3dTriangle(...)" << endl;
	}
}


C3dTriangle::C3dTriangle(	const C3dVector& v0,
							const C3dVector& v1,
							const C3dVector& v2,
							const C3dVector& n0,
							const C3dVector& n1,
							const C3dVector& n2,
							const C3dVector& t0,
							const C3dVector& t1,
							const C3dVector& t2,
							const CColorRGBA& color): C3dLine(v0, v1, n0, n1, t0, t1, color)
{
	if(	&v2 != NULL &&
		&n2 != NULL &&
		&t2 != NULL)
	{
		m_V2 = v2;
		
		//m_VN0 = n0;
		//m_VN1 = n1;
		m_VN2 = n2;
		m_VTex2 = t2;
		
		m_ClassEnum = GL_TRIANGLES;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::C3dTriangle(...)" << endl;
	}
}


/**
 * Konstruktor
 * Erstellt aus den drei angegebenen Punkten einen Dreieck
 */
C3dTriangle::C3dTriangle(C3dPoint& p1, C3dPoint& p2, C3dPoint& p3, CColorRGBA& color): C3dLine(p1, p2, color)
{
	if(&p3 != NULL)
	{
		m_V2 = p3.getV0();
		
		m_VN0 = (m_V0 - m_V1).getNormalVector(m_V1 - m_V2);
		m_VN1 = (m_V1 - m_V2).getNormalVector(m_V2 - m_V0);
		m_VN2 = (m_V2 - m_V0).getNormalVector(m_V0 - m_V1);
		
		m_VTex2 = p3.getVTex0();
		
		m_ClassEnum = GL_TRIANGLES;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::C3dTriangle(...)" << endl;
	}
}


C3dTriangle::~C3dTriangle()
{

}

/** Returns the GL_XXX constant that has to be used with glBegin to draw the object. e.g. GL_TRIANGLES
 */
GLenum C3dTriangle::getClassEnum() const
{
    return m_ClassEnum;
}

/** Contains the vertex, normal and texture calls  that draw the primitive.
 */
void C3dTriangle::draw() const
{
    C3dLine::draw();
	
	glNormal3dv(m_VN2.dv());
	glTexCoord2dv(m_VTex2.dv()); 
	m_V2.vertex();
}

/** Contains the vertex calls for drawing the normals.
 */
void C3dTriangle::drawNormals() const
{
    C3dLine::drawNormals();
	m_V2.vertex();
	(m_V2 + m_VN2).vertex();
}

/** Moves the line by vMove.
 */
void C3dTriangle::moveBy(const C3dVector& vMove)
{
	if(&vMove != NULL)
	{ 
		C3dLine::moveBy(vMove);
		m_V2 = m_V2 + vMove;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::moveBy(...)" << endl;
	}
}

/** Rotates the line around the origin.
 */
void C3dTriangle::rotate(const C3dVector& vAxis, double Angle)
{
	if(&vAxis != NULL)
	{
		C3dLine::rotate(vAxis, Angle);
		m_V2 = m_V2.rotateVector(vAxis, Angle);
		m_VN2 = m_VN2.rotateVector(vAxis, Angle);
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::rotate(...)" << endl;
	}
}

/** Stretches by sx,sy,sz. Calls stretchVector.
 */
void C3dTriangle::stretch(double sx, double sy, double sz)
{
    C3dLine::stretch(sx, sy, sz);
	m_V2 = m_V2.stretchVector(sx,sy,sz);
}

/**
 * Kopierfunktion
 */
void C3dTriangle::copy(const C3dTriangle& toCopy)
{
	if(&toCopy != NULL)
	{
		C3dLine::copy(toCopy);
		
		m_V2 = toCopy.getV2();
		m_VN2 = toCopy.getVN2();
		m_VTex2 = toCopy.getVTex2();
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::copy(...)" << endl;
	}
}



/**
 * Gibt den V2 zurück
 */
const C3dVector& C3dTriangle::getV2() const
{
	return m_V2;
}


/**
 * Gibt den VN2 zurück
 */
const C3dVector& C3dTriangle::getVN2() const
{
	return m_VN2;
}


/**
 * Gibt den VTex2 zurück
 */
const C3dVector& C3dTriangle::getVTex2() const
{
	return m_VTex2;
}


/**
 *  Setzt den VN2
 */
void C3dTriangle::setVN2(const C3dVector& _newVal)
{
	if(&_newVal != NULL)
	{
		m_VN2 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::setVN2(...)" << endl;
	}
}


/**
 * Setzt den VTex2
 */
void C3dTriangle::setVTex2(const C3dVector& _newVal)
{

	if(&_newVal != NULL)
	{
		m_VTex2 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::setVTex2(...)" << endl;
	}
}


/**
 * Setzt den V2
 */
void C3dTriangle::setV2(const C3dVector& _newVal)
{

	if(&_newVal != NULL)
	{
		m_V2 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei C3dTriangle::setV2(...)" << endl;
	}
}


/**!
 * Zeichnet das Dreieck
 */
void C3dTriangle::show() const
{
	glColor3fv(m_Color.fv());
	glBegin( GL_TRIANGLES );
	draw();
	glEnd();
}
