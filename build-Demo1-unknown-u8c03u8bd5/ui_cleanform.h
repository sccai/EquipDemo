/********************************************************************************
** Form generated from reading UI file 'cleanform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEANFORM_H
#define UI_CLEANFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "QRoundProgressBar.h"

QT_BEGIN_NAMESPACE

class Ui_CleanForm
{
public:
    QWidget *widget;
    QRoundProgressBar *roundProgressBar_DeviceCheck;
    QPushButton *pushButton_Start;
    QGroupBox *groupBox_CardSender;
    QPushButton *pushButton_CardSenderInit;
    QPushButton *pushButton_CardSender;
    QPushButton *pushButton_CardSenderRequest;
    QGroupBox *groupBox_SendMod;
    QPushButton *pushButton_SmInit;
    QPushButton *pushButton_SmFlipin;
    QPushButton *pushButton_SmFlipout;
    QPushButton *pushButton_SmCleanIn;
    QPushButton *pushButton_SmCleanOut;
    QPushButton *pushButton_SmCleanCache;
    QGroupBox *groupBox_Sort;
    QPushButton *pushButton_Sort_LongOut;
    QPushButton *pushButton_SortModInit;
    QGroupBox *groupBox_PrintMod2;
    QPushButton *pushButton_PrintMod2;
    QPushButton *pushButton_PM2_CLeanSlide;
    QPushButton *pushButton_PM2_S2Out;
    QPushButton *pushButton_AllInit;
    QTextEdit *textEdit;
    QGroupBox *groupBox_PrintMod3;
    QPushButton *pushButton_PrintMod3;
    QPushButton *pushButton_PM3_CLeanSlide;
    QPushButton *pushButton_PM3_S2Out;
    QPushButton *pushButton_Stop;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_Pause;
    QGroupBox *groupBox_PrintMod1;
    QPushButton *pushButton_PrintMod1;
    QPushButton *pushButton_PM1_CLeanSlide;
    QPushButton *pushButton_PM1_S2Out;
    QGroupBox *groupBox_Lam;
    QPushButton *pushButton_LamModInit;
    QPushButton *pushButton_LamCleanSlide;
    QPushButton *pushButton_LamOut;
    QTextEdit *textEdit_Send;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_StartWhile;
    QProgressBar *progressBar_SEND;
    QProgressBar *progressBar_P1;
    QProgressBar *progressBar_P2;
    QProgressBar *progressBar_P3;
    QProgressBar *progressBar_LAM;
    QProgressBar *progressBar_SORT;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *CleanForm)
    {
        if (CleanForm->objectName().isEmpty())
            CleanForm->setObjectName(QStringLiteral("CleanForm"));
        CleanForm->resize(988, 782);
        widget = new QWidget(CleanForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 991, 781));
        widget->setStyleSheet(QStringLiteral(""));
        roundProgressBar_DeviceCheck = new QRoundProgressBar(widget);
        roundProgressBar_DeviceCheck->setObjectName(QStringLiteral("roundProgressBar_DeviceCheck"));
        roundProgressBar_DeviceCheck->setGeometry(QRect(790, 20, 150, 150));
        pushButton_Start = new QPushButton(widget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(790, 250, 150, 60));
        groupBox_CardSender = new QGroupBox(widget);
        groupBox_CardSender->setObjectName(QStringLiteral("groupBox_CardSender"));
        groupBox_CardSender->setGeometry(QRect(40, 20, 431, 60));
        groupBox_CardSender->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_CardSenderInit = new QPushButton(groupBox_CardSender);
        pushButton_CardSenderInit->setObjectName(QStringLiteral("pushButton_CardSenderInit"));
        pushButton_CardSenderInit->setGeometry(QRect(10, 20, 130, 31));
        pushButton_CardSender = new QPushButton(groupBox_CardSender);
        pushButton_CardSender->setObjectName(QStringLiteral("pushButton_CardSender"));
        pushButton_CardSender->setGeometry(QRect(150, 20, 130, 31));
        pushButton_CardSenderRequest = new QPushButton(groupBox_CardSender);
        pushButton_CardSenderRequest->setObjectName(QStringLiteral("pushButton_CardSenderRequest"));
        pushButton_CardSenderRequest->setGeometry(QRect(290, 20, 130, 31));
        groupBox_SendMod = new QGroupBox(widget);
        groupBox_SendMod->setObjectName(QStringLiteral("groupBox_SendMod"));
        groupBox_SendMod->setGeometry(QRect(40, 140, 431, 101));
        groupBox_SendMod->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_SmInit = new QPushButton(groupBox_SendMod);
        pushButton_SmInit->setObjectName(QStringLiteral("pushButton_SmInit"));
        pushButton_SmInit->setGeometry(QRect(10, 20, 130, 31));
        pushButton_SmFlipin = new QPushButton(groupBox_SendMod);
        pushButton_SmFlipin->setObjectName(QStringLiteral("pushButton_SmFlipin"));
        pushButton_SmFlipin->setGeometry(QRect(150, 20, 130, 31));
        pushButton_SmFlipout = new QPushButton(groupBox_SendMod);
        pushButton_SmFlipout->setObjectName(QStringLiteral("pushButton_SmFlipout"));
        pushButton_SmFlipout->setGeometry(QRect(290, 20, 130, 31));
        pushButton_SmCleanIn = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanIn->setObjectName(QStringLiteral("pushButton_SmCleanIn"));
        pushButton_SmCleanIn->setGeometry(QRect(10, 60, 130, 31));
        pushButton_SmCleanOut = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanOut->setObjectName(QStringLiteral("pushButton_SmCleanOut"));
        pushButton_SmCleanOut->setGeometry(QRect(150, 60, 130, 31));
        pushButton_SmCleanCache = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanCache->setObjectName(QStringLiteral("pushButton_SmCleanCache"));
        pushButton_SmCleanCache->setGeometry(QRect(290, 60, 130, 31));
        groupBox_Sort = new QGroupBox(widget);
        groupBox_Sort->setObjectName(QStringLiteral("groupBox_Sort"));
        groupBox_Sort->setGeometry(QRect(40, 480, 431, 60));
        groupBox_Sort->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_Sort_LongOut = new QPushButton(groupBox_Sort);
        pushButton_Sort_LongOut->setObjectName(QStringLiteral("pushButton_Sort_LongOut"));
        pushButton_Sort_LongOut->setGeometry(QRect(290, 20, 130, 31));
        pushButton_SortModInit = new QPushButton(groupBox_Sort);
        pushButton_SortModInit->setObjectName(QStringLiteral("pushButton_SortModInit"));
        pushButton_SortModInit->setGeometry(QRect(10, 20, 131, 31));
        groupBox_PrintMod2 = new QGroupBox(widget);
        groupBox_PrintMod2->setObjectName(QStringLiteral("groupBox_PrintMod2"));
        groupBox_PrintMod2->setGeometry(QRect(40, 300, 431, 61));
        groupBox_PrintMod2->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_PrintMod2 = new QPushButton(groupBox_PrintMod2);
        pushButton_PrintMod2->setObjectName(QStringLiteral("pushButton_PrintMod2"));
        pushButton_PrintMod2->setGeometry(QRect(10, 20, 131, 31));
        pushButton_PM2_CLeanSlide = new QPushButton(groupBox_PrintMod2);
        pushButton_PM2_CLeanSlide->setObjectName(QStringLiteral("pushButton_PM2_CLeanSlide"));
        pushButton_PM2_CLeanSlide->setGeometry(QRect(150, 20, 130, 31));
        pushButton_PM2_S2Out = new QPushButton(groupBox_PrintMod2);
        pushButton_PM2_S2Out->setObjectName(QStringLiteral("pushButton_PM2_S2Out"));
        pushButton_PM2_S2Out->setGeometry(QRect(290, 20, 130, 31));
        pushButton_AllInit = new QPushButton(widget);
        pushButton_AllInit->setObjectName(QStringLiteral("pushButton_AllInit"));
        pushButton_AllInit->setGeometry(QRect(790, 180, 150, 60));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(500, 570, 440, 211));
        textEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        groupBox_PrintMod3 = new QGroupBox(widget);
        groupBox_PrintMod3->setObjectName(QStringLiteral("groupBox_PrintMod3"));
        groupBox_PrintMod3->setGeometry(QRect(40, 360, 431, 61));
        groupBox_PrintMod3->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_PrintMod3 = new QPushButton(groupBox_PrintMod3);
        pushButton_PrintMod3->setObjectName(QStringLiteral("pushButton_PrintMod3"));
        pushButton_PrintMod3->setGeometry(QRect(10, 20, 131, 31));
        pushButton_PM3_CLeanSlide = new QPushButton(groupBox_PrintMod3);
        pushButton_PM3_CLeanSlide->setObjectName(QStringLiteral("pushButton_PM3_CLeanSlide"));
        pushButton_PM3_CLeanSlide->setGeometry(QRect(150, 20, 130, 31));
        pushButton_PM3_S2Out = new QPushButton(groupBox_PrintMod3);
        pushButton_PM3_S2Out->setObjectName(QStringLiteral("pushButton_PM3_S2Out"));
        pushButton_PM3_S2Out->setGeometry(QRect(290, 20, 130, 31));
        pushButton_Stop = new QPushButton(widget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(790, 460, 150, 60));
        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(40, 80, 431, 60));
        groupBox_4->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_11 = new QPushButton(groupBox_4);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 20, 130, 31));
        pushButton_12 = new QPushButton(groupBox_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(150, 20, 130, 31));
        pushButton_Pause = new QPushButton(widget);
        pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));
        pushButton_Pause->setGeometry(QRect(790, 390, 150, 60));
        groupBox_PrintMod1 = new QGroupBox(widget);
        groupBox_PrintMod1->setObjectName(QStringLiteral("groupBox_PrintMod1"));
        groupBox_PrintMod1->setGeometry(QRect(40, 240, 431, 61));
        groupBox_PrintMod1->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_PrintMod1 = new QPushButton(groupBox_PrintMod1);
        pushButton_PrintMod1->setObjectName(QStringLiteral("pushButton_PrintMod1"));
        pushButton_PrintMod1->setGeometry(QRect(10, 20, 131, 31));
        pushButton_PM1_CLeanSlide = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_CLeanSlide->setObjectName(QStringLiteral("pushButton_PM1_CLeanSlide"));
        pushButton_PM1_CLeanSlide->setGeometry(QRect(150, 20, 130, 31));
        pushButton_PM1_S2Out = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_S2Out->setObjectName(QStringLiteral("pushButton_PM1_S2Out"));
        pushButton_PM1_S2Out->setGeometry(QRect(290, 20, 130, 31));
        groupBox_Lam = new QGroupBox(widget);
        groupBox_Lam->setObjectName(QStringLiteral("groupBox_Lam"));
        groupBox_Lam->setGeometry(QRect(40, 420, 431, 61));
        groupBox_Lam->setStyleSheet(QLatin1String("      QGroupBox {\n"
"            border-color: rgb(156, 156, 156);\n"
"            border-width: 1px;\n"
"            border-style: solid;\n"
"            margin-top: 0.5ex;\n"
"			 background-color:grey;\n"
"        }\n"
"        QGroupBox::title {\n"
"            subcontrol-origin: margin;\n"
"            subcontrol-position: top left;\n"
"            left: 10px;\n"
"            margin-left: 2px;\n"
"            padding: 0  0px;\n"
"        }"));
        pushButton_LamModInit = new QPushButton(groupBox_Lam);
        pushButton_LamModInit->setObjectName(QStringLiteral("pushButton_LamModInit"));
        pushButton_LamModInit->setGeometry(QRect(10, 20, 131, 31));
        pushButton_LamCleanSlide = new QPushButton(groupBox_Lam);
        pushButton_LamCleanSlide->setObjectName(QStringLiteral("pushButton_LamCleanSlide"));
        pushButton_LamCleanSlide->setGeometry(QRect(150, 20, 130, 31));
        pushButton_LamOut = new QPushButton(groupBox_Lam);
        pushButton_LamOut->setObjectName(QStringLiteral("pushButton_LamOut"));
        pushButton_LamOut->setGeometry(QRect(290, 20, 130, 31));
        textEdit_Send = new QTextEdit(widget);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(30, 570, 440, 211));
        textEdit_Send->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 553, 30, 15));
        QFont font;
        font.setPointSize(8);
        label->setFont(font);
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 553, 41, 15));
        label_2->setFont(font);
        pushButton_StartWhile = new QPushButton(widget);
        pushButton_StartWhile->setObjectName(QStringLiteral("pushButton_StartWhile"));
        pushButton_StartWhile->setGeometry(QRect(790, 320, 150, 60));
        progressBar_SEND = new QProgressBar(widget);
        progressBar_SEND->setObjectName(QStringLiteral("progressBar_SEND"));
        progressBar_SEND->setGeometry(QRect(490, 180, 181, 23));
        progressBar_SEND->setValue(0);
        progressBar_SEND->setTextVisible(false);
        progressBar_P1 = new QProgressBar(widget);
        progressBar_P1->setObjectName(QStringLiteral("progressBar_P1"));
        progressBar_P1->setGeometry(QRect(490, 260, 181, 23));
        progressBar_P1->setValue(0);
        progressBar_P1->setTextVisible(false);
        progressBar_P2 = new QProgressBar(widget);
        progressBar_P2->setObjectName(QStringLiteral("progressBar_P2"));
        progressBar_P2->setGeometry(QRect(490, 320, 181, 23));
        progressBar_P2->setValue(0);
        progressBar_P2->setTextVisible(false);
        progressBar_P3 = new QProgressBar(widget);
        progressBar_P3->setObjectName(QStringLiteral("progressBar_P3"));
        progressBar_P3->setGeometry(QRect(490, 380, 181, 23));
        progressBar_P3->setValue(0);
        progressBar_P3->setTextVisible(false);
        progressBar_LAM = new QProgressBar(widget);
        progressBar_LAM->setObjectName(QStringLiteral("progressBar_LAM"));
        progressBar_LAM->setGeometry(QRect(490, 440, 181, 23));
        progressBar_LAM->setValue(0);
        progressBar_LAM->setTextVisible(false);
        progressBar_SORT = new QProgressBar(widget);
        progressBar_SORT->setObjectName(QStringLiteral("progressBar_SORT"));
        progressBar_SORT->setGeometry(QRect(490, 500, 181, 23));
        progressBar_SORT->setValue(0);
        progressBar_SORT->setTextVisible(false);
        checkBox_1 = new QCheckBox(widget);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));
        checkBox_1->setGeometry(QRect(680, 260, 61, 22));
        checkBox_1->setChecked(true);
        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(680, 320, 61, 22));
        checkBox_2->setChecked(true);
        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(680, 380, 61, 22));
        checkBox_3->setChecked(false);

        retranslateUi(CleanForm);

        QMetaObject::connectSlotsByName(CleanForm);
    } // setupUi

    void retranslateUi(QWidget *CleanForm)
    {
        CleanForm->setWindowTitle(QApplication::translate("CleanForm", "Form", 0));
        pushButton_Start->setText(QApplication::translate("CleanForm", "\345\274\200\345\247\213\344\270\200\346\254\241", 0));
        groupBox_CardSender->setTitle(QApplication::translate("CleanForm", "\345\217\221\345\215\241\345\231\250", 0));
        pushButton_CardSenderInit->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_CardSender->setText(QApplication::translate("CleanForm", "\345\217\221\345\215\241", 0));
        pushButton_CardSenderRequest->setText(QApplication::translate("CleanForm", "\346\237\245\350\257\242\344\274\240\346\204\237\345\231\250\347\212\266\346\200\201", 0));
        groupBox_SendMod->setTitle(QApplication::translate("CleanForm", "\350\277\233\345\215\241\346\234\272\346\236\204", 0));
        pushButton_SmInit->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_SmFlipin->setText(QApplication::translate("CleanForm", "\350\275\254\345\220\221\350\277\233\345\215\241", 0));
        pushButton_SmFlipout->setText(QApplication::translate("CleanForm", "\350\275\254\345\220\221\345\207\272\345\215\241", 0));
        pushButton_SmCleanIn->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\350\277\233\345\215\241", 0));
        pushButton_SmCleanOut->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\345\207\272\345\215\241", 0));
        pushButton_SmCleanCache->setText(QApplication::translate("CleanForm", "\347\274\223\345\206\262\345\207\272\345\215\241", 0));
        groupBox_Sort->setTitle(QApplication::translate("CleanForm", "\345\210\206\346\213\243\346\250\241\345\235\227", 0));
        pushButton_Sort_LongOut->setText(QApplication::translate("CleanForm", "\345\215\241\346\247\275\345\207\272\345\215\241", 0));
        pushButton_SortModInit->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        groupBox_PrintMod2->setTitle(QApplication::translate("CleanForm", "\346\211\223\345\215\260\346\250\241\345\235\2272", 0));
        pushButton_PrintMod2->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM2_CLeanSlide->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\350\275\250\351\201\223", 0));
        pushButton_PM2_S2Out->setText(QApplication::translate("CleanForm", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_AllInit->setText(QApplication::translate("CleanForm", "\345\205\250\351\203\250\345\210\235\345\247\213\345\214\226", 0));
        groupBox_PrintMod3->setTitle(QApplication::translate("CleanForm", "\346\211\223\345\215\260\346\250\241\345\235\2273", 0));
        pushButton_PrintMod3->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM3_CLeanSlide->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\350\275\250\351\201\223", 0));
        pushButton_PM3_S2Out->setText(QApplication::translate("CleanForm", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_Stop->setText(QApplication::translate("CleanForm", "\345\201\234\346\255\242", 0));
        groupBox_4->setTitle(QApplication::translate("CleanForm", "OCR\350\256\276\345\244\207", 0));
        pushButton_11->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_12->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201", 0));
        pushButton_Pause->setText(QApplication::translate("CleanForm", "\346\232\202\345\201\234", 0));
        groupBox_PrintMod1->setTitle(QApplication::translate("CleanForm", "\346\211\223\345\215\260\346\250\241\345\235\2271", 0));
        pushButton_PrintMod1->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM1_CLeanSlide->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\350\275\250\351\201\223", 0));
        pushButton_PM1_S2Out->setText(QApplication::translate("CleanForm", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        groupBox_Lam->setTitle(QApplication::translate("CleanForm", "\350\246\206\350\206\234\346\250\241\345\235\227", 0));
        pushButton_LamModInit->setText(QApplication::translate("CleanForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_LamCleanSlide->setText(QApplication::translate("CleanForm", "\346\270\205\346\264\201\350\275\250\351\201\223", 0));
        pushButton_LamOut->setText(QApplication::translate("CleanForm", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        label->setText(QApplication::translate("CleanForm", "Send", 0));
        label_2->setText(QApplication::translate("CleanForm", "Receive", 0));
        pushButton_StartWhile->setText(QApplication::translate("CleanForm", "\345\276\252\347\216\257\345\274\200\345\247\213", 0));
        checkBox_1->setText(QApplication::translate("CleanForm", "\345\220\257\347\224\250", 0));
        checkBox_2->setText(QApplication::translate("CleanForm", "\345\220\257\347\224\250", 0));
        checkBox_3->setText(QApplication::translate("CleanForm", "\345\220\257\347\224\250", 0));
    } // retranslateUi

};

namespace Ui {
    class CleanForm: public Ui_CleanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEANFORM_H
