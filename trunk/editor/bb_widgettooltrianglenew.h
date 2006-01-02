//
// C++ Interface: bb_widgettooltrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLTRIANGLENEW_H
#define BB_WIDGETTOOLTRIANGLENEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetTriangleNew.h> 
/**
Eigenschaftsfenster für das Werkzeugt zur Flächenerstellung
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolTriangleNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        BB_WidgetToolTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolTriangleNew();

        virtual void clearToolWidget();
        virtual void setWidgetEnabled( bool value );
        virtual void updateWidget();

        Ui::WidgetToolTriangleNew m_Ui;

    private slots:
        void slotDelete();
        void slotNameFinished();
        void slotDescFinished();
};

#endif
