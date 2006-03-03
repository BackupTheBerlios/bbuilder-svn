//
// C++ Implementation: br_view
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "br_view.h"

#include <iostream>





using namespace std;

/**
 * Konstruktor
 * @param doc Dokument
 * @param info Informationsfenster
 * @param parent Parent-Fenster
 * @author Alex Letkemann
 */
BR_View::BR_View( BB_Doc * doc, BR_InfoWidget * info, QWidget * parent )
        : QGLWidget( parent )
{
	if( doc == NULL || info == NULL)
	{
		qDebug( " BR_View::BR_View( BB_Doc * doc, BR_InfoWidget * info ): NULL Pointer erhalten " );
		exit(1);
	}
	
	m_Doc = doc;
	m_Info = info;
	m_WireFrame = false;
	m_GhostMode = false;
	
	
    /* Fokus setzen, damit das Fenster die KeyPress events abfangen kann */
    setFocusPolicy( Qt::StrongFocus );
	m_FPS = 0;
	
	
	CColorRGBA tmpColor0,tmpColor1,tmpColor2;
	tmpColor0 = cl_White * 0.0;
	tmpColor1 = cl_White * 0.8;
	tmpColor2 = cl_White * 0.8;
	
	
	C3dVector lightPos(3.0, 10.0, 5.0);
	// Lichtquelle erzeugen
	m_Light = new CGLLight(lightPos,tmpColor0,tmpColor1,tmpColor2,1.0,true);
}

/**
 * Destruktor
 */
BR_View::~BR_View()
{}




/**
 * Initialisiert OpenGL
 * @author Alex Letkemann
 */
void BR_View::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glEnable( GL_DEPTH_TEST );



    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_NORMALIZE );
    glEnable( GL_CULL_FACE );

    glPolygonMode( GL_FRONT, GL_FILL );
    glPolygonMode( GL_BACK, GL_LINE );
}


/**
 * Wird aufgerufen, wenn das OpenGL Fenster die Größe ändert.
 * Passt den Aspekt an.
 * @param width Neue Breite des Fensters
 * @param height Neuen Höhe des Fensters
 * @author Alex Letkemann
 */
void BR_View::resizeGL( int width, int height )
{
    if ( height <= 0 )
    {
        height = 1;
    }
    if ( width <= 0 )
    {
        width = 1;
    }
    glViewport( 0, 0, width, height );
    m_Camera.setAspect( ( GLfloat ) width / ( GLfloat ) height );
}


/**
 * Zeichnet die 3D-Scene
 * @author Alex Letkemann
 */
void BR_View::paintGL()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	
	m_Light->switchOn();
	
	proceedActions();
	if( !m_GhostMode )
	{
		m_Camera.CheckCameraCollision( m_Doc->getCollisionVector(), m_Doc->getTriangles().count() * 3);
	}
    m_Camera.apply();
	m_Doc->showGl();

	m_FPS++;
}

/**
 * Zeichet ein Gitter auf der XZ-Ebene 
 * @author Alex Letkemann
 */
void BR_View::drawGrid( void )
{

    int linienX = 20;		// Ausrichtung des Gitters in jeder Richtung der X-Achse
    int linienZ = 20;		// Ausrichtung des Gitters in jeder Richtung der Z-Achse

    glColor3f( 0.3f, 0.3f, 0.3f );

    for ( int i = -linienX; i <= linienX; i++ )
    {
        if ( i % 5 == 0 )
            glColor3f( 0.6f, 0.6f, 0.6f );
        else
            glColor3f( 0.3f, 0.3f, 0.3f );

        glBegin( GL_LINES );
        glVertex3d( linienX, 0.0, ( double ) i );
        glVertex3d( -linienX, 0.0, ( double ) i );
        glEnd();
    }

    for ( int i = -linienZ; i <= linienZ; i++ )
    {
        if ( i % 5 == 0 )
            glColor3f( 0.6f, 0.6f, 0.6f );
        else
            glColor3f( 0.3f, 0.3f, 0.3f );

        glBegin( GL_LINES );
        glVertex3d( ( double ) i, 0.0, linienZ );
        glVertex3d( ( double ) i, 0.0, -linienZ );
        glEnd();
    }
}


