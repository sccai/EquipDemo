#include "lammod.h"
#include "QDebug"
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "mainwindow.h"


LamMod::LamMod(QObject *parent) : QObject(parent)
{

}
LamMod::~LamMod()
{
    delete this->client;
}
LamMod::LamMod(QString _ip,int _port,QWidget *_parent)
{
    this->ip=_ip;
    this->port=_port;
    this->parent=_parent;
}
void LamMod::InitDevice()
{
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(ip), port);
    //等待连接成功
    if(!client->waitForConnected(30000))
    {
        QMessageBox::information(parent,tr("提示"),tr("Connection failed!"),QMessageBox::Ok);
        return;
    }
    IsStart=true;
    //CommHelper::Instance()->Showtime();
    //qDebug() << "Socket链接成功";
    QString strInitUTF8=QString::fromUtf8("SocketTCP链接成功");
    CommHelper::Instance()->ShowLog(strInitUTF8);
    //连接信号槽
    QObject::connect(client, &QTcpSocket::readyRead, this, &LamMod::Socket_Read_Data);

    SendMsg(START);
}

void LamMod::StopDevice()
{

}

void LamMod::PauseDevice()
{

}
//清洁轨道
void LamMod::CleanSlide()
{
    SendMsg(LAMINATIONMODCLEAN);
}
//前缓冲进卡
void LamMod::FrontCacheCardIn()
{
    SendMsg(FRONTCACHECARDIN);
}

//前轨道进卡
void LamMod::LongSlideCardIn()
{
    SendMsg(FRONTCACHETOLONGSILDE);
}

//可擦写进卡
void LamMod::EPrintCardIn()
{
    SendMsg(ERASABLEPRINTERCARDIN);
}

//可擦写出卡
void LamMod::EPrintCardOut()
{
    //SendMsg(FRONTCACHECARDIN);
}

//清洁进卡
void LamMod::CleanCardIn()
{
    SendMsg(ROTATIONCARDINANDCLEAN);
}

//覆膜机进卡
void LamMod::LamCardIn()
{
    SendMsg(LAMINATORCARDIN);
}

//长轨道２进卡
void LamMod::LongSlide2In()
{
    SendMsg(LONGSILDE2IN);
}

//长轨道２出卡
void LamMod::LongSlide2Out()
{
    SendMsg(LONGSILDE2OUT);
}
void LamMod::SendMsg(QString HexString)//HexString="AA 55 02 01"
{
    QStringList lst =HexString.split(' ',QString::SkipEmptyParts);
    int len=lst.count();
    bool ok;
    QByteArray array;
    array.resize(5);
    QByteArray byte_head;
    byte_head.resize(6);

    for (int j=0; j<lst.count(); j++)
    {
        int byte1=lst.at(j).toInt(&ok,16);
        array[j]=byte1;
        byte_head[j]=byte1;
    }
    if(msn>255)
    {
        msn=1;
    }
    QString strmsn = QString("%1").arg(msn, 2, 10, QChar('0'));
    int byte5=strmsn.toInt(&ok,16);//msn

    //qDebug() << "MSN = "<< msn;
    array[4]=byte5;
    byte_head[4]=byte5;
    msn=msn+1;
    //异或
    int tempxor = 0;
    for (int i = 0; i < 5; i=i+1)
    {
        tempxor = (int)(tempxor ^ array[i]);
    }
    //std::cout<<"tempxor=";
    //std::cout<<tempxor<< '\n';
    byte_head[5]=tempxor;

    //qDebug() << "=======SendMsg发送指令=======";
    QString revStr=CommHelper::Instance()-> ByteArrayToHexString(byte_head);//字节数组转换为QString
    //CommHelper::Instance()->ShowLog("SendMsg发送指令: = "+revStr);
    emit OnSendMsg("LamMod",revStr,0);//返回给UI
    int sendRe = client->write(byte_head);
    client->flush();//冲掉缓存，不然无法读取服务端发送的数据

    if(sendRe == -1)
    {
        qDebug() << "=======write -1 =======";
        QMessageBox::information(parent, "QT网络通信", "向服务端发送数据失败！");
    }
}

