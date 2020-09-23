/********************************************************************************
** Form generated from reading UI file 'indexform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEXFORM_H
#define UI_INDEXFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IndexForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widgetMain;
    QVBoxLayout *verticalLayout;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnReturn;
    QLabel *labTitle;
    QPushButton *btnMsg;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QToolButton *btnDevice;
    QToolButton *btnData;
    QToolButton *btnViewMap;
    QToolButton *btnMap;
    QToolButton *btnViewPanel;
    QToolButton *btnConfig;
    QToolButton *btnShowCycle;
    QToolButton *btnShowClean;
    QToolButton *btnSelfCheck;
    QToolButton *btnLamMod;
    QToolButton *btnSendMod;
    QToolButton *btnSortMod;
    QWidget *page3;
    QLabel *label_2;

    void setupUi(QWidget *IndexForm)
    {
        if (IndexForm->objectName().isEmpty())
            IndexForm->setObjectName(QStringLiteral("IndexForm"));
        IndexForm->resize(990, 839);
        verticalLayout_2 = new QVBoxLayout(IndexForm);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetMain = new QWidget(IndexForm);
        widgetMain->setObjectName(QStringLiteral("widgetMain"));
        verticalLayout = new QVBoxLayout(widgetMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTop = new QWidget(widgetMain);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTop->sizePolicy().hasHeightForWidth());
        widgetTop->setSizePolicy(sizePolicy);
        widgetTop->setMinimumSize(QSize(0, 0));
        widgetTop->setMaximumSize(QSize(16777215, 45));
        horizontalLayout = new QHBoxLayout(widgetTop);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnReturn = new QPushButton(widgetTop);
        btnReturn->setObjectName(QStringLiteral("btnReturn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnReturn->sizePolicy().hasHeightForWidth());
        btnReturn->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnReturn);

        labTitle = new QLabel(widgetTop);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy2);
        labTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTitle);

        btnMsg = new QPushButton(widgetTop);
        btnMsg->setObjectName(QStringLiteral("btnMsg"));
        sizePolicy1.setHeightForWidth(btnMsg->sizePolicy().hasHeightForWidth());
        btnMsg->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btnMsg);


        verticalLayout->addWidget(widgetTop);

        stackedWidget = new QStackedWidget(widgetMain);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setSpacing(15);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, 20, 20, 20);
        btnDevice = new QToolButton(page);
        btnDevice->setObjectName(QStringLiteral("btnDevice"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnDevice->sizePolicy().hasHeightForWidth());
        btnDevice->setSizePolicy(sizePolicy3);
        btnDevice->setStyleSheet(QStringLiteral(""));
        btnDevice->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnDevice, 2, 1, 1, 1);

        btnData = new QToolButton(page);
        btnData->setObjectName(QStringLiteral("btnData"));
        sizePolicy3.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy3);
        btnData->setStyleSheet(QStringLiteral(""));
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnData, 0, 2, 1, 1);

        btnViewMap = new QToolButton(page);
        btnViewMap->setObjectName(QStringLiteral("btnViewMap"));
        sizePolicy3.setHeightForWidth(btnViewMap->sizePolicy().hasHeightForWidth());
        btnViewMap->setSizePolicy(sizePolicy3);
        btnViewMap->setStyleSheet(QStringLiteral(""));
        btnViewMap->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnViewMap, 0, 0, 1, 1);

        btnMap = new QToolButton(page);
        btnMap->setObjectName(QStringLiteral("btnMap"));
        sizePolicy3.setHeightForWidth(btnMap->sizePolicy().hasHeightForWidth());
        btnMap->setSizePolicy(sizePolicy3);
        btnMap->setStyleSheet(QStringLiteral(""));
        btnMap->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnMap, 2, 0, 1, 1);

        btnViewPanel = new QToolButton(page);
        btnViewPanel->setObjectName(QStringLiteral("btnViewPanel"));
        sizePolicy3.setHeightForWidth(btnViewPanel->sizePolicy().hasHeightForWidth());
        btnViewPanel->setSizePolicy(sizePolicy3);
        btnViewPanel->setStyleSheet(QStringLiteral(""));
        btnViewPanel->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnViewPanel, 0, 1, 1, 1);

        btnConfig = new QToolButton(page);
        btnConfig->setObjectName(QStringLiteral("btnConfig"));
        sizePolicy3.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy3);
        btnConfig->setStyleSheet(QStringLiteral(""));
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnConfig, 2, 2, 1, 1);

        btnShowCycle = new QToolButton(page);
        btnShowCycle->setObjectName(QStringLiteral("btnShowCycle"));
        sizePolicy3.setHeightForWidth(btnShowCycle->sizePolicy().hasHeightForWidth());
        btnShowCycle->setSizePolicy(sizePolicy3);
        btnShowCycle->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnShowCycle, 3, 0, 1, 1);

        btnShowClean = new QToolButton(page);
        btnShowClean->setObjectName(QStringLiteral("btnShowClean"));
        sizePolicy3.setHeightForWidth(btnShowClean->sizePolicy().hasHeightForWidth());
        btnShowClean->setSizePolicy(sizePolicy3);
        btnShowClean->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnShowClean, 3, 1, 1, 1);

        btnSelfCheck = new QToolButton(page);
        btnSelfCheck->setObjectName(QStringLiteral("btnSelfCheck"));
        sizePolicy3.setHeightForWidth(btnSelfCheck->sizePolicy().hasHeightForWidth());
        btnSelfCheck->setSizePolicy(sizePolicy3);
        btnSelfCheck->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnSelfCheck, 3, 2, 1, 1);

        btnLamMod = new QToolButton(page);
        btnLamMod->setObjectName(QStringLiteral("btnLamMod"));
        sizePolicy3.setHeightForWidth(btnLamMod->sizePolicy().hasHeightForWidth());
        btnLamMod->setSizePolicy(sizePolicy3);
        btnLamMod->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnLamMod, 4, 1, 1, 1);

        btnSendMod = new QToolButton(page);
        btnSendMod->setObjectName(QStringLiteral("btnSendMod"));
        sizePolicy3.setHeightForWidth(btnSendMod->sizePolicy().hasHeightForWidth());
        btnSendMod->setSizePolicy(sizePolicy3);
        btnSendMod->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnSendMod, 4, 0, 1, 1);

        btnSortMod = new QToolButton(page);
        btnSortMod->setObjectName(QStringLiteral("btnSortMod"));
        sizePolicy3.setHeightForWidth(btnSortMod->sizePolicy().hasHeightForWidth());
        btnSortMod->setSizePolicy(sizePolicy3);
        btnSortMod->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        gridLayout->addWidget(btnSortMod, 4, 2, 1, 1);

        stackedWidget->addWidget(page);
        page3 = new QWidget();
        page3->setObjectName(QStringLiteral("page3"));
        label_2 = new QLabel(page3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 70, 351, 201));
        QFont font;
        font.setPointSize(40);
        label_2->setFont(font);
        stackedWidget->addWidget(page3);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addWidget(widgetMain);


        retranslateUi(IndexForm);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(IndexForm);
    } // setupUi

    void retranslateUi(QWidget *IndexForm)
    {
        IndexForm->setWindowTitle(QApplication::translate("IndexForm", "Form", 0));
        btnReturn->setText(QString());
        labTitle->setText(QApplication::translate("IndexForm", "0", 0));
        btnMsg->setText(QString());
        btnDevice->setText(QString());
        btnData->setText(QString());
        btnViewMap->setText(QString());
        btnMap->setText(QString());
        btnViewPanel->setText(QString());
        btnConfig->setText(QString());
        btnShowCycle->setText(QString());
        btnShowClean->setText(QString());
        btnSelfCheck->setText(QString());
        btnLamMod->setText(QString());
        btnSendMod->setText(QString());
        btnSortMod->setText(QString());
        label_2->setText(QApplication::translate("IndexForm", "\346\234\252\345\256\236\347\216\260", 0));
    } // retranslateUi

};

namespace Ui {
    class IndexForm: public Ui_IndexForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEXFORM_H
