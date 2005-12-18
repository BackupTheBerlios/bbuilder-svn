/***************************************************************************
                          C3dVector.cpp  -  for description see c3dvector.h
                             -------------------
    begin                : Mon Feb 5 2001
    copyright            : (C) 2001-2003 by Walter Roth
    email                : roth@mfh-iserlohn.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software{} you can redistribute it and/or modim_Y  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation{} either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "c3dvector.h"
#include <stdio.h>
int C3dVector::m_AngleMode = C3dVector::Use360Degree;
int C3dVector::n_Buffer = 0;
C3dVector C3dVector::OpBufferVectors[AvailableOpBuffers];

//The following counters are activated in debugging mode only
#ifdef DEBUG_C3DVECTOR
int C3dVector::n_MaxBuffers = 0;
int C3dVector::n_OperatorCalls = 0;
int C3dVector::n_CopyCalls = 0;
int C3dVector::n_ConstructorCalls = 0;
int C3dVector::n_VertexCalls = 0;
#endif

/** Standard  constructor, creates a zero vector
    */
C3dVector::C3dVector(){
 #ifdef DEBUG_C3DVECTOR
  n_ConstructorCalls ++;
 #endif 
 m_X = 0;
 m_Y = 0;
 m_Z = 0;
 
}

/**Destructor, presently it does nothing.
    */
C3dVector::~C3dVector(){
}

C3dVector::C3dVector(double x, double y, double z){
 #ifdef DEBUG_C3DVECTOR
  n_ConstructorCalls ++;
 #endif
 m_X = x;
 m_Y = y;
 m_Z = z;
}

/** Constructor for polar coordinates. Pass UseRadian, Use360Degree or Use400NewDegree as
    * value for angleMode.
    */
C3dVector::C3dVector(int angleMode, double radius, double longitude, double latitude){
 #ifdef DEBUG_C3DVECTOR
  n_ConstructorCalls ++;
 #endif
  int oldAngleMode = getAngleMode();
  setAngleMode(angleMode);
  setRadiusLongitudeLatitude(radius, longitude, latitude);
  setAngleMode(oldAngleMode);
}

/** Copy constructor. Calls copy() function.
    */
C3dVector::C3dVector(const C3dVector& toCopy){
 #ifdef DEBUG_C3DVECTOR
  n_ConstructorCalls ++;
 #endif
 copy(toCopy);
}


/** Read property for x coordinate.
    */
double C3dVector::x(){
  return m_X;
}

/** Write property for x coordinate.
    */
void C3dVector::setX(double _newVal){
 m_X = _newVal;
}

/** Read property for y coordinate.
    */
double C3dVector::y(){
   return m_Y;
}

/** Write property for y coordinate.
    */
void C3dVector::setY(double _newVal){
 m_Y = _newVal;
}

/** Read property for z coordinate.
    */
double C3dVector::z(){
  return m_Z;
}

/** Write property for z coordinate.
    */
void C3dVector::setZ(double _newVal){
 m_Z = _newVal;
}

/** Returns vector with length 1.0 and same direction as  *this.
    */
const C3dVector & C3dVector::unitVector()const{
 C3dVector v1;
 double aLength;
 aLength= getLength();
 if (aLength != 0)  
  return getNextBuffer(m_X / aLength,
                       m_Y / aLength,
                       m_Z / aLength);
  else {
   qDebug("C3dVector::unitVector: Can not scale a zero vector to length 1.0");
   return getNextBuffer(0.0, 0.0, 0.0);
  }                   
}

/** Scalar product.
   */
double C3dVector::operator *( const C3dVector& v2 )const{
 return  m_X * v2.m_X + m_Y * v2.m_Y + m_Z * v2.m_Z;
}

/** Vector product *this X v2.
    */
const C3dVector & C3dVector::vectorMult( const C3dVector& v2)const{
 return getNextBuffer(
   m_Y * v2.m_Z - m_Z * v2.m_Y,
   m_Z * v2.m_X - m_X * v2.m_Z,
   m_X * v2.m_Y - m_Y * v2.m_X);
}

