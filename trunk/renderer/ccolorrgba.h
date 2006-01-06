/***************************************************************************
                          ccolorrgba.h  - description
                             -------------------
    begin                : Tue Feb 6 2001
    copyright            : (C) 2001, 2003 by Walter Roth
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

#ifndef CCOLORRGBA_H
#define CCOLORRGBA_H


/** A color class that supports RGBA colors. Color is saved as 4 double values
  * 0.0 = black, 1.0 = full intensity.
  * The "A" value is for transparency (very practical for window panes).
  * 0.0 = transparent, 1.0 = opaque
  *@author Walter Roth
  */
# include <GL/gl.h>

class CColorRGBA {
 GLfloat m_R,m_G,m_B,m_A;  //DO NOT CHANGE order of declaration! Is used as GLdouble *!
public:
  /** Constructs a black color.
  */
  CColorRGBA();
  /** Constructs the specified color.
   */
  CColorRGBA(GLfloat r, GLfloat g, GLfloat b, GLfloat a =1.0);
  /** Destructor, does nothing.
  */
  virtual ~CColorRGBA();
  /**Returns a pointer to fR. To be used with GLColorXXXfv functions.
    */
  const GLfloat * fv() const; 
  /** For brightness adjustment. "a" value is not multiplied.
    */
  CColorRGBA operator *(double f);
  /** Returns Red value.
    */
  double getR();
  /** Copy operator.
  */
  CColorRGBA operator=(const CColorRGBA & toCopy);
  /** Returns Green value.
  */
  double getG();
  /** Copy constructor.
 */
   CColorRGBA (const CColorRGBA & toCopy);
  /** Returns Blue value.
  */
  double getB();
  /** Returns A (transparency) value.
  */
  double getA();
protected: // Protected methods
 /** Copy function. For internal use only. MUST be called by subclassed copy functions.
 */
  void copy(const CColorRGBA & toCopy);
};

/** Predefined global colors for convenience.
  */
static CColorRGBA cl_White      = CColorRGBA(1.0,1.0,1.0);
static CColorRGBA cl_Black      = CColorRGBA(0.0,0.0,0.0);
static CColorRGBA cl_Red        = CColorRGBA(1.0,0.0,0.0);
static CColorRGBA cl_Green      = CColorRGBA(0.0,1.0,0.0);
static CColorRGBA cl_Blue       = CColorRGBA(0.0,0.0,1.0);
static CColorRGBA cl_Gray       = CColorRGBA(0.5,0.5,0.5);
static CColorRGBA cl_Yellow     = CColorRGBA(1.0,1.0,0.0);
static CColorRGBA cl_Magenta    = CColorRGBA(1.0,0.0,1.0);
static CColorRGBA cl_Cyan       = CColorRGBA(0.0,1.0,1.0);

#endif
