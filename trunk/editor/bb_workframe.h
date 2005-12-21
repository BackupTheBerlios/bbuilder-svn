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
#ifndef BB_WORKFRAME_H
#define BB_WORKFRAME_H

#include <QtGui>
#include "bb_abstracttool.h"
#include "bb_drawobject.h"
#include "bb_transformer.h"
#include "bb_tab.h"

/**
@author Alex Letkemann
*/
class BB_WorkFrame : public QLabel
{
    public:
        BB_WorkFrame( QVector<BB_DrawObject*>* selectVector, QWidget * parent = 0, Qt::WFlags f = 0 );

        ~BB_WorkFrame();
        void setZoomFaktor( double faktor );

        BB_AbstractTool* getTool();
        void setTool( BB_AbstractTool* tool );

        void setDocComponent( BB_DocComponent* theValue );


        BB_DocComponent* getDocComponent() const;


        // 	void setDrawObjects(QVector< BB_DrawObject *>* theValue);
        // 	QVector< BB_DrawObject *>* getDrawObjects() const;


    protected:
        virtual void mousePressEvent ( QMouseEvent * me );
        virtual void mouseReleaseEvent ( QMouseEvent* me );
        virtual void paintEvent ( QPaintEvent * pe );
        virtual void mouseMoveEvent ( QMouseEvent* me );
        void drawCenter( QPainter &painter );
    protected:
        BB_AbstractTool* m_Tool;
        QVector<BB_DrawObject*>* m_Selection;
        BB_Transformer m_Transformer;
        /** Hilfsobjekte, die von den Tools erzeugt werden und gezeichnet werden müssen. */
        QVector<BB_DrawObject*> m_ToolObjects;
        /** Kompenent, mit welchem gearbeitet wird */
        BB_DocComponent* m_Component;
        QVector<BB_DrawObject*>* m_DrawObjects;
};

#endif
