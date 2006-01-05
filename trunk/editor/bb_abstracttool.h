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
@author Alex Letkemann
*/
class BB_AbstractTool
{
    public:
        BB_AbstractTool( QWidget * parent );

        virtual ~BB_AbstractTool();

        virtual void move( QMouseEvent* me, bool overX, bool overY );
        virtual void release( QMouseEvent* me );
        virtual void click( QMouseEvent* me ) = 0;

        virtual bool deleteObject( BB_DrawObject * delObject );
        virtual void deleteSelection();
        virtual void reset();
        virtual BB_DrawObject* getClickedObject( const C2dVector & posLogic , const std::type_info &type );

        virtual void setTransformer( BB_Transformer* transformer );
        virtual BB_Transformer* getTransformer() const;

        virtual void setSelectionVector( QVector<BB_DrawObject*>* selectionVector );
        virtual QVector<BB_DrawObject*>* getSelectionVector() const;

        virtual void setToolObjects( QVector< BB_DrawObject * >* theValue );


        virtual QVector< BB_DrawObject * >* getToolObjects() const;
        virtual void clearSelection();

        virtual void setAction( QAction* theValue );
        virtual QAction* getAction();


        virtual void setDocComponent( BB_DocComponent* theValue );
        virtual BB_DocComponent* getDocComponent() const;
        virtual void setObjects( QVector<BB_DrawObject*>* objects );
        virtual bool getShowDrawObjects();

        virtual BB_AbstractToolWidget* getToolWidget();

        virtual void setWorkFrame( BB_WorkFrame* value );
        virtual void updateWidget();
        virtual void documentChanged();

        void setIcon( const QIcon& value );
        QIcon getIcon() const;
        virtual void selectObject( BB_DrawObject * object );




    protected:

        C2dVector m_LastLogicMouseClick;
        C2dVector m_pLogic;
        QPoint m_pScreen;
        QWidget * m_ParentWidget;
        QAction * m_Action;

        BB_WorkFrame* m_WorkFrame;



        /** Vektor mit Objekten, die bearbeitet werden sollen. */
        QVector<BB_DrawObject*>* m_Objects;

        QVector<BB_DrawObject*>* m_Selection;

        /** Transformer, der bei der Bearbeitung verwendet wird. */

        BB_Transformer* m_Transformer;
        /** Zu zeichende Objecte, die zum Ausgewaeltem tool gehoeren*/
        QVector<BB_DrawObject*>* m_ToolObjects;

        /** Pointer auf das DocComponent, mit welchem gearbeitet wird */
        BB_DocComponent * m_Component;
        bool m_ShowDrawObjects;

        BB_AbstractToolWidget* m_ToolWidget;
        QIcon m_Icon;
		/** Link auf ein Object der als erster selectiert wurde*/
		BB_DrawObject * m_FirstSelectedObject;


};

#endif
