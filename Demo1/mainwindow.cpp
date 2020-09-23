#include "mainwindow.h"
#include "ui_mainwindow.h"
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

enum Excep
{
    EXCEP_ONE,
    EXCEP_TWO
};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitEquip()
{
    dicPrintModChecked["1"]=false;
    dicPrintModChecked["2"]=false;
    dicPrintModChecked["3"]=false;

    //读取配置文件获取设备配置信息
    //AppInit::Instance()->domparser->printAllMembers();//打印设备列表
    int maxEquip= AppInit::Instance()->domparser->m_deviceinfolist.size();//总数量，设置圆环的百分比
    ui->roundProgressBar_DeviceCheck->setRange(0, maxEquip);
    ui->roundProgressBar_DeviceCheck->setValue(21);
    ui->RoundBar_Slot1->setValue(100);

    //从配置文件获取设备参数
    for (const DeviceInfoModel::DeviceInfo& device : AppInit::Instance()->domparser->m_deviceinfolist)
    {
        if(device.DeviceType=="SendCardModule")
        {
            sendMod=new SendMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sendMod,&SendMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(sendMod,&SendMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="1")
        {
            printMod1=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod1,&PrintMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(printMod1,&PrintMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="2")
        {
            printMod2=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod2,&PrintMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(printMod2,&PrintMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="3")
        {
            printMod3=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod3,&PrintMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(printMod3,&PrintMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="ErasableLaminatinModule")
        {
            lamMod=new LamMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(lamMod,&LamMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(lamMod,&LamMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }
        else if(device.DeviceType=="SortingModule")
        {
            sortMod=new SortMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sortMod,&SortMod::OnReceiveMsg,this,&MainWindow::OnRefresh);
            QObject::connect(sortMod,&SortMod::OnSendMsg,this,&MainWindow::OnRefreshSend);
        }

        else
        {
            //TODO 未完

        }
    }
}

void MainWindow::InitForm()
{
    //======状态栏======
    statusLayout = new QHBoxLayout;
    statusLayout->setSpacing(0);
    statusLayout->setMargin(0);
    QLabel *per1 = new QLabel("系统时间:", this);
    QLabel *per2 = new QLabel("2020/05/08 11:14", this);
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
    createTitle();
    //生成标题栏的最大最小化等按钮
    createTitleMenu();
    //连接信号槽
    connect(title_closeBtn,&QPushButton::clicked,this,&MainWindow::title_closeBtn_clicked);
    connect(title_maxBtn,&QPushButton::clicked,this,&MainWindow::title_maxBtn_clicked);
    connect(title_minBtn,&QPushButton::clicked,this,&MainWindow::title_minBtn_clicked);

    FlatUI::Instance()->setPushButtonQss(ui->pushButton_AllInit, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Start);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Pause, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Stop, 5, 8, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    //QPixmap icon1(":/image/main_config.png");
    //ui->pushButton_Para->setIcon(icon1);
    ui->widget_img->setStyleSheet("border-image: url(:/image/img.png);");
}

//初始化卡槽样式
void MainWindow::InitSlot()
{
    //圆环，设备自检百分比
    ui->roundProgressBar_DeviceCheck->setDecimals(0);
    ui->roundProgressBar_DeviceCheck->setBarStyle(QRoundProgressBar::StyleLine);
    ui->roundProgressBar_DeviceCheck->setOutlinePenWidth(28);//外环的宽度
    ui->roundProgressBar_DeviceCheck->setDataPenWidth(25);//内环的宽度

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

    //打印耗材用量默认值
    ui->widget_Battery_New->setDefault(0);
}

void MainWindow::createTitle()
{
    //设置标题栏图标
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

void MainWindow::createTitleMenu()//创建标题栏菜单内容
{
    //创建语言切换菜单
    langue_menu = new QMenu(tr("Langue"));
    setChinese = new QAction(tr("Chinese"),this);
    setChinese->setIcon(QIcon(":/image/CETeam/china_32.png"));
    setChinese->setCheckable(true);
    setChinese->setChecked(true);
    setEnglish = new QAction(tr("English"),this);
    setEnglish->setIcon(QIcon(":/image/CETeam/english_32.png"));
    setEnglish->setCheckable(true);
    langue_menu->addAction(setChinese);
    langue_menu->addAction(setEnglish);
    langueGroup = new QActionGroup(this);
    langueGroup->addAction(setEnglish);
    langueGroup->addAction(setChinese);

    //创建主题切换菜单
    theme_menu = new QMenu(tr("Theme"));
    setBlue = new QAction(tr("blue"),this);
    setBlue->setCheckable(true);
    setBlue->setChecked(true);
    setBlack = new QAction(tr("black"),this);
    setBlack->setCheckable(true);
    theme_menu->addAction(setBlue);
    theme_menu->addAction(setBlack);
    themeGroup = new QActionGroup(this);
    themeGroup->addAction(setBlue);
    themeGroup->addAction(setBlack);

    //参数设置
    setPara = new QAction(tr("SetPara"),this);
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
    //关联换肤和切换语言功能
    connect(langueGroup,&QActionGroup::triggered,this,&MainWindow::changeLangue);
    connect(themeGroup,&QActionGroup::triggered,this,&MainWindow::changeTheme);

    connect(setPara,&QAction::triggered,this,&MainWindow::funcParamter);
    connect(setNav,&QAction::triggered,this,&MainWindow::funcNav);
    connect(setConsumables,&QAction::triggered,this,&MainWindow::funcConsumables);


}

void MainWindow::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 ="+HexString);
    ui ->textEdit ->append(ModType+" 机构返回数据 ="+HexString);//追加到编辑区中
    if(ModType=="SendMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(8,2)=="00")
        {
            sendCardModChecked=true;
            ui ->textEdit ->append("进卡机构初始化成功");
            ui->groupBox_SendMod->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 =" <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            //QStringList returnValue= CommHelper::Instance()->HexStringToBytes("AA55700456010802D6");
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            //从第５位，开始是数据
            //qDebug()<<"returnValue.length() = "<<returnValue.length();
            //qDebug()<<returnValue;
            //CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));

            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            sendMod->SetCurrentStatus(statusList);

        }
    }
    else if(ModType=="PrintMod")
    {
        QString number= QString::number(c);

        if(HexString.mid(4,2)=="AA" && HexString.mid(8,2)=="00")
        {
            dicPrintModChecked[number]=true;
            ui ->textEdit ->append("打印机构初始化成功");
            if(number=="1")
            {
                ui->groupBox_PrintMod1->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="2")
            {
                // ui->groupBox_PrintMod2->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="3")
            {
                // ui->groupBox_PrintMod3->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }

            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 =" <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);

        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            //CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
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
        }
    }
    else if(ModType=="LamMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(8,2)=="00")
        {
            lamModChecked=true;
            ui ->textEdit ->append("覆膜机构初始化成功");
            ui->groupBox_Lam->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 =" <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            //CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            lamMod->SetCurrentStatus(statusList);
        }
    }
    else if(ModType=="SortMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(8,2)=="00")
        {
            sortModChecked=true;
            ui ->textEdit ->append("分拣机构初始化成功");
            ui->groupBox_Sort->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 =" <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            //CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            sortMod->SetCurrentStatus(statusList);
        }
    }
    //TODO　判断传感器状态执行操作
    ModChange(ModType);
}

void MainWindow::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送数据 ="+HexString);
    ui ->textEdit_Send ->append(ModType+" 机构发送数据 ="+HexString);
}

void throwFun()
{
    throw EXCEP_TWO;
}

void MainWindow::title_closeBtn_clicked()
{
    this->close();//退出程序
}

void MainWindow::title_minBtn_clicked()
{
    this->showMinimized();//最小化
}

void MainWindow::title_maxBtn_clicked()
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

void MainWindow::retranslateUI()//切换语言后刷新界面
{
    langue_menu->setTitle(tr("Langue"));
    setChinese->setText(tr("Chinese"));
    setEnglish->setText(tr("English"));
    title_name->setText(tr("通行证制证程序"));
    theme_menu->setTitle(tr("Theme"));
    setBlue->setText(tr("blue"));
    setBlack->setText(tr("black"));
}

void MainWindow::changeLangue()//切换语言
{
    if(setChinese->isChecked()){//判断选中了哪个语言
        translator->load(":/langue/zh_cn.qm");//加载翻译文件
        qApp->installTranslator(translator);//安装翻译文件

        //刷新界面,因为没有Ui文件，所以要手动实现刷新(类似:setBlue->setText(tr("blue"));如果有使用Ui文件只需要调用ui->retranslateUi(this)即可
        ui->retranslateUi(this);
        retranslateUI();
    }else if(setEnglish->isChecked()){
        translator->load(":/langue/lang_en.qm");//加载翻译文件
        qApp->installTranslator(translator);//安装翻译文件

        //刷新界面,因为没有Ui文件，所以要手动实现刷新(类似:setBlue->setText(tr("blue"));重新执行一次赋值),如果有使用Ui文件只需要调用ui->retranslateUi(this)即可
        ui->retranslateUi(this);
        retranslateUI();
    }
}

void MainWindow::changeTheme()//切换主题
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

void MainWindow::funcParamter()//设置参数
{
    dialog=new ParaWindow(this);
    //dialog->setModal(false);//非模态
    //dialog->setModal(true);//模态，只能移动弹出的窗口，后面的窗口不能点击
    dialog->show();
}

void MainWindow::funcNav()//测试导航
{
    UIDemo08 *frm=new UIDemo08(this);
    //frm->setModel(false);
    frm->show();
}

void MainWindow::funcConsumables()//测试耗材
{
    ui->widget_Battery_New->setValue(0);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e)//事件过滤器
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

void MainWindow::mouseMoveEvent(QMouseEvent *e)//处理鼠标移动事件
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

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e)
    isMousePressed = false;//鼠标点击置false
}
//发卡器
void MainWindow::on_pushButton_SendCardInit_clicked()
{
    qDebug()<<"发卡器初始化";
}
//发卡器发卡
void MainWindow::on_pushButton_SendCard_clicked()
{

}

//初始化进卡机构
void MainWindow::on_pushButton_SmInit_clicked()
{
    try {
        if (sendMod==NULL)
        {
            qDebug()<<"对象为空";
            return;
        }
        sendMod->InitDevice();
    }
    catch(Excep ex)
    {
        std::cout << "输入不是整数\n";
    }
}

void MainWindow::on_pushButton_SmFlipin_clicked()
{
    try
    {
        sendMod->FlipCardInFun();
    }
    catch(Excep ex)
    {
        std::cout << "输入不是整数\n";
    }
}

void MainWindow::on_pushButton_SmFlipout_clicked()
{
    sendMod->FlipCardOutFun();
}

void MainWindow::on_pushButton_SmCleanIn_clicked()
{
    sendMod->CleanCardInFun();
}

void MainWindow::on_pushButton_SmCleanOut_clicked()
{
    sendMod->CleanCardOutFun();
}

void MainWindow::on_pushButton_SmCleanCache_clicked()
{
    sendMod->CardCacheOutFun();
}

//打印机构1
void MainWindow::on_pushButton_PrintMod1_clicked()
{
    if (printMod1==NULL)
    {
        qDebug()<<"对象为空";
        return;
    }
    printMod1->InitDevice();
}
//覆膜机构
void MainWindow::on_pushButton_LamModInit_clicked()
{
    if (lamMod==NULL)
    {
        qDebug()<<"对象为空";
        return;
    }
    lamMod->InitDevice();

}
//分拣机构
void MainWindow::on_pushButton_SortModInit_clicked()
{
    if (sortMod==NULL)
    {
        qDebug()<<"对象为空";
        return;
    }
    sortMod->InitDevice();
}

//机构传感器变化触发操作
void MainWindow::ModChange(QString modeType)
{
    //    QMetaEnum metaEnum = QMetaEnum::fromType<SendMod::ModStatus>();
    //    QMetaEnum metaEnumC1 = QMetaEnum::fromType<SendMod::CardStatus>();
    //    qDebug()<< metaEnum.valueToKey(sendMod->currentSendCardModStatus);
    //    qDebug()<< metaEnumC1.valueToKey(sendMod->currentRotationFlipCardStatus);
    if(modeType=="SendMod")  {
        if(currentStatus==ApplicationStatus::Startup)
        {
            while(sendMod->currentRotationFlipStatus==SendMod::Idle &&sendMod->currentRotationFlipCardStatus==SendMod::HaveCard)
            {
                CommHelper::Instance()->sleepme(1000);
                sendMod->FlipCardOutFun();
            }


        }
    }
}

//all init
void MainWindow::on_pushButton_AllInit_clicked()
{
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
    printMod3->InitDevice();
    while(!dicPrintModChecked["3"])
    {
        CommHelper::Instance()->sleepme(1000);
    }
    lamMod->InitDevice();
    while(!lamModChecked)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    sortMod->InitDevice();
    CommHelper::Instance()->sleepme(5000);
    sortMod->LightControl(4,0);
    currentStatus=ApplicationStatus::InitFinish;

}
//start
void MainWindow::on_pushButton_Start_clicked()
{
    ui->lightButton1->setBgColor(QColor(24, 189, 155));
    if(currentStatus==ApplicationStatus::InitFinish)
    {
        currentStatus=ApplicationStatus::Startup;
    }
    else
    {
        QMessageBox::information(this,tr("Tip"),tr("Not InitDevice!"));
    }
}
//pause
void MainWindow::on_pushButton_Pause_clicked()
{
    ui->lightButton1->setBgColor(QColor(255, 107, 107));
}

void MainWindow::on_pushButton_Stop_clicked()
{
    if (!(QMessageBox::information(this,tr("exit tip"),tr("Do you really want exit ?"),tr("Yes"),tr("No"))))
    {
        QApplication* app;
        //app->quit();
        app->exit(0);
    }
}


void MainWindow::on_pushButton_SendCardInit_2_clicked()
{

}

void MainWindow::on_pushButton_ConnectDB_clicked()
{

}
