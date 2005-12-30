//
// C++ Interface: bb_toolwallnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLWALLNEW_H
#define BB_TOOLWALLNEW_H

#include <bb_toollinenew.h>

/**
Werkzeug zum erstellen von Wänden

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_ToolWallNew : public BB_ToolLineNew
{
public:
    BB_ToolWallNew(QWidget* parent = 0);

    ~BB_ToolWallNew();

    virtual BB_AbstractToolWidget* getToolWidget();

protected:
    virtual BB_Line* createNewLine(BB_Point* p1, BB_Point* p2);
    virtual BB_Line* getClickedLine(C2dVector& pos);

};

#endif
