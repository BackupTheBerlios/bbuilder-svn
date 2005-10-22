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
 ***************************************************************************/
#ifndef BB_DWPOINT_H
#define BB_DWPOINT_H

#include "bb_wall.h"

/**
BB_DWPoint - Door or Window Point

@author Vaceslav Ustinov
*/
class BB_DWPoint : public BB_DrawObject
{
public:
	/**
	Standart Construct
	@author Vaceslav Ustinov
	*/
    BB_DWPoint(BB_Wall * wall, bool first = false);

    ~BB_DWPoint();
    /**
    *Funktion zum ermitteln, ob diesen Punkt erster zur
    *BB_Point Pos1 von BB_Wall steht
    *
    *@author Vaceslav Ustinov
    *@return boolean m_first
    */
    bool isFirst();
    virtual const QString getClassName();
private:
	/**
	Pointer auf BB_Wall zu der dieser Punkt gehoert
	*/
	BB_Wall * m_wall;
	/**
	Koofezient: (Abstand Pos1 zu "this") / (Länge von BB_Wall (m_wall))
	*/
	double m_Pos;
	/**
	wenn true, dann steht dieser Punkt näher zur Pos1 von BB_Wall
	wenn false, dann steht dieser Punkt weiter als der "andere"
	*/
	bool m_first;


};

#endif
