//
// C++ Interface: bb_toolbuildingtrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLBUILDINGTRIANGLENEW_H
#define BB_TOOLBUILDINGTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolBuildingTriangleNew : public BB_ToolTriangleNew
{
public:
    BB_ToolBuildingTriangleNew(QWidget* parent);

    ~BB_ToolBuildingTriangleNew();

protected:
    virtual BB_Triangle* createNewSurface();

};

#endif
