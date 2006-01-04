//
// C++ Interface: bb_dlgleveledit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DLGLEVELEDIT_H
#define BB_DLGLEVELEDIT_H

#include <ui_levelEdit.h>
#include <QDialog>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_DlgLevelEdit : public QDialog
{
Q_OBJECT
public:
    BB_DlgLevelEdit( QWidget* parent );

    ~BB_DlgLevelEdit();
    const QString getDescription() const;
    const QString getName() const;
    const QString getPlanFile() const;
    void setDescription( const QString& desc );
    void setName( const QString& name );
    void setPlanFile( const QString& file );

protected:
    Ui::LevelEditDialog m_Dlg;
private slots:
    void slotPlanFileSearch();
};

#endif
