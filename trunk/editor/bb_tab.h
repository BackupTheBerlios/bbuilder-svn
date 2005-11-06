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
 *                                                                         *
 ***************************************************************************/
#ifndef BB_TAB_H
#define BB_TAB_H

#include <QtGui>
#include <iostream>

#include "bb_doc.h"
#include "bb_abstracttool.h"

class BB_WorkArea;

using namespace std;

/**
@author Alex Letkemann
*/
class BB_Tab : public QWidget
{
Q_OBJECT
public:
	BB_Tab(BB_Doc* doc, QWidget* parent = 0, Qt::WFlags f = 0);
	BB_Tab(BB_Doc* doc, bool leftFrame, bool rightFrame, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_Tab();
    void initTab();
    void unsetToolButton(QAction *action);
	void unsetDrawObjects();
	
	virtual void updateWidget();	
	virtual void clear();
	
private:	
	void initLayout(bool leftFrame, bool rightFrame);
    void setDoc(BB_Doc* doc);
	
	
protected:	
    bool addWidgetLeft(QWidget *widget, int stretchFaktor = 0);
	bool addWidgetRight(QWidget *widget, int stretchFaktor = 0);
	
	BB_Doc * m_Doc;
	QVector<BB_DrawObject*>* m_DrawObjects;
	QVector<BB_DrawObject*>  m_Selection;
	
	
	BB_WorkArea *m_Center;
	QFrame *m_LeftFrame;
    QFrame *m_RightFrame;
    QGridLayout* m_ToolsGridLayout;
    int m_ToolButtonCount;
    QList<QAction*> *m_ToolButtonActions;
	
	virtual bool createToolButton(QAction *action, BB_AbstractTool* tool);
    virtual void toolChanged(QAction* action);
    
	

private slots:
    void slotToolChanged(QAction* action);
};

#endif
