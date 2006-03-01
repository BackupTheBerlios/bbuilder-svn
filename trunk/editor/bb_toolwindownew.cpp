/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                      *
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
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "bb_toolwindownew.h"
#include "bb_window.h"

/**
Standart Konstruktor
@param parent Zeiger auf ein Widget zu dem dieser Tool gehört
@see BB_AbstractTool
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
BB_ToolWindowNew::BB_ToolWindowNew( QWidget *parent )
        : BB_AbstractTool( parent )
{
    m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolWindow.png" );
}

/**
Destruktor
*/
BB_ToolWindowNew::~BB_ToolWindowNew()
{}

/**
Ein Erreignis, wird aufgerufen wenn mann auf eine Mauste-Taste druckt
@param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
void BB_ToolWindowNew::click( QMouseEvent* me )
{
    m_pScreen = me->pos();
    m_Transformer->screenToLogical( m_pLogic, m_pScreen );
    m_LastLogicMouseClick = m_pLogic;
    BB_Window * tmpWindow = new BB_Window( m_pLogic, C2dVector( m_pLogic.x() + 1, m_pLogic.y() - 1 ) );
    tmpWindow->setTextureAbsoluteFileName( IMG_DIR() + SEPARATOR() + "window.png" );
    m_Objects->append( tmpWindow );
}

/**
Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
@param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
void BB_ToolWindowNew::move( QMouseEvent* me, bool overX, bool overY )
{}

/**
Wird aufgerufen, wenn eine Maustaste los gelassen wird.
@param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
void BB_ToolWindowNew::release( QMouseEvent* me )
{}

