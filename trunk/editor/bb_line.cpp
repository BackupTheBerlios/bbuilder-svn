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

bool BB_Line::isHit(C2dVector hit)
{
    //Richtungsvektor von Pos1 zu Pos2
    m_Richtung = m_Pos2->getPos() - m_Pos1->getPos();
    //Richtungsvektor von Pos1 zu hit (also da wo mann mit muas klickt)
    C2dVector Pos1Tohit = hit - m_Pos1->getPos();
    //wenn der Abstand von Pos1 zu hit kleiner is als
    //Abstand von Pos1 zu Pos2, dann mache weiter
    //es heist also, dass Mausposition zwieschen den beiden Punkten ist
    if (Pos1Tohit.getLength() < m_Richtung.getLength())
    {
        //Normierte Vektor von m_Richtung, also Laenge = 1
        //dass brauchen wir um den Abstand von von hit zu Wand zu finden
        C2dVector norm_m_Richtung = m_Richtung.getNormalVector();
        //Normierte Vektor von Pos1Tohit
        C2dVector norm_Pos1Tohit = Pos1Tohit.getNormalVector();
        //Vektor zwieschen den beiden normierten Vektoren
        C2dVector differenz = norm_Pos1Tohit - norm_m_Richtung;

        //um den Maximalen erlaubten Abstand von einem Punkt zu einer Gerade
        //zu ermitteln, braucht man auch m_hitRange zu dividieren
        double nenner = Pos1Tohit.getLength() / norm_Pos1Tohit.getLength();
        //wenn jetzt den Abstand kleiner ist als erlaubt, dann return true
        if ((norm_Pos1Tohit - norm_m_Richtung).getLength() < (m_hitRange / nenner))
        {

            cout << "hitline true: diff: "<< differenz.getLength()<< "line lenght: "<< m_Richtung.getLength() <<endl;
            return true;
        }
    }
    cout << "hitline false"<<endl;
    return false;
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
