/***************************************************************************
                          ccolorrgba.cpp  -  description
                             -------------------
    begin                : Tue Feb 6 2001
    copyright            : (C) 2001 by Walter Roth
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

#include "ccolorrgba.h"

/** Constructs a black color.
*/
CColorRGBA::CColorRGBA(){
 m_R = 0.0;
 m_G = 0.0;
 m_B = 0.0;
 m_A = 1.0;
}
/** Constructs the specified color.
*/
CColorRGBA::CColorRGBA(GLfloat r, GLfloat g, GLfloat b, GLfloat a){
 m_R = r;
 m_G = g;
 m_B = b;
 m_A = a;
}
/** Copy constructor.
 */
CColorRGBA::CColorRGBA (const CColorRGBA & toCopy){
   copy(toCopy);
}

/** Destructor, does nothing.
*/
CColorRGBA::~CColorRGBA(){ 
}

const GLfloat * CColorRGBA::fv() const {
 return &m_R;
}

/** For brightness adjustment. "a" value is not multipiled.
*/
CColorRGBA CColorRGBA::operator *(double f){
 return CColorRGBA(m_R * f,
                   m_G * f,
                   m_B * f,
                   m_A);
}
/** Returns Red value. */
double CColorRGBA::getR(){
  return m_R;
}
/** Returns Green value. */
double CColorRGBA::getG(){
  return m_G;
}
/** Returns Blue value. */
double CColorRGBA::getB(){
  return m_B;
}
/** Returns A (transparency) value. */
double CColorRGBA::getA(){
  return m_A;
}
/** Copy operator.
 */
CColorRGBA CColorRGBA::operator = (const CColorRGBA & toCopy){
  copy(toCopy);
  return * this;
}
/** Copy function. For internal use only.
 */
void CColorRGBA::copy(const CColorRGBA & toCopy){
  m_R = toCopy.m_R;
  m_G = toCopy.m_G;
  m_B = toCopy.m_B;
  m_A = toCopy.m_A;
}
