/***************************************************************************
                          C3dVector.h  - description
                             -------------------
    begin                : Mon Feb 5 2001
    copyright            : (C) 2004 by Walter Roth
    email                : roth@mfh-iserlohn.de
 ***************************************************************************/

/***************************************************************************
 *                                                                                   *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef C3DVECTOR_H
#define C3DVECTOR_H

#define DEBUG_C3DVECTOR   //comment this line for maximum performance
#define C3DVECTOR_DEBUG_LEVEL 1

#include <GL/gl.h>
#include <math.h>
#include "cglmatrix.h"

/** A vector with 3 dimensions in double numbers, especially designed for use with OpenGL.
  * Can be used easily with GL_xxx3dv functions. Use the dv() member function to obtain a
  * GLdouble * to the data. Alternatively, you may use vertex() for calls to glVertex and normal()
  * for calls to glNormal.
  * Contains the basic vector maths as memberfunctions and operators.
  * May be used with cartesian (x, y, z), geographic (radius, longitude angle counterclockwise
  * around y axis starting at z axis and latitude angle from equatorial xz plane up and down 90)
  * and polar coordinates ( radius, phi angle around z axis counterclockwise from x axis, theta angle
  * from positive z axis downwards). Radius is the length of the vector.
  * All angle functions work with 360 degree angles, unless you set C3dVector::UseRadian or
  * C3dVector::Use400NewDegree with the setAngleMode class function.
  * However, there is a constructor for geographic coordinates with a local AngleMode,
  * that accepts geographic coordinates and radian, 360 degree or 400 new degree angle
  * values. Pass Use360Degree or Use400NewDegree as first parameter, if you want to use degrees.
  * For polar coordinates, use the setRadiusPhiTheta function.
  * Data are kept as cartesian coordinates internally. Therefore, the geographic and polar values
  * may have rounding errors in the order of 10E-13.
  * All calculation functions except those operators, that include a = (=, +=, *= ...) are const functions.
  * This means, if you want to rotate a vector foo itself, you have to call: foo = foo.rotateVector().
  * For convenience, there are a couple of predefined vectors at the end of this header file (v_X, v_Y..).
  *
  * This class is designed for high performance and not for subclassing.
  * Undefine DEBUG_C3DVECTOR for maximum performance (refer to top of header file).
  * There are no virtual functions, which would create a VMT.
  * This increases performance. Make functions virtual, if you want to subclass.
  * The operators return references to members of the protected OpBufferVectors
  * array. This avoids permanent construction and destruction of temporary
  * C3dVectors for calculation results.<b> The predefined maximum number of nested
  * calculations is 32. If you need more, increase the value of AvailableOpBuffers.
  * See the getNextBuffer function for details. Use debugOutputStatistics() to obtain
  * informations on buffer useage and call statistics. Operator buffer overflow is very likely,
  * if results of vector calculations are passed as reference parameters to functions that perform lots
  * of calculations. Use "call by value" parameters or make an explicit copy of the reference parameter. 
  * If buffer overflow occurs, geometric objects are often "torn into pieces".</b>
  * @author Walter Roth
  */

