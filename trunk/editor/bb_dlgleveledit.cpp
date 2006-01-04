//
// C++ Implementation: bb_dlgleveledit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_dlgleveledit.h"
#include <QFileDialog>

BB_DlgLevelEdit::BB_DlgLevelEdit( QWidget* parent )
: QDialog(parent)
{
	m_Dlg.setupUi( this );
	connect(m_Dlg.button_PlanFileSearch, SIGNAL(clicked()), this, SLOT(slotPlanFileSearch()));
}


BB_DlgLevelEdit::~BB_DlgLevelEdit()
{
}




/*!
    \fn BB_DlgLevelEdit::getDescription() const
 */
const QString BB_DlgLevelEdit::getDescription() const
{
	return m_Dlg.textEdit_Desc->toPlainText();
}


/*!
    \fn BB_DlgLevelEdit::getName() const
 */
const QString BB_DlgLevelEdit::getName() const
{
	return m_Dlg.lineEdit_Name->text();
}


/*!
    \fn BB_DlgLevelEdit::getPlanFile() const
 */
const QString BB_DlgLevelEdit::getPlanFile() const
{
	return m_Dlg.lineEdit_PlanFile->text();
}


/*!
    \fn BB_DlgLevelEdit::setDescription( const QString& desc )
 */
void BB_DlgLevelEdit::setDescription( const QString& desc )
{
	m_Dlg.textEdit_Desc->setPlainText( desc );
}


/*!
    \fn BB_DlgLevelEdit::setName( const QString& name )
 */
void BB_DlgLevelEdit::setName( const QString& name )
{
	m_Dlg.lineEdit_Name->setText( name );
}


/*!
    \fn BB_DlgLevelEdit::setPlanFile( const QString& file )
 */
void BB_DlgLevelEdit::setPlanFile( const QString& file )
{
	m_Dlg.lineEdit_PlanFile->setText( file );
}


/*!
    \fn BB_DlgLevelEdit::slotPlanFileSearch()
 */
void BB_DlgLevelEdit::slotPlanFileSearch()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(	this,
			QString::fromUtf8("Öffnen"),
			m_Dlg.lineEdit_PlanFile->text(),
			"Images (*.png *.bmp *.jpg)");
	if(!filename.isEmpty())
	{
		m_Dlg.lineEdit_PlanFile->setText(filename);
	}
}
