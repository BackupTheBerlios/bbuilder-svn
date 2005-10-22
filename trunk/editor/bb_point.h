/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                             *
 *   alex@letkemann.de                                                                                  *
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
#ifndef BB_POINT_H
#define BB_POINT_H

#include <bb_drawobject.h>
#include "c2dvector.h"
using namespace std;

class BB_Line;

/**
Klasse zum darstellen von einem verbindungs-Punkt
 
@author Vaceslav Ustinov
*/
class BB_Point : public BB_DrawObject
{
public:
        BB_Point();
        BB_Point(C2dVector p);

        ~BB_Point();


        //     virtual void moveBy( QPoint pMove);
        virtual void moveBy( C2dVector pMove);
        virtual void show(BB_Transformer& transformer, QPainter& painter) const;
        int getRadius();
        void setRadius(int r);
        virtual bool isHit(C2dVector hit);
        void setPos(const C2dVector& theValue);
        C2dVector getPos() const;
        QVector<BB_Line*>* getLines();
        /**
        @author Vaceslav ustinov
        L&ouml;scht eine Linie (line) aus dem m_Lines vector
        @param  line BB_Line zu loeschende Linie
        @date 20.10.2005
        */
        void removeLine(BB_Line * line);
        /**
        @author Vaceslav ustinov
        F&uuml;gt eine neue Linie zu m_Lines Vector hinzu.
        @param line BB_Line eine neue Linie
        @date 20.10.2005
        */
        void addLine(BB_Line * line);
        /**
        @author Vaceslav Ustinov
        L&ouml;scht alle BB_lines aus dem Vector m_Lines
        @date 20.10.2005
         */
        void deleteLines(QVector< BB_DrawObject * >* objects);
    	virtual const QString getClassName();
        void setX(double value);
        void setY(double value);
        double getX(){return m_Pos.x();};
        double getY(){return m_Pos.y();};
    virtual void generateXElement(QTextStream &out, int depth);


private:
        int m_Radius;
protected:
        C2dVector m_Pos;
        /**
        @author Vaceslav Ustinov
        QVector mit allen Linien, die zu diesem Punkt gehoeren.
        @date 20.10.2005
        */
        QVector<BB_Line*> m_Lines;
};

#endif
