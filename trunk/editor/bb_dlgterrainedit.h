//
// C++ Interface: bb_dlgterrainedit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DLGTERRAINEDIT_H
#define BB_DLGTERRAINEDIT_H

#include <QtGui>
#include "ui_terrainEdit.h"

/**
 * Dialog zum Bearbeiten des Geländes.
 * Mit dem Dialog lassen sich der Name, die Beschreibung und der Pfad zur Bilddatei ändern.
 * @author Alex Letkemann
 */
class BB_DlgTerrainEdit : public QDialog
{
	Q_OBJECT
	
public:
	/** Konstruktor */
	BB_DlgTerrainEdit(QWidget * parent = 0, Qt::WFlags f = 0);

	/** Destruktor */
    ~BB_DlgTerrainEdit();

	/** Gibt den Namen zurück */
	const QString getName();
	
	/** Gibt die Beschreibung zurück */
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
	/** Ruft einen Datei-Dialog auf, mit welchem eine Bilddatei ausgewählt werden kann */
	void slotPlanFileSearch();
	
protected:
    Ui_TerrainEditDialog m_Dlg;
};

#endif
