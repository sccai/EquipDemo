/********************************************************************************
** Form generated from reading UI file 'concurrentform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONCURRENTFORM_H
#define UI_CONCURRENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConcurrentForm
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *ConcurrentForm)
    {
        if (ConcurrentForm->objectName().isEmpty())
            ConcurrentForm->setObjectName(QStringLiteral("ConcurrentForm"));
        ConcurrentForm->resize(570, 476);
        pushButton = new QPushButton(ConcurrentForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 50, 97, 26));
        pushButton_2 = new QPushButton(ConcurrentForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 100, 97, 26));
        pushButton_3 = new QPushButton(ConcurrentForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 80, 97, 26));
        pushButton_4 = new QPushButton(ConcurrentForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 300, 102, 26));
        pushButton_5 = new QPushButton(ConcurrentForm);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(370, 160, 97, 26));
        pushButton_6 = new QPushButton(ConcurrentForm);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(370, 220, 97, 26));

        retranslateUi(ConcurrentForm);

        QMetaObject::connectSlotsByName(ConcurrentForm);
    } // setupUi

    void retranslateUi(QWidget *ConcurrentForm)
    {
        ConcurrentForm->setWindowTitle(QApplication::translate("ConcurrentForm", "Form", 0));
        pushButton->setText(QApplication::translate("ConcurrentForm", "Start", 0));
        pushButton_2->setText(QApplication::translate("ConcurrentForm", "\345\244\232\347\272\277\347\250\213\345\220\257\345\212\250", 0));
        pushButton_3->setText(QApplication::translate("ConcurrentForm", "\345\201\234\346\255\242", 0));
        pushButton_4->setText(QApplication::translate("ConcurrentForm", "\350\277\220\350\241\214Python", 0));
        pushButton_5->setText(QApplication::translate("ConcurrentForm", "\346\265\213\350\257\225", 0));
        pushButton_6->setText(QApplication::translate("ConcurrentForm", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class ConcurrentForm: public Ui_ConcurrentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONCURRENTFORM_H
