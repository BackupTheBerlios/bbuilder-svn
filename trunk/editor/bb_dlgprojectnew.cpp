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
 ***************************************************************************/
#include "bb_dlgprojectnew.h"

#include <iostream>
#include <QtGui>
using namespace std;

BB_DlgProjectNew::BB_DlgProjectNew(QWidget * parent, Qt::WFlags f)
 : QDialog(parent,f)
{
	
#if defined(Q_WS_WIN32) || defined(Q_WS_WIN64)
	m_Slash = "\\";
#elif defined(Q_WS_X11)
	m_Slash = "/";
#endif
	
	
	m_Dlg.setupUi(this);
	
	m_Dlg.lineEditProjectName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z][A-Za-z0-9\\s._]+"), this ));
	
	m_Dlg.lineEditProjectPath->setText(QDir::homePath());
	
	connect(m_Dlg.buttonShowDir,
			SIGNAL(clicked()),
			this,
			SLOT(slotShowDir()));
	
	connect(m_Dlg.lineEditProjectName,
			SIGNAL(textChanged(const QString&)),
			this,
			SLOT(slotNameChanged(const QString&)));
	
	connect(m_Dlg.lineEditProjectPath,
			SIGNAL(textChanged(const QString&)),
			this,
			SLOT(slotPathChanged(const QString&)));

}


BB_DlgProjectNew::~BB_DlgProjectNew()
{
}




/*!
    \fn BB_DlgProjectNew::slotShowDir()
 */
void BB_DlgProjectNew::slotShowDir()
{
	cout << "ShowDir" << endl;
	QFileDialog fileDialog(this);
	fileDialog.setAcceptMode(QFileDialog::AcceptSave);
	fileDialog.setDirectory(QDir::home());
	fileDialog.setFileMode(QFileDialog::DirectoryOnly);
	fileDialog.setViewMode(QFileDialog::List);

	
	if(fileDialog.exec())
	{
		m_Dlg.lineEditProjectPath->setText(fileDialog.selectedFiles().at(0));
	}
	
	
}


/*!
    \fn BB_DlgProjectNew::slotPathChanged()
 */
void BB_DlgProjectNew::slotPathChanged(const QString & text)
{
	m_Dlg.lineEditFinalPath->setText(text
			+ m_Slash
			+ m_Dlg.lineEditProjectName->text());
	
	m_Dir = m_Dlg.lineEditFinalPath->text();
	
	checkDir();
}


/*!
    \fn BB_DlgProjectNew::slotNameChanged()
 */
void BB_DlgProjectNew::slotNameChanged(const QString & text)
{
	m_Dlg.lineEditFinalPath->setText(m_Dlg.lineEditProjectPath->text()
			+ m_Slash
			+ text.toLower().remove(QRegExp("\\W")));

}



/*!
    \fn BB_DlgProjectNew::checkDie(const QDir& dir)
 */
bool BB_DlgProjectNew::checkDir()
{
	return m_Dir.exists();
}
