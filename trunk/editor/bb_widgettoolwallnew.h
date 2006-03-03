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
 * Werkzeugfenster für das Wand-Erstellungs-Werkzeug.
 * Im Fenster lassen sich der Name, die Beschreibung und die 'Richtung' der Wand ändern.
 * Für eine ausgewählte Wand lässt sich ein weiterer Dialog starten, 
 * in dem die sichtbare Seite der Wand bearbeitet werden kann.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolWallNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
        /**
		 * Konstruktor. Erstellt ein neues Wand-Erstellungs-Werkzeug.
		 * @param parentTool Wand-Erstellungs-Werkzeug
         * @param parent Parent-Fenster, in den dieses Fenster plaziert wird.
         * @author Alex Letkemann
         */
        BB_WidgetToolWallNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
        ~BB_WidgetToolWallNew();

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
		 * Aktualisiert das Fenster
		 * @author Alex Letkemann
		 */
        virtual void updateWidget();

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
		 * Wird aufgerufen, wenn die Bearbeitung des Namen abgeschlossen ist.
		 * Speichert den neuen Namen im Objekt.
		 * @author Alex Letkemann 
		 */
        void slotNameFinished();
        
		/**
		 * Änder die Richtung der Wand.
		 * Dadurch wird die sichtbare Seite der Wand ungedreht.
		 * @author Alex Letkemann
		 */
		void slotSwap();
		
		
        /**
         * Startet ein weiteres Dialog, in dem die sichtbare Seite der Wand bearbeitet werden kann.
		 * @author Alex Letkemann
         */
        void slotEdit();
	protected:
		
		/** Form */
        Ui::WidgetToolWallNew m_Ui;
};

#endif
