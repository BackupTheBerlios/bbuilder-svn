/***************************************************************************
*   Copyright (C) 2005 by Vacesav Ustinov   						*
*   v.ustinov@web.de   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
***************************************************************************/
#ifndef BB_TOOLLINENEW_H
#define BB_TOOLLINENEW_H

#include <bb_abstracttool.h>
#include "bb_wall.h" 
//#include "bb_drawobject.h"

/**
dokumentation
 
@author Vacesav Ustinov, Alex Letkemann (Änderungen)
*/
class BB_ToolLineNew : public BB_AbstractTool
{
    public:
        BB_ToolLineNew();
        BB_ToolLineNew( QWidget *parent );

        ~BB_ToolLineNew();

        virtual void click( QMouseEvent* me );
        virtual void move( QMouseEvent* me, bool overX, bool overY );
        virtual void release( QMouseEvent* me );
        virtual BB_AbstractToolWidget* getToolWidget();
    protected:
//         BB_DrawObject * m_movedPoint;

        // EDIT: Alex Letkemann
        // Name angepasst ...
        BB_Line * m_Tmp_Line;
        BB_Point m_MovePoint;

    protected:
        virtual BB_Point* getClickedPoint( C2dVector& pos );
    virtual BB_Line* createNewLine( BB_Point* p1, BB_Point* p2 );
	virtual BB_Line* getClickedLine( C2dVector& pos );
};

#endif
