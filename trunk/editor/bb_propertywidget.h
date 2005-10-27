//
// C++ Interface: bb_propertywidget
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_PROPERTYWIDGET_H
#define BB_PROPERTYWIDGET_H

#include <qwidget.h>

/**
@author Alex Letkemann
*/
class BB_PropertyWidget : public QWidget
{
public:
	BB_PropertyWidget(QWidget * parent = 0, Qt::WFlags f = 0);

    ~BB_PropertyWidget();

};

#endif
