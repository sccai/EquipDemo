/********************************************************************************
** Form generated from reading UI file 'sortform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTFORM_H
#define UI_SORTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortForm
{
public:
    QGroupBox *groupBox_Sort;
    QPushButton *pushButton_Sort_AdjustIn;
    QPushButton *pushButton_Sort_AdjustOut;
    QPushButton *pushButton_Sort_OCRReaderIn;
    QPushButton *pushButton_Sort_VerifyIn;
    QPushButton *pushButton_Sort_LongOut;
    QPushButton *pushButton_SortMod_Light;
    QPushButton *pushButton_SortMod_Light_Close;
    QPushButton *pushButton_SortModInit;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QTextEdit *textEdit_Send;
    QLabel *label_2;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *SortForm)
    {
        if (SortForm->objectName().isEmpty())
            SortForm->setObjectName(QStringLiteral("SortForm"));
        SortForm->resize(991, 781);
        groupBox_Sort = new QGroupBox(SortForm);
        groupBox_Sort->setObjectName(QStringLiteral("groupBox_Sort"));
        groupBox_Sort->setGeometry(QRect(100, 90, 781, 201));
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
        pushButton_Sort_AdjustIn = new QPushButton(groupBox_Sort);
        pushButton_Sort_AdjustIn->setObjectName(QStringLiteral("pushButton_Sort_AdjustIn"));
        pushButton_Sort_AdjustIn->setGeometry(QRect(10, 60, 130, 31));
        pushButton_Sort_AdjustOut = new QPushButton(groupBox_Sort);
        pushButton_Sort_AdjustOut->setObjectName(QStringLiteral("pushButton_Sort_AdjustOut"));
        pushButton_Sort_AdjustOut->setGeometry(QRect(150, 60, 130, 31));
        pushButton_Sort_OCRReaderIn = new QPushButton(groupBox_Sort);
        pushButton_Sort_OCRReaderIn->setObjectName(QStringLiteral("pushButton_Sort_OCRReaderIn"));
        pushButton_Sort_OCRReaderIn->setGeometry(QRect(290, 60, 130, 31));
        pushButton_Sort_VerifyIn = new QPushButton(groupBox_Sort);
        pushButton_Sort_VerifyIn->setObjectName(QStringLiteral("pushButton_Sort_VerifyIn"));
        pushButton_Sort_VerifyIn->setGeometry(QRect(430, 60, 130, 31));
        pushButton_Sort_LongOut = new QPushButton(groupBox_Sort);
        pushButton_Sort_LongOut->setObjectName(QStringLiteral("pushButton_Sort_LongOut"));
        pushButton_Sort_LongOut->setGeometry(QRect(570, 60, 130, 31));
        pushButton_SortMod_Light = new QPushButton(groupBox_Sort);
        pushButton_SortMod_Light->setObjectName(QStringLiteral("pushButton_SortMod_Light"));
        pushButton_SortMod_Light->setGeometry(QRect(430, 20, 131, 31));
        pushButton_SortMod_Light_Close = new QPushButton(groupBox_Sort);
        pushButton_SortMod_Light_Close->setObjectName(QStringLiteral("pushButton_SortMod_Light_Close"));
        pushButton_SortMod_Light_Close->setGeometry(QRect(570, 20, 131, 31));
        pushButton_SortModInit = new QPushButton(groupBox_Sort);
        pushButton_SortModInit->setObjectName(QStringLiteral("pushButton_SortModInit"));
        pushButton_SortModInit->setGeometry(QRect(10, 20, 131, 31));
        layoutWidget = new QWidget(groupBox_Sort);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 60, 70, 132));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_1 = new QRadioButton(layoutWidget);
        radioButton_1->setObjectName(QStringLiteral("radioButton_1"));
        radioButton_1->setChecked(true);

        verticalLayout->addWidget(radioButton_1);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(layoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout->addWidget(radioButton_4);

        textEdit_Send = new QTextEdit(SortForm);
        textEdit_Send->setObjectName(QStringLiteral("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(40, 300, 440, 211));
        textEdit_Send->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label_2 = new QLabel(SortForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(500, 300, 41, 21));
        QFont font;
        font.setPointSize(8);
        label_2->setFont(font);
        textEdit = new QTextEdit(SortForm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(540, 300, 440, 211));
        textEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        label = new QLabel(SortForm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 300, 31, 17));
        label->setFont(font);

        retranslateUi(SortForm);

        QMetaObject::connectSlotsByName(SortForm);
    } // setupUi

    void retranslateUi(QWidget *SortForm)
    {
        SortForm->setWindowTitle(QApplication::translate("SortForm", "Form", 0));
        groupBox_Sort->setTitle(QApplication::translate("SortForm", "\345\210\206\346\213\243\346\250\241\345\235\227", 0));
        pushButton_Sort_AdjustIn->setText(QApplication::translate("SortForm", "\347\237\253\346\255\243\350\277\233\345\215\241", 0));
        pushButton_Sort_AdjustOut->setText(QApplication::translate("SortForm", "\347\237\253\346\255\243\345\207\272\345\215\241", 0));
        pushButton_Sort_OCRReaderIn->setText(QApplication::translate("SortForm", "OCR\350\257\206\345\210\253\350\277\233\345\215\241", 0));
        pushButton_Sort_VerifyIn->setText(QApplication::translate("SortForm", "\346\240\270\351\252\214\350\277\233\345\215\241", 0));
        pushButton_Sort_LongOut->setText(QApplication::translate("SortForm", "\345\215\241\346\247\275\345\207\272\345\215\241", 0));
        pushButton_SortMod_Light->setText(QApplication::translate("SortForm", "\351\227\252\347\201\257", 0));
        pushButton_SortMod_Light_Close->setText(QApplication::translate("SortForm", "\345\205\263\347\201\257", 0));
        pushButton_SortModInit->setText(QApplication::translate("SortForm", "\345\210\235\345\247\213\345\214\226", 0));
        radioButton_1->setText(QApplication::translate("SortForm", "\345\215\241\346\247\2751", 0));
        radioButton_2->setText(QApplication::translate("SortForm", "\345\215\241\346\247\2752", 0));
        radioButton_3->setText(QApplication::translate("SortForm", "\345\215\241\346\247\2753", 0));
        radioButton_4->setText(QApplication::translate("SortForm", "\345\215\241\346\247\2754", 0));
        label_2->setText(QApplication::translate("SortForm", "Receive", 0));
        label->setText(QApplication::translate("SortForm", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class SortForm: public Ui_SortForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTFORM_H
