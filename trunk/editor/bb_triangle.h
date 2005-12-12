//
// C++ Interface: bb_triangle
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TRIANGLE_H
#define BB_TRIANGLE_H

#include <bb_point.h>
#include <bb_line.h>

/**
@author Alex Letkemann
*/
class BB_Triangle : public BB_Line
{
public:
    BB_Triangle(BB_Point* p1, BB_Point* p2, BB_Point* p3 );

    ~BB_Triangle();

    virtual bool isHit(QRect rect);
    virtual bool isHit(C2dVector hit);
    virtual const QString getClassName();
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    
	
	//virtual void remove(BB_Point* point);

	/**
	 * Setzt die dritte Position (Ecke) der Trinagle.
	 * @param point Pointer auf einen Punkt. Wird auf NULL geprüft.
	 * @return False im Fehlerfall, sonst true
	 */
	bool setPos3(BB_Point* point);
	

	/**
	 * Gibt einen Pointer auf den Punkt der dritten Position zurück.
	 * @return Pointer auf den Punkt der dritten Position.
	 */
	BB_Point* getPos3() const;
    virtual void generateXElement(QTextStream &out, int depth);
	
	/** Pointer auf die dritte Position */
	BB_Point* m_Pos3;
};

#endif
