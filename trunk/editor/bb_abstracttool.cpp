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
***************************************************************************/
#include <bb_abstracttool.h>
#include <bb_tab.h>
#include <bb_workframe.h>
#include <iostream>

#include <bb_navigationpoint.h>
#include <bb_terrainpoint.h>

using namespace std;

BB_AbstractTool::BB_AbstractTool(QWidget * parent)
{
	m_ParentWidget = parent;
    m_Component = NULL;
    m_Transformer = NULL;
    m_Objects = NULL;
    m_Action = NULL;
    m_ToolWidget = NULL;
    m_WorkFrame = NULL;
	m_ToolObjects = NULL;
    m_ShowDrawObjects = true;
	m_ToolWidget = NULL;
	m_Selection = NULL;	
}

BB_AbstractTool::~BB_AbstractTool()
{}

void BB_AbstractTool::move( QMouseEvent* me, bool overX, bool overY )
{
	overX = false;
	overY = false;
	me->ignore();
}

void BB_AbstractTool::release( QMouseEvent* me )
{
	me->ignore();
}



bool BB_AbstractTool::deleteObject( BB_DrawObject * delObject )
{
    if ( m_Objects != NULL && delObject != NULL )
    {
        BB_DrawObject * tmpObject;
        // 		int objectPosition;
        // 		objectPosition = -1;
        for ( int i = m_Objects->count() - 1; i >= 0 ; i-- )
        {
            tmpObject = m_Objects->at( i );
            if ( tmpObject == delObject )
            {
                // Falls das Objekt ein Knoten ist, werden zuerst alle abhängigen Objekte gelöscht
                if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Point ) ||
					 typeid( *( m_Objects->at( i ) ) ) == typeid( BB_TerrainPoint ) ||
					 typeid( *( m_Objects->at( i ) ) ) == typeid( BB_NavigationPoint ))
                {
                    ( ( BB_Point* ) ( m_Objects->at( i ) ) ) ->deleteLinkedObjects( m_Component->getDrawObjects() );
                }

                m_Objects->remove( i );
                delete delObject;
                return true;
                // 				objectPosition = i;
            }
        }
    }

    return false;


}



/**
 * Gibt den Transformer zurück, der bei der Bearbeitung verwendet wird.
 * @return Transformer, der bei der Bearbeitung verwendet wird.
 */
BB_Transformer* BB_AbstractTool::getTransformer() const
{
    return m_Transformer;
}


/**
 * Setzt den Transformer, der bei der Bearbeitung verwendet werden soll.
 * @param transformer Transformer, der bei der bearbeitung verwendet werden soll.
 */
void BB_AbstractTool::setTransformer( BB_Transformer* transformer )
{
    m_Transformer = transformer;
}


QVector<BB_DrawObject*>* BB_AbstractTool::getSelectionVector() const
{
    return m_Selection;
}



void BB_AbstractTool::setSelectionVector( QVector<BB_DrawObject*>* selectionVector )
{
    if ( selectionVector != NULL )
    {
        m_Selection = selectionVector;
		if( m_ToolWidget != NULL )
		{
			m_ToolWidget->setSelection( m_Selection );
		}
    }
	
    else
    {
        cout << "BB_AbstractTool::setSelectionVector(): Übergebener Pointer ist NULL\n Auswahl-Vektor wurde nicht gesetzt." << endl;
    }
}


QVector< BB_DrawObject * >* BB_AbstractTool::getToolObjects() const
{
    return m_ToolObjects;
}


void BB_AbstractTool::setToolObjects( QVector< BB_DrawObject * >* theValue )
{
    m_ToolObjects = theValue;
}


/**
 * Hebt die Selektion alle Objekte, die im SelectionVector liegen, auf.
 */
void BB_AbstractTool::clearSelection()
{

    for ( int i = 0; i < m_Selection->count(); i++ )
    {
        m_Selection->at( i ) ->setSelected( false );
    }

    m_Selection->clear();
}


QAction* BB_AbstractTool::getAction()
{
    return m_Action;
}


void BB_AbstractTool::setAction( QAction* action )
{
    if ( action != NULL )
    {
        m_Action = action;
    }
    else
    {
        cout << "BB_AbstractTool::setAction(): NULL-Pointer erhalten" << endl;
    }
}


/**
 * Setzt das Tool zurück.
 * 
 */
