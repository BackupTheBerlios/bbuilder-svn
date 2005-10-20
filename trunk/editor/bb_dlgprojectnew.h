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
#ifndef BB_DLGPROJECTNEW_H
#define BB_DLGPROJECTNEW_H

#include <QDialog>
#include <QDir>
#include "ui_projectNew.h"

/**
@author Alex Letkemann
*/
class BB_DlgProjectNew : public QDialog
{
	Q_OBJECT
	
public:
	BB_DlgProjectNew(QWidget * parent = 0, Qt::WFlags f = 0);

    ~BB_DlgProjectNew();

	void setProjectDir(const QString& theValue);
	QString projectDir() const;
	void setProjectPath(const QString& theValue);
	void setProjectPath(const QDir& theValue);
	QDir projectPath() const;
	
	
	

private slots:
    void slotShowDir();
	void slotPathChanged(const QString & text);
	void slotNameChanged(const QString & text);
	
protected:
    Ui_ProjectNewDialog m_Dlg;
    QDir m_Dir;
    QString m_ProjectPath;
    QString m_ProjectDir;
	
private:
    void checkDir();
};

#endif
