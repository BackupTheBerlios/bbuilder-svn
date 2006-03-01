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
		
		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
        BB_WidgetToolPointNew( BB_AbstractTool* parentTool, QWidget *parent = 0 );

        ~BB_WidgetToolPointNew();
        virtual void updateWidget();
		
		/**
		 * Lädt die Default-Werte in das Werkzeugfenster.
		 * @author Alex Letkemann
		 */
        virtual void clearToolWidget();
		
		
		
		/**
		 * Aktiviert oder Deaktiviert das Fenster.<br />
		 * @param value True: Aktiviert, False: Deaktiviert
		 * @author Alex Letkemann
		 */
        virtual void setWidgetEnabled( bool value );


    private slots:
        void slotPosFinished();
        void slotDelete();
        void slotDescFinished();
        void slotNameFinished();
		void slotToLine_H();
		void slotToLine_V();
    
	protected:
        BB_Point* m_Tmp_Point;
        C2dVector m_Tmp_Vector;    
	
	private:
        Ui::WidgetToolPointNew m_Ui;
};

#endif
