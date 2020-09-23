#include "sendmod.h"
#include "QDebug"
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "mainwindow.h"
#include "QtConcurrent"

SendMod::SendMod(QObject *parent) : QObject(parent)
{

}
SendMod::~SendMod()
{
    delete this->client;
}
SendMod::SendMod(QString _ip,int _port,QWidget *_parent)
{
    this->ip=_ip;
    this->port=_port;
    this->parent=_parent;
}
void SendMod::InitDevice()
{
    client = new QTcpSocket(this);
    client->connectToHost(QHostAddress(ip), port);
    //等待连接成功
    if(!client->waitForConnected(3000))
    {
        QMessageBox::information(parent,tr("提示-Connection failed!"),tr("Connection failed!"),QMessageBox::Ok);
        return;
    }
    IsStart=true;

    //qDebug() << "Socket链接成功";
    QString strInitUTF8=QString::fromUtf8("SocketTCP链接成功");
    CommHelper::Instance()->ShowLog(strInitUTF8);
    //连接信号槽
    QObject::connect(client, &QTcpSocket::readyRead, this, &SendMod::Socket_Read_Data);

    SendMsg(START);
}

void SendMod::StopDevice()
{

}

void SendMod::PauseDevice()
{

}

void SendMod::FlipCardInFun()
{
    this->SendMsg(ROTATIONFLIPCARDIN);
}
void SendMod::FlipCardOutFun()
{
    this->SendMsg(ROTATIONFLIPCARDOUT);
}

void SendMod::CleanCardInFun()
{
    //指令执行开始
    //字典
    QString commandCode=CLEANCARDIN.mid(6,2);//.mid截取字符串 =06
    if(mapCmd.contains(commandCode))
    {
        if(mapCmd[commandCode]!="")
        {
            mapCmd[commandCode]="0";
        }
    }
    else
    {
        mapCmd.insert(commandCode,"0");
    }
    currentCleanCommandStatus = SendMod::Runing;
    this->SendMsg(CLEANCARDIN);
    //QtConcurrent::run(this,&SendMod::SendMsg,CLEANCARDIN);//线程执行
}

//命令是否执行完成, mapCmd 指令执行结束
void SendMod::CmdFinish(QString cmd)
{
    //    while (this->currentCleanCardStatus!=SendMod::CleanHaveCard) {
    //        qDebug()<<"currentCleanCardStatus ="<<this->currentCleanCardStatus;
    //        QTime t;
    //        t.start();
    //        while(t.elapsed()<2000);
    //    }
    //    qDebug()<<"currentCleanCardStatus HAVE="<<this->currentCleanCardStatus;

    //"0602028079" 80代表命令执行完成
    QString commandCode=cmd.mid(0,2);//.mid截取字符串 =06
    QString commandStatus=cmd.mid(6,2);//.mid截取完成情况=80

    //字典
    if(mapCmd.contains(commandCode))
    {
        if(commandStatus=="80")
        {
            currentCleanCommandStatus = SendMod::Finish;
            mapCmd[commandCode]="1";//执行完成
            //qDebug()<<"currentCleanCommandStatus ="<<currentCleanCommandStatus;
        }
    }
}

void SendMod::CleanCardOutFun()
{
    this->SendMsg(CLEANCARDOUT);
}
//缓冲机构出卡
void SendMod::CardCacheOutFun()
{
    this->SendMsg(CACHECARDOUT);
}

void SendMod::SendMsg(QString HexString)//HexString="AA 55 02 01"
{
    QStringList lst =HexString.split(' ',QString::SkipEmptyParts);
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
    //qDebug() << revStr;
    //CommHelper::Instance()->ShowLog("SendMsg发送指令: = "+revStr);
    emit OnSendMsg("SendMod",revStr,0);//返回给UI
    int sendRe = client->write(byte_head);
    client->flush();//冲掉缓存，不然无法读取服务端发送的数据

    if(sendRe == -1)
    {
        qDebug() << "=======write -1 =======";
        QMessageBox::information(parent, "QT网络通信", "向服务端发送数据失败！");
    }
}

void SendMod::Socket_Read_Data()
{
    if(IsStart)
    {
        CommHelper::Instance()->ShowLog("=======SendMod_Read_Data=======");
        QByteArray arrayRead = client->readAll();
        if(!arrayRead.isEmpty())
        {
            //qDebug() << "数据长度 = "<< le;
            QString receivestr=CommHelper::Instance()->ByteArrayToHexString(arrayRead);
            //"数据 = " qDebug() << "数据 = " << receivestr;
            //CommHelper::Instance()->ShowLog("数据 = "+receivestr);
            //删除所有空格
            QString receiveNotSpace = receivestr.remove(QRegExp("\\s"));
            //AA55 split
            QStringList lst = receiveNotSpace.split("AA55",QString::SkipEmptyParts);
            for (int j=0; j<lst.count(); j++)
            {
                qDebug() << "AA55"+lst.at(j);//"AA55 0602028079" 80代表命令执行完成

                //指令执行完成
                CmdFinish(lst.at(j));

                emit OnReceiveMsg("SendMod","AA55"+lst.at(j),100);//返回给UI

                //内部直接更新状态
                //"AA55"+lst.at(j)变成QStringList，再调用SetCurrentStatus
            }
        }
    }
}

//根据数据设置传感器状态
void SendMod::SetCurrentStatus(QStringList &ba)
{
    QString secondInstruction = ba.at(1);
    QString thirdInstruction = ba.at(2);
    if(secondInstruction[7] == '1')
    {
        this->currentSendCardModStatus = ModStatus::Startup;
    }
    else
    {
        this->currentSendCardModStatus = ModStatus::Closed;
    }
    if (secondInstruction[6] == '1')
        this->currentRotationFlipCardStatus = CardStatus::HaveCard;
    else
        this->currentRotationFlipCardStatus = CardStatus::NoCard;

    if (secondInstruction[5] == '1')
        this->currentRotationFlipStatus = FlipStatus::Busy;
    else
        this->currentRotationFlipStatus = FlipStatus::Idle;

    if (secondInstruction[4] == '1')
        this->currentCleanCardStatus = CleanCardStatus::CleanHaveCard;
    else
        this->currentCleanCardStatus = CleanCardStatus::CleanNoCard;

    if (secondInstruction[3] == '1')
        this->currentCleanStatus = CleanStatus::CleanBusy;
    else
        this->currentCleanStatus = CleanStatus::CleanIdle;

    if( secondInstruction[2] == '1')
        this->currentCacheCardStatus = CacheCardStatus::CacheHaveCard;
    else
        this->currentCacheCardStatus = CacheCardStatus::CacheNoCard;

    if( secondInstruction[1] == '1')
        this->currentCacheStatus = CacheStatus::CacheBusy;
    else
        this->currentCacheStatus = CacheStatus::CacheIdle;
    //拍照工位有卡 2020-09-17 去掉CIS设备，增加摄像头机构
    if( secondInstruction[1] == '1')
        this->currentPhotoCardStatus = PhotoCardStatus::PhotoHaveCard;
    else
        this->currentPhotoCardStatus = PhotoCardStatus::PhotoNoCard;
    //拍照工位
    if(thirdInstruction[7] == '1')
        this->currentPhotoStatus = PhotoStatus::PhotoBusy;
    else
        this->currentPhotoStatus = PhotoStatus::PhotoIdle;

}
