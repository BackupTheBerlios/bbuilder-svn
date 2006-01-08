//
// C++ Interface: bb_toolleveltrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLLEVELTRIANGLENEW_H
#define BB_TOOLLEVELTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
Werkzeug zum markieren von Decken und Böden bei den Etagen

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolLevelTriangleNew : public BB_ToolTriangleNew
{
public:
    BB_ToolLevelTriangleNew(QWidget* parent);

    ~BB_ToolLevelTriangleNew();

    virtual BB_Triangle* createNewSurface();

};

#endif
