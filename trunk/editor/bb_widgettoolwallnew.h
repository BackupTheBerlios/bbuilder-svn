//
// C++ Interface: bb_widgettoolwallnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLWALLNEW_H
#define BB_WIDGETTOOLWALLNEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetWallNew.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolWallNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        BB_WidgetToolWallNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolWallNew();

        virtual void clearWidget();
        virtual void setWidgetEnabled( bool value );
        virtual void updateWidget();

    private slots:
        void slotDelete();
        void slotDescFinished();
        void slotNameFinished();
        void slotSwap();
        void slotEdit();
	protected:
        Ui::WidgetToolWallNew m_Ui;
};

#endif
