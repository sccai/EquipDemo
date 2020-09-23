/********************************************************************************
** Form generated from reading UI file 'lamform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAMFORM_H
#define UI_LAMFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LamForm
{
public:
    QGroupBox *groupBox_Lam;
    QPushButton *pushButton_LamModInit;
    QPushButton *pushButton_LamCleanSlide;
    QPushButton *pushButton_LamShortSlideOut;
    QPushButton *pushButton_LamCacheCardIn;
    QPushButton *pushButton_LamCacheCardOut;
    QPushButton *pushButton_LamCleanCardIn;
    QPushButton *pushButton_LamCleanCardOut;
    QPushButton *pushButton_LamShortSlide2In;
    QTextEdit *textEdit_Send;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *LamForm)
    {
        if (LamForm->objectName().isEmpty())
            LamForm->setObjectName(QStringLiteral("LamForm"));
        LamForm->resize(991, 781);
        groupBox_Lam = new QGroupBox(LamForm);
        groupBox_Lam->setObjectName(QStringLiteral("groupBox_Lam"));
        groupBox_Lam->setGeometry(QRect(60, 70, 871, 141));
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
        pushButton_LamShortSlideOut = new QPushButton(groupBox_Lam);
        pushButton_LamShortSlideOut->setObjectName(QStringLiteral("pushButton_LamShortSlideOut"));
        pushButton_LamShortSlideOut->setGeometry(QRect(710, 70, 130, 31));
        pushButton_LamCacheCardIn = new QPushButton(groupBox_Lam);
        pushButton_LamCacheCardIn->setObjectName(QStringLiteral("pushButton_LamCacheCardIn"));
        pushButton_LamCacheCardIn->setGeometry(QRect(10, 70, 130, 31));
        pushButton_LamCacheCardOut = new QPushButton(groupBox_Lam);
        pushButton_LamCacheCardOut->setObjectName(QStringLiteral("pushButton_LamCacheCardOut"));
        pushButton_LamCacheCardOut->setGeometry(QRect(150, 70, 130, 31));
        pushButton_LamCleanCardIn = new QPushButton(groupBox_Lam);
        pushButton_LamCleanCardIn->setObjectName(QStringLiteral("pushButton_LamCleanCardIn"));
        pushButton_LamCleanCardIn->setGeometry(QRect(290, 70, 130, 31));
        pushButton_LamCleanCardOut = new QPushButton(groupBox_Lam);
        pushButton_LamCleanCardOut->setObjectName(QStringLiteral("pushButton_LamCleanCardOut"));
        pushButton_LamCleanCardOut->setGeometry(QRect(430, 70, 130, 31));
        pushButton_LamShortSlide2In = new QPushButton(groupBox_Lam);
        pushButton_LamShortSlide2In->setObjectName(QStringLiteral("pushButton_LamShortSlide2In"));
        pushButton_LamShortSlide2In->setGeometry(QRect(570, 70, 130, 31));
        textEdit_Send = new QTextEdit(LamForm);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(30, 270, 440, 211));
        textEdit_Send->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(LamForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 270, 41, 21));
        QFont font;
        font.setPointSize(8);
        label_2->setFont(font);
        textEdit = new QTextEdit(LamForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(530, 270, 440, 211));
        textEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label = new QLabel(LamForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 270, 31, 17));
        label->setFont(font);

        retranslateUi(LamForm);

        QMetaObject::connectSlotsByName(LamForm);
    } // setupUi

    void retranslateUi(QWidget *LamForm)
    {
        LamForm->setWindowTitle(QApplication::translate("LamForm", "Form", 0));
        groupBox_Lam->setTitle(QApplication::translate("LamForm", "\350\246\206\350\206\234\346\250\241\345\235\227", 0));
        pushButton_LamModInit->setText(QApplication::translate("LamForm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_LamCleanSlide->setText(QApplication::translate("LamForm", "\346\270\205\346\264\201\350\275\250\351\201\223", 0));
        pushButton_LamShortSlideOut->setText(QApplication::translate("LamForm", "\350\275\250\351\201\2232\345\207\272\345\215\241", 0));
        pushButton_LamCacheCardIn->setText(QApplication::translate("LamForm", "CacheCardIn", 0));
        pushButton_LamCacheCardOut->setText(QApplication::translate("LamForm", "CacheCardOut", 0));
        pushButton_LamCleanCardIn->setText(QApplication::translate("LamForm", "CleanCardIn", 0));
        pushButton_LamCleanCardOut->setText(QApplication::translate("LamForm", "CleanCardOut", 0));
        pushButton_LamShortSlide2In->setText(QApplication::translate("LamForm", "\350\275\250\351\201\2232CardIn", 0));
        label_2->setText(QApplication::translate("LamForm", "Receive", 0));
        label->setText(QApplication::translate("LamForm", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class LamForm: public Ui_LamForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAMFORM_H
