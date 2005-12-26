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
#ifndef C3DLINE_H
#define C3DLINE_H

#include <c3dpoint.h>
#include <iostream>


using namespace std;

/**
 * Stellt eine drei-dimensionale Linie dar.
 *@author Alex Letkemann
 */
class C3dLine : public C3dPoint
{
public:
	

    C3dLine();

    ~C3dLine();
    virtual const C3dVector& getV1 () const;
    virtual const C3dVector& getVN1 () const;
    virtual const C3dVector& getVTex1 () const;
    virtual void setV1 ( const C3dVector& _newVal );
    virtual void setVN1 ( const C3dVector& _newVal );
    virtual void setVTex1 ( const C3dVector& _newVal );
    virtual void draw ();
    virtual void drawNormals ();
    virtual void moveBy (const C3dVector &vMove);
    virtual void rotate (const C3dVector &vAxis, double Angle);
    virtual void stretch (double sx, double sy, double sz);
    void copy ( const C3dLine& toCopy);
	C3dLine(const C3dVector& v0, const C3dVector& v1, const C3dVector& n0, const C3dVector& n1, const C3dVector& t0 = v_Zero, const C3dVector& t1 = v_Zero, const CColorRGBA& color = cl_Red);
     C3dLine(C3dPoint& p1, C3dPoint& p2, CColorRGBA& color);
    virtual GLenum getClassEnum()const;
	
protected:
	
	/** Ortsvector des zweiten Vertex der Linie */
	C3dVector m_V1;
	
	/** Normalvektor für den zweiten Vertex */
	C3dVector m_VN1;

	/** Texturkoordinaten für den zweiten Vertex der Linie */
	C3dVector m_VTex1;
};

#endif
