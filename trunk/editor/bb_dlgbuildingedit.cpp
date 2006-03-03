//
// C++ Implementation: bb_dlgbuildingedit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_dlgbuildingedit.h"
#include <iostream>

using namespace std;

/** 
 * Konstruktor
 * @param parent Fenster, welches blockiert wird, solnage der Dialog aktiv ist.
 * @param Qt-Window-Flags
 * @author Alex Letkemann
 */
BB_DlgBuildingEdit::BB_DlgBuildingEdit(QWidget * parent, Qt::WFlags f)
 : QDialog(parent,f)
{
	
	m_Dlg.setupUi(this);
	
	connect(m_Dlg.buttonPlanFileSearch, SIGNAL(clicked()), this, SLOT(slotPlanFileSearch()));
}


/**
 * Destruktor
 */
BB_DlgBuildingEdit::~BB_DlgBuildingEdit()
{
}




/** 
 * Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei auswählen kann 
 * @author Alex Letkemann
 */
void BB_DlgBuildingEdit::slotPlanFileSearch()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(	this,
												QString::fromUtf8("Öffnen"),
												m_Dlg.lineEditPlanFile->text(),
												"Images (*.png *.bmp *.jpg)");
	if(!filename.isEmpty())
	{
		m_Dlg.lineEditPlanFile->setText(filename);
	}
}


/** 
 * Gibt den Namen des Gebäudes zurück
 * @return Name des Gebäudes
 * @author Alex Letkemann
 */
const QString BB_DlgBuildingEdit::getName()
{
	return m_Dlg.lineEditName->text();
}


/** 
 * Gibt die Beschreibung des Gebäudes zurück .
 * @return Beschreibung des Gebäudes.
 * @author Alex Letkemann
 */
const QString BB_DlgBuildingEdit::getDescription()
{
	return m_Dlg.lineEditDesc->text();
}


/**
 * Setzt die Beschreibung des Gebäudes
 * @param desc Beschreibung des Gebäudes
 * @author Alex Letkemann
 */
void BB_DlgBuildingEdit::setDescription(const QString& desc)
{
	m_Dlg.lineEditDesc->setText(desc);
}


/**
 * Setzt den Namen des Gebäudes
 * @param name Namen des Gebäudes
 * @author Alex Letkemann
 */
void BB_DlgBuildingEdit::setName(const QString& name)
{
	m_Dlg.lineEditName->setText(name);
}


/**
 * Gibt den Pfad zur Bilddatei zurück.
 * @return Pfad zur Bilddatei.
 * @author Alex Letkemann
 */
QString BB_DlgBuildingEdit::getPlanFile()
{
	return m_Dlg.lineEditPlanFile->text();
}


/**
 * Setzt den Pfad zur Bilddatei.
 * @param file Pfad zur Bilddatei.
 * @author Alex Letkemann
 */
void BB_DlgBuildingEdit::setPlanFile(QString& file)
{
	m_Dlg.lineEditPlanFile->setText(file);
}
