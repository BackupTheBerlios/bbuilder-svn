//
// C++ Interface: bb_triangle
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_TRIANGLE_H
#define BB_TRIANGLE_H

#include <bb_point.h>
#include <bb_line.h>

/**
 * Stellt ein Dreieck dar.
 * Das Dreieck wird durch drei Punkte beschrieben, welche in Form von Pointern übergeben werden.
 * Die Klasse selber speichert keine Informationen über die Punkte, sondern kennt nur die Pointer
 * auf die Punkte. Somit ist ein Objekt dieser Klasse abhängig von den jeweiligen Punkten und muss
 * gelöscht werden, bevor einer der drei Punkte gelöscht wird.
 * @author Alex Letkemann, Vaceslav Ustinov
 */
class BB_Triangle : public BB_Line
{
    public:
        /**
         * Konstruktor
        * Erstellt ein neues Dreieck mit den Übergebenen Punkten.
         * @param p1 Position des ersten Punktes
         * @param p2 Position des zweiten Punktes
         * @param p3 Position des dritten Punktes
        * @author Alex Letkemann
        * @date 12.12.2005
         */
        BB_Triangle( BB_Point* p1, BB_Point* p2, BB_Point* p3 );

        /**
         * Destruktor
         */
        ~BB_Triangle();


	
    /**
     * Prüft, ob das Dreieck innnerhald des angegebenen Rechteckes liegt.
     * @param rect Rechteck
     * @return True wenn das Dreieck komplet innerhalb des Rechteckes liegt, sonst false.
	 * @author Alex Letkemann
     */
    virtual bool isHit( const QRectF& rect);
	
	/**
	 * Prüft, ob das Dreieck auf der angegebenen Position liegt.
	 * @param hit Position, auf die geprüft werden soll.
	 * @return True, wenn das Dreieck auf der angegebenen Position liegt, sonst false.
	 */
	virtual bool isHit( const C2dVector& hit);
	
	/**
	 * @fn getClassName()
	 */
    virtual const QString getClassName();
	
	/**
	 * Wird aufgerufen, wenn das Dreieck bewegt oder verändert wird.
	 * @author Alex Letkemann
	 */
	virtual void moveEvent();
	
	/**
	 * Richtet die Punken so, dass Dreieck immer nach oben zeigt<br>
	 * Diese Funktion wird von Renderer benoetigt.
	 * @author Vaceslav Ustinov
	 */
	virtual void normalize();
	
	
    /**
     * Zeichnet das Dreieck auf der Arbeitsfläche.
     * @param transformer Transformer, der Benutzt werden soll.
     * @param painter Painter, der Benutzt werden soll.
	 * @author Alex Letkemann
     */
    virtual void show(BB_Transformer& transformer, QPainter& painter) const;
    
	/**
	 * Setzt die dritte Position (Ecke) der Trinagle.
	 * @param point Pointer auf einen Punkt. Wird auf NULL geprüft.
	 * @return False im Fehlerfall, sonst true
	 */
	bool setPos3(BB_Point* value);


	/**
	 * Gibt einen Pointer auf den Punkt der dritten Position zurück.
	 * @return Pointer auf den Punkt der dritten Position.
	 */
	BB_Point* getPos3() const;
	
	/**
	 * Erstellt ein BB_Triangle XML-Element und schreibt dieses in den out-Stream
	 * @param out Stream, in welchen das Element geschrieben wird.
	 * @param depth Tiefe der Einrückung
	 * @author Alex Letkemann
	 * @date 11.12.2005
	 */
    virtual void generateXElement(QTextStream &out, int depth);
	
	/** Pointer auf die dritte Position */
	BB_Point* m_Pos3;
	
protected:

        /**
        * Virtuelle Funktion für weitere abgeleitete Klassen.
        * @param triangles Vektor, an den die Dreiecke angehängt werden.
        * @param vector Positionsektor
        * @param rotation Rotation der Dreiecke
        * @param scale Skalierung der Dreiecke
        * @param height Hier keine Funktion
        * @author Alex Letkemann
        */
        virtual void createGl( QVector<C3dTriangle>& triangles, C3dVector vector, double rotation, double scale, double height );
};

#endif
