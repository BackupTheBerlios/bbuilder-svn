#ifndef UI_NEWPROJECT_H
#define UI_NEWPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

class Ui_NewProjectDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget_2;
    QWidget *widget;
    QGridLayout *gridLayout1;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *textEditProjectDesc;
    QLabel *label_2;
    QLineEdit *lineEditProjectName_2;
    QHBoxLayout *hboxLayout;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *NewProjectDialog)
    {
    NewProjectDialog->setObjectName(QString::fromUtf8("NewProjectDialog"));
    NewProjectDialog->resize(QSize(500, 300).expandedTo(NewProjectDialog->minimumSizeHint()));
    QSizePolicy sizePolicy((QSizePolicy::Policy)0, (QSizePolicy::Policy)0);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(NewProjectDialog->sizePolicy().hasHeightForWidth());
    NewProjectDialog->setSizePolicy(sizePolicy);
    gridLayout = new QGridLayout(NewProjectDialog);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(8);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    groupBox = new QGroupBox(NewProjectDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    layoutWidget_2 = new QWidget(groupBox);
    layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
    layoutWidget_2->setGeometry(QRect(10, 30, 421, 25));
    widget = new QWidget(groupBox);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(11, 30, 203, 25));
    gridLayout1 = new QGridLayout(groupBox);
    gridLayout1->setSpacing(6);
    gridLayout1->setMargin(8);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setFrameShape(QFrame::Panel);
    label_5->setFrameShadow(QFrame::Sunken);

    gridLayout1->addWidget(label_5, 3, 0, 1, 2);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout1->addWidget(label_3, 1, 0, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout1->addWidget(label_4, 2, 0, 1, 1);

    textEditProjectDesc = new QTextEdit(groupBox);
    textEditProjectDesc->setObjectName(QString::fromUtf8("textEditProjectDesc"));

    gridLayout1->addWidget(textEditProjectDesc, 1, 1, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout1->addWidget(label_2, 0, 0, 1, 1);

    lineEditProjectName_2 = new QLineEdit(groupBox);
    lineEditProjectName_2->setObjectName(QString::fromUtf8("lineEditProjectName_2"));

    gridLayout1->addWidget(lineEditProjectName_2, 0, 1, 1, 1);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    lineEdit = new QLineEdit(groupBox);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    hboxLayout->addWidget(lineEdit);

    toolButton = new QToolButton(groupBox);
    toolButton->setObjectName(QString::fromUtf8("toolButton"));

    hboxLayout->addWidget(toolButton);


    gridLayout1->addLayout(hboxLayout, 2, 1, 1, 1);


    gridLayout->addWidget(groupBox, 0, 0, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout1->addItem(spacerItem);

    okButton = new QPushButton(NewProjectDialog);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout1->addWidget(okButton);

    cancelButton = new QPushButton(NewProjectDialog);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout1->addWidget(cancelButton);


    gridLayout->addLayout(hboxLayout1, 1, 0, 1, 1);

    retranslateUi(NewProjectDialog);
    QObject::connect(okButton, SIGNAL(clicked()), NewProjectDialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), NewProjectDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(NewProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *NewProjectDialog)
    {
    NewProjectDialog->setWindowTitle(QApplication::translate("NewProjectDialog", "Neues Projekt erstellen"));
    groupBox->setTitle(QApplication::translate("NewProjectDialog", "Neues Projekt erstellen"));
    label_5->setText(QApplication::translate("NewProjectDialog", "TextLabel"));
    label_3->setText(QApplication::translate("NewProjectDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Beschreibung</p></body></html>"));
    label_4->setText(QApplication::translate("NewProjectDialog", "Pfad"));
    textEditProjectDesc->setStatusTip(QApplication::translate("NewProjectDialog", "Beschreibung des neuen Projektes"));
    label_2->setText(QApplication::translate("NewProjectDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Name</p></body></html>"));
    lineEditProjectName_2->setStatusTip(QApplication::translate("NewProjectDialog", "Name des neuen Projektes"));
    toolButton->setText(QApplication::translate("NewProjectDialog", "..."));
    okButton->setText(QApplication::translate("NewProjectDialog", "OK"));
    cancelButton->setText(QApplication::translate("NewProjectDialog", "Cancel"));
    Q_UNUSED(NewProjectDialog);
    } // retranslateUi

};

namespace Ui {
    class NewProjectDialog: public Ui_NewProjectDialog {};
} // namespace Ui

#endif // UI_NEWPROJECT_H
