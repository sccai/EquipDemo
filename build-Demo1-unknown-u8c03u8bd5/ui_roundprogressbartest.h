/********************************************************************************
** Form generated from reading UI file 'roundprogressbartest.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROUNDPROGRESSBARTEST_H
#define UI_ROUNDPROGRESSBARTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "roundprogressbar.h"

QT_BEGIN_NAMESPACE

class Ui_RoundProgressBarTest
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    RoundProgressBar *roundBar2;
    RoundProgressBar *roundBar1;
    RoundProgressBar *roundBar4;
    RoundProgressBar *roundBar6;
    RoundProgressBar *roundBar5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    RoundProgressBar *roundBar3;
    QHBoxLayout *horizontalLayout;
    QCheckBox *base_circle_ckb;
    QCheckBox *data_circle_ckb;
    QCheckBox *center_circle_ckb;
    QCheckBox *text_ckb;
    QPushButton *pushButton;
    QSlider *valueSlider;

    void setupUi(QWidget *RoundProgressBarTest)
    {
        if (RoundProgressBarTest->objectName().isEmpty())
            RoundProgressBarTest->setObjectName(QStringLiteral("RoundProgressBarTest"));
        RoundProgressBarTest->resize(930, 673);
        RoundProgressBarTest->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(RoundProgressBarTest);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        roundBar2 = new RoundProgressBar(RoundProgressBarTest);
        roundBar2->setObjectName(QStringLiteral("roundBar2"));

        gridLayout->addWidget(roundBar2, 1, 1, 1, 1);

        roundBar1 = new RoundProgressBar(RoundProgressBarTest);
        roundBar1->setObjectName(QStringLiteral("roundBar1"));

        gridLayout->addWidget(roundBar1, 1, 0, 1, 1);

        roundBar4 = new RoundProgressBar(RoundProgressBarTest);
        roundBar4->setObjectName(QStringLiteral("roundBar4"));

        gridLayout->addWidget(roundBar4, 2, 0, 1, 1);

        roundBar6 = new RoundProgressBar(RoundProgressBarTest);
        roundBar6->setObjectName(QStringLiteral("roundBar6"));

        gridLayout->addWidget(roundBar6, 2, 2, 1, 1);

        roundBar5 = new RoundProgressBar(RoundProgressBarTest);
        roundBar5->setObjectName(QStringLiteral("roundBar5"));

        gridLayout->addWidget(roundBar5, 2, 1, 1, 1);

        label_3 = new QLabel(RoundProgressBarTest);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_2 = new QLabel(RoundProgressBarTest);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(RoundProgressBarTest);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        roundBar3 = new RoundProgressBar(RoundProgressBarTest);
        roundBar3->setObjectName(QStringLiteral("roundBar3"));

        gridLayout->addWidget(roundBar3, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        base_circle_ckb = new QCheckBox(RoundProgressBarTest);
        base_circle_ckb->setObjectName(QStringLiteral("base_circle_ckb"));
        base_circle_ckb->setChecked(true);

        horizontalLayout->addWidget(base_circle_ckb);

        data_circle_ckb = new QCheckBox(RoundProgressBarTest);
        data_circle_ckb->setObjectName(QStringLiteral("data_circle_ckb"));
        data_circle_ckb->setChecked(true);

        horizontalLayout->addWidget(data_circle_ckb);

        center_circle_ckb = new QCheckBox(RoundProgressBarTest);
        center_circle_ckb->setObjectName(QStringLiteral("center_circle_ckb"));
        center_circle_ckb->setChecked(true);

        horizontalLayout->addWidget(center_circle_ckb);

        text_ckb = new QCheckBox(RoundProgressBarTest);
        text_ckb->setObjectName(QStringLiteral("text_ckb"));
        text_ckb->setChecked(true);

        horizontalLayout->addWidget(text_ckb);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(RoundProgressBarTest);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        valueSlider = new QSlider(RoundProgressBarTest);
        valueSlider->setObjectName(QStringLiteral("valueSlider"));
        valueSlider->setMaximum(100);
        valueSlider->setValue(30);
        valueSlider->setOrientation(Qt::Horizontal);
        valueSlider->setTickPosition(QSlider::TicksBothSides);
        valueSlider->setTickInterval(10);

        verticalLayout->addWidget(valueSlider);


        retranslateUi(RoundProgressBarTest);

        QMetaObject::connectSlotsByName(RoundProgressBarTest);
    } // setupUi

    void retranslateUi(QWidget *RoundProgressBarTest)
    {
        RoundProgressBarTest->setWindowTitle(QApplication::translate("RoundProgressBarTest", "\345\234\206\345\275\242\350\277\233\345\272\246\346\235\241", 0));
        label_3->setText(QApplication::translate("RoundProgressBarTest", "\347\272\277\346\235\241\351\243\216\346\240\274", 0));
        label_2->setText(QApplication::translate("RoundProgressBarTest", "\351\245\274\347\212\266\351\243\216\346\240\274", 0));
        label->setText(QApplication::translate("RoundProgressBarTest", "\345\234\206\347\216\257\351\243\216\346\240\274", 0));
        base_circle_ckb->setText(QApplication::translate("RoundProgressBarTest", "\345\244\226\345\234\206", 0));
        data_circle_ckb->setText(QApplication::translate("RoundProgressBarTest", "\346\225\260\346\215\256\345\234\206", 0));
        center_circle_ckb->setText(QApplication::translate("RoundProgressBarTest", "\345\206\205\345\234\206", 0));
        text_ckb->setText(QApplication::translate("RoundProgressBarTest", "\346\226\207\345\255\227", 0));
        pushButton->setText(QApplication::translate("RoundProgressBarTest", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class RoundProgressBarTest: public Ui_RoundProgressBarTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROUNDPROGRESSBARTEST_H
