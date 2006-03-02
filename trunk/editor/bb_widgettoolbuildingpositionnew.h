//
// C++ Interface: bb_widgettoolbuildingpositionnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
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
 * Werkzeugfenster für das Gebäudepositionierungs-Werkzeug.
 * Im Fenster lassen sich der Name des Gebäudes, die Beschreiung, die Position auf dem Gelände,
 * die Höhenposition sowie der Rotationswinkel des Gebäudes einstellen und verändern.
 * @author Alex Letkemann <alex@letkemann.de> 
 */
class BB_WidgetToolBuildingPositionNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:

        /**
		 * Konstruktor.<br />
		 * Erstellt ein neues Fenster für das Gebäudepositionierungs-Werkzeug.
		 * @param doc Dockument, welches das Gelände und die Gebäude enthält.
		 * @param parentTool Gebäudepositionierungs-Werkzeug.
		 * @param parent Parent-Fenster, in den das neue Fenster angelegt wird.
		 * @author Alex Letkemann
		 */
        BB_WidgetToolBuildingPositionNew( BB_Doc* doc, BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
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


    protected:
		/* Dialog-Form */
        Ui::WidgetToolBuildingPositionNew m_Ui;
		
		/* Gebäude, welches Position werden soll */
        BB_Building* m_Building;
		
		/* Gebäudeposition, der bearbeitet werden soll */
        BB_BuildingPosition *m_BPos;
		
		/* Dokument */
        BB_Doc* m_Doc;
    private slots:

        /**
         * Löscht die Selektion
         * @author Alex Letkemann
         */
        void slotDelete();

        /**
         * Wird aufgerufen, wenn die Beschreibung geändert wird.
         * @author Alex Letkemann
         */
        void slotDescFinished();

        /**
         * Wird aufgerufen, wenn die Höhenposition des Gebäudes geändert wurde.
         * Änder die Höhenposition des Gebäudes.
         * @author Alex Letkemann
         */
        void slotHeightFinished();

        /**
         * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
         * Speichert den neuen Namen im Objekt.
         * @author Alex Letkemann 
         */
        void slotNameFinished();

        /**
         * Wird aufgerufen, wenn die Position des Gebäudes im Fenster geändert wird.
         * Ändert die Position des Gebäudes.
         * @author Alex Letkemann
         */
        void slotPosFinished();

        /**
         * Wird aufgerufen, wenn die Rotationswinkel des Gebäudes im Fenster geändert wird.
         * Ändert den Rotationswinkel des Gebäudes.
         * @author Alex Letkemann
         */
        void slotRotationChanged( double value );
    private slots:
		
		/**
		 * Wird aufgerufen, wenn ein Gebäudes zur Plazierung ausgewählt wird.
		 * @author Alex Letkemann
		 */
        void slotBuildingChanged( int index );
};

#endif
