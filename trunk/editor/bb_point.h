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
#include <QStandardItemModel>
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
//     void removeLine(BB_Line * line);
    /**
    @author Vaceslav ustinov
    F&uuml;gt eine neue Linie zu m_Lines Vector hinzu.
    @param line BB_Line eine neue Linie
    @date 20.10.2005
    */
//     void addLine(BB_Line * line);
    /**
    @author Vaceslav Ustinov
    L&ouml;scht alle BB_lines aus dem Vector m_Lines
    @date 20.10.2005
     */
//     void deleteLines(QVector< BB_DrawObject * >* objects);
    virtual const QString getClassName();
    void setX(double value);
    void setY(double value);
    double getX(){return m_Pos.x();};
    double getY(){return m_Pos.y();};
    virtual void generateXElement(QTextStream &out, int depth);
    QStandardItemModel * getItemModel();
    void setScale(double theValue){m_scale = theValue;}
    bool isHit(QRect rect);
    /**
    Löscht vollständig ein Objekt aus dem Vektor.
    @author Vaceslav Ustinov
    @date 14.11.2005
    @param BB_DrawObject * zu löschende Objekt
    @return void
    */
    void deleteLinkedObject(BB_DrawObject * object);
    /**
    Entfernt ein Objekt aus dem Vektor.<br>Instantz wird nicht gelöscht
    @author Vaceslav Ustinov
    @date 14.11.2005
    @param BB_DrawObject * zu löschende Objekt
    @return BB_DrawObject wenn Ein Objekt aus dem Vektor entwernt wurde, wird ein Link auf diesen Objekt
    zurückgegeben. Wenn es nicht gelöscht wurde, wird ein Null - Pointer zurückgegeben.
    */
    void removeLinkedObject(BB_DrawObject * object);
    /**
    ///@todo
    @author Vaceslav Ustinov
    @date 14.11.2005
    @return void
    */
    void deleteLinkedObjects(QVector< BB_DrawObject * >* objects);
    void BB_Point::addObject(BB_DrawObject * newObject);
	/**
	* erzeugt von BB_Point ein QT-QPoint
	* @return QPoint
	* @date 20.12.2005
	* @author Vaceslav Ustinov
	*/
	QPoint getQPoint();



private:
    int m_Radius;
    double m_scale;
protected:
    C2dVector m_Pos;
    /**
    @author Vaceslav Ustinov
    QVector mit allen Linien, die zu diesem Punkt gehoeren.
    @date 20.10.2005
    */
//     QVector<BB_Line*> m_Lines;
    /**
    QVector mit allen Objekten, die zu diesem Punkt gehoeren.<br>
    z.B. BB_Line oder BB_Tiangle
    @author Vaceslav Ustinov
    @date 14.11.2005
    */
    QVector<BB_DrawObject*> m_Links;
};

#endif
