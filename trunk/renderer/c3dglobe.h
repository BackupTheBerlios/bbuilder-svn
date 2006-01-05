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
#ifndef C3DGLOBE_H
#define C3DGLOBE_H

// #include <qwidget.h>
 #include <qcolor.h>
// #include "c3dvector.h"
// #include <GL/gl.h>
// #include <qimage.h>

#include "c3dbody.h"

/**
 * @author Alex Letkemann
 */
class C3dGlobe : public C3dBody{

private:
    
	C3dVector m_Position;

    double m_Radius;

    int m_Longitudes;
    int m_Latitudes;


public:
/**
 * Konstrucktor
 * Erzeugt eine Kudel mit dem Mittelpunkt an der Position x|y|z
 * @param Radius Radius der Kugel
 * @param Longitudes Anzahl der Längengrade. Standart ist 10
 * @param Latitudes Anzahl der Breitengrade. Standart ist 10
 *
 */
    C3dGlobe(C3dVector& pos, double Radius, int Longitudes, int Latitudes, CColorRGBA& color);

    ~C3dGlobe();

	virtual void makeSurface();
    C3dVector& getPosition( void );
    void setPosition(C3dVector& _pos);


};

#endif
