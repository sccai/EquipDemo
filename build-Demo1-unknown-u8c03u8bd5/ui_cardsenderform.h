/********************************************************************************
** Form generated from reading UI file 'cardsenderform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSENDERFORM_H
#define UI_CARDSENDERFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardSenderForm
{
public:
    QTextEdit *sendtextEdit;
    QPushButton *GetPort;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QComboBox *comboBoxComm;
    QPushButton *pushButton_3;
    QTextEdit *receivetextEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_GetStatus;

    void setupUi(QWidget *CardSenderForm)
    {
        if (CardSenderForm->objectName().isEmpty())
            CardSenderForm->setObjectName(QStringLiteral("CardSenderForm"));
        CardSenderForm->resize(697, 539);
        sendtextEdit = new QTextEdit(CardSenderForm);
        sendtextEdit->setObjectName(QStringLiteral("sendtextEdit"));
        sendtextEdit->setGeometry(QRect(240, 140, 421, 141));
        sendtextEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        GetPort = new QPushButton(CardSenderForm);
        GetPort->setObjectName(QStringLiteral("GetPort"));
        GetPort->setGeometry(QRect(280, 30, 97, 26));
        pushButton_4 = new QPushButton(CardSenderForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 260, 97, 26));
        pushButton = new QPushButton(CardSenderForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 110, 97, 26));
        comboBoxComm = new QComboBox(CardSenderForm);
        comboBoxComm->setObjectName(QStringLiteral("comboBoxComm"));
        comboBoxComm->setGeometry(QRect(390, 30, 85, 27));
        pushButton_3 = new QPushButton(CardSenderForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 160, 97, 26));
        receivetextEdit = new QTextEdit(CardSenderForm);
        receivetextEdit->setObjectName(QStringLiteral("receivetextEdit"));
        receivetextEdit->setGeometry(QRect(240, 320, 421, 141));
        receivetextEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label = new QLabel(CardSenderForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 110, 67, 17));
        label_2 = new QLabel(CardSenderForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 290, 67, 17));
        pushButton_GetStatus = new QPushButton(CardSenderForm);
        pushButton_GetStatus->setObjectName(QStringLiteral("pushButton_GetStatus"));
        pushButton_GetStatus->setGeometry(QRect(50, 210, 97, 26));

        retranslateUi(CardSenderForm);

        QMetaObject::connectSlotsByName(CardSenderForm);
    } // setupUi

    void retranslateUi(QWidget *CardSenderForm)
    {
        CardSenderForm->setWindowTitle(QApplication::translate("CardSenderForm", "Form", 0));
        GetPort->setText(QApplication::translate("CardSenderForm", "GetPort", 0));
        pushButton_4->setText(QApplication::translate("CardSenderForm", "CloseDevice", 0));
        pushButton->setText(QApplication::translate("CardSenderForm", "InitDevice", 0));
        pushButton_3->setText(QApplication::translate("CardSenderForm", "SendCard", 0));
        label->setText(QApplication::translate("CardSenderForm", "\345\217\221\351\200\201\346\225\260\346\215\256", 0));
        label_2->setText(QApplication::translate("CardSenderForm", "\346\216\245\346\224\266\346\225\260\346\215\256", 0));
        pushButton_GetStatus->setText(QApplication::translate("CardSenderForm", "GetStatus", 0));
    } // retranslateUi

};

namespace Ui {
    class CardSenderForm: public Ui_CardSenderForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSENDERFORM_H
