//
// C++ Interface: bb_toolnavigationlinenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLNAVIGATIONLINENEW_H
#define BB_TOOLNAVIGATIONLINENEW_H

#include <bb_toollinenew.h>

/**
Werkzeug zur Erstellung von Navigationslinien.

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolNavigationLineNew : public BB_ToolLineNew
{
public:
    BB_ToolNavigationLineNew(QWidget* parent);

    ~BB_ToolNavigationLineNew();

    virtual BB_Line* createNewLine(BB_Point* p1, BB_Point* p2);
    virtual BB_Line* getClickedLine(C2dVector& pos);
    virtual BB_Point* getClickedPoint(C2dVector& pos);

};

#endif
