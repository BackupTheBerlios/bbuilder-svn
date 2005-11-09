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

BB_DlgTerrainEdit::BB_DlgTerrainEdit(QWidget * parent, Qt::WFlags f)
 : QDialog(parent,f)
{
	
	m_Dlg.setupUi(this);
	
	connect(m_Dlg.buttonPlanFileSearch, SIGNAL(clicked()), this, SLOT(slotPlanFileSearch()));
}



BB_DlgTerrainEdit::~BB_DlgTerrainEdit()
{
}


/*!
    \fn BB_DlgBuildingEdit::slotPlanFileSearch()
 */
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


/*!
    \fn BB_DlgBuildingEdit::getName()
 */
const QString BB_DlgTerrainEdit::getName()
{
	return m_Dlg.lineEditName->text();
}


/*!
    \fn BB_DlgBuildingEdit::getDescription()
 */
const QString BB_DlgTerrainEdit::getDescription()
{
	return m_Dlg.lineEditDesc->text();
}


/*!
    \fn BB_DlgBuildingEdit::setDescription(QString& desc)
 */
void BB_DlgTerrainEdit::setDescription(const QString& desc)
{
	m_Dlg.lineEditDesc->setText(desc);
}


/*!
    \fn BB_DlgBuildingEdit::setName(QString& name)
 */
void BB_DlgTerrainEdit::setName(const QString& name)
{
	m_Dlg.lineEditName->setText(name);
}


/*!
    \fn BB_DlgBuildingEdit::getPlanFile()
 */
QString BB_DlgTerrainEdit::getPlanFile()
{
	return m_Dlg.lineEditPlanFile->text();
}


/*!
    \fn BB_DlgBuildingEdit::setPlanFile(QString& file)
 */
void BB_DlgTerrainEdit::setPlanFile(QString& file)
{
	m_Dlg.lineEditPlanFile->setText(file);
}
