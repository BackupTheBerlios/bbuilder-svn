//
// C++ Implementation: bb_dlgterrainedit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_dlgterrainedit.h"

/** Konstruktor */
BB_DlgTerrainEdit::BB_DlgTerrainEdit(QWidget * parent, Qt::WFlags f)
 : QDialog(parent,f)
{
	
	m_Dlg.setupUi(this);
	
	connect(m_Dlg.buttonPlanFileSearch, SIGNAL(clicked()), this, SLOT(slotPlanFileSearch()));
}


/** Destruktor */
BB_DlgTerrainEdit::~BB_DlgTerrainEdit()
{
}


/** Ruft einen Datei-Dialog auf, mit welchem eine Bilddatei ausgewählt werden kann */
void BB_DlgTerrainEdit::slotPlanFileSearch()
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


/** Gibt den Namen zurück */
const QString BB_DlgTerrainEdit::getName()
{
	return m_Dlg.lineEditName->text();
}


/** Gibt die Beschreibung zurück */
const QString BB_DlgTerrainEdit::getDescription()
{
	return m_Dlg.lineEditDesc->text();
}


/** Setzt die Beschreibung */
void BB_DlgTerrainEdit::setDescription(const QString& desc)
{
	m_Dlg.lineEditDesc->setText(desc);
}


/** Setzt den Namen */
void BB_DlgTerrainEdit::setName(const QString& name)
{
	m_Dlg.lineEditName->setText(name);
}


/** Gibt den Pfad zur Bilddatei zurück */
QString BB_DlgTerrainEdit::getPlanFile()
{
	return m_Dlg.lineEditPlanFile->text();
}


/** Setzt den Pfad zur Bilddatei */
void BB_DlgTerrainEdit::setPlanFile(QString& file)
{
	m_Dlg.lineEditPlanFile->setText(file);
}
