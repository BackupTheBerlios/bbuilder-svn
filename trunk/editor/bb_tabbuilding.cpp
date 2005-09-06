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
#include "bb_tabbuilding.h"

#include <iostream>

#include "bb_point.h"

using namespace std;

BB_TabBuilding::BB_TabBuilding(QVector<BB_Building*>* buildings, QWidget* parent, Qt::WFlags f)
	: BB_Tab(true, true, parent, f)
{

	if(buildings != NULL)
		m_Buildings = buildings;
	else
	{
		cout << "BB_TabBuilding::BB_TabBuilding(): Ungültiger Vector (NULL)" << endl;
	}
	
	QGroupBox *gB_Buildings = new QGroupBox();
	gB_Buildings->setTitle(QString::fromUtf8("Gebäude"));
	gB_Buildings->setFlat(true);
		
	m_BuildingsListWidget = new QListWidget();
	connect(m_BuildingsListWidget,SIGNAL(currentRowChanged (int)),this,SLOT(slotBuildingChanged(int)));
	
	QVBoxLayout *gBL_Buildings = new QVBoxLayout();
	gBL_Buildings->setMargin(0);
	gBL_Buildings->setSpacing(2);
	gBL_Buildings->addWidget(m_BuildingsListWidget,Qt::AlignTop);
	
	m_ButtonBuildingNew = new QPushButton(QString::fromUtf8("Hinzufügen"));
	
	m_ButtonBuildingDelete = new QPushButton(QString::fromUtf8("Löschen"));
// 	m_ButtonLevelDelete->setEnabled(false);
	
	m_ButtonBuildingProperties = new QPushButton(QString::fromUtf8("Eigenschaften"));
// 	m_ButtonLevelProperties->setEnabled(false);
	
	connect(m_ButtonBuildingNew,SIGNAL(clicked(bool)),this,SLOT(slotBuildingNew()));
	connect(m_ButtonBuildingDelete,SIGNAL(clicked(bool)),this,SLOT(slotBuildingDelete()));
	connect(m_ButtonBuildingProperties,SIGNAL(clicked(bool)),this,SLOT(slotBuildingProperties()));
	
	gBL_Buildings->addWidget(m_ButtonBuildingNew,Qt::AlignTop);
	gBL_Buildings->addWidget(m_ButtonBuildingDelete,Qt::AlignTop);
	gBL_Buildings->addWidget(m_ButtonBuildingProperties,Qt::AlignTop);
	
	
	gB_Buildings->setLayout(gBL_Buildings);
	
	addWidgetLeft(gB_Buildings,1);
	
	QIcon zoom("../img/toolZoom.png");
	QAction *toolZoom = new QAction(zoom,"Zoom",this);
	toolZoom->setStatusTip("Zoom Werkzeug");
	createToolButton(toolZoom,SLOT(slotZoomTool(QAction*)));
	
	QAction *toolPointNew = new QAction("Point",this);
	toolPointNew->setStatusTip("Point Werkzeug");
	createToolButton(toolPointNew,SLOT(slotToolPointNew(QAction*)));
	
	QAction *toolMove = new QAction("Move",this);
	toolMove->setStatusTip("Move Werkzeug");
	createToolButton(toolMove,SLOT(slotToolMove(QAction*)));
	
	cout << "initialisiere Tools" << endl;
	
	m_ToolZoom = new BB_ToolZoom(m_Center);
	m_ToolPointNew = new BB_ToolPointNew();
	m_ToolMove = new BB_ToolMove();
	
	updateBuildingList();
	
}


BB_TabBuilding::~BB_TabBuilding()
{
}



/*!
    \fn BB_TabBuilding::slotZoomTool(QAction* action)
 */
void BB_TabBuilding::slotZoomTool(QAction* action)
{
	unsetToolButton(action);
	action->setChecked(true);
	m_Center->setTool(m_ToolZoom);
	cout << "m_ToolZoom:" << m_ToolZoom << endl;
}


/*!
    \fn BB_TabBuilding::slotBuildingDelete()
 */
void BB_TabBuilding::slotBuildingDelete()
{
	cout << m_BuildingsListWidget->currentRow() << endl;
	
	BB_Building *building;
	int row = m_BuildingsListWidget->currentRow();
		
	if(row != -1)
	{
		m_BuildingsListWidget->takeItem(row);	
		
		building = m_Buildings->at(row);
		m_Buildings->remove(row);
		delete building;
	}
	
	updateBuildingList();
}


/**
 *
 */
void BB_TabBuilding::slotBuildingNew()
{

	BB_Building* building = new BB_Building();
	if(building->keyBoardEdit(this) == QDialog::Accepted)
	{
		m_BuildingsListWidget->addItem(building->getName());
		
		cout << "Gebäude hinzugefügt (" << building << ")" << endl;
		
		m_Buildings->append(building);
	}
	else
	{
		delete building;
		cout << "Gelöscht" << endl;
	}
	
	updateBuildingList();
}


/**
 * Startet einen Dialog zum Bearbeiten der Eigenschaften eines Gebäudes
 */
void BB_TabBuilding::slotBuildingProperties()
{
	int row = m_BuildingsListWidget->currentRow();
	if(row >= 0)
	{
		m_Buildings->at(row)->keyBoardEdit(this);
	}
	
	updateBuildingList();
}


/**
 * Aktualisiert die Gebäudeliste und die Buttons
 */
void BB_TabBuilding::updateBuildingList()
{
	m_BuildingsListWidget->clear();
	
	for(int i = 0; i < m_Buildings->count(); i++)
	{
		m_BuildingsListWidget->addItem(m_Buildings->at(i)->getName());
	}
	
	if(m_Buildings->count() == 0)
	{
		m_ButtonBuildingDelete->setEnabled(false);
		m_ButtonBuildingProperties->setEnabled(false);
	}
	else if(m_Buildings->count() >= 0)
	{
		m_ButtonBuildingDelete->setEnabled(true);
		m_ButtonBuildingProperties->setEnabled(true);
	}
}


/*!
    \fn BB_TabBuilding::slotBuildingChanged(int index)
 */
void BB_TabBuilding::slotBuildingChanged(int index)
{
	cout << index << endl;
	
	if(index >= 0)
	{
		m_Center->setDrawObjects(m_Buildings->at(index)->getDrawObjects());
	}
}


/*!
    \fn BB_TabBuilding::slotToolPointNew(QAction* action)
 */
void BB_TabBuilding::slotToolPointNew(QAction* action)
{
	unsetToolButton(action);
	action->setChecked(true);
	m_Center->setTool(m_ToolPointNew);
	cout << "m_ToolPointNew:" << m_ToolPointNew << endl;
}


/*!
    \fn BB_TabBuilding::slotToolMove(QAction* action)
 */
void BB_TabBuilding::slotToolMove(QAction* action)
{
	unsetToolButton(action);
	action->setChecked(true);
	m_Center->setTool(m_ToolMove);
	cout << "m_ToolMove:" << m_ToolMove << endl;
}