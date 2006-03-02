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
 * Werkzeugfenster für das Geländeflächen-Erstellungs-Werkzeug.
 * Im Fenster lassen sich der Name, die Beschreibung und die Textur für die ausgewählte fläche ändern.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_WidgetToolTerrainTriangleNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:

        /**
		 * Konstruktor. Erstellt ein neues Fenster für das Geländeflächen-Erstellungs-Werkzeug.
		 * @param parentTool Geländeflächen-Erstellungs-Werkzeug.
         * @param parent Parent-Fenster, in dem das neue Fenster positioniert wird.
         * @return 
         */
        BB_WidgetToolTerrainTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

		/**
		 * Destruktor
		 */
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

        /**
         * Aktualisiert das Eigenschaftsfenster
         * @author Alex Letkemann
         */
        virtual void updateWidget();
		
		
        /**
         * Gibt den Textur-Dateinamen zurück.
         * @return Textur-Dateiname
		 * @author Alex Letkemann
         */
        QString getTextureFileName();

        

    private slots:

        /**
         * Löscht die Selektion
         * @author Alex Letkemann
         */
        void slotDelete();

        /**
         * Wird aufgerufen, wenn die Beschreibung geändert wird.
		 * Ändert die Beschreibung.
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
		 * Wird aufgerufen, wenn die Bearbeitung des Textur-Dateinamen abgeschlossen ist.
		 * Ändert den Text-Dateinamen der Fläche.
		 * @author Alex Letkemann 
		 */
        void slotTextureFinished();
		
		
        /**
         * Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei als Textur auswählen kann.
		 * @author Alex Letkemann
         */
        void slotTextureSearch();
		
	protected:
		/* Form */
		Ui::WidgetToolTerrainTriangleNew m_Ui;
};

#endif
