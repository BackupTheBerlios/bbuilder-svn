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
#include "bb_globals.h"

#include "bb_tabbuilding.h"

#include <iostream>

#include "bb_point.h"

using namespace std;

BB_TabBuilding::BB_TabBuilding(BB_Doc * doc, QWidget* parent, Qt::WFlags f)
        : BB_Tab(doc, true, true, parent, f)
{

    if(m_Doc->getBuildings() != NULL)
        m_Buildings = m_Doc->getBuildings();
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

    m_ButtonBuildingProperties = new QPushButton(QString::fromUtf8("Speichern"));
    // 	m_ButtonLevelProperties->setEnabled(false);

    connect(m_ButtonBuildingNew,SIGNAL(clicked(bool)),this,SLOT(slotBuildingNew()));
    connect(m_ButtonBuildingDelete,SIGNAL(clicked(bool)),this,SLOT(slotBuildingDelete()));
    connect(m_ButtonBuildingProperties,SIGNAL(clicked(bool)),this,SLOT(slotBuildingProperties()));

    gBL_Buildings->addWidget(m_ButtonBuildingNew,Qt::AlignTop);
    gBL_Buildings->addWidget(m_ButtonBuildingDelete,Qt::AlignTop);
    gBL_Buildings->addWidget(m_ButtonBuildingProperties,Qt::AlignTop);


    gB_Buildings->setLayout(gBL_Buildings);

    addWidgetLeft(gB_Buildings,1);

    QAction *toolSelect = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolSelect.png"), "Auswahl",this);
    toolSelect->setStatusTip("Auswahl Werkzeug");
    createToolButton(toolSelect,SLOT(slotToolSelect(QAction*)));

    QIcon zoom(IMG_DIR() + SEPARATOR() + "toolZoom.png");
    QAction *toolZoom = new QAction(zoom,"Zoom",this);
    toolZoom->setStatusTip("Zoom Werkzeug");
    createToolButton(toolZoom,SLOT(slotZoomTool(QAction*)));

    QIcon knote(IMG_DIR() + SEPARATOR() + "toolPoint.png");
    // 	QAction *toolPointNew = new QAction("Point",this);
    QAction *toolPointNew = new QAction(knote,"Point",this);
    toolPointNew->setStatusTip("Point Werkzeug");
    createToolButton(toolPointNew,SLOT(slotToolPointNew(QAction*)));

    QAction *toolLineNew = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolWall.png"),"Wand",this);
    toolPointNew->setStatusTip("Line Werkzeug");
    createToolButton(toolLineNew,SLOT(slotToolLineNew(QAction*)));

    QAction *toolMove = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolMove.png"), "Move",this);
    toolMove->setStatusTip("Move Werkzeug");
    createToolButton(toolMove,SLOT(slotToolMove(QAction*)));


    m_ToolZoom = new BB_ToolZoom(m_Center);
    m_ToolPointNew = new BB_ToolPointNew();
    m_ToolMove = new BB_ToolMove();
    m_ToolLineNew = new BB_ToolLineNew(m_Center);
    m_ToolSelect = new BB_ToolSelect();

    updateBuildingList();


    /*****************/

    // 	QTableView *view = new QTableView();
    /*
     
    	
    	view->verticalHeader()->setVisible(false);
    			
    	
    	QStandardItemModel *model = new QStandardItemModel(7,2);
    // 	model->
    	model->setHeaderData(0, Qt::Horizontal, tr("Attribut"));
    	model->setHeaderData(1, Qt::Horizontal, tr("Wert"));
    	
    	QModelIndex index = model->index(0, 0);
    	model->setData(index, QVariant("Name"));
    	index = model->index(0, 1);
    	model->setData(index, QVariant("Object_x"));
    	
    //	view->horizontalHeader()->setResizeMode(0, QHeaderView::Interactive);
    //	view->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
     
    	
    	view->horizontalHeader()->setClickable(false);
    	view->horizontalHeader()->setSortIndicatorShown(false);
    	view->horizontalHeader()->setHighlightSections (false);	
    	
    	view->setModel(NULL);
    */

    m_PropertyWidget = new BB_PropertyWidget();

    addWidgetRight(m_PropertyWidget);

    /*****************/

    slotToolSelect(toolSelect);

}


