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
 * Werkzeugfenster für das Navigations-Knoten Werkzeug.
 * Im Fenster lassen sich der Name, die Beschreibung und die Position des Navigationsknotens ändern.
 * Ein ausgewählter Navigationsknoten lässt sich als Indiziert oder als nicht Indiziert markieren oder auch löschen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolNavigationPointNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
		
        /**
         * Konstruktor. Erstellt ein neues Werkzeugfenster für das Navigations-Knoten Werkzeug.
		 * @param parentTool Navigations-Knoten Werkzeug
         * @param parent Parent-Fenster, in dem diese Fenster positionier wird.
         */
        BB_WidgetToolNavigationPointNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        /**
         * Destruktor
         */
        ~BB_WidgetToolNavigationPointNew();
		
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
		 * Aktualisiert das Fenster
		 * @author Alex Letkemann
		 */
        virtual void updateWidget();

    private slots:
		
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
         * Wird aufgerufen, wenn die Position des Knotens im Fenster geändert wird.
		 * Ändert die Position des Knotens.
		 * @author Alex Letkemann
         */
        void slotPosFinished();
		
		
        /**
         * Markiert den asugewählten Knoten als Indiziert oder als nicht Indiziert.
         * @param index True: Indiziert, False: nicht Indiziert.
		 * @author Alex Letkemann
         */
        void slotIndexChanged( int index );
		
		/**
		 * Löscht die Selektion
		 * @author Alex Letkemann
		 */
        void slotDelete();

    protected:
        Ui::WidgetToolNavigationPointNew m_Ui;
		BB_Point* m_Tmp_Point;
        C2dVector m_Tmp_Vector;

};

#endif
