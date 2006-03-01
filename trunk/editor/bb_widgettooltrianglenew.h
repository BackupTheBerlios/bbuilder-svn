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
		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
        BB_WidgetToolTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolTriangleNew();

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

        Ui::WidgetToolTriangleNew m_Ui;

    private slots:
        void slotDelete();
        void slotNameFinished();
        void slotDescFinished();
};

#endif
