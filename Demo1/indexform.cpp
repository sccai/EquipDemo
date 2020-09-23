#pragma execution_character_set("utf-8")

#include "indexform.h"
#include "ui_indexform.h"
#include "tool/iconhelper.h"
#include "cleanform.h"
#include "mainwindow.h"
#include "tool/fontawesomeicons.h"
#include "roundprogressbartest.h"
#include "selfcheckform.h"
#include "newmainwindow.h"
#include "opencvform.h"
#include "cardsenderform.h"
#include "concurrentform.h"
#include "lamform.h"
#include "sortform.h"
#include "printform.h"

#define iconSize    50
#define iconWidth   100
#define iconHeight  70
#define navBtnWidth 45
#define navIcoWidth 32
#define closecodeIcon (int)FontAweSomeIcons::IconIdentity::icon_close//FontAweSomeIcons::IconIdentity::icon_close是图标的枚举
#define homecodeIcon (int)FontAweSomeIcons::IconIdentity::icon_home

IndexForm::IndexForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IndexForm)
{
    ui->setupUi(this);
    this->initForm();
    this->initNav();
    setWindowIcon(QIcon(":/image/CETeam/lg.ico"));
}

IndexForm::~IndexForm()
{
    delete ui;
}

void IndexForm::initForm()
{
    ui->labTitle->setText("通行证制证程序");
    this->setWindowTitle(ui->labTitle->text());
    this->setProperty("canMove", true);
    //设置无边框
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint);

    ui->widgetTop->setProperty("flag", "nav");
    ui->widgetTop->setFixedHeight(40);

    IconHelper::Instance()->setIcon(ui->btnReturn, homecodeIcon, navIcoWidth);
    IconHelper::Instance()->setIcon(ui->btnMsg, closecodeIcon, navIcoWidth);

    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:#FEFEFE;}"));
    //主窗体背景
    qss.append(QString("QWidget#widgetMain{border-image:url(%1);}").arg(":/image/main.png"));
    //标题字体大小
    qss.append(QString("QLabel#labTitle{font:%1px;}").arg(navIcoWidth));
    //顶部导航
    qss.append(QString("QWidget[flag=\"nav\"]{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,"
                       "stop:0 %1,stop:1 %2);}").arg("#00688B").arg("#093746"));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{background:none;border:none;"
                       "min-width:%1px;max-width:%1px;}").arg(navBtnWidth));

    this->setStyleSheet(qss.join(""));//Wrong JPEG library version: library is 62, caller expects 80

    CleanForm *cleanFrm=new CleanForm;
    ui->stackedWidget->insertWidget(1,cleanFrm);

    RoundProgressBarTest *rfrm=new RoundProgressBarTest;
    ui->stackedWidget->insertWidget(2,rfrm);

    SelfCheckForm *selffrm=new SelfCheckForm;
    ui->stackedWidget->insertWidget(3,selffrm);

    CardSenderForm *cardfrm=new CardSenderForm;
    ui->stackedWidget->insertWidget(4,cardfrm);

    //覆膜机构 5
    LamForm *lamfrm=new LamForm;
    ui->stackedWidget->insertWidget(5,lamfrm);

    //分拣机构  6
    SortForm *sortfrm=new SortForm;
    ui->stackedWidget->insertWidget(6,sortfrm);

    //打印机RCK600  7
    PrintForm *printfrm=new PrintForm;
    ui->stackedWidget->insertWidget(7,printfrm);
}

