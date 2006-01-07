//
// C++ Interface: bb_widgettoolterraintrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_WIDGETTOOLTERRAINTRIANGLENEW_H
#define BB_WIDGETTOOLTERRAINTRIANGLENEW_H

#include <bb_abstracttoolwidget.h>
#include <ui_toolWidgetTerrainTriangleNew.h>
#include <bb_triangle.h>

/**
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_WidgetToolTerrainTriangleNew : public BB_AbstractToolWidget
{
        Q_OBJECT
    public:

        BB_WidgetToolTerrainTriangleNew( BB_AbstractTool* parentTool, QWidget* parent = 0 );

        ~BB_WidgetToolTerrainTriangleNew();

        virtual void clearToolWidget();
        virtual void setWidgetEnabled( bool value );
        virtual void updateWidget();
    QString getTextureFileName();

        Ui::WidgetToolTerrainTriangleNew m_Ui;

    private slots:
        void slotDelete();
        void slotDescFinished();
        void slotNameFinished();
        void slotTextureFinished();
        void slotTextureSearch();
};

#endif
