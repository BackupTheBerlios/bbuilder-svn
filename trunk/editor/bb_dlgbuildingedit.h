//
// C++ Interface: bb_dlgbuildingedit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DLGBUILDINGEDIT_H
#define BB_DLGBUILDINGEDIT_H

#include <QtGui>
#include "ui_buildingEdit.h"

/**
 * Dialog zum Bearbeiten von Gebäuden.
 * Mit dem Dialog lassen sich der Name, die Beschreibung und der Pfad zur Bilddatei ändern.
 * @author Alex Letkemann
 */
class BB_DlgBuildingEdit : public QDialog
{
	Q_OBJECT
public:
	/** 
	 * Konstruktor
	 * @param parent Fenster, welches blockiert wird, solnage der Dialog aktiv ist.
	 * @param f Qt-Window-Flags
	 * @author Alex Letkemann
	 */ 
	BB_DlgBuildingEdit(QWidget * parent = 0, Qt::WFlags f = 0);

	/** Destruktor */
    ~BB_DlgBuildingEdit();
	
	/** 
	 * Gibt den Namen des Gebäudes zurück
     * @return Name des Gebäudes
	 * @author Alex Letkemann
     */
    const QString getName();
	
	/** 
	 * Gibt die Beschreibung des Gebäudes zurück .
	 * @return Beschreibung des Gebäudes.
	 * @author Alex Letkemann
	 */
    const QString getDescription();
	
    /**
     * Setzt die Beschreibung des Gebäudes
	 * @param desc Beschreibung des Gebäudes
	 * @author Alex Letkemann
     */
    void setDescription(const QString& desc);
	
	
    /**
     * Setzt den Namen des Gebäudes
	 * @param name Namen des Gebäudes
	 * @author Alex Letkemann
     */
    void setName(const QString& name);
	
    /**
	 * Gibt den Pfad zur Bilddatei zurück.
	 * @return Pfad zur Bilddatei.
	 * @author Alex Letkemann
     */
    QString getPlanFile();
	
    /**
     * Setzt den Pfad zur Bilddatei.
	 * @param file Pfad zur Bilddatei.
	 * @author Alex Letkemann
     */
    void setPlanFile(QString& file);

private slots:
	/** 
	 * Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei auswählen kann 
	 * @author Alex Letkemann
	 */
    void slotPlanFileSearch();
	
protected:
	/** Form */
	Ui_BuildingEditDialog m_Dlg;
};

#endif
