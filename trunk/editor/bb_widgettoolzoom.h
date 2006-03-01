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
Fenster des Zoom-Werkzeuges
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolZoom : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
		BB_WidgetToolZoom( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolZoom();
        virtual void setZoomFaktor( double value );

    protected:
        Ui::WidgetToolZoom m_Ui;
};

#endif
