//
// C++ Interface: bb_dlgleveledit
//
// Description: 
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef BB_DLGLEVELEDIT_H
#define BB_DLGLEVELEDIT_H

#include <ui_levelEdit.h>
#include <QDialog>

/**
 * Dialog zum Bearbeiten von Etagen.
 * Mit dem Dialog lassen sich der Name, die Beschreibung und der Pfad zur Bilddatei ändern.
 * @author Alex Letkemann <alex@letkemann.de>
 */
class BB_DlgLevelEdit : public QDialog
{
Q_OBJECT
public:
	
	/** Konstruktor */
    BB_DlgLevelEdit( QWidget* parent );

	/** Destruktor */
    ~BB_DlgLevelEdit();
	
	
	/** Gibt die Beschreibung der Etage zurück */
    const QString getDescription() const;
    
	/** Gibt den Namen der Etage zurück */
	const QString getName() const;
	
	/** Gibt den Pfad zur Bilddatei zurück */
    const QString getPlanFile() const;
    
	/** Setzt die Beschreibung der Etage */
	void setDescription( const QString& desc );
	
	/** Setzt den Namen der Etage */
    void setName( const QString& name );
	
	/** Setzt den Pfad zur Bilddatei */
    void setPlanFile( const QString& file );

protected:
	/** Form */
	Ui::LevelEditDialog m_Dlg;
private slots:
	/** Ruft einen Datei-Dialog auf, mit dem man eine Bilddatei auswählen kann */
    void slotPlanFileSearch();
};

#endif
