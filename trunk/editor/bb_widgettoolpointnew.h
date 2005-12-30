//
// C++ Interface: bb_widgettoolpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLPOINTNEW_H
#define BB_WIDGETTOOLPOINTNEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetPointNew.h>
#include <bb_point.h>

/**
Fenster für das Punkt-Erstellungs-Werkzeug
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolPointNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        BB_WidgetToolPointNew( BB_AbstractTool* parentTool, QWidget *parent = 0 );

        ~BB_WidgetToolPointNew();
        virtual void updateWidget();
        virtual void clearWidget();
        virtual void setWidgetEnabled( bool value );


    private slots:
        void slotPosFinished();
        void slotDelete();
        void slotDescFinished();
        void slotNameFinished();
    
	protected:
        BB_Point* m_Tmp_Point;
        C2dVector m_Tmp_Vector;    
	
	private:
        Ui::WidgetToolPointNew m_Ui;
};

#endif
