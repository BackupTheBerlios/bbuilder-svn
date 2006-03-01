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
#ifndef BB_DLGWALLEDITAREA_H
#define BB_DLGWALLEDITAREA_H 
//QT includes
#include <QLabel> 
//Local Includes
#include "bb_map.h"
#include "bb_wall.h"
#include "bb_doccomponent.h"
#include "bb_abstracttoolwalledit.h"
#include "bb_tooldoornew.h"

/**
Cetral Widget in BB_DlgWallEdit.<br>
BB_DlgWallEditArea ist von QLabel abgeleitet.<br>
Dieses Widget dient zum Edittieren einer Wand.
Hier werden Türen und Fenster plaziert
@author Vaceslav Ustinov
*/
class BB_DlgWallEditArea : public QLabel
{
    public:
        /**
        Standart Konstruktor: <br>
        Es wird ein Dialog erzeugt, das die Objekte von BB_Wall verwalten kann<br>
        Deafult Wert für Höhe einer Wand ist 3.2 Meter
        @param BB_Wall Obejekt von einer Wand. Für diese Wand wird dann ein Dialog erzeugt
        @Param BB_DocComponent Etage mit der gearbeitet werden soll
        @param QWidget Benötigt von QT
        @param Qt::WFlags als Eigenschaft von Qt
        */
        BB_DlgWallEditArea( BB_Wall * wall, BB_DocComponent * docComponent, double hohe = 3.2, QWidget * parent = 0, Qt::WFlags f = 0 );
        /**
        Standart Dekonstruktor. Hier werden alle Objekte, 
        die in deisem Class erzeugt wurden, gelöscht
        */
        ~BB_DlgWallEditArea();
        /**
        Setzt das Tool <b>tool</b> als aktiv (ausgewählt) ein
        @param BB_AbstractTool
        */
        void setTool( BB_AbstractTool * tool );
        /**
        Lädt die Textur für die Wand herunter
        */
        void loadTexture();
    protected:
        /**
        Zeiger auf BB_Map
        */
        BB_Map * m_currentMap;
        /**
        Zeiger auf BB_Wall
        */
        BB_Wall * m_Wall;
        /**
        Höhe in Meter
        */
        double m_Height;
        /**
        Breite in Meter
        */
        double m_Width;
        /**
        Höhe in Pixel
        */
        double m_PixelHeight;
        /**
        Breite in Pixel
        */
        double m_PixelWidth;
        /**
        Proportion zwieschen Breite und Höhe
        */
        double m_Proportion;
        double m_ProportionWidth;
        double m_ProportionHeight;
        /**
        Zeiger auf aktuelle Toll
        */
        BB_AbstractTool * m_Tool;
        /**
        Vector mit Objekten die gezechnet Werden
        */
        QVector<BB_DrawObject * > * m_DrawObjects;
        /**
        Vector mit Objekten die ausgewählt sind
        */
        QVector<BB_DrawObject * > * m_Selection;
        /**
        Zeiger auf Vector mit Tools
        */
        QVector<BB_DrawObject * > * m_ToolObjects;
        /**
        Transformer
        */
        BB_Transformer m_transformer;
        /**
        Texture für die Wand
        */
        QPixmap m_WallTexture;
    protected:
        /**
        Abgeleitete Funktion zum Zeichen
        @param QPaintEvent
        */
        virtual void paintEvent ( QPaintEvent * );
        /**
        Abgeleitete Funktion zum Anpassen von Breite und Höhe<br>
        Wird aufgerufen wenn die Größe von Fenster geändert wurde
        @param QResizeEvent
        */
        virtual void resizeEvent ( QResizeEvent * );
        /**
        Ein Erreigniss, das aufgerufen wird, wenn eine von  Maus-tasten gedrükt wird
        */
        virtual void mousePressEvent ( QMouseEvent * me );
        /**
        Ein Erreigniss, das aufgerufen wird, wenn eine von der Maus-Tasten losgelassen wird
        */
        virtual void mouseReleaseEvent ( QMouseEvent* me );
        /**
        Ein Erreigniss, das aufgerufen wird, wenn Maus bewegt wird
        */
        virtual void mouseMoveEvent ( QMouseEvent* me );
        /**
        Funktion zum Generieren einer großer Hitergrund-Image, das auf ganze Fenster passt
        */
        virtual void makeWallTexture( QPainter *p );
        /**
        Diese Funktion Generiert Positionen von Objekten von aktueller Wand
        */
        virtual void generatePositionOnWall();
};

#endif
