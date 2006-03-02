//
// C++ Interface: bb_widgettoolzoom
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLZOOM_H
#define BB_WIDGETTOOLZOOM_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetZoom.h>

/**
 * Fenster des Zoom-Werkzeuges.
 * Im Fenter wird der aktuelle Zoomfaktor angezeigt.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolZoom : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
		/**
		 * Konstruktor. Erzeugt das Fenster für das Zoom-Werkzeug.
		 * @param parentTool Zoom-Werkzeug
		 * @param parent Parent-Fenster, wo dieses Fenster plaziert wird.
		 * @author Alex Letkemann
		 */
		BB_WidgetToolZoom( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
        ~BB_WidgetToolZoom();
		
        /**
         * Setzt den Zoomfaktor im Fenster
         * @param value Zoomfaktor der Arbeistfläche.
		 * @author Alex Letkemann
         */
        virtual void setZoomFaktor( double value );

    protected:
		/* Form */
        Ui::WidgetToolZoom m_Ui;
};

#endif
