//
// C++ Implementation: bb_toolscale
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_toolscale.h"
#include "bb_line.h"
#include <bb_abstracttoolwidget.h>
#include <bb_widgettoolscale.h>

#include <iostream>

using namespace std;


BB_ToolScale::BB_ToolScale( QWidget * parent )
        : BB_AbstractTool( parent )
{
    m_Parent = parent;
    m_MovePoint = NULL;
    m_ScaleLine = NULL;
    /* Alle Objekte ausblenden */
    m_ShowDrawObjects = false;
    m_Icon = QIcon( IMG_DIR() + SEPARATOR() + "toolScale.png" );
}


BB_ToolScale::~BB_ToolScale()
{}


void BB_ToolScale::click( QMouseEvent* me )
{

    if ( me != NULL && me->buttons() == Qt::LeftButton )
    {
        m_Transformer->screenToLogical( m_pLogic, me->pos() );

        if ( m_Component->getScalePoint_1() ->isHit( m_pLogic ) )
        {
            m_MovePoint = m_Component->getScalePoint_1();
        }
        else if ( m_Component->getScalePoint_2() ->isHit( m_pLogic ) )
        {
            m_MovePoint = m_Component->getScalePoint_2();
        }
    }

}

void BB_ToolScale::move( QMouseEvent* me, bool overX, bool overY )
{
    if ( me != NULL && m_MovePoint != NULL && !overX && !overY )
    {
        m_Transformer->screenToLogical( m_pLogic, me->pos() );
        m_MovePoint->setPos( m_pLogic );

        updateWidget();
    }
}

void BB_ToolScale::release( QMouseEvent* me )
{
    ( ( BB_WidgetToolScale* ) getToolWidget() ) ->setLogicalScale( getLogicalScale() );
    m_MovePoint = NULL;
    me->ignore();
}



/*!
    \fn BB_ToolScale::setDocComponent( BB_DocComponent* component )
 */
void BB_ToolScale::setDocComponent( BB_DocComponent* component )
{
    BB_AbstractTool::setDocComponent( component );

    if ( m_Component != NULL )
    {

        updateWidget();

        if ( m_ScaleLine == NULL )
        {
            m_ScaleLine = new BB_Line( m_Component->getScalePoint_1(), m_Component->getScalePoint_2() );
        }
        else
        {
            m_ScaleLine->setPos1( m_Component->getScalePoint_1() );
            m_ScaleLine->setPos2( m_Component->getScalePoint_2() );
        }

        m_ToolObjects->clear();

        m_ToolObjects->append( m_Component->getScalePoint_1() );
        m_ToolObjects->append( m_Component->getScalePoint_2() );
        m_ToolObjects->append( m_ScaleLine );
    }
    else
    {
        reset();

    }
}


/**
 * Setzt das Tool zurück
 */
void BB_ToolScale::reset()
{

    m_ToolObjects->clear();
    if ( m_ScaleLine != NULL )
    {
        delete m_ScaleLine;
        m_ScaleLine = NULL;
    }
}


/**
 * Rechnet die Länge zwischen den beiden Punkten aus
 */
double BB_ToolScale::getLogicalScale()
{
    m_Tmp_v1 = m_Component->getScalePoint_2() ->getPos();
    m_Tmp_v2 = m_Component->getScalePoint_1() ->getPos();
    return ( m_Tmp_v2 - m_Tmp_v1 ).getLength();
}


/*!
    \fn BB_ToolScale::updateWidget()
 */
void BB_ToolScale::updateWidget()
{
    if ( m_Component != NULL )
    {
        ( ( BB_WidgetToolScale* ) getToolWidget() ) ->setLogicalScale( getLogicalScale() );
        ( ( BB_WidgetToolScale* ) getToolWidget() ) ->setRealScale( m_Component->getScaleRealPointer() );
    }
}


/*!
    \fn BB_AbstractTool::getToolWidget()
 */
BB_AbstractToolWidget* BB_ToolScale::getToolWidget()
{
    if ( m_ToolWidget == NULL )
    {
        m_ToolWidget = new BB_WidgetToolScale( this );
    }

    return m_ToolWidget;
}
