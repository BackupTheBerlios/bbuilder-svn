//
// C++ Implementation: br_camera
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "br_camera.h"

BR_Camera::BR_Camera()
{
	
	m_Aspect = 0.75;
	m_FoVY = 45.0;
	m_Far = 1000.0;
	m_Near = 0.1;
	
	m_Camera = C3dVector(0.0,3.0,-3.0);
	m_ViewPoint = v_Z;
	m_Up = v_Y;
	m_Strave = v_X;
}


BR_Camera::~BR_Camera()
{
}




/*!
    \fn BR_Camera::rotateY(double angle)
 */
void BR_Camera::rotateY(double angle)
{
	m_ViewPoint = m_ViewPoint.rotateVector(v_Y,angle).unitVector();
	m_Strave = m_Strave.rotateVector(v_Y,angle).unitVector();
	m_Up = m_Up.rotateVector(v_Y,angle).unitVector();
}


/*!
    \fn BR_Camera::rotateX(double angle)
 */
void BR_Camera::rotateX(double angle)
{
	m_ViewPoint = m_ViewPoint.rotateVector(m_Strave,angle).unitVector();
	m_Up = m_Up.rotateVector(m_Strave,angle).unitVector();
}


/*!
    \fn BR_Camera::apply()
 */
void BR_Camera::apply()
{
	
	m_tmpV1 = m_Camera + m_ViewPoint;
	
	
	glMatrixMode(GL_PROJECTION);
	
	glLoadIdentity();
	
	gluPerspective(m_FoVY,m_Aspect,m_Near,m_Far);
	
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	
	gluLookAt(m_Camera.x(),m_Camera.y(),m_Camera.z(),
			  m_tmpV1.x(),m_tmpV1.y(),m_tmpV1.z(),
			  m_Up.x(),m_Up.y(),m_Up.z());
}


/*!
    \fn BR_Camera::setAspect(double aspect)
 */
void BR_Camera::setAspect(double aspect)
{
	m_Aspect = aspect;
}


/*! 
    \fn BR_Camera::strafe(double speed)
 */
void BR_Camera::strafe(double speed)
{
	m_Camera = m_Camera + speed * m_Strave;
// 	m_ViewPoint = m_ViewPoint + speed * m_Strave;
}


/*!
    \fn BR_Camera::move(double speed)
 */
void BR_Camera::move(double speed)
{
	m_Camera = m_Camera + speed * m_ViewPoint;
}
