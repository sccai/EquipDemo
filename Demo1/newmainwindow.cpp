#include "newmainwindow.h"
#include "ui_newmainwindow.h"
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"
#include "roundprogressbartest.h"
#include "parawindow.h"
#include "uidemo08.h"
#include "QMovie"
#include "flatui.h"
#include "formchild.h"
#include "tool/commhelper.h"
#include "PrintMod/printmod.h"
#include "tool/appinit.h"
#include "tool/fontawesomeicons.h"
#include "deviceinfo.h"
#include "SendMod/sendmod.h"
#include "control/lightbutton.h"
#include "QMessageBox"
#include "QtConcurrent"
#include "QCoreApplication"

NewMainWindow::NewMainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewMainWindow),
    translator(new QTranslator(qApp))
{
    ui->setupUi(this);
    QStringList qss;
    //全局无焦点虚边框
    qss.append(QString("*{outline:0px;}"));
    this->setStyleSheet(qss.join(""));

    this->InitEquip();
    this->InitForm();
    this->InitSlot();
    this->InitStatusImage();
    this->InitEquipConsume();
    setWindowIcon(QIcon(":/image/CETeam/lg.ico"));
    this->setWindowTitle("通行证制证程序");

    //
    CommHelper::Instance()->SetDebug(true);
    //获取当前运行路径
    //QString ff=QCoreApplication::applicationDirPath();//"/home/aisino/project/EquipDemo/build-Demo1-unknown-u8c03u8bd5"
}

NewMainWindow::~NewMainWindow()
{
    delete ui;
}

