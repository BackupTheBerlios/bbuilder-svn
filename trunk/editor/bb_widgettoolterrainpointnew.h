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
	/**
	 * @fn BB_AbstractToolWidget::BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget* parent = 0 )
	 */
    BB_WidgetToolTerrainPointNew(BB_AbstractTool* parentTool, QWidget* parent = 0);

    ~BB_WidgetToolTerrainPointNew();

	/**
	 * Lädt die Default-Werte in das Werkzeugfenster.
	 * @author Alex Letkemann
	 */
    virtual void clearToolWidget();
	
	/**
	 * Aktiviert oder Deaktiviert das Fenster.<br />
	 * @param value True: Aktiviert, False: Deaktiviert
	 * @author Alex Letkemann
	 */
    virtual void setWidgetEnabled(bool value);
	
	/**
	 * Aktiviert oder Deaktiviert das Fenster.<br />
	 * @param value True: Aktiviert, False: Deaktiviert
	 * @author Alex Letkemann
	 */
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