void BB_AbstractTool::reset()
{
    if ( m_ToolWidget != NULL )
    {
        m_ToolWidget->updateWidget();
    }
}


/**
 * Gibt ein Objekt des angegebenen Typs zurück, 
 * welches sich an der angegebenen Logischen position befindet.
 * Falls es kein Objekt an der angegebenen Position zu finden ist, wird NULL zurück gegeben.
 * @param posLogic Position, an welcher gesucht wird.
 * @param type Typ des Objektes, welcher gesucht wird.
 * @return Pointer auf das Objekt, falls es solch ein Objekt gibt, sonst NULL.
 */
BB_DrawObject* BB_AbstractTool::getClickedObject( const C2dVector &posLogic , const std::type_info &type )
{

    /// todo Fehler abfangen
    BB_DrawObject * object;
    bool exit = false;
    for ( int i = 0; i < m_Objects->count() && exit == false; i++ )
    {
        object = m_Objects->at( i );
        if ( object != NULL && typeid( *object ) == type && object->isHit( posLogic ) )
        {
            exit = true;
            object = object;
        }
        else
        {
            object = NULL;
        }

    }

    return object;
}


/**
 * Gibt das DocComponent, mit welchem gearbeitet wird, zurück.
 * Wenn kein DocComponent gesetzt ist wird NULL-Zurückgegeben.
 * @return DocComponent, mit welchem gearbeitet wird.
 */
BB_DocComponent* BB_AbstractTool::getDocComponent() const
{
    return m_Component;
}


/**
 * Setzt das DocComponent, mit welchem gearbeitet wird.
 * NULL-Pointer sind Erlaubt
 * @param component DocComponent, mit welchem gearbeitet wird.
 */
void BB_AbstractTool::setDocComponent( BB_DocComponent* component )
{
    m_Component = component;
    if ( m_Component == NULL )
    {
        m_Objects = NULL;
        m_Transformer = NULL;
    }
    else
    {
        m_Objects = m_Component->getDrawObjects();
    }
}

void BB_AbstractTool::setObjects( QVector<BB_DrawObject*>* objects )
{
    if ( objects != NULL )
    {
// 		qDebug("Vector mit Points ist gesetzt!");
        m_Objects = objects;
    }
    else
    {
        qDebug( "Null-Pointer in BB_AbstractTool::setObjects(QVector<BB_DrawObject*>* objects)" );
    }
}


/**
 * Gibt den Status zurück, ob die DrawObject gezeichnet werden sollen oder nicht.
 * @return Status
 */
bool BB_AbstractTool::getShowDrawObjects()
{
    return m_ShowDrawObjects;
}




/**
 * Gibt das Tool-Fenster zurück
 */
BB_AbstractToolWidget* BB_AbstractTool::getToolWidget()
{
    return m_ToolWidget;
}


/**
 * Setzt das aktuelle Workframe
 * @param value das aktuelle Workframe
 */
void BB_AbstractTool::setWorkFrame( BB_WorkFrame* value )
{
    m_WorkFrame = value;
}


/**
 * Aktualisiert das Workframe.
 */
void BB_AbstractTool::documentChanged()
{
    if ( m_WorkFrame != NULL )
    {
        m_WorkFrame->documentChanged();
    }

    if ( m_ToolWidget )
    {
        m_ToolWidget->updateWidget();
    }
}


/**
 * Aktualisiert das Tool-Fenster
 */
void BB_AbstractTool::updateWidget()
{
	if( m_ToolWidget != NULL )
	{
		m_ToolWidget->updateWidget();
	}
}



/**
 * Löscht alle selektierten Objekte
 * @author Alex Letkemann
 * @date 26.12.2005
 */
void BB_AbstractTool::deleteSelection()
{
	if( m_Selection != NULL )
	{
		for(int i = m_Selection->count() -1 ; i >= 0; i--)
		{
			deleteObject( m_Selection->at(i) );
			m_Selection->remove(i);
		}
	}
	
	documentChanged();
}


/**
 * Gibt das Icon des Tools zurück
 * @return Das Icon des Tools
 * @author Alex Letkemann
 */
QIcon BB_AbstractTool::getIcon() const
{
    return m_Icon;
}


/**
 * Setzt das Icon des Tool
 * @param value Das neue Icon
 * @author Alex Letkemann
 */
void BB_AbstractTool::setIcon( const QIcon& value )
{
    m_Icon = value;
}
