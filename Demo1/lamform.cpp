#include "lamform.h"
#include "ui_lamform.h"
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


LamForm::LamForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LamForm)
{
    ui->setupUi(this);
    this->initForm();
    this->initEquip();
}

LamForm::~LamForm()
{
    delete ui;
}
void LamForm::initForm()
{
    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:#ffffff;}"));
    this->setStyleSheet(qss.join(""));
}

void LamForm::initEquip()
{
    //读取配置文件获取设备配置信息
    int maxEquip= AppInit::Instance()->domparser->m_deviceinfolist.size();//总数量，设置圆环的百分比

    //从配置文件获取设备参数
    for (const DeviceInfoModel::DeviceInfo& device : AppInit::Instance()->domparser->m_deviceinfolist)
    {
        if(device.DeviceType=="ErasableLaminatinModule")
        {
            lamMod=new LamMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(lamMod,&LamMod::OnSendMsg,this,&LamForm::OnRefreshSend);
            QObject::connect(lamMod,&LamMod::OnReceiveMsg,this,&LamForm::OnRefresh);
        }
    }
}
void LamForm::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 = "+HexString);
    ui ->textEdit ->append(ModType+" 机构返回数据 = "+HexString);//追加到编辑区中

    if(ModType=="LamMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            lamModChecked=true;
            ui ->textEdit ->append("覆膜机构初始化成功");
            ui->groupBox_Lam->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            //圆环百分比
            //int current=ui->roundProgressBar_DeviceCheck->value();
            //qDebug()<<"已完成检测设备数";
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
            LamModChangedEvent();
        }
    }
}

void LamForm::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送指令 ="+HexString);
    ui ->textEdit_Send ->append(ModType+" 机构发送指令 ="+HexString);
}
//覆膜模块
void LamForm::LamModChangedEvent()
{
    qDebug()<<"LamModChangedEvent";
    // QtConcurrent::run(this,&CleanForm::LamLongSlideCardInFun);

}

void LamForm::on_pushButton_LamModInit_clicked()
{
    lamMod->InitDevice();
}

void LamForm::on_pushButton_LamCleanSlide_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->CleanSlide();
    }
}

void LamForm::on_pushButton_LamCacheCardIn_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->FrontCacheCardIn();
    }
}

void LamForm::on_pushButton_LamCacheCardOut_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->LongSlideCardIn();
    }
}

void LamForm::on_pushButton_LamCleanCardIn_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->CleanCardIn();
    }
}

void LamForm::on_pushButton_LamCleanCardOut_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->LamCardIn();
    }
}

void LamForm::on_pushButton_LamShortSlide2In_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->LongSlide2In();
    }
}

void LamForm::on_pushButton_LamShortSlideOut_clicked()
{
    if(lamModChecked==true)
    {
        lamMod->LongSlide2Out();
    }
}
