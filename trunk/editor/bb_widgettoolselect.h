//
// C++ Interface: bb_widgettoolselect
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLSELECT_H
#define BB_WIDGETTOOLSELECT_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetSelect.h>


class BB_ToolMove;

/**
Fenster für das Selektions-Werkzeug
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolSelect : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:
		BB_WidgetToolSelect( BB_ToolMove* parentTool );
        ~BB_WidgetToolSelect();
        virtual void updateWidget();


    private slots:
        void slotNameFinished();
        void slotDescFinished();
    void slotDeleteSelection();

    protected:
        Ui::WidgetToolSelect m_Ui;
    private:
        void commitName();
        void commitDesc();


private slots:
    void slotSelectAll();
};

#endif
