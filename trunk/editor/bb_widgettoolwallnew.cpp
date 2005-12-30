//
// C++ Implementation: bb_widgettoolwallnew
//
// Description:
//
//
// Author: Alex Letkemann <alex@letkemann.de>, (C) 2005
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "bb_widgettoolwallnew.h"
#include <bb_wall.h>
#include <bb_abstracttool.h>

BB_WidgetToolWallNew::BB_WidgetToolWallNew( BB_AbstractTool* parentTool, QWidget* parent ) : BB_AbstractToolWidget( parentTool, parent )
{
    m_Ui.setupUi( this );


    connect( m_Ui.lineEdit_WallName, SIGNAL( editingFinished() ), this, SLOT( slotNameFinished() ) );
    connect( m_Ui.textEdit_WallDesc, SIGNAL( textChanged() ), this, SLOT( slotDescFinished() ) );

    connect( m_Ui.pushButton_Swap, SIGNAL( released() ), this, SLOT( slotSwap() ) );
    connect( m_Ui.pushButton_Edit, SIGNAL( released() ), this, SLOT( slotEdit() ) );
    connect( m_Ui.pushButton_Delete, SIGNAL( released() ), this, SLOT( slotDelete() ) );

    setWidgetEnabled( false );
}


BB_WidgetToolWallNew::~BB_WidgetToolWallNew()
{}


void BB_WidgetToolWallNew::clearWidget()
{
    m_Ui.lineEdit_WallName->clear();
    m_Ui.textEdit_WallDesc->clear();
    m_Ui.label_Pos1->clear();
    m_Ui.label_Pos2->clear();
}

void BB_WidgetToolWallNew::setWidgetEnabled( bool value )
{
    m_Ui.lineEdit_WallName->setEnabled( value );
    m_Ui.textEdit_WallDesc->setEnabled( value );

    m_Ui.pushButton_Delete->setEnabled( value );
    m_Ui.pushButton_Edit->setEnabled( value );
    m_Ui.pushButton_Swap->setEnabled( value );
}

void BB_WidgetToolWallNew::updateWidget()
{
    BB_Wall * tmpWall;

    if ( m_Selection != NULL &&
            m_Selection->count() == 1 &&
            typeid( *( m_Selection->at( 0 ) ) ) == typeid( BB_Wall ) )
    {
        tmpWall = ( BB_Wall* ) m_Selection->at( 0 );

        m_Ui.lineEdit_WallName->setText( tmpWall->getName() );
        m_Ui.textEdit_WallDesc->setPlainText( tmpWall->getDescription() );

        m_Tmp_DrawObject = tmpWall->getPos1();
        if ( m_Tmp_DrawObject != NULL )
        {
            m_Ui.label_Pos1->setText( m_Tmp_DrawObject->getName() + " (" + QString::number( m_Tmp_DrawObject->getObjectNr() ) + ")" );
        }

        m_Tmp_DrawObject = tmpWall->getPos2();
        if ( m_Tmp_DrawObject != NULL )
        {
            m_Ui.label_Pos2->setText( m_Tmp_DrawObject->getName() + " (" + QString::number( m_Tmp_DrawObject->getObjectNr() ) + ")" );
        }

        setWidgetEnabled( true );
    }
    else
    {
        clearWidget();
        setWidgetEnabled( false );
    }
}



/*!
    \fn BB_WidgetToolWallNew::slotDelete()
 */
void BB_WidgetToolWallNew::slotDelete()
{
    m_ParentTool->deleteSelection();
}


/*!
    \fn BB_WidgetToolWallNew::slotDescFinished()
 */
void BB_WidgetToolWallNew::slotDescFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setDescription( m_Ui.textEdit_WallDesc->toPlainText() );
        m_ParentTool->documentChanged();
    }
}


/*!
    \fn BB_WidgetToolWallNew::slotNameFinished()
 */
void BB_WidgetToolWallNew::slotNameFinished()
{
    if ( m_Selection != NULL && m_Selection->count() == 1 )
    {
        m_Tmp_DrawObject = m_Selection->at( 0 );
        m_Tmp_DrawObject->setName( m_Ui.lineEdit_WallName->text() );
        m_ParentTool->documentChanged();
    }
}


/*!
    \fn BB_WidgetToolWallNew::slotSwap()
 */
void BB_WidgetToolWallNew::slotSwap()
{
    BB_Wall * wall = ( BB_Wall * ) m_Selection->at( 0 );
    wall->swap();

    m_ParentTool->documentChanged();
}


/*!
    \fn BB_WidgetToolWallNew::slotEdit()
 */
void BB_WidgetToolWallNew::slotEdit()
{
    BB_Wall * wall = ( BB_Wall * ) m_Selection->at( 0 );
    wall->editDlg( m_ParentTool->getDocComponent() );
}
