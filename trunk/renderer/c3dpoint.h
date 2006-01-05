/***************************************************************************
                         c3dpoint.h  - description
                            -------------------
   begin                : Tue Feb 6 2001
   copyright            : (C) 2001, 2004 by Walter Roth
   email                : roth@mfh-iserlohn.de
***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef C3DPOINT_H
#define C3DPOINT_H


/**A 3d point with color, light, normal vector and texture coordinates properties
  *@author Walter Roth
  */
// #include <GL/gl.h>
#include <QtOpenGL>
#include <QVector>

#include "c3dvector.h"
#include "ccolorrgba.h"

#include <iostream>

using namespace std;

/**The type to be used for the arrays that contain vertices, normals and texturecoordinates.
*/
typedef QVector<C3dVector> C3dVectorArray;

class C3dPoint
{
    public:
        /** Standard constructor
        */
        C3dPoint();
        /** Creates a point with given V0, true normal, color and texture coordinates.
          */
        C3dPoint( const C3dVector & position,
                  const C3dVector & normal0 = v_Zero,
                  const C3dVector & tex0 = v_Zero,
                  const CColorRGBA & color = cl_Black );
        virtual ~C3dPoint();
        /** Copy constructor.
          */
        C3dPoint( const C3dPoint& toCopy );
        /** Write property of fColor
          */
        virtual void setColor( const CColorRGBA &newColor );
        /** Contains the vertex, normal and texture calls  that draw the primitive.
          * For C3dPoint, only color and vertex are used.
          * To be overridden by subclassed objects.
          */
        virtual void draw();
        /**Calls GLBegin, draw and GLEnd. Needs not be overridden for geometric primitives subclasses.
          *Override draw() in subclasses.
          */
        virtual void show();
        /** Moves the point by vMove.
          */
        virtual void moveBy( const C3dVector &vMove );
        /** Rotates the point around the origin.
          */
        virtual void rotate( const C3dVector &vAxis, double Angle );
        /** Stretches by sx,sy,sz. Calls stretchVector.
          */
        virtual void stretch( double sx, double sy, double sz );
        /** Read property of fColor.
          */
        const CColorRGBA & getColor() const;
        /** Returns address of color data for use with glColor3dv.
          */
        GLfloat * colorFv();
        /** Read property of V0
          */
        const C3dVector & getV0() const;
        /** Write property of C3dVector V0.
          */
        virtual void setV0( const C3dVector& _newVal );
        /** Write property of C3dVector VN0.
          */
        virtual void setVN0( const C3dVector& _newVal );
        /** Read property of C3dVector VN0.
          */
        virtual const C3dVector& getVN0() const;
        /** Write property of C3dVector VTex0.
          */
        virtual void setVTex0( const C3dVector& _newVal );
        /** Read property of C3dVector VTex0.
          */
        virtual const C3dVector& getVTex0() const;
        /** Write property of bool m_ShowNormals. */
        static void setShowNormals( const bool& _newVal );
        /** Read property of bool m_ShowNormals. */
        static const bool& getShowNormals();
        /** Shows the normal vectors for debugging.
        */
        virtual void showNormals();
        /** Copies the data to the valuearrays for use with OpenGL array functions.
        */
        virtual void toArrays( int & index, C3dVectorArray * vertices, C3dVectorArray * normals = NULL, C3dVectorArray * texCoords = NULL );
        /** Returns the GL_XXX constant that has to be used with glBegin to draw the object. e.g. GL_TRIANGLES
        */
        virtual GLenum getClassEnum() const;
        /** Returns number of vertices in class.
        */
        virtual int getNumberOfVertices();
    protected:  //Protected member functions
        /** Copy function for operator = and copy constructor.
          */
        void copy( const C3dPoint & toCopy );
        /** Contains the vertex calls for drawing the normals.
        */
        virtual void drawNormals();
    protected:  //Protected attributes
        /** The position of the point.
          */
        C3dVector m_V0;
        /** The color of the point.
          */
        CColorRGBA m_Color; //use float colors red, green, blue from 0 to 1.0.
        //Default alpha value is 1.0 = opaque.
        /** The normal vector to be used with m_V0.
          */
        C3dVector m_VN0;
        /** The texture coordinates of the point.
          */
        C3dVector m_VTex0;
        /** Show the normal vector as a line. Switch on for debugging.
        */
        static bool m_ShowNormals;

        GLenum m_ClassEnum;
};
/** Predefined global vectors for convenience.
*/
static C3dPoint pt_Zero = C3dPoint( v_Zero );
static C3dPoint pt_X = C3dPoint( v_X );
static C3dPoint pt_Y = C3dPoint( v_Y );
static C3dPoint pt_Z = C3dPoint( v_Z );
static C3dPoint pt_XY = C3dPoint( v_XY );
static C3dPoint pt_YZ = C3dPoint( v_YZ );
static C3dPoint pt_XZ = C3dPoint( v_XZ );
static C3dPoint pt_XYZ = C3dPoint( v_XYZ );

#endif
