//
// C++ Interface: br_view
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BR_VIEW_H
#define BR_VIEW_H

#include <QtOpenGL>

#include <br_camera.h>
#include <br_keyhandler.h>
#include <br_infowidget.h>

#include <c3dvector.h>
#include <cgllight.h>
#include <ccolorrgba.h>

#include "3dmath.h"

/**
 * Fenster, in dem die OpenGL darstellung aubläuft.
 *
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BR_View : public QGLWidget
{
public:
	/**
	 * Konstruktor
	 * @param doc Dokument
	 * @param info Informationsfenster
	 * @param parent Parent-Fenster
	 * @author Alex Letkemann
	 */
	BR_View( BB_Doc * doc, BR_InfoWidget * info, QWidget * parent = 0 );

	/**
	 * Destruktor
	 */
	~BR_View();

	/**
	 * Zeigt die aktuelle Framerate im Informationsfenster an
	 * @author Alex Letkemann
	 */
	void showCurrentFPS();
	
	/**
	 * Aktiviert oder deaktiviert den Wireframe-Modus
	 * @param value True: Wireframe aktiviert, False: deaktiviert
	 * @author Alex Letkemann
	 */
    void setWireFrame( bool value );
	
	/**
	 * Setzt den Status des Geist-Modus
	 * @param value Status des Geist-Modus
	 * @author Alex Letkemann
	 */
    void setGhostMode( bool value );

protected:
	/**
	 * Initialisiert OpenGL
     * @author Alex Letkemann
	 */
	virtual void initializeGL();
	
	/**
	 * Wird aufgerufen, wenn das OpenGL Fenster die Größe ändert.
	 * Passt den Aspekt an.
	 * @param width Neue Breite des Fensters
	 * @param height Neuen Höhe des Fensters
	 * @author Alex Letkemann
	 */
	virtual void resizeGL( int width, int height );
	
	
	/**
	 * Zeichnet die 3D-Scene
	 * @author Alex Letkemann
	 */
	virtual void paintGL();

	
	/**
	 * Zeichet ein Gitter auf der XZ-Ebene 
	 * @author Alex Letkemann
	 */
	void drawGrid();

	/**
	 * Wird aufgerufen, wenn eine Taste gedrückt wird.
	 * Setzt den Status der Taste
	 * @param ke QKeyEvent
	 * @author Alex Letkemann
	 */
	virtual void keyPressEvent ( QKeyEvent * ke );
	
	/**
	 * Wird aufgerufen, wenn eine Taste los gelassen wird.
	 * Setzt den Status der Taste
	 * @param ke QKeyEvent
	 * @author Alex Letkemann
	 */
	virtual void keyReleaseEvent ( QKeyEvent * ke );
	
	
	/**
	 * Wird aufgerufen, wenn eine Maustatste gedrückt wird.
	 * @param me QMouseEvent
	 * @author Alex Letkemann
	 */
	virtual void mousePressEvent ( QMouseEvent * me );
	
	
	/**
	 * Wird aufgerufen, wenn die Maus mit gedrückter Maustatste bewegt wird
	 * Setzt die Rotation der Kamera
	 * @param me QMouseEvent
	 * @author Alex Letkemann
	 */
	virtual void mouseMoveEvent ( QMouseEvent * me );
protected:

	/** Dir Kamera, die vom User Gesteuert wird */
	BR_Camera m_Camera;
	
	/** KeyHandler*/
	BR_KeyHandler m_Keys;
	
	/** Position der Maus auf der X-Achse */
    int m_MousePosX;
	/** Position der Maus auf der Y-Achse */
    int m_MousePosY;
	
	/** Zähler für die Bilder pro Sekunde */
	unsigned int m_FPS;
	
	/** Anzahl der Bilder der letzten Sekunde */
	unsigned int m_CurrentFPS;
	
	/** Informationsfenster */
    BR_InfoWidget* m_Info;
	
	/** Dokument */
    BB_Doc* m_Doc;
	
	/** Lichtquelle */
    CGLLight* m_Light;
	
	/** Status: Geistmodus */
    bool m_GhostMode;
	
	/** Status: Wireframe */
    bool m_WireFrame;
private:
	
	/** Führ die Bewegungs-Aktionen aus */
    void proceedActions();
};

#endif
