//
// C++ Interface: bb_toolterraintrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTERRAINTRIANGLENEW_H
#define BB_TOOLTERRAINTRIANGLENEW_H

#include <bb_tooltrianglenew.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolTerrainTriangleNew : public BB_ToolTriangleNew
{
public:
    BB_ToolTerrainTriangleNew(QWidget* parent);

    ~BB_ToolTerrainTriangleNew();

    virtual BB_AbstractToolWidget* getToolWidget();
    virtual BB_Point* getClickedPoint(C2dVector& pos);
    virtual BB_Triangle* createNewSurface();

};

#endif
