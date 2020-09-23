#include "printmod.h"
#include "QDebug"
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "mainwindow.h"


PrintMod::PrintMod(QObject *parent) : QObject(parent)
{

}
PrintMod::~PrintMod()
{
    delete this->client;
}
PrintMod::PrintMod(QString _ip,int _port,std::string _id,QWidget *_parent)
{
    this->ip=_ip;
    this->port=_port;
    this->id=_id;
    this->parent=_parent;
}
void PrintMod::InitDevice()
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

    //qDebug() << "Socket链接成功";
    QString strInitUTF8=QString::fromUtf8("SocketTCP链接成功");
    CommHelper::Instance()->ShowLog(strInitUTF8);
    //连接信号槽
    QObject::connect(client, &QTcpSocket::readyRead, this, &PrintMod::Socket_Read_Data);

    SendMsg(START);
}

void PrintMod::StopDevice()
{

}

void PrintMod::PauseDevice()
{

}

void PrintMod::CleanSlide()
{
    SendMsg(SLIDECLEAN);
}
void PrintMod::WriteIn()
{
    SendMsg(WRITERCARDIN);
}
//写卡工位出卡，转向进卡
void PrintMod::WriteOut()
{
    SendMsg(SWINGCARDIN);
}

void PrintMod::PrinterIn()
{
    SendMsg(PRINTERCARDIN);
}
void PrintMod::PrinterOut()
{
    SendMsg(PRINTERCARDOUT);
}

void PrintMod::Silde2Out()
{
    SendMsg(SHORTSLIDEOUT);
}

void PrintMod::LongSildePass()
{
    SendMsg(LONGSLIDEPASSING);
}

void PrintMod::SendMsg(QString HexString)//HexString="AA 55 02 01"
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
    emit OnSendMsg("PrintMod",revStr,0);//返回给UI
    int sendRe = client->write(byte_head);
    client->flush();//冲掉缓存，不然无法读取服务端发送的数据

    if(sendRe == -1)
    {
        qDebug() << "=======write -1 =======";
        QMessageBox::information(parent, "QT网络通信", "向服务端发送数据失败！");
    }
}

void PrintMod::Socket_Read_Data()
{
    if(IsStart)
    {
        CommHelper::Instance()->ShowLog("=======socket_Read_Data=======");
        QByteArray returnValue = client->readAll();
        int le = returnValue.length();
        if(!returnValue.isEmpty())
        {
            //qDebug() << "数据长度 = "<< le;
            QString receivestr=CommHelper::Instance()->ByteArrayToHexString(returnValue);
            //qDebug() << "数据 = " << receivestr;
            //CommHelper::Instance()->ShowLog("数据 = "+receivestr);

            //删除所有空格
            QString receiveNotSpace = receivestr.remove(QRegExp("\\s"));
            //AA55 split
            QStringList allBack = receiveNotSpace.split("AA55",QString::SkipEmptyParts);
            for (int j=0; j<allBack.count(); j++)
            {
                QStringList returnValue= CommHelper::Instance()->HexStringToBytes("AA55"+allBack.at(j));
//                if (!Helper.CheckCode(Helper.HexStringToBytes(s)))
//                            {
//                                continue;
//                            }


                //qDebug() << "AA55"+lst.at(j);
                int number=atoi(this->id.c_str());
                QString msg="AA55"+allBack.at(j);
                //执行的命令
                QString commandCode=msg.mid(4,2);//70: 更新传感器状态

                if(commandCode=="70")
                {
                    //QStringList returnValue= CommHelper::Instance()->HexStringToBytes(msg);
                    //QStringList statusList=CommHelper::Instance()->GetStatusBackData(returnValue);
                    //SetCurrentStatus(statusList);
                }
                emit OnReceiveMsg("PrintMod",msg,number);//返回给UI
            }
        }
    }
}

//根据数据设置传感器状态
void PrintMod::SetCurrentStatus(QStringList &ba)
{
    QString secondInstruction = ba.at(1);
    QString thirdInstruction = ba.at(2);

    if(secondInstruction[7] == '1')
        this->currentPrinterModStatus=ModStatus::Startup;
    else
        this->currentPrinterModStatus =ModStatus::Closed;
    if(secondInstruction[6] == '1')
        this->currentLongSildeCardStatus=LongSlideCardStatus::HaveCard;
    else
        this->currentLongSildeCardStatus=LongSlideCardStatus::NoCard;
    if(secondInstruction[5] == '1')
        this->currentLongSildeStatus=LongSildeStatus::Busy;
    else
        this->currentLongSildeStatus=LongSildeStatus::Idle;

    if(secondInstruction[4] == '1')
        this->currentWriterCardStatus=WriterCardStatus::WriterHaveCard;
    else
        this->currentWriterCardStatus=WriterCardStatus::WriterNoCard;
    if(secondInstruction[3] == '1')
        this->currentWriterStatus=WriterStatus::WriterBusy;
    else
        this->currentWriterStatus=WriterStatus::WriterIdle;

    if(secondInstruction[2] == '1')
        this->currentSwingCardStatus=SwingCardStatus::SwingHaveCard;
    else
        this->currentSwingCardStatus=SwingCardStatus::SwingNoCard;
    if(secondInstruction[1] == '1')
        this->currentSwingStatus=SwingStatus::SwingBusy;
    else
        this->currentSwingStatus=SwingStatus::SwingIdle;
    if(secondInstruction[0] == '1')
        this->currentShortSildeCardStatus=ShortSildeCardStatus::ShortHaveCard;
    else
        this->currentShortSildeCardStatus=ShortSildeCardStatus::ShortNoCard;
    if(thirdInstruction[7] == '1')
        this->currentShortSildeStatus=ShortSlideStatus::ShortBusy;
    else
        this->currentShortSildeStatus=ShortSlideStatus::ShortIdle;
    if(thirdInstruction[6] == '1')
        this->currentLongSildeReady=LongSildeReady::YesLong;
    else
        this->currentLongSildeReady=LongSildeReady::NoLong;
    if(thirdInstruction[5] == '1')
        this->currentShortSildeReady=ShortSildeReady::YesShort;
    else
        this->currentShortSildeReady=ShortSildeReady::NoShort;

}
