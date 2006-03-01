//
// C++ Interface: bb_widgettoolbuildingpositionnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLBUILDINGPOSITIONNEW_H
#define BB_WIDGETTOOLBUILDINGPOSITIONNEW_H

#include <bb_widgettoolterrainpointnew.h>
#include <ui_toolWidgetBuildingPositionNew.h>
#include <bb_buildingposition.h>
#include <bb_doc.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolBuildingPositionNew : public BB_AbstractToolWidget
{
	Q_OBJECT
    public:
		
		/**
	     * Konstruktor
		 */
        BB_WidgetToolBuildingPositionNew( BB_Doc* doc, BB_AbstractTool* parentTool, QWidget* parent = 0);

        ~BB_WidgetToolBuildingPositionNew();
		
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
         * Aktualisiert das Eigenschaftsfenster
		 * @author Alex Letkemann
         */
        virtual void updateWidget();


        Ui::WidgetToolBuildingPositionNew m_Ui;
        BB_Building* m_Building;
        BB_BuildingPosition *m_BPos;
        BB_Doc* m_Doc;
    private slots:
        void slotDelete();
        void slotDescFinished();
        void slotHeightFinished();
        void slotNameFinished();
        void slotPosFinished();
		void slotRotationChanged( double value );
private slots:
    void slotBuildingChanged( int index );
};

#endif
