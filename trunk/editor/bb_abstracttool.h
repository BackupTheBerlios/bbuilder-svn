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
#ifndef BB_ABSTRACTTOOL_H
#define BB_ABSTRACTTOOL_H

#include <QtGui>
#include <QAction>

#include <bb_globals.h>
#include <bb_doccomponent.h>

#include <bb_drawobject.h>
#include <bb_transformer.h>
#include <c2dvector.h>
#include <bb_abstracttoolwidget.h>

class BB_Tab;
class BB_WorkFrame;

/**
 * Abstrakte Basisklasse für die Tools.<br>
 * Jedes Tool besitzt eine eigene QAction, durch welche das Tool idendifiziert wird.<br>
 * Als weiteres besitzt jedes Tool ein Eigenschaftsfenster, durch welches das Tool eingestellt werden kann 
 * oder die Objekte manipuliert werden können.<br>.
 * Das Tool kennt mehrere Vektoren, mit denen es Abrbeitet. Die Vektoren sind:<br>
 * 1. Objekt-Vektor, welcher alle Objekte des Dokumentes Enthält. 
 * Dieser kann mit setDocComponent() gesetzt werden, oder separat mit setObjects().<br>.
 * 2. Selektions-Vektor, welcher die Pointer auf selektierten Objekte enthält.<br>
 * 3. Tool-Vektor, welches verschiedene Tool-Objekte (z.B. Maskierungs-Viereck) enthalten kann.<br><br>
 * Bei abgeletiteten Klassen muss die funktion <i>click( QMouseEvent* me )</i> implementiert werden.<br>
 * Die Klasse stellt eine vilezahl von Methoden bereit, die in allen Tools verwendet werden können.
 * @author Alex Letkemann
 */
class BB_AbstractTool
{
    public:

        /** Konstucktor */
        BB_AbstractTool( QWidget * parent );

        /** Destruktor */
        virtual ~BB_AbstractTool();

        /**
         * Die Methode wird aufgerufen, wenn die Maus bei beliebiger gedrückter Maustaste bewegt wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @param overX Gibt an, ob der Mauszeiger horizontal außerhalb der Arbeitsfläche ist (true).
         * @param overY Gibt an, ob der Mauszeiger vertikal außerhalb der Arbeitsfläche ist (true).
         * @author Alex Letkemann
         */
        virtual void move( QMouseEvent* me, bool overX, bool overY );


        /**
         * Wird aufgerufen, wenn eine Maustaste los gelassen wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @author Alex	Letkemann
         */
        virtual void release( QMouseEvent* me );

        /**
         * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
         * @param me Qt-MouseEvent, welches weitere Informationen enthält. Siehe Qt-Dokumentation.
         * @author Alex Letkemann
         */
        virtual void click( QMouseEvent* me ) = 0;

        /**
         * Löscht das übergeben Objekt aus dem Objekt-Vektor.
         * @param delObject Objekt, welches gelöscht werden soll.
         * @return Gibt true zurück, wenn das Objekt erfolgreich gelöscht werden konnte, False wenn das Objekt nicht gefunden wurde.
         * @author Alex Letkemann
         */
        virtual bool deleteObject( BB_DrawObject * delObject );

        /**
         * Löscht alle Selektierten Objekte, die Im Selektions-Vektor sind.
         * @author Alex Letkemann
         */
        virtual void deleteSelection();

        /**
         * Setzt das Tool in seinen Ausgangs-Status
         * @author Alex Letkemann
         */
        virtual void reset();

        /**
         * Sucht und gibt das Objekt zurück, welches sich an der übergebenen, logischen Position 'posLogic' befindet und vom Typ 'type' ist.
         * @param posLogic Logische Position, an der gesucht wird.
         * @param type Typ des Objektes, nach welchem gesucht wird. Der Typ wird mit typeid(Klasse) erzeugt. 
         * @return Pointer auf das erste an der Position gefundes Objekt, oder NULL wenn kein Objekt gefunden wurde.
         * @author Alex Letkemann
         */
        virtual BB_DrawObject* getClickedObject( const C2dVector & posLogic , const std::type_info &type );

        /**
         * Setzt den Trasformer, der bei der Bearbeitung verwendet werden Soll.
         * @param transformer Trasformer, der bei der Bearbeitung verwendet werden Soll.
         * @author Alex Letkemann
         */
        virtual void setTransformer( BB_Transformer* transformer );

        /**
         * Gibt den Transformer zurück, der gerade verwendet wird.
         * @return Transformer, der gerade verwendet wird.
         * @author Alex Letkemann
         */
        virtual BB_Transformer* getTransformer() const;

        /**
         * Setzt den Selektions-Vektor
         * @param selectionVector Selektions-Vektor
         * @author Alex Letkemann
         */
        virtual void setSelectionVector( QVector<BB_DrawObject*>* selectionVector );

        /**
         * Gibt den Selektions-Vektor zurück.
         * @return Selektions-Vektor.
         * @author Alex Letkemann
         */
        virtual QVector<BB_DrawObject*>* getSelectionVector() const;