BB_TabBuilding::~BB_TabBuilding()
{}



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

    BB_Building *building;
    int row = m_BuildingsListWidget->currentRow();
    if(row != -1)
    {
        building = m_Buildings->at(row);
        if( QMessageBox::question(this,
                                  QString::fromUtf8("Bestätigung"),
                                  QString::fromUtf8("Möchten Sie das Gebäude ")
                                  + building->getName()
                                  + QString::fromUtf8(" wirklich löschen?"),
                                  QMessageBox::Yes,
                                  QMessageBox::No) == QMessageBox::Yes)
        {
            m_BuildingsListWidget->takeItem(row);

            building = m_Buildings->at(row);
            m_Buildings->remove
            (row);
            building->remove
            ();
            delete building;
            building = NULL;

            m_Doc->save();

            updateBuildingList();
            unsetDrawObjects();
            m_Center->setEnabled(false);

            m_BuildingsListWidget->setCurrentRow(row - 1);
            slotBuildingChanged(row - 1);

        }
    }
}


/**
 *
 */
void BB_TabBuilding::slotBuildingNew()
{

    // 	BB_Building* building = new BB_Building();
    // 	if(building->keyBoardEdit(this) == QDialog::Accepted)
    // 	{
    // 		m_BuildingsListWidget->addItem(building->getName());
    //
    // 		cout << "Gebäude hinzugefügt (" << building << ")" << endl;
    //
    // 		m_Buildings->append(building);
    // 	}
    // 	else
    // 	{
    // 		delete building;
    // 		building = NULL;
    // 		cout << "Gelöscht" << endl;
    // 	}
    //
    // 	m_BuildingsListWidget->setCurrentRow (m_Buildings->count()-1);
    //
    //
    // 	updateBuildingList();


    if(m_Doc->newBuilding(this) != NULL)
    {
        m_BuildingsListWidget->setCurrentRow (m_BuildingsListWidget->count()-1);
        updateBuildingList();
    }


    cout << "BuildingNew" << endl;
}


/**
 * Startet einen Dialog zum Bearbeiten der Eigenschaften eines Gebäudes
 */
void BB_TabBuilding::slotBuildingProperties()
{
    int row = m_BuildingsListWidget->currentRow();
    if(row >= 0)
    {
        // 		m_Buildings->at(row)->keyBoardEdit(this);
        m_Buildings->at(row)->save();

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
        m_Center->setEnabled(false);
    }
    else if(m_Buildings->count() >= 0)
    {
        m_ButtonBuildingDelete->setEnabled(true);
        m_ButtonBuildingProperties->setEnabled(true);
        m_Center->setEnabled(true);
    }
}


/*!
    \fn BB_TabBuilding::slotBuildingChanged(int index)
 */
void BB_TabBuilding::slotBuildingChanged(int index)
{
    cout << "slotBuildingChanged(" << index << ")" << endl;

    if(index >= 0)
    {
        m_Center->setDrawObjects(m_Buildings->at(index)->getDrawObjects());
        m_Center->setEnabled(true);
        m_Center->setMap(m_Buildings->at(index));
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


/*!
    \fn BB_TabBuilding::void slotToolLineNew(QAction* action)
 */
void BB_TabBuilding::slotToolLineNew(QAction* action)
{
    unsetToolButton(action);
    action->setChecked(true);
    m_Center->setTool(m_ToolLineNew);
    cout << "m_ToolLineNew:" << m_ToolLineNew << endl;
}


/*!
    \fn BB_TabBuilding::mousePressEvent ( QMouseEvent * e )
 */
void BB_TabBuilding::mousePressEvent ( QMouseEvent * e )
{
    // TODO
    e->ignore();

    cout << "BB_Tab::mousePressEvent(e);" << endl;
}


/*!
    \fn BB_TabBuilding::slotToolSelect(QAction* action)
 */
void BB_TabBuilding::slotToolSelect(QAction* action)
{
    unsetToolButton(action);
    action->setChecked(true);
    m_Center->setTool(m_ToolSelect);
    cout << "m_ToolSelect" << m_ToolSelect << endl;
}


/*!
    \fn BB_TabBuilding::updateWidget()
 */
void BB_TabBuilding::updateWidget()
{
    updateBuildingList();
}
