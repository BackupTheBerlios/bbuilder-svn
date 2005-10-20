#ifndef UI_PROJECTNEW_H
#define UI_PROJECTNEW_H

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

class Ui_ProjectNewDialog
{
public:
    QWidget *widget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QLabel *labelPath;
    QGridLayout *gridLayout;
    QLineEdit *lineEditFinalPath;
    QHBoxLayout *hboxLayout1;
    QLineEdit *lineEditProjectPath;
    QToolButton *buttonShowDir;
    QLabel *label_2;
    QLineEdit *lineEditProjectName;
    QTextEdit *textEditProjectDesc;
    QLabel *label_4;
    QLabel *label_4_2;
    QLabel *label_3;

    void setupUi(QDialog *ProjectNewDialog)
    {
    ProjectNewDialog->setObjectName(QString::fromUtf8("ProjectNewDialog"));
    ProjectNewDialog->resize(QSize(500, 400).expandedTo(ProjectNewDialog->minimumSizeHint()));
    QSizePolicy sizePolicy((QSizePolicy::Policy)0, (QSizePolicy::Policy)0);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(ProjectNewDialog->sizePolicy().hasHeightForWidth());
    ProjectNewDialog->setSizePolicy(sizePolicy);
    ProjectNewDialog->setContextMenuPolicy(Qt::NoContextMenu);
    ProjectNewDialog->setSizeGripEnabled(false);
    ProjectNewDialog->setModal(false);
    widget = new QWidget(ProjectNewDialog);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(9, 358, 482, 33));
    hboxLayout = new QHBoxLayout(widget);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(widget);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    cancelButton = new QPushButton(widget);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout->addWidget(cancelButton);

    groupBox = new QGroupBox(ProjectNewDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(9, 9, 482, 343));
    labelPath = new QLabel(groupBox);
    labelPath->setObjectName(QString::fromUtf8("labelPath"));
    labelPath->setGeometry(QRect(53, 315, 16, 17));
    QSizePolicy sizePolicy1((QSizePolicy::Policy)0, (QSizePolicy::Policy)0);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(labelPath->sizePolicy().hasHeightForWidth());
    labelPath->setSizePolicy(sizePolicy1);
    labelPath->setFrameShape(QFrame::NoFrame);
    labelPath->setFrameShadow(QFrame::Plain);
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(8);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    lineEditFinalPath = new QLineEdit(groupBox);
    lineEditFinalPath->setObjectName(QString::fromUtf8("lineEditFinalPath"));
    lineEditFinalPath->setReadOnly(true);

    gridLayout->addWidget(lineEditFinalPath, 3, 1, 1, 1);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setMargin(0);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    lineEditProjectPath = new QLineEdit(groupBox);
    lineEditProjectPath->setObjectName(QString::fromUtf8("lineEditProjectPath"));

    hboxLayout1->addWidget(lineEditProjectPath);

    buttonShowDir = new QToolButton(groupBox);
    buttonShowDir->setObjectName(QString::fromUtf8("buttonShowDir"));

    hboxLayout1->addWidget(buttonShowDir);


    gridLayout->addLayout(hboxLayout1, 2, 1, 1, 1);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 0, 0, 1, 1);

    lineEditProjectName = new QLineEdit(groupBox);
    lineEditProjectName->setObjectName(QString::fromUtf8("lineEditProjectName"));
    QSizePolicy sizePolicy2((QSizePolicy::Policy)7, (QSizePolicy::Policy)0);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(lineEditProjectName->sizePolicy().hasHeightForWidth());
    lineEditProjectName->setSizePolicy(sizePolicy2);
    lineEditProjectName->setMaxLength(32767);

    gridLayout->addWidget(lineEditProjectName, 0, 1, 1, 1);

    textEditProjectDesc = new QTextEdit(groupBox);
    textEditProjectDesc->setObjectName(QString::fromUtf8("textEditProjectDesc"));

    gridLayout->addWidget(textEditProjectDesc, 1, 1, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 2, 0, 1, 1);

    label_4_2 = new QLabel(groupBox);
    label_4_2->setObjectName(QString::fromUtf8("label_4_2"));

    gridLayout->addWidget(label_4_2, 3, 0, 1, 1);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 1, 0, 1, 1);

    QWidget::setTabOrder(lineEditProjectName, okButton);
    QWidget::setTabOrder(okButton, cancelButton);
    retranslateUi(ProjectNewDialog);
    QObject::connect(okButton, SIGNAL(clicked()), ProjectNewDialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), ProjectNewDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(ProjectNewDialog);
    } // setupUi

    void retranslateUi(QDialog *ProjectNewDialog)
    {
    ProjectNewDialog->setWindowTitle(QApplication::translate("ProjectNewDialog", "Neues Projekt erstellen", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("ProjectNewDialog", "OK", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("ProjectNewDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("ProjectNewDialog", "Neues Projekt erstellen", 0, QApplication::UnicodeUTF8));
    labelPath->setText(QApplication::translate("ProjectNewDialog", "", 0, QApplication::UnicodeUTF8));
    buttonShowDir->setText(QApplication::translate("ProjectNewDialog", "...", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ProjectNewDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Name</p></body></html>", 0, QApplication::UnicodeUTF8));
    lineEditProjectName->setStatusTip(QApplication::translate("ProjectNewDialog", "Name des neuen Projektes", 0, QApplication::UnicodeUTF8));
    lineEditProjectName->setInputMask(QApplication::translate("ProjectNewDialog", "", 0, QApplication::UnicodeUTF8));
    lineEditProjectName->setText(QApplication::translate("ProjectNewDialog", "", 0, QApplication::UnicodeUTF8));
    textEditProjectDesc->setStatusTip(QApplication::translate("ProjectNewDialog", "Beschreibung des neuen Projektes", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("ProjectNewDialog", "Pfad", 0, QApplication::UnicodeUTF8));
    label_4_2->setText(QApplication::translate("ProjectNewDialog", "", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("ProjectNewDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Beschreibung</p></body></html>", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ProjectNewDialog);
    } // retranslateUi

};

namespace Ui {
    class ProjectNewDialog: public Ui_ProjectNewDialog {};
} // namespace Ui

#endif // UI_PROJECTNEW_H
