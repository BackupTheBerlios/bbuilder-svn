//
// C++ Interface: bb_dlgtoolscaleedit
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DLGTOOLSCALEEDIT_H
#define BB_DLGTOOLSCALEEDIT_H

#include <QDialog>
#include <ui_scaleEdit.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_DlgToolScaleEdit : public QDialog
{
	Q_OBJECT
    public:
        BB_DlgToolScaleEdit( QWidget * parent );

        ~BB_DlgToolScaleEdit();
        double getScaleReal();
        double getScaleLogic();
        void setScaleLogic( double scale );
        void setScaleReal( double scale );
	
		Ui_ScaleEditDialog m_Dlg;
};

#endif
