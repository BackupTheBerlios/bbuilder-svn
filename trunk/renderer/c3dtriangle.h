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
#ifndef C3DTRIANGLE_H
#define C3DTRIANGLE_H

#include <c3dline.h>

/**
@author Alex Letkemann
*/
class C3dTriangle : public C3dLine
{
public:
    C3dTriangle();
    
	C3dTriangle(	const C3dVector& v0,
					const C3dVector& v1,
					const C3dVector& v2,
					const C3dVector& t0,
					const C3dVector& t1,
					const C3dVector& t2,const CColorRGBA& color);
	
	
	C3dTriangle(	const C3dVector& v0,
					const C3dVector& v1,
					const C3dVector& v2,
					const C3dVector& n0,
					const C3dVector& n1,
					const C3dVector& n2,
					const C3dVector& t0,
					const C3dVector& t1,
					const C3dVector& t2,const CColorRGBA& color);
    
    C3dTriangle(C3dPoint& p1, C3dPoint& p2, C3dPoint& p3, CColorRGBA& color);

    ~C3dTriangle();

	virtual GLenum getClassEnum() const;
    virtual void draw();
    virtual void drawNormals();
    virtual void moveBy(const C3dVector& vMove);
    virtual void rotate(const C3dVector& vAxis, double Angle);
    virtual void stretch(double sx, double sy, double sz);
	void copy(const C3dTriangle& toCopy);
    virtual const C3dVector& getV2() const;
	virtual const C3dVector& getVN2() const;
	virtual const C3dVector& getVTex2() const;
    virtual void setVN2(const C3dVector& _newVal);
    virtual void setVTex2(const C3dVector& _newVal);
    virtual void setV2(const C3dVector& _newVal);
	
protected:
	C3dVector m_V2;
	C3dVector m_VN2;
	C3dVector m_VTex2;
	
};

#endif
