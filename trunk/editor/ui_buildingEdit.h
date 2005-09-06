#ifndef UI_BUILDINGEDIT_H
#define UI_BUILDINGEDIT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

class Ui_BuildingEditDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QWidget *widget;
    QWidget *widget1;
    QWidget *widget2;
    QLabel *label;
    QLineEdit *lineEditName;
    QWidget *widget3;
    QLabel *label_2;
    QLineEdit *lineEditDesc;

    void setupUi(QDialog *BuildingEditDialog)
    {
    BuildingEditDialog->setObjectName(QString::fromUtf8("BuildingEditDialog"));
    BuildingEditDialog->resize(QSize(566, 406).expandedTo(BuildingEditDialog->minimumSizeHint()));
    layoutWidget = new QWidget(BuildingEditDialog);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(30, 330, 351, 33));
    hboxLayout = new QHBoxLayout(layoutWidget);
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hboxLayout->addItem(spacerItem);

    okButton = new QPushButton(layoutWidget);
    okButton->setObjectName(QString::fromUtf8("okButton"));

    hboxLayout->addWidget(okButton);

    cancelButton = new QPushButton(layoutWidget);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

    hboxLayout->addWidget(cancelButton);

    groupBox = new QGroupBox(BuildingEditDialog);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 20, 441, 171));
    widget = new QWidget(groupBox);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(11, 87, 80, 54));
    widget1 = new QWidget(groupBox);
    widget1->setObjectName(QString::fromUtf8("widget1"));
    widget1->setGeometry(QRect(97, 87, 233, 54));
    widget2 = new QWidget(groupBox);
    widget2->setObjectName(QString::fromUtf8("widget2"));
    widget2->setGeometry(QRect(10, 80, 344, 194));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(12, 88, 78, 23));
    lineEditName = new QLineEdit(groupBox);
    lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
    lineEditName->setGeometry(QRect(130, 80, 231, 23));
    widget3 = new QWidget(groupBox);
    widget3->setObjectName(QString::fromUtf8("widget3"));
    widget3->setGeometry(QRect(20, 160, 80, 91));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 120, 78, 21));
    lineEditDesc = new QLineEdit(groupBox);
    lineEditDesc->setObjectName(QString::fromUtf8("lineEditDesc"));
    lineEditDesc->setGeometry(QRect(130, 110, 113, 20));
    retranslateUi(BuildingEditDialog);
    QObject::connect(okButton, SIGNAL(clicked()), BuildingEditDialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), BuildingEditDialog, SLOT(reject()));

    QMetaObject::connectSlotsByName(BuildingEditDialog);
    } // setupUi

    void retranslateUi(QDialog *BuildingEditDialog)
    {
    BuildingEditDialog->setWindowTitle(QApplication::translate("BuildingEditDialog", "Dialog"));
    okButton->setText(QApplication::translate("BuildingEditDialog", "OK"));
    cancelButton->setText(QApplication::translate("BuildingEditDialog", "Cancel"));
    groupBox->setTitle(QApplication::translate("BuildingEditDialog", "Eigenschaften"));
    label->setText(QApplication::translate("BuildingEditDialog", "Name"));
    label_2->setText(QApplication::translate("BuildingEditDialog", "Beschreibung"));
    Q_UNUSED(BuildingEditDialog);
    } // retranslateUi

};

namespace Ui {
    class BuildingEditDialog: public Ui_BuildingEditDialog {};
} // namespace Ui

#endif // UI_BUILDINGEDIT_H