//初始化设备列表，读取配置文件
void NewMainWindow::InitEquip()
{
    dicPrintModChecked["1"]=false;
    dicPrintModChecked["2"]=false;
    dicPrintModChecked["3"]=false;

    //读取配置文件获取设备配置信息
    //AppInit::Instance()->domparser->printAllMembers();//打印设备列表
    //int maxEquip= AppInit::Instance()->domparser->m_deviceinfolist.size();//总数量，设置圆环的百分比
    //ui->roundProgressBar_DeviceCheck->setRange(0, maxEquip);
    //ui->roundProgressBar_DeviceCheck->setValue(21);

    //从配置文件获取设备参数
    for (const DeviceInfoModel::DeviceInfo& device : AppInit::Instance()->domparser->m_deviceinfolist)
    {
        if(device.DeviceType=="SendCardModule")
        {
            sendMod=new SendMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sendMod,&SendMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(sendMod,&SendMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="1")
        {
            printMod1=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod1,&PrintMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(printMod1,&PrintMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="2")
        {
            printMod2=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod2,&PrintMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(printMod2,&PrintMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="3")
        {
            printMod3=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod3,&PrintMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(printMod3,&PrintMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="ErasableLaminatinModule")
        {
            lamMod=new LamMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(lamMod,&LamMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(lamMod,&LamMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="SortingModule")
        {
            sortMod=new SortMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sortMod,&SortMod::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            QObject::connect(sortMod,&SortMod::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="CardSender")
        {
            cardsender=new CardSender(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(cardsender,&CardSender::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
            QObject::connect(cardsender,&CardSender::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
        }
        else if(device.DeviceType=="Printer")
        {
            qDebug()<<"打印机IP:"<<QString::fromStdString(device.DeviceIP);
            if(device.DeviceID=="1")
            {
                printer1=new Print_RCK600(QString::fromStdString(device.DeviceIP),9000,"1",this,true);
                QObject::connect(printer1,&Print_RCK600::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
                QObject::connect(printer1,&Print_RCK600::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            }
            else if(device.DeviceID=="2")
            {
                printer2=new Print_RCK600(QString::fromStdString(device.DeviceIP),9000,"2",this,true);
                QObject::connect(printer2,&Print_RCK600::OnSendMsg,this,&NewMainWindow::OnRefreshSend);
                QObject::connect(printer2,&Print_RCK600::OnReceiveMsg,this,&NewMainWindow::OnRefresh);
            }

        }
        else
        {
            //TODO 未完

        }
    }
}
//初始化界面显示
void NewMainWindow::InitForm()
{
    ui->lightButton1->setBgColor(QColor(166,166,166));

    //======状态栏======
    statusLayout = new QHBoxLayout;
    statusLayout->setSpacing(0);
    statusLayout->setMargin(0);
    QLabel *per1 = new QLabel("系统时间:", this);
    QLabel *per2 = new QLabel("2020/09/02 11:14", this);
    //左对齐
    //statusLayout->addWidget();
    //右对齐
    QHBoxLayout *time_layout = new QHBoxLayout;
    time_layout->setSpacing(0);
    time_layout->setContentsMargins(5,0,10,0);
    time_layout->addWidget(per1);
    time_layout->addWidget(per2);

    QWidget *time_widget = new QWidget;
    time_widget->setObjectName(QStringLiteral("time_widget"));
    time_widget->setMinimumHeight(35);
    time_widget->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    time_widget->setLayout(time_layout);
    statusLayout->addWidget(time_widget,0,Qt::AlignRight);//右对齐

    //ui->statusBar->addPermanentWidget(per1); //窗体默认的状态栏,现实永久信息
    //ui->statusBar->addPermanentWidget(per2);
    //ui->statusBar->setStyleSheet(QString("QStatusBar::item{border: 0px}")); // 设置不显示label的边框
    //ui->statusBar->setSizeGripEnabled(false); //设置是否显示右边的大小控制点
    //ui->statusBar->showMessage("Status is here...", 3000); // 显示临时信息，时间3秒钟.
    ui->statusBar->setLayout(statusLayout);
    //======状态栏======

    //设置无边框
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint);
    //设置右下角有个三角图标可以改变窗口大小
    //this->setSizeGripEnabled(true);
    isMousePressed = false;//判断鼠标是否按下的变量
    //加载字体图标
    iconFont = FontAweSomeIcons::Instance().getFont();
    //窗口主布局
    mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    ui->widget->setLayout(mainLayout);

    //生成标题栏
    CreateTitle();
    //生成标题栏的最大最小化等按钮
    CreateTitleMenu();
    //连接信号槽
    connect(title_closeBtn,&QPushButton::clicked,this,&NewMainWindow::title_closeBtn_clicked);
    connect(title_maxBtn,&QPushButton::clicked,this,&NewMainWindow::title_maxBtn_clicked);
    connect(title_minBtn,&QPushButton::clicked,this,&NewMainWindow::title_minBtn_clicked);

    FlatUI::Instance()->setPushButtonQss(ui->pushButton_AllInit, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Start);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Pause, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Stop, 5, 8, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    ui->widget_img->setStyleSheet("border-image: url(:/image/img.png);");

    ////////////使用量////////////
    QPixmap iconLF(":/image/CETeam/擦写使用量.png");
    ui->label_LamFilm->setPixmap(iconLF);

    QPixmap iconSC(":/image/CETeam/发卡-01.png");
    ui->label_SendCard->setPixmap(iconSC);
    //温度计
    ui->widget_LamTemp->setValue(160);
    ui->widget_LamTemp->setMinValue(150);
    ui->widget_LamTemp->setMaxValue(200);
    ui->widget_LamTemp->setPrecision(CThermometer::E_FIVE);
    ////////////使用量////////////


    ui->widget_Main->setStyleSheet("QWidget#widget_Main{background-color:#e9e9e9}"); //设定背景颜色为#e9e9e9

    FlatUI::Instance()->setPushButtonQss(ui->pushButton_DataSIgn);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_DataTran);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Retrun);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_GoManager);

    //ui->groupBox_SendMod->hide();
    //ui->groupBox_CardSend->hide();
    //ui->groupBox_CIS->hide();
    //ui->groupBox_PrintMod1_3->hide();
    //ui->groupBox_Lam->hide();
    //ui->groupBox_Sort->hide();

}
//初始化卡槽样式
void NewMainWindow::InitSlot()
{
    ui->RoundBar_Slot1->setValue(100);

    //圆环，设备自检百分比
    //ui->roundProgressBar_DeviceCheck->setDecimals(0);
    //ui->roundProgressBar_DeviceCheck->setBarStyle(QRoundProgressBar::StyleLine);
    //ui->roundProgressBar_DeviceCheck->setOutlinePenWidth(28);//外环的宽度
    //ui->roundProgressBar_DeviceCheck->setDataPenWidth(25);//内环的宽度

    //卡槽1样式
    ui->RoundBar_Slot1->setFormat("%v");//setFormat默认显示百分号例如：10%
    ui->RoundBar_Slot1->setDecimals(0);
    ui->RoundBar_Slot1->setBarStyle(QRoundProgressBar::StyleLine);
    ui->RoundBar_Slot1->setOutlinePenWidth(20);//外环的宽度
    ui->RoundBar_Slot1->setDataPenWidth(15);//内环的宽度

    //卡槽2样式
    QPalette p1;//字体颜色
    p1.setBrush(QPalette::AlternateBase, Qt::gray);
    p1.setColor(QPalette::Text, Qt::blue);
    ui->RoundBar_Slot2->setFormat("%v");
    //ui->RoundBar_Slot2->setPalette(p1);
    ui->RoundBar_Slot2->setDecimals(0);

    //卡槽3样式，根据百分比的数据变颜色gradientPoints
    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);

    QPalette p2(p1);
    //p2.setBrush(QPalette::Base, Qt::lightGray);
    //p2.setColor(QPalette::Text, Qt::magenta);
    //p2.setColor(QPalette::Shadow, Qt::green);
    //ui->RoundBar_Slot3->setPalette(p2);
    ui->RoundBar_Slot3->setFormat("%v");
    ui->RoundBar_Slot3->setDecimals(0);
    //ui->RoundBar_Slot3->setNullPosition(QRoundProgressBar::PositionLeft);
    //ui->RoundBar_Slot3->setDataColors(gradientPoints);

    ui->RoundBar_Slot4->setFormat("%v");
    ui->RoundBar_Slot4->setDecimals(0);
}
//初始化设备图标
void NewMainWindow::InitStatusImage()
{
    ui->device_SendCard->setStatusImageColor(QPixmap(":/image/CETeam/sendcard_1.png")
                                             ,QPixmap(":/image/CETeam/sendcard_2.png")
                                             ,QPixmap(":/image/CETeam/sendcard_3.png")
                                             ,QPixmap(":/image/CETeam/sendcard_1.png"));
    ui->device_SendCard->setBgPixmap();

    ui->device_Flip->setStatusImageColor(QPixmap(":/image/CETeam/flip_1.png")
                                         ,QPixmap(":/image/CETeam/flip_2.png")
                                         ,QPixmap(":/image/CETeam/flip_3.png")
                                         ,QPixmap(":/image/CETeam/flip_1.png"));
    ui->device_Flip->setBgPixmap();

    ui->device_CIS->setStatusImageColor(QPixmap(":/image/CETeam/cis_1.png")
                                        ,QPixmap(":/image/CETeam/cis_2.png")
                                        ,QPixmap(":/image/CETeam/cis_3.png")
                                        ,QPixmap(":/image/CETeam/cis_4.png"));
    ui->device_CIS->setBgPixmap();

    ui->device_Clean->setStatusImageColor(QPixmap(":/image/CETeam/clean_1.png")
                                          ,QPixmap(":/image/CETeam/clean_2.png")
                                          ,QPixmap(":/image/CETeam/clean_3.png")
                                          ,QPixmap(":/image/CETeam/clean_4.png"));
    ui->device_Clean->setBgPixmap();

    ui->device_Cache1->setStatusImageColor(QPixmap(":/image/CETeam/cache_1.png")
                                           ,QPixmap(":/image/CETeam/cache_2.png")
                                           ,QPixmap(":/image/CETeam/cache_3.png")
                                           ,QPixmap(":/image/CETeam/cache_1.png"));
    ui->device_Cache1->setBgPixmap();

    ui->device_Print1->setStatusImageColor(QPixmap(":/image/CETeam/print_1.png")
                                           ,QPixmap(":/image/CETeam/print_2.png")
                                           ,QPixmap(":/image/CETeam/print_3.png")
                                           ,QPixmap(":/image/CETeam/print_4.png"));
    ui->device_Print1->setBgPixmap();

    ui->print1_Swing->setStatusImageColor(QPixmap(":/image/CETeam/转向_1.png")
                                          ,QPixmap(":/image/CETeam/转向_2.png")
                                          ,QPixmap(":/image/CETeam/转向_3.png")
                                          ,QPixmap(":/image/CETeam/转向_4.png"));
    ui->print1_Swing->setBgPixmap();

    ui->print1_Reader->setStatusImageColor(QPixmap(":/image/CETeam/reader_4.png")
                                           ,QPixmap(":/image/CETeam/reader_1.png")
                                           ,QPixmap(":/image/CETeam/reader_2.png")
                                           ,QPixmap(":/image/CETeam/reader_3.png"));
    ui->print1_Reader->setBgPixmap();


    ui->print1_BackSlot->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                             ,QPixmap(":/image/CETeam/废卡槽2.png")
                                             ,QPixmap(":/image/CETeam/废卡槽3.png")
                                             ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_BackSlot->setBgPixmap();

    ui->print1_FrontSlot->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                              ,QPixmap(":/image/CETeam/废卡槽2.png")
                                              ,QPixmap(":/image/CETeam/废卡槽3.png")
                                              ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_FrontSlot->setBgPixmap();


    //print1_Reader_2
    ui->device_Print1_2->setStatusImageColor(QPixmap(":/image/CETeam/print_1.png")
                                             ,QPixmap(":/image/CETeam/print_2.png")
                                             ,QPixmap(":/image/CETeam/print_3.png")
                                             ,QPixmap(":/image/CETeam/print_4.png"));
    ui->device_Print1_2->setBgPixmap();

    ui->print1_Swing_2->setStatusImageColor(QPixmap(":/image/CETeam/转向_1.png")
                                            ,QPixmap(":/image/CETeam/转向_2.png")
                                            ,QPixmap(":/image/CETeam/转向_3.png")
                                            ,QPixmap(":/image/CETeam/转向_4.png"));
    ui->print1_Swing_2->setBgPixmap();

    ui->print1_Reader_2->setStatusImageColor(QPixmap(":/image/CETeam/reader_4.png")
                                             ,QPixmap(":/image/CETeam/reader_1.png")
                                             ,QPixmap(":/image/CETeam/reader_2.png")
                                             ,QPixmap(":/image/CETeam/reader_3.png"));
    ui->print1_Reader_2->setBgPixmap();


    ui->print1_BackSlot_2->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                               ,QPixmap(":/image/CETeam/废卡槽2.png")
                                               ,QPixmap(":/image/CETeam/废卡槽3.png")
                                               ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_BackSlot_2->setBgPixmap();

    ui->print1_FrontSlot_2->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                                ,QPixmap(":/image/CETeam/废卡槽2.png")
                                                ,QPixmap(":/image/CETeam/废卡槽3.png")
                                                ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_FrontSlot_2->setBgPixmap();

    //3
    ui->device_Print1_3->setStatusImageColor(QPixmap(":/image/CETeam/print_1.png")
                                             ,QPixmap(":/image/CETeam/print_2.png")
                                             ,QPixmap(":/image/CETeam/print_3.png")
                                             ,QPixmap(":/image/CETeam/print_4.png"));
    ui->device_Print1_3->setBgPixmap();

    ui->print1_Swing_3->setStatusImageColor(QPixmap(":/image/CETeam/转向_1.png")
                                            ,QPixmap(":/image/CETeam/转向_2.png")
                                            ,QPixmap(":/image/CETeam/转向_3.png")
                                            ,QPixmap(":/image/CETeam/转向_4.png"));
    ui->print1_Swing_3->setBgPixmap();

    ui->print1_Reader_3->setStatusImageColor(QPixmap(":/image/CETeam/reader_4.png")
                                             ,QPixmap(":/image/CETeam/reader_1.png")
                                             ,QPixmap(":/image/CETeam/reader_2.png")
                                             ,QPixmap(":/image/CETeam/reader_3.png"));
    ui->print1_Reader_3->setBgPixmap();


    ui->print1_BackSlot_3->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                               ,QPixmap(":/image/CETeam/废卡槽2.png")
                                               ,QPixmap(":/image/CETeam/废卡槽3.png")
                                               ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_BackSlot_3->setBgPixmap();

    ui->print1_FrontSlot_3->setStatusImageColor(QPixmap(":/image/CETeam/废卡槽1.png")
                                                ,QPixmap(":/image/CETeam/废卡槽2.png")
                                                ,QPixmap(":/image/CETeam/废卡槽3.png")
                                                ,QPixmap(":/image/CETeam/废卡槽1.png"));
    ui->print1_FrontSlot_3->setBgPixmap();

    //lam
    ui->lam_reader->setStatusImageColor(QPixmap(":/image/CETeam/reader_4.png")
                                        ,QPixmap(":/image/CETeam/reader_1.png")
                                        ,QPixmap(":/image/CETeam/reader_2.png")
                                        ,QPixmap(":/image/CETeam/reader_3.png"));
    ui->lam_reader->setBgPixmap();
    ui->lam_ep->setStatusImageColor(QPixmap(":/image/CETeam/擦写_1.png")
                                    ,QPixmap(":/image/CETeam/擦写_1.png")
                                    ,QPixmap(":/image/CETeam/擦写_1.png")
                                    ,QPixmap(":/image/CETeam/擦写_1.png"));
    ui->lam_ep->setBgPixmap();


    ui->lam_clean->setStatusImageColor(QPixmap(":/image/CETeam/clean_1.png")
                                       ,QPixmap(":/image/CETeam/clean_2.png")
                                       ,QPixmap(":/image/CETeam/clean_3.png")
                                       ,QPixmap(":/image/CETeam/clean_4.png"));
    ui->lam_clean->setBgPixmap();
    ui->lam_lam->setStatusImageColor(QPixmap(":/image/CETeam/覆膜_1.png")
                                     ,QPixmap(":/image/CETeam/覆膜_1.png")
                                     ,QPixmap(":/image/CETeam/覆膜_1.png")
                                     ,QPixmap(":/image/CETeam/覆膜_1.png"));
    ui->lam_lam->setBgPixmap();

    //sort

    ui->sort_slot_1->setStatusImageColor(QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png"));
    ui->sort_slot_1->setBgPixmap();
    ui->sort_slot_2->setStatusImageColor(QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png"));
    ui->sort_slot_2->setBgPixmap();
    ui->sort_slot_3->setStatusImageColor(QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png"));
    ui->sort_slot_3->setBgPixmap();
    ui->sort_slot_4->setStatusImageColor(QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png")
                                         ,QPixmap(":/image/CETeam/卡槽_1.png"));
    ui->sort_slot_4->setBgPixmap();

    ui->sort_cis->setStatusImageColor(QPixmap(":/image/CETeam/cis_1.png")
                                      ,QPixmap(":/image/CETeam/cis_2.png")
                                      ,QPixmap(":/image/CETeam/cis_3.png")
                                      ,QPixmap(":/image/CETeam/cis_4.png"));
    ui->sort_cis->setBgPixmap();
    ui->sort_reader->setStatusImageColor(QPixmap(":/image/CETeam/reader_4.png")
                                         ,QPixmap(":/image/CETeam/reader_1.png")
                                         ,QPixmap(":/image/CETeam/reader_2.png")
                                         ,QPixmap(":/image/CETeam/reader_3.png"));
    ui->sort_reader->setBgPixmap();
    ui->sort_adjust->setStatusImageColor(QPixmap(":/image/CETeam/矫正_1.png")
                                         ,QPixmap(":/image/CETeam/矫正_1.png")
                                         ,QPixmap(":/image/CETeam/矫正_1.png")
                                         ,QPixmap(":/image/CETeam/矫正_1.png"));
    ui->sort_adjust->setBgPixmap();


    ui->print1_arrow1->setStatusImageColor(QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头2.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png"));
    ui->print1_arrow1->setBgPixmap();
    ui->print2_arrow1->setStatusImageColor(QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头2.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png"));
    ui->print2_arrow1->setBgPixmap();
    ui->print3_arrow1->setStatusImageColor(QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头2.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png")
                                           ,QPixmap(":/image/CETeam/左箭头1.png"));
    ui->print3_arrow1->setBgPixmap();
}
//初始化设备消耗
void NewMainWindow::InitEquipConsume()
{
    //打印耗材用量默认值
    ui->widget_Print1_Ribbon->setDefault(0);
    ui->widget_Print1_Film->setDefault(0);
    ui->widget_Print2_Ribbon->setDefault(0);
    ui->widget_Print2_Film->setDefault(0);
    ui->widget_Print3_Ribbon->setDefault(0);
    ui->widget_Print3_Film->setDefault(0);

    ui->widget_Battery_LAM->setDefault(0);
    ui->widget_Battery_EP->setDefault(0);
    ui->widget_Battery_Clean->setDefault(0);
    ui->widget_Battery_CardSender->setDefault(0);
}

//标题栏
void NewMainWindow::CreateTitle()
{
    //设置logo图标
    title_icon = new QLabel;
    title_icon->setObjectName(QStringLiteral("title_icon"));//设置对象名
    title_icon->setMinimumSize(QSize(30,0));//设置最小大小
    title_icon->setMaximumHeight(27);
    title_icon->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);//设置尺寸策略
    title_icon->setAlignment(Qt::AlignCenter);//居中显示
    iconFont.setPointSize(10);//设置字体图标大小
    title_icon->setFont(iconFont);//设置字体族
    //设置FontAweSome图标
    //title_icon->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_apple));
    //设置label显示图片,资源图片
    title_icon->setPixmap(QPixmap(":/image/CETeam/logo.png"));

    //设置标题栏名字
    title_name = new QLabel;
    title_name->setObjectName(QStringLiteral("title_name"));
    title_name->setText(tr("通行证制证程序"));
    title_name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    title_name->setAlignment(Qt::AlignVCenter|Qt::AlignCenter);
    QFont font;
    font.setFamily(QString("微软雅黑"));
    font.setPointSize(14);
    title_name->setFont(font);
    title_name->setContentsMargins(5,2,0,0);
    title_name->installEventFilter(this);//安装事件过滤器

    //设置菜单按钮
    title_menuBtn = new QPushButton;
    title_menuBtn->setObjectName(QStringLiteral("title_menuBtn"));
    title_menuBtn->setFixedWidth(35);
    title_menuBtn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    title_menuBtn->setFlat(true);//设置按钮为扁平化样式
    iconFont.setPointSize(10);
    title_menuBtn->setFont(iconFont);
    title_menuBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_list_ul));
    title_menuBtn->setFocusPolicy(Qt::NoFocus);

    //设置最小化按钮
    title_minBtn = new QPushButton;
    title_minBtn->setObjectName(QStringLiteral("title_minBtn"));
    title_minBtn->setFixedWidth(35);
    title_minBtn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    title_minBtn->setFlat(true);
    iconFont.setPointSize(12);
    title_minBtn->setFont(iconFont);
    title_minBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_minus));
    title_minBtn->setFocusPolicy(Qt::NoFocus);

    //设置最大化按钮
    title_maxBtn = new QPushButton;
    title_maxBtn->setObjectName(QStringLiteral("title_maxBtn"));
    title_maxBtn->setFixedWidth(35);
    title_maxBtn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    title_maxBtn->setFlat(true);
    title_maxBtn->setFont(iconFont);
    title_maxBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_square_o));
    title_maxBtn->setFocusPolicy(Qt::NoFocus);

    //设置关闭按钮
    title_closeBtn = new QPushButton;
    title_closeBtn->setObjectName(QStringLiteral("title_closeBtn"));
    title_closeBtn->setFixedWidth(40);
    title_closeBtn->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Expanding);
    title_closeBtn->setFlat(true);
    iconFont.setPointSize(14);
    title_closeBtn->setFont(iconFont);
    title_closeBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_close));
    title_closeBtn->setFocusPolicy(Qt::NoFocus);

    //创建按钮布局
    titleBtn_layout = new QHBoxLayout;
    titleBtn_layout->setSpacing(0);
    titleBtn_layout->setContentsMargins(0,0,0,0);
    titleBtn_layout->addWidget(title_menuBtn);
    titleBtn_layout->addWidget(title_minBtn);
    titleBtn_layout->addWidget(title_maxBtn);
    titleBtn_layout->addWidget(title_closeBtn);

    //创建一个widget放置标题栏按钮
    titleBtn_widget = new QWidget;
    titleBtn_widget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);
    titleBtn_widget->setLayout(titleBtn_layout);

    //创建标题栏主布局
    title_layout = new QHBoxLayout;
    title_layout->setSpacing(0);
    title_layout->setContentsMargins(5,0,0,0);
    title_layout->addWidget(title_icon);
    title_layout->addWidget(title_name);
    title_layout->addWidget(titleBtn_widget);

    //创建标题栏widget放置标题栏元素
    title_widget = new QWidget;
    title_widget->setObjectName(QStringLiteral("title_widget"));
    title_widget->setMinimumHeight(35);
    title_widget->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Fixed);
    title_widget->setLayout(title_layout);

    //加入主布局
    mainLayout->addWidget(title_widget);
}
//创建标题栏菜单内容
void NewMainWindow::CreateTitleMenu()
{
    //创建语言切换菜单
    langue_menu = new QMenu(tr("语言"));
    setChinese = new QAction(tr("中文"),this);
    setChinese->setIcon(QIcon(":/image/CETeam/china_32.png"));
    setChinese->setCheckable(true);
    setChinese->setChecked(true);
    setEnglish = new QAction(tr("英文"),this);
    setEnglish->setIcon(QIcon(":/image/CETeam/english_32.png"));
    setEnglish->setCheckable(true);
    langue_menu->addAction(setChinese);
    langue_menu->addAction(setEnglish);
    langueGroup = new QActionGroup(this);
    langueGroup->addAction(setEnglish);
    langueGroup->addAction(setChinese);

    //创建主题切换菜单
    theme_menu = new QMenu(tr("主题"));
    setBlue = new QAction(tr("蓝色"),this);
    setBlue->setCheckable(true);
    setBlue->setChecked(true);
    setBlack = new QAction(tr("黑色"),this);
    setBlack->setCheckable(true);
    theme_menu->addAction(setBlue);
    theme_menu->addAction(setBlack);
    themeGroup = new QActionGroup(this);
    themeGroup->addAction(setBlue);
    themeGroup->addAction(setBlack);

    //参数设置
    setPara = new QAction(tr("参数设置"),this);
    //测试耗材用量
    setConsumables = new QAction(tr("测试耗材用量"),this);
    //测试导航栏
    setNav = new QAction(tr("导航栏"),this);

    //创建主菜单,将主题和语言菜单当二级菜单加入主菜单
    title_menu = new QMenu;
    title_menu->addAction(setPara);

    title_menu->addSeparator();
    title_menu->addMenu(langue_menu);
    title_menu->addMenu(theme_menu);
    title_menuBtn->setMenu(title_menu);//将主菜单设置到菜单按钮
    title_menu->addSeparator();
    title_menu->addAction(setConsumables);
    title_menu->addAction(setNav);

    //Click Action - 关联换肤和切换语言功能
    connect(langueGroup,&QActionGroup::triggered,this,&NewMainWindow::changeLangue);
    connect(themeGroup,&QActionGroup::triggered,this,&NewMainWindow::changeTheme);

    //Click Action
    connect(setPara,&QAction::triggered,this,&NewMainWindow::funcParamter);

    connect(setNav,&QAction::triggered,this,&NewMainWindow::funcNav);

    connect(setConsumables,&QAction::triggered,this,&NewMainWindow::funcConsumables);
}

