//
// C++ Implementation: bb_propertywidget
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_propertywidget.h"


#include <QtGui>
#include <iostream>

using namespace std;


BB_PropertyWidget::BB_PropertyWidget(QWidget * parent, Qt::WFlags f)
 : QWidget(parent,f)
{
	QHBoxLayout layout;
	

	QTableView *view = new QTableView();
		

	
	view->verticalHeader()->setVisible(false);
			
	
	QStandardItemModel *model = new QStandardItemModel(7,2);
// 	model->
    model->setHeaderData(0, Qt::Horizontal, tr("Attribut"));
    model->setHeaderData(1, Qt::Horizontal, tr("Wert"));
	
    QModelIndex index = model->index(0, 0);
    model->setData(index, QVariant("Name"));
    index = model->index(0, 1);
    model->setData(index, QVariant("Object_x"));
	
// 	view->horizontalHeader()->setResizeMode(0, QHeaderView::Interactive);
// 	view->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
	
	view->horizontalHeader()->setClickable(false);
	view->horizontalHeader()->setSortIndicatorShown(false);
	view->horizontalHeader()->setHighlightSections (false);	
	
	view->setModel(model);
	
	layout.addWidget(view);
	setLayout(&layout);
}


BB_PropertyWidget::~BB_PropertyWidget()
{
}


