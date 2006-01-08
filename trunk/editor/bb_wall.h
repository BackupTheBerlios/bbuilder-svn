/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                             *
*   v.ustinov@web.de                                                                                           *
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
#ifndef BB_WALL_H
#define BB_WALL_H

#include "bb_line.h"
#include "bb_doccomponent.h"
#include "bb_door.h"

#include <QPixmap>

/**
Diese Klasse representiert eine Wand,
sie hat zwei pointer auf BB_WallPoint.
Eigene Pinkten hat sie nicht
 
@author Vaceslav Ustinov
*/
class BB_Wall : public BB_Line
{
    public:
        BB_Wall( BB_Point* p1, BB_Point* p2 );
        ~BB_Wall();
        virtual const QString getClassName();
        virtual void generateXElement( QTextStream &out, int depth );
        virtual void show( BB_Transformer& transformer, QPainter& painter ) const;
        void editDlg( BB_DocComponent * docComponent );
        virtual void moveEvent();
        void setObjects( QVector< BB_DrawObject * >* Value );
        QVector< BB_DrawObject * >* getObjects() const;
        QVector< BB_DrawObject * >* getObjectsWithPoints() const;
        QVector< BB_DrawObject * >* getPoints() const;
        void openTextureDlg();
        virtual void swap();
        BB_Door * hastDoor();

    private:
        virtual void showDirection( BB_Transformer& transformer, QPainter& painter, QPoint& middle ) const;
        void calculateDirection();
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );

    protected:
        C2dVector m_Direction;
        bool m_ShowDirection;
        QPen m_PenDirection;
        QVector <BB_DrawObject *> * m_Objects;
        /** Hohe in meter*/
        double m_Hight;
};

#endif
