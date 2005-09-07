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
#include "bb_mainwindow.h"
#include "bb_workframe.h"
#include <iostream>
#include <QScrollArea>


using namespace std;

BB_WorkFrame::BB_WorkFrame(QWidget * parent, Qt::WFlags f)
        :QLabel(parent,f)
{
    m_ZoomFaktor = 1.0;
    m_Tool = NULL;
    m_DrawObjects = NULL;
    m_Transformer.setOffset(QPoint(10, 200));
}


BB_WorkFrame::~BB_WorkFrame()
{}


/*!
    \fn BB_WorkFrame::paintEvent ( QPaintEvent * pe)
 */
void BB_WorkFrame::paintEvent ( QPaintEvent * pe)
{
    QLabel::paintEvent(pe);

    QPainter painter(this);
//     painter.scale(m_ZoomFaktor, m_ZoomFaktor);
//     painter.setPen(QColor("Blue"));
//     painter.drawLine(0,0,100,100);
	

    if(m_DrawObjects != NULL)
    {
        for(int i = 0; i < m_DrawObjects->count(); i++)
        {
			m_DrawObjects->at(i)->show(m_Transformer,painter);
        }
    }
    else
    {
		cout << "m_DrawObjects nicht initialisiert!" << endl;
	}
}


/*!
    \fn BB_WorkFrame::setZoomFaktor(double faktor)
 */
void BB_WorkFrame::setZoomFaktor(double faktor)
{
    m_ZoomFaktor = faktor;
	cout << "Zoom: " << m_ZoomFaktor << endl;
	m_Transformer.setScale(m_ZoomFaktor);
}




/*!
    \fn BB_WorkFrame::getTool()
 */
BB_AbstractTool* BB_WorkFrame::getTool()
{
    return m_Tool;
}


/*!
    \fn BB_WorkFrame::setTool(BB_AbstractTool* tool)
 */
void BB_WorkFrame::setTool(BB_AbstractTool* tool)
{
    if(tool != NULL)
    {
        m_Tool = tool;
    }
    else
    {
        QMessageBox::critical (this, "Fehler (BB_WorkFrame)", "Fehler beim setzten des Tools.\nNULL-Pointer erhalten", QMessageBox::Ok,QMessageBox::NoButton);
    }
}

/*!
    \fn BB_WorkFrame::mousePressEvent ( QMouseEvent * me)
 */
void BB_WorkFrame::mousePressEvent ( QMouseEvent * me)
{
    if(m_Tool != NULL)
    {
		m_Tool->click(me,m_DrawObjects,&m_Transformer);
// 		update();
    }
    else
        cout << "Kein Tool ausgewählt" << endl;
}

/*!
    \fn BB_WorkFrame::mouseReleaseEvent(QMouseEvent* me)
 */
void BB_WorkFrame::mouseReleaseEvent(QMouseEvent* me)
{
    if(m_Tool != NULL)
    {
		m_Tool->release(me,m_DrawObjects,&m_Transformer);
		update();
    }
    else
        cout << "Kein Tool ausgewählt" << endl;
}


/*!
    \fn BB_WorkFrame::mouseMoveEvent(QMouseEvent* me);
 */
void BB_WorkFrame::mouseMoveEvent(QMouseEvent* me)
{
    if(m_Tool != NULL)
    {
        m_Tool->move(me,m_DrawObjects,&m_Transformer);
		update();
    }
    else
        cout << "Kein Tool ausgewählt" << endl;
}


QVector< BB_DrawObject *>* BB_WorkFrame::getDrawObjects() const
{
    return m_DrawObjects;
}


void BB_WorkFrame::setDrawObjects(QVector< BB_DrawObject *>* theValue)
{
    m_DrawObjects = theValue;
}
