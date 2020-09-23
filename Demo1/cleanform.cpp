#include "cleanform.h"
#include "ui_cleanform.h"
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"
#include "roundprogressbartest.h"
#include "QMovie"
#include "flatui.h"
#include "tool/commhelper.h"
#include "PrintMod/printmod.h"
#include "tool/appinit.h"
#include "deviceinfo.h"
#include "SendMod/sendmod.h"
#include "QMessageBox"
#include "QtConcurrent"

CleanForm::CleanForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CleanForm)
{
    ui->setupUi(this);
    this->initForm();
    this->InitEquip();
    ui->roundProgressBar_DeviceCheck->setValue(5);

    setWindowIcon(QIcon(":/image/CETeam/lg.ico"));
    this->setWindowTitle("清洁程序");
}

CleanForm::~CleanForm()
{
    delete ui;
}

void CleanForm::initForm()
{
    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:#ffffff;}"));
    this->setStyleSheet(qss.join(""));

    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    QPalette p1;//字体颜色
    p1.setBrush(QPalette::AlternateBase, Qt::gray);//内圆背景色
    p1.setColor(QPalette::Text, Qt::white);
    QPalette p2(p1);
    //p2.setBrush(QPalette::Base, Qt::red);
    p2.setColor(QPalette::Text, Qt::blue);
    p2.setColor(QPalette::Highlight, Qt::green); //已完成覆盖的圆环颜色
    //p2.setColor(QPalette::Shadow, Qt::yellow);
    //p2.setColor(QPalette::Window, Qt::black);//圆环之外的颜色
    //ui->roundProgressBar_DeviceCheck->setFormat("%v");
    ui->roundProgressBar_DeviceCheck->setDataColors(gradientPoints);
    ui->roundProgressBar_DeviceCheck->setDecimals(0);
    ui->roundProgressBar_DeviceCheck->setNullPosition(QRoundProgressBar::PositionLeft);
    ui->roundProgressBar_DeviceCheck->setPalette(p2);

    //ui->widget->setStyleSheet("background:#ff11ff;");//窗口设置背景色后,圆环的内圆背景色和圆环外部颜色设置失效
    //ui->widget->setStyleSheet("border-image:url(:/image/main.jpg);");

    FlatUI::Instance()->setPushButtonQss(ui->pushButton_AllInit, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Start);
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Pause, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Stop, 5, 8, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");
}

