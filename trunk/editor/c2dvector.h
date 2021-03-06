/***************************************************************************
                         c2dvector.h  -  A 2d vector class
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

#ifndef C2DVECTOR_H
#define C2DVECTOR_H

//#include <qdom.h>

/**A vector with 2 double coordinates. Used for vector maths.
  *Get functions are called x() and y().
  *@author Walter Roth, Alex Letkemann (Änderungen), Vaceslav Ustinov (Änderungen)
  */
#include <math.h>

class C2dVector
{
    public:
        /** Standard constructor, accepts no to all parameters.
        */
        C2dVector( double x = 0, double y = 0 );
        /** Virtual destructor
        */
        virtual	~C2dVector();
        /** Write property of double m_X.
        */
        virtual void setX( const double& _newVal );
        /** Read property of double m_X.
        */
        virtual const double& x() const;
        /** Write property of double m_Y.
        */
        virtual void setY( const double& _newVal );
        /** Read property of double m_Y.
        */
        virtual const double& y() const;
        /** Returns vector with length 1.0 perpendicular to this.
        */
        C2dVector getNormalVector() const;
        /** Returns vector length.
        */
        virtual double getLength() const;
        /** Gibt den Abstand zwischen zwei Punkten zurück.
        */
        virtual double getAbstand( C2dVector v2 );
        /**Return: Winkel von diesem Vektror zum X-Achse
        */
        virtual double getWinkel();
        /** Returns vector sum this + v2.
        */
        virtual C2dVector operator + ( const C2dVector & v2 ) const;
        /** Returns: this - v2.
        */
        virtual C2dVector operator - ( const C2dVector & v2 ) const;

        const char * getClassName() const;
		
		/** Prints the vector to console
		 */
        void print(char c[] = "");
		
		
        /**
         * Compares the vector with an another vector
         * @param v2 second vector to compare
         * @return true if its equal
         */
        bool operator == ( const C2dVector & v2 ) const;

        /**
         * Returns this * skalar
         * @author Alex Letkmann
         */
        virtual C2dVector operator * ( const double value ) const;

        /**
         * Returns a vector that is rotated by 'angle'-degrees from this
         * @author Alex Letkemann
         */
        C2dVector rotate( double angle ) const;

        /**
         * Returns a vector with the length of 1.0
         * and the direction of this vctor
         */
        C2dVector unitVector();
    protected:  // Protected attributes
        /** X coordinate.
        */
        double m_X;
        /** Y coordinate.
        */
        double m_Y;
    private:
        static const char * ClassName;
};

#endif
