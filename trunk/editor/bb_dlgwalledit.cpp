/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                      *
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
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "bb_dlgwalledit.h"
#include "bb_level.h"
#include <iostream>
#include <QtGui>

using namespace std;

BB_DlgWallEdit::BB_DlgWallEdit( BB_Wall * wall, BB_DocComponent * docComponent ,double hohe, QWidget * parent, Qt::WFlags f )
        : QDialog( parent, f )
{
    initilize( wall, docComponent, hohe );
}


BB_DlgWallEdit::~BB_DlgWallEdit()
{
    delete m_CentralWidget;
    delete m_PreviewWidget;
    delete m_ToolDoorNew;
    delete m_ToolWindowNew;
    delete m_ToolMove;
	delete m_ToolTexture;
	delete m_ToolDelete;
    // 	QScrollArea * scroll = new QScrollArea();
    // 	QVBoxLayout *layout_area_preview = new QVBoxLayout;
    // 	QVBoxLayout * layout_buttons = new QVBoxLayout;
    delete m_ButtonWindow;
    delete m_ButtonDoor;
    delete m_ButtonMove;
	delete m_ButtonTexture;
	delete m_ButtonDelete;
	delete m_Buttons;
}

void BB_DlgWallEdit::initilize( BB_Wall * wall, BB_DocComponent * docComponent ,double hohe )
{
    //eigenschaften von Widget bearbeiten
    setWindowTitle ( tr( "Eigenschaften von einer Wand" ) );

    //member-variablen zuweisen
    m_level = docComponent;
    m_wall = wall;
    m_CentralWidget = new BB_DlgWallEditArea( wall, docComponent, hohe );
    m_PreviewWidget = new BB_DlgWallEditPreview( wall, docComponent );

    //tols initialisieren
	m_ToolDoorNew = new BB_ToolDoorNew(this);
    m_ToolDoorNew->setObjects( wall->getObjects() );

	m_ToolWindowNew = new BB_ToolWindowNew(this);
    m_ToolWindowNew->setObjects( wall->getObjects() );

	m_ToolMove = new BB_ToolMove(this);

	m_ToolTexture = new BB_ToolTexture(this);
	m_ToolTexture->setObjects( wall->getObjects());

	m_ToolDelete = new BB_ToolDelete(this);
	m_ToolDelete->setObjects( wall->getObjects());

    //Scroll-Fenster mit haupt-Widget
    QScrollArea * scroll = new QScrollArea();
    scroll->setWidget( m_CentralWidget );
    //Layout fuer Area und Preview - Widget
    QVBoxLayout *layout_area_preview = new QVBoxLayout;
    layout_area_preview->addWidget( scroll );
    layout_area_preview->addWidget( m_PreviewWidget );

    //Layout fuer Buttons
    QVBoxLayout * layout_buttons = new QVBoxLayout;
	m_Buttons = new QVector<QToolButton *>;
	
    m_ButtonWindow = new QToolButton();
    m_ButtonWindow->setText( "Fenster" );
	m_ButtonWindow->setCheckable(true);
	m_ButtonWindow->setIcon(m_ToolWindowNew->getIcon());
	m_Buttons->append(m_ButtonWindow);
	
    m_ButtonDoor = new QToolButton();
    m_ButtonDoor->setText( QString::fromUtf8( "Tür" ) );
	m_ButtonDoor->setCheckable(true);
	m_ButtonDoor->setIcon(m_ToolDoorNew->getIcon());
	m_Buttons->append(m_ButtonDoor);
	
    m_ButtonMove = new QToolButton();
    m_ButtonMove->setText( "Move" );
	m_ButtonMove->setCheckable(true);
	m_ButtonMove->setIcon(m_ToolMove->getIcon());
	m_Buttons->append(m_ButtonMove);
	
	m_ButtonTexture = new QToolButton();
	m_ButtonTexture->setText("Texture");
	m_ButtonTexture->setCheckable(true);
	m_ButtonTexture->setIcon(m_ToolTexture->getIcon());
	m_Buttons->append(m_ButtonTexture);

	m_ButtonDelete = new QToolButton();
	m_ButtonDelete->setText("delete");
	m_ButtonDelete->setCheckable(true);
	m_ButtonDelete->setIcon(m_ToolDelete->getIcon());
	m_Buttons->append(m_ButtonDelete);

    //buttons hinzufuegen
    layout_buttons->addWidget( m_ButtonWindow );
    layout_buttons->addWidget( m_ButtonDoor );
    layout_buttons->addWidget( m_ButtonMove );
	layout_buttons->addWidget(m_ButtonTexture);
	layout_buttons->addWidget(m_ButtonDelete);

    //layout mit allen anderen Layouts
    QHBoxLayout * layout_alles_zusammen = new QHBoxLayout;
    layout_alles_zusammen->addLayout( layout_buttons );
    layout_alles_zusammen->addLayout( layout_area_preview );

    //Haupt_layout zum Widget hinzufuegen
    setLayout( layout_alles_zusammen );
    // 	setFixedHeight(500);

    initSingals();
}

void BB_DlgWallEdit::paintEvent ( QPaintEvent * pe )
{
    m_CentralWidget->repaint();
}
void BB_DlgWallEdit::resizeEvent ( QResizeEvent * re )
{
    m_CentralWidget->update();
}



BB_DocComponent* BB_DlgWallEdit::getLevel() const
{
    return m_level;
}


void BB_DlgWallEdit::setLevel( BB_DocComponent* Value )
{
    m_level = Value;
}


BB_Wall* BB_DlgWallEdit::getWall() const
{
    return m_wall;
}


void BB_DlgWallEdit::setWall( BB_Wall* Value )
{
    m_wall = Value;
}


void BB_DlgWallEdit::slotToolDoor()
{
    m_CentralWidget->setTool( m_ToolDoorNew );
	unsetButton( m_ButtonDoor);
}

void BB_DlgWallEdit::slotToolWindow()
{
    m_CentralWidget->setTool( m_ToolWindowNew );
	unsetButton( m_ButtonWindow);
}

void BB_DlgWallEdit::slotToolMove()
{
    m_CentralWidget->setTool( m_ToolMove );
	unsetButton( m_ButtonMove);
}

void BB_DlgWallEdit::slotToolTexture()
{
	m_CentralWidget->setTool( m_ToolTexture );
	unsetButton( m_ButtonTexture);
}

void BB_DlgWallEdit::slotToolDelete()
{
	m_CentralWidget->setTool( m_ToolDelete );
	unsetButton( m_ButtonDelete);
}


void BB_DlgWallEdit::initSingals()
{
    connect( m_ButtonDoor, SIGNAL( clicked( bool ) ), this, SLOT( slotToolDoor() ) );
    connect( m_ButtonWindow, SIGNAL( clicked( bool ) ), this, SLOT( slotToolWindow() ) );
    connect( m_ButtonMove, SIGNAL( clicked( bool ) ), this, SLOT( slotToolMove() ) );
	connect( m_ButtonTexture, SIGNAL(clicked(bool)), this, SLOT(slotToolTexture()));
	connect( m_ButtonDelete, SIGNAL(clicked(bool)), this, SLOT(slotToolDelete()));
}


/*!
    \fn BB_DlgWallEdit::usetButton(QToolButton * button)
 */
void BB_DlgWallEdit::unsetButton(QToolButton * button)
{
	for (int i=0; i< m_Buttons->count();i++){
		if (m_Buttons->at(i) != button)
			m_Buttons->at(i)->setChecked(false);
	}
}

void BB_DlgWallEdit::openTextureDlg(){
	m_wall->openTextureDlg();
	m_CentralWidget->loadTexture();
}
