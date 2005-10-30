/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann   *
 *   alex@letkemann.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ***************************************************************************/
#include "bb_tablevel.h"
#include "bb_globals.h"

BB_TabLevel::BB_TabLevel(BB_Doc * doc, QWidget* parent, Qt::WFlags f)
 : BB_Tab(doc, parent, f)
{
		
	QGroupBox *gB_Buildings = new QGroupBox();
	gB_Buildings->setTitle(QString::fromUtf8("Gebäude"));
	gB_Buildings->setFlat(true);
	
	QComboBox *cB_Buildings = new QComboBox();
        cB_Buildings->addItem(QString::fromUtf8("Gebäude 1"));
        cB_Buildings->addItem(QString::fromUtf8("Gebäude 2"));
        cB_Buildings->addItem(QString::fromUtf8("Gebäude 3"));
        cB_Buildings->addItem(QString::fromUtf8("Gebäude 4"));
	
	QVBoxLayout *gBL_Building = new QVBoxLayout();
	gBL_Building->setMargin(0);
	gBL_Building->setSpacing(2);
	gBL_Building->addWidget(cB_Buildings,Qt::AlignTop);
	
	gB_Buildings->setLayout(gBL_Building);
	addWidgetLeft(gB_Buildings,0);
	
	QGroupBox *gB_Levels = new QGroupBox();
	gB_Levels->setTitle(QString::fromUtf8("Etagen"));
	gB_Levels->setFlat(true);
		
	QListWidget *lB_Levels = new QListWidget();
	lB_Levels->addItem("Etage 1");
        lB_Levels->addItem("Etage 2");
        lB_Levels->addItem("Etage 3");
        lB_Levels->addItem("Etage 4");
        lB_Levels->addItem("Etage 5");
        lB_Levels->addItem("Etage 6");
        lB_Levels->addItem("Etage 7");
        lB_Levels->addItem("Etage 8");
        lB_Levels->addItem("Etage 9");
        lB_Levels->addItem("Etage 10");
        lB_Levels->addItem("Etage 11");

	
	QVBoxLayout *gBL_Levels = new QVBoxLayout();
	gBL_Levels->setMargin(0);
	gBL_Levels->setSpacing(2);
	gBL_Levels->addWidget(lB_Levels,Qt::AlignTop);
	
	m_ButtonLevelNew = new QPushButton(QString::fromUtf8("Hinzufügen"));
	
	m_ButtonLevelDelete = new QPushButton(QString::fromUtf8("Löschen"));
// 	m_ButtonLevelDelete->setEnabled(false);
	
	m_ButtonLevelProperties = new QPushButton(QString::fromUtf8("Eigenschaften"));
// 	m_ButtonLevelProperties->setEnabled(false);
	
	connect(m_ButtonLevelNew,SIGNAL(clicked(bool)),this,SLOT(slotLevelNew()));
	connect(m_ButtonLevelDelete,SIGNAL(clicked(bool)),this,SLOT(slotLevelDelete()));
	connect(m_ButtonLevelProperties,SIGNAL(clicked(bool)),this,SLOT(slotLevelProperties()));
	
	gBL_Levels->addWidget(m_ButtonLevelNew,Qt::AlignTop);
	gBL_Levels->addWidget(m_ButtonLevelDelete,Qt::AlignTop);
	gBL_Levels->addWidget(m_ButtonLevelProperties,Qt::AlignTop);

	
	gB_Levels->setLayout(gBL_Levels);
	
	addWidgetLeft(gB_Levels,1);
	
	QIcon zoom(IMG_DIR() + SEPARATOR() + "toolZoom.png");
	QAction *toolZoom = new QAction(zoom,"Zoom",this);
	toolZoom->setStatusTip("Zoom Werkzeug");
	createToolButton(toolZoom,SLOT(slotZoomTool(QAction*)));
	
	createToolButton(new QAction("3",this),SLOT(test(QAction*)));
	createToolButton(new QAction("4",this),SLOT(test(QAction*)));
	createToolButton(new QAction("5",this),SLOT(test(QAction*)));
	createToolButton(new QAction("6",this),SLOT(test(QAction*)));
	createToolButton(new QAction("7",this),SLOT(test(QAction*)));
	
	
	m_ToolZoom = new BB_ToolZoom(m_Center);
}


BB_TabLevel::~BB_TabLevel()
{
}




/*!
    \fn BB_TabLevel::slotLevelNew()
 */
void BB_TabLevel::slotLevelNew()
{
	cout << "Neu!!" << endl;

}


/*!
    \fn BB_TabLevel::slotLevelProperties()
 */
void BB_TabLevel::slotLevelProperties()
{
	cout << "Eigenschaften!!" << endl;
}


/*!
    \fn BB_TabLevel::slotLevelDelete()
 */
void BB_TabLevel::slotLevelDelete()
{
	cout << "Löschen? ... ";
	if(QMessageBox::question(this,"Frage?","sicher?",QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
		cout << "Gelöscht!" << endl;
	else
		cout << "Abgebrochen" << endl;
}


/*!
    \fn BB_TabLevel::test(QAction* action)
 */
void BB_TabLevel::test(QAction* action)
{
	unsetToolButton(action);
}



/**
 * TODO
 */
void BB_TabLevel::slotZoomTool(QAction* action)
{
	unsetToolButton(action);
	action->setChecked(true);
	m_Center->setTool(m_ToolZoom);
	cout << "m_ToolZoom:" << m_ToolZoom << endl;
}
