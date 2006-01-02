//
// C++ Interface: bb_toolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLNAVIGATIONPOINTNEW_H
#define BB_TOOLNAVIGATIONPOINTNEW_H

#include <bb_toolpointnew.h>
#include <bb_navigationpoint.h>

/**
Werkzeug zum Erstellen von Naviationspunkten

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolNavigationPointNew : public BB_ToolPointNew
{
public:
	BB_ToolNavigationPointNew(QWidget *parent);

    ~BB_ToolNavigationPointNew();
    virtual BB_AbstractToolWidget* getToolWidget();

protected:
    virtual BB_Point* createNewPoint( C2dVector& pos );
    virtual BB_Point* getClickedPoint( C2dVector& pos );
};

#endif
