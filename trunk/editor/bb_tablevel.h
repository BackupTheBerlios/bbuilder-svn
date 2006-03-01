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
#ifndef BB_TABLEVEL_H
#define BB_TABLEVEL_H

#include "bb_tab.h"
#include "bb_toolzoom.h"

/**
 * Ein Tab, in dem die Etagen bearbeitet werden.
 * Auf der Linken seite befinden sich die Tools, die Gebäude-Combo-Box, die Etagen liste und die Buttons Neu, Löschen und Eigenschaften.
 * In der Mitte befindet sich die Arbeitsfläche.
 * Rechts erscheinen die Eigenschaftsfenster der Tools.
 * @author Alex Letkemann
 */
class BB_TabLevel : public BB_Tab
{
Q_OBJECT
public:
    /**
 	 * Konstruktor.
	 * Erstellt ein neues Etagen-Tab.
	 * @param doc Dokument, welches die Daten enthält.
	 * @param parent Das Parent-Fenster
	 * @param f QtWindowFlags
     * @author Alex Letkemann
	 */
	BB_TabLevel(BB_Doc * doc, QWidget* parent = 0, Qt::WFlags f = 0);

    /**
     * Destruktor
	 * @author Alex Letkemann
     */
    ~BB_TabLevel();
	
    /**
     * Aktualisert die Listen
	 * @author Alex Letkemann
     */
    virtual void updateLists();
    
	/**
	 * Speichert die Aktuelle Etage
	 * @return Erfolg des Seicherns. True im Erfolg, sonst false
	 * @author Alex Letkemann
	 */
	virtual bool saveCurrent();
    

protected:
    QPushButton* m_ButtonLevelProperties;
    QPushButton* m_ButtonLevelDelete;
    QPushButton* m_ButtonLevelNew;
    BB_AbstractTool* m_ToolZoom;
    QVector< BB_Building* >* m_Buildings;
    QVector< BB_Level* >* m_Levels;
	QListWidget* m_ListWidgetLevels;
	QComboBox* m_ComboBoxBuildings;
	BB_Building* m_Building;
	
private slots:
	
	/**
	 * Startet ein Dialog zum erstellen einer neuen Etage
	 * @author Alex Letkemann
	 */
	void slotLevelNew();
	
	/**
	 * Startet ein Dialog zum Bearbeiten der aktuellen Etage
	 * @author Alex Letkemann
	 */
	void slotLevelProperties();
	
	/**
	 * Löscht die Aktuelle Etage
	 * @author Alex Letkemann
	 */
	void slotLevelDelete();


protected:
	
    /**
     * Initialisiert das linke Fenster
     * @author Alex Letkemann
     */
    void initWidgetLeft();
	
	
    /**
     * Initialisiert die Tools
	 * @author Alex Letkemann
     */
    void initTools();
	
    /**
     * Aktualisert die Gebäudeliste
	 * @author Alex Letkemann
     */
    void updateBuildingList();
	
    /**
     * Aktualisert die Etagenliste
	 * @author Alex Letkemann
     */
    void updateLevelList();
	
    /**
     * Wird aufgerufen, wenn das Dokument (m_Doc) sich ändert.
	 * @author Alex Letkemann
     */
    void documentChanged();
	
	/**
	 * Setzt das Gebäude, dessen Etagen bearbeitet werden sollen.
	 * @param building Gebäude, dessen Etagen bearbeitet werden sollen
	 * @author Alex Letkemann
	 */
	void setBuilding( BB_Building* building );
	
	
	/**
	 * Setzt die Etage, die Bearbeitet werden soll.
	 * @param level Etage, die Bearbeitet werden soll
	 * @author Alex Letkemann
	 */
	void setLevel( BB_Level* level );
	
	
    /**
     * Aktiviert oder Deaktiviert das Tab-Fenster
     * @param value True: Aktiviert, False: Deaktiviert
	 * @author Alex Letkemann
     */
    void setWidgetEnabled( bool value );
	
private slots:
    /**
     * Wird aufgerufen, wenn das Geböude geändert wird.
	 * Aktualisert die Listen.
     * @param row Index des Gebäudes.
     * @author Alex Letkemann
     */
    void slotBuildingChanged( int row );
	
	
    /**
     * Wird aufgerufen, wenn die Etage geändert wird.
	 * Aktualisert die Arbeitsfläche.
     * @param row Index der Etage.
	 * @author Alex Letkemann
     */
    void slotLevelChanged( int row );
};

#endif
