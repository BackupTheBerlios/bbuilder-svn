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
#include "bb_dlgwalleditarea.h"
#include "bb_dlgwalledit.h"
#include "bb_level.h"
#include "bb_window.h"

#include <iostream>
#include <QPainter>

using namespace std;


/**
Standart Konstruktor: <br>
Es wird ein Dialog erzeugt, das die Objekte von BB_Wall verwalten kann<br>
Deafult Wert für Höhe einer Wand ist 3.2 Meter
@param BB_Wall Obejekt von einer Wand. Für diese Wand wird dann ein Dialog erzeugt
@Param BB_DocComponent Etage mit der gearbeitet werden soll
@param QWidget Benötigt von QT
@param Qt::WFlags als Eigenschaft von Qt
*/
BB_DlgWallEditArea::BB_DlgWallEditArea( BB_Wall * wall, BB_DocComponent * docComponent, double hohe, QWidget * parent, Qt::WFlags f )
        : QLabel( parent, f )
{
    //zum testen, feste hoehe von 3,2 meter
    double hohe_meter = docComponent->getHeight();
    double laenge_pixel = wall->getLength();
    double laenge_meter = docComponent->getMeterPerPixel( laenge_pixel );
    m_Height = hohe_meter;
    m_Width = laenge_meter;
    m_Proportion = m_Width / m_Height;
    m_Wall = wall;
    //immer Statisch
    m_PixelHeight = 400.0;
    m_PixelWidth = m_PixelHeight * m_Proportion;
    m_ProportionHeight = m_PixelHeight / m_Height;
    m_ProportionWidth = m_PixelWidth / m_Width;
    setFixedSize ( m_PixelWidth, m_PixelHeight );
    m_Tool = NULL;
    m_DrawObjects = NULL;
    m_DrawObjects = wall->getObjects();

    m_Selection = new QVector<BB_DrawObject *>;
    m_ToolObjects = new QVector<BB_DrawObject *>;
    m_transformer.setScale( m_ProportionWidth );
    m_transformer.setOffset( C2dVector( 0.0, m_Height ) );
    // 	setMinimumSize ( 400 * m_verhaeltniss, 400);
    // cout << "height: "<<m_ProportionHeight << "width: "<<m_ProportionWidth<<endl;

    loadTexture();
}

/**
Standart Dekonstruktor. Hier werden alle Objekte, 
die in deisem Class erzeugt wurden, gelöscht
*/
BB_DlgWallEditArea::~BB_DlgWallEditArea()
{
    delete m_Selection;
    delete m_ToolObjects;
    generatePositionOnWall();
    // 	delete m_WallTexture;
}

/**
Abgeleitete Funktion zum Zeichen
@param QPaintEvent
*/
void BB_DlgWallEditArea::paintEvent ( QPaintEvent * pe )
{
    QLabel::paintEvent( pe );
    QPainter painter( this );
    painter.drawRect( 0, 0, width() - 1, height() - 1 );
    makeWallTexture( &painter );
    if ( m_DrawObjects != NULL )
    {
        BB_DrawObject * tmpElement;
        for ( int i = 0; i < m_DrawObjects->count(); i++ )
        {
            tmpElement = m_DrawObjects->at( i );
            tmpElement->show( m_transformer, painter );
        }
    }
    else
    {
        qDebug( "m_DrawObjects ist nicht initialisiert: in BB_DlgWallEditArea" );
    }

    for ( int i = 0;i < m_ToolObjects->count() ;i++ )
    {
        m_ToolObjects->at( i ) ->show( m_transformer, painter );
    }
}

/**
Abgeleitete Funktion zum Anpassen von Breite und Höhe<br>
Wird aufgerufen wenn die Größe von Fenster geändert wurde
@param QResizeEvent
*/
void BB_DlgWallEditArea::resizeEvent ( QResizeEvent * re )
{}


/**
 * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
 */
void BB_DlgWallEditArea::mousePressEvent ( QMouseEvent * me )
{
    if ( m_Tool != NULL )
    {
        m_Tool->click( me );
    }
    else
    {
        cout << "Kein Tool ausgewählt" << endl;
    }
}

/**
 * Wird aufgerufen, wenn eine Maustaste losgelassen wird.
 */
void BB_DlgWallEditArea::mouseReleaseEvent( QMouseEvent* me )
{
    if ( m_Tool != NULL )
    {
        m_Tool->release( me );
        update();
    }
    else
    {
        cout << "Kein Tool ausgewählt" << endl;
    }

    /* Mouseevent weiterleiten, damit das BB_TabXXXXX es mitkriegt */
    QLabel::mouseReleaseEvent( me );
}


/**
 * Wird aufgerufen, wenn die Maus mit einer gedrückten Maustaste bewegt wird.
 */