//机构接收事件
void NewMainWindow::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 = "+HexString);

    if(ModType=="SendMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            sendCardModChecked=true;
            //ui ->textEdit ->append("进卡机构初始化成功");
            //ui->groupBox_SendMod->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
            //圆环百分比
            //int current=ui->roundProgressBar_DeviceCheck->value();
            //qDebug()<<"已完成检测设备数 = " <<current+1;
            //ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //QStringList returnValue= CommHelper::Instance()->HexStringToBytes("AA55700456010802D6");
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);//解析传感器参数
            //从第５位，开始是数据
            //qDebug()<<"returnValue.length() = "<<returnValue.length();
            //qDebug()<<returnValue;
            CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));

            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);//转化为二进制
            sendMod->SetCurrentStatus(statusList);
            if(forloop == true)
            {
                SendModChangedEvent();
            }
        }
    }
    else if(ModType=="PrintMod")
    {
        QString number= QString::number(c);

        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            dicPrintModChecked[number]=true;
            //ui ->textEdit ->append("打印机构初始化成功");
            if(number=="1")
            {
                //ui->groupBox_PrintMod1->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="2")
            {
                //ui->groupBox_PrintMod2->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="3")
            {
                //ui->groupBox_PrintMod3->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            //圆环百分比
            //int current=ui->roundProgressBar_DeviceCheck->value();
            //qDebug()<<"已完成检测设备数 = " <<current+1;
            //ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            if(number=="1")
            {
                printMod1->SetCurrentStatus(statusList);
            }
            else if(number=="2")
            {
                printMod2->SetCurrentStatus(statusList);
            }
            else if(number=="3")
            {
                printMod3->SetCurrentStatus(statusList);
            }
            if(forloop == true)
            {
                PrintModChangedEvent(number);
            }
        }
    }
    else if(ModType=="LamMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            lamModChecked=true;
            //ui ->textEdit ->append("覆膜机构初始化成功");
            //ui->groupBox_Lam->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            //int current=ui->roundProgressBar_DeviceCheck->value();
            //qDebug()<<"已完成检测设备数 = " <<current+1;
            //ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            lamMod->SetCurrentStatus(statusList);
            if(forloop == true)
            {
                LamModChangedEvent();
            }
        }
    }
    else if(ModType=="SortMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            sortModChecked=true;
            //ui ->textEdit ->append("分拣机构初始化成功");
            //ui->groupBox_Sort->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            //int current=ui->roundProgressBar_DeviceCheck->value();
            //qDebug()<<"已完成检测设备数 = " <<current+1;
            //ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            sortMod->SetCurrentStatus(statusList);
            if(forloop == true)
            {
                SortModChangedEvent();
            }
        }
    }
    else if(ModType=="CardSender")
    {

    }
    else if(ModType=="Print")
    {

    }
}
//机构发送命令事件
void NewMainWindow::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送数据 ="+HexString);
    //ui ->textEdit_Send ->append(ModType+" 机构发送数据 ="+HexString);
}

