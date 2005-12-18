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
#include "cgllight.h"
#include "iostream"

using namespace std;

/** Statischer Instanzzähler für die automatische Nummernverwaltung */
GLenum CGLLight::m_ClassLightNumber = 0;


/** 
 * Konstrucktor
 * Erstellt eine nicht directionale, weiße Lichtquelle an den Koordinaten 0|5|0.
 */
CGLLight::CGLLight()
{
	m_LightNumber = m_ClassLightNumber++;	// Lichtnummer zuweisen
	
	m_Directional = false;
	m_Brightness = 1.0;
	m_Position = v_Zero;
		
	setAmbientColor(cl_Black);
	setDiffuseColor(cl_Black);
	setSpecularColor(cl_Black);
	
	m_Globe = new C3dGlobe(m_Position,0.1,3,5,cl_White);
	
}


/**
 * Konstrucktor
 * Erstellt eine Lichquelle mit den angegebenen Parametern
 * @param pos Position der Lichtquelle
 * @param ambient Ambient-Farbe der Lichtquelle
 * @param diffuse Diffuse-Farbe der Lichquelle
 * @param specular Specular-Farbe der Lichquelle
 * @param brightness Heligkeit der Lichquelle. Standard 1.0
 * @param directional Art der Lichquelle. Standard false (nicht directional).
 * */
CGLLight::CGLLight(C3dVector& pos,
				   CColorRGBA& ambient,
				   CColorRGBA& diffuse,
				   CColorRGBA& specular,
				   double brightness = 1.0,
				   bool directional = false)
{
	m_LightNumber = m_ClassLightNumber++;	// Lichtnummer zuweisen
	
	
	m_Directional = directional;			// Muss vor setPosition gesetzt werden!
	m_Brightness = brightness;
	m_Position = pos;
	
	setAmbientColor(ambient);
	setDiffuseColor(diffuse);
	setSpecularColor(specular);

	m_Globe = new C3dGlobe(m_Position,0.1,3,5,cl_White);
}



CGLLight::~CGLLight()
{
}




/**
 * Gibt den Status der Lichtquelle zurück
 */
bool CGLLight::isOn(void) const
{
	return m_On;
}


/**
 * Schaltet die Lichtquelle aus
 */
void CGLLight::switchOff(void)
{
	glDisable(GL_LIGHT0 + m_LightNumber);
	m_On = false;
}


/**
 * Schaltet die Lichquelle ein
 */
void CGLLight::switchOn(void)
{
	

	GLfloat pos[4];
	pos[0] = m_Position.x(); pos[1] = m_Position.y(); pos[2] = m_Position.z();
	
	if(isDirectional())
		pos[3] = 0.0; // 0 is a flag for directional light (like the sun)
	else pos[3] =1.0; // 1 is a positional light (like a lamp)
	
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_POSITION, pos);
	
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_AMBIENT, (m_AmbientColor * m_Brightness).fv());
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_DIFFUSE, (m_DiffuseColor * m_Brightness).fv());
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_SPECULAR, (m_SpecularColor * m_Brightness).fv());

	glEnable(GL_LIGHT0 + m_LightNumber);
	
	m_On = true;
	
// 	cout << "LichtNr: " << GL_LIGHT0 + m_LightNumber << " eigeschaltet" << endl;
}


/**
 * Zeigt an, ob es sich die Lichtquelle in unendlicher Entfernung befindet
 */
bool CGLLight::isDirectional() const
{
	return m_Directional;
}


/**
 * Gibt die Position der Lichtquelle Zurück
 */
C3dVector CGLLight::getPosition() const
{
	return m_Position;
}


/**
 * Gibt die Ambient-Farbe der Lichtquelle zurück
 */
CColorRGBA CGLLight::getAmbientColor() const
{
	return m_AmbientColor;
}


/** 
 * Gibt die Diffuse-Farbe der Lichtquelle zurück
 */
CColorRGBA CGLLight::getDiffuseColor() const
{
	return m_DiffuseColor;
}


/**
 * Gibt die Specular-Farbe der Lichtquelle zurück
 */
CColorRGBA CGLLight::getSpecularColor() const
{
	return m_SpecularColor;
}


/*!
 * Gibt die Helligkeit der Lichtquelle zurück
 */
double CGLLight::getBrightness() const
{
	return m_Brightness;
}


/**
 * Setzt die Position der Lichtquelle
 */
void CGLLight::setPosition(const C3dVector& _pos)
{
	GLfloat pos[4];
	m_Position = _pos;
	pos[0] = m_Position.x(); pos[1] = m_Position.y(); pos[2] = m_Position.z();
	//copy position
	if(isDirectional())
		pos[3] = 0.0; // 0 is a flag for directional light (like the sun)
	else pos[3] =1.0; // 1 is a positional light (like a lamp)
	m_Globe->setPosition(m_Position);
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_POSITION, pos);
}


/*!
 * Bewegt die Lichtquelle mit Vector move
 */
void CGLLight::moveBy(const C3dVector& move)
{
	setPosition(m_Position + move);
	m_Globe->moveBy(move);
}


/**
 * Setzt die Ambient-Farbe der Lichtquelle
 */
void CGLLight::setAmbientColor(const CColorRGBA& _color)
{
	m_AmbientColor = _color;
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_AMBIENT, (m_AmbientColor * m_Brightness).fv());
}


/**
 * Setzt die Diffuse-Farbe der Lichtquelle
 */
void CGLLight::setDiffuseColor(const CColorRGBA& _color)
{
	m_DiffuseColor = _color;
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_DIFFUSE, (m_DiffuseColor * m_Brightness).fv());
}



/**
 * Setzt die Specular-Farbe der Lichtquelle
 */
void CGLLight::setSpecularColor(const CColorRGBA& _color)
{
	m_SpecularColor = _color;
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_SPECULAR, (m_SpecularColor * m_Brightness).fv());

}


/*!
 * Setzt die Helligkeit der Lichtquelle
 */
void CGLLight::setBrightness(const double _brightness)
{
	m_Brightness = _brightness;
	
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_AMBIENT, (m_AmbientColor * m_Brightness).fv());
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_DIFFUSE, (m_DiffuseColor * m_Brightness).fv());
	glLightfv(GL_LIGHT0 + m_LightNumber, GL_SPECULAR, (m_SpecularColor * m_Brightness).fv());
}



/**
 * Zeichnet eine Weise Kugel an der Position der Lichtquelle
 */
void CGLLight::show()
{
	glDisable(GL_LIGHTING);

	m_Globe->show();

	glEnable(GL_LIGHTING);
}
