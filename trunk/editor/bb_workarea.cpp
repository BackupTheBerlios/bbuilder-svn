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
#include "bb_workarea.h"

#include <iostream>

using namespace std;

BB_WorkArea::BB_WorkArea(QWidget *parent)
 : QScrollArea(parent)
{
	m_ZoomFaktor = 1.0;
	
	m_WorkFrame = new BB_WorkFrame(this);
	m_WorkFrame->setFrameShape(QFrame::Box);
	m_WorkFrame->setFrameShadow(QFrame::Plain);
	
	QImage  *bg = new QImage();
	bg->load("../img/002.bmp");
 	m_WorkFrame->setPixmap(QPixmap(QPixmap::fromImage(*bg)));
	m_WorkFrame->setBackgroundRole(QPalette::Base);
	m_WorkFrame->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	m_WorkFrame->setScaledContents(true);

	setWidget(m_WorkFrame);
}


BB_WorkArea::~BB_WorkArea()
{
}


/*!
    \fn BB_WorkArea::zoom(double faktor)
 */
void BB_WorkArea::zoom(double faktor)
{
	
	Q_ASSERT(m_WorkFrame->pixmap());
	
	m_ZoomFaktor += faktor;
	
	if(m_ZoomFaktor > 2.0)
	{
		m_ZoomFaktor = 2.0;
	}
	else if(m_ZoomFaktor < 0.5)
	{
		m_ZoomFaktor = 0.5;
	}
		
	
	m_WorkFrame->resize(m_ZoomFaktor * m_WorkFrame->pixmap()->size());
	m_WorkFrame->setZoomFaktor(m_ZoomFaktor);
	
	horizontalScrollBar()->setValue(int(faktor * horizontalScrollBar()->value()	+ ((faktor - 1) * horizontalScrollBar()->pageStep()/2)));

	verticalScrollBar()->setValue(int(faktor * verticalScrollBar()->value()	+ ((faktor - 1) * verticalScrollBar()->pageStep()/2)));

}


/**
 * Gibt das Tool zurück, welches im Workframe verwendet wird.
 * @return Das Tool, welches im Workframe benutzt wird.
 */
BB_AbstractTool* BB_WorkArea::getTool()
{
	return m_WorkFrame->getTool();
}


/**
 * Setzt das Tool des Workframes auf <i>tool</i>.
 * @param tool Tool, welches im Workframe benutzt werden soll.
 */
void BB_WorkArea::setTool(BB_AbstractTool* tool)
{
	if(tool != NULL)
		m_WorkFrame->setTool(tool);
	else
		cout << "BB_WorkArea::setTool(): NULL-Pointer erhalten" << endl; 
}


/**
 * Setzt den Zoomfaktor auf <i>zoom</i>
 * @param zoom Zoomfaktor
 */
void BB_WorkArea::setZoomFaktor(double zoom)
{
	m_ZoomFaktor = 1.0;
	this->zoom(zoom);
}


/*!
    \fn BB_WorkArea::getDrawObjects() const
 */
QVector<BB_DrawObject*>* BB_WorkArea::getDrawObjects() const
{
	return m_WorkFrame->getDrawObjects();
}


/*!
    \fn BB_WorkArea::setDrawObjects(QVector<BB_DrawObject>* objectsVector)
 */
void BB_WorkArea::setDrawObjects(QVector<BB_DrawObject*>* objectsVector)
{
	if(objectsVector != NULL)
	{
		m_WorkFrame->setDrawObjects(objectsVector);
		m_WorkFrame->update();
	}
	else
	{
		cout << "BB_WorkArea::setDrawObjects(): NULL-Pointer erhalten" << endl;
	}
}