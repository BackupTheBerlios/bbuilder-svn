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

#include <bb_globals.h>
#include <c3dtriangle.h>

using namespace std;

BB_DrawObject::BB_DrawObject( QString name )
        : BB_Object( name )
{
    m_Pen.setStyle( Qt::SolidLine );
    m_Pen.setColor( Qt::red );

    m_PenSelected.setStyle( Qt::DashLine );
    m_PenSelected.setColor( Qt::magenta );

	m_Brush.setColor( Qt::red );
	m_Brush.setStyle( Qt::SolidPattern );
	
	m_BrushSelected.setColor( Qt::magenta );
	m_BrushSelected.setStyle( Qt::SolidPattern );

    m_Selected = false;
	
// 	m_GlObject = NULL;
}


BB_DrawObject::~BB_DrawObject()
{

}




/*!
    \fn BB_DrawObject::moveBy(const QPoint &pMove)
 */
void BB_DrawObject::moveBy( C2dVector pMove )
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
// const QColor & BB_DrawObject::getColor() const
// {
//     return m_Color;
// }


/*!
    \fn BB_DrawObject::setColor(QColor c)
 */
// void BB_DrawObject::setColor( const QColor& value )
// {
// 	m_Color = value;
// }
// 

bool BB_DrawObject::isHit( const QRectF& rect )
{
	return false;
}

/*!
    \fn BB_DrawObject::getClassName()
 */
const QString BB_DrawObject::getClassName()
{
    return QString( "BB_DrawObject" );
}


bool BB_DrawObject::isSelected() const
{
    return m_Selected;
}


void BB_DrawObject::setSelected( bool theValue )
{
    m_Selected = theValue;
}


void BB_DrawObject::setBrush( const QBrush& value )
{
	m_Brush = value;
}


void BB_DrawObject::setPen( const QPen& value )
{
	m_Pen = value;
}



/**
 * Wird aufgerufen, wenn das Objekt durch abhängige Objekte bewegt wird.
 * @author Alex Letkemann
 */
void BB_DrawObject::moveEvent()
{
    // Hier keine Implementierung
}


/*!
    \fn BB_DrawObject::createGl()
 */
void BB_DrawObject::createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height )
{
	// hier keine Implementierung, einfach nichts machen ...
}

QString BB_DrawObject::getTextureFileName() const
{
	return m_TextureFileName;
}


void BB_DrawObject::setTextureFileName( const QString& Value )
{
// 	if ( m_TextureFileName != Value )
// 	{
// 		m_TextureFileName = getName() + ".png";
// 		QImage image( Value );
// 		image.save( PRO_TEXTURES_DIR() + SEPARATOR() + getTextureFileName(), "PNG" );
// 	}
	
	m_TextureFileName = Value;
}

void BB_DrawObject::setTextureAbsoluteFileName( const QString& Value )
{
	QImage image( Value );
	if ( !image.isNull() )
	{
		image.save( PRO_TEXTURES_DIR() + SEPARATOR() + getName() + ".png", "PNG" );
		setTextureFileName( getName() + ".png" );
		return;
	}
	qDebug("image ist nicht geladen");
}
