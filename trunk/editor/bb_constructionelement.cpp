/***************************************************************************
*   Copyright (C) 2005 by Vaceslav Ustinov                                *
*   v.ustinov@web.de                                                      *
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
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
***************************************************************************/
#include "bb_constructionelement.h"
#include "bb_dlgopentexture.h"
#include "bb_point.h"
#include "bb_globals.h"

BB_ConstructionElement::BB_ConstructionElement( C2dVector v1, C2dVector v2 )
        : BB_Rect()
{
    setPos1( new BB_Point( v1 ) );
    setPos2( new BB_Point( v2 ) );
}


BB_ConstructionElement::~BB_ConstructionElement()
{}





QString BB_ConstructionElement::getTextureFileName() const
{
    return m_TextureFileName;
}


void BB_ConstructionElement::setTextureFileName( const QString& Value )
{
    if ( !Value.isNull() )
    {
        m_TextureFileName = Value;
        if ( !m_Image.load( PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName ) )
        {
            qDebug( "image wurde nicht geladen" );
        }
    }
}


/*!
    \fn BB_ConstructionElement::openTextureDlg()
 */
void BB_ConstructionElement::openTextureDlg()
{
    BB_DlgOpenTexture dlg;
    dlg.setTextureFile( PRO_TEXTURES_DIR() + SEPARATOR() + m_TextureFileName );
    dlg.exec();
    setTextureAbsoluteFileName( dlg.getTextureFile() );
}

void BB_ConstructionElement::setTextureAbsoluteFileName( const QString& Value )
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

