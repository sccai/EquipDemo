/********************************************************************************
** Form generated from reading UI file 'formchild.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHILD_H
#define UI_FORMCHILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "battery.h"
#include "batterynew.h"

QT_BEGIN_NAMESPACE

class Ui_FormChild
{
public:
    Battery *widget_Battery;
    QLabel *label_Battery;
    QLabel *label_Battery_4;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *toolButton;
    BatteryNew *widget_Battery_New;
    QLabel *label_Battery_2;
    QLabel *label_Battery_3;
    QPushButton *pushButton_2;
    QWidget *widget_img;

    void setupUi(QWidget *FormChild)
    {
        if (FormChild->objectName().isEmpty())
            FormChild->setObjectName(QStringLiteral("FormChild"));
        FormChild->resize(1042, 750);
        widget_Battery = new Battery(FormChild);
        widget_Battery->setObjectName(QStringLiteral("widget_Battery"));
        widget_Battery->setGeometry(QRect(320, 200, 241, 261));
        widget_Battery->setProperty("value", QVariant(0));
        label_Battery = new QLabel(widget_Battery);
        label_Battery->setObjectName(QStringLiteral("label_Battery"));
        label_Battery->setGeometry(QRect(70, 160, 67, 51));
        QFont font;
        font.setPointSize(40);
        label_Battery->setFont(font);
        label_Battery_4 = new QLabel(widget_Battery);
        label_Battery_4->setObjectName(QStringLiteral("label_Battery_4"));
        label_Battery_4->setGeometry(QRect(50, 70, 121, 51));
        label_Battery_4->setFont(font);
        graphicsView = new QGraphicsView(FormChild);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(750, 20, 256, 192));
        widget = new QWidget(FormChild);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(470, 20, 271, 160));
        widget->setStyleSheet(QLatin1String("#Widget\n"
"{	\n"
"	background-color: rgb(85, 141, 127);\n"
"}\n"
"*\n"
"{\n"
"	font:30pt;\n"
"}\n"
"#WidgetShowImage\n"
"{\n"
"	border:2px solid black;\n"
"}\n"
"\n"
"#label\n"
"{\n"
"	background-color: rgb(85, 141, 127);\n"
"	color: rgb(255, 255, 255);\n"
"	border-image: url(:/images/transall.png);\n"
"	font: 28pt;\n"
"	text-align : left;\n"
"}\n"
"QPushButton\n"
"{\n"
"        background: rgb(68, 69, 73);\n"
"        color: white;\n"
"	/*boder-top:2px solid rgb(255,0,183);*/\n"
"}\n"
"QPushButton:!checked\n"
"{\n"
"        background: rgb(255, 0, 0);\n"
"        color: rgb(200, 200, 200);\n"
"}\n"
"\n"
"#tableWidget\n"
"{\n"
"	background-color:rgba(117,117,117);\n"
"}\n"
"#tableWidget:item\n"
"{\n"
"	/*border-top:1px solid rgb(181,182,183);\n"
"	border-bottom:1px solid rgb(71,68,67);*/\n"
"	margin-left:40px;\n"
"	margin-right:40px;\n"
"}/*\n"
"#scrollArea,#scrollAreaWidgetContents\n"
"{	\n"
"	border:none;\n"
"	background-color:rgba(117,117,117,0);\n"
"}*/\n"
"#btn_2\n"
"{\n"
"	background-color: rgb(85, 255,"
                        " 255);\n"
"        color: white;\n"
"}"));
        label = new QLabel(FormChild);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 40, 91, 61));
        pushButton = new QPushButton(FormChild);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(810, 50, 96, 68));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setLayoutDirection(Qt::LeftToRight);
        label_2 = new QLabel(FormChild);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(800, 430, 221, 221));
        label_3 = new QLabel(FormChild);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(610, 240, 190, 190));
        toolButton = new QPushButton(FormChild);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(810, 220, 190, 190));
        widget_Battery_New = new BatteryNew(FormChild);
        widget_Battery_New->setObjectName(QStringLiteral("widget_Battery_New"));
        widget_Battery_New->setGeometry(QRect(50, 200, 211, 261));
        widget_Battery_New->setProperty("value", QVariant(0));
        label_Battery_2 = new QLabel(widget_Battery_New);
        label_Battery_2->setObjectName(QStringLiteral("label_Battery_2"));
        label_Battery_2->setGeometry(QRect(60, 110, 67, 51));
        label_Battery_2->setFont(font);
        label_Battery_3 = new QLabel(widget_Battery_New);
        label_Battery_3->setObjectName(QStringLiteral("label_Battery_3"));
        label_Battery_3->setGeometry(QRect(60, 30, 61, 51));
        QFont font1;
        font1.setPointSize(20);
        label_Battery_3->setFont(font1);
        pushButton_2 = new QPushButton(FormChild);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 490, 97, 26));
        widget_img = new QWidget(FormChild);
        widget_img->setObjectName(QStringLiteral("widget_img"));
        widget_img->setGeometry(QRect(180, 480, 451, 241));

        retranslateUi(FormChild);

        QMetaObject::connectSlotsByName(FormChild);
    } // setupUi

    void retranslateUi(QWidget *FormChild)
    {
        FormChild->setWindowTitle(QApplication::translate("FormChild", "Form", 0));
        label_Battery->setText(QApplication::translate("FormChild", "10", 0));
        label_Battery_4->setText(QApplication::translate("FormChild", "\346\260\264\345\271\263", 0));
        label->setText(QApplication::translate("FormChild", "\346\227\213\350\275\254====", 0));
        pushButton->setText(QApplication::translate("FormChild", "\346\227\213\350\275\254", 0));
        label_2->setText(QApplication::translate("FormChild", "TextLabel", 0));
        label_3->setText(QApplication::translate("FormChild", "TextLabel", 0));
        toolButton->setText(QApplication::translate("FormChild", "\346\214\211\351\222\256\350\256\276\347\275\256\350\203\214\346\231\257\345\233\276", 0));
        label_Battery_2->setText(QApplication::translate("FormChild", "10", 0));
        label_Battery_3->setText(QApplication::translate("FormChild", "\350\211\262\345\270\246", 0));
        pushButton_2->setText(QApplication::translate("FormChild", "\347\224\265\346\261\240\347\224\265\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class FormChild: public Ui_FormChild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHILD_H
