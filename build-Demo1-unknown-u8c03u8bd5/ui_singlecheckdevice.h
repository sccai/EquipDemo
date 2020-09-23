/********************************************************************************
** Form generated from reading UI file 'singlecheckdevice.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLECHECKDEVICE_H
#define UI_SINGLECHECKDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleCheckDevice
{
public:
    QWidget *widget_Checking;
    QWidget *widget_Normal;
    QLabel *label;
    QWidget *widget_Img;

    void setupUi(QWidget *SingleCheckDevice)
    {
        if (SingleCheckDevice->objectName().isEmpty())
            SingleCheckDevice->setObjectName(QStringLiteral("SingleCheckDevice"));
        SingleCheckDevice->resize(200, 200);
        SingleCheckDevice->setMinimumSize(QSize(200, 200));
        SingleCheckDevice->setMaximumSize(QSize(200, 200));
        widget_Checking = new QWidget(SingleCheckDevice);
        widget_Checking->setObjectName(QStringLiteral("widget_Checking"));
        widget_Checking->setGeometry(QRect(0, 0, 200, 200));
        widget_Checking->setMinimumSize(QSize(0, 0));
        widget_Checking->setMaximumSize(QSize(200, 200));
        widget_Checking->setLayoutDirection(Qt::LeftToRight);
        widget_Checking->setAutoFillBackground(false);
        widget_Normal = new QWidget(SingleCheckDevice);
        widget_Normal->setObjectName(QStringLiteral("widget_Normal"));
        widget_Normal->setGeometry(QRect(0, 0, 200, 200));
        widget_Normal->setMinimumSize(QSize(0, 0));
        widget_Normal->setMaximumSize(QSize(200, 200));
        widget_Normal->setLayoutDirection(Qt::LeftToRight);
        widget_Normal->setAutoFillBackground(false);
        label = new QLabel(widget_Normal);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 161, 51));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        widget_Img = new QWidget(widget_Normal);
        widget_Img->setObjectName(QStringLiteral("widget_Img"));
        widget_Img->setGeometry(QRect(50, 90, 100, 100));

        retranslateUi(SingleCheckDevice);

        QMetaObject::connectSlotsByName(SingleCheckDevice);
    } // setupUi

    void retranslateUi(QWidget *SingleCheckDevice)
    {
        SingleCheckDevice->setWindowTitle(QApplication::translate("SingleCheckDevice", "Form", 0));
        label->setText(QApplication::translate("SingleCheckDevice", "\346\211\223\345\215\260\346\234\272", 0));
    } // retranslateUi

};

namespace Ui {
    class SingleCheckDevice: public Ui_SingleCheckDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLECHECKDEVICE_H
