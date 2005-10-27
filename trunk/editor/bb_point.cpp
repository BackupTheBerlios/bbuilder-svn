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
 ***************************************************************************/
#include "bb_point.h"

#include <iostream>
#include <math.h>
#include "bb_line.h"

using namespace std;


BB_Point::BB_Point()
                : BB_DrawObject()
{
        m_Radius = 7;
        m_hitRange = 2;
        m_Color.setNamedColor("Red");
        m_scale = 1.0;
}

BB_Point::BB_Point(C2dVector p)
{
        m_Pos = p;
        m_Radius = 7;
        m_Color.setNamedColor("Red");
        m_hitRange = 2;
        m_Selected = false;
        m_scale = 1.0;
}


BB_Point::~BB_Point()
{}


// void BB_Point::moveBy(QPoint pMove)
// {
//     m_P0.setX(m_P0.x() + pMove.x());
//     m_P0.setY(m_P0.y() + pMove.y());
// }

void BB_Point::moveBy(C2dVector vMove)
{
        m_Pos = m_Pos + vMove;
}

void BB_Point::show(BB_Transformer& transformer, QPainter& painter) const
{
        QPoint dest;
        double breite = m_Radius / 3;

        transformer.logicalToScreen(dest, m_Pos);

        painter.setPen(m_Color);
        painter.setBrush(m_Color);
        //painter.drawEllipse(dest.x() - m_Radius, dest.y() - m_Radius, m_Radius*2, m_Radius*2);
        painter.drawRect(dest.x() - m_Radius, dest.y() - m_Radius,
                         m_Radius*2, breite);
        painter.drawRect(dest.x() - m_Radius, dest.y() + m_Radius - breite,
                         m_Radius*2, breite);
        painter.drawRect(dest.x() - m_Radius, dest.y() - m_Radius + breite,
                         breite, m_Radius * 2 - breite * 2);
        painter.drawRect(dest.x() + m_Radius -breite, dest.y() - m_Radius + breite,
                         breite, m_Radius * 2 - breite * 2);
        painter.setBrush(QColor(0,200,0));
        painter.setPen(QColor(0,200,0));
        painter.drawRect(dest.x() - breite, dest.y() - breite,
                         breite * 2, breite * 2);
        if(m_Selected){
          painter.setBrush(QColor(0,0,200));
          painter.setPen(QColor(0,0,200));
          painter.drawText(dest.x() - m_Radius - breite, dest.y() - m_Radius -breite,"->");
          painter.drawRect(dest.x() - m_Radius - breite, dest.y() - m_Radius -breite,
                           breite, breite);
          painter.drawRect(dest.x() - m_Radius - breite, dest.y() + m_Radius,
                           breite, breite);
          painter.drawRect(dest.x() + m_Radius, dest.y() - m_Radius - breite,
                           breite, breite);
          painter.drawRect(dest.x() + m_Radius, dest.y() + m_Radius,
                           breite, breite);
        }
}



/*!
    \fn BB_Point::getRadius()
 */
int BB_Point::getRadius()
{
        return m_Radius;
}


/*!
    \fn BB_Point::setRadius(int r)
 */
void BB_Point::setRadius(int r)
{
        m_Radius = r;
}

bool BB_Point::isHit(C2dVector hit)
{
  //isHit von Kreis
//         double abstand = m_Pos.getAbstand(hit);
//         if(abstand <= (m_Radius + m_hitRange))
//                 return true;
//         return false;

  //isHit von Viereck
  double abstandX = abs ((int) (hit.x() - m_Pos.x()));
  double abstandY = abs ((int) (hit.y() - m_Pos.y()));
//   cout << "scale:" << m_scale<<endl;
  if (abstandX <= (m_Radius / m_scale) && abstandY <= (m_Radius/ m_scale)){
    cout << "hittrue" << m_scale<<endl;
    return true;
  }
  return false;
}




C2dVector BB_Point::getPos() const
{
        return m_Pos;
}


void BB_Point::setPos(const C2dVector& theValue)
{
        m_Pos = theValue;
}


/*!
    \fn BB_Point::deleteLines()
 */
void BB_Point::deleteLines(QVector< BB_DrawObject * >* objects)
{
        BB_Line * tmp;
        for (int i = 0; i < m_Lines.count(); i++) {
                tmp = m_Lines.at(i);
                BB_DrawObject * tmp_object;
                for (int j = 0; j < objects->count(); j++) {
                        tmp_object = objects->at(j);
                        if(tmp_object == tmp)
                                objects->remove(j);
                }
                //m_Lines.remove(i);
                cout <<"linie nummer "<< i << ":" << tmp <<endl;
                tmp->remove(this);
                cout <<"linie nummer(delete) "<< i << ":" << tmp <<endl;
        }
        m_Lines.clear();
}


/*!
    \fn BB_Point::removeMe(BB_Line * line)
 */
void BB_Point::removeLine(BB_Line * line)
{
        BB_Line * tmp;
        for (int i = 0; i<m_Lines.count(); i++) {
                tmp = m_Lines.at(i);
                if (tmp == line) {
                        m_Lines.remove(i);
                        delete line;
                }
        }
}


/*!
    \fn BB_Point::addLine()
 */
void BB_Point::addLine(BB_Line * line)
{
        m_Lines.insert(m_Lines.count(), line);
}

/*!
    \fn BB_Point::getClassName()
 */
const QString BB_Point::getClassName()
{
	return QString("BB_Point");
}
void BB_Point::setX(double value){
  m_Pos.setX(value);
}
void BB_Point::setY(double value){
  m_Pos.setY(value);
}


/*!
    \fn BB_Point::generateXElement(QTextStream &out, int depth)
 */
void BB_Point::generateXElement(QTextStream &out, int depth)
{
	out << BB::indent(depth) << "<bb_point id=\"" << getObjectNr() << "\" x=\"" << getX() << "\" y=\"" << getY() << "\">\n";
	BB_Object::generateXElement(out,depth+1);
	out << BB::indent(depth) << "</bb_point>\n";
}


/*!
    \fn BB_Point::getItemModel()
 */
QStandardItemModel * BB_Point::getItemModel()
{
  QStandardItemModel *model = new QStandardItemModel(4,2);
      QModelIndex index = model->index(0, 0, QModelIndex());
      //model->setData(index, QVariant((row+1) * (column+1)));
      model->setData(index, QVariant("m_Color"));
      index = model->index(0, 1, QModelIndex());
      model->setData(index, QVariant("Red"));
}


/*!
    \fn BB_Point::isHit(QRect rect)
 */
bool BB_Point::isHit(QRect rect)
{
  QRect normRect = rect;
  if (rect.x() > (rect.x() + rect.width()))
    normRect.setX(rect.x() + rect.width());
  if (rect.y() < (rect.y() + rect.height()))
    normRect.setY(rect.y() + rect.height());

  if ((getX() > normRect.x()) && (getX() < (rect.x() + rect.width()))) {
    if ((getY() < normRect.y()) && (getY() > (normRect.y() -normRect.height()))){
      return true;
    }
  }
  return false;
}
