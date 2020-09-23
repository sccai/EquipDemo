/********************************************************************************
** Form generated from reading UI file 'printform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTFORM_H
#define UI_PRINTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrintForm
{
public:
    QPushButton *pushButton_InitDevice;
    QPushButton *pushButton_LoadTask;
    QPushButton *pushButton_FeedPrint;
    QPushButton *pushButton_EjectCard;
    QTextEdit *txt_IP;
    QLabel *label;
    QPushButton *pushButton_FrontImg;
    QPushButton *pushButton_BackImg;
    QWidget *widget;
    QLabel *label_front_img;
    QWidget *widget_2;
    QLabel *label_back_img;
    QPushButton *pushButton_GetStatus;
    QTextEdit *textEdit_2;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QLabel *label_3;
    QTextEdit *textEdit_4;
    QLabel *label_4;
    QTextEdit *txt_Main;
    QLabel *label_5;
    QTextEdit *txt_Sub;
    QLabel *label_6;
    QTextEdit *txt_Warn;
    QLabel *label_7;
    QTextEdit *textEdit_Log;
    QCheckBox *chkSimu;
    QCheckBox *chkDoublePrint;
    QTextEdit *txt_FrontPath;
    QTextEdit *txt_BackPath;
    QPushButton *pushButton_RunLoad;
    QPushButton *pushButton_RunFeed;
    QPushButton *pushButton_RunEjectCard;
    QLineEdit *lineEdit;

    void setupUi(QWidget *PrintForm)
    {
        if (PrintForm->objectName().isEmpty())
            PrintForm->setObjectName(QStringLiteral("PrintForm"));
        PrintForm->resize(954, 627);
        PrintForm->setStyleSheet(QStringLiteral(""));
        pushButton_InitDevice = new QPushButton(PrintForm);
        pushButton_InitDevice->setObjectName(QStringLiteral("pushButton_InitDevice"));
        pushButton_InitDevice->setGeometry(QRect(30, 140, 121, 26));
        pushButton_InitDevice->setStyleSheet(QStringLiteral(""));
        pushButton_LoadTask = new QPushButton(PrintForm);
        pushButton_LoadTask->setObjectName(QStringLiteral("pushButton_LoadTask"));
        pushButton_LoadTask->setGeometry(QRect(30, 180, 121, 26));
        pushButton_FeedPrint = new QPushButton(PrintForm);
        pushButton_FeedPrint->setObjectName(QStringLiteral("pushButton_FeedPrint"));
        pushButton_FeedPrint->setGeometry(QRect(30, 220, 121, 26));
        pushButton_EjectCard = new QPushButton(PrintForm);
        pushButton_EjectCard->setObjectName(QStringLiteral("pushButton_EjectCard"));
        pushButton_EjectCard->setGeometry(QRect(30, 260, 121, 26));
        txt_IP = new QTextEdit(PrintForm);
        txt_IP->setObjectName(QStringLiteral("txt_IP"));
        txt_IP->setGeometry(QRect(130, 60, 131, 31));
        label = new QLabel(PrintForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 81, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        pushButton_FrontImg = new QPushButton(PrintForm);
        pushButton_FrontImg->setObjectName(QStringLiteral("pushButton_FrontImg"));
        pushButton_FrontImg->setGeometry(QRect(200, 340, 111, 26));
        pushButton_BackImg = new QPushButton(PrintForm);
        pushButton_BackImg->setObjectName(QStringLiteral("pushButton_BackImg"));
        pushButton_BackImg->setGeometry(QRect(550, 340, 97, 26));
        widget = new QWidget(PrintForm);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(200, 140, 310, 190));
        widget->setStyleSheet(QLatin1String("      QWidget#widget{\n"
"            border-color: #d1d5d6;\n"
"            border-width: 2px;\n"
"            border-style: dotted ;\n"
"background-color: rgb(255, 255, 255);\n"
"        }\n"
"\n"
""));
        label_front_img = new QLabel(widget);
        label_front_img->setObjectName(QStringLiteral("label_front_img"));
        label_front_img->setGeometry(QRect(10, 10, 291, 171));
        widget_2 = new QWidget(PrintForm);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(550, 140, 310, 190));
        widget_2->setStyleSheet(QLatin1String("      QWidget#widget_2{\n"
"            border-color: #d1d5d6;\n"
"            border-width: 2px;\n"
"            border-style: dotted ;\n"
"background-color: rgb(255, 255, 255);\n"
"        }"));
        label_back_img = new QLabel(widget_2);
        label_back_img->setObjectName(QStringLiteral("label_back_img"));
        label_back_img->setGeometry(QRect(10, 10, 291, 171));
        pushButton_GetStatus = new QPushButton(PrintForm);
        pushButton_GetStatus->setObjectName(QStringLiteral("pushButton_GetStatus"));
        pushButton_GetStatus->setGeometry(QRect(30, 300, 121, 26));
        textEdit_2 = new QTextEdit(PrintForm);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(250, 440, 51, 31));
        label_2 = new QLabel(PrintForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 440, 71, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setFrameShape(QFrame::NoFrame);
        label_2->setLineWidth(1);
        textEdit_3 = new QTextEdit(PrintForm);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(250, 480, 51, 31));
        label_3 = new QLabel(PrintForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(180, 480, 51, 31));
        label_3->setFont(font);
        textEdit_4 = new QTextEdit(PrintForm);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setGeometry(QRect(250, 520, 51, 31));
        label_4 = new QLabel(PrintForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(180, 520, 51, 31));
        label_4->setFont(font);
        txt_Main = new QTextEdit(PrintForm);
        txt_Main->setObjectName(QStringLiteral("txt_Main"));
        txt_Main->setGeometry(QRect(430, 440, 91, 31));
        label_5 = new QLabel(PrintForm);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 440, 91, 31));
        label_5->setFont(font1);
        txt_Sub = new QTextEdit(PrintForm);
        txt_Sub->setObjectName(QStringLiteral("txt_Sub"));
        txt_Sub->setGeometry(QRect(430, 480, 91, 31));
        label_6 = new QLabel(PrintForm);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 480, 91, 31));
        label_6->setFont(font1);
        txt_Warn = new QTextEdit(PrintForm);
        txt_Warn->setObjectName(QStringLiteral("txt_Warn"));
        txt_Warn->setGeometry(QRect(430, 520, 91, 31));
        label_7 = new QLabel(PrintForm);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(330, 520, 91, 31));
        label_7->setFont(font1);
        textEdit_Log = new QTextEdit(PrintForm);
        textEdit_Log->setObjectName(QStringLiteral("textEdit_Log"));
        textEdit_Log->setGeometry(QRect(560, 410, 371, 211));
        textEdit_Log->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        chkSimu = new QCheckBox(PrintForm);
        chkSimu->setObjectName(QStringLiteral("chkSimu"));
        chkSimu->setGeometry(QRect(40, 360, 121, 22));
        chkSimu->setChecked(true);
        chkDoublePrint = new QCheckBox(PrintForm);
        chkDoublePrint->setObjectName(QStringLiteral("chkDoublePrint"));
        chkDoublePrint->setGeometry(QRect(40, 390, 121, 22));
        chkDoublePrint->setChecked(false);
        txt_FrontPath = new QTextEdit(PrintForm);
        txt_FrontPath->setObjectName(QStringLiteral("txt_FrontPath"));
        txt_FrontPath->setGeometry(QRect(200, 370, 311, 31));
        txt_BackPath = new QTextEdit(PrintForm);
        txt_BackPath->setObjectName(QStringLiteral("txt_BackPath"));
        txt_BackPath->setGeometry(QRect(550, 370, 311, 31));
        pushButton_RunLoad = new QPushButton(PrintForm);
        pushButton_RunLoad->setObjectName(QStringLiteral("pushButton_RunLoad"));
        pushButton_RunLoad->setGeometry(QRect(20, 460, 141, 26));
        pushButton_RunFeed = new QPushButton(PrintForm);
        pushButton_RunFeed->setObjectName(QStringLiteral("pushButton_RunFeed"));
        pushButton_RunFeed->setGeometry(QRect(20, 490, 141, 26));
        pushButton_RunEjectCard = new QPushButton(PrintForm);
        pushButton_RunEjectCard->setObjectName(QStringLiteral("pushButton_RunEjectCard"));
        pushButton_RunEjectCard->setGeometry(QRect(20, 520, 141, 26));
        lineEdit = new QLineEdit(PrintForm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 590, 113, 27));

        retranslateUi(PrintForm);

        QMetaObject::connectSlotsByName(PrintForm);
    } // setupUi

    void retranslateUi(QWidget *PrintForm)
    {
        PrintForm->setWindowTitle(QApplication::translate("PrintForm", "Form", 0));
        pushButton_InitDevice->setText(QApplication::translate("PrintForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_LoadTask->setText(QApplication::translate("PrintForm", "\344\270\213\350\275\275\346\211\223\345\215\260\344\273\273\345\212\241", 0));
        pushButton_FeedPrint->setText(QApplication::translate("PrintForm", "\350\277\233\345\215\241\346\211\223\345\215\260", 0));
        pushButton_EjectCard->setText(QApplication::translate("PrintForm", "\345\207\272\345\215\241", 0));
        txt_IP->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">192.168.150.101</p></body></html>", 0));
        label->setText(QApplication::translate("PrintForm", "IP:", 0));
        pushButton_FrontImg->setText(QApplication::translate("PrintForm", "\351\200\211\346\213\251\346\255\243\351\235\242\345\233\276\345\203\217", 0));
        pushButton_BackImg->setText(QApplication::translate("PrintForm", "\351\200\211\346\213\251\350\203\214\351\235\242\345\233\276\345\203\217", 0));
        label_front_img->setText(QString());
        label_back_img->setText(QString());
        pushButton_GetStatus->setText(QApplication::translate("PrintForm", "\346\237\245\350\257\242\346\211\223\345\215\260\346\234\272\347\212\266\346\200\201", 0));
        textEdit_2->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_2->setText(QApplication::translate("PrintForm", "Ribbon:", 0));
        textEdit_3->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_3->setText(QApplication::translate("PrintForm", "Film:", 0));
        textEdit_4->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_4->setText(QApplication::translate("PrintForm", "Temp:", 0));
        txt_Main->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_5->setText(QApplication::translate("PrintForm", "Mainstatus", 0));
        txt_Sub->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_6->setText(QApplication::translate("PrintForm", "SubStatus:", 0));
        txt_Warn->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_7->setText(QApplication::translate("PrintForm", "WarnStatus:", 0));
        chkSimu->setText(QApplication::translate("PrintForm", "\346\250\241\346\213\237\350\277\220\350\241\214\347\212\266\346\200\201", 0));
        chkDoublePrint->setText(QApplication::translate("PrintForm", "\346\230\257\345\220\246\345\217\214\351\235\242\346\211\223\345\215\260", 0));
        txt_FrontPath->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        txt_BackPath->setHtml(QApplication::translate("PrintForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        pushButton_RunLoad->setText(QApplication::translate("PrintForm", "QtConcurrent\344\270\213\350\275\275", 0));
        pushButton_RunFeed->setText(QApplication::translate("PrintForm", "QtConcurrent\350\277\233\345\215\241", 0));
        pushButton_RunEjectCard->setText(QApplication::translate("PrintForm", "QtConcurrent\345\207\272\345\215\241", 0));
        lineEdit->setText(QApplication::translate("PrintForm", "lineEdit", 0));
    } // retranslateUi

};

namespace Ui {
    class PrintForm: public Ui_PrintForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTFORM_H
