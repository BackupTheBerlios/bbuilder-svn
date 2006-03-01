//
// C++ Interface: bb_widgettoolterraintrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLTERRAINTRIANGLENEW_H
#define BB_WIDGETTOOLTERRAINTRIANGLENEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetTerrainTriangleNew.h>
#include <bb_triangle.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolTerrainTriangleNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:

		/**
		 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
		 */
        BB_WidgetToolTerrainTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolTerrainTriangleNew();

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
        virtual void updateWidget();
    QString getTextureFileName();

        Ui::WidgetToolTerrainTriangleNew m_Ui;

    private slots:
        void slotDelete();
        void slotDescFinished();
        void slotNameFinished();
        void slotTextureFinished();
        void slotTextureSearch();
};

#endif
