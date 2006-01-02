//
// C++ Interface: bb_widgettoolnavigationpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLNAVIGATIONPOINTNEW_H
#define BB_WIDGETTOOLNAVIGATIONPOINTNEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetNavigationPointNew.h>
#include <bb_point.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolNavigationPointNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        BB_WidgetToolNavigationPointNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolNavigationPointNew();

        virtual void clearToolWidget();
        virtual void setWidgetEnabled( bool value );
        virtual void updateWidget();

    private slots:
        void slotDescFinished();
        void slotNameFinished();
        void slotPosFinished();
        void slotIndexChanged( int index );
        void slotDelete();

    protected:
        Ui::WidgetToolNavigationPointNew m_Ui;
		BB_Point* m_Tmp_Point;
        C2dVector m_Tmp_Vector;

};

#endif
