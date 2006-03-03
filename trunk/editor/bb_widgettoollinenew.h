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
 * Werkzeugfenster für dasd Linienerstellungs-Werkzeug.
 * Im Fenster lassen sich der Name und die Beschreibung der Linie ändern.
 * Aßerdem lässt sich eine ausgewählte Linie löschen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolLineNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
		/**
		 * Konstruktor. Erstellt ein neues Werkzeugfenster für das Linienerstellungs-Werkzeug.
		 * @param parentTool Linienerstellungs-Werkzeug
		 * @param parent Parent-Fenster, in dem dieses Fenster Positioniert werden soll.
		 */
        BB_WidgetToolLineNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
        virtual ~BB_WidgetToolLineNew();

    public:
		
		/**
	     * Aktualisiert das Fenster
	     * @author Alex Letkemann
		 */
        virtual void updateWidget();
		
		/**
		 * Aktiviert oder Deaktiviert das Fenster.<br>
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
		
		/**
         * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
         * Speichert den neuen Namen im Objekt.
         * @author Alex Letkemann 
		 */
        void slotNameFinished();
		/**
		 * Wird aufgerufen, wenn die Beschreibung geändert wird.
		 * @author Alex Letkemann
		 */
        void slotDescFinished();
		
		/**
		 * Löscht die Selektion
		 * @author Alex Letkemann
		 */
        void slotDelete();

	private:
		Ui::WidgetToolLineNew m_Ui;
		
};

#endif
