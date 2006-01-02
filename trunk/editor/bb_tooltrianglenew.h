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
 * Tool zum Erzeugen von Triangles
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
	
	virtual void click(QMouseEvent* me);
	
	/**
	 * Setzt das Tool zurück.
	 * Falls es ein temporäres Triangle-Objekt bereits erstellt wurde, wird dieses gelöscht.
	 */
	virtual void reset();
	virtual BB_AbstractToolWidget* getToolWidget();

protected:
	
	BB_Point* m_P1;
	BB_Point* m_P2;
	BB_Point* m_P3;
protected:
    virtual BB_Point* getClickedPoint( C2dVector &pos);
	virtual BB_Triangle* createNewSurface();
};

#endif
