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
#ifndef BB_DLGWALLEDIT_H
#define BB_DLGWALLEDIT_H

#include <QDialog>

#include "bb_doccomponent.h"
#include "bb_dlgwalleditarea.h"
#include "bb_dlgwalleditpreview.h"
#include "bb_wall.h"
#include "bb_toolwindownew.h"
#include "bb_toolmove.h"

/**
Ein Diaolog zum editieren von Wand-Eigenschaften.
In diesem Dialog koennen grafisch neu Fenster, Türen und etc eingefügt.
 
@author Vaceslav Ustinov
@date 24.11.2005
*/
class BB_DlgWallEdit : public QDialog
{
        Q_OBJECT
    public:
        /**
        Standart Konstruktor: Es wird ein Dialog erzeugt, das die Objekte von BB_Wall verwalten kann
        @param BB_Wall
        @Param BB_DocComponent
        @param QWidget von QT
        @param Qt::WFlags als Eigenschaft von Qt
        */
        BB_DlgWallEdit( BB_Wall * wall, BB_DocComponent * docComponent , QWidget * parent = 0, Qt::WFlags f = 0 );
        ~BB_DlgWallEdit();
        /**
        Legt die Etage mit der gearbeitet werden soll fest
        @param BB_DocComponent
        */
        void setLevel( BB_DocComponent* Value );
        /**
        Gibt ein Zeiger auf eine Etage zuruck
        @return BB_DocComponent 
        */
        BB_DocComponent* getLevel() const;
        void setWall( BB_Wall* Value );
        BB_Wall* getWall() const;
    protected:
        void paintEvent ( QPaintEvent * pe );
        void resizeEvent ( QResizeEvent * re );
        /**
        Funktion zum Initialisieren, wird vom Konstruktor verwendet.
        @param BB_Wall
        @Param BB_DocComponent
        */
        void initilize( BB_Wall * wall, BB_DocComponent * docComponent );
        void initSingals();
    protected:
        BB_DocComponent * m_level;
        BB_Wall * m_wall;
        BB_DlgWallEditArea * m_CentralWidget;
        BB_DlgWallEditPreview * m_PreviewWidget;
        QRect m_rect;
        //buttons
        QToolButton * m_ButtonWindow;
        QToolButton * m_ButtonDoor;
        QToolButton * m_ButtonMove;

        //tools
        BB_ToolDoorNew * m_ToolDoorNew;
        BB_ToolWindowNew * m_ToolWindowNew;
        BB_ToolMove * m_ToolMove;


    public slots:
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolDoorNew
        */
        void slotToolDoor();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolWindowNew
         */
        void slotToolWindow();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolMove
         */
        void slotToolMove();
};

#endif
