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
#include "bb_workarea.h"

#include <iostream>
#include <iomanip>

using namespace std;

/**
@author Alex Letkemann
*/
class BB_Tab : public QWidget
{
Q_OBJECT
public:
	BB_Tab(QWidget* parent = 0, Qt::WFlags f = 0);
    BB_Tab(bool leftFrame, bool rightFrame, QWidget* parent = 0, Qt::WFlags f = 0);

    ~BB_Tab();
    void initTab();
    void unsetToolButton(QAction *action);
	
	
private:	
	void initLayout(bool leftFrame, bool rightFrame);
	
	
protected:	
    bool addWidgetLeft(QWidget *widget, int stretchFaktor = 0);
	bool addWidgetRight(QWidget *widget, int stretchFaktor = 0);

	BB_WorkArea *m_Center;
	QFrame *m_LeftFrame;
    QFrame *m_RightFrame;
    QGridLayout* m_ToolsGridLayout;
    int m_ToolButtonCount;
    QList<QAction*> *m_ToolButtonActions;
	
	virtual bool createToolButton(QAction *action, const char* method);
	
};

#endif