        /**
         * Setzt den Tool-Vektor.
         * @param theValue Tool-Vektor.
         * @author Alex Letkemann
         */
        virtual void setToolObjects( QVector< BB_DrawObject * >* theValue );

        /**
         * Gibt den Tool-Vektor zurück.
         * @return Tool-Vektor.
         * @author Alex Letkemann
         */
        virtual QVector< BB_DrawObject * >* getToolObjects() const;

        /**
         * Deselektiert alle Objekte (Leert den Selektions-Vektor).
         * @author Alex Letkemann
         */
        virtual void clearSelection();

        /**
         * Setzt die QAction des Tools.
         * @param theValue QAction des Tools.
         * @author Alex Letkemann
         */
        virtual void setAction( QAction* theValue );

        /**
         * Gibt die QAction des Tools zurück.
         * @return QAction des Tools.
         * @author Alex Letkemann
         */
        virtual QAction* getAction();

        /**
         * Setzt das DocComponent, welches bearbeitet werden soll.
         * @param theValue DocComponent, welches bearbeitet werden soll.
         * @author Alex Letkemann
         */
        virtual void setDocComponent( BB_DocComponent* theValue );

        /**
         * Gibt das DocComponent zurück, welches gerade bearbeitet wird.
         * @return DocComponent, welches gerade bearbeitet wird.
         * @author Alex Letkemann
         */
        virtual BB_DocComponent* getDocComponent() const;

        /**
         * Setzt, den Objekt-Vektor.
         * @param objects Objekt-Vektor.
         * @author Alex Letkemann
         */
        virtual void setObjects( QVector<BB_DrawObject*>* objects );

        /**
         * Gibt den Status zurück, ob die Objekte auf der Arbeitsfläche angezeigt werden sollen.
         * @return Status, ob die Objekte auf der Arbeitsfläche angezeigt werden sollen.
         * @author Alex Letkemann
         */
        virtual bool getShowDrawObjects();

        /**
         * Gibt das Eigenschftsfenster des Tools zurück.
         * @return Eigenschftsfenster des Tools.
         * @author Alex Letkemann
         */
        virtual BB_AbstractToolWidget* getToolWidget();

        /**
         * Setzt die Arbeitsfläche, auf welcher das Tool arbeitet.
         * @param value Arbeitsfläche, auf welcher das Tool arbeitet.
         * @author Alex Letkemann
         */
        virtual void setWorkFrame( BB_WorkFrame* value );

        /**
         * Aktualisiert das Eigenschftsfenster.
         * @author Alex Letkemann
         */
        virtual void updateWidget();

        /**
         * Wird aufgerufen, wenn das Dokument sich ändert.
         * @author Alex Letkemann
         */
        virtual void documentChanged();

        /**
         * Setzt das Icon des Tools.
         * @param value Icon des Tools.
         * @author Alex Letkemann
         */
        void setIcon( const QIcon& value );

        /**
         * Gibt das Icon des Tools zurück.
         * @return Icon des Tools.
         * @author Alex Letkemann.
         */
        QIcon getIcon() const;

        /**
         * Selektiert das übergebene Objekt.
         * @param object Objekt, welches Selektiert werden soll.
         * @author Alex Letkemann
         */
        virtual void selectObject( BB_DrawObject * object );

        void setScaleHeight( double Value );
        void setScaleWidth( double Value );





    protected:
        /** Die Position des letzten Mausclickes */
        C2dVector m_LastLogicMouseClick;

        /** Das ElternFenster */
        QWidget * m_ParentWidget;

        /** QAction des Tools */
        QAction * m_Action;

        /** Arbeitsfläche */
        BB_WorkFrame* m_WorkFrame;

        /** Hilfsvariablen */
        C2dVector m_pLogic;
        QPoint m_pScreen;

        /** Vektor mit Objekten, die bearbeitet werden sollen. */
        QVector<BB_DrawObject*>* m_Objects;

        /** Vektor mit Selektierten Objekten */
        QVector<BB_DrawObject*>* m_Selection;

        /** Transformer, der bei der Bearbeitung verwendet wird. */
        BB_Transformer* m_Transformer;

        /** Zu zeichende Objecte, die zum Ausgewaeltem tool gehoeren*/
        QVector<BB_DrawObject*>* m_ToolObjects;

        /** Pointer auf das DocComponent, mit welchem gearbeitet wird */
        BB_DocComponent * m_Component;

        /** Status, ob die Objekte auf der Arbeitsfläche angezeigt werden sollen */
        bool m_ShowDrawObjects;

        /** Das Eigenschftsfenster */
        BB_AbstractToolWidget* m_ToolWidget;

        /** Icon des Tools */
        QIcon m_Icon;

        /** Link auf ein Object der als erster selectiert wurde*/
        BB_DrawObject * m_FirstSelectedObject;

        /** Factor zum Scalieren */
        double m_ScaleHeight;
        double m_ScaleWidth;


};

#endif