void LamMod::Socket_Read_Data()
{
    if(IsStart)
    {
        CommHelper::Instance()->ShowLog("=======socket_Read_Data=======");
        QByteArray arrayRead = client->readAll();
        int le = arrayRead.length();
        if(!arrayRead.isEmpty())
        {
            //qDebug() << "数据长度 = "<< le;
            QString receivestr=CommHelper::Instance()->ByteArrayToHexString(arrayRead);
            //CommHelper::Instance()->ShowLog("数据 = "+receivestr);
            //删除所有空格
            QString receiveNotSpace = receivestr.remove(QRegExp("\\s"));
            //AA55 split
            QStringList lst = receiveNotSpace.split("AA55",QString::SkipEmptyParts);
            for (int j=0; j<lst.count(); j++)
            {
                //qDebug() << "AA55"+lst.at(j);
                emit OnReceiveMsg("LamMod","AA55"+lst.at(j),100);//返回给UI
            }
        }
    }
}

//根据数据设置传感器状态
void LamMod::SetCurrentStatus(QStringList &ba)
{
    QString secondInstruction = ba.at(1);
    QString thirdInstruction = ba.at(2);
    if(secondInstruction[7] == '1')
    {
        this->currentErasableLaminationModStatus=ModStatus::Startup;
    }
    else
    {
        this->currentErasableLaminationModStatus=ModStatus::Closed;
    }
    if(secondInstruction[6] == '1')
    {
        this->currentFrontCacheCardStatus=FrontCacheCardStatus::HaveCard;
    }
    else
    {
        this->currentFrontCacheCardStatus=FrontCacheCardStatus::NoCard;
    }
    if(secondInstruction[5] == '1')
    {
        this->currentFrontCacheStatus=FrontCacheStatus::Busy;
    }
    else
    {
        this->currentFrontCacheStatus=FrontCacheStatus::Idle;
    }
    if(secondInstruction[4] == '1')
    {
        this->currentLongSildeCardStatus=LongSildeCardStatus::LongSildeHaveCard;
    }
    else
    {
        this->currentLongSildeCardStatus=LongSildeCardStatus::LongSildeNoCard;
    }

    if(secondInstruction[3] == '1')
    {
        this->currentLongSildeStatus=LongSildeStatus::LongBusy;
    }
    else
    {
        this->currentLongSildeStatus=LongSildeStatus::LongIdle;
    }

    if(secondInstruction[2] == '1')
    {
        this->currentCleanCardStatus=CleanCardStatus::CleanHaveCard;
    }
    else
    {
        this->currentCleanCardStatus=CleanCardStatus::CleanNoCard;
    }
    if(secondInstruction[1] == '1')
    {
        this->currentCleanStatus=CleanStatus::CleanBusy;
    }
    else
    {
        this->currentCleanStatus=CleanStatus::CleanIdle;
    }

    if(secondInstruction[0] == '1')
    {
        this->currentCache2CardStatus=Cache2CardStatus::Cache2HaveCard;
    }
    else
    {
        this->currentCache2CardStatus=Cache2CardStatus::Cache2NoCard;
    }
    if(thirdInstruction[7] == '1')
    {
        this->currentCache2Status=Cache2Status::Cache2Busy;
    }
    else
    {
        this->currentCache2Status=Cache2Status::Cache2Idle;
    }

    if(thirdInstruction[6] == '1')
    {
        this->currentLongSilde2CardStatus=LongSilde2CardStatus::LongSilde2HaveCard;
    }
    else
    {
        this->currentLongSilde2CardStatus=LongSilde2CardStatus::LongSilde2NoCard;
    }

    if(thirdInstruction[5] == '1')
    {
        this->currentLongSilde2Status=LongSilde2Status::Long2Busy;
    }
    else
    {
        this->currentLongSilde2Status=LongSilde2Status::Long2Idle;
    }

    if(thirdInstruction[4] == '1')
    {
        this->currentPauseButtonStatus=PauseButtonStatus::Press;
    }
    else
    {
        this->currentPauseButtonStatus=PauseButtonStatus::Normal;
    }
}
