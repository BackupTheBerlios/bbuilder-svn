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
	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->setMargin(0);
	layout->setMargin(0);
	layout->setSpacing(2);

	QTableWidget *view = new QTableWidget();
	
	view->setColumnCount(2);

	
	view->verticalHeader()->setVisible(false);
	
	view->setSelectionBehavior(QAbstractItemView::SelectRows);
	view->setSelectionMode(QAbstractItemView::SingleSelection);
			
	
// 	QStandardItemModel *model = new QStandardItemModel(7,2);
// // 	model->
//     model->setHeaderData(0, Qt::Horizontal, tr("Attribut"));
//     model->setHeaderData(1, Qt::Horizontal, tr("Wert"));
// 	
//     QModelIndex index = model->index(0, 0);
// 	model->setData(index, QVariant("Name"), Qt::DisplayRole);
//     index = model->index(0, 1);
// 	model->setData(index, QVariant("Object_x"), Qt::EditRole);
	
	view->horizontalHeader()->setResizeMode(0, QHeaderView::Interactive);
	view->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
	
	view->horizontalHeader()->setClickable(false);
	view->horizontalHeader()->setSortIndicatorShown(false);
	view->horizontalHeader()->setHighlightSections (false);	
	
// 	view->setModel(model);
	
	
	QGroupBox * gBox = new QGroupBox();
	gBox->setTitle(QString::fromUtf8("Eigenschaften"));
	gBox->setFlat(true);
	
	layout->addWidget(gBox);
	layout->addWidget(view);
 	setLayout(layout);
}


BB_PropertyWidget::~BB_PropertyWidget()
{
}
