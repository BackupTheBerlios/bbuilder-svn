//
// C++ Interface: bb_widgettoolterrainpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLTERRAINPOINTNEW_H
#define BB_WIDGETTOOLTERRAINPOINTNEW_H

#include <bb_abstracttoolwidget.h>
#include <bb_point.h>
#include <ui_toolWidgetTerrainPointNew.h> 
/**
 * Fenster für das Geländepunkt-Erstellungs-Werkzeug.
 * Im Fenster lassen sich der Name, die Beschreibung, die Position und die Höhenposition ändern.
 * Ein ausgewählter Punkt lässt sich auch löschen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolTerrainPointNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
        
		
        /**
		 * Konstruktor. Erstellt ein neues Fenster für das Geländepunkt-Erstellungs-Werkzeug.
		 * @param parentTool Geländepunkt-Erstellungs-Werkzeug.
         * @param parent Parent-Fenster, in dem dieses Fenster plaziert wird.
         * @author Alex Letkemann
         */
        BB_WidgetToolTerrainPointNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
        ~BB_WidgetToolTerrainPointNew();

        /**
         * Lädt die Default-Werte in das Werkzeugfenster.
         * @author Alex Letkemann
         */
        virtual void clearToolWidget();

        /**
         * Aktiviert oder Deaktiviert das Fenster.<br>
         * @param value True: Aktiviert, False: Deaktiviert
         * @author Alex Letkemann
         */
        virtual void setWidgetEnabled( bool value );

        /**
         * Aktualisiert das Eigenschaftsfenster
         * @author Alex Letkemann
         */
        virtual void updateWidget();

    private slots:
        
		/**
         * Wird aufgerufen, wenn die Position des Punktes im Fenster geändert wurde.
		 * Ändert die Position des Punktes.
		 * @author Alex Letkemann
         */
        void slotPosFinished();

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
         * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
         * Speichert den neuen Namen im Objekt.
         * @author Alex Letkemann 
         */
        void slotNameFinished();

        /**
         * Wird aufgerufen, wenn die Bearbeitung der Höhenposition des Punktes abgeschlossen wurde.
		 * Ändert die Höhenposition des Punktes.
		 * @author Alex Letkemann
         */
        void slotHeightFinished();
		
    protected:
		/** Hilfsvariable */
        BB_Point* m_Tmp_Point;
		
		/** Form */
        Ui::WidgetToolTerrainPointNew m_Ui;
};

#endif
