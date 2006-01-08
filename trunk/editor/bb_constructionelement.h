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
#ifndef BB_CONSTRUCTIONELEMENT_H
#define BB_CONSTRUCTIONELEMENT_H

#include <bb_rect.h>
#include "QFileInfo"

/**
Eine Basis-Klasse fuer allle Konstruktion-Elemente z.B: Fenster oder T&uuml;r
In Zukunft auch m&ouml;glicherweise Bilder und Poster
 
	@author Vaceslav Ustinov <v.ustinov@web.de>
*/
class BB_ConstructionElement : public BB_Rect
{
    public:
        BB_ConstructionElement( C2dVector v1, C2dVector v2 );
        ~BB_ConstructionElement();
        void setTextureFileName( const QString& Value );
        void setTextureAbsoluteFileName( const QString& Value );
        QString getTextureFileName() const;
        void openTextureDlg();
        void show( BB_Transformer& transformer, QPainter& painter ) const;
        void setWallPosition1( const C2dVector& Value );
        C2dVector getWallPosition1() const;
        void setWallPosition2( const C2dVector& Value );
        C2dVector getWallPosition2() const;
        void setCoefficientPos1( const C2dVector& Value );
        C2dVector getCoefficientPos1() const;
        void setCoefficientPos2( const C2dVector& Value );
        C2dVector getCoefficientPos2() const;
    protected:
        QString m_TextureFileName;
        QImage m_Image;
        C2dVector m_WallPosition1;
        C2dVector m_WallPosition2;
        C2dVector m_CoefficientPos1;
        C2dVector m_CoefficientPos2;
};

#endif