//关闭窗体
void NewMainWindow::title_closeBtn_clicked()
{
    this->close();//退出程序
}
//最小化
void NewMainWindow::title_minBtn_clicked()
{
    this->showMinimized();//最小化
}
//最大化
void NewMainWindow::title_maxBtn_clicked()
{
    if(isMaximized()){//判断窗口是否已经最大化,是则还原,不是则最大化
        this->showNormal();
        title_maxBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_square_o));
    }else{
        windowWidth = this->width();//记录窗口普通状态下的宽度,在窗口最大化而拖动了窗口是计算窗口位置用
        this->showMaximized();
        //改变最大化按钮的图标
        title_maxBtn->setText(FontAweSomeIcons::Instance().getIconChar(FontAweSomeIcons::IconIdentity::icon_retweet));
    }
}

//切换语言后刷新界面
void NewMainWindow::RetranslateUI()
{
    langue_menu->setTitle(tr("语言"));
    setChinese->setText(tr("中文"));
    setEnglish->setText(tr("英语"));
    title_name->setText(tr("通行证制证程序"));
    theme_menu->setTitle(tr("主题"));
    setBlue->setText(tr("蓝色"));
    setBlack->setText(tr("黑色"));
}
//切换语言后刷新界面
void NewMainWindow::RetranslateUIEnglish()
{
    langue_menu->setTitle(tr("Langue"));
    setChinese->setText(tr("Chinese"));
    setEnglish->setText(tr("English"));
    title_name->setText(tr("Application"));
    theme_menu->setTitle(tr("Theme"));
    setBlue->setText(tr("blue"));
    setBlack->setText(tr("black"));
}
//切换语言
void NewMainWindow::changeLangue()
{
    if(setChinese->isChecked()){//判断选中了哪个语言
        translator->load(":/langue/zh_cn.qm");//加载翻译文件
        qApp->installTranslator(translator);//安装翻译文件
        //刷新界面,因为没有Ui文件，所以要手动实现刷新(类似:setBlue->setText(tr("blue"));如果有使用Ui文件只需要调用ui->retranslateUi(this)即可
        ui->retranslateUi(this);
        RetranslateUI();
    }else if(setEnglish->isChecked()){
        translator->load(":/langue/lang_en.qm");//加载翻译文件
        qApp->installTranslator(translator);//安装翻译文件

        //刷新界面,因为没有Ui文件，所以要手动实现刷新(类似:setBlue->setText(tr("blue"));重新执行一次赋值),如果有使用Ui文件只需要调用ui->retranslateUi(this)即可
        ui->retranslateUi(this);
        RetranslateUIEnglish();
    }
}
//切换主题
void NewMainWindow::changeTheme()
{
    if(setBlue->isChecked()){//判断选中了哪个主题,然后应用相应主题
        QFile styleFile(QStringLiteral(":/css/blue.css"));//读取主题文件
        if(styleFile.open(QFile::ReadOnly)){
            QString qss = styleFile.readAll();
            qApp->setStyleSheet(qss);//设置主题
            qApp->setPalette(QPalette(QColor("#f0f0f0")));//设置窗体调色板
            styleFile.close();
        }else{
            qDebug()<<"styleFile Loading error";
        }
    }else if(setBlack->isChecked()){
        QFile styleFile(QStringLiteral(":/css/black.css"));
        if(styleFile.open(QFile::ReadOnly)){
            QString qss = styleFile.readAll();
            qApp->setStyleSheet(qss);
            qApp->setPalette(QPalette(QColor("#f0f0f0")));
            styleFile.close();
        }else{
            qDebug()<<"styleFile Loading error";
        }
    }
}