/** Normal vector with length 1.0 obtained by *this X v2.
   */
const C3dVector & C3dVector::getNormalVector(const C3dVector& v2)const{
 /*C3dVector v = vectorMult(v2);
 v = v.unitVector();
 return getNextBuffer(v.m_X, v.m_Y, v.m_Z);*/
 return vectorMult(v2).unitVector();
}

/** Caculates the length.
   */
double C3dVector::getLength()const{
 return sqrt(m_X * m_X + m_Y * m_Y + m_Z * m_Z);
}

//****************Function RotateVector************************************
//First get the projection of v1 on rotation axis. Then make a 2d axis
//system where Rotation.axis is normal to. xNew is the first axis of this
//system xNew = v1 - Av1(Projection of v1 on Rotation.Axis). The second axis
//yNew is obtained by vectormultiplication of Av1 and xNew divided by |Av1|.
//this has the same length as xNew and is normal to xNew and Rotation.Axis.
//Now xNew can easily be rotated in a 2d coordinate system made by xNew and
//yNew. The result is xRotated. The result of rotating v1 is Av1 + xRotated.

const C3dVector C3dVector::rotateVector(const C3dVector& Axis, double Angle)const{
C3dVector vAxis = Axis; //local copy
C3dVector Av1     ; //Projection of v1 on Rotation Axis
C3dVector xNew    ; //v1-Av1 first vector in plane of rotation
C3dVector yNew    ; //second vector in plane of rotation
C3dVector xRotated; //result of rotation of xnew by Rotation.Theta
C3dVector xNewComp; //xNew component of xRotated in xNew, yNew plane
C3dVector yNewComp; //yNew component of xRotated in xNew, yNew plane
double     AbsAxis;    // |Rotation Axis|
double     AbsAv1 ;    // |Av1|
double   radAngle = toRadian(Angle);
 // precalculate lengths
 AbsAxis = vAxis.getLength();  // precalculate length of Axis
 AbsAv1  = (*this * vAxis )/ AbsAxis ;   // precalculate length of Av1

 //get projection of v1 on Axis
 Av1     = vAxis * AbsAv1 ;

 // Make a cartesian xNew,yNew plane with equal xNew and yNew lengths.
 // Because xNew is normal to Axis, sin(Axis, xNew) is 1
 xNew    = * this - Av1; //keep length != 1 for speed
 yNew    = vAxis.vectorMult(xNew) * ( 1.0 / AbsAxis );

 // Rotate xNew in xNew, yNew plane by Theta
 xNewComp= xNew * cos( radAngle );
 yNewComp= yNew * sin( radAngle );
 xRotated= xNewComp + yNewComp;

 //Add Av1 and xRotated to get final result
 return Av1 + xRotated;
}

/** Returns the vectorsum of v1 and v2. */
const C3dVector & C3dVector::operator+(const C3dVector& v2)const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators(this, &v2);
 #endif
 return getNextBuffer (m_X + v2.m_X,
                       m_Y + v2.m_Y,
                       m_Z + v2.m_Z);
}
/** Returns this - v2. */
const C3dVector & C3dVector::operator-(const C3dVector& v2)const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators(this, &v2);
 #endif
 return getNextBuffer (m_X - v2.m_X,
                       m_Y - v2.m_Y,
                       m_Z - v2.m_Z);
}

/** For use with glXXXX3dv functions. */
GLdouble * C3dVector::dv()const{
  #ifdef DEBUG_C3DVECTOR
   n_VertexCalls ++;
  #endif
 return (GLdouble *)&m_X;
}
/** Stretches a vector to x*sx, y*sy, z*sz. */
const C3dVector & C3dVector::stretchVector(double sx, double sy, double sz)const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators();
 #endif
 return getNextBuffer( m_X * sx, m_Y * sy,m_Z * sz);
}

