#include "print_rck600.h"
#include "QDebug"
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "mainwindow.h"


Print_RCK600::Print_RCK600(QObject *parent) : QObject(parent)
{

}
Print_RCK600::~Print_RCK600()
{
    //delete this->client;
}
Print_RCK600::Print_RCK600(QString _ip,int _port,QString _id,QWidget *_parent,bool simu)
{
    this->ip=_ip;
    this->port=_port;
    this->id=_id;
    this->parent=_parent;
    this->isSimulated=simu;
}
bool Print_RCK600::InitDevice()
{
    try
    {
        print=new R600Printer();
        bool res= print->InitDevice(ip.toStdString().c_str());
        if(res)
        {
            print->SetSimulate(isSimulated);
            IsStart=true;
            emit OnReceiveMsg("Print","打印机初始化成功",1);//返回给UI
        }
        else
        {
            emit OnReceiveMsg("Print","打印机初始化失败",1);//返回给UI
        }
        QString strInitUTF8=QString::fromUtf8("打印机初始化 = ")+QString::number(res);
        CommHelper::Instance()->ShowLog(strInitUTF8);
        return res;

    }
    catch (...) {
        qDebug()<<"打印机初始化失败";
        return false;
    }
}

void Print_RCK600::StopDevice()
{
    bool res=print->StopDevice();

}

void Print_RCK600::PauseDevice()
{

}
//设置是否模拟打印
void Print_RCK600::SetSimulate(bool isSimulate)
{
    if(print==NULL)
    {
        return;
    }
    this->isSimulated=isSimulate;
    print->SetSimulate(isSimulate);
}

//下发打印任务
bool Print_RCK600::LoadPrintTask(QString pFImagePath, QString pBImagePath, bool isDouble)
{
    if(isSimulated)
    {
        bool res=print->LoadPrintTask(pFImagePath,pBImagePath,isDouble);
        qDebug()<<"LoadPrintTask = "<<res;
        emit OnReceiveMsg("Print","打印机下载任务"+QString::number(res),1);//返回给UI
        return res;
    }
    else
    {
        QByteArray frontImg;
        QByteArray backImg;

        QBuffer fbuffer(&frontImg);
        fbuffer.open(QIODevice::WriteOnly);
        QPixmap fimage(pFImagePath);
        fimage.save(&fbuffer,"png",0);

        if(pFImagePath.isEmpty())
        {
            qDebug()<<"正面图像不存在！ ";
            return false;
        }
        if(isDouble)
        {
            if(pBImagePath.isEmpty())
            {
                qDebug()<<"背面图像不存在！ ";
                return false;
            }
            bool res=print->LoadPrintTask(pFImagePath,pBImagePath,isDouble);
            return res;
        }
        else {
            //bool res=print->LoadPrintTask(pFImagePath,"");

            bool res=print->LoadPrintTask(pFImagePath,pBImagePath,isDouble);

            qDebug()<<"LoadPrintTask[print one] = "<<res;
            emit OnReceiveMsg("Print","打印机下载任务"+QString::number(res),1);//返回给UI
            if(!res)
            {
                qDebug()<<"GetErrorMsg ="<< print->GetErrorMsg();
            }
            return res;
        }
    }
    //QByteArray -> QString
    //QString str2 = QString(bytearry.toBase64());

    //QString -> QByteArray
    //QByteArray bytearry = QByteArray::fromBase64(str2.toLocal8Bit());
}

//进卡并打印
bool Print_RCK600::FeedCardAndPrint()
{
    bool res=print->FeedCardAndPrint();
    qDebug()<<"FeedCardAndPrint ="<<res<<",ID ="<<id;
    if(!res)
    {
        qDebug()<<print->GetErrorMsg();
    }
    emit OnReceiveMsg("Print","打印机进卡结果"+QString::number(res),1);//返回给UI
    return res;
}

//退卡
bool Print_RCK600::EjectCard()
{
    bool res=print->EjectCard();
    qDebug()<<"EjectCard ="<<res<<",ID ="<<id;
    if(!res)
    {
        qDebug()<<"EjectCard Error ="<<print->GetErrorMsg()<<",ID ="<<id;
    }
    emit OnReceiveMsg("Print","打印机出卡结果"+QString::number(res),1);//返回给UI
}
//获得打印机状态
bool Print_RCK600::GetStatus(R600Status &status)
{
    bool res = print->GetStatus(status);
    if(!res)
    {
        qDebug()<<"GetStatus Error ="<<print->GetErrorMsg()<<",ID ="<<id;
    }
}

bool Print_RCK600::PrintReset()
{
    bool res = print->PrintReset();
    if(!res)
    {
        qDebug()<<"PrintReset Error ="<<print->GetErrorMsg()<<",ID ="<<id;
    }
}