//设置参数
void NewMainWindow::funcParamter()
{
    dialog=new ParaWindow(this);
    //dialog->setModal(false);//非模态
    //dialog->setModal(true);//模态，只能移动弹出的窗口，后面的窗口不能点击
    if(dialog->exec()==QDialog::Accepted)
    {
        updateParamter(dialog->para);
    }
}
//更新参数
void NewMainWindow::updateParamter(ParamterClass *para)
{
    isPrint1=para->isUsePrint1;
    isPrint2=para->isUsePrint2;
    isPrint3=para->isUsePrint3;
    isUsePrintMod1=para->isPrint1ModEnable;
    isUsePrintMod2=para->isPrint2ModEnable;
    isUsePrintMod3=para->isPrint3ModEnable;

    //是否打印
    printer1->SetSimulate(!isPrint1);
    printer2->SetSimulate(!isPrint2);
    //printer3->SetSimulate(!isPrint3);

    //覆膜
    isUseLam=para->isUseLam;
    //默认使用卡槽
    if(para->isOpenSolt1==true)
        soltIndex=1;
    else if(para->isOpenSolt2==true)
        soltIndex=2;
    else if(para->isOpenSolt3==true)
        soltIndex=3;
    else if(para->isOpenSolt4==true)
        soltIndex=4;
}

void NewMainWindow::funcNav()//测试导航
{
    UIDemo08 *frm=new UIDemo08(this);
    //frm->setModel(false);
    frm->show();
}

void NewMainWindow::funcConsumables()//测试耗材
{
    double currValue= ui->widget_Print1_Ribbon->getValue();
    ui->widget_Print1_Ribbon->setValue(currValue-10);
}

bool NewMainWindow::eventFilter(QObject *obj, QEvent *e)//事件过滤器
{
    if(obj == title_name){//判断发送信号的是否是标题栏
        if(e->type() == QEvent::MouseButtonDblClick){//是否是双击
            QMouseEvent *event = static_cast<QMouseEvent*>(e);
            if(event->button() == Qt::LeftButton){//是否是鼠标左键
                title_maxBtn_clicked();//双击则最大化或还原窗口
                return true;
            }
        }
        else if(e->type() == QEvent::MouseButtonPress){//是否是单击
            QMouseEvent *event = static_cast<QMouseEvent*>(e);
            if(event->button() == Qt::LeftButton){
                isMousePressed = true;//单击则记录已经单击
                mousePressPos = event->globalPos() - this->pos();//记录点击位置到窗口起始位置偏移
                return true;
            }
        }else{
            return false;
        }
    }
    return QObject::eventFilter(obj,e);
}

void NewMainWindow::mouseMoveEvent(QMouseEvent *e)//处理鼠标移动事件
{
    if(isMousePressed){//判断鼠标左键是否点击
        if(isMaximized()){//窗口是否处于最大化状态,是则还原窗口,并计算偏移位置
            this->showNormal();
            if(mousePressPos.x() - windowWidth/2 <= 0){
                mousePressPos = e->globalPos();
            }else if(mousePressPos.x() + windowWidth/2 >= qApp->desktop()->availableGeometry().width()){
                int desktopWidth = qApp->desktop()->availableGeometry().width();
                int temp = desktopWidth - e->globalPos().x();
                temp = windowWidth - temp;
                mousePressPos = QPoint(temp,e->globalPos().y());
            }else{
                mousePressPos = QPoint(windowWidth/2,e->globalPos().y());
            }
        }
        this->move(e->globalPos() - mousePressPos);//移动窗口
        e->accept();
    }
}

void NewMainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    isMousePressed = false;//鼠标点击置false
}

///////////////////////////////////////////////////////////////////
//发卡器
void NewMainWindow::on_pushButton_SendCardInit_clicked()
{

}
//发卡器发卡
void NewMainWindow::on_pushButton_SendCard_clicked()
{

}
//初始化进卡机构
void NewMainWindow::on_pushButton_SmInit_clicked()
{
    try {
        if (sendMod==NULL)
        {
            qDebug()<<"对象为空";
            return;
        }
        sendMod->InitDevice();
    }
    catch(int e)
    {
        std::cout << "输入不是整数\n";
    }
}

void NewMainWindow::on_pushButton_SmFlipin_clicked()
{
    try
    {
        sendMod->FlipCardInFun();
    }
    catch(int e)
    {
        std::cout << "输入不是整数\n";
    }
}

void NewMainWindow::on_pushButton_SmFlipout_clicked()
{
    sendMod->FlipCardOutFun();
}

void NewMainWindow::on_pushButton_SmCleanIn_clicked()
{
    sendMod->CleanCardInFun();
}

void NewMainWindow::on_pushButton_SmCleanOut_clicked()
{
    sendMod->CleanCardOutFun();
}

void NewMainWindow::on_pushButton_SmCleanCache_clicked()
{
    sendMod->CardCacheOutFun();
}

//覆膜机构
void NewMainWindow::on_pushButton_LamModInit_clicked()
{
    if (lamMod==NULL)
    {
        qDebug()<<"对象为空";
        return;
    }
    lamMod->InitDevice();

}
//分拣机构
void NewMainWindow::on_pushButton_SortModInit_clicked()
{
    if (sortMod==NULL)
    {
        qDebug()<<"对象为空";
        return;
    }
    sortMod->InitDevice();
}
///////////////////////////////////////////////////////////////////


//全部初始化
void NewMainWindow::on_pushButton_AllInit_clicked()
{
    AppInit::Instance()->LoadParamterFile();
    updateParamter(AppInit::Instance()->domparser->para);

    ui->lightButton1->startAlarm();
    //发卡器初始化
    int ret = cardsender->InitDevice();
    if(ret==0)
    {
        //ui ->textEdit ->append("发卡器初始化成功");
        //ui->groupBox_CardSender->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
        //圆环百分比
        //int current=ui->roundProgressBar_DeviceCheck->value();
        //qDebug()<<"已完成检测设备数 = " <<current+1;
        //ui->roundProgressBar_DeviceCheck->setValue(current+1);
    }
    //进卡机构
    sendMod->InitDevice();
    while(!sendCardModChecked)
    {
        CommHelper::Instance()->sleepme(1000);
    }

    printMod1->InitDevice();
    while(!dicPrintModChecked["1"])
    {
        CommHelper::Instance()->sleepme(1000);
    }
    printMod2->InitDevice();
    while(!dicPrintModChecked["2"])
    {
        CommHelper::Instance()->sleepme(1000);
    }
    if(isUsePrintMod3)
    {
        printMod3->InitDevice();
        while(!dicPrintModChecked["3"])
        {
            CommHelper::Instance()->sleepme(1000);
        }
    }
    lamMod->InitDevice();
    while(!lamModChecked)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    //初始化打印机1
    bool res=printer1->InitDevice();
    if(!res)
    {
        qDebug()<<"打印机2初始化失败";
        //QMessageBox::information(this, "Title", "打印机初始化失败");
        return;
    }

    //初始化打印机2
    if(isUsePrintMod2)
    {
        res=printer2->InitDevice();
        if(!res)
        {
            qDebug()<<"打印机2初始化失败";
            //QMessageBox::information(this, "Title", "打印机2初始化失败");
            return;
        }
    }

    sortMod->InitDevice();
    CommHelper::Instance()->sleepme(5000);
    sortMod->LightControl(4,0);

    //自检完成
    ui->lightButton1->stopAlarm();
    ui->lightButton1->setBgColor(QColor(100, 184, 255));
    initFinish=true;
    currentStatus=ApplicationStatus::InitFinish;

}
//start
void NewMainWindow::on_pushButton_Start_clicked()
{
    if(!initFinish)
    {
        QMessageBox::information(this, "标题", "初始化未完成！");
        return;
    }
    try
    {
        //参数配置
        //1.读取参数文件
        //AppInit::Instance()->LoadParamterFile();
        //updateParamter(AppInit::Instance()->domparser->para);
        //2.打印参数
        printer1->SetSimulate(!isPrint1);//isPrint1是否打印，true:打印,false:进卡不打印
        if(isUsePrintMod2)
        {
            printer2->SetSimulate(!isPrint2);//isPrint1是否打印，true:打印,false:进卡不打印
        }
        if(currentStatus==ApplicationStatus::InitFinish)
        {
            forloop = true;
            ui->lightButton1->setBgColor(QColor(24, 189, 155));
            currentStatus=ApplicationStatus::Startup;
        }
        else
        {
            QMessageBox::information(this,tr("标题"),tr("设备初始化失败!"));
        }
    }
    catch(...)
    {
        QMessageBox::information(this, "标题", "开始失败！");
        return;
    }
}
//pause
void NewMainWindow::on_pushButton_Pause_clicked()
{
    currentStatus==ApplicationStatus::Pause;
    ui->lightButton1->setBgColor(QColor(255, 107, 107));
}
//停止
void NewMainWindow::on_pushButton_Stop_clicked()
{
    if (!(QMessageBox::information(this,tr("exit tip"),tr("Do you really want exit ?"),tr("Yes"),tr("No"))))
    {
        QApplication* app;
        //app->quit();
        app->exit(0);
    }
}
//返回
void NewMainWindow::on_pushButton_Retrun_clicked()
{
    this->close();//退出程序
}