/** Multiplies vector with f. */
const C3dVector & C3dVector::operator *(double f)const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators();
 #endif
 return getNextBuffer(m_X *f,
                      m_Y *f,
                      m_Z *f);
}
/** Returns address of m_X for glXXXfv functions.
*/
GLfloat * C3dVector::fv()const{
  #ifdef DEBUG_C3DVECTOR
   n_VertexCalls ++;
  #endif
 return (GLfloat *)&m_X;
}
/** Returns true, if all coordinates are 0.
*/
bool C3dVector::isNull()const{
 return ((m_X == 0) & (m_Y ==0) & (m_Z==0));
}
/** Compares two vectors.
  * Will only return true if ALL digits of the double coordinates are the same.
  */
bool C3dVector::operator == (const C3dVector& v2) const{
 return ((v2.m_X == m_X) & (v2.m_Y == m_Y) & (v2.m_Z== m_Z));
}
/** Compares two vectors. */
bool C3dVector::operator != (const C3dVector& v2) const{
 return ! (*this == v2);
}
/** Copy function used by copy constructor and operator =. */
void C3dVector::copy(const C3dVector & toCopy){
  if(this!= & toCopy){ //no self copy
     m_X = toCopy.m_X;
     m_Y = toCopy.m_Y;
     m_Z = toCopy.m_Z;
  }
 #ifdef DEBUG_C3DVECTOR
   n_CopyCalls ++;
 #endif
}
/** Copies toCopy and returns * this. */
C3dVector & C3dVector::operator = (const C3dVector & toCopy){
  copy(toCopy);
  return *this;
}
/** Multipies 3d Vector with 4*4 matrix. 4th coordinate of vector is assumed to be 1.0.
   * Calculations run on main fpu. Use glMultMatrix for calculation on graphics processor.
   */
const C3dVector & C3dVector::operator *(const CGLMatrix & m) const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators();
 #endif
  CGLMatrix myM = m; //local copy
  GLfloat *pm = myM.getMatrix();  //call non - const member function for local copy
  return getNextBuffer(
    pm[0] * m_X + pm[4] * m_Y + pm[8] * m_Z + pm[12],   //use fast single index zero based addressing
    pm[1] * m_X + pm[5] * m_Y + pm[9] * m_Z + pm[13],
    pm[2] * m_X + pm[6] * m_Y + pm[10] * m_Z + pm[14]
  );
} 
/** Writes list of coordinates to stderr. */
void C3dVector::debugOutput(const QString & caption)const{
// 	qDebug(debugString(caption).toStdString());
}
/** Returns the debug output string.
*/
QString C3dVector::debugString(const QString & caption)const{
  QString sx,sy,sz, msg;
  return QString( caption + " C3dVector  x: " + sx.setNum(m_X, 'g', 4) +" y: " + sy.setNum(m_Y, 'g', 4)+
  " z: " + sz.setNum(m_Z, 'g', 4));  
}

/** Returns length of vector, for convenience.
 */
double C3dVector::getRadius()const{
  return getLength();
}
/** Returns latitude angle form equatorial xz plane up and down.
 */
double C3dVector::getLatitude()const{
  double lengthXZ = sqrt(m_X * m_X + m_Z * m_Z);

  double latitude;
  if (lengthXZ !=0.0)
   latitude= atan(m_Y / lengthXZ);
  else{
     if( m_Y > 0.0)
      latitude = M_PI /2.0;
     else latitude = - M_PI /2.0;
  }
  return toDegree(latitude);
}
/** Returns theta angle from z axis downwards.
 */
double C3dVector::getTheta()const{
  double lengthXY = sqrt(m_X * m_X + m_Y * m_Y);

  double theta;
  if (lengthXY !=0.0)
   theta= atan(m_Z / lengthXY) + M_PI /2.0;
  else{
     if( m_Z > 0.0)
      theta = 0.0;
     else theta = - M_PI;
  }
  return toDegree(theta);
}
/** Returns radian value for angle.
 */