void BB_DlgWallEditArea::mouseMoveEvent( QMouseEvent* me )
{

    if ( m_Tool != NULL )
    {
        bool overX, overY;
        overX = ( me->pos().x() < 0 || me->pos().x() > width() );
        overY = ( me->pos().y() < 0 || me->pos().y() > height() );

        m_Tool->move( me, overX, overY );
        update();
    }
    else
    {
        qDebug() << "Kein Tool ausgewählt" << endl;
    }
}


/**
Setzt das Tool <b>tool</b> als aktiv (ausgewählt) ein
@param BB_AbstractTool
*/
void BB_DlgWallEditArea::setTool( BB_AbstractTool * tool )
{
    if ( tool != NULL )
    {
        if ( m_Tool != NULL )
        {
            m_Tool->reset();
        }

        m_Tool = tool;
        if ( typeid( * tool ) == typeid( BB_ToolMove ) )
        {
            m_Tool->setObjects( m_Wall->getPoints() );
            //m_Tool->setObjects( m_Wall->getObjectsWithPoints() );
            for ( int i = 0; i < m_DrawObjects->count(); i++ )
            {
                m_DrawObjects->at( i ) ->setSelected( true );
            }
        }
        else
        {
            for ( int i = 0; i < m_DrawObjects->count(); i++ )
            {
                m_DrawObjects->at( i ) ->setSelected( false );
            }
        }
        m_Tool->setSelectionVector( m_Selection );
        m_Tool->setToolObjects( m_ToolObjects );
        m_Tool->setTransformer( &m_transformer );
        m_Tool->setScaleHeight( m_ProportionHeight );
        m_Tool->setScaleWidth( m_ProportionWidth );
        //         m_Tool->setTransformer( &m_Transformer );
        // 		m_Tool->setObjects(m_DrawObjects);
        //         m_Tool->setToolObjects( &m_ToolObjects );
        //         m_Tool->setSelectionVector( m_Selection );
        //         m_Tool->setDocComponent( m_Component );
    }
    else
    {
        QMessageBox::critical ( this, "Fehler (BB_DlgWallEditArea)", "Fehler beim setzten des Tools.\nNULL-Pointer erhalten", QMessageBox::Ok, QMessageBox::NoButton );
    }
    update();
}

/**
Funktion zum Generieren einer großer Hitergrund-Image, das auf ganze Fenster passt
*/
void BB_DlgWallEditArea::makeWallTexture( QPainter * p )
{
    //     p->drawPixmap( 0, 0, m_WallTexture );
    int k = m_PixelHeight / m_WallTexture.height() ;
    int n = m_PixelWidth / m_WallTexture.width() ;
    for ( int i = 0;i <= k ;i++ )
    {
        p->drawPixmap( 0, m_WallTexture.height() * i , m_WallTexture );
        for ( int j = 1;j <= n ;j++ )
        {
            p->drawPixmap( m_WallTexture.width() * j , m_WallTexture.height() * i , m_WallTexture );
        }
    }
}

/**
Lädt die Textur für die Wand herunter
*/
void BB_DlgWallEditArea::loadTexture()
{
    m_WallTexture.load( PRO_TEXTURES_DIR() + SEPARATOR() + m_Wall->getTextureFileName() );
}

/**
Diese Funktion Generiert Positionen von Objekten von aktueller Wand
*/
void BB_DlgWallEditArea::generatePositionOnWall()
{
    BB_ConstructionElement * myElement;
    C2dVector ortVector;
    C2dVector richtungsVector;
    C2dVector elementPosition;
    double factor;
    C2dVector coefficient;
    for ( int i = 0;i < m_DrawObjects->count() ;i++ )
    {
        myElement = ( BB_ConstructionElement * ) m_DrawObjects->at( i );
        ortVector = m_Wall->getPos1() ->getPos();
        richtungsVector = m_Wall->getPos2() ->getPos() - ortVector;

        factor = myElement->getPos1() ->getPos().x() / m_Width;
        elementPosition = ortVector + ( richtungsVector * factor );
        coefficient.setX( myElement->getPos1() ->getPos().x() / m_Width );
        coefficient.setY( myElement->getPos1() ->getPos().y() / m_Height );
        myElement->setWallPosition1( elementPosition );
        myElement->setCoefficientPos1( coefficient );

        factor = myElement->getPos2() ->getPos().x() / m_Width;
        elementPosition = ortVector + ( richtungsVector * factor );
        coefficient.setX( myElement->getPos2() ->getPos().x() / m_Width );
        coefficient.setY( myElement->getPos2() ->getPos().y() / m_Height );
        myElement->setWallPosition2( elementPosition );
        myElement->setCoefficientPos2( coefficient );
        //coefficient

    }
}
