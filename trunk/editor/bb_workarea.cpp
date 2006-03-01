/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
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
***************************************************************************/
#include "bb_workarea.h"
#include "bb_globals.h"

#include <iostream>

using namespace std;

/**
 * Konstruktor
 * Erzeugt einen scrollbaren Arbeitbereich.
 * @param selectVector Selektions-Vektor
 * @param parent Eltern-Fenster
 */
BB_WorkArea::BB_WorkArea( QVector<BB_DrawObject*>* selectVector, QWidget *parent )
        : QScrollArea( parent )
{

    m_WorkFrame = new BB_WorkFrame( selectVector );
    m_WorkFrame->setFrameShape( QFrame::NoFrame );
    m_WorkFrame->setFrameShadow( QFrame::Plain );
    m_WorkFrame->setBackgroundRole( QPalette::Background );
    m_WorkFrame->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    m_WorkFrame->setScaledContents( true );

    setWidget( m_WorkFrame );
}


/**
 * Destruktor
 */
BB_WorkArea::~BB_WorkArea()
{}


/**
 * Zoom um den übergeben Faktor.
 * @param factor Zoomfaktor, um den gezoomt werden soll.
 * @author Alex Letkemann
 */
void BB_WorkArea::zoom( double faktor )
{

    if ( m_Map != NULL )
    {
        double zoom = m_Map->getZoom();

        Q_ASSERT( m_WorkFrame->pixmap() );

        zoom *= faktor;

        if ( zoom > 5.0 )
        {
            zoom = 5.0;
        }
        else if ( zoom < 0.5 )
        {
            zoom = 0.5;
        }


        m_WorkFrame->resize( zoom * m_WorkFrame->pixmap() ->size() );
        m_WorkFrame->setZoomFaktor( zoom );

        horizontalScrollBar() ->setValue( int( faktor * horizontalScrollBar() ->value() + ( ( faktor - 1 ) * horizontalScrollBar() ->pageStep() / 2 ) ) );

        verticalScrollBar() ->setValue( int( faktor * verticalScrollBar() ->value() + ( ( faktor - 1 ) * verticalScrollBar() ->pageStep() / 2 ) ) );

        m_Map->setZoom( zoom );
    }

}


/**
 * Gibt das Tool zurück, welches im Workframe verwendet wird.
 * @return Das Tool, welches im Workframe benutzt wird.
 * @author Alex Letkemann
 */
BB_AbstractTool* BB_WorkArea::getTool()
{
    return m_WorkFrame->getTool();
}


/**
 * Setzt das Tool des Workframes auf <i>tool</i>.
 * @param tool Tool, welches im Workframe benutzt werden soll.
 * @author Alex Letkemann
 */
void BB_WorkArea::setTool( BB_AbstractTool* tool )
{
    if ( tool != NULL )
        m_WorkFrame->setTool( tool );
    else
        cout << "BB_WorkArea::setTool(): NULL-Pointer erhalten" << endl;
}


/**
 * Setzt den Zoom auf den übergebenen Zoomfaktor
 * @param zoom Zoomfaktor
 * @author Alex Letkemann
 */
void BB_WorkArea::setZoomFaktor( double z )
{
    if ( m_Map != NULL )
    {
        m_Map->setZoom( 1.0 );
        zoom( z );
    }
}



/**
 * Gibt das Komponent zurück, welches gerade bearbeitet wird.
 * Falls kein Komponent eingestellt ist wird NULL zurückgegeben
 * @return Das aktuelle DocComponent
 * @author Alex Letkemann
 */
BB_DocComponent* BB_WorkArea::getDocComponent()
{
    return m_WorkFrame->getDocComponent();
}



/**
 * Setzt das DocComponent, welches bearbeitet werden soll.
 * Falls NULL übergeben wird, wird der Arbeitbereich deaktiviert.
 * @param component DocComponent, welches bearbeitet werden soll.
 * @author Alex Letkemann
 */
void BB_WorkArea::setDocComponent( BB_DocComponent* component )
{
    if ( component == NULL )
    {
        m_Map = NULL;
        m_WorkFrame->setDocComponent( NULL );
        m_WorkFrame->setScaledContents( false );
        setEnabled( false );
    }
    else
    {
        m_Map = component;

        m_WorkFrame->setPixmap( m_Map->getMap() );

        m_WorkFrame->setFrameShape( QFrame::Box );
        m_WorkFrame->setBackgroundRole( QPalette::Background );
        m_WorkFrame->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        m_WorkFrame->setScaledContents( true );
        m_WorkFrame->setEnabled( true );

        setZoomFaktor( m_Map->getZoom() );
        m_WorkFrame->setDocComponent( component );
        setEnabled( true );
    }
}


/**
 * Gibt den Zoomfaktor zurück
 * @return Zoomfaktor
 * @author Alex Letkemann
 */
double BB_WorkArea::getZoom()
{
    if ( m_Map != NULL )
    {
        return m_Map->getZoom();
    }
    return 0.0;
}