/**
 * Wird aufgerufen, wenn eine Taste gedrückt wird.
 * Setzt den Status der Taste
 * @param ke QKeyEvent
 * @author Alex Letkemann
 */
void BR_View::keyPressEvent ( QKeyEvent * ke )
{

    /* Falls der KeyEvent ein AutoRepeatEvent ist, wird er nicht weiter beachtet */
    if ( ke->isAutoRepeat () )
    {
        ke->ignore ();
        return ;
    }

    m_Keys.pressed( ke->key() );
	ke->ignore();
}




/**
 * Wird aufgerufen, wenn eine Taste los gelassen wird.
 * Setzt den Status der Taste
 * @param ke QKeyEvent
 * @author Alex Letkemann
 */
void BR_View::keyReleaseEvent ( QKeyEvent * ke )
{
    /* Falls der KeyEvent ein AutoRepeatEvent ist, wird er nicht weiter beachtet */
    if ( ke->isAutoRepeat () )
    {
        ke->ignore ();
        return ;
    }

    m_Keys.released( ke->key() );
	ke->ignore();
}


/**
 * Wird aufgerufen, wenn eine Maustatste gedrückt wird.
 * @param me QMouseEvent
 * @author Alex Letkemann
 */
void BR_View::mousePressEvent ( QMouseEvent * me )
{

    m_MousePosX = me->globalX();
    m_MousePosY = me->globalY();
}


/**
 * Wird aufgerufen, wenn die Maus mit gedrückter Maustatste bewegt wird
 * Setzt die Rotation der Kamera
 * @param me QMouseEvent
 * @author Alex Letkemann
 */
void BR_View::mouseMoveEvent ( QMouseEvent * me )
{

    if ( me->buttons() == Qt::LeftButton )
    {

        double x, y;

		x = m_MousePosX - (me->globalX());
		y = m_MousePosY - (me->globalY());

        m_Camera.rotateX( y * 0.3 );
        m_Camera.rotateY( x * 0.3 );

        m_MousePosX = me->globalX();
        m_MousePosY = me->globalY();


    }
}


/**
 * Führ die Aktionen aus, die der User über die Tastatur angibt.
 */
void BR_View::proceedActions()
{

	if( m_Keys.isPressed( Qt::Key_W ) )
	{
		m_Camera.move( 0.2 );
	}
	
	if( m_Keys.isPressed( Qt::Key_S ) )
	{
		m_Camera.move( -0.2 );
	}
	
	if( m_Keys.isPressed( Qt::Key_A ) )
	{
		m_Camera.strafe( -0.1 );
	}
	
	if( m_Keys.isPressed( Qt::Key_D ) )
	{
		m_Camera.strafe( 0.1 );
	}
	
}


/**
 * Zeigt die aktuelle Framerate im Informationsfenster an
 * @author Alex Letkemann
 */
void BR_View::showCurrentFPS()
{
	m_CurrentFPS = m_FPS;
	m_FPS = 0;

	m_Info->printFPS( m_CurrentFPS );
	
}



/**
 * Aktiviert oder deaktiviert den Wireframe-Modus
 * @param value True: Wireframe aktiviert, False: deaktiviert
 * @author Alex Letkemann
 */
void BR_View::setWireFrame( bool value )
{
	if( value )
	{
		glDisable( GL_CULL_FACE );
		glPolygonMode( GL_FRONT, GL_LINE );
	}
	else
	{
		glEnable( GL_CULL_FACE );
		glPolygonMode( GL_FRONT, GL_FILL );
	}
}


/**
 * Setzt den Status des Geist-Modus
 * @param value Status des Geist-Modus
 */
void BR_View::setGhostMode( bool value )
{
	m_GhostMode = value;
}
