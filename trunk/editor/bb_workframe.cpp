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

#include <bb_triangle.h>

using namespace std;

///@todo alle m_DrawObjects gegen m_DocComponent->getDrawObjects() tauschen

BB_WorkFrame::BB_WorkFrame(QVector<BB_DrawObject*>* selectVector, QWidget * parent, Qt::WFlags f)
        :QLabel(parent,f)
{
	
	if(selectVector != NULL)
	{
		m_Selection = selectVector;
	}
// 	exit(0);
	
	m_Component = NULL;
    m_Tool = NULL;
    m_DrawObjects = NULL;
//     m_Transformer.setOffset(QPoint(100, 100));
}


BB_WorkFrame::~BB_WorkFrame()
{}


/**
 * Zeichnet den Hintergrund und alle Objekte (Wenn die Arbeitsfläche aktiviert ist).
 * Zeichen Reihenfolge:
 * 1. Alle Objekte aus dem DrawObjects-Vektor, die KEINE Punkte sind
 * 2. Alle Punkte
 * 3. Die ToolObjekte
 * Jedes Objekt, das Gezeichnet wird, liegt oberhalb der bereits gezeichneten Objekte.
 * @author Alex Letkemann
 * @date 12.12.2005
 */
void BB_WorkFrame::paintEvent ( QPaintEvent * pe)
{
	/* Nur Zeichnen, wenn die Arbeitsfläche aktiviert ist. */
    if(isEnabled())
    {
        QLabel::paintEvent(pe);

        QPainter painter(this);
        drawCenter(painter);

        if(m_DrawObjects != NULL)
        {
			BB_DrawObject* object;		
			
			/* Prüfen, ob die Objekte gezeichnet werden sollen, oder ob sie vom Tool ausgeblendet werden */
			if( m_Tool == NULL || ( m_Tool != NULL && m_Tool->getShowDrawObjects() == true ) )
			{
				/* Alle Objekte außer der Punkte zeichnen */
				for(int i = 0; i < m_DrawObjects->count(); i++)
				{
					if( typeid(*(m_DrawObjects->at(i))) != typeid(BB_Point) )
					{
						object = m_DrawObjects->at(i);
						object->show(m_Transformer,painter);
					}
				}
				
				
				/* Alle Punkte zeichnen */
				for(int i = 0; i < m_DrawObjects->count(); i++)
				{
					if( typeid(*(m_DrawObjects->at(i))) == typeid(BB_Point) )
					{
						object = m_DrawObjects->at(i);
						object->show(m_Transformer,painter);
					}
				}
			}
			
			/* ToolObjekte Zeichnen */
			for(int i = 0; i < m_ToolObjects.count(); i++)
			{
				m_ToolObjects.at(i)->show(m_Transformer,painter);
			}
			
        }
        else
        {
			qDebug() << "m_DrawObjects nicht initialisiert!" << endl;
        }
    }
}


/**
 * Setzt den Zoomfaktor, mit dem dargestellt werden soll.
 * @param faktor Zoomfaktor
 */
void BB_WorkFrame::setZoomFaktor(double faktor)
{
	m_Transformer.setScale(faktor);
}




/**
 * Gibt das Tool, welches verwendet wird.
 * @return Tool, welches gerade verwendet wird.
 */
BB_AbstractTool* BB_WorkFrame::getTool()
{
    return m_Tool;
}


/**
 * Setzt das Tool, welches verwendet werden soll. 
 * Vorher wird das Letze Tool zurückgesetzt.
 * @param tool Tool, welches verwendet werden soll.
 */
void BB_WorkFrame::setTool(BB_AbstractTool* tool)
{
    if(tool != NULL)
    {
		if(m_Tool != NULL)
		{
			m_Tool->reset();
		}
		
		/* ToolObjekte des letzten Tools entfernen */
		m_ToolObjects.clear();		
		
        m_Tool = tool;
		m_Tool->setWorkFrame( this );
		m_Tool->setTransformer(&m_Transformer);
		m_Tool->setToolObjects(&m_ToolObjects);
		m_Tool->setSelectionVector(m_Selection);
		m_Tool->setDocComponent( m_Component );
		

		
    }
    else
    {
        QMessageBox::critical (this, "Fehler (BB_WorkFrame)", "Fehler beim setzten des Tools.\nNULL-Pointer erhalten", QMessageBox::Ok,QMessageBox::NoButton);
    }
	
	update();
}

