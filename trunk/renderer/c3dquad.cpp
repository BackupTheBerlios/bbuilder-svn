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
#include "c3dquad.h"

C3dQuad::C3dQuad(): C3dTriangle()
{
	
// 	m_VN0 = (m_V0 - m_V1).getNormalVector(m_V1 - m_V2).unitVector();
// 	m_VN1 = (m_V1 - m_V2).getNormalVector(m_V2 - m_V3).unitVector();
// 	m_VN2 = (m_V2 - m_V3).getNormalVector(m_V3 - m_V0).unitVector();
// 	m_VN3 = (m_V3 - m_V0).getNormalVector(m_V0 - m_V1).unitVector();
	// TODO

}


/**
 * Konstruktor 
 * Erstellt einen Quad aus den Apgegebenen Vectoren
 */
C3dQuad::C3dQuad(	const C3dVector& v0,
					const C3dVector& v1,
					const C3dVector& v2,
					const C3dVector& v3,
					const C3dVector& t0,
					const C3dVector& t1,
					const C3dVector& t2,
					const C3dVector& t3,
					const CColorRGBA& color): C3dTriangle(v0, v1, v2, v_Zero,v_Zero,v_Zero, t0, t1, t2, color)
{
	if(	&v3 != NULL &&
	  	&t3 != NULL)
	{
		m_V3 = v3;
	
		m_VN0 = (v0 - v1).getNormalVector(v1 - v2);
		m_VN1 = (v1 - v2).getNormalVector(v2 - v3);
		m_VN2 = (v2 - v3).getNormalVector(v3 - v0);
		m_VN3 = (v3 - v0).getNormalVector(v0 - v1);
		
		m_VTex3 = t3;
		
		if(!checkPlanarity())
			cout << "C3dQuad: Nicht alle Punkte liegen auf einer Ebene" << endl;
		
		m_ClassEnum = GL_QUADS;
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::C3dQuad(...)" << endl;
	}
}
 
C3dQuad::C3dQuad(	const C3dVector& v0,
					const C3dVector& v1,
					const C3dVector& v2,
					const C3dVector& v3,
					const C3dVector& n0,
					const C3dVector& n1,
					const C3dVector& n2,
					const C3dVector& n3,
					const C3dVector& t0,
					const C3dVector& t1,
					const C3dVector& t2,
					const C3dVector& t3,
					const CColorRGBA& color): C3dTriangle(v0, v1, v2, n0, n1, n2, t0, t1, t2, color)
{
	if(	&v3 != NULL &&
		&n3 != NULL &&
		&t3 != NULL)
	{
		m_V3 = v3;
	
		m_VN0 = n0;
		m_VN1 = n1;
		m_VN2 = n2;
		m_VN3 = n3;
		
		m_VTex3 = t3;
		
		//if(!checkPlanarity())
		//	cout << "C3dQuad: Nicht alle Punkte liegen auf einer Ebene" << endl;
		
		m_ClassEnum = GL_QUADS;
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::C3dQuad(...)" << endl;
	}
}

/**
 * Konstruktor
 * Erstellt einen Quad aus den vier angegebenen Punkten
 * Die Punkte werden gegen den Uhrzeigersinn angegeben.
 */
C3dQuad::C3dQuad(C3dPoint& p1, C3dPoint& p2, C3dPoint& p3, C3dPoint& p4, CColorRGBA& color): C3dTriangle(p1, p2, p3, color)
{
	if(&p3 != NULL)
	{
		m_V3 = p4.getV0();
		
		m_VN0 = (m_V0 - m_V1).getNormalVector(m_V1 - m_V2);
		m_VN1 = (m_V1 - m_V2).getNormalVector(m_V2 - m_V3);
		m_VN2 = (m_V2 - m_V3).getNormalVector(m_V3 - m_V0);
		m_VN3 = (m_V3 - m_V0).getNormalVector(m_V0 - m_V1);
		
		m_VTex3 = p4.getVTex0();
		
		m_ClassEnum = GL_QUADS;
		
		//if(!checkPlanarity())
		//	cout << "C3dQuad: Nicht alle Punkte liegen auf einer Ebene" << endl;
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::C3dQuad(...)" << endl;
	}
}

/** Destruktor
 */
C3dQuad::~C3dQuad()
{
	m_ClassEnum = 0;
}

/** Gibt V3 zurück
 */
const C3dVector& C3dQuad::getV3() const
{
	return m_V3;
}

/** Gibt VN3 zurück;
 */
const C3dVector& C3dQuad::getVN3() const
{
	return m_VN3;
}

/** Gibt VTex3 zurück;
 */
const C3dVector& C3dQuad::getVTex3() const
{
	return m_VTex3;
}

/** Gibt das ClassenEnum zurück
 */
GLenum C3dQuad::getClassEnum() const
{
	return m_ClassEnum;
}

/** Enthält die Vertex Aufruffe für das Objekt
 */
void C3dQuad::draw() const
{
    C3dTriangle::draw();
	
	glNormal3dv(m_VN3.dv());
	m_V3.vertex();
}

/** Enthält Vertex aufruffe für die Normalvektoren
 */
void C3dQuad::drawNormals() const
{
    C3dTriangle::drawNormals();
	m_V3.vertex();
	(m_V3 + m_VN3).vertex();
}

/** Bewegt das Objekt um vMove
 */
void C3dQuad::moveBy(const C3dVector& vMove)
{
	if(&vMove != NULL)
	{
		C3dTriangle::moveBy(vMove);
		m_V3 = m_V3 + vMove;
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::moveBy(...)" << endl;
	}
}

/**
 * Rotiert das Objekt 
 */
void C3dQuad::rotate(const C3dVector& vAxis, double Angle)
{
	if(&vAxis != NULL)
	{
		m_V3 = m_V3.rotateVector(vAxis,Angle);
		m_VN3 = m_VN3.rotateVector(vAxis,Angle);
		C3dTriangle::rotate(vAxis, Angle);
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::rotate(...)" << endl;
	}
}

/** Setzt V3
 */
void C3dQuad::setV3(const C3dVector& _newVal)
{
	if(&_newVal != NULL)
	{
		m_V3 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei setV3" << endl;
	}
}

/** Setzt VN3
 */
void C3dQuad::setVN3(const C3dVector& _newVal)
{
	if(&_newVal != NULL)
	{
		m_VN3 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei setVN3" << endl;
	}
}

/**
 * Setzt VTex3
 */
void C3dQuad::setVTex3(const C3dVector& _newVal)
{
	if(&_newVal != NULL)
	{
		m_VTex3 = _newVal;
	}
	else
	{
		cout << "NULL-Pointer bei setVTex3" << endl;
	}
}

/**
 * Stretch Funktion
 */
void C3dQuad::stretch(double sx, double sy, double sz)
{
    C3dTriangle::stretch(sx, sy, sz);
	m_V3 = m_V3.stretchVector(sx,sy,sz);
}

/**
 * Kopierfunktion für = Operator und Kopier-Konstrucktor
 */
void C3dQuad::copy(const C3dQuad& toCopy)
{
	if(&toCopy != NULL)
	{
		C3dTriangle::copy(toCopy);
		m_V3 = toCopy.getV3();
		m_VN3 = toCopy.getVN3();
		m_VTex3 = toCopy.getVTex3();
	}
	else
	{
		cout << "NULL-Pointer bei C3dQuad::copy(...)" << endl;
	}
}



/**
 * Überprüft, ob alle Punkte des Vierecks auf des selber Ebene liegen
 */
bool C3dQuad::checkPlanarity()
{
	return (m_VN0 == m_VN2 && m_VN1 == m_VN3); //TODO
}
