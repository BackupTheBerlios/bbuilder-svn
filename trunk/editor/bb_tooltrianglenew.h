//
// C++ Interface: bb_tooltrianglenew
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TOOLTRIANGLENEW_H
#define BB_TOOLTRIANGLENEW_H

#include <bb_abstracttool.h>
#include <bb_triangle.h>

/**
 * Tool zum Erzeugen von Dreieckecn.<br />
 * Ein Dreieck wird in drei Schritten erzeugt.<br />
 * Dabei müssen drei verschiedene Punkte nacheinander angeclick werden. Erst nach dem dritten Click wird das Dreieck erzeugt.
 *
 * @author Alex Letkemann
 */
class BB_ToolTriangleNew : public BB_AbstractTool
{
public:
    /**
     * Konstruktor
     */
	BB_ToolTriangleNew(QWidget *parent);

	
    /**
     * Destruktor 
     */
    ~BB_ToolTriangleNew();
	
	/**
	 * @fn BB_AbstractTool::click(QMouseEvent* me)
	 */
	virtual void click(QMouseEvent* me);
	
	/**
	 * @fn BB_AbstractTool::reset()
	 */
	virtual void reset();
	
	/**
	 * @fn BB_AbstractTool::getToolWidget()
	 */
	virtual BB_AbstractToolWidget* getToolWidget();

protected:
	
	BB_Point* m_P1;
	BB_Point* m_P2;
	BB_Point* m_P3;
	
protected:
	
    /**
     * Sucht und gibt den zuerst gefundenen Punkt an der übergebenen Position zurück.
     * @param pos Position, an der gesucht werden soll.
     * @return Punkt oder NULL
     * @author Alex Letkemann
     */
    virtual BB_Point* getClickedPoint( C2dVector &pos);
	
	/**
	 * Erzeugt ein neues Dreieck und gibt dieses zurück.
	 * @return Neues Dreieck.
	 * @author Alex Letkemann
	 */
	virtual BB_Triangle* createNewSurface();
};

#endif
