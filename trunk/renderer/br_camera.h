//
// C++ Interface: br_camera
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BR_CAMERA_H
#define BR_CAMERA_H

#include <c3dvector.h>
#include "3dmath.h"
#include <QtOpenGL>


/**
 * Berechnet die Bewegungen und die Perspektiven des Users.
 * Dabei kann der User die Kamera um die X- und die Y-Achse drehen aber nicht um die Z-Achse,
 * d.H. der User kann die Kamera nicht 'rollen'.
 * @author Alex Letkemann <alex@letkemann.de>
 **/
class BR_Camera{
public:
    BR_Camera();

    ~BR_Camera();

	void rotateY(double angle);
	void rotateX(double angle);
	void apply();
	void setAspect(double aspect);
	void strafe(double speed);
	void move(double speed);
	C3dVector getViewPoint();
	C3dVector getPos();
	void CheckCameraCollision(CVector3 *pVertices, int numOfVerts);

protected:	
	double m_Aspect;
	double m_FoVY;
	double m_Near;
	double m_Far;
	C3dVector m_ViewPoint;
	C3dVector m_Camera;
	
	CVector3   m_vPosition;
// 	CVector3   m_vView;
	float m_Radius;
	
	C3dVector m_Strave;
	C3dVector m_Up;

	/* Vektoren für Zwischenwerte */
	C3dVector m_tmpV1;
	C3dVector m_tmpV2;
	C3dVector m_tmpV3;
	
};

#endif
