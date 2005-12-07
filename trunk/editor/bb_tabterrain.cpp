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
#include "bb_tabterrain.h"

#include "bb_globals.h"
#include "bb_toolselect.h"
#include "bb_toolzoom.h"
#include "bb_toolmove.h"
#include "bb_toolpointnew.h"
#include "bb_tooltrianglenew.h"

#include <QtGui>


BB_TabTerrain::BB_TabTerrain(BB_Doc* doc, QWidget* parent, Qt::WFlags f)
	: BB_Tab(doc, true, false, parent, f)
{
	
	if(m_Doc!= NULL && m_Doc->getTerrain() != NULL)
	{
		m_Terrain = m_Doc->getTerrain();
		m_Center->setDrawDevice(m_Terrain);
		m_Center->setMap(m_Terrain);
	}
	
	initTools();
	
	/***** <Debug> *****/
	
	QGroupBox* box = new QGroupBox();
	box->setFlat(true);
	box->setTitle("Optionen");

	QPushButton * button = new QPushButton("Eigenschaften");
	
	QVBoxLayout * layout = new QVBoxLayout();
	layout->addWidget(button);
	box->setLayout(layout);
	
	addWidgetLeft(box,1);
	
	connect(button,SIGNAL(clicked(bool)),this,SLOT(slotTerrainEdit()));
	
	/***** </Debug> *****/
	
}


BB_TabTerrain::~BB_TabTerrain()
{
}



/**
 * Initialisiert alle Tools
 */
void BB_TabTerrain::initTools()
{
/* Tool zum Selektieren */
	m_ToolSelect = new BB_ToolSelect();
	QAction *toolSelect = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolSelect.png"), "Auswahl",this);
	toolSelect->setStatusTip("Auswahl Werkzeug");
	createToolButton(toolSelect,m_ToolSelect);
	

/* Zoomtool */
	m_ToolZoom = new BB_ToolZoom(m_Center);
	QIcon zoom(IMG_DIR() + SEPARATOR() + "toolZoom.png");
	QAction *toolZoom = new QAction(zoom,"Zoom",this);
	toolZoom->setStatusTip("Zoom Werkzeug");
	createToolButton(toolZoom,m_ToolZoom);
	

/* Tool zum Erstellen neuer Knoten */
	m_ToolPointNew = new BB_ToolPointNew();
	QIcon knote(IMG_DIR() + SEPARATOR() + "toolPoint.png");
    // 	QAction *toolPointNew = new QAction("Point",this);
	QAction *toolPointNew = new QAction(knote,"Point",this);
	toolPointNew->setStatusTip("Point Werkzeug");
	createToolButton(toolPointNew,m_ToolPointNew);
	

// /* Tool zum Erstellen neuer Linien */
// 	m_ToolLineNew = new BB_ToolLineNew(m_Center);
// 	QAction *toolLineNew = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolWall.png"),"Wand",this);
// 	toolPointNew->setStatusTip("Line Werkzeug");
// 	createToolButton(toolLineNew,m_ToolLineNew);
	
	/* Tool zum Erstellen neuer Linien */
	m_ToolTriangleNew = new BB_ToolTriangleNew();
	QAction *toolTriangleNew = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolTerrain.png"),QString::fromUtf8("Fläche"),this);
	toolTriangleNew->setStatusTip("Terrain Werkzeug");
	createToolButton(toolTriangleNew,m_ToolTriangleNew);

/* Tool zum Bewegen der Objekte */
	m_ToolMove = new BB_ToolMove();
	QAction *toolMove = new QAction(QIcon(IMG_DIR() + SEPARATOR() + "toolMove.png"), "Move",this);
	toolMove->setStatusTip("Move Werkzeug");
	createToolButton(toolMove,m_ToolMove);
	

	
	/* Das Selektionstool alst Standard wählen */
	toolChanged(toolSelect);
}

/**
 * Verarbeitet die Tools von BB_TabTerrain und übergibt diese weiter an die Arbeitfläche.
 * @param action Aktion des Tools, welches Betätigt wurde.
 */
void BB_TabTerrain::toolChanged(QAction* action)
{
	
	if(m_ToolSelect->getAction() == action)
	{
		unsetToolButton(action);
		action->setChecked(true);
		m_Center->setTool(m_ToolSelect);
	}
	else if(m_ToolMove->getAction() == action)
	{
		unsetToolButton(action);
		action->setChecked(true);
		m_Center->setTool(m_ToolMove);
	}
	else if(m_ToolZoom->getAction() == action)
	{
		unsetToolButton(action);
		action->setChecked(true);
		m_Center->setTool(m_ToolZoom);
	}
	else if(m_ToolPointNew->getAction() == action)
	{
		unsetToolButton(action);
		action->setChecked(true);
		m_Center->setTool(m_ToolPointNew);
	}
	else if(m_ToolTriangleNew->getAction() == action)
	{
		unsetToolButton(action);
		action->setChecked(true);
		m_Center->setTool(m_ToolTriangleNew);
	}
	else
	{
		cout << "Unbekanntes Tool" << endl;
	}
}


/**
 * Editiert das Gelände
 */
void BB_TabTerrain::slotTerrainEdit()
{
	m_Terrain = m_Doc->getTerrain();
	
	if(m_Terrain != NULL)
	{
		m_Terrain->keyBoardEdit(this);
		m_Center->setMap(m_Terrain);
		m_Center->setDrawDevice(m_Terrain);
	}
}


/**
 * Speichert das Gelände
 */
bool BB_TabTerrain::saveCurrent()
{
	m_Terrain = m_Doc->getTerrain();
	
	if(m_Terrain != NULL)
	{
		return m_Terrain->save();
	}
	
	return false;
}


/**
 *
 */
void BB_TabTerrain::updateWidget()
{
	m_Terrain = m_Doc->getTerrain();
	
	if(m_Terrain != NULL)
	{
		m_Center->setMap(m_Terrain);
		m_Center->setDrawDevice(m_Terrain);
	}
	else
	{
		m_Center->setMap(NULL);
		m_Center->setDrawDevice(NULL);
	}
		
}
