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
		
		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
        BB_WidgetToolLineNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        virtual ~BB_WidgetToolLineNew();

    public:
		
		/**
	     * Aktiviert oder Deaktiviert das Fenster.<br />
	     * @param value True: Aktiviert, False: Deaktiviert
	     * @author Alex Letkemann
		 */
        virtual void updateWidget();
		
		/**
		 * Aktiviert oder Deaktiviert das Fenster.<br />
		 * @param value True: Aktiviert, False: Deaktiviert
		 * @author Alex Letkemann
		 */
        virtual void setWidgetEnabled( bool value );
		
		/**
		 * Lädt die Default-Werte in das Werkzeugfenster.
		 * @author Alex Letkemann
		 */
        virtual void clearToolWidget();

    private slots:
        void slotNameFinished();
        void slotDescFinished();
        void slotDelete();

	private:
		Ui::WidgetToolLineNew m_Ui;
		
};

#endif
