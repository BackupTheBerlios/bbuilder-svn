/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov   						*
 *   v.ustinov@web.de										     *
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
#include "bb_line.h"
#include <iostream>
#include <math.h>

using namespace std;

const char * BB_Line::ClassName = "BB_Line";

BB_Line::BB_Line(BB_Point *p1, BB_Point *p2)
{
	m_Pos1 = p1;
    m_Pos2 = p2;
    m_Color.setNamedColor("Red");
    m_hitRange = 3;
}


BB_Line::~BB_Line()
{}


// QPoint BB_Line::getP0() const
// {
//     return BB_DrawObject::getP0();
// }

bool BB_Line::isHit(C2dVector hit)
{
	/*
    //hier wird eine Gleichung ermittelt y=mx+b
    double m, 	//Steigung
    b,		//verschiebung
    y,		//y ist y :-)
    min,		//man muss feststellen welcher Punkt ist kleiner. In X-Achse
    max,
    min_y,		//man muss feststellen welcher Punkt ist kleiner. In Y-Achse
    max_y;

    QPoint P1, P2;

    P2 = m_Pos2->getP0();
    P1 = m_Pos1->getP0();

    //minimum maximum ermitteln

    if (P1.x() < P2.x())
    {
        min = P1.x();
        max = P2.x();
    }
    else
    {
        max = P1.x();
        min = P2.x();
    }

    if ((P2.x() - P1.x()) > 20 || (P2.x() - P1.x()) < -20)
    {

        //Steigung ermitteln
        //m=(getY2()-getY())/(getX2()-getX());
        double zaehler, nenner;
        zaehler = (P2.y() - P1.y());
        nenner = (P2.x() - P1.x());
        m = zaehler/ nenner;
        //b finden
        //b=getY()-m*getX();
        b = P2.y() - (m * P2.x());
        //y finden, also die mogliche Position von y wenn die X-Position von maus ist :
        y = m * hit.x() + b;



        //         cout <<"y:"<<y<<"m"<<m<<endl;
        //         cout <<"b:"<<b<<endl;
        //         cout <<"min:" << min<< ":::max"<< max<< endl;
        //         cout <<"hit.x:" << hit.x()<< ":::hit.y:"<< hit.y()<< endl;
        //         cout <<"P1.x:" << P1.x()<< ":::P1.y:"<< P1.y()<< endl;
        //         cout <<"P2.x:" << P2.x()<< ":::P2.y:"<< P2.y()<< endl;
        
	   
	   if (hit.x() >= (min - m_hitRange) && hit.x() <= (max + m_hitRange))
        {
//             cout << "ich bin drin"<<endl;
            if (hit.y() >= (y - m_hitRange) && hit.y() <= (y + m_hitRange))
            {
//                 cout <<"hit line true" <<endl;
                return true;
            }
        }
    }
    else
    {
        if (P1.y() < P2.y())
        {
            min_y = P1.y();
            max_y = P2.y();
        }
        else
        {
            max_y = P1.y();
            min_y = P2.y();
        }
//         cout << "else"<<endl;
        if (hit.x() >= (min - m_hitRange) && hit.x() <= (max + m_hitRange))
            if (hit.y() >= (min_y - m_hitRange) && hit.y() <= (max_y + m_hitRange))
            {
//                 cout <<"hit line true" <<endl;
                return true;
            }
    }
    return false;
	*/
// 	m_Richtung = m_Pos2 -m_Pos1;
// 	C2dVector Pos1Tohit = hit - m_Pos1;
// 	if (Pos1Tohit.getLength() < m_Richtung.getLength())
// 	{
// 		
// 	}
	return false;
}

const QColor& BB_Line::getColor() const
{
    return BB_DrawObject::getColor();
}

void BB_Line::moveBy(QPoint pMove)
{
    //BB_DrawObject::moveBy(pMove);
}

void BB_Line::setColor(const QColor& _newVal)
{
    BB_DrawObject::setColor(_newVal);
}

void BB_Line::show(BB_Transformer& transformer, QPainter& painter) const
{
    BB_DrawObject::show(transformer, painter);

    QPoint dest_Pos1, dest_Pos2;

    transformer.logicalToScreen(dest_Pos1, m_Pos1->getPos());
    transformer.logicalToScreen(dest_Pos2, m_Pos2->getPos());

    painter.setPen(m_Color);
    painter.setBrush(m_Color);
    painter.drawLine(dest_Pos1.x(), dest_Pos1.y(), dest_Pos2.x(), dest_Pos2.y());
}




BB_Point* BB_Line::getPos1() const
{
    return m_Pos1;
}


bool BB_Line::setPos1(BB_Point* Value)
{
    if (Value != NULL)
    {
        m_Pos1 = Value;
        return true;
    }
    return false;
}


BB_Point* BB_Line::getPos2() const
{
    return m_Pos2;
}


bool BB_Line::setPos2(BB_Point* Value)
{
    if (m_Pos1 != Value && Value != NULL)
    {
        m_Pos2 = Value;
        return true;
    }
    return false;
}


const char * BB_Line::getClassName() const
{
    return BB_Line::ClassName;
}


/*!
    \fn BB_Line::getLaenge()
 */
double BB_Line::getLaenge()
{
    /// @todo implement me
}
