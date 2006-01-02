/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
***************************************************************************/
#ifndef BB_TAB_H
#define BB_TAB_H

#include <QtGui>
#include <iostream>

#include "bb_doc.h"
#include "bb_abstracttool.h"

class BB_WorkArea;

using namespace std;

/**
@author Alex Letkemann
*/
class BB_Tab : public QWidget
{
        Q_OBJECT
    public:
        /**
         * Konstruktor
		 * Erstellt ein neues Tab mit drei Bereichen.<br />
		 * Links: Das Fenster, in dem die Toolbuttons angezeigt werden (QFrame).<br />
		 * Mitte: Die Arbeitsfl&auml;che (BB_WorkArea).<br />
		 * Rechts: Das Fenster für die Eigenschaften der Tools (QStackedWidget).<br />
         * @param doc Das Dokument, mit welchem gearbeitet werden soll
         * @param parent Fenster in dem der Tab erstellt wird.
         * @param f QtFlags
         */
        BB_Tab( BB_Doc* doc, QWidget* parent = 0, Qt::WFlags f = 0 );
//         BB_Tab( BB_Doc* doc, bool leftFrame, bool rightFrame, QWidget* parent = 0, Qt::WFlags f = 0 );

        /**
         * Destruktor
         */
        ~BB_Tab();
		
        /**
         * Initialisiert das Tab-Fenster.
         */
        virtual void initTab();
		
        /**
         * Setzt alle Toolbuttons außer dem Toolbutton, welches 'action'
		 * als DefaultAction besitzt, auf nicht gedrückt.
         * @param action Aktion des Toolbuttons, welches nicht zur&uuml;ckgesetzt werden soll.
         */
        void unsetToolButton( QAction *action );
		
		/**
		 * Setzt den DocComponent der Arbeitsfl&auml;che auf null und
		 * deaktiviert diese damit;
		 */
        void unsetDocComponent();

        /**
         * Aktualisiert das Fenster
         */
        virtual void updateWidget();
		
		/**
		 * Setzt alle DrawObject-Vektoren auf NULL
		 * Und leert alles Listen. BB_Doc muss bereits geleert sein, 
		 * wenn diese Funktion aufgerufen wird.
		 */
        virtual void clear();
		
        /**
         * Speichert das Aktuelle DocComponent,
		 * welches in der Workframe bearbeitet wird
         * @return Erfolg des Speicherns
         */
        virtual bool saveCurrent();
		
        /**
         * Setzt das Aktuelle Tool zur&uuml;ck
         */
        virtual void resetTool();

	private:
		/**
		 * Prüft und setzt das Doc, welches verwendet wird.
		 * @param doc Doc, welches verwendet wird.
		 * @author Alex Letkemann
		 * @date 22.10.2005
		 */
        void setDoc( BB_Doc* doc );
		
    private slots:
		/**
		 * Setzt das Tool zurück, und ruft die Funktion toolChanged(..) auf, die das Tool weiterbearbeitet
		 * Wird aufgeruffen, wenn ein neues Tool ausgewählt wird.
		 * @param action Aktion des neuen Tools
		 */
        void slotToolChanged( QAction* action );
		
    protected:
        /**
         * Fügt ein Tool zum Linken Fenster hinzu
         * @param tool Tool, welches hinzugef&uuml;gt werden soll
         * @param name Name des Tools
         * @param info Informationen zum Tool
         * @return Die Aktion des erzeugten Tools
         */
        virtual QAction* addTool( BB_AbstractTool* tool, const QString& name, const QString& info );
		
        /**
         * Setzt das Tool 'tool' in der WorkArea.
         * @param tool Tool welches benutzt werden soll.
         */
        virtual void setTool( BB_AbstractTool* tool );
		
		
		/**
		 * Initialisiert und erstellt das Layout des Tabs.
		 * @param leftFrame Gibt an, ob das Linke Fenster erzegt werden soll.
		 * @param rightFrame Gibt an, ob das Rechte Fenster erzegt werden soll.
		 */
		void initLayout( bool leftFrame, bool rightFrame );
		
		/**
		 * Erzeugt ein Toolbutton
		 * @param action Aktion des Tools
		 * @param tool Tool, für welches der Toolbutton erzeugt werden soll.
		 * @return True, falls der Toolbutton erfolgreich erstellt werden konnte, sonst false.
		 */
		virtual bool createToolButton( QAction* action, BB_AbstractTool* tool );
		
		/**
		 * Wird ausgeführt, wenn ein Toolbuttons betätigt wird. Diese Funktion sollte in jeder 
		 * abgeleiteten Klasse, die Tools enthält, überladen werden. Falls dies nicht geschechen ist
		 * und ToolButton wird betätigt kommt die die Meldung <i>toolChanged(QAction* action) nicht implementiert</i> in stdout.
		 * Hier werden die Tools weiter an die Arbeitsfläche übergeben.
		 * @param action QAction Pointer des Tools
		 */
		virtual void toolChanged( QAction* action );
    protected:
		
		/**
		 * Hängt ein QWidget im linken Frame an
		 * @param widget Das QWidget, dass angehängt werden soll
		 * @param stretchFaktor Gibt an, ob und wie stark sich das Widget streckt wenn die Größe des Fensters verändert wird. Default ist 0
		 * @return Gibt false im Fehlerfall zurück, sonst true
		 * @author Alex Letkemann
	 	 * @date 18.08.2005
		 */
        bool addWidgetLeft( QWidget *widget, int stretchFaktor = 0 );
		
		/**
		 * Fügt ein Fenster zum StackWidget hinzu
		 * @param widget Das QWidget, das im rechten StackWidget hinzugefügt werden soll
		 * @return Gibt false im Fehlerfall zurück, sonst true
		 * @author Alex Letkemann
		 * @date 25.12.2005
		 */
        bool addWidgetRight( QWidget *widget );

        BB_Doc * m_Doc;
        QVector<BB_DrawObject*>* m_DrawObjects;
        QVector<BB_DrawObject*> m_Selection;


        BB_WorkArea *m_Center;

        QFrame *m_LeftFrame;
        QStackedWidget *m_RightFrame;

        QGridLayout* m_ToolsGridLayout;
        int m_ToolButtonCount;
        QList<QAction*> *m_ToolButtonActions;



};

#endif
