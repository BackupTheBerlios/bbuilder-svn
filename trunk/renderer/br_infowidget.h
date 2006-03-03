//
// C++ Interface: br_infowidget
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BR_INFOWIDGET_H
#define BR_INFOWIDGET_H

#include <QWidget>

#include <bb_doc.h>
#include <QtGui>

/**
 * Fenster zum anzeigen der Informationen
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BR_InfoWidget : public QWidget
{
public:
	/**
	 * Konstruktor
	 * @param doc Dokument
	 * @param parent Parent-Fenster, in der dieses Fenster plaziert wird.
	 * @param f Qt Fenster Flags
	 * @author Alex Letkemann
	 */
	BR_InfoWidget(BB_Doc * doc, QWidget * parent = 0, Qt::WFlags f = 0 );

	/** Destruktor */
    ~BR_InfoWidget();
	
	
    /**
     * Stelt die Anzahl der Bilder pro Sekunde in unteren Bereich des Fensters dar.
     * @param fps Anzahl der Bilder pro Sekunde
	 * @author Alex Letkemann
     */
    void printFPS(int fps);
	
	
    /**
     * Setzt den Text in den Informationsbereich.
     * @param text Text
	 * @author Alex Letkemann
     */
    void setText( QString& text );

protected:
	/** Textfeld für die Informationen */
    QTextEdit* m_Text;
	
	/** Label für die FPS */
    QLabel* m_FpsLabel;
};

#endif
