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
@author Alex Letkemann
*/
class BB_DlgBuildingEdit : public QDialog
{
	Q_OBJECT
public:
	BB_DlgBuildingEdit(QWidget * parent = 0, Qt::WFlags f = 0);

    ~BB_DlgBuildingEdit();
    const QString getName();
    const QString getDescription();
    void setDescription(const QString& desc);
    void setName(const QString& name);
    QString getPlanFile();
    void setPlanFile(QString& file);

private slots:
    void slotPlanFileSearch();
	
protected:
	Ui_BuildingEditDialog m_Dlg;
};

#endif
