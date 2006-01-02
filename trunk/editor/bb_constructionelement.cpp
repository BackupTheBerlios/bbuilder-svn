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

BB_ConstructionElement::BB_ConstructionElement()
        : BB_Rect()
{}


BB_ConstructionElement::~BB_ConstructionElement()
{}





QString BB_ConstructionElement::getTextureFileName() const
{
    return m_TextureFileName;
}


void BB_ConstructionElement::setTextureFileName( const QString& Value )
{
    m_TextureFileName = Value;
    if ( !m_TextureFileName.isNull() )
    {
        m_Image.load( m_TextureFileName );
    }
}


/*!
    \fn BB_ConstructionElement::openTextureDlg()
 */
void BB_ConstructionElement::openTextureDlg()
{
    BB_DlgOpenTexture dlg;
    dlg.setTextureFile( m_TextureFileName );
    dlg.exec();
    setTextureFileName( dlg.getTextureFile() );
}