void CleanForm::InitEquip()
{
    dicPrintModChecked["1"]=false;
    dicPrintModChecked["2"]=false;
    dicPrintModChecked["3"]=false;

    //读取配置文件获取设备配置信息
    int maxEquip= AppInit::Instance()->domparser->m_deviceinfolist.size();//总数量，设置圆环的百分比
    ui->roundProgressBar_DeviceCheck->setRange(0, maxEquip);
    ui->roundProgressBar_DeviceCheck->setValue(0);

    //从配置文件获取设备参数
    for (const DeviceInfoModel::DeviceInfo& device : AppInit::Instance()->domparser->m_deviceinfolist)
    {
        if(device.DeviceType=="SendCardModule")
        {
            sendMod=new SendMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            //绑定信号-槽，获取机构返回的数据
            QObject::connect(sendMod,&SendMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(sendMod,&SendMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="1")
        {
            printMod1=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod1,&PrintMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(printMod1,&PrintMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="2")
        {
            printMod2=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod2,&PrintMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(printMod2,&PrintMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else if(device.DeviceType=="PrinterModule" && device.DeviceID=="3")
        {
            printMod3=new PrintMod(QString::fromStdString(device.DeviceIP),device.DevicePort,device.DeviceID,this);
            QObject::connect(printMod3,&PrintMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(printMod3,&PrintMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else if(device.DeviceType=="ErasableLaminatinModule")
        {
            lamMod=new LamMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(lamMod,&LamMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(lamMod,&LamMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else if(device.DeviceType=="SortingModule")
        {
            sortMod=new SortMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sortMod,&SortMod::OnReceiveMsg,this,&CleanForm::OnRefresh);
            QObject::connect(sortMod,&SortMod::OnSendMsg,this,&CleanForm::OnRefreshSend);
        }
        else if(device.DeviceType=="CardSender")
        {
            //            if(cardsender==NULL)
            //            {
            //                qDebug()<<"NULL";
            //            }
            //            if(cardsender==0X00)
            //            {
            //                qDebug()<<"PTR";
            //            }
            cardsender=new CardSender(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(cardsender,&CardSender::OnSendMsg,this,&CleanForm::OnRefreshSend);
            QObject::connect(cardsender,&CardSender::OnReceiveMsg,this,&CleanForm::OnRefresh);
        }
        else
        {
            //TODO 未完

        }
    }
}

void CleanForm::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 = "+HexString);
    ui ->textEdit ->append(ModType+" 机构返回数据 = "+HexString);//追加到编辑区中

    if(ModType=="SendMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            sendCardModChecked=true;
            ui ->textEdit ->append("进卡机构初始化成功");
            ui->groupBox_SendMod->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 = " <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
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
            ui ->textEdit ->append("打印机构初始化成功");
            if(number=="1")
            {
                ui->groupBox_PrintMod1->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="2")
            {
                ui->groupBox_PrintMod2->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            else if(number=="3")
            {
                ui->groupBox_PrintMod3->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            }
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 = " <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
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
                PrintModChangedEvent();
            }
        }
    }
    else if(ModType=="LamMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            lamModChecked=true;
            ui ->textEdit ->append("覆膜机构初始化成功");
            ui->groupBox_Lam->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 = " <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
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
            ui ->textEdit ->append("分拣机构初始化成功");
            ui->groupBox_Sort->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            int current=ui->roundProgressBar_DeviceCheck->value();
            qDebug()<<"已完成检测设备数 = " <<current+1;
            ui->roundProgressBar_DeviceCheck->setValue(current+1);
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
}

void CleanForm::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送指令 ="+HexString);
    ui ->textEdit_Send ->append(ModType+" 机构发送指令 ="+HexString);
}

void CleanForm::on_pushButton_Stop_clicked()
{
    //close();
}

//初始化
void CleanForm::on_pushButton_AllInit_clicked()
{
    //发卡器初始化
    int ret = cardsender->InitDevice();
    if(ret==0)
    {
        ui ->textEdit ->append("发卡器初始化成功");
        ui->groupBox_CardSender->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
        //圆环百分比
        int current=ui->roundProgressBar_DeviceCheck->value();
        qDebug()<<"已完成检测设备数 = " <<current+1;
        ui->roundProgressBar_DeviceCheck->setValue(current+1);
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
    if(ui->checkBox_3->checkState()==Qt::Checked)
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
    sortMod->InitDevice();
    CommHelper::Instance()->sleepme(5000);
    sortMod->LightControl(4,0);

    initFinish=true;
}

//开始清洁
void CleanForm::on_pushButton_Start_clicked()
{
    if(!initFinish)
    {
        QMessageBox::information(this, "Title", "未初始化");
        return;
    }
    ui->progressBar_SEND->setValue(0);
    ui->progressBar_P1->setValue(0);
    ui->progressBar_P2->setValue(0);
    ui->progressBar_P3->setValue(0);
    ui->progressBar_LAM->setValue(0);
    ui->progressBar_SORT->setValue(0);

    cardsender->RequestStatus();
    while(cardsender->currentCardStatus==CardSender::NoCard)
    {
        ui ->textEdit_Send ->append("发卡器无卡");
        CommHelper::Instance()->sleepme(1000);
    }

    //qDebug()<<"FlipCardInFun";
    sendMod->FlipCardInFun();
    CommHelper::Instance()->sleepme(1000);
    //发卡器发卡
    cardsender->SendCard();

    cardsender->cardsenderdata=this->data_index;//工位数据
    this->data_index++;

    while(sendMod->currentRotationFlipCardStatus!=SendMod::HaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    sendMod->flipdata=cardsender->cardsenderdata;
    qDebug()<<"sendMod->flipdata ="<<sendMod->flipdata;

    //qDebug()<<"FlipCardOutFun";
    sendMod->FlipCardOutFun();
    CommHelper::Instance()->sleepme(4000);

    sendMod->CleanCardInFun();
    while(sendMod->currentCleanCardStatus!=SendMod::CleanHaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }

    sendMod->CleanCardOutFun();

    while(sendMod->currentCacheCardStatus!=SendMod::CacheHaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }

    printMod1->CleanSlide();
    CommHelper::Instance()->sleepme(1000);
    sendMod->CardCacheOutFun();

    while(printMod1->currentShortSildeCardStatus!=PrintMod::ShortSildeCardStatus::ShortHaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    printMod2->CleanSlide();
    printMod1->Silde2Out();

    while(printMod2->currentShortSildeCardStatus!=PrintMod::ShortSildeCardStatus::ShortHaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }

    if(ui->checkBox_3->checkState()==Qt::Checked)
    {
        printMod3->CleanSlide();
        printMod2->Silde2Out();

        while(printMod3->currentShortSildeCardStatus!=PrintMod::ShortSildeCardStatus::ShortHaveCard)
        {
            CommHelper::Instance()->sleepme(1000);
        }
        //覆膜机构清洁轨道
        lamMod->CleanSlide();
        printMod3->Silde2Out();
    }
    else
    {
        //覆膜机构清洁轨道
        lamMod->CleanSlide();
        printMod2->Silde2Out();
    }

    //状态判断有问题
    while(lamMod->currentLongSilde2CardStatus!=LamMod::LongSilde2CardStatus::LongSilde2HaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    sortMod->AdjustCardIn();
    //矫正进卡，覆膜后轨道出卡
    lamMod->LongSlide2Out();

    //
    while(sortMod->currentAdjustCardStatus!=SortMod::AdjustCardStatus::HaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    //矫正出卡
    sortMod->AdjustCardOut();
    CommHelper::Instance()->sleepme(3000);

    sortMod->VerifyCardIn();

    while(sortMod->currentVerifyCardStatus!=SortMod::VerifyCardStatus::VerifyHaveCard)
    {
        CommHelper::Instance()->sleepme(1000);
    }
    sortMod->SlotCardOut(1);
}

//覆膜初始化
void CleanForm::on_pushButton_SortModInit_clicked()
{
    sortMod->InitDevice();
}

//打印1轨道清洁
void CleanForm::on_pushButton_PM1_CLeanSlide_clicked()
{
    printMod1->CleanSlide();
}

//覆膜机构初始化
void CleanForm::on_pushButton_LamModInit_clicked()
{
    lamMod->InitDevice();
}
//覆膜机构轨道清洁
void CleanForm::on_pushButton_LamCleanSlide_clicked()
{
    qDebug()<<"覆膜机构轨道清洁";
    lamMod->CleanSlide();
}
//覆膜机构轨道2出卡
void CleanForm::on_pushButton_LamOut_clicked()
{
    lamMod->LongSlide2Out();
}
//发卡器初始化
void CleanForm::on_pushButton_CardSenderInit_clicked()
{
    int ret = cardsender->InitDevice();
    if(ret == 0)
    {
        ui->groupBox_CardSender->setStyleSheet("QGroupBox{background:green}"); //设定背景颜色为绿色
    }
}

//发卡器发卡
void CleanForm::on_pushButton_CardSender_clicked()
{
    int ret = cardsender->SendCard();
    if(ret==0)
    {
        ui ->textEdit ->append("发卡成功");
    }
}
//发卡器查询传感器状态
void CleanForm::on_pushButton_CardSenderRequest_clicked()
{
    unsigned char * ReadData;
    int length = 0;
    int result = cardsender->RequestStatus(1,5000,ReadData,length);
}

//进卡机构初始化
void CleanForm::on_pushButton_SmInit_clicked()
{
    sendMod->InitDevice();
}
//进卡
void CleanForm::on_pushButton_SmFlipin_clicked()
{
    sendMod->FlipCardInFun();

    QTime t;
    t.start();
    while(t.elapsed()<1000);
    //发卡器发卡
    cardsender->SendCard();
}
//出卡
void CleanForm::on_pushButton_SmFlipout_clicked()
{
    sendMod->FlipCardOutFun();
}
//暂停
void CleanForm::on_pushButton_Pause_clicked()
{
    if(ui->checkBox_1->checkState()==Qt::Checked)
    {
        //Unchecked
        qDebug()<<"Checked";

    }

}
//连续走卡
void CleanForm::on_pushButton_StartWhile_clicked()
{
    forloop = true;
}
//打印机构1初始化
void CleanForm::on_pushButton_PrintMod1_clicked()
{
    printMod1->InitDevice();
}
void CleanForm::on_pushButton_PrintMod2_clicked()
{
    printMod2->InitDevice();
}
void CleanForm::on_pushButton_PrintMod3_clicked()
{
    printMod3->InitDevice();
}
///////////////======连续走卡=======////////////////////////
//进卡模块
void CleanForm::SendModChangedEvent()
{
    if(flipInFinish==true)
    {
        return;
    }
    flipInFinish=true;
    qDebug()<<"SendModChangedEvent";
    QtConcurrent::run(this,&CleanForm::FlipCardInFun);//多线程执行死循环启动
    QtConcurrent::run(this,&CleanForm::FlipCardOutFun);
    QtConcurrent::run(this,&CleanForm::CleanCardOutFun);

    //FlipCardInFun();
    //FlipCardOutFun();
    //CleanCardOutFun();

    flipInFinish=false;
}
void CleanForm::FlipCardInFun()
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
    //QMutexLocker(m_mutex).unlock();
    // m_mutex.unlock();
}
void CleanForm::FlipCardOutFun()
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
void CleanForm::CleanCardOutFun()
{
    if( sendMod->currentCleanStatus==SendMod::CleanIdle &&
            sendMod->currentCleanCardStatus==SendMod::CleanHaveCard)
    {
        qDebug()<<"CleanCardOutFun";

        sendMod->CleanCardOutFun();
    }
}

//打印模块
void CleanForm::PrintModChangedEvent()
{
    if(cacheInFinish==true)
    {
        return;
    }
    cacheInFinish=true;
    qDebug()<<"PrintModChangedEvent";
    QtConcurrent::run(this,&CleanForm::CacheCardOutFun);
    QtConcurrent::run(this,&CleanForm::PrintMod2CardOutFun);
    QtConcurrent::run(this,&CleanForm::PrintMod3CardOutFun);

    cacheInFinish=false;
}
//进卡机构缓冲出卡,打印机构1进卡
void CleanForm::CacheCardOutFun()
{
    if( sendMod->currentCacheStatus==SendMod::CacheIdle
            && sendMod->currentCacheCardStatus==SendMod::CacheHaveCard
            && printMod1->currentLongSildeStatus==PrintMod::Idle)
    {
        qDebug()<<"CacheCardOutFun";
        printMod1->CleanSlide();
        sendMod->CardCacheOutFun();
    }
}
//打印机构1出卡，打印机构2进卡
void CleanForm::PrintMod2CardOutFun()
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
void CleanForm::PrintMod3CardOutFun()
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
void CleanForm::LamModChangedEvent()
{
    qDebug()<<"LamModChangedEvent";
    QtConcurrent::run(this,&CleanForm::LamLongSlideCardInFun);

}
//轨道1进卡清洁，打印3后轨道出卡
void CleanForm::LamLongSlideCardInFun()
{
    if(ui->checkBox_3->checkState()==Qt::Checked)
    {
        if(lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                && lamMod->currentFrontCacheStatus==LamMod::Idle
                && printMod3->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                && printMod3->currentShortSildeStatus==PrintMod::Idle)
        {
            qDebug()<<"LamLongSlideCardInFun";
            lamMod->CleanSlide();
            printMod3->Silde2Out();
        }
    }
    else
    {
        if(lamMod->currentFrontCacheCardStatus== LamMod::NoCard
                && lamMod->currentFrontCacheStatus==LamMod::Idle
                && printMod2->currentShortSildeCardStatus==PrintMod::ShortHaveCard
                && printMod2->currentShortSildeStatus==PrintMod::Idle)
        {
            qDebug()<<"LamLongSlideCardInFun";
            lamMod->CleanSlide();
            printMod2->Silde2Out();
        }
    }
}

//分拣模块
void CleanForm::SortModChangedEvent()
{
    QtConcurrent::run(this,&CleanForm::LamLongSlide2CardOutFun);
    QtConcurrent::run(this,&CleanForm::SortAdjustCardOutFun);
    QtConcurrent::run(this,&CleanForm::SortCardOutFun);
}
//矫正进卡
void CleanForm::LamLongSlide2CardOutFun()
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
//矫正出卡，核验进卡
void CleanForm::SortAdjustCardOutFun()
{
    if(sortMod->currentVerifyCardStatus== SortMod::VerifyNoCard
            && sortMod->currentVerifyPosStatus==SortMod::VerifyIdle
            && sortMod->currentAdjustCardStatus==SortMod::HaveCard
            && sortMod->currentAdjustPosStatus==SortMod::Idle)
    {
        qDebug()<<"SortAdjustCardOutFun";
        //矫正出卡
        sortMod->AdjustCardOut();
        CommHelper::Instance()->sleepme(3000);
        sortMod->VerifyCardIn();
    }
}
//分拣出卡
void CleanForm::SortCardOutFun()
{
    if(sortMod->currentVerifyCardStatus== SortMod::VerifyHaveCard
            && sortMod->currentVerifyPosStatus==SortMod::VerifyIdle
            && sortMod->currentSortPosStatus==SortMod::SortIdle
            )
    {
        qDebug()<<"SortCardOutFun";
        sortMod->SlotCardOut(1);
    }
}
///////////////======连续走卡=======////////////////////////
