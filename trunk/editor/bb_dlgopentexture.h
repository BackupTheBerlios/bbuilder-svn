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
#ifndef BB_DLGOPENTEXTURE_H
#define BB_DLGOPENTEXTURE_H

#include <QDialog>
#include "ui_textureOpenDialog.h"

/**
Ein Dialog zum Offnen von Texturen
Dieser Dialog benutzt in QT-Designer erstelte GUI und abgeleitet von QDialog
@see QT::QDialog
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_DlgOpenTexture : public QDialog
{
        Q_OBJECT;
    public:
        /**
        Standart Konstruktor
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        BB_DlgOpenTexture( QWidget * parent = 0, Qt::WFlags f = 0 );
        /**
        Dekonstruktor
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        ~BB_DlgOpenTexture();
        /**
        Gibt ausgewählte Dateiname zurück
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        QString getTextureFile() const;
        /**
        Setzt in GUI-Dialog schon vorausgewählte Dateiname
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        void setTextureFile( QString pfad );
    protected:
        /**
        GUI
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        Ui_textureOpenDialog m_Dlg;
    public slots:
        /**
        Wird aufgerufen, wenn beim Dateiauswahl auf "OK" geklick wurde<br>
        Setzt ausgewählte Dateiname in Dialog fest
        @author Vaceslav Ustinov <v.ustinov@web.de>
        */
        void slotTextureFileSearch();
};

#endif