///////////////======调度控制 - 连续走卡=======////////////////////////
//进卡模块
void NewMainWindow::SendModChangedEvent()
{
    if(flipInFinish==true)
    {
        return;
    }
    flipInFinish=true;
    qDebug()<<"SendModChangedEvent";
    QtConcurrent::run(this,&NewMainWindow::FlipCardInFun);//多线程执行死循环启动
    QtConcurrent::run(this,&NewMainWindow::FlipCardOutFun);
    QtConcurrent::run(this,&NewMainWindow::CleanCardOutFun);

    flipInFinish=false;
}
void NewMainWindow::FlipCardInFun()
{

    if(flipCardIn==true)
    {
        return;
    }
    flipCardIn=true;
    QMutexLocker locker(&m_mutex);
    // m_mutex.lock();
    //查询发卡器状态
    cardsender->RequestStatus();

    if(cardsender->currentCardStatus!=CardSender::NoCard
            && sendMod->currentRotationFlipStatus==SendMod::Idle
            && sendMod->currentRotationFlipCardStatus==SendMod::NoCard)
    {
        qDebug()<<"FlipCardInFun";
        qDebug()<<cardsender->currentCardStatus;
        qDebug()<<sendMod->currentRotationFlipStatus;
        qDebug()<<sendMod->currentRotationFlipCardStatus;

        sendMod->FlipCardInFun();
        QTime t;
        t.start();
        while(t.elapsed()<500);

        //发卡器发卡
        cardsender->SendCard();

    }
    flipCardIn=false;
}
void NewMainWindow::FlipCardOutFun()
{
    if(sendMod->currentRotationFlipCardStatus==SendMod::HaveCard
            &&sendMod->currentRotationFlipStatus==SendMod::Idle
            &&sendMod->currentCleanStatus==SendMod::CleanIdle
            &&sendMod->currentCleanCardStatus==SendMod::CleanNoCard )
    {
        qDebug()<<"FlipCardOutFun";
        sendMod->FlipCardOutFun();

        QTime t;
        t.start();
        while(t.elapsed()<4000);
        sendMod->CleanCardInFun();
    }
}
void NewMainWindow::CleanCardOutFun()
{
    if(sendMod->currentCleanStatus==SendMod::CleanIdle
            && sendMod->currentCleanCardStatus==SendMod::CleanHaveCard
            && sendMod->currentCacheStatus==SendMod::CacheIdle
            && sendMod->currentCacheCardStatus==SendMod::CacheNoCard
            )
    {
        qDebug()<<"CleanCardOutFun";

        sendMod->CleanCardOutFun();
    }
}
//TODO 清洁进卡，需要替换 CIS设备 为摄像头机构
void NewMainWindow::CleanCardInFun()
{
    if(sendMod->currentCleanStatus==SendMod::CleanIdle
            && sendMod->currentCleanCardStatus==SendMod::CleanNoCard
            && sendMod->currentPhotoCardStatus==SendMod::PhotoIdle
            && sendMod->currentPhotoStatus==SendMod::PhotoHaveCard
            )
    {
        qDebug()<<"CleanCardInFun";
        sendMod->CleanCardInFun();
    }
}


//打印模块
void NewMainWindow::PrintModChangedEvent(QString number)
{
    qDebug()<<"PrintModChangedEvent";
    qDebug()<<"number"<<number;

    if(number=="1"&& isUsePrintMod1)
    {
        QtConcurrent::run(this,&NewMainWindow::CardInAndCardOut,1);
        QtConcurrent::run(this,&NewMainWindow::Printer1FlipCardInFun);
        QtConcurrent::run(this,&NewMainWindow::Printer1CardInFun);
        //QtConcurrent::run(this,&NewMainWindow::Printer1CardOutFun);
    }
    else if(number=="2" && isUsePrintMod2)
    {
        QtConcurrent::run(this,&NewMainWindow::CardInAndCardOut,2);
        QtConcurrent::run(this,&NewMainWindow::Printer2FlipCardInFun);
        QtConcurrent::run(this,&NewMainWindow::Printer2CardInFun);
        //QtConcurrent::run(this,&NewMainWindow::Printer2CardOutFun);
    }
}

//写卡工位进卡,优先后轨道出卡，进卡出卡占用长轨道
void NewMainWindow::CardInAndCardOut(int serialnumber)//1:1号打印机,2:2号打印机
{
    if(syncCardInAndCardOut==true)
    {
        return;
    }
    syncCardInAndCardOut=true;

    if(serialnumber==1)
    {
        //出卡
        if(IsLongSlidesReady(serialnumber,1)
                && lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                && lamMod->currentFrontCacheStatus==LamMod::Idle
                && printMod1->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle)
        {
            qDebug()<<"覆膜缓存进卡，打印1出卡";
            lamMod->CleanSlide();
            printMod2->LongSildePass();//打印机构2，长轨道过卡
            printMod1->Silde2Out();
        }
        else
        {
            //进卡
            if(IsLongSlidesReady(serialnumber,0)
                    && printMod1->currentWriterStatus==PrintMod::WriterIdle
                    && printMod1->currentWriterCardStatus ==PrintMod::WriterNoCard
                    && sendMod->currentCacheStatus==SendMod::CacheIdle
                    && sendMod->currentCacheCardStatus==SendMod::CacheHaveCard

                    )
            {
                printMod1->WriteIn();
                sendMod->CardCacheOutFun();
            }
        }
    }

    else if(serialnumber==2)
    {
        //出卡
        if(IsLongSlidesReady(serialnumber,1)
                && lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                && lamMod->currentFrontCacheStatus==LamMod::Idle
                && printMod1->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle)
        {
            qDebug()<<"覆膜缓存进卡，打印1出卡";
            lamMod->CleanSlide();
            //printMod2->LongSildePass();//打印机构2，长轨道过卡
            printMod2->Silde2Out();//打印机构2，短轨道出卡
        }
        else
        {
            //进卡
            if(IsLongSlidesReady(serialnumber,0)
                    && printMod2->currentWriterStatus==PrintMod::WriterIdle
                    && printMod2->currentWriterCardStatus ==PrintMod::WriterNoCard
                    && sendMod->currentCacheStatus==SendMod::CacheIdle
                    && sendMod->currentCacheCardStatus==SendMod::CacheHaveCard)
            {
                printMod1->LongSildePass();
                printMod2->WriteIn();
                sendMod->CardCacheOutFun();
            }
        }
    }
    syncCardInAndCardOut=false;
}

