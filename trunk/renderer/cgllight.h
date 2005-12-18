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
#ifndef CGLLIGHT_H
#define CGLLIGHT_H

#include "ccolorrgba.h"
#include "c3dvector.h"
#include "c3dglobe.h"
#include "GL/gl.h"

/**
@author Alex Letkemann
*/
class CGLLight{
public:
    CGLLight();
    CGLLight(C3dVector& pos, CColorRGBA& ambient, CColorRGBA& diffuse, CColorRGBA& specular, double brightness, bool directional);

    ~CGLLight();
    bool isOn(void) const;
    void switchOff(void);
    void switchOn(void);
	bool isDirectional() const;
	C3dVector getPosition() const;
	CColorRGBA getAmbientColor() const;
	CColorRGBA getDiffuseColor() const;
	CColorRGBA getSpecularColor() const;
	double getBrightness() const;
    void moveBy(const C3dVector& move);
    void setAmbientColor(const CColorRGBA& _color);
    void setBrightness(const double _brightness);
    void setDiffuseColor(const CColorRGBA& _color);
    void setSpecularColor(const CColorRGBA& _color);
	void setPosition(const C3dVector& _pos);
    void show();

protected:
	CColorRGBA m_AmbientColor;
	CColorRGBA m_DiffuseColor; 
	CColorRGBA m_SpecularColor;
	
	bool m_Directional;
	bool m_On;
	
	GLenum m_LightNumber;
	
	double m_Brightness;
	C3dVector m_Position;
	C3dGlobe *m_Globe;
 
private:
    static GLenum m_ClassLightNumber;
};

#endif
