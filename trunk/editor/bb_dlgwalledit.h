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
#include "bb_tooltexture.h"
#include "bb_tooldelete.h"

/**
BB_DlgWallEdit ist ein haupt-Widget zum editieren von Wand-Eigenschaften<br>
Dieser Widget beeinhält in sich zwei weitere Komponente: BB_DlgWallEditArea BB_DlgWallEditPreview
In diesem Dialog koennen grafisch neu Fenster, Türen und etc eingefügt.
@author Vaceslav Ustinov
@date 24.11.2005
*/
class BB_DlgWallEdit : public QDialog
{
        Q_OBJECT
    public:
        /**
        Standart Konstruktor: <br>
        Es wird ein Dialog erzeugt, das die Objekte von BB_Wall verwalten kann<br>
        Deafult Wert für Höhe einer Wand ist 3.2 Meter
		@param wall Obejekt von einer Wand. Für diese Wand wird dann ein Dialog erzeugt
		@Param docComponent Etage mit der gearbeitet werden soll
		@param hohe Höhe der Wand
		@param parent Benötigt von QT
		@param f als Eigenschaft von Qt
        @author Vaceslav Ustinov
        */
        BB_DlgWallEdit( BB_Wall * wall, BB_DocComponent * docComponent , double hohe = 3.2, QWidget * parent = 0, Qt::WFlags f = 0 );
        /**
        Standart Dekonstruktor. Hier werden alle Objekte, 
        die in deisem Class erzeugt wurden, gelöscht
        @author Vaceslav Ustinov
        */
        ~BB_DlgWallEdit();
        /**
        Legt die Etage mit der gearbeitet werden soll fest
        @param Value Zeiger auf eine Etage
        @author Vaceslav Ustinov
        */
        void setLevel( BB_DocComponent* Value );
        /**
        Gibt ein Zeiger auf eine Etage zurück
        @return BB_DocComponent
        @author Vaceslav Ustinov
        */
        BB_DocComponent* getLevel() const;
        /**
        Setzt die Wand mit der gearbeitet werden soll
        @param Value Zeiger auf eine Wand
        @author Vaceslav Ustinov
        */
        void setWall( BB_Wall* Value );
        /**
        Gibt ein Zeiger von der Wand zurück
        @return BB_Wall
        @author Vaceslav Ustinov
        */
        BB_Wall* getWall() const;
        /**
        Diese Funktion öffnet ein kleines Dialog.<br>
        In diesem Dialog kann man dann die Textur fuer die Wand, Türe und Fenster auswählen.
        @author Vaceslav Ustinov
        */
        void openTextureDlg();
    protected:
        /**
        Abgeleitete Funktion zum Zeichen
        @param pe QPaintEvent
        @author Vaceslav Ustinov
        */
        void paintEvent ( QPaintEvent * pe );
        /**
        Abgeleitete Funktion zum Anpassen von Breite und Höhe<br>
        Wird aufgerufen wenn die Größe von Fenster geändert wurde
        @param re QResizeEvent
        @author Vaceslav Ustinov
        */
        void resizeEvent ( QResizeEvent * re );
        /**
        Funktion zum Initialisieren, wird vom Konstruktor verwendet.<br>
        Hintergrund: Debuger kann nicht auf Konstruktoren und Destruktren zugreifen
        @param wall BB_Wall Zeiger auf eine Wand
        @param docComponent BB_DocComponent Zeiger auf eine Etage
        @param hohe hohe von der Wand, Default 3.2 Meter
        @author Vaceslav Ustinov
        */
        void initilize( BB_Wall * wall, BB_DocComponent * docComponent, double hohe = 3.2 );
        /**
        Funktion zum intilisieren von Signalen
        @author Vaceslav Ustinov
        */
        void initSingals();
        /**
        Setzt die Eigenschaft checked allen, ausser in "button", Buttons auf false
        @param button QToolButton Zeiger auf einen Button. Dieser Button wird nicht auf False gesetzt
        @author Vaceslav Ustinov
        */
        void unsetButton( QToolButton * button );
    protected:
        /**
        Zeiger auf eine Etage
        */
        BB_DocComponent * m_level;
        /**
        Zeiger auf eine Wand
        */
        BB_Wall * m_wall;
        /**
        Zeiger auf Area-Widget von diesem Dialog
        */
        BB_DlgWallEditArea * m_CentralWidget;
        /**
        Zeiger auf Preview-Widget
        */
        BB_DlgWallEditPreview * m_PreviewWidget;

        //QRectF m_rect;
        //buttons
        /**
        Button zum Erzeugen von Fenster
        */
        QToolButton * m_ButtonWindow;
        /**
        Button zum Erzeugen von Türen
        */
        QToolButton * m_ButtonDoor;
        /**
        Button zum Bewegen von Objekten
        */
        QToolButton * m_ButtonMove;
        /**
        Button zum Erzeugen von Texturen
        */
        QToolButton * m_ButtonTexture;
        /**
        Button zum Löschen von Obekten
        */
        QToolButton * m_ButtonDelete;
        /**
        Vector mit allen Buttons
        */
        QVector<QToolButton *> * m_Buttons;

        //tools
        /**
        Tool zum Erzeugen von Türen
        */
        BB_ToolDoorNew * m_ToolDoorNew;
        /**
        Tool zum Erzeugen von Fenster
        */
        BB_ToolWindowNew * m_ToolWindowNew;
        /**
        Tool zum Bewegen von Objekten
        */
        BB_ToolMove * m_ToolMove;
        /**
        Tool zum Erzeugen von Texturen
        */
        BB_ToolTexture * m_ToolTexture;
        /**
        Tool zum Löschen von Objekten
        */
        BB_ToolDelete * m_ToolDelete;


    public slots:
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolDoorNew
        @author Vaceslav Ustinov
        */
        void slotToolDoor();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolWindowNew
        @author Vaceslav Ustinov
         */
        void slotToolWindow();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolMove
        @author Vaceslav Ustinov
         */
        void slotToolMove();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolTexture
        @author Vaceslav Ustinov
        */
        void slotToolTexture();
        /**
        setzt das Tool in BB_DlgWallEditArea auf BB_ToolDelete
        @author Vaceslav Ustinov
        */
        void slotToolDelete();
};

#endif
