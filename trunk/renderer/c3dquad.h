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
#ifndef C3DQUAD_H
#define C3DQUAD_H

#include <c3dtriangle.h>

/**
@author Alex Letkemann
*/
class C3dQuad : public C3dTriangle
{
public:
    C3dQuad();
	C3dQuad(	const C3dVector& v0, 
				const C3dVector& v1,
				const C3dVector& v2,
				const C3dVector& v3,
				const C3dVector& t0,
				const C3dVector& t1,
				const C3dVector& t2,
				const C3dVector& t3,
				const CColorRGBA& color);

	C3dQuad(	const C3dVector& v0, 
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
				const CColorRGBA& color);
	
    C3dQuad(C3dPoint& p1, C3dPoint& p2, C3dPoint& p3, C3dPoint& p4, CColorRGBA& color);

    ~C3dQuad();

	virtual const C3dVector& getV3() const;
	virtual const C3dVector& getVN3() const;
	virtual const C3dVector& getVTex3() const;
    virtual GLenum getClassEnum() const;
    virtual void draw() const;
    virtual void drawNormals() const;
    virtual void moveBy(const C3dVector& vMove);
    virtual void rotate(const C3dVector& vAxis, double Angle);
    virtual void setV3(const C3dVector& _newVal);
    virtual void setVN3(const C3dVector& _newVal);
    virtual void setVTex3(const C3dVector& _newVal);
    virtual void stretch(double sx, double sy, double sz);
    void copy(const C3dQuad& toCopy);
    bool checkPlanarity();
	
protected:
	C3dVector m_V3;
	C3dVector m_VN3;
	C3dVector m_VTex3;
	

};

#endif
