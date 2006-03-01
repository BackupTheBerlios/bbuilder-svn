/***************************************************************************
 *   Copyright (C) 2005 by Alex Letkemann   *
 *   alex@letkemann.de   *
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
 ***************************************************************************/
#ifndef BB_DLGPROJECTNEW_H
#define BB_DLGPROJECTNEW_H

#include <QDialog>
#include <QDir>
#include "ui_projectNew.h"

/**
 * Dialog zum Erstellen eines neuen Projektes.<br />
 * Im Dialog lassen sich der Name, die Beschreibung und das Verzeichnis, in welchem der Projekt erstellt werden soll, angeben.
 * Der Projektname muss mit einem Buchstaben beginen und darf keine Sonderzeichen enthalten.
 * Im angegeben Verzeichnis darf kein Projekt mit dem angegebenen Namen existieren.
 * @author Alex Letkemann
 */
class BB_DlgProjectNew : public QDialog
{
	Q_OBJECT
	
public:
	/** Konstruktor */
	BB_DlgProjectNew(QWidget * parent = 0, Qt::WFlags f = 0);

	/** Destruktor */
    ~BB_DlgProjectNew();

	/** Gibt den Projekt-Verzeichnis-Namen zurück */
	QString getProjectDir() const;
	
	/** Gibt den Pfad zum Projekt-Verzeichnis zurück */
	QDir getProjectPath() const;
	
	/** Gibt den Projektnamen zurück */
	QString getProjectName() const;
	
	/** Gibt die Projektbeschreibung zurück */
	QString getProjectDescription() const;
	

private slots:
    
	/** Wird aufgerufen, wenn der 'Suchen'-Button gedrückt wird */
	void slotShowDir();
	
	/** Wird aufgerufen, wenn das Verzeichnis geändert wird */
	void slotPathChanged(const QString & text);
	
	/** Wird aufgerufen, wenn der Name geändert wird */
	void slotNameChanged(const QString & text);
    
	/** Wird aufgerufen, wenn die Beschreibung geändert wird */
	void slotDescChanged();
	
protected:
    Ui_ProjectNewDialog m_Dlg;
	
    QDir m_Dir;
    QString m_ProjectPath;
    QString m_ProjectDir;
    QString m_ProjectName;
	QString m_ProjectDescription;
	
private:
	/** Prüft, ob das angegebene Verzeichnis gültig ist. */
    void checkDir();
};

#endif
