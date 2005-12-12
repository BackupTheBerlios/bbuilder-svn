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

#include "bb_dlgwalleditarea.h"

/**
Ein Diaolog zum editieren von Wand-Eigenschaften.
In diesem Dialog koennen grafisch neu Fenster, Türen und etc eingefügt.
 
@author Vaceslav Ustinov
@date 24.11.2005
*/
class BB_DlgWallEdit : public QDialog
{
    public:
        BB_DlgWallEdit( QWidget * parent = 0, Qt::WFlags f = 0 );
        ~BB_DlgWallEdit();
        void setImage( QPixmap * Value );
        QPixmap * getImage() const;
    private:
        void initilize();
    protected:
        BB_DlgWallEditArea * m_CentralWidget;
		QPixmap * myImage;
};

#endif
