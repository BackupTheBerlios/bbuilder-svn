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
#ifndef BB_CONSTRUCTIONELEMENT_H
#define BB_CONSTRUCTIONELEMENT_H

#include <bb_rect.h>
#include "QFileInfo"

/**
Eine Basis-Klasse fuer allle Konstruktion-Elemente z.B: Fenster oder T&uuml;re
In Zukunft auch m&ouml;glicherweise Bilder und Poster, etc
@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ConstructionElement : public BB_Rect
{
    public:
        /**
        Standart Konstruktor
        @param v1 Position von obere-linke Ecke
        @param v2 Position von untere-rechte Ecke
        */
        BB_ConstructionElement( C2dVector v1, C2dVector v2 );
        /**
        Dekonstruktor.
        */
        ~BB_ConstructionElement();
        /**
        Setzt das TextureFileName fest.<br>
        Das Pfad soll relativ zum Verzeichniss "textures" in Projekt-Ordner sein
		@param Value relative Pfad Angabe
        */
        void setTextureFileName( const QString& Value );
        /**
        Setzt das TextureFileName fest.<br>
        Das Pfad soll Absolut sein
		@param Value absolute Pfad Angabe
        */
        void setTextureAbsoluteFileName( const QString& Value );
        /**
        Gibt relative Pfad zum Texture-File-Name zurück<br>
        Das Bild selbst liegt in Verzeichniss "textures" von Projekt-Ordner
        */
        QString getTextureFileName() const;
        /**
        Diese funktion öffnet ein kleines Dialog.<br>
        In diesem Dialog kann man dann die Textur (Image-File) auswählen.
        */
        void openTextureDlg();
        /**
        Funktion zum Zeichnen.
		@param transformer Transformation-Tool, damit es korrekt gezeichnet wird
		@param painter Werkzeug zum Zeichnen @see QT::QPainter
        */
        void show( BB_Transformer& transformer, QPainter& painter ) const;
        /**
        Legt die erste Position an der Wand fest
        */
        void setWallPosition1( const C2dVector& Value );
        /**
        Gibt die ertse Position an der Wand zurück
        */
        C2dVector getWallPosition1() const;
        /**
        Legt die zweite Position an der Wand fest
        */
        void setWallPosition2( const C2dVector& Value );
        /**
        Gibt die zweite Position an der Wand zurück
        */
        C2dVector getWallPosition2() const;
        /**
        Legt die erste Position in Proportion an der Wand fest<br>
        z.B. Die Wand hat Länge 100. Die Positionen von Unserem Element sind 10 und 50.
        Dann ergeben sich folgende Proportionen: P1 10 /100 = 0.1 und P2 50 / 100 = 0,5<br>
        Hier werden Positionen auf X und Y - Achse gespeichert
		@param Value Proportionen von X und Y
        */
        void setCoefficientPos1( const C2dVector& Value );
        /**
        Gibt Proportion von der erste Position zurück
        @see setCoefficientPos1()
        */
        C2dVector getCoefficientPos1() const;
        /**
        Legt die erste Position in Proportion an der Wand fest
		@param Value von X und Y
        @see setCoefficientPos1()
        */
        void setCoefficientPos2( const C2dVector& Value );
        /**
        Gibt Proportion von der zweite Position zurück
        @see setCoefficientPos1()
        */
        C2dVector getCoefficientPos2() const;
    protected:
        /**
        Relative Pfad zur Bild-Datei in Verzeichnis "textures"
        */
        QString m_TextureFileName;
        /**
        Die Textur selbt in Speicher
        */
        QImage m_Image;
        /**
        Erste Position an der Wand in Pixel
        */
        C2dVector m_WallPosition1;
        /**
        Zweite Position an der Wand in Pixel
        */
        C2dVector m_WallPosition2;
        /**
        Erste Position in Proportion
        @see setCoefficientPos1()
        */
        C2dVector m_CoefficientPos1;
        /**
        Erste Position in Proportion
        @see setCoefficientPos1()
        */
        C2dVector m_CoefficientPos2;
};

#endif