/// <summary>
/// 相关的长轨道是否空闲
/// </summary>
/// <param name="currentSN">当前设备序号</param>
/// <param name="cardMove">0:进卡,1:出卡</param>
/// <returns></returns>
bool NewMainWindow::IsLongSlidesReady(int currentSN, int cardMove)
{
    bool isReady = true;

    if (cardMove == 0)//进卡
    {
        if(currentSN==1)
        {
            if(printMod1->currentLongSildeReady==PrintMod::NoLong)
            {
                isReady = false;
            }
        }
        else if(currentSN==2)
        {
            if(printMod1->currentLongSildeReady==PrintMod::NoLong
                    ||printMod2->currentLongSildeReady==PrintMod::NoLong)
            {
                isReady = false;
            }

        }
        else if(currentSN==3)
        {
            if(printMod1->currentLongSildeReady==PrintMod::NoLong
                    ||printMod2->currentLongSildeReady==PrintMod::NoLong
                    ||printMod3->currentLongSildeReady==PrintMod::NoLong)
            {
                isReady = false;
            }
        }


        //        for (int i = 0; i <= currentSN; i++)
        //        {
        //            if (printerModList[i].CurrentLongSildeReady == LongSildeReady.No
        //                || printerModList[i].LongPassCommandStatus != CommandStatus.Finish
        //                || printerModList[i].OutCardCommandStatus != CommandStatus.Finish
        //                || printerModList[i].WriteInCommandStatus != CommandStatus.Finish)
        //            {
        //                isReady = false;
        //                break;
        //            }
        //        }
    }
    else//出卡，出卡时当前开始的长轨道都要准备好
    {
        if(currentSN==1)
        {
            if(printMod1->currentLongSildeReady==PrintMod::NoLong
                    ||printMod2->currentLongSildeReady==PrintMod::NoLong)
            {
                isReady = false;
                //break;
            }
        }
        else if(currentSN==2)
        {
            if(printMod2->currentLongSildeReady==PrintMod::NoLong)
            {
                isReady = false;
            }
        }
        else if(currentSN==3)
        {
            //            if(printMod2->currentLongSildeReady==PrintMod::NoLong)
            //            {
            //                isReady = false;
            //            }
        }

        //for (int i = currentSN; i < printerModList.Count; i++)
        //for (int i = currentSN; i < 2; i++)
        //{
        //            if (printerModList[i].CurrentLongSildeReady == LongSildeReady.No
        //                || printerModList[i].LongPassCommandStatus != CommandStatus.Finish
        //                || printerModList[i].OutCardCommandStatus != CommandStatus.Finish
        //                || printerModList[i].WriteInCommandStatus != CommandStatus.Finish)
        //            {
        //                isReady = false;
        //                break;
        //            }
        //}
    }
    return isReady;
}

//转向进卡,读写工位出卡
void NewMainWindow::Printer1FlipCardInFun()
{
    if(syncPrintFlipCardIn==true)
    {
        return;
    }
    syncPrintFlipCardIn=true;

    if(printMod1->currentSwingCardStatus==PrintMod::SwingNoCard
            && printMod1->currentSwingStatus ==PrintMod::SwingIdle
            && printMod1->currentWriterCardStatus==PrintMod::WriterHaveCard
            && printMod1->currentWriterStatus ==PrintMod::WriterIdle)
    {
        printMod1->WriteOut();
    }
    syncPrintFlipCardIn=false;
}

//打印机2转向进卡,读写工位出卡
void NewMainWindow::Printer2FlipCardInFun()
{
    if(syncPrint2FlipCardIn==true)
    {
        return;
    }
    syncPrint2FlipCardIn=true;

    if(printMod2->currentSwingCardStatus==PrintMod::SwingNoCard
            && printMod2->currentSwingStatus ==PrintMod::SwingIdle
            && printMod2->currentWriterCardStatus==PrintMod::WriterHaveCard
            && printMod2->currentWriterStatus ==PrintMod::WriterIdle)
    {
        printMod2->WriteOut();
    }
    syncPrint2FlipCardIn=false;
}

//打印机进卡
void NewMainWindow::FeedCardAndPrint(int num)
{
    if(num==1)
    {
        bool res= printer1->FeedCardAndPrint();
    }
    else if(num==2)
    {
        bool res= printer2->FeedCardAndPrint();
    }
}

//打印机构1进卡
void NewMainWindow::Printer1CardInFun()
{
    //打印机状态：准备打印，
    //转向机构：有卡、空闲

    if(syncPrinterCardIn==true)
    {
        return;
    }
    syncPrinterCardIn=true;

    R600Status status;
    printer1->GetStatus(status);

    qDebug()<<"QtConcurrent-Printer1CardInFun"<<"MainStatus ="<<status.MainStatus;
    qDebug()<<"isSimulated ="<<printer1->isSimulated;

    if(printMod1->currentSwingCardStatus==PrintMod::SwingHaveCard
            && printMod1->currentSwingStatus ==PrintMod::SwingIdle
            && status.MainStatus==1004)
    {
        //打印机下载任务
        bool res= printer1->LoadPrintTask(frontimagepath,backimagepath,false);
        if(res==true)
        {
            QtConcurrent::run(this,&NewMainWindow::FeedCardAndPrint,1);
            QTime t;
            t.start();
            while(t.elapsed()<1000);
            //机构进卡
            printMod1->PrinterIn();
        }
        else
        {
            qDebug()<<"任务下载失败";
        }
    }


    if(printer1->isSimulated)
    {
        if(printMod1->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1027)//制卡中，此时可以进卡。只过卡不打印时，没有制卡中（等待排卡状态）
        {
            printMod1->PrinterOut();
            printer1->EjectCard();
        }
    }
    else
    {
        if( printMod1->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1025)//等待排卡，此时可以出卡
        {
            printMod1->PrinterOut();
            printer1->EjectCard();
        }
    }
    syncPrinterCardIn=false;
}
//打印机构2进卡
void NewMainWindow::Printer2CardInFun()
{
    if(syncPrinter2CardIn==true)
    {
        return;
    }
    syncPrinter2CardIn=true;

    R600Status status;
    printer2->GetStatus(status);

    if(printMod2->currentSwingCardStatus==PrintMod::SwingHaveCard
            && printMod2->currentSwingStatus ==PrintMod::SwingIdle
            && status.MainStatus==1004)
    {
        //打印机下载任务
        bool res= printer2->LoadPrintTask(frontimagepath,backimagepath,false);
        if(res==true)
        {
            QtConcurrent::run(this,&NewMainWindow::FeedCardAndPrint,2);
            QTime t;
            t.start();
            while(t.elapsed()<1000);
            //机构进卡
            printMod2->PrinterIn();
        }
        else
        {
            qDebug()<<"任务下载失败";
        }
    }

    qDebug()<<"QtConcurrent-Printer2CardOutFun"<<"MainStatus ="<<status.MainStatus;
    qDebug()<<"isSimulated ="<<printer2->isSimulated;

    if(printer2->isSimulated)
    {
        if(printMod2->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod2->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1027)//制卡中，此时可以进卡。只过卡不打印时，没有制卡中（等待排卡状态）
        {
            printMod2->PrinterOut();
            printer2->EjectCard();
        }
    }
    else
    {
        if( printMod2->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod2->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1025)//等待排卡，此时可以出卡
        {
            printMod2->PrinterOut();
            printer2->EjectCard();
        }
    }
    syncPrinter2CardIn=false;
}

//打印机构1出卡
void NewMainWindow::Printer1CardOutFun()
{
    if(syncPrinterCardOut==true)
    {
        return;
    }
    syncPrinterCardOut=true;

    R600Status status;
    printer1->GetStatus(status);

    qDebug()<<"QtConcurrent-PrinterCardOutFun"<<"MainStatus ="<<status.MainStatus;
    qDebug()<<"isSimulated ="<<printer1->isSimulated;

    if(printer1->isSimulated)
    {
        if(printMod1->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1027)//制卡中，此时可以进卡。只过卡不打印时，没有制卡中（等待排卡状态）
        {
            printMod1->PrinterOut();
            printer1->EjectCard();
        }
    }
    else
    {
        if( printMod1->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod1->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1025)//等待排卡，此时可以出卡
        {
            printMod1->PrinterOut();
            printer1->EjectCard();
        }
    }
    syncPrinterCardOut=false;
}
//打印机构2出卡
void NewMainWindow::Printer2CardOutFun()
{
    if(syncPrinterCardOut==true)
    {
        return;
    }
    syncPrinterCardOut=true;

    R600Status status;
    printer2->GetStatus(status);

    qDebug()<<"QtConcurrent-Printer2CardOutFun"<<"MainStatus ="<<status.MainStatus;
    qDebug()<<"isSimulated ="<<printer2->isSimulated;

    if(printer2->isSimulated)
    {
        if(printMod2->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod2->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1027)//制卡中，此时可以进卡。只过卡不打印时，没有制卡中（等待排卡状态）
        {
            printMod2->PrinterOut();
            printer2->EjectCard();
        }
    }
    else
    {
        if( printMod2->currentShortSildeCardStatus==PrintMod::ShortNoCard
                && printMod2->currentShortSildeStatus ==PrintMod::ShortIdle
                && status.MainStatus==1025)//等待排卡，此时可以出卡
        {
            printMod2->PrinterOut();
            printer2->EjectCard();
        }
    }
    syncPrinterCardOut=false;
}

