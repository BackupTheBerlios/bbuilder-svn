/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   alex@letkemann.de   										*
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
#include "bb_drawobject.h"

#include <iostream>

using namespace std;

BB_DrawObject::BB_DrawObject(QString name) 
	: BB_Object(name)
{

}


BB_DrawObject::~BB_DrawObject()
{
}




/*!
    \fn BB_DrawObject::moveBy(const QPoint &pMove)
 */
void BB_DrawObject::moveBy(C2dVector pMove)
{
    /// @todo implement me
}


/*!
    \fn BB_DrawObject::show()
 */
// void BB_DrawObject::show(BB_Transformer& transformer,QPainter& painter) const
// {
//     /// @todo implement me
// }


/*!
    \fn BB_DrawObject::getColor()
 */
const QColor & BB_DrawObject::getColor()const
{
	return m_Color;
}


/*!
    \fn BB_DrawObject::setColor(QColor c)
 */
void BB_DrawObject::setColor(const QColor& _newVal)
{
	m_Color = _newVal;
}



/*!
    \fn BB_DrawObject::isHit(QPoint p)
 */
// bool BB_DrawObject::isHit(C2dVector hit)
// {
//     /// @todo implement me
// }


/*!
    \fn BB_DrawObject::getClassName()
 */
const QString BB_DrawObject::getClassName()
{
	return QString("BB_DrawObject");
}


bool BB_DrawObject::isSelected() const
{
    return m_Selected;
}


void BB_DrawObject::setSelected(bool theValue)
{
    m_Selected = theValue;
}
