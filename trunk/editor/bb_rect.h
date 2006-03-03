//
// C++ Interface: bb_rect
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_RECT_H
#define BB_RECT_H

#include <bb_line.h>

/**
 * Stellt einen Recheck dar. Das Rechteck wird zwischen zwei Punkten P1 und P2 gespannt.
 * Das Rechteck selber speichert keine Koordinaten und hängt somit komplett von den beiden Punkten ab.
 * Wenn sich die Position der Punkte ändert, ändert sich auch die Position bzw. die Größe des Rechecks.
 *
 * p1 ___________
 *  |           |
 *  |___________| p2
 *  
 * @author Alex Letkemann
 * @date 26.10.2005
*/
class BB_Rect : public BB_Line
{
public:
	
	/**
     * Konstruktor
     * Erstellt ein leeres Rechteck, welchem die beiden Punkte erst noch zugewiesen werden müssen.
     * @author Alex Letkemann
	 */
	BB_Rect();
	
	/**
	 * Konstruktor
	 * Erstellt einen <i>dynamischen</i> Rechteck. D.h. wenn sich die Positionen der übergeben Punkte ändern,
	 * ändert sich auch die Position bzw. die Größe des Rechtecks.
	 * @param p1 Position des ersten Punktes.
	 * @param p2 Position des zweiten, <b>quer gegenüber liegenden</b> Punktes.
	 * @author Alex Letkemann
	 */
	BB_Rect(BB_Point* p1, BB_Point* p2);

	/** Destruktor */
    ~BB_Rect();
	
	/**
	 * Gibt den Klassennamen zurück
	 * @return Klassenname
	 */
    virtual const QString getClassName();
	
	/**
	 * Zeichnet den Rechteck auf der Arbeitsfläche
	 * @param transformer Transformer, welcher benutzt werden soll.
	 * @param painter Painter, mit welchem gezeichnet werden soll.
	 */
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
	
	/**
	 * Prüft, ob der Rechteck angeclickt wurde.
	 * @param hit Position, an der geprüft werden soll.
	 * @return Wenn angeclickt true, sonst false.
	 * @author Alex Letkemann
	 */
    bool isHit(const C2dVector &hit);
	
	/**
	 * Bewegt den Rechteck um den übergebenen Vektor
	 * @param pMove Vektor, um den der Rechteck bewegt werden soll.
	 * @author Alex Letkemann
	 */
	virtual void moveBy( C2dVector pMove );

};

#endif
