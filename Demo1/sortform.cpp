#include "sortform.h"
#include "ui_sortform.h"
#include "QDebug"
#include "flatui.h"
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QTime"
#include "roundprogressbartest.h"
#include "QMovie"
#include "tool/commhelper.h"
#include "PrintMod/printmod.h"
#include "tool/appinit.h"
#include "deviceinfo.h"
#include "SendMod/sendmod.h"
#include "QMessageBox"
#include "QtConcurrent"

SortForm::SortForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortForm)
{
    ui->setupUi(this);
    this->initForm();
    this->initEquip();
}

SortForm::~SortForm()
{
    delete ui;
}
void SortForm::initForm()
{
    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("*{outline:0px;color:#ffffff;}"));
    this->setStyleSheet(qss.join(""));

    FlatUI::Instance()->setRadioButtonQss(ui->radioButton_1);
    FlatUI::Instance()->setRadioButtonQss(ui->radioButton_2);
    FlatUI::Instance()->setRadioButtonQss(ui->radioButton_3);
    FlatUI::Instance()->setRadioButtonQss(ui->radioButton_4);
}
void SortForm::initEquip()
{
    //从配置文件获取设备参数
    for (const DeviceInfoModel::DeviceInfo& device : AppInit::Instance()->domparser->m_deviceinfolist)
    {
        if(device.DeviceType=="SortingModule")
        {
            sortMod=new SortMod(QString::fromStdString(device.DeviceIP),device.DevicePort,this);
            QObject::connect(sortMod,&SortMod::OnReceiveMsg,this,&SortForm::OnRefresh);
            QObject::connect(sortMod,&SortMod::OnSendMsg,this,&SortForm::OnRefreshSend);
        }
    }
}
void SortForm::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 = "+HexString);
    ui ->textEdit ->append(ModType+" 机构返回数据 = "+HexString);//追加到编辑区中

    if(ModType=="SortMod")
    {
        if(HexString.mid(4,2)=="AA" && HexString.mid(10,2)=="80")
        {
            sortModChecked=true;
            ui ->textEdit ->append("分拣机构初始化成功");
            ui->groupBox_Sort->setStyleSheet("QGroupBox{background:rgb(125,255,125)}");
            qDebug()<<"已完成检测设备数";
        }
        //传感器参数
        else if(HexString.mid(4,2)=="70")
        {
            //解析传感器参数
            QStringList returnValue= CommHelper::Instance()->HexStringToBytes(HexString);
            CommHelper::Instance()->ShowLog("解析结果 = "+returnValue.join(","));
            QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
            sortMod->SetCurrentStatus(statusList);

            SortModChangedEvent();
        }
    }
}

void SortForm::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送指令 ="+HexString);
    ui ->textEdit_Send ->append(ModType+" 机构发送指令 ="+HexString);
}
//分拣模块
void SortForm::SortModChangedEvent()
{

}
void SortForm::on_pushButton_SortModInit_clicked()
{
    sortMod->InitDevice();
}

void SortForm::on_pushButton_SortMod_Light_clicked()
{
    if(sortModChecked==true)
    {
        startCheckLight = true;
        while(startCheckLight)
        {
            sortMod->LightCheck();
        }
    }
}

void SortForm::on_pushButton_SortMod_Light_Close_clicked()
{
    if(sortModChecked==true)
    {
        startCheckLight = false;
        sortMod->LightClose();
    }
}

void SortForm::on_pushButton_Sort_AdjustIn_clicked()
{
    if(sortModChecked==true)
    {
        sortMod->AdjustCardIn();
    }
}

void SortForm::on_pushButton_Sort_AdjustOut_clicked()
{
    if(sortModChecked==true)
    {
        sortMod->AdjustCardOut();
    }
}

void SortForm::on_pushButton_Sort_OCRReaderIn_clicked()
{

}
void SortForm::on_pushButton_Sort_VerifyIn_clicked()
{
    if(sortModChecked==true)
    {
        sortMod->VerifyCardIn();
    }
}

void SortForm::on_pushButton_Sort_LongOut_clicked()
{
    sortMod->SlotCardOut(1);
}




