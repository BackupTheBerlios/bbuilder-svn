/***************************************************************************
 *   Copyright (C) 2005 by Vaceslav Ustinov                                *
 *   v.ustinov@web.de                                                      *
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
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "bb_dlgopentexture.h"

#include <QFileDialog>

BB_DlgOpenTexture::BB_DlgOpenTexture(QWidget * parent, Qt::WFlags f)
 : QDialog(parent, f)
{
	m_Dlg.setupUi( this);

	connect(m_Dlg.buttonShowDir,SIGNAL(clicked()), this, SLOT(slotTextureFileSearch()));
}


BB_DlgOpenTexture::~BB_DlgOpenTexture()
{
}




/*!
    \fn BB_DlgOpenTexture::slotTextureFileSearch()
 */
void BB_DlgOpenTexture::slotTextureFileSearch()
{
	QString filename;
	filename = QFileDialog::getOpenFileName(	this,
			QString::fromUtf8("Öffnen"),
			m_Dlg.lineEditPfad->text(),
			"Images (*.png *.bmp *.jpg)");
	if(!filename.isEmpty())
	{
		m_Dlg.lineEditPfad->setText(filename);
	}
}



QString BB_DlgOpenTexture::getTextureFile() const
{
	return m_Dlg.lineEditPfad->text();;
}

void BB_DlgOpenTexture::setTextureFile(QString pfad){
	m_Dlg.lineEditPfad->setText(pfad);
}