class C3dVector {
public:
  /** Standard  constructor, creates a zero vector
  */
	C3dVector();
  /**Destructor, presently it does nothing.
   */
  ~C3dVector();
   /** Constructor for cartesian coordinates.
   */
	C3dVector(double x, double y, double z);
  /** Constructor for geographic coordinates. Pass UseRadian, Use360Degree or Use400NewDegree as
    * value for angleMode.  Static AngleMode is NOT affected.
    * Alternatives: Construct a C3dVector using the standard constructor. Then call
    * setRadiusPhiTheta for polar or setRadiusLongitudeLatitude for geographic coordinates.
    */
	C3dVector(int angleMode,  double radius, double longitude, double latitude);
  /** Copy constructor. Calls copy() function.
  */
	C3dVector(const C3dVector&  toCopy);
  /** Read property  for x coordinate.
  */
  double x() const;
  /** Write property for x coordinate.
      */
  void setX(double _newVal);
  /** Read property  for y coordinate.
  */
  double y() const;
  /** Write property for y coordinate.
  */
  void setY(double _newVal);
  /** Read property  for z coordinate.
  */
  double z() const;
  /** Write property for z coordinate.
  */
  void setZ(double _newVal);
  /** Returns vector with length 1.0 and same direction as  *this.
  */
  const C3dVector & unitVector()const;
  /** Scalar product.
   *  For vector product see function vectorMult.
   */
  double operator *(const C3dVector& v2 )const;
  /** Vector product *this X v2.
  */
  const C3dVector & vectorMult(const C3dVector& v2)const;
  /** Normal vector with lenght 1.0 obtained by *this X v2.
  */
  const C3dVector & getNormalVector(const C3dVector& v2)const;
  /** Caculates the length.
  */
  double getLength()const;
  /** Returns a vector obtained by rotating *this around axis. Uses radian Angle.
  */
  const C3dVector rotateVector(const C3dVector& Axis, double Angle)const;
  /** Returns this - v2.
  */
  const C3dVector & operator-(const C3dVector& v2)const;
  /** Returns the vectorsum of v1 and v2.
  */
  const C3dVector & operator+(const C3dVector& v2)const;
  /** For use with glXXXX3dv functions. This function relies on the internal order of declaration.
  */
  GLdouble * dv()const;
  /** Returns  a vector  x*sx, y*sy, z*sz.
  */
  const C3dVector & stretchVector(double sx, double sy, double sz)const;
  /** Multiplies vector with f.
  */
  const C3dVector & operator *(double f)const;
  /** Returns addres of fX fo glXXXfv functions.  This function will fail if GLfloat and double are
    * different number formats.
    */
  GLfloat * fv()const;
  /** Returns true, if all coordinates are 0.
  */
  bool isNull()const;
 /** Compares two vectors.
   * Will only return true if ALL digits of the double coordinates are the same.
   */
  bool operator == (const C3dVector& v2)const ;
  /** Compares two vectors. Uses !operator ==.
  */
  bool operator != (const C3dVector& v2)const ;
  /** Copies toCopy and returns * this.
  */
  C3dVector & operator = (const C3dVector & toCopy);
  /** Multipies 3d Vector with 4*4 matrix. 4th coordinate of vector is assumed to be 1.0.
    * Calculations run on main fpu. Use glMultMatrix for calculation on graphics processor.
    */
  const C3dVector & operator *(const CGLMatrix & m) const;
  /** Returns the debug output string.
  */
  QString debugString(const QString & caption)const;
  /** Writes list of coordinates to stderr.
  */
  void debugOutput(const QString &  caption)const;
  /** Produces a debug output of the number of operations, constructor calls etc.
  */
  static void debugOutputStatistics();
  /** Returns latitude angle from equatorial xz plane up and down.
  */
  double getLatitude()const;
  /** Returns theta angle from z axis downwards.
  */
  double getTheta()const;
  /** Returns length of vector, for convenience.
  */
  double getRadius()const;
  /** Returns degree value for angle. If angleMode is UseRadian, angle is returned unscaled.
  */
  double toDegree(double angle)const;
 /** Returns the longitude angle around y axis in radian, 360 degree or 400 new degree
   *according to angleMode.  Angle starts at z-axis.
   */
  double getLongitude()const;
 /** Returns phi angle around z axis in radian, 360 degree or 400 new degree
   *according to angleMode.
   */
  double getPhi()const;
  /** Multiplies vector with1/ f.
    */
  const C3dVector & operator /(double f)const;
  /** Sets polar coordinates. Z is up, phi in xy plane, theta from z downwards.
    */
  void setRadiusPhiTheta(double radius, double phi, double theta);
 /** Sets geographic coordinates. Y is up, longitude in xz plane, latitude
   * from xz plane up- and downwards.
   */
  void setRadiusLongitudeLatitude(double radius, double longitude, double latitude);
  /** Write property of int m_AngleMode.
  */
  static void setAngleMode( const int& _newVal);
  /** Read property of int m_AngleMode.
  */
  static const int& getAngleMode();
  /** Returns radian value for angle.
  */
  double toRadian(double angle)const;
  /** Calls glVertex3dv.
 */
  void vertex()const;
  /** Sets debugging counters to 0.
 */
  static void debugResetCounters();
  /** Returns scalar product. May be used instead of operator *.
   *  For vector product see function vectorMult.
   */
  double scalarMult(const C3dVector & v2)const;
 
protected: // Protected methods
  /** Copy function used by copy constructor and operator =.
  */
  void copy(const C3dVector & toCopy);
/**Copies x, y and z to the next (and hopefully free) buffer vector
  *from the buffer ring OpBufferVectors and returns its address.
  *The number of available buffer vectors is controlled by AvailableOpBufferVectors.
  *<b>There is no verification,
  *whether a buffer position is no longer used. Therefore, if you are
  *performing very deeply nested calculations, you may have to set
  *AvailableOpBufferVectors to a higher value. Use debugOutputStatistics() for debugging.</b>
 */
 static const C3dVector & getNextBuffer(double x, double y, double z);
public: // Public attributes
  /** 360 degree mode for polar coordinates.
  */
   static const int Use360Degree = 1;
  /** 400 new degree mode for polar coordinates.
 */
  static const int Use400NewDegree = 2;
  /** Radian mode for polar coordinates.
  */
  static const int UseRadian = 3;
  /** Number of buffer vectors available for calculations using
    *the C3dVector operators. See getNextBuffer.
    */
  static const int AvailableOpBuffers = 64;
protected: //Protected attributes
  //remove the dummy declaration, if your debugger works well without it.
 // char dummy; //neccessary for gdb 5.3 to show the correct formats of doubles!
  //DO NOT CHANGE order of declaration for m_X, m_Y, m_Z !! dv() and fv()will fail!!
  double m_X ;
  double m_Y;
  double m_Z;
  //DO NOT CHANGE order of declaration!! dv() and fv()will fail!!
  /** Use radian, 360 degrees or 400 new degrees.
    * Set with C3dVector::UseRadian, Use360Degree or Use400NewDegree.
    * Default: C3dVector::Use360Degree
    */
  static int m_AngleMode;
  /** Array with buffer vectors for return values of operators.
    */
  static C3dVector OpBufferVectors[AvailableOpBuffers];
  /**Number of the presently used buffer for calculations.
  */
  static int n_Buffer;

