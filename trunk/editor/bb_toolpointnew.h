/***************************************************************************
*   Copyright (C) 2005 by Alex Letkemann   *
*   alex@letkemann.de   *
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
#ifndef BB_TOOLPOINTNEW_H
#define BB_TOOLPOINTNEW_H

#include "bb_abstracttool.h"
#include "bb_point.h"
#include "bb_drawobject.h"

/**
@author Alex Letkemann
*/
class BB_ToolPointNew : public BB_AbstractTool
{
    public:
        /**
         * Konstruktor.
		 * Erstellt ein neues Werkzeug zur Erstellung von Punkten
		 * @author Alex Letkemann
         */
		BB_ToolPointNew(QWidget * parent);

		/**
		 * Destruktor
		 */
        ~BB_ToolPointNew();

        
        /**
		 * \fn BB_AbstractTool::getToolWidget()
         */
        virtual BB_AbstractToolWidget* getToolWidget();

    protected:
		/**
	 	 * \fn BB_AbstractTool::click( QMouseEvent* me )
		 */
		virtual void click( QMouseEvent* me );
        
		/**
		 * \fn BB_AbstractTool::release( QMouseEvent* me )
		 */
		virtual void release( QMouseEvent* me );
		
		/**
		 * \fn move( QMouseEvent* me, bool overX, bool overY )
		 */
		virtual void move( QMouseEvent* me, bool overX, bool overY );
		
        /**
         * Die Funktion such nach einem Punkt an der Position 'pos'.
		 * Wird ein Punkt an der angegebenen Position gefunden, wird der 
		 * Zeiger des Punktes zur&uumlckgegeben. Falls nicht wird NULL zurückgegeben.
         * @param pos Position an der nach dem Punkt gesucht wird
         * @return Zeiger auf den gefundenen Punkt.
         */
        virtual BB_Point* getClickedPoint( C2dVector& pos );

        /**
         * Die Funktion erzeugt einen neuen Punkt an der Position 'pos' und gibt den Zeiger
		 * auf den neuen Punkt zur&uuml;ck
         * @param pos Position, an der der neue Punkt erzeugt wird.
         * @return Zeiger auf den neuen Punkt
         */
        virtual BB_Point* createNewPoint( C2dVector& pos );



    protected:
        BB_Point* m_Point;
};

#endif
