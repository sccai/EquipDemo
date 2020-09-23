/********************************************************************************
** Form generated from reading UI file 'selfcheckform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELFCHECKFORM_H
#define UI_SELFCHECKFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "control/DRoundProgressBar.h"
#include "roundprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_SelfCheckForm
{
public:
    QWidget *widget_Parent;
    QGridLayout *gridLayout;
    QWidget *widget_Top;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    RoundProgressBar *roundProgressBar_DeviceCheck;
    DRoundProgressBar *roundProgressBar2;
    QWidget *widget_Status;
    QLabel *label_2;

    void setupUi(QWidget *SelfCheckForm)
    {
        if (SelfCheckForm->objectName().isEmpty())
            SelfCheckForm->setObjectName(QStringLiteral("SelfCheckForm"));
        SelfCheckForm->resize(990, 900);
        SelfCheckForm->setStyleSheet(QStringLiteral(""));
        widget_Parent = new QWidget(SelfCheckForm);
        widget_Parent->setObjectName(QStringLiteral("widget_Parent"));
        widget_Parent->setGeometry(QRect(0, 250, 990, 610));
        widget_Parent->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(widget_Parent);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        widget_Top = new QWidget(SelfCheckForm);
        widget_Top->setObjectName(QStringLiteral("widget_Top"));
        widget_Top->setGeometry(QRect(0, 0, 991, 251));
        widget_Top->setStyleSheet(QStringLiteral(""));
        label = new QLabel(widget_Top);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(289, 90, 481, 57));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(32);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 32pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_2 = new QPushButton(widget_Top);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(800, 150, 130, 70));
        pushButton = new QPushButton(widget_Top);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(800, 40, 130, 70));
        roundProgressBar_DeviceCheck = new RoundProgressBar(widget_Top);
        roundProgressBar_DeviceCheck->setObjectName(QStringLiteral("roundProgressBar_DeviceCheck"));
        roundProgressBar_DeviceCheck->setGeometry(QRect(20, 10, 231, 231));
        roundProgressBar2 = new DRoundProgressBar(widget_Top);
        roundProgressBar2->setObjectName(QStringLiteral("roundProgressBar2"));
        roundProgressBar2->setGeometry(QRect(300, 40, 160, 160));
        widget_Status = new QWidget(SelfCheckForm);
        widget_Status->setObjectName(QStringLiteral("widget_Status"));
        widget_Status->setGeometry(QRect(10, 865, 971, 30));
        label_2 = new QLabel(widget_Status);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(860, 8, 111, 17));

        retranslateUi(SelfCheckForm);

        QMetaObject::connectSlotsByName(SelfCheckForm);
    } // setupUi

    void retranslateUi(QWidget *SelfCheckForm)
    {
        SelfCheckForm->setWindowTitle(QApplication::translate("SelfCheckForm", "\350\207\252\346\243\200\347\225\214\351\235\242", 0));
        label->setText(QApplication::translate("SelfCheckForm", "\350\256\276\345\244\207\346\255\243\345\234\250\346\243\200\346\265\213...", 0));
        pushButton_2->setText(QApplication::translate("SelfCheckForm", "\345\201\234\346\255\242\346\243\200\346\265\213", 0));
        pushButton->setText(QApplication::translate("SelfCheckForm", "\345\274\200\345\247\213\346\243\200\346\265\213", 0));
        label_2->setText(QApplication::translate("SelfCheckForm", "\347\263\273\347\273\237\347\211\210\346\234\254:1.0.0", 0));
    } // retranslateUi

};

namespace Ui {
    class SelfCheckForm: public Ui_SelfCheckForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELFCHECKFORM_H
