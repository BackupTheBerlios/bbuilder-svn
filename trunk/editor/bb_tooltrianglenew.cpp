//
// C++ Implementation: bb_tooltrianglenew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_tooltrianglenew.h"

#include <iostream>

using namespace std;

BB_ToolTriangleNew::BB_ToolTriangleNew()
        : BB_AbstractTool()
{
	m_Triangle = NULL;
}


BB_ToolTriangleNew::~BB_ToolTriangleNew()
{
	reset();
}

void BB_ToolTriangleNew::click(QMouseEvent* me)
{
    if(me != NULL)
    {
		m_pScreen = me->pos();	
		m_Transformer->screenToLogical(m_pLogic, m_pScreen);
		BB_DrawObject *object;
		
        if(me->button() == Qt::LeftButton)
        {
            if(m_Triangle == NULL)
            /* Erster Click */
            {

				object = getClickedObject(m_pLogic,typeid(BB_Point));
				
				/* Falls ein BB_Point ausgewählt wurde */
				if(object != NULL)
				{
					m_Triangle = new BB_Triangle((BB_Point*) object, (BB_Point*) object, (BB_Point*) object);
					object->setSelected( true );						// Den angeclickten Punkt markieren
					m_ToolObjects->append(m_Triangle);
				}
            }
			else
			/* Weitere clicks */
			{

				cout 	<< " pos1:" << m_Triangle->getPos1() 
						<< " pos2:" << m_Triangle->getPos2() 
						<< " pos3:" << m_Triangle->getPos3() << endl;
				
				/* Prüfen, ob die zweite Ecke bereits gesetzt ist */
				if(m_Triangle->getPos1() == m_Triangle->getPos2())
				{
					object = getClickedObject(m_pLogic,typeid(BB_Point));
// 					cout << object << endl;
					if(object != NULL)
					{
						if(object != m_Triangle->getPos1())
						{
							object->setSelected( true );				// Den angeclickten Punkt markieren
							m_Triangle->setPos2((BB_Point*) object);
						}
						object = NULL;
					}
				}
				
				/* Prüfen, ob die dritte Ecke bereits gesetzt ist */ 
				else if(m_Triangle->getPos1() == m_Triangle->getPos3())
				{
					object = getClickedObject(m_pLogic,typeid(BB_Point));
// 					cout << object << endl;
					if(object != NULL)
					{
						if(object != m_Triangle->getPos1() && object != m_Triangle->getPos2())
						{
							m_Triangle->setPos3((BB_Point*) object);
							object->setSelected( true );				// Den angeclickten Punkt markieren
							object = NULL;
							
							
							/// @todo
							
							// Triangle an Vektor anhängen
							m_Objects->append(m_Triangle);
// 							cout << "Triangle: ["<< m_Triangle->getPos1() 
// 									<<"]["<<m_Triangle->getPos2()
// 									<<"]["<<m_Triangle->getPos3()<<"]" 
// 									<< m_Triangle << endl;
							
							// Wichtig:  m_Triangle wird auf NULL gesetzt, da sie sonst vom reset() gelösch wird
							
							// Die Selektion aufheben
							m_Triangle->getPos1()->setSelected( false );
							m_Triangle->getPos2()->setSelected( false );
							m_Triangle->getPos3()->setSelected( false );
							
							m_Triangle = NULL;
							reset();
						}
						
					}
				}
				
			}
        }
        else if(me->button() == Qt::RightButton)
        {
			reset();
        }
    }
}

void BB_ToolTriangleNew::move(QMouseEvent* me, bool overX, bool overY)
{
	/* Eigendlich sinnlos aber die Warnungen sind weg. */
	if(me != NULL && overX && overY)
	{
		me->ignore();
	}
}

void BB_ToolTriangleNew::release(QMouseEvent* me)
{
	me->ignore();
}



/**
 * Setzt das Tool zurück
 */
void BB_ToolTriangleNew::reset()
{
	if(m_Triangle != NULL)
	{
		// Alle Links zum erstellten Triangle löschen
		m_Triangle->getPos1()->removeLinkedObject( m_Triangle );
		m_Triangle->getPos2()->removeLinkedObject( m_Triangle );
		m_Triangle->getPos3()->removeLinkedObject( m_Triangle );
		
		// Die Selektion aller Punkte aufheben
		m_Triangle->getPos1()->setSelected( false );
		m_Triangle->getPos2()->setSelected( false );
		m_Triangle->getPos3()->setSelected( false );
		
		
		// Triangle lösche
		delete m_Triangle;
		m_Triangle = NULL;
	}
	
 	m_ToolObjects->clear();
	
}