/**
 * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
 */
void BB_WorkFrame::mousePressEvent ( QMouseEvent * me)
{
    if(m_Tool != NULL)
    {
        m_Tool->click(me);
        // 		update();
    }
    else
	{
        cout << "Kein Tool ausgewählt" << endl;
	}
}

/**
 * Wird aufgerufen, wenn eine Maustaste losgelassen wird.
 */
void BB_WorkFrame::mouseReleaseEvent(QMouseEvent* me)
{
    if(m_Tool != NULL)
    {
        m_Tool->release(me);
        update();
    }
    else
	{
        cout << "Kein Tool ausgewählt" << endl;
	}
	
	/* Mouseevent weiterleiten, damit das BB_TabXXXXX es mitkriegt */
	QLabel::mouseReleaseEvent(me);
}


/**
 * Wird aufgerufen, wenn die Maus mit einer gedrückten Maustaste bewegt wird.
 */
void BB_WorkFrame::mouseMoveEvent(QMouseEvent* me)
{

    if(m_Tool != NULL)
    {
		bool overX, overY;
		overX = (me->pos().x() < 0 || me->pos().x() > width() );
		overY = (me->pos().y() < 0 || me->pos().y() > height() );
		
        m_Tool->move(me, overX, overY);
        update();
    }
    else
	{
		qDebug() << "Kein Tool ausgewählt" << endl;
	}
}


/* *
 * Gibt einen Pointer des Objektvectors oder NULL, falls dieser nicht gesetzt ist.
 * @return Pointer des Objektvectors.
 */
// QVector< BB_DrawObject *>* BB_WorkFrame::getDrawObjects() const
// {
//     return m_DrawObjects;
// }


/* *
 * Setzt den Pointer des Workframe auf den Vector mit den Objekten.
 * Es findet keine Überprüfung statt, ob der Pointer NULL ist oder nicht.
 * @param objects Pointer auf den Objektvector.
 */
// void BB_WorkFrame::setDrawObjects(QVector< BB_DrawObject *>* objects)
// {
// 	/* Keine überprüfung auf null, da NULL die darstellung der Objekte deaktiviert*/
// 	m_DrawObjects = objects;
// 	
// 	if(m_Tool != NULL)
// 	{
// 		m_Tool->setDocComponent( m_Component );
// // 		m_Tool->setObjects(m_DrawObjects);
// // 		m_Tool->setTransformer(&m_Transformer);
// 	}
// }


/**
 * Zeichnet einen blauen Kreutz am logischen Koordinatenursprung
 * @param painter Painter, mit dem gezeichnet wird
 * @author Alex Letkemann
 * @date 13.09.2005
 */
void BB_WorkFrame::drawCenter(QPainter &painter)
{

    QPoint dest;
    C2dVector src(0,0);
    m_Transformer.logicalToScreen(dest,src);

    painter.save();
    painter.setPen(QColor("Blue"));
    painter.drawLine(dest.x() - 10,dest.y(),dest.x() + 10,dest.y());
    painter.drawLine(dest.x(),dest.y() -10,dest.x(), dest.y() + 10);
    painter.restore();
}


BB_DocComponent* BB_WorkFrame::getDocComponent() const
{
    return m_Component;
}


void BB_WorkFrame::setDocComponent( BB_DocComponent* component )
{
	m_Component = component;
	if(m_Component == NULL)
	{
		m_DrawObjects = NULL;
	}
	else
	{
		m_DrawObjects = m_Component->getDrawObjects();
		if(m_Tool != NULL)
		{
			m_Tool->setDocComponent( m_Component );
			m_Tool->setTransformer( &m_Transformer );
		}
	}
}


/*!
    \fn BB_WorkFrame::documentChanged()
 */
void BB_WorkFrame::documentChanged()
{
	update();
	if( m_Component != NULL)
	{
		m_Component->setModified( true );
	}
}
