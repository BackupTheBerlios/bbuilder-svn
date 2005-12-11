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
#include "bb_globals.h"

#include <iostream>

using namespace std;

BB_WorkArea::BB_WorkArea(QVector<BB_DrawObject*>* selectVector, QWidget *parent)
 : QScrollArea(parent)
{

        m_WorkFrame = new BB_WorkFrame(selectVector);
        m_WorkFrame->setFrameShape(QFrame::NoFrame);
        m_WorkFrame->setFrameShadow(QFrame::Plain);

//      /**** Image zum Testen *****/
//      QImage  *bg = new QImage();
//
//      bg->load(IMG_DIR() + SEPARATOR() + "RettungsPlan.png");
//
//      /***************/
//      m_WorkFrame->setPixmap(QPixmap(QPixmap::fromImage(*bg)));
        m_WorkFrame->setBackgroundRole(QPalette::Background);
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

        if(m_Map != NULL)
        {
                double zoom = m_Map->getZoom();

                Q_ASSERT(m_WorkFrame->pixmap());

                zoom *= faktor;

                if(zoom > 5.0)
                {
                        zoom = 5.0;
                }
                else if(zoom < 0.5)
                {
                        zoom = 0.5;
                }


                m_WorkFrame->resize(zoom * m_WorkFrame->pixmap()->size());
                m_WorkFrame->setZoomFaktor(zoom);

                horizontalScrollBar()->setValue(int(faktor * horizontalScrollBar()->value()     + ((faktor - 1) * horizontalScrollBar()->pageStep()/2)));

                verticalScrollBar()->setValue(int(faktor * verticalScrollBar()->value() + ((faktor - 1) * verticalScrollBar()->pageStep()/2)));

                m_Map->setZoom(zoom);
        }

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
 * Setzt den Zoomfaktor
 * @param zoom Zoomfaktor
 */
void BB_WorkArea::setZoomFaktor(double z)
{
        if(m_Map != NULL)
        {
                m_Map->setZoom(1.0);
                zoom(z);
        }
}


/**
 * Setzt den Hintergrund des Arbeitsbereiches
 * @return map Map welche als Hintergrund hinterlegt wird.
 */
bool BB_WorkArea::setMap(BB_Map* map)
{
        if(map != NULL)
        {
                m_Map = map;

                m_WorkFrame->setPixmap(m_Map->getMap());

                m_WorkFrame->setFrameShape(QFrame::Box);
                m_WorkFrame->setBackgroundRole(QPalette::Background);
                m_WorkFrame->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
                m_WorkFrame->setScaledContents(true);
                m_WorkFrame->setEnabled(true);

                setZoomFaktor(m_Map->getZoom());
                return true;
        }
        else
        {
                m_WorkFrame->setEnabled(false);
                m_WorkFrame->setFrameShape(QFrame::NoFrame);
                return false;
        }

}


/**
 * Setzt das Objekt, auf welchem gezeichnet wird.
 * @param device Objekt, auf welchem gezeichnet wird
 */
void BB_WorkArea::setDrawDevice(BB_DrawDevice * device)
{
        if(device == NULL)
        {
                m_WorkFrame->setEnabled(false);
                m_WorkFrame->setDrawObjects(NULL);
        }
        else
        {
                m_WorkFrame->setDrawObjects( device->getDrawObjects() );
                m_WorkFrame->setEnabled(true);

        }
        m_WorkFrame->update();
}


BB_Map* BB_WorkArea::getMap() const
{
    return m_Map;
}