//进卡机构缓冲出卡,打印机构1进卡
void NewMainWindow::CacheCardOutFun()
{
    if( sendMod->currentCacheStatus==SendMod::CacheIdle
            && sendMod->currentCacheCardStatus==SendMod::CacheHaveCard
            && printMod1->currentLongSildeStatus==PrintMod::Idle
            )
    {
        qDebug()<<"CacheCardOutFun";
        printMod1->CleanSlide();
        sendMod->CardCacheOutFun();
    }
}
//打印机构1出卡，打印机构2进卡
void NewMainWindow::PrintMod2CardOutFun()
{
    if(printMod2->currentLongSildeStatus==PrintMod::Idle
            && printMod1->currentShortSildeCardStatus==PrintMod::ShortHaveCard
            && printMod1->currentShortSildeStatus==PrintMod::Idle)
    {

        qDebug()<<"PrintMod2CardOutFun";
        printMod2->CleanSlide();
        printMod1->Silde2Out();

    }
}
//打印机构2出卡，打印机构3进卡
void NewMainWindow::PrintMod3CardOutFun()
{
    if(printMod3->currentLongSildeStatus==PrintMod::Idle
            && printMod2->currentShortSildeCardStatus==PrintMod::ShortHaveCard
            && printMod2->currentShortSildeStatus==PrintMod::Idle)
    {
        qDebug()<<"PrintMod3CardOutFun";
        printMod3->CleanSlide();
        printMod2->Silde2Out();
    }
}


//覆膜模块
void NewMainWindow::LamModChangedEvent()
{
    qDebug()<<"LamModChangedEvent";
    QtConcurrent::run(this,&NewMainWindow::LamLongSlideCardInFun);

}
//覆膜轨道进卡清洁，打印后轨道出卡
void NewMainWindow::LamLongSlideCardInFun()
{
    if(syncLamCleanSlideCardIn==true)
    {
        return;
    }
    syncLamCleanSlideCardIn=true;


    if(isUsePrintMod3)
    {
        //        if(lamMod->currentFrontCacheCardStatus== LamMod::NoCard
        //                && lamMod->currentFrontCacheStatus==LamMod::Idle
        //                && printMod3->currentShortSildeCardStatus==PrintMod::ShortHaveCard
        //                && printMod3->currentShortSildeStatus==PrintMod::Idle)
        //        {
        //            qDebug()<<"LamLongSlideCardInFun";
        //            lamMod->CleanSlide();
        //            printMod3->Silde2Out();
        //        }
    }
    else
    {
        if(isUsePrintMod2)//启用打印机构2
        {
            //打印机构2
            if(lamMod->currentLongSildeStatus==LamMod::LongIdle
                    && lamMod->currentLongSilde2Status==LamMod::Long2Idle
                    && lamMod->currentLongSilde2CardStatus==LamMod::LongSilde2NoCard
                    && lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                    && lamMod->currentFrontCacheStatus==LamMod::Idle
                    && printMod2->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                    && printMod2->currentShortSildeStatus==PrintMod::Idle)
            {
                qDebug()<<"LamLongSlideCardInFun2";
                lamMod->CleanSlide();
                printMod2->Silde2Out();
            }
            else
            {
                if(lamMod->currentLongSildeStatus==LamMod::LongIdle
                        && lamMod->currentLongSilde2Status==LamMod::Long2Idle
                        && lamMod->currentLongSilde2CardStatus==LamMod::LongSilde2NoCard
                        && lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                        && lamMod->currentFrontCacheStatus==LamMod::Idle
                        && printMod2->currentLongSildeStatus==PrintMod::Idle
                        && printMod1->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                        && printMod1->currentShortSildeStatus==PrintMod::Idle)
                {
                    qDebug()<<"LamLongSlideCardInFun1";
                    printMod2->LongSildePass();//打印机构2，长轨道过卡
                    lamMod->CleanSlide();
                    printMod1->Silde2Out();
                }
            }
        }
        else
        {
            if(lamMod->currentLongSilde2Status==LamMod::Long2Idle
                    && lamMod->currentLongSilde2CardStatus==LamMod::LongSilde2NoCard
                    && lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                    && lamMod->currentFrontCacheStatus==LamMod::Idle
                    && printMod2->currentLongSildeStatus==PrintMod::Idle
                    && printMod1->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                    && printMod1->currentShortSildeStatus==PrintMod::Idle)
            {
                qDebug()<<"LamLongSlideCardInFun";
                lamMod->CleanSlide();
                printMod2->LongSildePass();//打印机构2，长轨道过卡
                printMod1->Silde2Out();
            }
        }
    }
    syncLamCleanSlideCardIn=false;
}


//分拣模块
void NewMainWindow::SortModChangedEvent()
{
    QtConcurrent::run(this,&NewMainWindow::LamLongSlide2CardOutFun);
    QtConcurrent::run(this,&NewMainWindow::SortAdjustCardOutFun);
    QtConcurrent::run(this,&NewMainWindow::SortCardOutFun);
}
//矫正进卡
void NewMainWindow::LamLongSlide2CardOutFun()
{
    if(lamMod->currentLongSilde2CardStatus== LamMod::LongSilde2HaveCard
            && lamMod->currentLongSilde2Status==LamMod::Long2Idle
            && sortMod->currentAdjustCardStatus==SortMod::NoCard
            && sortMod->currentAdjustPosStatus==SortMod::Idle)
    {
        qDebug()<<"LamLongSlide2CardOutFun";
        sortMod->AdjustCardIn();
        lamMod->LongSlide2Out();
    }
}
//矫正出卡，核验进卡,由于不能控制CIS需要手动把卡从CIS里推出来
void NewMainWindow::SortAdjustCardOutFun()
{
    if(sortMod->currentVerifyCardStatus== SortMod::VerifyNoCard
            && sortMod->currentVerifyPosStatus==SortMod::VerifyIdle
            && sortMod->currentAdjustCardStatus==SortMod::HaveCard
            && sortMod->currentAdjustPosStatus==SortMod::Idle)
        //&& sortMod->currentPhotoCardStatus==SortMod::PhotoNoCard
        //&& sortMod->currentPhotoStatus==SortMod::PhotoIdle
    {
        qDebug()<<"SortAdjustCardOutFun";
        //矫正出卡
        sortMod->AdjustCardOut();
        CommHelper::Instance()->sleepme(3000);//手动把卡从CIS里推出来
        sortMod->VerifyCardIn();
    }
}
//分拣出卡
void NewMainWindow::SortCardOutFun()
{
    if(sortMod->currentVerifyCardStatus== SortMod::VerifyHaveCard
            && sortMod->currentVerifyPosStatus==SortMod::VerifyIdle
            && sortMod->currentSortPosStatus==SortMod::SortIdle
            )
    {
        qDebug()<<"SortCardOutFun";
        sortMod->SlotCardOut(soltIndex);
    }
}

//TODO 核验工位进卡，需要替换 CIS设备 为摄像头机构
void NewMainWindow::SortCheckCardInFun()
{
    if(sortMod->currentVerifyCardStatus== SortMod::VerifyNoCard
            && sortMod->currentVerifyPosStatus==SortMod::VerifyIdle
            && sortMod->currentPhotoCardStatus==SortMod::PhotoHaveCard
            && sortMod->currentPhotoStatus==SortMod::PhotoIdle)
    {
        qDebug()<<"VerifyCardIn";
        sortMod->VerifyCardIn();
    }
}
///////////////======连续走卡=======////////////////////////

void NewMainWindow::on_pushButton_GetStatus_clicked()
{
    QtConcurrent::run(this,&NewMainWindow::Printer1CardInFun);
    R600Status status;
    printer1->GetStatus(status);
    qDebug()<<"PrinterCardInFun"<<"status"<<status.MainStatus;

}