void IndexForm::initNav()
{
    QList<QString> listColorBg;
    listColorBg << "#1570A5" << "#16A085" << "#C0392B" << "#047058" << "#9B59BB" << "#34495E"<< "#22225E"<< "#025058"<< "#0059BB"<< "#34005E"<< "#ff9200"<< "#011058" ;//按钮背景颜色
    QList<QString> listColorText;
    listColorText << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE" << "#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE"<<"#FEFEFE";//字体颜色

    QList<QChar> listChar;//Font Awesome 图标
    listChar << 0xf030 << 0xf108 << 0xf002 << 0xf03e << 0xf0e8 << 0xf085<< 0xf069<< 0xf0c4<< 0xf022<< 0xf085<< 0xf123<< 0xf011;//图标
    QList<QString> listText;
    listText << "主程序" <<"自检界面"<< "主界面" << "发卡器" << "打印机RCK600" << "覆膜机" << "读卡器"<< "清洁程序"<< "识别设备"<<"QtConcurrent"<<"覆膜机构"<<"分拣机构";//标题

    btns << ui->btnViewMap << ui->btnViewPanel << ui->btnData << ui->btnMap << ui->btnDevice << ui->btnConfig<<ui->btnShowCycle<<ui->btnShowClean<<ui->btnSelfCheck
         << ui->btnSendMod
         <<ui->btnLamMod
        <<ui->btnSortMod;
    for (int i = 0; i < btns.count(); i++) {
        QToolButton *btn = btns.at(i);
        btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        btn->setIconSize(QSize(iconWidth, iconHeight));

        QPixmap pix = IconHelper::Instance()->getPixmap(listColorText.at(i), listChar.at(i), iconSize, iconWidth, iconHeight);
        btn->setIcon(QIcon(pix));
        btn->setText(listText.at(i));

        QStringList list;
        list.append(QString("QToolButton{font:%1px;background:%2;}").arg(iconSize / 2.5).arg(listColorBg.at(i)));
        list.append(QString("QToolButton{border:none;border-radius:8px;padding:30px;}"));
        list.append(QString("QToolButton:pressed{background:%1;}").arg("#737A97"));
        btn->setStyleSheet(list.join(""));

        connect(btn, SIGNAL(clicked(bool)), this, SLOT(buttonClicked()));
    }
}

void IndexForm::buttonClicked()
{
    QToolButton *btn = (QToolButton *)sender();
    QString text= btn->text();
    //ui->labTitle->setText(btn->text());
    if(text=="主程序")
    {
        ui->labTitle->setText("通行证制证程序");
        MainWindow *main=new MainWindow;
        main->show();
        main->move ((QApplication::desktop()->width() - main->width())/2,(QApplication::desktop()->height() - main->height())/2);//居中
        return;
        //ui->stackedWidget->insertWidget(1,main);
        //ui->stackedWidget->setCurrentIndex(1);
    }
    else if(text=="清洁程序"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(text=="CIS设备"){
        ui->labTitle->setText(btn->text());
        CleanForm *rfrm=new CleanForm;
        rfrm->show();
        return;
    }
    else if(text=="发卡器"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(4);
    }
    else if(text=="识别设备"){
        ui->labTitle->setText(btn->text());
        //OpenCVForm *rfrm=new OpenCVForm;
        //rfrm->show();
        return;
    }
    else if(text=="圆环"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if(text=="自检界面"){
        //ui->labTitle->setText(btn->text());
        //ui->stackedWidget->setCurrentIndex(3);
        ui->labTitle->setText("自检界面");
        SelfCheckForm *main=new SelfCheckForm;
        main->show();
        main->move ((QApplication::desktop()->width() - main->width())/2,(QApplication::desktop()->height() - main->height())/2);//居中
        return;
    }
    else if(text=="主界面"){
        NewMainWindow *main=new NewMainWindow;
        main->show();
        main->move ((QApplication::desktop()->width() - main->width())/2,(QApplication::desktop()->height() - main->height())/2);//居中
        return;
    }
    else if(text=="QtConcurrent"){
        ConcurrentForm *main=new ConcurrentForm;
        main->show();
        main->move ((QApplication::desktop()->width() - main->width())/2,(QApplication::desktop()->height() - main->height())/2);//居中
        return;
    }
    else if(text=="覆膜机构"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(5);
    }
    else if(text=="分拣机构"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(6);
    }
    else if(text=="打印机RCK600"){
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(7);
    }
    else
    {
        ui->labTitle->setText(btn->text());
        ui->stackedWidget->setCurrentIndex(8);
    }

    IconHelper::Instance()->setIcon(ui->btnReturn, 0xf122, navIcoWidth);
}

void IndexForm::on_btnReturn_pressed()
{
    int index = ui->stackedWidget->currentIndex();
    if (index != 0) {
        ui->stackedWidget->setCurrentIndex(0);
        ui->labTitle->setText("通行证制证程序");
        IconHelper::Instance()->setIcon(ui->btnReturn, homecodeIcon, navIcoWidth);
    }
}

void IndexForm::on_btnMsg_pressed()
{
    exit(0);
}
