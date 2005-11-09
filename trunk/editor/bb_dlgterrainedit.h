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
@author Alex Letkemann
*/
class BB_DlgTerrainEdit : public QDialog
{
	Q_OBJECT
	
public:
	BB_DlgTerrainEdit(QWidget * parent = 0, Qt::WFlags f = 0);

    ~BB_DlgTerrainEdit();

	
	const QString getName();
	const QString getDescription();
	void setDescription(const QString& desc);
	void setName(const QString& name);
	QString getPlanFile();
	void setPlanFile(QString& file);

private slots:
	void slotPlanFileSearch();
	
protected:
    Ui_TerrainEditDialog m_Dlg;
};

#endif
