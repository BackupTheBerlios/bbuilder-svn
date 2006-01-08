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
Fenster zum anzeigen der Informationen

	@author Alex Letkemann <alex@letkemann.de>
*/
class BR_InfoWidget : public QWidget
{
public:
	BR_InfoWidget(BB_Doc * doc, QWidget * parent = 0, Qt::WFlags f = 0 );

    ~BR_InfoWidget();
    void printFPS(int fps);
    void setText( QString& text );

protected:
    QTextEdit* m_Text;
    QLabel* m_FpsLabel;
};

#endif