double C3dVector::toRadian(double angle)const{
  if(m_AngleMode == C3dVector::Use360Degree)
    return angle * M_PI / 180.0;
  else {
    if(m_AngleMode == C3dVector::Use400NewDegree)
      return angle * M_PI / 200.0;
    else return angle;
  }
}
/** Returns degree value for angle. If m_AngleMode is UseRadian, angle is returned unscaled.
*/
double C3dVector::toDegree(double angle)const{
  if(m_AngleMode == C3dVector::Use360Degree)
    return angle / M_PI * 180.0;
  else {
    if(m_AngleMode == C3dVector::Use400NewDegree)
      return angle / M_PI * 200.0;
    else return angle;
  }
}
/** Returns the longitude angle around y axis in radian, 360 degree or 400 new degree
according to angleMode.  Angle starts at z-axis.*/
double C3dVector::getLongitude()const{
  double longitude;
  if(m_Z == 0.0){
      if(m_X > 0.0)
         longitude = M_PI /2.0;
      else longitude = -M_PI /2.0;
    }
  else longitude = atan(m_X / m_Z);
  if((m_Z < 0.0) & (m_X > 0.0))
   longitude += M_PI;
  if((m_X <0.0)&(m_Z<0.0))
   longitude -= M_PI;
  return toDegree(longitude);
}

/** Returns phi angle around z axis in radian, 360 degree or 400 new degree
according to angleMode. */
double C3dVector::getPhi()const{
  double phi;
  if(m_X == 0.0){
      if(m_Y >0.0)
         phi = M_PI /2.0;
      else phi = -M_PI /2.0;
    }
  else phi = atan(m_Y / m_X);
  if((m_X < 0.0) & (m_Y > 0.0) | (m_Y <0.0)&(m_X<0.0))
   phi += M_PI;
  return toDegree(phi);
}

/** Multiplies vector with1/ f.
 */
const C3dVector & C3dVector::operator /(double f)const{
 #ifdef DEBUG_C3DVECTOR
  debugOperators();
 #endif
    if (f !=0.0){
       double f1= 1.0 / f; 
       return getNextBuffer(m_X * f1, m_Y * f1, m_Z * f1);
    }
    else{
      qDebug("Vector division by zero. Returning zero vector." );
      return getNextBuffer(0.0,0.0,0.0);
    }
}
/** Sets polar coordinates. Z is up, phi in xy plane, theta from z downwards.
  */
void C3dVector::setRadiusPhiTheta(double radius, double phi, double theta){
  phi = toRadian(phi);
  theta = toRadian(theta);
  m_X = radius * sin(theta)* cos(phi);
  m_Y = radius * sin(theta)*sin(phi);
  m_Z = radius * cos(theta);
}

/** Sets geographic coordinates. Y is up, longitude in xz plane, latitude from xz plane up- and downwards.
  */
void C3dVector::setRadiusLongitudeLatitude(double radius, double longitude, double latitude){
  double radLongitude = toRadian(longitude); // may be more than +-180 degree
  double radLatitude = toRadian(latitude);
  //Not more than +- 90 degree.
  if(radLatitude > M_PI / 2.0)
    radLatitude = M_PI/ 2.0;
  if(radLatitude < -M_PI / 2.0)
    radLatitude = -M_PI/ 2.0;
  m_X = radius * sin(radLongitude)* cos(radLatitude);
  m_Y = radius * sin(radLatitude);
  m_Z = radius * cos(radLongitude)* cos(radLatitude);
}

/** Read property of int m_AngleMode. */
const int& C3dVector::getAngleMode(){
	return C3dVector::m_AngleMode;
}
/** Write property of int m_AngleMode. */
void C3dVector::setAngleMode( const int& _newVal){
	C3dVector::m_AngleMode = _newVal;
}
/** Calls glVertex3dv.
 */
void C3dVector::vertex()const{
  #ifdef DEBUG_C3DVECTOR
   n_VertexCalls ++;
  #endif
  glVertex3dv(& m_X);
}
/**Copies x, y and z to the next (and hopefully free) buffer vector
  *from the buffer ring OpBuffer and returns its address.
  *The number of available buffer vectors is controlled by AvailableOpBuffers.
  *<b>There is no verification,
  *whether a buffer position is no longer used. Therefore, if you are
  *performing very deeply nested calculations, you may have to set
  *m_BufferVectors to a higher value.</b>
 */
