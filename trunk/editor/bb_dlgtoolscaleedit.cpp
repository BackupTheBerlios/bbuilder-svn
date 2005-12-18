//
// C++ Implementation: bb_dlgtoolscaleedit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_dlgtoolscaleedit.h"
#include <QRegExpValidator>

#include <iostream>


using namespace std;


BB_DlgToolScaleEdit::BB_DlgToolScaleEdit( QWidget * parent )
	: QDialog(parent)
{
	m_Dlg.setupUi(this);
	
	m_Dlg.lineEditScaleReal->setValidator(new QRegExpValidator(QRegExp("[0-9.]+"), this ));
}


BB_DlgToolScaleEdit::~BB_DlgToolScaleEdit()
{
}




/**
 * Gibt den eingegebenen reellen Maßstab zurück
 */
double BB_DlgToolScaleEdit::getScaleReal()
{
	bool ok;
	double value = QString( m_Dlg.lineEditScaleReal->text() ).toDouble(&ok);
	
	cout <<  value << endl;
	if (ok)
	{
		return value;
	}
	else
	{
		return 1;
	}
}


/**
 * Gibt ein angezeigten logischen Maßstab zurück
 */
double BB_DlgToolScaleEdit::getScaleLogic()
{
	bool ok;
	double value = QString( m_Dlg.lineEditScaleLogic->text() ).toDouble(&ok);
	if (ok)
	{
		return value;
	}
	else
	{
		return 1;
	}
}


/**
 * Setzt den logischen Maßstab zurück
 */
void BB_DlgToolScaleEdit::setScaleLogic( double scale )
{
	m_Dlg.lineEditScaleLogic->setText( QString::number( scale ) );
}


/**
 * Setzt den reellen Maßstab zurück
 */
void BB_DlgToolScaleEdit::setScaleReal( double scale )
{
	m_Dlg.lineEditScaleReal->setText( QString::number( scale ));
}
