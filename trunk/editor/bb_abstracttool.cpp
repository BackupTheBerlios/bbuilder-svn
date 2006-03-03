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

/** Konstucktor */
BB_AbstractTool::BB_AbstractTool( QWidget * parent )
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
    m_FirstSelectedObject = NULL;
}

/** Destructor */
BB_AbstractTool::~BB_AbstractTool()
{}

/**
 * Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
 * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
 * @param overX Gibt an, ob der Mauszeiger horizontal außerhalb der Arbeitsfläche ist (true).
 * @param overY Gibt an, ob der Mauszeiger vertikal außerhalb der Arbeitsfläche ist (true).
 * @author Alex Letkemann
 */
void BB_AbstractTool::move( QMouseEvent* me, bool overX, bool overY )
{
    overX = false;
    overY = false;
    me->ignore();
}

/**
 * Wird aufgerufen, wenn eine Maustaste los gelassen wird.
 * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
 * @author Alex	Letkemann
 */
void BB_AbstractTool::release( QMouseEvent* me )
{
    me->ignore();
}


/**
 * Löscht das übergeben Objekt aus dem Objekt-Vektor.
 * @param delObject Objekt, welches gelöscht werden soll.
 * @return Gibt true zurück, wenn das Objekt erfolgreich gelöscht werden konnte, False wenn das Objekt nicht gefunden wurde.
 * @author Alex Letkemann
 */
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
                //                 if ( typeid( *( m_Objects->at( i ) ) ) == typeid( BB_Point ) ||
                // 					 typeid( *( m_Objects->at( i ) ) ) == typeid( BB_TerrainPoint ) ||
                // 					 typeid( *( m_Objects->at( i ) ) ) == typeid( BB_NavigationPoint ))
                if ( dynamic_cast< BB_Point* >( m_Objects->at( i ) ) )
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
 * Gibt den Transformer zurück, der gerade verwendet wird.
 * @return Transformer, der gerade verwendet wird.
 * @author Alex Letkemann
 */
BB_Transformer* BB_AbstractTool::getTransformer() const
{
    return m_Transformer;
}


/**
 * Setzt den Trasformer, der bei der Bearbeitung verwendet werden Soll.
 * @param transformer Trasformer, der bei der Bearbeitung verwendet werden Soll.
 * @author Alex Letkemann
 */
void BB_AbstractTool::setTransformer( BB_Transformer* transformer )
{
    m_Transformer = transformer;
}

/**
 * Gibt den Selektions-Vektor zurück.
 * @return Selektions-Vektor.
 * @author Alex Letkemann
 */
QVector<BB_DrawObject*>* BB_AbstractTool::getSelectionVector() const
{
    return m_Selection;
}


/**
 * Setzt den Selektions-Vektor
 * @param selectionVector Selektions-Vektor
 * @author Alex Letkemann
 */
void BB_AbstractTool::setSelectionVector( QVector<BB_DrawObject*>* selectionVector )
{
    if ( selectionVector != NULL )
    {
        m_Selection = selectionVector;
        if ( m_ToolWidget != NULL )
        {
            getToolWidget() ->setSelection( m_Selection );
        }
    }

    else
    {
        cout << "BB_AbstractTool::setSelectionVector(): Übergebener Pointer ist NULL\n Auswahl-Vektor wurde nicht gesetzt." << endl;
    }
}

/**
 * Gibt den Tool-Vektor zurück.
 * @return Tool-Vektor.
 * @author Alex Letkemann
 */
QVector< BB_DrawObject * >* BB_AbstractTool::getToolObjects() const
{
    return m_ToolObjects;
}

/**
 * Setzt den Tool-Vektor.
 * @param theValue Tool-Vektor.
 * @author Alex Letkemann
 */
void BB_AbstractTool::setToolObjects( QVector< BB_DrawObject * >* theValue )
{
    m_ToolObjects = theValue;
}


/**
 * Deselektiert alle Objekte (Leert den Selektions-Vektor).
 * @author Alex Letkemann
 */
void BB_AbstractTool::clearSelection()
{

    for ( int i = 0; i < m_Selection->count(); i++ )
    {
        m_Selection->at( i ) ->setSelected( false );
    }

    m_Selection->clear();
    m_FirstSelectedObject = NULL;
}

/**
 * Gibt die QAction des Tools zurück.
 * @return QAction des Tools.
 * @author Alex Letkemann
 */
QAction* BB_AbstractTool::getAction()
{
    return m_Action;
}

/**
 * Setzt die QAction des Tools.
 * @param theValue QAction des Tools.
 * @author Alex Letkemann
 */
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
 * Setzt das Tool in seinen Ausgangs-Status
 * @author Alex Letkemann
 */
void BB_AbstractTool::reset()
{
    if ( m_ToolWidget != NULL )
    {
        m_ToolWidget->updateWidget();
    }
}


