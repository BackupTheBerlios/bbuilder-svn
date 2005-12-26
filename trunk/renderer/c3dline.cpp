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
#include "c3dline.h"


/** 
 * Standard Konstrucktor
 * Erstellt eine Linie von 0|0|0 bis 1|1|1
 **/
C3dLine::C3dLine()
 : C3dPoint()
{
	m_V1.setX(1.0);
	m_V1.setY(1.0);
	m_V1.setZ(1.0);
	
	m_ClassEnum = GL_LINES;
}

/**
 * Konstruktor
 * Erstellt aus den Eingegebenen Vectoren eine Linie
 */
C3dLine::C3dLine(	const C3dVector& v0,
					const C3dVector& v1,
					const C3dVector& n0,
					const C3dVector& n1,
					const C3dVector& t0,
					const C3dVector& t1,
					const CColorRGBA& color)
	:C3dPoint(v0,n0,t0,color)
{
	if(	&v1 != NULL &&
		&n1 != NULL &&
	  	&t1 != NULL)
	{
		m_V1 = v1;
		m_VN1 = n1;
		m_VTex1 = t1;
		
		m_ClassEnum = GL_LINES;
	}
	else
	{
		cout << "NULL-Pointer bei C3dLine::C3dLine(...)" << endl;
	}
}


/**
 * Konstruktor
 * Erstellt aus zwei Punkten eine Linie
 */
C3dLine::C3dLine(C3dPoint& p1, C3dPoint& p2, CColorRGBA& color)
	: C3dPoint(p1)
{
	if(&p2 != NULL && &color != NULL)
	{
		m_V1 = p2.getV0();
		m_VN1 = p2.getVN0();
		m_VTex1 = p2.getVTex0();
		
		m_Color = color;
		m_ClassEnum = GL_LINES;
	}
	else
	{
		cout << "NULL-Objekt in C2dLine-Konstruktor" << endl;
	}
}

/**
 * Destruktor
 *
 */
C3dLine::~C3dLine()
{
}


/**
 * Gibt V1 zurück
 */
const C3dVector& C3dLine::getV1 () const
{
	return m_V1;
}


/**
 * Gibt den Normalvector des V1 zurück
 */
const C3dVector& C3dLine::getVN1 () const
{
	return m_VN1;
}


/**
 * Gibt die Texturkoordinaten des V1 zurück
 */
const C3dVector& C3dLine::getVTex1 () const
{
	return m_VTex1;
}


/**
 * Setzt den V1
 */
void C3dLine::setV1 ( const C3dVector& _newVal )
{
	if(&_newVal != NULL)
	{
		m_V1 = _newVal;
	}
	else
	{
		cout << "NULL-Parameter bei setV1" << endl;
	}
}


/**
 * Setzt den Normalvector des V1
 */
void C3dLine::setVN1 ( const C3dVector& _newVal )
{
	if(&_newVal != NULL)
	{
		m_VN1 = _newVal;
	}
	else
	{
		cout << "NULL-Parameter bei setVN1" << endl;
	}
}


/**
 * Setzt die Texturkoordianten des V1
 */
void C3dLine::setVTex1 ( const C3dVector& _newVal )
{
	if(&_newVal == NULL)
	{
		m_VTex1 = _newVal;
	}
	else
	{
		cout << "NULL-Parameter bei setVTex1" << endl;
	}
}


/** Contains the vertex, normal and texture calls  that draw the primitive.
*/
void C3dLine::draw ()
{
	C3dPoint::draw();
	
	glNormal3dv(m_VN1.dv());
	glTexCoord2dv(m_VTex1.dv()); 
	m_V1.vertex();
}

/** Contains the vertex calls for drawing the normals.
*/
void C3dLine::drawNormals ()
{
	C3dPoint::drawNormals();
	m_V1.vertex();
	(m_V1 + m_VN1).vertex();
}


/** Moves the line by vMove.
*/
void C3dLine::moveBy (const C3dVector &vMove)
{
	if(&vMove != NULL)
	{
		C3dPoint::moveBy(vMove);
		m_V1 = m_V1 + vMove;
	}
	else
	{
		cout << "NULL-Pointer in C3dLine::moveBy(...)" << endl;
	}
}


/** Rotates the line around the origin.
 */
void C3dLine::rotate (const C3dVector &vAxis, double Angle)
{
	if(&vAxis != NULL)
	{
		C3dPoint::rotate(vAxis,Angle);
		m_V1 = m_V1.rotateVector(vAxis,Angle);
		m_VN1 = m_VN1.rotateVector(vAxis, Angle);
	}
	else
	{
		cout << "NULL-Pointer in C3dLine::rotate(...)" << endl;
	}
}


/** Stretches by sx,sy,sz. Calls stretchVector.
*/
void C3dLine::stretch (double sx, double sy, double sz)
{
	C3dPoint::stretch(sx,sy,sz);
	m_V1 = m_VN1.stretchVector(sx,sy,sz);
}

/** Copy function for operator = and copy constructor.
 */
void C3dLine::copy ( const C3dLine& toCopy)
{
	if(&toCopy != NULL)
	{
		C3dPoint::copy(toCopy);
	
		m_V1 = toCopy.getV1();
		m_VN1 = toCopy.getVN1();
		m_VTex1 = toCopy.getVTex1();
	}
	else
	{
		cout << "NULL-Pointer in C3dLine::copy(...)" << endl;
	}
}

/** Returns the GL_XXX constant that has to be used with glBegin to draw the object. e.g. GL_TRIANGLES
 */
GLenum C3dLine::getClassEnum()const
{
	return m_ClassEnum;
}