  #ifdef DEBUG_C3DVECTOR
  /**Maximum operator buffers used
  */ 
  static int n_MaxBuffers;
  /**Total number of operator calls
  */
  static int n_OperatorCalls;
  /**Total number of calls to function copy
  */
  static int n_CopyCalls;
  /**Total number of calls to constructors
  */
  static int n_ConstructorCalls;
  /**Total number of calls to dv, fv and vertex
  */
  static int n_VertexCalls;
private: // Private methods
  /** Counts the calls to operator functions.
  */
  static void debugOperators(const C3dVector * v1 = NULL, const C3dVector * v2 = NULL);
  #endif
};

  /** Returns f*v. For convenience.
    * Adds double * C3dVector functionality as suppliment to C3dVector operator *(double).
    */
const C3dVector & operator *(double f, const C3dVector& v);
  /** Returns v * (-1.0). For convenience.
    */
const C3dVector & operator -(const C3dVector& v);
 
/** Predefined global vectors for convenience.
*/
static C3dVector v_Zero = C3dVector(0,0,0);
static C3dVector v_X    = C3dVector(1,0,0);
static C3dVector v_Y    = C3dVector(0,1,0);
static C3dVector v_Z    = C3dVector(0,0,1);
static C3dVector v_XY   = C3dVector(1,1,0);
static C3dVector v_YZ   = C3dVector(0,1,1);
static C3dVector v_XZ   = C3dVector(1,0,1);
static C3dVector v_XYZ  = C3dVector(1,1,1);


#endif
