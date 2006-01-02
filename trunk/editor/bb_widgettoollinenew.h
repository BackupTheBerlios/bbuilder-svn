//
// C++ Interface: bb_widgettoollinenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLLINENEW_H
#define BB_WIDGETTOOLLINENEW_H

#include <bb_widgettoolpointnew.h>
#include <ui_toolWidgetLineNew.h>
#include <bb_abstracttool.h>


/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolLineNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        BB_WidgetToolLineNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        virtual ~BB_WidgetToolLineNew();

    public:
        virtual void updateWidget();
        virtual void setWidgetEnabled( bool value );
        virtual void clearToolWidget();

    private slots:
        void slotNameFinished();
        void slotDescFinished();
        void slotDelete();

	private:
		Ui::WidgetToolLineNew m_Ui;
		
};

#endif
