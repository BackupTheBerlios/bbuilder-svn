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

#include <iostream>

using namespace std;

/**
 * Konstruktor
 * @author Alex Letkemann
 */
BR_Camera::BR_Camera()
{

    m_Aspect = 0.75;
    m_FoVY = 45.0;
    m_Far = 1000.0;
    m_Near = 0.1;

    m_Camera = C3dVector( 0.0, 3.0, -3.0 );
    m_vPosition.x = 0.0;
    m_vPosition.y = 3.0;
    m_vPosition.z = -3.0;
    m_Radius = 0.4;

    m_ViewPoint = v_Z;
//     m_vView.x = 0.0;
//     m_vView.y = 0.0;
//     m_vView.z = 1.0;

    m_Up = v_Y;
    m_Strave = v_X;
}


/**
 * Destruktor
 */
BR_Camera::~BR_Camera()
{}




/**
 * Rotiert die Kamera um die Y-Achse um den angegebenen Winkel
 * @param angle Winkel
 * @author Alex Letkemann
 */
void BR_Camera::rotateY( double angle )
{
    m_ViewPoint = m_ViewPoint.rotateVector( v_Y, angle ).unitVector();
    m_Strave = m_Strave.rotateVector( v_Y, angle ).unitVector();

}


/**
 * Rotiert die Kamera um die X-Achse um den angegebenen Winkel
 * @param angle Winkel
 * @author Alex Letkemann
 */
void BR_Camera::rotateX( double angle )
{
    m_ViewPoint = m_ViewPoint.rotateVector( m_Strave, angle ).unitVector();
}


/**
 * Erstellt die Pespektive.
 * Führ die OpenGl operationen aus.
 * @author Alex Letkemann
 */
void BR_Camera::apply()
{

    m_tmpV1 = m_Camera + m_ViewPoint;


    glMatrixMode( GL_PROJECTION );

    glLoadIdentity();

    gluPerspective( m_FoVY, m_Aspect, m_Near, m_Far );

    glMatrixMode( GL_MODELVIEW );

    glLoadIdentity();

    gluLookAt( m_Camera.x(), m_Camera.y(), m_Camera.z(),
               m_tmpV1.x(), m_tmpV1.y(), m_tmpV1.z(),
               m_Up.x(), m_Up.y(), m_Up.z() );
}


/**
 * Setzt den Aspekt
 * @param aspect Aspekt zwischen der Höhe und der Breite des Fensters.
 * @author Alex Letkemann
 */
void BR_Camera::setAspect( double aspect )
{
    m_Aspect = aspect;
}


/**
 * Bewegt die Kamera seitwärts.
 * Positive Geschwindigkeit bewegt die Kamera rechts, negative Links.
 * @param speed Geschwindigkeit.
 * @author Alex Letkemann
 */
void BR_Camera::strafe( double speed )
{
    m_Camera = m_Camera + speed * m_Strave;
}


/**
 * Bewegt die Kamera nach vonr und zurück.
 * Positive Geschwindigkeit bewegt die Kamera vor, negative zurück.
 * @param speed Geschwindigkeit.
 * @author Alex Letkemann
 */
void BR_Camera::move( double speed )
{
    m_Camera = m_Camera + speed * m_ViewPoint;
}

/**
 * Geibt den Punkt zurück, auf den die Kamera gerichtet ist.
 * @return Punkt, auf den die Kamera gerichtet ist.
 * @author Alex Letkemann
 */
C3dVector BR_Camera::getViewPoint()
{
    return m_ViewPoint;
}


/**
 * Gibt die Position der Kamera zurück.
 * @return Position der Kamera.
 * @author Alex Letkemann
 */
C3dVector BR_Camera::getPos()
{
    return m_Camera;
}


///////////////////////////////// CHECK CAMERA COLLISION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*
/////
/////   This checks all the polygons in our list and offsets the camera if collided
/////
///////////////////////////////// CHECK CAMERA COLLISION \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*

