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
#include "c3dbody.h"
// #include <QGL>

/**
 * Konstrucktor
 */
C3dBody::C3dBody()
{
    m_Triangles.resize( 256 );
    m_Quads.resize( 256 );

    m_Texture = 0;
    m_TexGenError = 0;
}

/**
 * Destrucktor
 */
C3dBody::~C3dBody()
{}


/**
 * Gibt den V4 zurück
 */
const C3dVector& C3dBody::getV4() const
{
    return m_V4;
}

/**
 * Bewegt das Objekt
 */
void C3dBody::moveBy( const C3dVector& vMove )
{
    if ( &vMove != NULL )
    {
        for ( int i = 0; i < m_Triangles.count(); i++ )
        {
            m_Triangles.at( i ) ->moveBy( vMove );
        }

        for ( int i = 0; i < m_Quads.count(); i++ )
        {
            m_Quads.at( i ) ->moveBy( vMove );
        }
    }
    else
    {
        cout << "NULL-Pointer bei C3dBody::moveBy(...)" << endl;
    }
}


/**
 * Rotiert das Objekt
 */
void C3dBody::rotate( const C3dVector& vAxis, double Angle )
{
    if ( &vAxis != NULL )
    {
        for ( int i = 0; i < m_Triangles.count(); i++ )
        {
            m_Triangles.at( i ) ->rotate( vAxis, Angle );
        }

        for ( int i = 0; i < m_Quads.count(); i++ )
        {
            m_Quads.at( i ) ->rotate( vAxis, Angle );
        }
    }
    else
    {
        cout << "NULL-Pointer bei C3dBody::rotate(...)" << endl;
    }
}

/**
 * Setzt V4
 */
void C3dBody::setV4( const C3dVector& _newVal )
{
    m_V4 = _newVal;
}
/**
 * Kopierfunktion
 */
void C3dBody::copy( const C3dBody& toCopy )
{
    C3dQuad::copy( toCopy );
    m_V4 = toCopy.getV4();
}



/**
 * Erzeugt alle Flächen des Objektes
 */
void C3dBody::makeSurface()
{
    // leer, da Abstrakte funktion
    // cout << "afökjasdfköjf" << endl;
}


/**
 * Gibt den Flag m_SurfaceExists zurück
 */
bool C3dBody::surfaceExists( void )
{
    return m_SurfaceExists;
}


/**
 * Zeichnet die einzelnen Quads und Triangles
 */
void C3dBody::draw() const
{

    C3dQuad * tmpQuad;
    C3dTriangle * tmpTri;

    glBegin( GL_TRIANGLES );
    for ( int i = 0; i < m_Triangles.count(); i++ )
    {
        tmpTri = m_Triangles.at( i );
        tmpTri->show();
        if ( m_ShowNormals )
            tmpTri->showNormals();
    }
    glEnd();

    glBegin( GL_QUADS );
    for ( int i = 0; i < m_Quads.count(); i++ )
    {
        tmpQuad = m_Quads.at( i );

        tmpQuad->show();
        if ( m_ShowNormals )
            tmpQuad->showNormals();
    }
    glEnd();



}


/**
 * Zeichnet die Körper
 */
void C3dBody::show()
{
    if ( m_TexGenError == 0 && m_Texture == 0 && m_TextureFileName == "" )
    {
        m_TexGenError = !createTexture();
    }

    glColor3fv( m_Color.fv() );

    if ( m_Texture != 0 )
    {
        glEnable( GL_TEXTURE_2D );
        glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
        glBindTexture( GL_TEXTURE_2D, m_Texture );
    }
    else
    {
        glBindTexture( GL_TEXTURE_2D, 0 );
    }

    if ( m_Transformations.count() == 0 )
        draw();
    else
    {

        for ( int i = 0; i < m_Transformations.count(); i++ )
        {
            glPushMatrix();
            glMultMatrixf( m_Transformations.at( i ) ->getMatrix() );
            draw();
            glPopMatrix();
        }
    }

    glDisable( GL_TEXTURE_2D );

}


/**
 * Gibt die Texturnummer zurück
 */
GLuint C3dBody::getTexture( void )
{
    return m_Texture;
}


/**
 * Gibt den Textur File zurück
 */
QString & C3dBody::getTextureFileName()
{
    return m_TextureFileName;
}


/**
 * Setzt den Textur File
 */
void C3dBody::setTextureFileName( QString &name )
{
    m_TextureFileName = name;
}


/**
 * Erzeugt die Transformationen
 */
void C3dBody::makeTransformations()
{
    /// @todo implement me
}


/**
 * Erzeugt die Texturen des Objektes
 */
bool C3dBody::createTexture()
{
    cout << "No texture definined" << endl;
    return false;
}
