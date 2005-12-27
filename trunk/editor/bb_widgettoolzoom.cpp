//
// C++ Implementation: bb_widgettoolzoom
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolzoom.h"

BB_WidgetToolZoom::BB_WidgetToolZoom()
        : BB_AbstractToolWidget()
{
    m_Ui.setupUi( this );
}


BB_WidgetToolZoom::~BB_WidgetToolZoom()
{}




/**
 * Setzt den Zoomfaktor, der im Label im Fenster angezeigt wird
 */
void BB_WidgetToolZoom::setZoomFaktor( double value )
{
    m_Ui.label_Zoom->setText( QString::number( value * 100.0 ) + "%" );
}
