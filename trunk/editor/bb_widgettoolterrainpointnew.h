//
// C++ Interface: bb_widgettoolterrainpointnew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLTERRAINPOINTNEW_H
#define BB_WIDGETTOOLTERRAINPOINTNEW_H

#include <bb_abstracttoolwidget.h>
#include <bb_point.h>
#include <ui_toolWidgetTerrainPointNew.h>
/**
Fenster für das Geländepunkt-Erstellungs-Werkzeug

	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolTerrainPointNew : public BB_AbstractToolWidget
{
	Q_OBJECT
public:
    BB_WidgetToolTerrainPointNew(BB_AbstractTool* parentTool, QWidget* parent = 0);

    ~BB_WidgetToolTerrainPointNew();

    virtual void clearToolWidget();
    virtual void setWidgetEnabled(bool value);
    virtual void updateWidget();

	private slots:
		void slotPosFinished();
		void slotDelete();
		void slotDescFinished();
		void slotNameFinished();
protected:
    BB_Point* m_Tmp_Point;
	Ui::WidgetToolTerrainPointNew m_Ui;
private slots:
    void slotHeightFinished();
};

#endif
