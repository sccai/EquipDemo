/********************************************************************************
** Form generated from reading UI file 'uidemo08.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIDEMO08_H
#define UI_UIDEMO08_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIDemo08
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btnMain;
    QToolButton *btnConfig;
    QToolButton *btnData;
    QToolButton *btnHelp;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetLeftMain;
    QVBoxLayout *verticalLayout_2;
    QToolButton *tbtnMain1;
    QToolButton *tbtnMain2;
    QToolButton *tbtnMain3;
    QSpacerItem *verticalSpacer_2;
    QLabel *lab1;
    QWidget *page2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widgetLeftConfig;
    QVBoxLayout *verticalLayout_3;
    QToolButton *tbtnConfig1;
    QToolButton *tbtnConfig2;
    QToolButton *tbtnConfig3;
    QToolButton *tbtnConfig4;
    QToolButton *tbtnConfig5;
    QToolButton *tbtnConfig6;
    QSpacerItem *verticalSpacer_3;
    QLabel *lab2;
    QWidget *page3;
    QVBoxLayout *verticalLayout_5;
    QLabel *lab3;
    QWidget *page4;
    QVBoxLayout *verticalLayout_4;
    QLabel *lab4;

    void setupUi(QWidget *UIDemo08)
    {
        if (UIDemo08->objectName().isEmpty())
            UIDemo08->setObjectName(QStringLiteral("UIDemo08"));
        UIDemo08->resize(810, 600);
        UIDemo08->setStyleSheet(QLatin1String("      QWidget {\n"
"			 background-color:rgb(111,111,125);\n"
"        }"));
        UIDemo08->setProperty("sizeGripEnabled", QVariant(false));
        verticalLayout = new QVBoxLayout(UIDemo08);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        widgetTitle = new QWidget(UIDemo08);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btnMain = new QToolButton(widgetTop);
        btnMain->setObjectName(QStringLiteral("btnMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMain->sizePolicy().hasHeightForWidth());
        btnMain->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMain->setIcon(icon);
        btnMain->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnMain);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QStringLiteral("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon1);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);

        btnData = new QToolButton(widgetTop);
        btnData->setObjectName(QStringLiteral("btnData"));
        sizePolicy1.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/main_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon2);
        btnData->setChecked(false);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnData);

        btnHelp = new QToolButton(widgetTop);
        btnHelp->setObjectName(QStringLiteral("btnHelp"));
        sizePolicy1.setHeightForWidth(btnHelp->sizePolicy().hasHeightForWidth());
        btnHelp->setSizePolicy(sizePolicy1);
        btnHelp->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/main_person.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon3);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnHelp);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        stackedWidget = new QStackedWidget(UIDemo08);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page1 = new QWidget();
        page1->setObjectName(QStringLiteral("page1"));
        horizontalLayout = new QHBoxLayout(page1);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widgetLeftMain = new QWidget(page1);
        widgetLeftMain->setObjectName(QStringLiteral("widgetLeftMain"));
        widgetLeftMain->setMaximumSize(QSize(90, 16777215));
        verticalLayout_2 = new QVBoxLayout(widgetLeftMain);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tbtnMain1 = new QToolButton(widgetLeftMain);
        tbtnMain1->setObjectName(QStringLiteral("tbtnMain1"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tbtnMain1->sizePolicy().hasHeightForWidth());
        tbtnMain1->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(tbtnMain1);

        tbtnMain2 = new QToolButton(widgetLeftMain);
        tbtnMain2->setObjectName(QStringLiteral("tbtnMain2"));
        sizePolicy3.setHeightForWidth(tbtnMain2->sizePolicy().hasHeightForWidth());
        tbtnMain2->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(tbtnMain2);

        tbtnMain3 = new QToolButton(widgetLeftMain);
        tbtnMain3->setObjectName(QStringLiteral("tbtnMain3"));
        sizePolicy3.setHeightForWidth(tbtnMain3->sizePolicy().hasHeightForWidth());
        tbtnMain3->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(tbtnMain3);

        verticalSpacer_2 = new QSpacerItem(20, 471, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(widgetLeftMain);

        lab1 = new QLabel(page1);
        lab1->setObjectName(QStringLiteral("lab1"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lab1->sizePolicy().hasHeightForWidth());
        lab1->setSizePolicy(sizePolicy4);
        lab1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(lab1);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QStringLiteral("page2"));
        horizontalLayout_4 = new QHBoxLayout(page2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widgetLeftConfig = new QWidget(page2);
        widgetLeftConfig->setObjectName(QStringLiteral("widgetLeftConfig"));
        widgetLeftConfig->setMaximumSize(QSize(100, 16777215));
        verticalLayout_3 = new QVBoxLayout(widgetLeftConfig);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tbtnConfig1 = new QToolButton(widgetLeftConfig);
        tbtnConfig1->setObjectName(QStringLiteral("tbtnConfig1"));
        sizePolicy3.setHeightForWidth(tbtnConfig1->sizePolicy().hasHeightForWidth());
        tbtnConfig1->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig1);

        tbtnConfig2 = new QToolButton(widgetLeftConfig);
        tbtnConfig2->setObjectName(QStringLiteral("tbtnConfig2"));
        sizePolicy3.setHeightForWidth(tbtnConfig2->sizePolicy().hasHeightForWidth());
        tbtnConfig2->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig2);

        tbtnConfig3 = new QToolButton(widgetLeftConfig);
        tbtnConfig3->setObjectName(QStringLiteral("tbtnConfig3"));
        sizePolicy3.setHeightForWidth(tbtnConfig3->sizePolicy().hasHeightForWidth());
        tbtnConfig3->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig3);

        tbtnConfig4 = new QToolButton(widgetLeftConfig);
        tbtnConfig4->setObjectName(QStringLiteral("tbtnConfig4"));
        sizePolicy3.setHeightForWidth(tbtnConfig4->sizePolicy().hasHeightForWidth());
        tbtnConfig4->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig4);

        tbtnConfig5 = new QToolButton(widgetLeftConfig);
        tbtnConfig5->setObjectName(QStringLiteral("tbtnConfig5"));
        sizePolicy3.setHeightForWidth(tbtnConfig5->sizePolicy().hasHeightForWidth());
        tbtnConfig5->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig5);

        tbtnConfig6 = new QToolButton(widgetLeftConfig);
        tbtnConfig6->setObjectName(QStringLiteral("tbtnConfig6"));
        sizePolicy3.setHeightForWidth(tbtnConfig6->sizePolicy().hasHeightForWidth());
        tbtnConfig6->setSizePolicy(sizePolicy3);

        verticalLayout_3->addWidget(tbtnConfig6);

        verticalSpacer_3 = new QSpacerItem(20, 417, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_4->addWidget(widgetLeftConfig);

        lab2 = new QLabel(page2);
        lab2->setObjectName(QStringLiteral("lab2"));
        sizePolicy4.setHeightForWidth(lab2->sizePolicy().hasHeightForWidth());
        lab2->setSizePolicy(sizePolicy4);
        lab2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lab2);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        verticalLayout_5 = new QVBoxLayout(page3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        lab3 = new QLabel(page3);
        lab3->setObjectName(QStringLiteral("lab3"));
        lab3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lab3);

        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QStringLiteral("page4"));
        verticalLayout_4 = new QVBoxLayout(page4);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lab4 = new QLabel(page4);
        lab4->setObjectName(QStringLiteral("lab4"));
        lab4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lab4);

        stackedWidget->addWidget(page4);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(UIDemo08);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UIDemo08);
    } // setupUi

    void retranslateUi(QWidget *UIDemo08)
    {
        UIDemo08->setWindowTitle(QApplication::translate("UIDemo08", "Dialog", 0));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnMain->setText(QApplication::translate("UIDemo08", "\344\270\273\347\225\214\351\235\242", 0));
        btnConfig->setText(QApplication::translate("UIDemo08", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        btnData->setText(QApplication::translate("UIDemo08", "\350\255\246\346\203\205\346\237\245\350\257\242", 0));
        btnHelp->setText(QApplication::translate("UIDemo08", "\350\260\203\350\257\225\345\270\256\345\212\251", 0));
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("UIDemo08", "\346\234\200\345\260\217\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("UIDemo08", "\345\205\263\351\227\255", 0));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
        btnMenu_Max->setText(QString());
        tbtnMain1->setText(QApplication::translate("UIDemo08", "\350\247\206\351\242\221\347\233\221\346\216\247", 0));
        tbtnMain2->setText(QApplication::translate("UIDemo08", "\345\234\260\345\233\276\347\233\221\346\216\247", 0));
        tbtnMain3->setText(QApplication::translate("UIDemo08", "\350\256\276\345\244\207\347\233\221\346\216\247", 0));
        lab1->setText(QString());
        tbtnConfig1->setText(QApplication::translate("UIDemo08", "\345\237\272\346\234\254\350\256\276\347\275\256", 0));
        tbtnConfig2->setText(QApplication::translate("UIDemo08", "\350\275\254\345\217\221\350\256\276\347\275\256", 0));
        tbtnConfig3->setText(QApplication::translate("UIDemo08", "\347\224\250\346\210\267\350\256\276\347\275\256", 0));
        tbtnConfig4->setText(QApplication::translate("UIDemo08", "\351\230\262\345\214\272\350\256\276\347\275\256", 0));
        tbtnConfig5->setText(QApplication::translate("UIDemo08", "\350\256\276\345\244\207\350\256\276\347\275\256", 0));
        tbtnConfig6->setText(QApplication::translate("UIDemo08", "\345\205\266\344\273\226\350\256\276\347\275\256", 0));
        lab2->setText(QApplication::translate("UIDemo08", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        lab3->setText(QApplication::translate("UIDemo08", "\350\255\246\346\203\205\346\237\245\350\257\242", 0));
        lab4->setText(QApplication::translate("UIDemo08", "\350\260\203\350\257\225\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class UIDemo08: public Ui_UIDemo08 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIDEMO08_H
