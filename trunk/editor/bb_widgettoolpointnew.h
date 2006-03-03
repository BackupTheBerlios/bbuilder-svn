//
// C++ Interface: bb_widgettoolpointnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLPOINTNEW_H
#define BB_WIDGETTOOLPOINTNEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetPointNew.h>
#include <bb_point.h>

/**
 * Fenster für das Punkt-Erstellungs-Werkzeug.
 * Im Genster lassen sich der Name, die Beschreibung und die Position des Punktes ändern.
 * Ein ausgewählter Punkt lässt sich auch löschen.
 * @author Alex Letkemann <alex@letkemann.de>, Vaceslav Ustinov
 */
class BB_WidgetToolPointNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		

        /**
         * Konstruktor. Erzeugt ein neues Werkzeugfenster für das Punkt-Erstellungs-Werkzeug.
		 * @param parentTool Punkt-Erstellungs-Werkzeug.
         * @param parent Parent-Fenster in dem dieses Fenster plaziert wird.
		 * @author Alex Letkemann
         */
        BB_WidgetToolPointNew( BB_AbstractTool* parentTool, QWidget *parent = 0 );

		/**
		 * Destruktor 
		 */
        ~BB_WidgetToolPointNew();
		
		/**
		 * Aktualisiert das Eigenschaftsfenster
		 * @author Alex Letkemann
		 */
        virtual void updateWidget();
		
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


    private slots:
        /**
         * Wird aufgerufen, wenn die Position des Punktes im Fenster geändert wird.
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
		 * @todo doku
		 * @author Vaceslav Ustinov
		 */
		void slotToLine_H();
		/**
		 * @todo doku
		 * @author Vaceslav Ustinov
		 */
		void slotToLine_V();
    
	protected:
        BB_Point* m_Tmp_Point;
        C2dVector m_Tmp_Vector;    
	
	private:
		/* Dialog Form */
        Ui::WidgetToolPointNew m_Ui;
};

#endif