/**
 * Sucht und gibt das Objekt zurück, welches sich an der übergebenen, logischen Position 'posLogic' befindet und vom Typ 'type' ist.
 * @param posLogic Logische Position, an der gesucht wird.
 * @param type Typ des Objektes, nach welchem gesucht wird. Der Typ wird mit typeid(Klasse) erzeugt. 
 * @return Pointer auf das erste an der Position gefundes Objekt, oder NULL wenn kein Objekt gefunden wurde.
 * @author Alex Letkemann
 */
BB_DrawObject* BB_AbstractTool::getClickedObject( const C2dVector &posLogic , const std::type_info &type )
{

    /// todo Fehler abfangen
    BB_DrawObject * object = NULL;
    bool exit = false;
    for ( int i = 0; i < m_Objects->count() && exit == false; i++ )
    {
        object = m_Objects->at( i );
        //         if ( typeid( object ) == typeid( BB_Point ) )
        //         {
        //             ( ( BB_Point* ) object ) ->setScale( m_Transformer->getScale() );
        //--------zur presentation
        ///@todo das muss irgentwie anders geloest werden
        if ( object->getClassName() == "BB_Point" )
        {
            ( ( BB_Point * ) object ) ->setScale( m_Transformer->getScale() );
            //---------ende-----------
        }
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
 * Gibt das DocComponent zurück, welches gerade bearbeitet wird.
 * @return DocComponent, welches gerade bearbeitet wird.
 * @author Alex Letkemann
 */
BB_DocComponent* BB_AbstractTool::getDocComponent() const
{
    return m_Component;
}


/**
 * Setzt das DocComponent, welches bearbeitet werden soll.
 * @param theValue DocComponent, welches bearbeitet werden soll.
 * @author Alex Letkemann
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

/**
 * Setzt, den Objekt-Vektor.
 * @param objects Objekt-Vektor.
 * @author Alex Letkemann
 */
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
 * Gibt den Status zurück, ob die Objekte auf der Arbeitsfläche angezeigt werden sollen.
 * @return Status, ob die Objekte auf der Arbeitsfläche angezeigt werden sollen.
 * @author Alex Letkemann
 */
bool BB_AbstractTool::getShowDrawObjects()
{
    return m_ShowDrawObjects;
}




/**
 * Gibt das Eigenschftsfenster des Tools zurück.
 * @return Eigenschftsfenster des Tools.
 * @author Alex Letkemann
 */
BB_AbstractToolWidget* BB_AbstractTool::getToolWidget()
{
    return m_ToolWidget;
}


/**
 * Setzt die Arbeitsfläche, auf welcher das Tool arbeitet.
 * @param value Arbeitsfläche, auf welcher das Tool arbeitet.
 * @author Alex Letkemann
 */
void BB_AbstractTool::setWorkFrame( BB_WorkFrame* value )
{
    m_WorkFrame = value;
}


/**
 * Wird aufgerufen, wenn das Dokument sich ändert.
 * @author Alex Letkemann
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
 * Aktualisiert das Eigenschftsfenster.
 * @author Alex Letkemann
 */
void BB_AbstractTool::updateWidget()
{
    if ( m_ToolWidget != NULL )
    {
        m_ToolWidget->updateWidget();
    }
}



/**
 * Löscht alle Selektierten Objekte, die Im Selektions-Vektor sind.
 * @author Alex Letkemann
 */
void BB_AbstractTool::deleteSelection()
{
    if ( m_Selection != NULL )
    {
        for ( int i = m_Selection->count() - 1 ; i >= 0; i-- )
        {
            deleteObject( m_Selection->at( i ) );
            m_Selection->remove( i );
        }
    }

    documentChanged();
}


/**
 * Gibt das Icon des Tools zurück.
 * @return Icon des Tools.
 * @author Alex Letkemann.
 */
QIcon BB_AbstractTool::getIcon() const
{
    return m_Icon;
}


/**
 * Setzt das Icon des Tools.
 * @param value Icon des Tools.
 * @author Alex Letkemann
 */
void BB_AbstractTool::setIcon( const QIcon& value )
{
    m_Icon = value;
}


/**
 * Selektiert das übergebene Objekt.
 * @param object Objekt, welches Selektiert werden soll.
 * @author Alex Letkemann
 */
void BB_AbstractTool::selectObject( BB_DrawObject * object )
{
    if ( m_Selection != NULL )
    {
        object->setSelected( true );
        m_Selection->append( object );
    }
}

// //TODO
// void BB_AbstractTool::setScaleHeight( double Value )
// {
//     m_ScaleHeight = Value;
// }

// //TODO
// void BB_AbstractTool::setScaleWidth( double Value )
// {
//     m_ScaleWidth = Value;
// }
