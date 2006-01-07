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
#include <bb_widgettooltrianglenew.h>
#include <bb_abstracttoolwidget.h>
#include <iostream>
#include <bb_terrainpoint.h>

using namespace std;

BB_ToolTriangleNew::BB_ToolTriangleNew(QWidget *parent)
        : BB_AbstractTool(parent)
{
    m_P1 = NULL;
    m_P2 = NULL;
    m_P3 = NULL;
}


BB_ToolTriangleNew::~BB_ToolTriangleNew()
{
    reset();
}

void BB_ToolTriangleNew::click( QMouseEvent* me )
{
    if ( me != NULL )
    {
        m_pScreen = me->pos();
        m_Transformer->screenToLogical( m_pLogic, m_pScreen );
        BB_Point *point;

        if ( me->button() == Qt::LeftButton )
        {
			
			point = getClickedPoint( m_pLogic );
            if ( m_P1 == NULL )
            {
                if ( point != NULL )
                {
                    m_P1 = point;
					selectObject( m_P1 );

                    point = NULL;
                }
            }
            /* Prüfen, ob die zweite Ecke bereits gesetzt ist */
            else if ( m_P2 == NULL )
            {
                point = getClickedPoint( m_pLogic );

                if ( point != NULL )
                {
                    if ( point != m_P1 )
                    {
						m_P2 = point;
						selectObject( m_P2 );
                    }
                    point = NULL;
                }
            }

            /* Prüfen, ob die dritte Ecke bereits gesetzt ist */
            else if ( m_P3 == NULL )
            {
                point = getClickedPoint( m_pLogic );
                // 					cout << object << endl;
                if ( point != NULL )
                {
					if ( point != m_P1 && point != m_P2 )
                    {
						m_P3 = point;
						selectObject( m_P3 );
						point = NULL;

                        BB_Triangle* newTriangle = createNewSurface();
                        // Triangle an Vektor anhängen
                        clearSelection();
                        if ( newTriangle )
                        {
                            m_Objects->append( newTriangle );
                            selectObject( newTriangle );
							updateWidget();
                        }

                        reset();
                    }

                }
            }

        }
    }
    else if ( me->button() == Qt::RightButton )
    {
        reset();
		updateWidget();
    }

}


/**
 * Setzt das Tool zurück
 */
void BB_ToolTriangleNew::reset()
{

    m_P1 = NULL;
    m_P2 = NULL;
    m_P3 = NULL;

}


/*!
    \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolTriangleNew::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolTriangleNew( this );
    }

    return m_ToolWidget;
}


/*!
    \fn BB_ToolTriangleNew::getClickedPoint( C2dVector &pos)
 */
BB_Point* BB_ToolTriangleNew::getClickedPoint( C2dVector & pos )
{
	return (BB_Point*) getClickedObject( pos, typeid( BB_Point ) );
}


/*!
    \fn BB_ToolTriangleNew::createNewSurface()
 */
BB_Triangle* BB_ToolTriangleNew::createNewSurface()
{
	
	BB_Triangle* triangle = NULL;
	
    if ( m_P1 != NULL && m_P2 != NULL && m_P3 != NULL )
    {
		triangle = new BB_Triangle( m_P1, m_P2, m_P3 );
    }
	return triangle;
}
