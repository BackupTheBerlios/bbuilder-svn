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
#include <br_doc.h>
#include <br_infowidget.h>

#include <c3dvector.h>
#include <cgllight.h>
#include <ccolorrgba.h>

/**
 * Fenster, in dem die OpenGL darstellung aubläuft.
 *
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BR_View : public QGLWidget
{
public:
	BR_View( BB_Doc * doc, BR_InfoWidget * info, QWidget * parent = 0 );

	~BR_View();

	void showCurrentFPS();

protected:
	virtual void initializeGL();
	virtual void resizeGL( int width, int height );
	virtual void paintGL();

	void drawGrid();

	virtual void keyPressEvent ( QKeyEvent * ke );
	virtual void keyReleaseEvent ( QKeyEvent * ke );
	virtual void mousePressEvent ( QMouseEvent * me );
	virtual void mouseMoveEvent ( QMouseEvent * me );
protected:

	/** Dir Kamera, die vom User Gesteuert wird */
	BR_Camera m_Camera;
	
	/** KeyHandler*/
	BR_KeyHandler m_Keys;
	
    int m_MousePosX;
    int m_MousePosY;
	
	unsigned int m_FPS;
	unsigned int m_CurrentFPS;
    BR_InfoWidget* m_Info;
    BB_Doc* m_Doc;
    CGLLight* m_Light;
private:
    void proceedActions();
};

#endif
