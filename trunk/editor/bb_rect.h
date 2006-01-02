//
// C++ Interface: bb_rect
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_RECT_H
#define BB_RECT_H

#include <bb_line.h>

/**
 * Stellt einen Recheck dar. Das Rechteck wird zwischen zwei Punkten P1 und P2 gespannt.
 * Das Rechteck selber speichert keine Koordinaten und hängt somit komplett von den beiden Punkten ab.
 * Wenn sich die Position der Punkte ändert, ändert sich auch die Position bzw. die Größe des Rechecks.
 * @todo !!!!!!!!!!
 *
 * p1 ___________
 *  |           |
 *  |___________| p2
 *  
 * @author Alex Letkemann
 * @date 26.10.2005
*/
class BB_Rect : public BB_Line
{
public:
	BB_Rect();
	BB_Rect(BB_Point* p1, BB_Point* p2);

    ~BB_Rect();
    virtual const QString getClassName();
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    bool isHit(const C2dVector &hit);
	virtual void moveBy( C2dVector pMove );

};

#endif
