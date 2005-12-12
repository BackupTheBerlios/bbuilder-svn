/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                *
 *   V.Ustinov@web.de                                                      *
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
#include "bb_wall.h"

#include "bb_point.h"
#include "bb_dlgwalledit.h"

BB_Wall::BB_Wall(BB_Point* p1, BB_Point* p2): BB_Line(p1, p2)
{
}


BB_Wall::~BB_Wall()
{
}



/*!
    \fn BB_Wall::getClassName()
 */
const QString BB_Wall::getClassName()
{
        return QString("BB_Wall");
}


/*!
    \fn BB_Wall::generateXElement(QTextStream &out, int depth)
 */
void BB_Wall::generateXElement(QTextStream &out, int depth)
{
        out << BB::indent(depth) << "<bb_wall id=\"" << getObjectNr()
                        << "\" p1=\"" << getPos1()->getObjectNr()
                        << "\" p2=\"" << getPos2()->getObjectNr() << "\">\n";

        BB_Object::generateXElement(out,depth+1);
        out << BB::indent(depth) << "</bb_wall>\n";
}

void BB_Wall::show(BB_Transformer& transformer, QPainter& painter) const
{
//     BB_DrawObject::show(transformer, painter);

  QPoint dest_Pos1, dest_Pos2;

  transformer.logicalToScreen(dest_Pos1, m_Pos1->getPos());
  transformer.logicalToScreen(dest_Pos2, m_Pos2->getPos());

  painter.setPen(m_Color);
  painter.setBrush(m_Color);
  QPen pen;
  pen.setColor(m_Color);
  pen.setWidth(3);
  painter.setPen(pen);
  painter.drawLine(dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y());
}


/*!
    \fn BB_Wall::editDlg(QPixmap * pixmap)
 */
void BB_Wall::editDlg(QPixmap * pixmap)
{
	BB_DlgWallEdit EditDlg;
  EditDlg.setImage(pixmap);
  EditDlg.exec();
}
