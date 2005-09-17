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
#include "bb_tab.h"

#include <QHBoxLayout>


BB_Tab::BB_Tab(QWidget* parent, Qt::WFlags f): QWidget(parent, f)
{
	initTab();
    initLayout(true, true);
	
	
}

BB_Tab::BB_Tab(bool leftFrame, bool rightFrame,QWidget* parent, Qt::WFlags f): QWidget(parent, f)
{
	initTab();
    initLayout(leftFrame, rightFrame);
}


BB_Tab::~BB_Tab()
{
	delete m_ToolButtonActions;
	delete m_Center;
	if(m_LeftFrame != NULL)
		delete m_LeftFrame;
	if(m_RightFrame != NULL)
		delete m_RightFrame;
	
// TODO m_ToolsGridLayout lässt sich nicht löschen
// 	if(m_ToolsGridLayout != NULL)
// 		delete m_ToolsGridLayout;
}

/**
 * Initialisiert alle wichtigen Einstellungen des Tabs.
 * Muss als Erstes in jedem Konstrucktor aufgeruffen werden.
 */
void BB_Tab::initTab()
{
	m_ToolButtonCount = 0;
	m_ToolButtonActions = new QList<QAction*>();
	
	m_ToolsGridLayout = NULL;
	m_LeftFrame = NULL;
	m_RightFrame = NULL;
}



/**
 * Erzeugt das Layout für das Tab-Fenster
 */
void BB_Tab::initLayout(bool leftFrame, bool rightFrame)
{
    int iFrames = 0;

    QSplitter *splitter = new QSplitter(this);
    if(leftFrame)
    {
        m_LeftFrame = new QFrame();
        m_LeftFrame->setFrameShape(QFrame::Box);
        m_LeftFrame->setFrameShadow(QFrame::Sunken);
		
		m_LeftFrame->setFixedWidth(160);

        QVBoxLayout *leftLayout = new QVBoxLayout();
        leftLayout->setMargin(0);
        leftLayout->setSpacing(5);

        /* GroupBox für die ToolButtons */
        QGroupBox *groupBox = new QGroupBox(NULL);
        groupBox->setObjectName(QString::fromUtf8("leftFrameTools"));
        groupBox->setFlat(true);
        groupBox->setTitle(QString::fromUtf8("Tools"));

        m_ToolsGridLayout = new QGridLayout();
        m_ToolsGridLayout->setMargin(2);

        groupBox->setLayout(m_ToolsGridLayout);


        leftLayout->addWidget(groupBox);
        leftLayout->setStretchFactor(groupBox,0);

        m_LeftFrame->setLayout(leftLayout);

        splitter->addWidget(m_LeftFrame);
        splitter->setCollapsible(iFrames,true);
        splitter->setStretchFactor(iFrames, 0);
        iFrames++;

        m_LeftFrame->setGeometry(
            m_LeftFrame->x(),
            m_LeftFrame->y(),
            160,
            m_LeftFrame->height());
    }
    else
        m_LeftFrame = NULL;

    m_Center = new BB_WorkArea();
    m_Center->setFrameShape(QFrame::Box);
    m_Center->setFrameShadow(QFrame::Sunken);

    splitter->addWidget(m_Center);
    splitter->setCollapsible(iFrames,false);
    splitter->setStretchFactor(iFrames, 1);

    iFrames++;

    if(rightFrame)
    {
        m_RightFrame = new QFrame();
        m_RightFrame->setFrameShape(QFrame::Box);
        m_RightFrame->setFrameShadow(QFrame::Sunken);
        m_RightFrame->setMinimumSize(160, 400);
        m_RightFrame->setMaximumSize(400,10000);

        splitter->addWidget(m_RightFrame);
        splitter->setCollapsible(iFrames,true);
        splitter->setStretchFactor(iFrames, 0);
        iFrames++;

        m_RightFrame->setGeometry(
            m_RightFrame->x(),
            m_RightFrame->y(),
            200,
            m_RightFrame->height());
    }
    else
        m_RightFrame = NULL;

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(splitter);
    setLayout(layout);
}



/**
 * Erzeugt einen QToolButton und plaziert diesen im linken Frame.
 * Der QToolButton übernimmt die Eigenschaften wie Text, Icon usw. von action und wird 'connected' zu method.
 * @param action Die QAction, aus der der QToolButton erzeugt werden soll.
 * @param method Slot, an der die QAction 'connected' werden soll.<BR>Achtung: Slot muss mit dem Qt-Makro SLOT() erzeugt werden.
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 21.08.2005
 */
bool BB_Tab::createToolButton(QAction *action, const char* method)
{
    if(action != NULL)
    {
		action->setCheckable(true);
		m_ToolButtonActions->append(action);
		
        QToolButton *button = new QToolButton();
		button->setToolButtonStyle(Qt::ToolButtonIconOnly);
		button->setFixedSize(24,24);
        button->setDefaultAction(action);

        m_ToolsGridLayout->addWidget(button,m_ToolButtonCount / 5,m_ToolButtonCount % 5);
        m_ToolButtonCount++;
        return connect(button,SIGNAL(triggered(QAction*)),this,method);
    }
    else
        return false;
}


/**
 * Hängt ein QWidget im linken Frame an
 * @param widget Das QWidget, dass angehängt werden soll
 * @param stretchFaktor Gibt an, ob und wie stark sich das Widget streckt wenn die Größe des Fensters verändert wird. Default ist 0
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 18.08.2005
 */
bool BB_Tab::addWidgetLeft(QWidget *widget, int stretchFaktor)
{
    if(widget != NULL && m_LeftFrame != NULL)
    {
		widget->setFixedWidth(156);
        m_LeftFrame->layout()->addWidget(widget);
        ((QVBoxLayout*)m_LeftFrame->layout())->setStretchFactor(widget,stretchFaktor);
        return true;
    }
    return false;
}

/**
 * Hängt ein QWidget im rechten Frame an
 * @param widget Das QWidget, das im rechten Frame angehängt werden soll
 * @param stretchFaktor Gibt an, ob und wie stark sich das Widget streckt wenn die Größe des Fensters verändert wird. Default ist 0
 * @return Gibt false im Fehlerfall zurück, sonst true
 * @author Alex Letkemann
 * @date 18.08.2005
 */
bool BB_Tab::addWidgetRight(QWidget *widget, int stretchFaktor)
{
    if(widget != NULL && m_RightFrame != NULL)
    {
        m_RightFrame->layout()->addWidget(widget);
        ((QVBoxLayout*)m_RightFrame->layout())->setStretchFactor(widget,stretchFaktor);
        return true;
    }
    return false;
}


/**
 * Setzt alle Actions der Toolbuttons außer <i>action</i> auf unchecked.
 * @param action Aktion, welche nicht auf unchecked gesetzt werden soll. 
 */
void BB_Tab::unsetToolButton(QAction *action)
{
	for(int i = 0; i < m_ToolButtonActions->count(); i++)
	{
		if(m_ToolButtonActions->at(i) != action)
			((QAction*)m_ToolButtonActions->at(i))->setChecked(false);
	}
}
