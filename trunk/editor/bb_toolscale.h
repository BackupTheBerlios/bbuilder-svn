//
// C++ Interface: bb_toolscale
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLSCALE_H
#define BB_TOOLSCALE_H

#include <bb_abstracttool.h>
#include <QWidget>

/**
 * Werkzeug zum Einstellen von Maßstäben in den DocComponents.<br>
 * Der Maßstab wird durch zwei Punkte gebildet, 
 * dabei wird der logische Abstand zwischen den Punkten berechnet und mit dem reelem Abstand, 
 * der über das Werkzeug-Fenster eingegeben werden kann ins Verhältnis gesetzt.
 * Mit dem Werkzeug lassen sich die Punkte verschieben und somit die logische Entfernung verändern.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_ToolScale : public BB_AbstractTool
{
    public:
        /**
         * Konstruktor
         */
        BB_ToolScale( QWidget* parent = 0 );

        /**
         * Destruktor
         */
        ~BB_ToolScale();

        /**
         * \fn click(QMouseEvent* me)
         */
        virtual void click( QMouseEvent* me );

        /**
         * Bewegt den Angeclickten Punkt.
         * @see virtual void BB_AbstractTool::move(QMouseEvent* me, bool overX, bool overY)
         */
        virtual void move( QMouseEvent* me, bool overX, bool overY );

        /**
         * \fn release(QMouseEvent* me)
         */
        virtual void release( QMouseEvent* me );

        /**
         * \fn setDocComponent( BB_DocComponent* component )
         */
        virtual void setDocComponent( BB_DocComponent* component );

        /**
         * \fn reset()
         */
        virtual void reset();

        /**
         *  \fn updateWidget()
         */
        virtual void updateWidget();

        /**
         * \fn getToolWidget()
         */
        virtual BB_AbstractToolWidget* getToolWidget();
    protected:
        BB_Point* m_MovePoint;
        BB_Line* m_ScaleLine;
        QWidget* m_Parent;
        C2dVector m_Tmp_v1;
        C2dVector m_Tmp_v2;
    private:
        /**
         * Gibt die logische Entfernung zurück
         * @return logische Entfernung
         * @author Alex Letkemann
         */
        double getLogicalScale();

};

#endif
