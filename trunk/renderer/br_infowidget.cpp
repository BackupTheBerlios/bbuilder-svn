//
// C++ Implementation: br_infowidget
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "br_infowidget.h"

#include <QtGui>

BR_InfoWidget::BR_InfoWidget( BB_Doc * doc,  QWidget * parent, Qt::WFlags f )
 : QWidget(parent, f)
{
	
	if( doc == NULL )
	{
		qDebug() << "Kritischer Programmfehler" <<  endl;
		exit(1);
	}
	
	m_FpsLabel = NULL;
	
	m_Text = new QTextEdit();
	m_Text->setFrameShape ( QFrame::Box );
	m_Text->setReadOnly( true );
	
	m_Text->setHtml("test");
	
	QVBoxLayout *outerLayout = new QVBoxLayout();
	QVBoxLayout *innerLayout = new QVBoxLayout();
	
	outerLayout->setMargin(0);
	outerLayout->setSpacing(5);
	
	innerLayout->setMargin(0);
	innerLayout->setSpacing(5);
	
	m_FpsLabel = new QLabel();
	m_FpsLabel->setText("FPS: 0");
	
	QGroupBox *groupBox = new QGroupBox(NULL);
	groupBox->setFlat(true);
	groupBox->setTitle(QString::fromUtf8("Information"));
	groupBox->setLayout( innerLayout );
	
	innerLayout->addWidget( m_Text );
	innerLayout->addWidget( m_FpsLabel );
	
	outerLayout->addWidget(groupBox);
	
	setLayout( outerLayout );
}


BR_InfoWidget::~BR_InfoWidget()
{
}




/**
 * Schreibt die Frameanzahl in das Label 'm_FpsLabel'
 */
void BR_InfoWidget::printFPS(int fps)
{
	m_FpsLabel->setText( "FPS: " + QString::number(fps) );
}