void BR_Camera::CheckCameraCollision( CVector3 *pVertices, int numOfVerts )
{
    // This function is pretty much a direct rip off of SpherePolygonCollision()
    // We needed to tweak it a bit though, to handle the collision detection once
    // it was found, along with checking every triangle in the list if we collided.
    // pVertices is the world data. If we have space partitioning, we would pass in
    // the vertices that were closest to the camera. What happens in this function
    // is that we go through every triangle in the list and check if the camera's
    // sphere collided with it.  If it did, we don't stop there.  We can have
    // multiple collisions so it's important to check them all.  One a collision
    // is found, we calculate the offset to move the sphere off of the collided plane.

// 	cout <<"Function aufgerufen"<<endl;
	m_vPosition.x = m_Camera.x();
	m_vPosition.y = m_Camera.y();
	m_vPosition.z = m_Camera.z();

// 	m_vView.x= m_ViewPoint.x();
// 	m_vView.y= m_ViewPoint.y();
// 	m_vView.z= m_ViewPoint.z();
    // Go through all the triangles
    for ( int i = 0; i < numOfVerts; i += 3 )
    {
// 		cout <<"In der Schleife"<<endl;
// 		cout <<"m_vPosition: x->"<<m_vPosition.x<<"y->"<<m_vPosition.y<<"x->"<<m_vPosition.z<<endl;
        // Store of the current triangle we testing
        CVector3 vTriangle[ 3 ] = { pVertices[ i ], pVertices[ i + 1 ], pVertices[ i + 2 ] };

        // 1) STEP ONE - Finding the sphere's classification

        // We want the normal to the current polygon being checked
        CVector3 vNormal = Normal( vTriangle );

        // This will store the distance our sphere is from the plane
        float distance = 0.0f;

        // This is where we determine if the sphere is in FRONT, BEHIND, or INTERSECTS the plane
        int classification = ClassifySphere( m_vPosition, vNormal, vTriangle[ 0 ], m_Radius, distance );

        // If the sphere intersects the polygon's plane, then we need to check further
        if ( classification == INTERSECTS )
        {
// 			cout <<"classification == INTERSECTS "<<endl;
            // 2) STEP TWO - Finding the psuedo intersection point on the plane

            // Now we want to project the sphere's center onto the triangle's plane
            CVector3 vOffset = vNormal * distance;

            // Once we have the offset to the plane, we just subtract it from the center
            // of the sphere.  "vIntersection" is now a point that lies on the plane of the triangle.
            CVector3 vIntersection =  - vOffset;

            // 3) STEP THREE - Check if the intersection point is inside the triangles perimeter

            // We first check if our intersection point is inside the triangle, if not,
            // the algorithm goes to step 4 where we check the sphere again the polygon's edges.

            // We do one thing different in the parameters for EdgeSphereCollision though.
            // Since we have a bulky sphere for our camera, it makes it so that we have to
            // go an extra distance to pass around a corner. This is because the edges of
            // the polygons are colliding with our peripheral view (the sides of the sphere).
            // So it looks likes we should be able to go forward, but we are stuck and considered
            // to be colliding.  To fix this, we just pass in the radius / 2.  Remember, this
            // is only for the check of the polygon's edges.  It just makes it look a bit more
            // realistic when colliding around corners.  Ideally, if we were using bounding box
            // collision, cylinder or ellipses, this wouldn't really be a problem.

            if ( InsidePolygon( vIntersection, vTriangle, 3 ) ||
                    EdgeSphereCollision( m_vPosition, vTriangle, 3, m_Radius / 2 ) )
            {
// 				cout <<"InsidePolygon( "<<endl;
                // If we get here, we have collided!  To handle the collision detection
                // all it takes is to find how far we need to push the sphere back.
                // GetCollisionOffset() returns us that offset according to the normal,
                // radius, and current distance the center of the sphere is from the plane.
                vOffset = GetCollisionOffset( vNormal, m_Radius, distance );

                // Now that we have the offset, we want to ADD it to the position and
                // view vector in our camera.  This pushes us back off of the plane.  We
                // don't see this happening because we check collision before we render
                // the scene.
                m_vPosition = m_vPosition + vOffset;
                m_Camera.setX( m_vPosition.x );
                m_Camera.setY( m_vPosition.y );
                m_Camera.setZ( m_vPosition.z );

//                 m_vView = m_vView + vOffset;
//                 m_ViewPoint.setX( m_vView.x );
//                 m_ViewPoint.setY( m_vView.y );
//                 m_ViewPoint.setZ( 1 );
            }
        }
    }
}
