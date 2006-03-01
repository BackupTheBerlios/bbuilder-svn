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
#ifndef BB_TABBUILDING_H
#define BB_TABBUILDING_H

#include "bb_tab.h"
#include "bb_building.h"


/**
 * Ein Tab, in dem die Gebäude bearbeitet werden.
 * Auf der Linken seite befinden sich die Tools, die Gebäude liste und die Buttons Neu, Löschen und Eigenschaften.
 * In der Mitte befindet sich die Arbeitsfläche.
 * Rechts erscheinen die Eigenschaftsfenster der Tools.
 * @author Alex Letkemann
 */
class BB_TabBuilding : public BB_Tab
{
        Q_OBJECT
    public:
		
		/**
		 * Konstruktor.
		 * Erstellt ein neues Gebäude-Tab.
		 * @param doc Doc, welches die Daten enthält.
		 * @param parent Das Parent-Fenster
		 * @param f QtWindowFlags
		 * @author Alex Letkemann
		 */
        BB_TabBuilding( BB_Doc * doc, QWidget* parent = 0, Qt::WFlags f = 0 );

		/**
		 * Destruktor
		 */
        ~BB_TabBuilding();

		/**
		 * Erzeugt die Gebäude-Liste.
		 * @author Alex Letkemann
		 */
        void createBuildingList();
		
		/**
		 * Leert die aktuelle Liste und löscht das 'Luste-Erstellt'-Flag,
		 * damit eine neue Liste erstellt werden kann.
		 * @author Alex Letkemann
		 */
        virtual void clear();
		
		/**
		 * Aktualisiert die Gebäudeliste
		 * @author Alex Letkemann
		 */
        virtual void updateLists();

    private slots:
		
		/**
		 * Startet einen Dialog zum Bearbeiten der Eigenschaften eines Gebäudes
		 * @author Alex Letkemann
		 */
        void slotBuildingProperties();
		
		/**
		 * Wird aufgerufen, wenn der Button 'Löschen' auf der linken Seite gedrückt wird.
		 * Löscht das aüsgewählte Gebäude.
		 * @author Alex Letkemann
		 */
        void slotBuildingDelete();
		
		/**
		 * Wird aufgerufen, wenn der Button 'Neu' auf der linken Seite gedrückt wird.
		 * Lässt ein neues Gebäude erstellen.
		 * @author Alex Letkemann
		 */
        void slotBuildingNew();

		
		/**
		 * Wird aufgerufen, wenn der User ein anderes Gebäude in der Liste auswählt.
		 * Setzt das neue DocComponent in die Arbeitsfläche.
		 * @param current Das QListWidgetItem des neuen Gebäudes.
		 * @param previous Das QListWidgetItem des letzen Gebäudes.
		 * @author Alex Letkemann
		 */
        void slotBuildingChanged( QListWidgetItem * current, QListWidgetItem * previous );
    protected:

		/* Vektor mit allen Gebäuden */
        QVector<BB_Building*>* m_Buildings;
		
		/* ListenFenster */
        QListWidget* m_BuildingsListWidget;
		
		/* Buttons */
        QPushButton* m_ButtonBuildingDelete;
        QPushButton* m_ButtonBuildingNew;
        QPushButton* m_ButtonBuildingProperties;

		/** Status der Liste */
        bool m_BuildingsListCreated;

    private:
        void initTools();
		/**
		 * Initialisiert das linke Tool-Fenster
		 */
        void initWidgetLeft();
		
		/**
		 * Initialisiert das rechte Tool-Fenster
		 */
        void initWidgetRight();
		
		/**
		 * Speichert das aktuelle Gebäude
		 * @return Erfolg des Speicherns. True im Erfolg, sonst false.
		 * @author Alex Letkemann
		 */
        virtual bool saveCurrent();

};

#endif
