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


BR_View::~BR_View()
{}




/**
 * Initialisiert OpenGL
 */
void BR_View::initializeGL()
{
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    glEnable( GL_DEPTH_TEST );



    glEnable( GL_LIGHTING );
    glEnable( GL_COLOR_MATERIAL );
    glEnable( GL_NORMALIZE );
//     glEnable( GL_CULL_FACE );
    //   glFrontFace(GL_CCW);

    glPolygonMode( GL_FRONT, GL_FILL );
    glPolygonMode( GL_BACK, GL_LINE );
}


/*!
    \fn BR_View::resizeGL()
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


/*!
    \fn BR_View::paintGL()
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

//     drawGrid();
	m_FPS++;
}


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


/*!
    \fn BR_View::keyPressEvent ( QKeyEvent * )
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




/*!
    \fn BR_View::keyReleaseEvent ( QKeyEvent * ke )
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


/*!
    \fn BR_View::mousePressEvent ( QMouseEvent * me)
 */
void BR_View::mousePressEvent ( QMouseEvent * me )
{
    //     cout << me->button() << endl;
    //     setCursor ( Qt::BlankCursor );
    // 	setMouseTracking( true );
    //     grabMouse();

    m_MousePosX = me->globalX();
    m_MousePosY = me->globalY();
}

void BR_View::mouseMoveEvent ( QMouseEvent * me )
{

    // 	cout << me ->buttons() << " ? " << Qt::LeftButton << endl;
    if ( me->buttons() == Qt::LeftButton )
    {
        //cout << "move " << e->x() << "|" << e->y() << endl;
        double x, y;

//         cout << me->x() << " | " << me->y() << endl;


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
// 	QVector<BB_DrawObject *> * objects =  m_Doc->getLevels()->at(0)->getDrawObjects();
	if( m_Keys.isPressed( Qt::Key_W ) )
	{
// 		cout << "CameraViewPoint: " <<m_Camera.getViewPoint().x() <<"-"<<m_Camera.getViewPoint().y() <<"-"<<m_Camera.getViewPoint().z() <<endl;
// 		cout << "CameraPos: " <<m_Camera.getPos().x() <<"-"<<m_Camera.getPos().y() <<"-"<<m_Camera.getPos().z() <<endl;
		m_Camera.move( 0.2 );
	}
	
	if( m_Keys.isPressed( Qt::Key_S ) )
	{
// 		cout << "CameraViewPoint: " <<m_Camera.getViewPoint().x() <<"-"<<m_Camera.getViewPoint().y() <<"-"<<m_Camera.getViewPoint().z() <<endl;
// 		cout << "CameraPos: " <<m_Camera.getPos().x() <<"-"<<m_Camera.getPos().y() <<"-"<<m_Camera.getPos().z() <<endl;
		m_Camera.move( -0.2 );
	}
	
	if( m_Keys.isPressed( Qt::Key_A ) )
	{
// 		cout << "CameraViewPoint: " <<m_Camera.getViewPoint().x() <<"-"<<m_Camera.getViewPoint().y() <<"-"<<m_Camera.getViewPoint().z() <<endl;
// 		cout << "CameraPos: " <<m_Camera.getPos().x() <<"-"<<m_Camera.getPos().y() <<"-"<<m_Camera.getPos().z() <<endl;
		m_Camera.strafe( -0.1 );
	}
	
	if( m_Keys.isPressed( Qt::Key_D ) )
	{
// 		cout << "CameraViewPoint: " <<m_Camera.getViewPoint().x() <<"-"<<m_Camera.getViewPoint().y() <<"-"<<m_Camera.getViewPoint().z() <<endl;
// 		cout << "CameraPos: " <<m_Camera.getPos().x() <<"-"<<m_Camera.getPos().y() <<"-"<<m_Camera.getPos().z() <<endl;
		m_Camera.strafe( 0.1 );
	}
	
}


/*!
    \fn BR_MainWindow::showCurrentFPS()
 */
void BR_View::showCurrentFPS()
{
	m_CurrentFPS = m_FPS;
	m_FPS = 0;

	m_Info->printFPS( m_CurrentFPS );
	
}



/*!
    \fn BR_View::setWireFrame( bool value )
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
