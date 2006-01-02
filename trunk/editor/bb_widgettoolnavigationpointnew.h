//
// C++ Interface: bb_widgettoolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLNAVIGATIONPOINTNEW_H
#define BB_WIDGETTOOLNAVIGATIONPOINTNEW_H

#include <bb_abstracttoolwidget.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolNavigationPointNew : public BB_AbstractToolWidget
{
public:
    BB_WidgetToolNavigationPointNew(BB_AbstractTool* parentTool, QWidget* parent = 0);

    ~BB_WidgetToolNavigationPointNew();

    virtual void clearToolWidget();
    virtual void setWidgetEnabled(bool value);
    virtual void updateWidget();

};

#endif
