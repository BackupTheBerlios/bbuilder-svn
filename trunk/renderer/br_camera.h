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
 * @author Alex Letkemann <alex@letkemann.de>, Vaceslav Ustinov
 **/
class BR_Camera{
public:
    /**
     * Konstruktor
     * @author Alex Letkemann
     */
    BR_Camera();

	/**
	 * Destruktor
	 */
    ~BR_Camera();

	/**
	 * Rotiert die Kamera um die Y-Achse um den angegebenen Winkel
	 * @param angle Winkel
	 * @author Alex Letkemann
	 */
	void rotateY(double angle);
	
	/**
	 * Rotiert die Kamera um die X-Achse um den angegebenen Winkel
	 * @param angle Winkel
	 * @author Alex Letkemann
	 */
	void rotateX(double angle);
	
	/**
	 * Erstellt die Pespektive.
	 * Führ die OpenGl operationen aus.
	 * @author Alex Letkemann
	 */
	void apply();
	
	
	/**
	 * Setzt den Aspekt
	 * @param aspect Aspekt zwischen der Höhe und der Breite des Fensters.
	 * @author Alex Letkemann
	 */
	void setAspect(double aspect);
	
	
	/**
	 * Bewegt die Kamera seitwärts.
	 * Positive Geschwindigkeit bewegt die Kamera rechts, negative Links.
	 * @param speed Geschwindigkeit.
	 * @author Alex Letkemann
	 */
	void strafe(double speed);
	
	/**
	 * Bewegt die Kamera nach vonr und zurück.
	 * Positive Geschwindigkeit bewegt die Kamera vor, negative zurück.
	 * @param speed Geschwindigkeit.
	 * @author Alex Letkemann
	 */
	void move(double speed);
	
	
	/**
	 * Geibt den Punkt zurück, auf den die Kamera gerichtet ist.
	 * @return Punkt, auf den die Kamera gerichtet ist.
	 * @author Alex Letkemann
	 */
	C3dVector getViewPoint();
	
	
	/**
	 * Gibt die Position der Kamera zurück.
	 * @return Position der Kamera.
	 * @author Alex Letkemann
	 */
	C3dVector getPos();
	
	
	/**
	 * Prüft die Kamera auf Kollisionen mit der Welt.
	 * @param pVertices Vektor mit Dreiecken, auf die geprüft werden soll.
	 * @param numOfVerts Anzahl der Dreiecke
	 * @author Vaceslav Ustinov
	 */
	void CheckCameraCollision(CVector3 *pVertices, int numOfVerts);

protected:	
	
	/** Aspekt der Kamera */
	double m_Aspect;
	
	/** Weitwinkel der Kamera */
	double m_FoVY;
	
	/** Nahe Clippingplane */
	double m_Near;
	
	/** Weite Clippingplane */
	double m_Far;
	
	/** Punkt, auf den die Kamera gerichtet ist */
	C3dVector m_ViewPoint;
	
	/** Position, der Kamera */
	C3dVector m_Camera;
	
	/** Punkt, auf den die Kamera gerichtet ist */
	CVector3 m_vPosition;

	/** Radius der Kamera für Kollisionen */
	float m_Radius;
	
	/** Seitwärtsvektor, um den die Kamera bewegt wird */
	C3dVector m_Strave;
	
	/** Der Up-Vektor der Kamera */
	C3dVector m_Up;

	/** Vektor für Zwischenwerte */
	C3dVector m_tmpV1;
	/** Vektor für Zwischenwerte */
	C3dVector m_tmpV2;
	/** Vektor für Zwischenwerte */
	C3dVector m_tmpV3;
	
};

#endif