const C3dVector & C3dVector::getNextBuffer(double x, double y, double z){
  n_Buffer++;
  if(n_Buffer >= AvailableOpBuffers) //take the first after the last vector
   n_Buffer = 0;
  OpBufferVectors[n_Buffer].m_X = x;
  OpBufferVectors[n_Buffer].m_Y = y;
  OpBufferVectors[n_Buffer].m_Z = z;
  #ifdef DEBUG_C3DVECTOR
   if(C3DVECTOR_DEBUG_LEVEL > 2){
     QString sNumber;
     sNumber.setNum(n_Buffer);
     C3dVector v(x,y,z);
     v.debugOutput("C3dVector buffer number:" + sNumber);
   }
  #endif
  return OpBufferVectors[n_Buffer];
}
/** Counts the calls to operator functions.
*/
#ifdef DEBUG_C3DVECTOR
void C3dVector::debugOperators(const C3dVector * v1, const C3dVector * v2){
  n_OperatorCalls ++;
  if(C3DVECTOR_DEBUG_LEVEL >1
   && v1 >= &OpBufferVectors[0] && v1 < &OpBufferVectors[AvailableOpBuffers]
   && v2 >= &OpBufferVectors[0] && v2 < &OpBufferVectors[AvailableOpBuffers]){
     int depth = v2 - v1;
     if(depth < 0) depth = depth + n_MaxBuffers;
     depth ++; //one buffer is minimum
     if(depth < AvailableOpBuffers){ //address is within buffer range
      if(depth > n_MaxBuffers){
        n_MaxBuffers = depth;   //set debugging breakpoint here
        QString sNumber;
        sNumber.setNum(depth);
//         qDebug("C3dVector::debugOperators: Maximum operator buffers used: " + sNumber);
    }
   }
  }//end if debug level
}
#endif
/** Produces a debug output of the number of operations, constructoir calls etc.
 */
void C3dVector::debugOutputStatistics(){
  #ifdef DEBUG_C3DVECTOR
  char msg[255];
  if(C3DVECTOR_DEBUG_LEVEL >1)
   sprintf(msg, "C3dVector statistics: Constructor calls: %i Copy calls: %i Vertex calls: %i Operator calls: %i Maximum buffers used: %i",
   n_ConstructorCalls, n_CopyCalls, n_VertexCalls, n_OperatorCalls, n_MaxBuffers);
  else
   sprintf(msg, "C3dVector statistics: Constructor calls: %i Copy calls: %i Vertex calls: %i Operator calls: %i",
   n_ConstructorCalls, n_CopyCalls, n_VertexCalls, n_OperatorCalls);
  qDebug(msg);
  #else
   qDebug("Debugging is switched off. Compile with -D DEBUG_C3DVECTOR to switch on");
  #endif
}
/** Sets debugging counters to 0.
 */
void C3dVector::debugResetCounters(){
  #ifdef DEBUG_C3DVECTOR
   n_ConstructorCalls = 0;
   n_CopyCalls = 0;
   n_VertexCalls = 0;
   n_OperatorCalls = 0;
   n_MaxBuffers = 0;
   n_Buffer = 0;
   for (int i = 0; i < AvailableOpBuffers; i++){
     OpBufferVectors[i] = v_Zero;
   }  
  #else
   qDebug("Debugging is switched off. Compile with -D DEBUG_C3DVECTOR to switch on");
  #endif
}
/** Returns scalar product.
 */
double C3dVector::scalarMult(const C3dVector & v2)const{
  //Source code copied from operator * for speed reasons.
 return  m_X * v2.m_X
        +m_Y * v2.m_Y
        +m_Z * v2.m_Z;
}
/** Returns f*v. For convenience.  Adds double * C3dVector functionality as suppliment to C3dVector operator *(double).
 */
const C3dVector & operator *(double f, const C3dVector& v){
  return v * f;   //call operator * of C3dVector class
}
/** Returns v * (-1.0). For convenience.
 */
const C3dVector & operator -(const C3dVector& v2){
  return v2 * (-1.0);
}
