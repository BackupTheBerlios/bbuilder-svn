//
// C++ Implementation: bb_widgettoolnavigationpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolnavigationpointnew.h"

BB_WidgetToolNavigationPointNew::BB_WidgetToolNavigationPointNew(BB_AbstractTool* parentTool, QWidget* parent): BB_AbstractToolWidget(parentTool, parent)
{
}


BB_WidgetToolNavigationPointNew::~BB_WidgetToolNavigationPointNew()
{
}


void BB_WidgetToolNavigationPointNew::clearToolWidget()
{
    BB_AbstractToolWidget::clearToolWidget();
}

void BB_WidgetToolNavigationPointNew::setWidgetEnabled(bool value)
{
    BB_AbstractToolWidget::setWidgetEnabled(value);
}

void BB_WidgetToolNavigationPointNew::updateWidget()
{
    BB_AbstractToolWidget::updateWidget();
}

