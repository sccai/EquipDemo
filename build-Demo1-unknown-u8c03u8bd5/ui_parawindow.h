/********************************************************************************
** Form generated from reading UI file 'parawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAWINDOW_H
#define UI_PARAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>
#include "control/imageswitch.h"

QT_BEGIN_NAMESPACE

class Ui_ParaWindow
{
public:
    QLabel *label_slotTitle1_3;
    QCheckBox *chk_Print2_Print;
    QLabel *label_5;
    QCheckBox *chk_Print3_Reader;
    QCheckBox *chk_Print1_Print;
    QLabel *label_3;
    ImageSwitch *solt4_switch;
    QLineEdit *txt2;
    QCheckBox *chk_Print3_Print;
    QLabel *label_4;
    QPushButton *pushButton_Cancle;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QRadioButton *rbtn1;
    QRadioButton *rbtn2;
    QLineEdit *txt4;
    QLineEdit *txt1;
    QLabel *label_slotTitle1;
    QPushButton *pushButton_Save;
    QCheckBox *chk_Print2_Reader;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QRadioButton *rbtn3;
    QRadioButton *rbtn4;
    ImageSwitch *solt3_switch;
    ImageSwitch *solt1_switch;
    QLabel *label_slotTitle1_4;
    ImageSwitch *solt2_switch;
    QCheckBox *chk_Print1_Reader;
    QLineEdit *txt3;
    QLabel *label_slotTitle1_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QCheckBox *chk_Print1;
    QCheckBox *chk_Print2;
    QCheckBox *chk_Print3;
    QLabel *label_slotTitle1_5;
    ImageSwitch *corder_switch;
    QLabel *label_slotTitle1_6;
    ImageSwitch *ocr_switch;
    QLabel *label_slotTitle1_7;
    ImageSwitch *checkreader_switch;
    QLineEdit *txt_X;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *txt_Y;
    QLabel *label_slotTitle1_8;
    ImageSwitch *use_EP_switch;
    QLabel *label_slotTitle1_9;
    ImageSwitch *clearBeforePrint_switch;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labTitle;
    QLabel *label_setlam;
    ImageSwitch *use_LAM_switch;

    void setupUi(QDialog *ParaWindow)
    {
        if (ParaWindow->objectName().isEmpty())
            ParaWindow->setObjectName(QStringLiteral("ParaWindow"));
        ParaWindow->resize(583, 596);
        label_slotTitle1_3 = new QLabel(ParaWindow);
        label_slotTitle1_3->setObjectName(QStringLiteral("label_slotTitle1_3"));
        label_slotTitle1_3->setGeometry(QRect(310, 470, 39, 23));
        QFont font;
        font.setPointSize(12);
        label_slotTitle1_3->setFont(font);
        chk_Print2_Print = new QCheckBox(ParaWindow);
        chk_Print2_Print->setObjectName(QStringLiteral("chk_Print2_Print"));
        chk_Print2_Print->setGeometry(QRect(330, 210, 131, 22));
        chk_Print2_Print->setFont(font);
        label_5 = new QLabel(ParaWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 240, 91, 17));
        label_5->setFont(font);
        chk_Print3_Reader = new QCheckBox(ParaWindow);
        chk_Print3_Reader->setObjectName(QStringLiteral("chk_Print3_Reader"));
        chk_Print3_Reader->setGeometry(QRect(210, 240, 131, 22));
        chk_Print3_Reader->setFont(font);
        chk_Print1_Print = new QCheckBox(ParaWindow);
        chk_Print1_Print->setObjectName(QStringLiteral("chk_Print1_Print"));
        chk_Print1_Print->setGeometry(QRect(330, 180, 131, 22));
        chk_Print1_Print->setFont(font);
        label_3 = new QLabel(ParaWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 180, 91, 17));
        label_3->setFont(font);
        solt4_switch = new ImageSwitch(ParaWindow);
        solt4_switch->setObjectName(QStringLiteral("solt4_switch"));
        solt4_switch->setGeometry(QRect(490, 470, 71, 31));
        solt4_switch->setFont(font);
        txt2 = new QLineEdit(ParaWindow);
        txt2->setObjectName(QStringLiteral("txt2"));
        txt2->setGeometry(QRect(360, 350, 91, 27));
        txt2->setFont(font);
        chk_Print3_Print = new QCheckBox(ParaWindow);
        chk_Print3_Print->setObjectName(QStringLiteral("chk_Print3_Print"));
        chk_Print3_Print->setGeometry(QRect(330, 240, 131, 22));
        chk_Print3_Print->setFont(font);
        label_4 = new QLabel(ParaWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(120, 210, 91, 17));
        label_4->setFont(font);
        pushButton_Cancle = new QPushButton(ParaWindow);
        pushButton_Cancle->setObjectName(QStringLiteral("pushButton_Cancle"));
        pushButton_Cancle->setGeometry(QRect(440, 540, 100, 32));
        layoutWidget = new QWidget(ParaWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 30, 251, 30));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        rbtn1 = new QRadioButton(layoutWidget);
        rbtn1->setObjectName(QStringLiteral("rbtn1"));
        rbtn1->setChecked(true);

        horizontalLayout_2->addWidget(rbtn1);

        rbtn2 = new QRadioButton(layoutWidget);
        rbtn2->setObjectName(QStringLiteral("rbtn2"));

        horizontalLayout_2->addWidget(rbtn2);

        txt4 = new QLineEdit(ParaWindow);
        txt4->setObjectName(QStringLiteral("txt4"));
        txt4->setGeometry(QRect(360, 390, 91, 27));
        txt4->setFont(font);
        txt1 = new QLineEdit(ParaWindow);
        txt1->setObjectName(QStringLiteral("txt1"));
        txt1->setGeometry(QRect(140, 350, 81, 27));
        txt1->setFont(font);
        label_slotTitle1 = new QLabel(ParaWindow);
        label_slotTitle1->setObjectName(QStringLiteral("label_slotTitle1"));
        label_slotTitle1->setGeometry(QRect(50, 470, 39, 23));
        label_slotTitle1->setFont(font);
        pushButton_Save = new QPushButton(ParaWindow);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));
        pushButton_Save->setGeometry(QRect(330, 540, 100, 32));
        chk_Print2_Reader = new QCheckBox(ParaWindow);
        chk_Print2_Reader->setObjectName(QStringLiteral("chk_Print2_Reader"));
        chk_Print2_Reader->setGeometry(QRect(210, 210, 131, 22));
        chk_Print2_Reader->setFont(font);
        layoutWidget_2 = new QWidget(ParaWindow);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(50, 70, 271, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout->addWidget(label_6);

        rbtn3 = new QRadioButton(layoutWidget_2);
        rbtn3->setObjectName(QStringLiteral("rbtn3"));

        horizontalLayout->addWidget(rbtn3);

        rbtn4 = new QRadioButton(layoutWidget_2);
        rbtn4->setObjectName(QStringLiteral("rbtn4"));

        horizontalLayout->addWidget(rbtn4);

        solt3_switch = new ImageSwitch(ParaWindow);
        solt3_switch->setObjectName(QStringLiteral("solt3_switch"));
        solt3_switch->setGeometry(QRect(360, 470, 71, 31));
        solt3_switch->setFont(font);
        solt1_switch = new ImageSwitch(ParaWindow);
        solt1_switch->setObjectName(QStringLiteral("solt1_switch"));
        solt1_switch->setGeometry(QRect(100, 470, 71, 31));
        solt1_switch->setFont(font);
        label_slotTitle1_4 = new QLabel(ParaWindow);
        label_slotTitle1_4->setObjectName(QStringLiteral("label_slotTitle1_4"));
        label_slotTitle1_4->setGeometry(QRect(440, 470, 39, 23));
        label_slotTitle1_4->setFont(font);
        solt2_switch = new ImageSwitch(ParaWindow);
        solt2_switch->setObjectName(QStringLiteral("solt2_switch"));
        solt2_switch->setGeometry(QRect(230, 470, 71, 31));
        solt2_switch->setFont(font);
        chk_Print1_Reader = new QCheckBox(ParaWindow);
        chk_Print1_Reader->setObjectName(QStringLiteral("chk_Print1_Reader"));
        chk_Print1_Reader->setGeometry(QRect(210, 180, 131, 22));
        chk_Print1_Reader->setFont(font);
        txt3 = new QLineEdit(ParaWindow);
        txt3->setObjectName(QStringLiteral("txt3"));
        txt3->setGeometry(QRect(140, 390, 81, 27));
        txt3->setFont(font);
        label_slotTitle1_2 = new QLabel(ParaWindow);
        label_slotTitle1_2->setObjectName(QStringLiteral("label_slotTitle1_2"));
        label_slotTitle1_2->setGeometry(QRect(180, 470, 39, 23));
        label_slotTitle1_2->setFont(font);
        label_7 = new QLabel(ParaWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 360, 91, 17));
        label_7->setFont(font);
        label_8 = new QLabel(ParaWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(250, 360, 91, 17));
        label_8->setFont(font);
        label_9 = new QLabel(ParaWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(50, 390, 91, 17));
        label_9->setFont(font);
        label_10 = new QLabel(ParaWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(250, 390, 91, 16));
        label_10->setFont(font);
        chk_Print1 = new QCheckBox(ParaWindow);
        chk_Print1->setObjectName(QStringLiteral("chk_Print1"));
        chk_Print1->setGeometry(QRect(50, 180, 61, 22));
        chk_Print1->setFont(font);
        chk_Print1->setChecked(true);
        chk_Print2 = new QCheckBox(ParaWindow);
        chk_Print2->setObjectName(QStringLiteral("chk_Print2"));
        chk_Print2->setGeometry(QRect(50, 210, 61, 22));
        chk_Print2->setFont(font);
        chk_Print3 = new QCheckBox(ParaWindow);
        chk_Print3->setObjectName(QStringLiteral("chk_Print3"));
        chk_Print3->setGeometry(QRect(50, 240, 61, 22));
        chk_Print3->setFont(font);
        label_slotTitle1_5 = new QLabel(ParaWindow);
        label_slotTitle1_5->setObjectName(QStringLiteral("label_slotTitle1_5"));
        label_slotTitle1_5->setGeometry(QRect(50, 120, 71, 23));
        label_slotTitle1_5->setFont(font);
        corder_switch = new ImageSwitch(ParaWindow);
        corder_switch->setObjectName(QStringLiteral("corder_switch"));
        corder_switch->setGeometry(QRect(130, 120, 71, 31));
        label_slotTitle1_6 = new QLabel(ParaWindow);
        label_slotTitle1_6->setObjectName(QStringLiteral("label_slotTitle1_6"));
        label_slotTitle1_6->setGeometry(QRect(50, 420, 71, 23));
        label_slotTitle1_6->setFont(font);
        ocr_switch = new ImageSwitch(ParaWindow);
        ocr_switch->setObjectName(QStringLiteral("ocr_switch"));
        ocr_switch->setGeometry(QRect(130, 420, 71, 31));
        ocr_switch->setFont(font);
        label_slotTitle1_7 = new QLabel(ParaWindow);
        label_slotTitle1_7->setObjectName(QStringLiteral("label_slotTitle1_7"));
        label_slotTitle1_7->setGeometry(QRect(250, 420, 81, 23));
        label_slotTitle1_7->setFont(font);
        checkreader_switch = new ImageSwitch(ParaWindow);
        checkreader_switch->setObjectName(QStringLiteral("checkreader_switch"));
        checkreader_switch->setGeometry(QRect(350, 420, 71, 31));
        checkreader_switch->setFont(font);
        txt_X = new QLineEdit(ParaWindow);
        txt_X->setObjectName(QStringLiteral("txt_X"));
        txt_X->setGeometry(QRect(280, 120, 31, 27));
        label_11 = new QLabel(ParaWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(220, 130, 61, 17));
        label_11->setFont(font);
        label_12 = new QLabel(ParaWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(330, 130, 61, 17));
        label_12->setFont(font);
        txt_Y = new QLineEdit(ParaWindow);
        txt_Y->setObjectName(QStringLiteral("txt_Y"));
        txt_Y->setGeometry(QRect(390, 120, 31, 27));
        label_slotTitle1_8 = new QLabel(ParaWindow);
        label_slotTitle1_8->setObjectName(QStringLiteral("label_slotTitle1_8"));
        label_slotTitle1_8->setGeometry(QRect(50, 270, 81, 23));
        label_slotTitle1_8->setFont(font);
        use_EP_switch = new ImageSwitch(ParaWindow);
        use_EP_switch->setObjectName(QStringLiteral("use_EP_switch"));
        use_EP_switch->setGeometry(QRect(130, 270, 71, 31));
        use_EP_switch->setFont(font);
        label_slotTitle1_9 = new QLabel(ParaWindow);
        label_slotTitle1_9->setObjectName(QStringLiteral("label_slotTitle1_9"));
        label_slotTitle1_9->setGeometry(QRect(250, 270, 101, 23));
        label_slotTitle1_9->setFont(font);
        clearBeforePrint_switch = new ImageSwitch(ParaWindow);
        clearBeforePrint_switch->setObjectName(QStringLiteral("clearBeforePrint_switch"));
        clearBeforePrint_switch->setGeometry(QRect(350, 270, 71, 31));
        clearBeforePrint_switch->setFont(font);
        widgetTop = new QWidget(ParaWindow);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        widgetTop->setGeometry(QRect(0, 0, 585, 28));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTop->sizePolicy().hasHeightForWidth());
        widgetTop->setSizePolicy(sizePolicy);
        widgetTop->setMaximumSize(QSize(16777215, 45));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labTitle = new QLabel(widgetTop);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy1);
        labTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(labTitle);

        label_setlam = new QLabel(ParaWindow);
        label_setlam->setObjectName(QStringLiteral("label_setlam"));
        label_setlam->setGeometry(QRect(50, 310, 81, 23));
        label_setlam->setFont(font);
        use_LAM_switch = new ImageSwitch(ParaWindow);
        use_LAM_switch->setObjectName(QStringLiteral("use_LAM_switch"));
        use_LAM_switch->setGeometry(QRect(130, 310, 71, 31));
        use_LAM_switch->setFont(font);

        retranslateUi(ParaWindow);

        QMetaObject::connectSlotsByName(ParaWindow);
    } // setupUi

    void retranslateUi(QDialog *ParaWindow)
    {
        ParaWindow->setWindowTitle(QApplication::translate("ParaWindow", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label_slotTitle1_3->setText(QApplication::translate("ParaWindow", "\345\215\241\346\247\2753", 0));
        chk_Print2_Print->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\346\211\223\345\215\260\346\234\2722", 0));
        label_5->setText(QApplication::translate("ParaWindow", "\346\211\223\345\215\260\346\250\241\345\235\227\357\274\223", 0));
        chk_Print3_Reader->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\350\257\273\345\215\241\345\231\250", 0));
        chk_Print1_Print->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\346\211\223\345\215\260\346\234\2721", 0));
        label_3->setText(QApplication::translate("ParaWindow", "\346\211\223\345\215\260\346\250\241\345\235\227\357\274\221", 0));
        txt2->setText(QApplication::translate("ParaWindow", "165", 0));
        chk_Print3_Print->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\346\211\223\345\215\260\346\234\2723", 0));
        label_4->setText(QApplication::translate("ParaWindow", "\346\211\223\345\215\260\346\250\241\345\235\227\357\274\222", 0));
        pushButton_Cancle->setText(QApplication::translate("ParaWindow", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("ParaWindow", "\345\267\245\344\275\234\346\250\241\345\274\217", 0));
        rbtn1->setText(QApplication::translate("ParaWindow", "\350\207\252\345\212\250", 0));
        rbtn2->setText(QApplication::translate("ParaWindow", "\346\211\213\345\212\250", 0));
        txt4->setText(QApplication::translate("ParaWindow", "50", 0));
        txt1->setText(QApplication::translate("ParaWindow", "8", 0));
        label_slotTitle1->setText(QApplication::translate("ParaWindow", "\345\215\241\346\247\2751", 0));
        pushButton_Save->setText(QApplication::translate("ParaWindow", "\344\277\235\345\255\230", 0));
        chk_Print2_Reader->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\350\257\273\345\215\241\345\231\250", 0));
        label_6->setText(QApplication::translate("ParaWindow", "\346\225\260\346\215\256\345\214\205", 0));
        rbtn3->setText(QApplication::translate("ParaWindow", "\350\207\252\345\212\250\347\255\276\346\224\266", 0));
        rbtn4->setText(QApplication::translate("ParaWindow", "\346\211\213\345\212\250\347\255\276\346\224\266", 0));
        label_slotTitle1_4->setText(QApplication::translate("ParaWindow", "\345\215\241\346\247\2754", 0));
        chk_Print1_Reader->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250\350\257\273\345\215\241\345\231\250", 0));
        txt3->setText(QApplication::translate("ParaWindow", "7", 0));
        label_slotTitle1_2->setText(QApplication::translate("ParaWindow", "\345\215\241\346\247\2752", 0));
        label_7->setText(QApplication::translate("ParaWindow", "\350\246\206\350\206\234\351\200\237\345\272\246", 0));
        label_8->setText(QApplication::translate("ParaWindow", "\350\246\206\350\206\234\346\270\251\345\272\246", 0));
        label_9->setText(QApplication::translate("ParaWindow", "\345\217\257\346\223\246\345\206\231\345\274\272\345\272\246", 0));
        label_10->setText(QApplication::translate("ParaWindow", "\345\217\257\346\223\246\345\206\231\346\270\251\345\272\246", 0));
        chk_Print1->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250", 0));
        chk_Print2->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250", 0));
        chk_Print3->setText(QApplication::translate("ParaWindow", "\345\220\257\347\224\250", 0));
        label_slotTitle1_5->setText(QApplication::translate("ParaWindow", "\350\276\271\350\267\235\350\257\206\345\210\253", 0));
        label_slotTitle1_6->setText(QApplication::translate("ParaWindow", "OCR\350\257\206\345\210\253", 0));
        label_slotTitle1_7->setText(QApplication::translate("ParaWindow", "\346\240\270\351\252\214\350\257\273\345\215\241\345\231\250", 0));
        txt_X->setText(QApplication::translate("ParaWindow", "2", 0));
        label_11->setText(QApplication::translate("ParaWindow", "X\350\275\264\350\257\257\345\267\256", 0));
        label_12->setText(QApplication::translate("ParaWindow", "Y\350\275\264\350\257\257\345\267\256", 0));
        txt_Y->setText(QApplication::translate("ParaWindow", "2", 0));
        label_slotTitle1_8->setText(QApplication::translate("ParaWindow", "\345\217\257\346\223\246\345\206\231\346\211\223\345\215\260", 0));
        label_slotTitle1_9->setText(QApplication::translate("ParaWindow", "\345\205\210\346\223\246\351\231\244\345\206\215\346\211\223\345\215\260", 0));
        labTitle->setText(QApplication::translate("ParaWindow", "0", 0));
        label_setlam->setText(QApplication::translate("ParaWindow", "\346\230\257\345\220\246\350\246\206\350\206\234", 0));
    } // retranslateUi

};

namespace Ui {
    class ParaWindow: public Ui_ParaWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAWINDOW_H
