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
	/** Konstruktor */ 
	BB_DlgBuildingEdit(QWidget * parent = 0, Qt::WFlags f = 0);

	/** Destruktor */
    ~BB_DlgBuildingEdit();
	
	/** Gibt den Namen des Gebäudes zurück */
    const QString getName();
	
	/** Gibt die Beschreibung des Gebäudes zurück */
    const QString getDescription();
	
	/** Setzt die Beschreibung */
    void setDescription(const QString& desc);
	
	/** Setzt den Namen */
    void setName(const QString& name);
	
	/** Gibt den Pfad zur Bilddatei zurück */
    QString getPlanFile();
	
	/** Setzt den Pfad zur Bilddatei */
    void setPlanFile(QString& file);

private slots:
	/** Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei auswählen kann */
    void slotPlanFileSearch();
	
protected:
	Ui_BuildingEditDialog m_Dlg;
};

#endif
