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

/**
 * Konstruktor. Erzeugt das Fenster für das Zoom-Werkzeug.
 * @param parentTool Zoom-Werkzeug
 * @param parent Parent-Fenster, wo dieses Fenster plaziert wird.
 * @author Alex Letkemann
 */
BB_WidgetToolZoom::BB_WidgetToolZoom( BB_AbstractTool* parentTool, QWidget* parent )
        : BB_AbstractToolWidget(parentTool, parent)
{
    m_Ui.setupUi( this );
}

/**
 * Destruktor
 */
BB_WidgetToolZoom::~BB_WidgetToolZoom()
{}




/**
 * Setzt den Zoomfaktor im Fenster
 * @param value Zoomfaktor der Arbeistfläche.
 * @author Alex Letkemann
 */
void BB_WidgetToolZoom::setZoomFaktor( double value )
{
    m_Ui.label_Zoom->setText( QString::number( value * 100.0 ) + "%" );
}

