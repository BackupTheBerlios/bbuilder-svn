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
#include "bb_constructionelement.h"
#include "bb_dlgopentexture.h"
#include "bb_point.h"
#include "bb_globals.h"


/**
Standart Konstruktor
@param C2dVector v1 Position von obere-linke Ecke
@param C2dVector v2 Position von untere-rechte Ecke
*/
BB_ConstructionElement::BB_ConstructionElement( C2dVector v1, C2dVector v2 )
        : BB_Rect()
{
    setPos1( new BB_Point( v1 ) );
    setPos2( new BB_Point( v2 ) );
    m_Pos1->setRadius( 0.07 );
    m_Pos2->setRadius( 0.07 );
}

/**
Dekonstruktor
*/
BB_ConstructionElement::~BB_ConstructionElement()
{}

/**
Gibt relative Pfad zum Texture-File-Name zurück<br>
Das Bild selbst liegt in Verzeichniss "textures" von Projekt-Ordner
*/
QString BB_ConstructionElement::getTextureFileName() const
{
    return m_TextureFileName;
}

/**
Setzt das TextureFileName fest.<br>
Das Pfad soll relativ zum Verzeichniss "textures" in Projekt-Ordner sein
@param QString relative Pfad Angabe
*/
void BB_ConstructionElement::setTextureFileName( const QString& Value )
{
    if ( !Value.isNull() )
    {
        m_TextureFileName = Value;
        qDebug() << PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName;
        if ( !m_Image.load( PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName ) )
        {
            qDebug() << "image " << Value << " wurde nicht geladen";
        }
        else
        {
            qDebug() << "image " << Value << " wurde erfolgreich geladen";
        }
    }
}


/**
Diese funktion öffnet ein kleines Dialog.<br>
In diesem Dialog kann man dann die Textur (Image-File) auswählen.
*/
void BB_ConstructionElement::openTextureDlg()
{
    BB_DlgOpenTexture dlg;
    dlg.setTextureFile( PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName );
    dlg.exec();
    setTextureAbsoluteFileName( dlg.getTextureFile() );
}

/**
Setzt das TextureFileName fest.<br>
Das Pfad soll Absolut sein
@param QString absolute Pfad Angabe
*/
void BB_ConstructionElement::setTextureAbsoluteFileName( const QString& Value )
{
    QImage image( Value );
    if ( !image.isNull() )
    {
        image.save( PRO_TEXTURES_DIR() + SEPARATOR() + getName() + ".png", "PNG" );
        setTextureFileName( getName() + ".png" );
        return ;
    }
    qDebug( "image ist nicht geladen" );
}

/**
Funktion zum Zeichnen.
@param BB_Transformer Transformation-Tool, damit es korrekt gezeichnet wird
@param QPainter Werkzeug zum Zeichnen @see QT::QPainter
*/
void BB_ConstructionElement::show( BB_Transformer& transformer, QPainter& painter ) const
{
    if ( &transformer != NULL && &painter != NULL && m_Pos1 != NULL && m_Pos2 != NULL )
    {
        painter.setPen( m_Pen );
        painter.setBrush( m_Brush );

        QPoint dest1;
        QPoint dest2;

        transformer.logicalToScreen( dest1, m_Pos1->getPos() );
        transformer.logicalToScreen( dest2, m_Pos2->getPos() );

        QRect rect( dest1.x(),
                    dest1.y(),
                    ( dest2.x() - dest1.x() ),
                    ( dest2.y() - dest1.y() ) );
        rect = rect.normalized();
        painter.drawRect( rect );

        painter.drawImage( rect, m_Image );

        if ( m_Selected )
        {
            double r1 = m_Pos1->getRadius();
            double r2 = m_Pos2->getRadius();
            m_Pos1->setRadius( 7.0 );
            m_Pos2->setRadius( 7.0 );
            m_Pos1->show( transformer, painter );
            m_Pos2->show( transformer, painter );
            m_Pos1->setRadius( r1 );
            m_Pos2->setRadius( r2 );
        }
    }
}

/**
Gibt die ertse Position von der Wand zurück
*/
C2dVector BB_ConstructionElement::getWallPosition1() const
{
    return m_WallPosition1;
}


/**
Legt die erste Position an der Wand fest
*/
void BB_ConstructionElement::setWallPosition1( const C2dVector& Value )
{
    m_WallPosition1 = Value;
}

/**
Gibt die zweite Position von der Wand zurück
*/
C2dVector BB_ConstructionElement::getWallPosition2() const
{
    return m_WallPosition2;
}

/**
Legt die zweite Position an der Wand fest
*/
void BB_ConstructionElement::setWallPosition2( const C2dVector& Value )
{
    m_WallPosition2 = Value;
}

/**
Gibt Proportion von der erste Position zurück
@see setCoefficientPos1()
*/
C2dVector BB_ConstructionElement::getCoefficientPos1() const
{
    return m_CoefficientPos1;
}


/**
Legt die erste Position in Proportion an der Wand fest<br>
z.B. Die Wand hat Länge 100. Die Positionen von Unserem Element sind 10 und 50.
Dann ergeben sich folgende Proportionen: P1 10 /100 = 0.1 und P2 50 / 100 = 0,5<br>
Hier werden Positionen auf X und Y - Achse gespeichert
@param C2dVector Proportionen von X und Y
*/
void BB_ConstructionElement::setCoefficientPos1( const C2dVector& Value )
{
    m_CoefficientPos1 = Value;
}

/**
Gibt Proportion von der zweite Position zurück
@see setCoefficientPos1()
*/
C2dVector BB_ConstructionElement::getCoefficientPos2() const
{
    return m_CoefficientPos2;
}

/**
Legt die erste Position in Proportion an der Wand fest
@param C2dVector Proportionen von X und Y
@see setCoefficientPos1()
*/
void BB_ConstructionElement::setCoefficientPos2( const C2dVector& Value )
{
    m_CoefficientPos2 = Value;
}
