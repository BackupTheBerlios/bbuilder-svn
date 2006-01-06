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
#include "c3dpoint.h"
#include <GL/gl.h>

bool C3dPoint::m_ShowNormals;

/** Standard Konstructor
 * Erstellt einen Punkt an der Koordinate 0|0|0
 */
C3dPoint::C3dPoint()
{
    m_V0.setX( 0.0 );
    m_V0.setY( 0.0 );
    m_V0.setZ( 0.0 );

    m_ClassEnum = GL_POINTS;
}

/** Creates a point with given V0, true normal, color and texture coordinates.
*/
C3dPoint::C3dPoint( const C3dVector & position,
                    const C3dVector & normal0,
                    const C3dVector & tex0,
                    const CColorRGBA & color )
{
    if ( &position != NULL &&
            &normal0 != NULL &&
            &tex0 != NULL &&
            &color != NULL )
    {
        m_V0 = position;
        m_VN0 = normal0;
        m_VTex0 = tex0;
        m_Color = color;

        m_ClassEnum = GL_POINTS;
    }
    else
    {
        cout << "NULL-Pointer bei C3dPoint::C3dPoint(...)" << endl;
    }
}
C3dPoint::~C3dPoint()
{}

/** Copy constructor.
 */
C3dPoint::C3dPoint( const C3dPoint& toCopy )
{
    if ( &toCopy != NULL )
    {
        copy( toCopy );
        m_ClassEnum = GL_POINTS;
    }
    else
    {
        cout << "NULL-Pointer bei C3dPoint::C3dPoint(...)" << endl;
    }
}

/** Write property of fColor
*/
void C3dPoint::setColor( const CColorRGBA &newColor )
{
    if ( &newColor )
    {
        m_Color = newColor;
    }
    else
    {
        cout << "NULL-Pointer bei C3dPoint::setColor(...)" << endl;
    }
}

/** Contains the vertex, normal and texture calls  that draw the primitive.
* For C3dPoint, only color and vertex are used.
* To be overridden by subclassed objects.
 */
void C3dPoint::draw() const
{
    glNormal3dv( m_VN0.dv() );
    glTexCoord2dv( m_VTex0.dv() );
    m_V0.vertex();
}
/**Calls GLBegin, draw and GLEnd. Needs not be overridden for geometric primitives subclasses.
*Override draw() in subclasses.
 */
void C3dPoint::show() const
{
	glColor3fv(m_Color.fv());
    glBegin( m_ClassEnum );
    draw();
    glEnd();
	
}


/** Moves the point by vMove.
 */
void C3dPoint::moveBy( const C3dVector &vMove )
{
    if ( &vMove != NULL )
    {
        m_V0 = m_V0 + vMove;
    }
    else
    {
        cout << "NULL-Pointer bei C3dPoint::moveBy(...)" << endl;
    }
}

/** Rotates the point around the origin.
 */
void C3dPoint::rotate( const C3dVector &vAxis, double Angle )
{
    if ( &vAxis != NULL )
    {
        m_V0 = m_V0.rotateVector( vAxis, Angle );
        m_VN0 = m_VN0.rotateVector( vAxis, Angle );
    }
    else
    {
        cout << "NULL-Pointer bei C3dPoint::rotate(...)" << endl;
    }
}


/** Stretches by sx,sy,sz. Calls stretchVector.
 */
void C3dPoint::stretch( double sx, double sy, double sz )
{
    m_V0 = m_V0.stretchVector( sx, sy, sz );
}


/** Read property of fColor.
 */
const CColorRGBA & C3dPoint::getColor() const
{
    return m_Color;
}
/** Returns address of color data for use with glColor3dv.
 */
const GLfloat * C3dPoint::colorFv()
{
    return m_Color.fv();
}


/** Read property of V0
 */
const C3dVector & C3dPoint::getV0() const
{
    return m_V0;
}

/** Write property of C3dVector V0.
 */
void C3dPoint::setV0( const C3dVector& _newVal )
{
    m_V0 = _newVal;
}

/** Write property of C3dVector VN0.
 */
void C3dPoint::setVN0( const C3dVector& _newVal )
{
    m_VN0 = _newVal;
}

/** Read property of C3dVector VN0.
 */
const C3dVector& C3dPoint::getVN0() const
{
    return m_VN0;
}

/** Write property of C3dVector VTex0.
 */
void C3dPoint::setVTex0( const C3dVector& _newVal )
{
    m_VTex0 = _newVal;
}

/** Read property of C3dVector VTex0.
 */
const C3dVector& C3dPoint::getVTex0() const
{
    return m_VTex0;
}
/** Write property of bool m_ShowNormals. */
void C3dPoint::setShowNormals( const bool& _newVal )
{
    m_ShowNormals = _newVal;
}

/** Read property of bool m_ShowNormals. */
const bool& C3dPoint::getShowNormals()
{
    return m_ShowNormals;
}


/** Shows the normal vectors for debugging.
 */
void C3dPoint::showNormals()
{
    glColor3fv( cl_White.fv() );

    glDisable( GL_LIGHTING );

    glBegin( GL_LINES );
    drawNormals();
    glEnd();

    glEnable( GL_LIGHTING );
}
/** Copies the data to the valuearrays for use with OpenGL array functions.
 */
void C3dPoint::toArrays( int & index, C3dVectorArray * vertices, C3dVectorArray * normals, C3dVectorArray * texCoords )
{
    // TODO
}

/** Returns the GL_XXX constant that has to be used with glBegin to draw the object. e.g. GL_TRIANGLES
 */
GLenum C3dPoint::getClassEnum() const
{
    return m_ClassEnum;
}

/** Returns number of vertices in class.
 */
int C3dPoint::getNumberOfVertices()
{
    return 1;
}

/** Copy function for operator = and copy constructor.
 */
void C3dPoint::copy( const C3dPoint & toCopy )
{
    m_V0 = toCopy.getV0();
    m_VN0 = toCopy.getVN0();
    m_VTex0 = toCopy.getVTex0();
    m_Color = toCopy.getColor();
    m_ShowNormals = toCopy.getShowNormals();
}


/** Contains the vertex calls for drawing the normals.
 */
void C3dPoint::drawNormals() const
{
    m_V0.vertex();
    ( m_V0 + m_VN0 ).vertex();
}
