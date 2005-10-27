/***************************************************************************
                          c2dvector.cpp  -  description
                             -------------------
    begin                : Di Nov 18 2003
    copyright            : (C) 2003 by Walter Roth
    email                : Please get the address from www.fh-swf.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "c2dvector.h"

#include <iostream>

using namespace std;

const char * C2dVector::ClassName = "C2dVector";

/** Standard constructor, accepts no to all parameters.
*/
C2dVector::C2dVector(double x , double y){
  m_X = x;
  m_Y = y;
}
/** Virtual destructor
*/
C2dVector::~C2dVector(){
}
/** Read property of double m_X. */
const double& C2dVector::x()const{
	return m_X;
}
/** Write property of double m_X. */
void C2dVector::setX( const double& _newVal){
	m_X = _newVal;
}
/** Read property of double m_Y. */
const double& C2dVector::y()const{
	return m_Y;
}
/** Write property of double m_Y. */
void C2dVector::setY( const double& _newVal){
	m_Y = _newVal;
}
/** Returns vector length.
 */
double C2dVector::getLength()const{
  return sqrt(m_X * m_X + m_Y * m_Y);
}
/** Returns vector with length 1.0 perpendicular to this. (counterclockwise)
 */
C2dVector C2dVector::getNormalVector()const{
  double length = getLength();
  return C2dVector(-m_Y / length, m_X / length);
}                                   
/** Returns vector sum this + v2.
 */
C2dVector C2dVector::operator + (const C2dVector & v2)  const{
  return C2dVector(m_X + v2.m_X,
                   m_Y + v2.m_Y);
}
/** Returns: this - v2.
 */
C2dVector C2dVector::operator - (const C2dVector & v2)const{
  return C2dVector(m_X - v2.m_X,
                   m_Y - v2.m_Y);
}

/** Adds object data as a node to the QDomDocument. */ 
/*
QDomElement C2dVector::createDomElement(QDomDocument & doc)const{
  QDomElement tag = doc.createElement( getClassName() ); 
  tag.setAttribute("x",x());  
  tag.setAttribute("y",y());  
  return tag;
 }
 */

 /** Virtual function, that returns the classname
*/
const char * C2dVector::getClassName()const{
 return C2dVector::ClassName;
}


double C2dVector::getAbstand(C2dVector v2)
{
	double abstand = sqrt((double)((m_X - v2.x()) * (m_X - v2.x())) + ((m_Y - v2.y()) * (m_Y - v2.y())));
	return abstand;
}





/*!
    \fn C2dVector::print()
 */
void C2dVector::print()
{
	cout << "x: " << m_X << "--y: "<< m_Y<<endl;
}


/*!
    \fn C2dVector::operator == (const C2dVector & v2) const
 */
bool C2dVector::operator == (const C2dVector & v2) const
{
	return (m_X == v2.x() && m_Y == v2.y());
}
