#include "sortmod.h"
#include "QDebug"
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "mainwindow.h"


SortMod::SortMod(QObject *parent) : QObject(parent)
{

}
SortMod::~SortMod()
{
    delete this->client;
}
SortMod::SortMod(QString _ip,int _port,QWidget *_parent)
{
    this->ip=_ip;
    this->port=_port;
    this->parent=_parent;
}
void SortMod::InitDevice()
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
    QObject::connect(client, &QTcpSocket::readyRead, this, &SortMod::Socket_Read_Data);
    QObject::connect(client, &QTcpSocket::disconnected, this, &SortMod::socket_Disconnected);
    SendMsg(START);
}

void SortMod::StopDevice()
{

}

void SortMod::PauseDevice()
{

}
//矫正进卡
void SortMod::AdjustCardIn()
{
    SendMsg(ADJUSTCARDIN);
}
//矫正出卡
void SortMod::AdjustCardOut()
{
    SendMsg(CISCARDIN);
}
//校验进卡
void SortMod::VerifyCardIn()
{
    SendMsg(VERIFYCARDIN);
}
//出卡槽
void SortMod::SlotCardOut(int slot)//正常出卡
{
    if(slot==1)
        SendMsg(SLOT1OUTCARD);
    else if(slot==2)
        SendMsg(SLOT2OUTCARD);
    else if(slot==3)
        SendMsg(SLOT3OUTCARD);
    else if(slot==4)
        SendMsg(SLOT4OUTCARD);
}

void SortMod::SlotCardEject(int slot)//异常提卡
{
    if(slot==1)
        SendMsg(SLOT1EJECTCARD);
    else if(slot==2)
        SendMsg(SLOT2EJECTCARD);
    else if(slot==3)
        SendMsg(SLOT3EJECTCARD);
    else if(slot==4)
        SendMsg(SLOT4EJECTCARD);
}

//自检循环亮灯
void SortMod::LightCheck()
{
    isStopCheckLight = false;
    LightCheckControl(1,0);
    CommHelper::Instance()->sleepme(1000);
    if (isStopCheckLight)
    {
        return;
    }
    LightClose();

    LightCheckControl(2,0);
    CommHelper::Instance()->sleepme(1000);
    if (isStopCheckLight)
    {
        return;
    }
    LightClose();

    LightCheckControl(4,0);
    CommHelper::Instance()->sleepme(1000);
    if (isStopCheckLight)
    {
        return;
    }
    LightClose();
}

//lightType,0:闪,1:亮
void SortMod::LightCheckControl(int color, int lightType)
{
    if(lightType==0)
        SendLightMsg(LIGHTSWITCH,color);
    else
        SendLightMsg(LIGHTFLICKER,color);
}

void SortMod::LightControl(int color, int lightType)
{
    isStopCheckLight=true;
    if(lightType==0)
        SendLightMsg(LIGHTSWITCH,color);
    else
        SendLightMsg(LIGHTFLICKER,color);
}

void SortMod::LightClose()
{
    QString cmd=LIGHTSWITCH+" 00";
    SendLightMsg(LIGHTSWITCH,0);
}

void SortMod::SendMsg(QString HexString)//HexString="AA 55 02 01"
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
    emit OnSendMsg("SortMod",revStr,0);//返回给UI
    int sendRe = client->write(byte_head);
    client->flush();//冲掉缓存，不然无法读取服务端发送的数据

    if(sendRe == -1)
    {
        qDebug() << "=======write -1 =======";
        QMessageBox::information(parent, "QT网络通信", "向服务端发送数据失败！");
    }
}

void SortMod::SendLightMsg(QString HexString,int msnnum)
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

    QString strmsn = QString("%1").arg(msnnum, 2, 10, QChar('0'));
    int byte5=strmsn.toInt(&ok,16);

    //qDebug() << "MSN = "<< msnnum;
    array[4]=byte5;
    byte_head[4]=byte5;

    //异或
    int tempxor = 0;
    for (int i = 0; i < 5; i=i+1)
    {
        tempxor = (int)(tempxor ^ array[i]);
    }
    //std::cout<<"tempxor=";
    //std::cout<<tempxor<< '\n';
    byte_head[5]=tempxor;

    QString revStr=CommHelper::Instance()-> ByteArrayToHexString(byte_head);//字节数组转换为QString
    //CommHelper::Instance()->ShowLog("SendLightMsg发送指令: = "+revStr);
    emit OnSendMsg("SortMod",revStr,0);//返回给UI
    int sendRe = client->write(byte_head);
    client->flush();//冲掉缓存，不然无法读取服务端发送的数据

    if(sendRe == -1)
    {
        qDebug() << "=======write -1 =======";
        QMessageBox::information(parent, "QT网络通信", "向服务端发送数据失败！");
    }
}

void SortMod::Socket_Read_Data()
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
                emit OnReceiveMsg("SortMod","AA55"+lst.at(j),100);//返回给UI
            }
        }
    }
}
void SortMod::socket_Disconnected()
{
    client->close();
}
//根据数据设置传感器状态
void SortMod::SetCurrentStatus(QStringList &ba)
{
    QString secondInstruction = ba.at(1);
    if(secondInstruction[7] == '1')
    {
        this->currentOutcardModStatus=ModStatus::Startup;
    }
    else
    {
        this->currentOutcardModStatus=ModStatus::Closed;
    }
    if(secondInstruction[6] == '1')
    {
        this->currentAdjustCardStatus=AdjustCardStatus::HaveCard;
    }
    else
    {
        this->currentAdjustCardStatus=AdjustCardStatus::NoCard;
    }
    if(secondInstruction[5] == '1')
    {
        this->currentAdjustPosStatus=AdjustPosStatus::Busy;
    }
    else
    {
        this->currentAdjustPosStatus=AdjustPosStatus::Idle;
    }
    if(secondInstruction[4] == '1')
    {
        this->currentVerifyCardStatus=VerifyCardStatus::VerifyHaveCard;
    }
    else
    {
        this->currentVerifyCardStatus=VerifyCardStatus::VerifyNoCard;
    }
    //验证工位忙
    if(secondInstruction[3] == '1')
    {
        this->currentVerifyPosStatus=VerifyPosStatus::VerifyBusy;
    }
    else
    {
        this->currentVerifyPosStatus=VerifyPosStatus::VerifyIdle;
    }
    if(secondInstruction[2] == '1')
    {
        this->currentSortPosStatus=SortPosStatus::SortBusy;
    }
    else
    {
        this->currentSortPosStatus=SortPosStatus::SortIdle;
    }
    //拍照工位有卡 2020-09-17 去掉CIS设备，增加摄像头机构
    if( secondInstruction[1] == '1')
        this->currentPhotoCardStatus = PhotoCardStatus::PhotoHaveCard;
    else
        this->currentPhotoCardStatus = PhotoCardStatus::PhotoNoCard;
    //拍照工位
    if(secondInstruction[0] == '1')
        this->currentPhotoStatus = PhotoStatus::PhotoBusy;
    else
        this->currentPhotoStatus = PhotoStatus::PhotoIdle;
}
