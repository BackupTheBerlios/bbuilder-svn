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
 * Eigenschaftsfenster für das Werkzeug zur Flächenerstellung
 * Im Fenster lassen sich der Name und die Beschreibung ändern.
 * Eine ausgewählte Fläche lässt dich auch löschen.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolTriangleNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		
        /**
         * Konstruktor. Erzeugt ein neues Fenster für das Flächenerstellungs-Werkzeug.
		 * @param parentTool Flächenerstellungs-Werkzeug.
         * @param parent Parent-Fenster, in dem dieses Fenster plaziert wird.
         * @author Alex Letkemann
         */
        BB_WidgetToolTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		
        /**
         * Destruktor
         */
        ~BB_WidgetToolTriangleNew();

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
		 * Aktualisiert das Fenster.
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
		
	protected:
		
		/** Form */
		Ui::WidgetToolTriangleNew m_Ui;
};

#endif
