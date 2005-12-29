//
// C++ Interface: bb_widgettoolscale
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLSCALE_H
#define BB_WIDGETTOOLSCALE_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetScale.h>

/**
Tool-Fenster für das ToolScale

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolScale : public BB_AbstractToolWidget
{
	Q_OBJECT
public:
	BB_WidgetToolScale( BB_AbstractTool* parentTool );

    ~BB_WidgetToolScale();
    void setLogicalScale( double value );
    void setRealScale( double *real );

	
	protected:
		Ui::WidgetToolScale m_Ui;
    double* m_RealScale;
private:
    void commitReal();
private slots:
	void slotRealFinished();
protected:
    virtual void setupUi();
};

#endif
