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

/**
Basisklasse für alle Tool-Fenster
 
	@author Alex Letkemann <alex@letkemann.de>
*/
class BB_AbstractToolWidget : public QWidget
{
        Q_OBJECT
    public:
        BB_AbstractToolWidget( QWidget *parent = 0 );

        ~BB_AbstractToolWidget();
    virtual void updateWidget();

};

#endif
