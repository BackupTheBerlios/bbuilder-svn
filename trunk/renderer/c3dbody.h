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
#ifndef C3DBODY_H
#define C3DBODY_H

#include <c3dquad.h>
#include <QVector>
#include <cglmatrix.h>
#include <GL/gl.h>

/**
@author Alex Letkemann
*/
class C3dBody : public C3dQuad
{
    public:
        C3dBody();

        ~C3dBody();

        virtual const C3dVector& getV4() const;
        virtual void moveBy( const C3dVector& vMove );
        virtual void rotate( const C3dVector& vAxis, double Angle );
        virtual void setV4( const C3dVector& _newVal );
        void copy( const C3dBody& toCopy );
        virtual void makeSurface();
        bool surfaceExists( void );
        virtual void draw();
        virtual void show();
        GLuint getTexture( void );
        QString & getTextureFileName();
        void setTextureFileName( QString &name );
        virtual void makeTransformations();

    protected:
        C3dVector m_V4;

        bool m_SurfaceExists;

        QVector<C3dTriangle*> m_Triangles;
        QVector<C3dQuad*> m_Quads;
        GLuint m_Texture;
        QString m_TextureFileName;
        QVector<CGLMatrix*> m_Transformations;
        bool m_TexGenError;
    protected:
        virtual bool createTexture();
};

#endif
