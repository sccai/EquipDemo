/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "QRoundProgressBar.h"
#include "batterynew.h"
#include "control/lightbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_SendCardInit;
    QPushButton *pushButton_SendCard;
    QPushButton *pushButton_Stop;
    QPushButton *pushButton_Start;
    QTextEdit *textEdit;
    QPushButton *pushButton_Pause;
    QGroupBox *groupBox_SendMod;
    QPushButton *pushButton_SmInit;
    QPushButton *pushButton_SmFlipin;
    QPushButton *pushButton_SmFlipout;
    QPushButton *pushButton_SmCleanIn;
    QPushButton *pushButton_SmCleanOut;
    QPushButton *pushButton_SmCleanCache;
    QGroupBox *groupBox_PrintMod1;
    QPushButton *pushButton_PrintMod1;
    QPushButton *pushButton_PM1_WriteIn;
    QPushButton *pushButton_PM1_WriteOut;
    QPushButton *pushButton_PM1_Long;
    QPushButton *pushButton_PM1_POut;
    QPushButton *pushButton_PM1_S2Out;
    QPushButton *pushButton_PM1_PIn;
    QGroupBox *groupBox_Lam;
    QPushButton *pushButton_LamModInit;
    QPushButton *pushButton_SmFlipin_5;
    QPushButton *pushButton_SmFlipin_6;
    QPushButton *pushButton_SmFlipin_7;
    QPushButton *pushButton_SmFlipin_8;
    QPushButton *pushButton_SmFlipin_9;
    QGroupBox *groupBox_Sort;
    QPushButton *pushButton_SortModInit;
    QPushButton *pushButton_SmFlipin_10;
    QPushButton *pushButton_SmFlipin_11;
    QPushButton *pushButton_SmFlipin_13;
    QPushButton *pushButton_SmFlipin_14;
    QPushButton *pushButton_SmFlipin_12;
    BatteryNew *widget_Battery_New;
    QLabel *label_Battery_2;
    QLabel *label_Battery_3;
    BatteryNew *widget_Battery_New_2;
    QLabel *label_Battery_4;
    QLabel *label_Battery_5;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QRoundProgressBar *RoundBar_Slot2;
    QRoundProgressBar *RoundBar_Slot1;
    QRoundProgressBar *RoundBar_Slot3;
    QRoundProgressBar *RoundBar_Slot4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QRoundProgressBar *roundProgressBar_DeviceCheck;
    QPushButton *pushButton_AllInit;
    QWidget *widget_img;
    BatteryNew *widget_Battery_New_3;
    QLabel *label_Battery_10;
    QLabel *label_Battery_11;
    BatteryNew *widget_Battery_New_4;
    QLabel *label_Battery_12;
    QLabel *label_Battery_13;
    BatteryNew *widget_Battery_New_5;
    QLabel *label_Battery_16;
    QLabel *label_Battery_17;
    BatteryNew *widget_Battery_New_6;
    QLabel *label_Battery_18;
    QLabel *label_Battery_19;
    BatteryNew *widget_Battery_New_7;
    QLabel *label_Battery_20;
    QLabel *label_Battery_21;
    BatteryNew *widget_Battery_New_8;
    QLabel *label_Battery_22;
    QLabel *label_Battery_23;
    BatteryNew *widget_Battery_New_9;
    QLabel *label_Battery_26;
    QLabel *label_Battery_27;
    QGroupBox *groupBox_PrintMod1_2;
    QPushButton *pushButton_PrintMod2;
    QPushButton *pushButton_PM2_WriteIn;
    QPushButton *pushButton_PM2_WriteOut;
    QPushButton *pushButton_PM2_Long;
    QPushButton *pushButton_PM2_POut;
    QPushButton *pushButton_PM2_S2Out;
    QPushButton *pushButton_PM2_PIn;
    QGroupBox *groupBox_PrintMod1_3;
    QPushButton *pushButton_PrintMod2_2;
    QPushButton *pushButton_PM2_WriteIn_2;
    QPushButton *pushButton_PM2_WriteOut_2;
    QPushButton *pushButton_PM2_Long_2;
    QPushButton *pushButton_PM2_POut_2;
    QPushButton *pushButton_PM2_S2Out_2;
    QPushButton *pushButton_PM2_PIn_2;
    QWidget *widget;
    QTextEdit *textEdit_Send;
    QLabel *label;
    QLabel *label_22;
    LightButton *lightButton1;
    QWidget *statusBar;
    QLabel *label_23;
    QProgressBar *progressBar_DataPercent;
    QLabel *label_24;
    QPushButton *pushButton_ConnectDB;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1554, 1080);
        MainWindow->setMaximumSize(QSize(1554, 1500));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1400, 270, 151, 101));
        groupBox_2->setStyleSheet(QLatin1String("      QGroupBox {\n"
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
        pushButton_SendCardInit = new QPushButton(groupBox_2);
        pushButton_SendCardInit->setObjectName(QStringLiteral("pushButton_SendCardInit"));
        pushButton_SendCardInit->setGeometry(QRect(10, 20, 130, 31));
        pushButton_SendCard = new QPushButton(groupBox_2);
        pushButton_SendCard->setObjectName(QStringLiteral("pushButton_SendCard"));
        pushButton_SendCard->setGeometry(QRect(10, 60, 130, 31));
        pushButton_Stop = new QPushButton(centralWidget);
        pushButton_Stop->setObjectName(QStringLiteral("pushButton_Stop"));
        pushButton_Stop->setGeometry(QRect(1410, 900, 141, 141));
        pushButton_Start = new QPushButton(centralWidget);
        pushButton_Start->setObjectName(QStringLiteral("pushButton_Start"));
        pushButton_Start->setGeometry(QRect(1110, 900, 141, 141));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(620, 590, 491, 171));
        pushButton_Pause = new QPushButton(centralWidget);
        pushButton_Pause->setObjectName(QStringLiteral("pushButton_Pause"));
        pushButton_Pause->setGeometry(QRect(1260, 900, 141, 141));
        groupBox_SendMod = new QGroupBox(centralWidget);
        groupBox_SendMod->setObjectName(QStringLiteral("groupBox_SendMod"));
        groupBox_SendMod->setGeometry(QRect(1080, 270, 151, 271));
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
        pushButton_SmFlipin->setGeometry(QRect(10, 60, 130, 31));
        pushButton_SmFlipout = new QPushButton(groupBox_SendMod);
        pushButton_SmFlipout->setObjectName(QStringLiteral("pushButton_SmFlipout"));
        pushButton_SmFlipout->setGeometry(QRect(10, 100, 130, 31));
        pushButton_SmCleanIn = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanIn->setObjectName(QStringLiteral("pushButton_SmCleanIn"));
        pushButton_SmCleanIn->setGeometry(QRect(10, 140, 130, 31));
        pushButton_SmCleanOut = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanOut->setObjectName(QStringLiteral("pushButton_SmCleanOut"));
        pushButton_SmCleanOut->setGeometry(QRect(10, 180, 130, 31));
        pushButton_SmCleanCache = new QPushButton(groupBox_SendMod);
        pushButton_SmCleanCache->setObjectName(QStringLiteral("pushButton_SmCleanCache"));
        pushButton_SmCleanCache->setGeometry(QRect(10, 220, 130, 31));
        groupBox_PrintMod1 = new QGroupBox(centralWidget);
        groupBox_PrintMod1->setObjectName(QStringLiteral("groupBox_PrintMod1"));
        groupBox_PrintMod1->setGeometry(QRect(920, 270, 151, 301));
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
        pushButton_PM1_WriteIn = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_WriteIn->setObjectName(QStringLiteral("pushButton_PM1_WriteIn"));
        pushButton_PM1_WriteIn->setGeometry(QRect(10, 60, 130, 31));
        pushButton_PM1_WriteOut = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_WriteOut->setObjectName(QStringLiteral("pushButton_PM1_WriteOut"));
        pushButton_PM1_WriteOut->setGeometry(QRect(10, 100, 130, 31));
        pushButton_PM1_Long = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_Long->setObjectName(QStringLiteral("pushButton_PM1_Long"));
        pushButton_PM1_Long->setGeometry(QRect(10, 260, 130, 31));
        pushButton_PM1_POut = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_POut->setObjectName(QStringLiteral("pushButton_PM1_POut"));
        pushButton_PM1_POut->setGeometry(QRect(10, 180, 130, 31));
        pushButton_PM1_S2Out = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_S2Out->setObjectName(QStringLiteral("pushButton_PM1_S2Out"));
        pushButton_PM1_S2Out->setGeometry(QRect(10, 220, 130, 31));
        pushButton_PM1_PIn = new QPushButton(groupBox_PrintMod1);
        pushButton_PM1_PIn->setObjectName(QStringLiteral("pushButton_PM1_PIn"));
        pushButton_PM1_PIn->setGeometry(QRect(10, 140, 130, 31));
        groupBox_Lam = new QGroupBox(centralWidget);
        groupBox_Lam->setObjectName(QStringLiteral("groupBox_Lam"));
        groupBox_Lam->setGeometry(QRect(440, 270, 151, 261));
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
        pushButton_SmFlipin_5 = new QPushButton(groupBox_Lam);
        pushButton_SmFlipin_5->setObjectName(QStringLiteral("pushButton_SmFlipin_5"));
        pushButton_SmFlipin_5->setGeometry(QRect(10, 100, 130, 31));
        pushButton_SmFlipin_6 = new QPushButton(groupBox_Lam);
        pushButton_SmFlipin_6->setObjectName(QStringLiteral("pushButton_SmFlipin_6"));
        pushButton_SmFlipin_6->setGeometry(QRect(10, 140, 130, 31));
        pushButton_SmFlipin_7 = new QPushButton(groupBox_Lam);
        pushButton_SmFlipin_7->setObjectName(QStringLiteral("pushButton_SmFlipin_7"));
        pushButton_SmFlipin_7->setGeometry(QRect(10, 180, 130, 31));
        pushButton_SmFlipin_8 = new QPushButton(groupBox_Lam);
        pushButton_SmFlipin_8->setObjectName(QStringLiteral("pushButton_SmFlipin_8"));
        pushButton_SmFlipin_8->setGeometry(QRect(10, 60, 130, 31));
        pushButton_SmFlipin_9 = new QPushButton(groupBox_Lam);
        pushButton_SmFlipin_9->setObjectName(QStringLiteral("pushButton_SmFlipin_9"));
        pushButton_SmFlipin_9->setGeometry(QRect(10, 220, 130, 31));
        groupBox_Sort = new QGroupBox(centralWidget);
        groupBox_Sort->setObjectName(QStringLiteral("groupBox_Sort"));
        groupBox_Sort->setGeometry(QRect(0, 270, 431, 101));
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
        pushButton_SortModInit = new QPushButton(groupBox_Sort);
        pushButton_SortModInit->setObjectName(QStringLiteral("pushButton_SortModInit"));
        pushButton_SortModInit->setGeometry(QRect(290, 20, 131, 31));
        pushButton_SmFlipin_10 = new QPushButton(groupBox_Sort);
        pushButton_SmFlipin_10->setObjectName(QStringLiteral("pushButton_SmFlipin_10"));
        pushButton_SmFlipin_10->setGeometry(QRect(290, 60, 130, 31));
        pushButton_SmFlipin_11 = new QPushButton(groupBox_Sort);
        pushButton_SmFlipin_11->setObjectName(QStringLiteral("pushButton_SmFlipin_11"));
        pushButton_SmFlipin_11->setGeometry(QRect(150, 60, 130, 31));
        pushButton_SmFlipin_13 = new QPushButton(groupBox_Sort);
        pushButton_SmFlipin_13->setObjectName(QStringLiteral("pushButton_SmFlipin_13"));
        pushButton_SmFlipin_13->setGeometry(QRect(150, 20, 130, 31));
        pushButton_SmFlipin_14 = new QPushButton(groupBox_Sort);
        pushButton_SmFlipin_14->setObjectName(QStringLiteral("pushButton_SmFlipin_14"));
        pushButton_SmFlipin_14->setGeometry(QRect(10, 20, 130, 31));
        pushButton_SmFlipin_12 = new QPushButton(groupBox_Sort);
        pushButton_SmFlipin_12->setObjectName(QStringLiteral("pushButton_SmFlipin_12"));
        pushButton_SmFlipin_12->setGeometry(QRect(10, 60, 130, 31));
        widget_Battery_New = new BatteryNew(centralWidget);
        widget_Battery_New->setObjectName(QStringLiteral("widget_Battery_New"));
        widget_Battery_New->setGeometry(QRect(700, 80, 160, 190));
        widget_Battery_New->setProperty("value", QVariant(0));
        label_Battery_2 = new QLabel(widget_Battery_New);
        label_Battery_2->setObjectName(QStringLiteral("label_Battery_2"));
        label_Battery_2->setGeometry(QRect(50, 110, 67, 51));
        QFont font;
        font.setPointSize(40);
        label_Battery_2->setFont(font);
        label_Battery_3 = new QLabel(widget_Battery_New);
        label_Battery_3->setObjectName(QStringLiteral("label_Battery_3"));
        label_Battery_3->setGeometry(QRect(50, 30, 81, 51));
        QFont font1;
        font1.setPointSize(20);
        label_Battery_3->setFont(font1);
        widget_Battery_New_2 = new BatteryNew(centralWidget);
        widget_Battery_New_2->setObjectName(QStringLiteral("widget_Battery_New_2"));
        widget_Battery_New_2->setGeometry(QRect(530, 80, 160, 190));
        widget_Battery_New_2->setProperty("value", QVariant(0));
        label_Battery_4 = new QLabel(widget_Battery_New_2);
        label_Battery_4->setObjectName(QStringLiteral("label_Battery_4"));
        label_Battery_4->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_4->setFont(font);
        label_Battery_5 = new QLabel(widget_Battery_New_2);
        label_Battery_5->setObjectName(QStringLiteral("label_Battery_5"));
        label_Battery_5->setGeometry(QRect(40, 30, 81, 51));
        label_Battery_5->setFont(font1);
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1240, 270, 151, 101));
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
        pushButton_12->setGeometry(QRect(10, 60, 130, 31));
        RoundBar_Slot2 = new QRoundProgressBar(centralWidget);
        RoundBar_Slot2->setObjectName(QStringLiteral("RoundBar_Slot2"));
        RoundBar_Slot2->setGeometry(QRect(220, 810, 160, 160));
        RoundBar_Slot1 = new QRoundProgressBar(centralWidget);
        RoundBar_Slot1->setObjectName(QStringLiteral("RoundBar_Slot1"));
        RoundBar_Slot1->setGeometry(QRect(10, 810, 160, 160));
        RoundBar_Slot3 = new QRoundProgressBar(centralWidget);
        RoundBar_Slot3->setObjectName(QStringLiteral("RoundBar_Slot3"));
        RoundBar_Slot3->setGeometry(QRect(430, 810, 160, 160));
        RoundBar_Slot4 = new QRoundProgressBar(centralWidget);
        RoundBar_Slot4->setObjectName(QStringLiteral("RoundBar_Slot4"));
        RoundBar_Slot4->setGeometry(QRect(640, 810, 160, 160));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 780, 67, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(14);
        label_2->setFont(font2);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 780, 67, 23));
        label_3->setFont(font2);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 780, 67, 23));
        label_4->setFont(font2);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(640, 780, 67, 23));
        label_5->setFont(font2);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 970, 67, 23));
        label_6->setFont(font2);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 970, 31, 23));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 1010, 31, 23));
        label_8->setFont(font2);
        label_8->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 1010, 67, 23));
        label_9->setFont(font2);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(300, 970, 31, 23));
        label_10->setFont(font2);
        label_10->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 1010, 31, 23));
        label_11->setFont(font2);
        label_11->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(220, 970, 67, 23));
        label_12->setFont(font2);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(220, 1010, 67, 23));
        label_13->setFont(font2);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(510, 970, 31, 23));
        label_14->setFont(font2);
        label_14->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(510, 1010, 31, 23));
        label_15->setFont(font2);
        label_15->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(430, 970, 67, 23));
        label_16->setFont(font2);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(430, 1010, 67, 23));
        label_17->setFont(font2);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(720, 970, 31, 23));
        label_18->setFont(font2);
        label_18->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(720, 1010, 31, 23));
        label_19->setFont(font2);
        label_19->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(640, 970, 67, 23));
        label_20->setFont(font2);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(640, 1010, 67, 23));
        label_21->setFont(font2);
        roundProgressBar_DeviceCheck = new QRoundProgressBar(centralWidget);
        roundProgressBar_DeviceCheck->setObjectName(QStringLiteral("roundProgressBar_DeviceCheck"));
        roundProgressBar_DeviceCheck->setGeometry(QRect(1240, 380, 310, 310));
        pushButton_AllInit = new QPushButton(centralWidget);
        pushButton_AllInit->setObjectName(QStringLiteral("pushButton_AllInit"));
        pushButton_AllInit->setGeometry(QRect(960, 900, 141, 141));
        widget_img = new QWidget(centralWidget);
        widget_img->setObjectName(QStringLiteral("widget_img"));
        widget_img->setGeometry(QRect(30, 380, 391, 201));
        widget_Battery_New_3 = new BatteryNew(centralWidget);
        widget_Battery_New_3->setObjectName(QStringLiteral("widget_Battery_New_3"));
        widget_Battery_New_3->setGeometry(QRect(870, 80, 160, 190));
        widget_Battery_New_3->setProperty("value", QVariant(0));
        label_Battery_10 = new QLabel(widget_Battery_New_3);
        label_Battery_10->setObjectName(QStringLiteral("label_Battery_10"));
        label_Battery_10->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_10->setFont(font);
        label_Battery_11 = new QLabel(widget_Battery_New_3);
        label_Battery_11->setObjectName(QStringLiteral("label_Battery_11"));
        label_Battery_11->setGeometry(QRect(40, 30, 81, 51));
        label_Battery_11->setFont(font1);
        widget_Battery_New_4 = new BatteryNew(centralWidget);
        widget_Battery_New_4->setObjectName(QStringLiteral("widget_Battery_New_4"));
        widget_Battery_New_4->setGeometry(QRect(1040, 80, 160, 190));
        widget_Battery_New_4->setProperty("value", QVariant(0));
        label_Battery_12 = new QLabel(widget_Battery_New_4);
        label_Battery_12->setObjectName(QStringLiteral("label_Battery_12"));
        label_Battery_12->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_12->setFont(font);
        label_Battery_13 = new QLabel(widget_Battery_New_4);
        label_Battery_13->setObjectName(QStringLiteral("label_Battery_13"));
        label_Battery_13->setGeometry(QRect(50, 30, 81, 51));
        label_Battery_13->setFont(font1);
        widget_Battery_New_5 = new BatteryNew(centralWidget);
        widget_Battery_New_5->setObjectName(QStringLiteral("widget_Battery_New_5"));
        widget_Battery_New_5->setGeometry(QRect(1380, 80, 160, 190));
        widget_Battery_New_5->setProperty("value", QVariant(0));
        label_Battery_16 = new QLabel(widget_Battery_New_5);
        label_Battery_16->setObjectName(QStringLiteral("label_Battery_16"));
        label_Battery_16->setGeometry(QRect(60, 110, 67, 51));
        label_Battery_16->setFont(font);
        label_Battery_17 = new QLabel(widget_Battery_New_5);
        label_Battery_17->setObjectName(QStringLiteral("label_Battery_17"));
        label_Battery_17->setGeometry(QRect(40, 30, 91, 51));
        label_Battery_17->setFont(font1);
        widget_Battery_New_6 = new BatteryNew(centralWidget);
        widget_Battery_New_6->setObjectName(QStringLiteral("widget_Battery_New_6"));
        widget_Battery_New_6->setGeometry(QRect(1210, 80, 160, 190));
        widget_Battery_New_6->setProperty("value", QVariant(0));
        label_Battery_18 = new QLabel(widget_Battery_New_6);
        label_Battery_18->setObjectName(QStringLiteral("label_Battery_18"));
        label_Battery_18->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_18->setFont(font);
        label_Battery_19 = new QLabel(widget_Battery_New_6);
        label_Battery_19->setObjectName(QStringLiteral("label_Battery_19"));
        label_Battery_19->setGeometry(QRect(30, 30, 111, 51));
        label_Battery_19->setFont(font1);
        widget_Battery_New_7 = new BatteryNew(centralWidget);
        widget_Battery_New_7->setObjectName(QStringLiteral("widget_Battery_New_7"));
        widget_Battery_New_7->setGeometry(QRect(190, 80, 160, 190));
        widget_Battery_New_7->setProperty("value", QVariant(0));
        label_Battery_20 = new QLabel(widget_Battery_New_7);
        label_Battery_20->setObjectName(QStringLiteral("label_Battery_20"));
        label_Battery_20->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_20->setFont(font);
        label_Battery_21 = new QLabel(widget_Battery_New_7);
        label_Battery_21->setObjectName(QStringLiteral("label_Battery_21"));
        label_Battery_21->setGeometry(QRect(40, 30, 81, 51));
        label_Battery_21->setFont(font1);
        widget_Battery_New_8 = new BatteryNew(centralWidget);
        widget_Battery_New_8->setObjectName(QStringLiteral("widget_Battery_New_8"));
        widget_Battery_New_8->setGeometry(QRect(360, 80, 160, 190));
        widget_Battery_New_8->setProperty("value", QVariant(0));
        label_Battery_22 = new QLabel(widget_Battery_New_8);
        label_Battery_22->setObjectName(QStringLiteral("label_Battery_22"));
        label_Battery_22->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_22->setFont(font);
        label_Battery_23 = new QLabel(widget_Battery_New_8);
        label_Battery_23->setObjectName(QStringLiteral("label_Battery_23"));
        label_Battery_23->setGeometry(QRect(50, 30, 81, 51));
        label_Battery_23->setFont(font1);
        widget_Battery_New_9 = new BatteryNew(centralWidget);
        widget_Battery_New_9->setObjectName(QStringLiteral("widget_Battery_New_9"));
        widget_Battery_New_9->setGeometry(QRect(20, 80, 160, 190));
        widget_Battery_New_9->setProperty("value", QVariant(0));
        label_Battery_26 = new QLabel(widget_Battery_New_9);
        label_Battery_26->setObjectName(QStringLiteral("label_Battery_26"));
        label_Battery_26->setGeometry(QRect(50, 110, 67, 51));
        label_Battery_26->setFont(font);
        label_Battery_27 = new QLabel(widget_Battery_New_9);
        label_Battery_27->setObjectName(QStringLiteral("label_Battery_27"));
        label_Battery_27->setGeometry(QRect(40, 30, 81, 51));
        label_Battery_27->setFont(font1);
        groupBox_PrintMod1_2 = new QGroupBox(centralWidget);
        groupBox_PrintMod1_2->setObjectName(QStringLiteral("groupBox_PrintMod1_2"));
        groupBox_PrintMod1_2->setGeometry(QRect(760, 270, 151, 301));
        groupBox_PrintMod1_2->setStyleSheet(QLatin1String("      QGroupBox {\n"
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
        pushButton_PrintMod2 = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PrintMod2->setObjectName(QStringLiteral("pushButton_PrintMod2"));
        pushButton_PrintMod2->setGeometry(QRect(10, 20, 131, 31));
        pushButton_PM2_WriteIn = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_WriteIn->setObjectName(QStringLiteral("pushButton_PM2_WriteIn"));
        pushButton_PM2_WriteIn->setGeometry(QRect(10, 60, 130, 31));
        pushButton_PM2_WriteOut = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_WriteOut->setObjectName(QStringLiteral("pushButton_PM2_WriteOut"));
        pushButton_PM2_WriteOut->setGeometry(QRect(10, 100, 130, 31));
        pushButton_PM2_Long = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_Long->setObjectName(QStringLiteral("pushButton_PM2_Long"));
        pushButton_PM2_Long->setGeometry(QRect(10, 260, 130, 31));
        pushButton_PM2_POut = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_POut->setObjectName(QStringLiteral("pushButton_PM2_POut"));
        pushButton_PM2_POut->setGeometry(QRect(10, 180, 130, 31));
        pushButton_PM2_S2Out = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_S2Out->setObjectName(QStringLiteral("pushButton_PM2_S2Out"));
        pushButton_PM2_S2Out->setGeometry(QRect(10, 220, 130, 31));
        pushButton_PM2_PIn = new QPushButton(groupBox_PrintMod1_2);
        pushButton_PM2_PIn->setObjectName(QStringLiteral("pushButton_PM2_PIn"));
        pushButton_PM2_PIn->setGeometry(QRect(10, 140, 130, 31));
        groupBox_PrintMod1_3 = new QGroupBox(centralWidget);
        groupBox_PrintMod1_3->setObjectName(QStringLiteral("groupBox_PrintMod1_3"));
        groupBox_PrintMod1_3->setGeometry(QRect(600, 270, 151, 301));
        groupBox_PrintMod1_3->setStyleSheet(QLatin1String("      QGroupBox {\n"
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
        pushButton_PrintMod2_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PrintMod2_2->setObjectName(QStringLiteral("pushButton_PrintMod2_2"));
        pushButton_PrintMod2_2->setGeometry(QRect(10, 20, 131, 31));
        pushButton_PM2_WriteIn_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_WriteIn_2->setObjectName(QStringLiteral("pushButton_PM2_WriteIn_2"));
        pushButton_PM2_WriteIn_2->setGeometry(QRect(10, 60, 130, 31));
        pushButton_PM2_WriteOut_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_WriteOut_2->setObjectName(QStringLiteral("pushButton_PM2_WriteOut_2"));
        pushButton_PM2_WriteOut_2->setGeometry(QRect(10, 100, 130, 31));
        pushButton_PM2_Long_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_Long_2->setObjectName(QStringLiteral("pushButton_PM2_Long_2"));
        pushButton_PM2_Long_2->setGeometry(QRect(10, 260, 130, 31));
        pushButton_PM2_POut_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_POut_2->setObjectName(QStringLiteral("pushButton_PM2_POut_2"));
        pushButton_PM2_POut_2->setGeometry(QRect(10, 180, 130, 31));
        pushButton_PM2_S2Out_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_S2Out_2->setObjectName(QStringLiteral("pushButton_PM2_S2Out_2"));
        pushButton_PM2_S2Out_2->setGeometry(QRect(10, 220, 130, 31));
        pushButton_PM2_PIn_2 = new QPushButton(groupBox_PrintMod1_3);
        pushButton_PM2_PIn_2->setObjectName(QStringLiteral("pushButton_PM2_PIn_2"));
        pushButton_PM2_PIn_2->setGeometry(QRect(10, 140, 130, 31));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(2, 0, 1551, 41));
        textEdit_Send = new QTextEdit(centralWidget);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(90, 590, 461, 171));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 610, 31, 17));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(570, 600, 31, 17));
        lightButton1 = new LightButton(centralWidget);
        lightButton1->setObjectName(QStringLiteral("lightButton1"));
        lightButton1->setGeometry(QRect(840, 920, 100, 100));
        statusBar = new QWidget(centralWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setGeometry(QRect(2, 1048, 1552, 30));
        label_23 = new QLabel(statusBar);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 3, 71, 23));
        label_23->setFont(font2);
        progressBar_DataPercent = new QProgressBar(statusBar);
        progressBar_DataPercent->setObjectName(QStringLiteral("progressBar_DataPercent"));
        progressBar_DataPercent->setGeometry(QRect(80, 4, 321, 23));
        progressBar_DataPercent->setValue(24);
        label_24 = new QLabel(statusBar);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(420, 3, 131, 23));
        label_24->setFont(font2);
        pushButton_ConnectDB = new QPushButton(centralWidget);
        pushButton_ConnectDB->setObjectName(QStringLiteral("pushButton_ConnectDB"));
        pushButton_ConnectDB->setGeometry(QRect(1240, 720, 141, 141));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\210\266\344\275\234\347\250\213\345\272\217", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\217\221\345\215\241\345\231\250", 0));
        pushButton_SendCardInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_SendCard->setText(QApplication::translate("MainWindow", "\345\217\221\345\215\241", 0));
        pushButton_Stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", 0));
        pushButton_Start->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", 0));
        pushButton_Pause->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234", 0));
        groupBox_SendMod->setTitle(QApplication::translate("MainWindow", "\350\277\233\345\215\241\346\234\272\346\236\204", 0));
        pushButton_SmInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_SmFlipin->setText(QApplication::translate("MainWindow", "\350\275\254\345\220\221\350\277\233\345\215\241", 0));
        pushButton_SmFlipout->setText(QApplication::translate("MainWindow", "\350\275\254\345\220\221\345\207\272\345\215\241", 0));
        pushButton_SmCleanIn->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\201\350\277\233\345\215\241", 0));
        pushButton_SmCleanOut->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\201\345\207\272\345\215\241", 0));
        pushButton_SmCleanCache->setText(QApplication::translate("MainWindow", "\347\274\223\345\206\262\345\207\272\345\215\241", 0));
        groupBox_PrintMod1->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\250\241\345\235\2271", 0));
        pushButton_PrintMod1->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM1_WriteIn->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\350\277\233\345\215\241", 0));
        pushButton_PM1_WriteOut->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\345\207\272\345\215\241", 0));
        pushButton_PM1_Long->setText(QApplication::translate("MainWindow", "\351\225\277\350\275\250\351\201\223\350\277\207\345\215\241", 0));
        pushButton_PM1_POut->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\345\207\272\345\215\241", 0));
        pushButton_PM1_S2Out->setText(QApplication::translate("MainWindow", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_PM1_PIn->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\350\277\233\345\215\241", 0));
        groupBox_Lam->setTitle(QApplication::translate("MainWindow", "\350\246\206\350\206\234\346\250\241\345\235\227", 0));
        pushButton_LamModInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_SmFlipin_5->setText(QApplication::translate("MainWindow", "\345\217\257\346\223\246\345\206\231\345\207\272\345\215\241", 0));
        pushButton_SmFlipin_6->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\201\350\277\233\345\215\241", 0));
        pushButton_SmFlipin_7->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\201\345\207\272\345\215\241", 0));
        pushButton_SmFlipin_8->setText(QApplication::translate("MainWindow", "\345\217\257\346\223\246\345\206\231\350\277\233\345\215\241", 0));
        pushButton_SmFlipin_9->setText(QApplication::translate("MainWindow", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        groupBox_Sort->setTitle(QApplication::translate("MainWindow", "\345\210\206\346\213\243\346\250\241\345\235\227", 0));
        pushButton_SortModInit->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_SmFlipin_10->setText(QApplication::translate("MainWindow", "\347\237\253\346\255\243\350\277\233\345\215\241", 0));
        pushButton_SmFlipin_11->setText(QApplication::translate("MainWindow", "\347\237\253\346\255\243\345\207\272\345\215\241", 0));
        pushButton_SmFlipin_13->setText(QApplication::translate("MainWindow", "\350\257\273\345\215\241\345\231\250\350\277\233\345\215\241", 0));
        pushButton_SmFlipin_14->setText(QApplication::translate("MainWindow", "\350\257\273\345\215\241\345\231\250\345\207\272\345\215\241", 0));
        pushButton_SmFlipin_12->setText(QApplication::translate("MainWindow", "\351\225\277\350\275\250\351\201\223\345\207\272\345\215\241", 0));
        label_Battery_2->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_3->setText(QApplication::translate("MainWindow", "\350\211\262\345\270\246\357\274\222", 0));
        label_Battery_4->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_5->setText(QApplication::translate("MainWindow", "\350\206\234\345\270\246\357\274\222", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "CIS\346\240\270\351\252\214", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "\350\277\207\345\215\241", 0));
        label_2->setText(QApplication::translate("MainWindow", "\345\215\241\346\247\2751", 0));
        label_3->setText(QApplication::translate("MainWindow", "\345\215\241\346\247\2752", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\215\241\346\247\2753", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\215\241\346\247\2754", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220\357\274\232", 0));
        label_7->setText(QApplication::translate("MainWindow", "0", 0));
        label_8->setText(QApplication::translate("MainWindow", "0", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\207\272\351\224\231\357\274\232", 0));
        label_10->setText(QApplication::translate("MainWindow", "0", 0));
        label_11->setText(QApplication::translate("MainWindow", "0", 0));
        label_12->setText(QApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220\357\274\232", 0));
        label_13->setText(QApplication::translate("MainWindow", "\345\207\272\351\224\231\357\274\232", 0));
        label_14->setText(QApplication::translate("MainWindow", "0", 0));
        label_15->setText(QApplication::translate("MainWindow", "0", 0));
        label_16->setText(QApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220\357\274\232", 0));
        label_17->setText(QApplication::translate("MainWindow", "\345\207\272\351\224\231\357\274\232", 0));
        label_18->setText(QApplication::translate("MainWindow", "0", 0));
        label_19->setText(QApplication::translate("MainWindow", "0", 0));
        label_20->setText(QApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220\357\274\232", 0));
        label_21->setText(QApplication::translate("MainWindow", "\345\207\272\351\224\231\357\274\232", 0));
        pushButton_AllInit->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\345\210\235\345\247\213\345\214\226", 0));
        label_Battery_10->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_11->setText(QApplication::translate("MainWindow", "\350\206\234\345\270\246\357\274\221", 0));
        label_Battery_12->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_13->setText(QApplication::translate("MainWindow", "\350\211\262\345\270\246\357\274\221", 0));
        label_Battery_16->setText(QApplication::translate("MainWindow", "\357\274\221", 0));
        label_Battery_17->setText(QApplication::translate("MainWindow", "\345\215\241\346\225\260\351\207\217", 0));
        label_Battery_18->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_19->setText(QApplication::translate("MainWindow", "\346\270\205\346\264\201\346\234\272\346\236\204", 0));
        label_Battery_20->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_21->setText(QApplication::translate("MainWindow", "\350\206\234\345\270\246\357\274\223", 0));
        label_Battery_22->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_23->setText(QApplication::translate("MainWindow", "\350\211\262\345\270\246\357\274\223", 0));
        label_Battery_26->setText(QApplication::translate("MainWindow", "10", 0));
        label_Battery_27->setText(QApplication::translate("MainWindow", "\351\230\262\344\274\252\350\206\234", 0));
        groupBox_PrintMod1_2->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\250\241\345\235\2272", 0));
        pushButton_PrintMod2->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM2_WriteIn->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\350\277\233\345\215\241", 0));
        pushButton_PM2_WriteOut->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\345\207\272\345\215\241", 0));
        pushButton_PM2_Long->setText(QApplication::translate("MainWindow", "\351\225\277\350\275\250\351\201\223\350\277\207\345\215\241", 0));
        pushButton_PM2_POut->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\345\207\272\345\215\241", 0));
        pushButton_PM2_S2Out->setText(QApplication::translate("MainWindow", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_PM2_PIn->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\350\277\233\345\215\241", 0));
        groupBox_PrintMod1_3->setTitle(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\250\241\345\235\2273", 0));
        pushButton_PrintMod2_2->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_PM2_WriteIn_2->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\350\277\233\345\215\241", 0));
        pushButton_PM2_WriteOut_2->setText(QApplication::translate("MainWindow", "\345\206\231\345\215\241\345\207\272\345\215\241", 0));
        pushButton_PM2_Long_2->setText(QApplication::translate("MainWindow", "\351\225\277\350\275\250\351\201\223\350\277\207\345\215\241", 0));
        pushButton_PM2_POut_2->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\345\207\272\345\215\241", 0));
        pushButton_PM2_S2Out_2->setText(QApplication::translate("MainWindow", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_PM2_PIn_2->setText(QApplication::translate("MainWindow", "\346\211\223\345\215\260\346\234\272\350\277\233\345\215\241", 0));
        label->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", 0));
        label_22->setText(QApplication::translate("MainWindow", "\346\216\245\346\224\266", 0));
        label_23->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\214\205", 0));
        label_24->setText(QApplication::translate("MainWindow", "1\346\235\241\345\276\205\345\210\266\350\257\201\346\225\260\346\215\256", 0));
        pushButton_ConnectDB->setText(QApplication::translate("MainWindow", "Oracle", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
