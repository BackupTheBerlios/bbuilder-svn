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
#include "bb_tooltexture.h"
#include "bb_constructionelement.h"
#include "bb_dlgwalledit.h"
#include <iostream>

using namespace std;

/**
Standart Konstruktor
@param parent Zeiger auf ein Widget zu dem dieser Tool gehört
@see BB_AbstractTool
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
BB_ToolTexture::BB_ToolTexture( QWidget *parent )
        : BB_AbstractTool( parent )
{
    m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolTexture.png" );
}

/**
Destruktor
*/
BB_ToolTexture::~BB_ToolTexture()
{}

/**
Ein Erreignis, wird aufgerufen wenn mann auf eine Mauste-Taste druckt
@param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
void BB_ToolTexture::click( QMouseEvent* me )
{
    m_pScreen = me->pos();
    m_Transformer->screenToLogical( m_pLogic, m_pScreen );
    BB_ConstructionElement * myElement;
    for ( int i = 0; i < m_Objects->count();i++ )
    {
        myElement = dynamic_cast<BB_ConstructionElement *>( m_Objects->at( i ) );
        if ( myElement != NULL )
        {
            if ( myElement->isHit( m_pLogic ) )
            {
                myElement->openTextureDlg();
                m_ParentWidget->update();
                return ;
            }
        }
    }
    ( ( BB_DlgWallEdit * ) m_ParentWidget ) ->openTextureDlg();
    m_ParentWidget->update();
}


