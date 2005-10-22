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
	
	m_Dlg.setupUi(this);
	
	m_Dlg.lineEditProjectName->setValidator(new QRegExpValidator(QRegExp("[A-Za-z][A-Za-z0-9\\s._]+"), this ));
	
	m_ProjectPath = QDir::homePath();
	m_Dlg.lineEditProjectPath->setText(m_ProjectPath);
	checkDir();
	
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
	
	connect(m_Dlg.textEditProjectDesc,
			SIGNAL(textChanged()),
			this,
			SLOT(slotDescChanged()));

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

// 	m_ProjectPath = m_Dlg.lineEditProjectPath->text();
	m_ProjectPath = text;
	checkDir();
}


/*!
    \fn BB_DlgProjectNew::slotNameChanged()
 */
void BB_DlgProjectNew::slotNameChanged(const QString & text)
{
	m_ProjectName = text;
	m_ProjectDir = text.toLower().remove(QRegExp("\\W"));	
	checkDir();
	cout << "test" << endl;
}



/**
 * Prüft ob, der angegebene Pfad für das neue Projekt gültig ist,
 * schaltet den OK Button ein bzw. aus und
 * Setzt schreibt ein "Ungültig" hinter dem Pfad im Anzeigelabel im Dialog.
 * @author Alex Letkemann
 * @date 17.09.2005
 */
void BB_DlgProjectNew::checkDir()
{
	m_Dir = m_ProjectPath;
	QDir fullPath(m_ProjectPath + "/" + m_ProjectDir);

	bool fullPathExists = fullPath.exists();

	if(m_Dir.exists() && m_ProjectDir != "" && !fullPathExists)
	{
		m_Dlg.okButton->setEnabled(true);
		m_Dlg.lineEditFinalPath->setText(m_Dir.path() 
				+ "/" 
				+ m_ProjectDir);
	}
	else
	{
		m_Dlg.okButton->setEnabled(false);
		m_Dlg.lineEditFinalPath->setText(m_Dir.path() 
				+ "/" 
				+ m_ProjectDir);
		
		if(fullPathExists && m_ProjectDir != "")
		{
			m_Dlg.lineEditFinalPath->setText(m_Dlg.lineEditFinalPath->text() 
					+ QString::fromUtf8(" ( existiert bereits )")); 
		}
		else
		{
			m_Dlg.lineEditFinalPath->setText(m_Dlg.lineEditFinalPath->text() 
					+ QString::fromUtf8(" ( ungültig )")); 
		}

	}
}


QString BB_DlgProjectNew::getProjectDir() const
{
    return m_ProjectDir;
}

QDir BB_DlgProjectNew::getProjectPath() const
{
    return m_Dir;
}



/*!
    \fn BB_DlgProjectNew::slotDescChanged(const QString & text)
 */
void BB_DlgProjectNew::slotDescChanged()
{
	m_ProjectDescription = m_Dlg.textEditProjectDesc->toPlainText(); 
}


QString BB_DlgProjectNew::getProjectName() const
{
    return m_ProjectName;
}


QString BB_DlgProjectNew::getProjectDescription() const
{
    return m_ProjectDescription;
}
