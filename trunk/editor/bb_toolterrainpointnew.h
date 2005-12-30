//
// C++ Interface: bb_toolterrainpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTERRAINPOINTNEW_H
#define BB_TOOLTERRAINPOINTNEW_H

#include <bb_toolpointnew.h>

/**
 * Werkzeug zum Erstellen von TerrainPoints
 *
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolTerrainPointNew : public BB_ToolPointNew
{
public:
    BB_ToolTerrainPointNew();

    ~BB_ToolTerrainPointNew();

    /**
     * \fn BB_AbstractTool::getToolWidget()
     */
    virtual BB_AbstractToolWidget* getToolWidget();

protected:
    
	/**
 	 * \fn BB_ToolPointNew::createNewPoint(C2dVector& pos)
	 */
	virtual BB_Point* createNewPoint(C2dVector& pos);
	
    /**
	 * \fn BB_ToolPointNew::getClickedPoint(C2dVector& pos)
     */
    virtual BB_Point* getClickedPoint(C2dVector& pos);

};

#endif
