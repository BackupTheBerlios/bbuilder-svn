//
// C++ Interface: bb_navigationline
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_NAVIGATIONLINE_H
#define BB_NAVIGATIONLINE_H

#include <bb_line.h>
#include <bb_navigationpoint.h>

/**
Navigationslinie. Verbindet zwei Navigationsknoten.

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_NavigationLine : public BB_Line
{
public:
    BB_NavigationLine(BB_Point* p1, BB_Point* p2);

    ~BB_NavigationLine();
    virtual const QString getClassName();

};

#endif
