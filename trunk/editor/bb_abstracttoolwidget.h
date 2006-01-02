//
// C++ Interface: bb_abstracttoolwidget
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_ABSTRACTTOOLWIDGET_H
#define BB_ABSTRACTTOOLWIDGET_H

#include <QWidget>
#include <bb_drawobject.h>

class BB_AbstractTool;

/**
Basisklasse für alle Tool-Fenster
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_AbstractToolWidget : public QWidget
{
        Q_OBJECT
    public:
		BB_AbstractToolWidget( BB_AbstractTool* parentTool, QWidget *parent = 0 );

        ~BB_AbstractToolWidget();
    virtual void updateWidget();
    virtual void setSelection( QVector< BB_DrawObject* >* vector );
    virtual void clearToolWidget();
    virtual void setWidgetEnabled( bool value );
	
	QVector< BB_DrawObject* >* m_Selection;
	protected:
		BB_AbstractTool *m_ParentTool;
    	BB_DrawObject* m_Tmp_DrawObject;
};

#endif
