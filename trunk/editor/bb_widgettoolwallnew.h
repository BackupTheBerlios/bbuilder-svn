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
		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
        BB_WidgetToolWallNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolWallNew();

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
		
		/**
		 * Aktiviert oder Deaktiviert das Fenster.<br />
		 * @param value True: Aktiviert, False: Deaktiviert
		 * @author Alex Letkemann
		 */
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
