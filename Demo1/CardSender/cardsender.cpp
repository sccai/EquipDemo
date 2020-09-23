#include "cardsender.h"
#include <QElapsedTimer>
#include <QDebug>
#include "QTime"
#include "QMessageBox"
#include "tool/commhelper.h"
#include "QtConcurrent"

CardSender::CardSender(QObject *parent) : QObject(parent)
{

}
CardSender::CardSender(QString _ip,int _port,QWidget *_parent)
{
    this->ip=_ip;
    this->port=_port;
    this->parent=_parent;
}
CardSender::~CardSender()
{
    delete this->m_serialPort;
}

//枚举可用串口
void GetPort()
{
    qDebug()<<"GetPort";
    QStringList m_serialPortName;
    QList<QSerialPortInfo> lst= QSerialPortInfo::availablePorts();
    qDebug()<<"availablePorts "<< lst.count();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);

        if(serial.open(QIODevice::ReadWrite))
        {
            serial.close();
        }
    }
}

/// <summary>
/// 打开设备，默认波特率38400，数据位8位，停止位1位，偶校验
/// </summary>
/// <param name="comname">串口号</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSender::InitDevice()
{
    int result=OpenDevice();
    if(result == 0)
    {
        emit OnReceiveMsg("CardSender","打开发卡器设备成功！",0);//返回给UI
    }
    else
    {
        emit OnReceiveMsg("CardSender","打开设备失败！",0);//返回给UI
    }

    //连接信号槽 当下位机发送数据QSerialPort会发送个readyRead信号,我们定义个槽void ReadData()解析数据
    IsStart=true;
    //连接信号槽
    //QObject::connect(m_serialPort, &QSerialPort::readyRead, this, &CardSender::Socket_Read_Data);

    unsigned char * ReadData;
    int length = 0;
    result =Init(1,5000,ReadData,length);
    if(result == 0)
    {
        emit OnReceiveMsg("CardSender","初始化发卡器成功！",0);
    }
    else
    {
        emit OnReceiveMsg("CardSender","初始化发卡器失败！",0);
    }
    return result;
}

/// <summary>
/// 打开设备，默认波特率38400，数据位8位，停止位1位，偶校验
/// </summary>
/// <param name="comname">串口号</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSender::OpenDevice()
{
    QString comname="ttyS0";

    QString strInitUTF8=QString::fromUtf8("OpenDevice ")+comname;
    CommHelper::Instance()->ShowLog(strInitUTF8);

    //const char*
    m_serialPort = new QSerialPort();
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        m_serialPort->close();
    }

    //设置串口名
    m_serialPort->setPortName(comname);

    //设置波特率
    if(!m_serialPort->setBaudRate(QSerialPort::Baud38400))
    {
        return -4;
    }

    //设置数据位数
    if(!m_serialPort->setDataBits(QSerialPort::Data8))
    {
        return -4;
    }

    //设置奇偶校验
    if(!m_serialPort->setParity(QSerialPort::EvenParity))
    {
        return -4;
    }

    //设置停止位
    if(!m_serialPort->setStopBits(QSerialPort::OneStop))
    {
        return -4;
    }

    //设置流控制
    if(!m_serialPort->setFlowControl(QSerialPort::NoFlowControl))
    {
        return -4;
    }

    //打开串口
    if(!m_serialPort->open(QIODevice::ReadWrite))
    {
        return -4;
    }
    return 0;
}

//
int CardSender::CloseDevice()
{

}
void CardSender::PauseDevice()
{
    IsStart = false;
    timer->stop();
}

void CardSender::Socket_Read_Data()
{
    if(IsStart)
    {
        CommHelper::Instance()->ShowLog("=======CardSender_Read_Data=======");
        static QByteArray readData;
        static int sumlength = 0;
        int length = 0;
        static int datalength = 0;
        QByteArray rxData;
        if(m_serialPort->waitForReadyRead(30))//30ms内读取到数据作为一包
        {
            length = m_serialPort->bytesAvailable(); //接收长度
            rxData = m_serialPort->readAll();
            qDebug()<<"rxData = "<<rxData;
            if(!rxData.isEmpty())
            {
                qDebug() << "ReadData length = "<< length;
                if(rxData[0] == char(0x06))//接收到正确应答
                {
                    datalength = rxData[3];//数据长度
                }
                readData.append(rxData);
                sumlength += length;
                if(datalength + 6 == sumlength)//接收到完整数据进行解析( 6:4 + data + 2)
                {
                    sumlength = 0;
                    datalength = 0;
                    ParseData(readData);
                    readData.clear();
                }
            }
        }
        rxData.clear();
    }
}

int CardSender::ParseData(QByteArray readdata)
{
    int length = readdata.length();
    CommHelper::Instance()->ShowLog("Cardsender-ParseData length = "+length);
     CommHelper::Instance()->ShowLog("Cardsender-ParseData = "+CommHelper::Instance()->ByteArrayToHexStringCard(readdata));
   // qDebug() << "Cardsender-ParseData length = "<< length;
   // qDebug()<<CommHelper::Instance()->ByteArrayToHexStringCard(readdata);

    //查询版本
    if(readdata[5] == char(0x76) && readdata[6] == char(0x30))
    {
        readdata.remove(0,1);//去掉0x06
        QString result = CommHelper::Instance()->GetStrData(readdata);
        qDebug()<<"固件版本号:"<<result;
        emit OnReceiveMsg("CardSender","固件版本号:" + result,0);
    }
    //查询传感器状态
    else if(readdata[5] == char(0x76) && readdata[6] == char(0x31))
    {
        if(currcmd=="7631")
        {
            currcmd="";
        }
        if(readdata[4] == char(0x50))
        {
            cardHookIsReady=true;
            ParseStatusData(readdata);
        }
        else
        {
            cardHookIsReady = false;
        }
        emit OnReceiveMsg("CardSender","查询传感器: " +CommHelper::Instance()->ByteArrayToHexStringCard(readdata),0);
    }
    //初始化
    else if(readdata[5] == char(0x30) && readdata[6] == char(0x33))
    {
        if(currcmd=="3033")
        {
            currcmd="";
            //开启状态查询timer
            timer = new QTimer(this);
            //connect(timer, SIGNAL(timeout()), this, SLOT(updateStatus()));
            //timer->setInterval(1000);
            //timer->start();
            emit OnReceiveMsg("CardSender","初始化结果: "+CommHelper::Instance()->ByteArrayToHexStringCard(readdata),0);
            return 1;
        }
    }
    //发卡成功
    else if(readdata[5] == char(0x76) && readdata[6] == char(0x43))
    {
        if(currcmd=="7643")
        {
            currcmd="";
            RequestStatus();
            emit OnReceiveMsg("CardSender","发卡结果: "+CommHelper::Instance()->ByteArrayToHexStringCard(readdata),0);
            return 1;
        }
        //RequestStatus();
        //timer->start();
    }
    else
    {
        currcmd="";
        emit OnReceiveMsg("CardSender","指令执行失败结果: "+CommHelper::Instance()->ByteArrayToHexStringCard(readdata),0);
        return -1;
    }
}

// 解析下位机发来状态查询数据
int CardSender::ParseStatusData(QByteArray readdata)
{
    QString ret(readdata.toHex().toUpper());
    char data_status = readdata[9];
    switch (data_status) {
    case (char)0x0A://卡少，卡勾后光耦 1010
    {
        qDebug()<<"data_status :" << "OA";
        currentCardStatus=CardStatus::LessCard;
        break;
    }
    case (char)0x0B://卡空，卡少，卡勾后光耦 1011
    {
        qDebug()<<"data_status : " << "OB";
        currentCardStatus=CardStatus::NoCard;
        break;
    }
    case (char)0x09://卡空，卡勾后光耦 1001
    {
        qDebug()<<"data_status : " << "O9";
        currentCardStatus=CardStatus::NoCard;
        break;
    }
    case (char)0x08://卡勾后光耦 1000
    {
        qDebug()<<"data_status : " << "O8";
        currentCardStatus=CardStatus::Normal;
        break;
    }
    default:
        qDebug()<<"data_status : " << ret;
        break;
    }
    return 0;
}

/// <summary>
/// 设备初始化，首先上位机发送初始化指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
/// </summary>
/// <param name="trytimes">重试次数</param>
/// <param name="timeout">等待接收的超时时长，单位ms</param>
/// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
/// <param name="length">数据长度</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
///
int CardSender::Init(int trytimes, int timeout, unsigned char* ReadData,int& length)
{
    currcmd="3033";
    //准备命令
    QString sendDataStr("F2000E4330333332343030303031303030");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);

    emit OnSendMsg("CardSender",CommHelper::Instance()->ByteArrayToHexStringCard(sendData),0);//返回给UI

    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }

    m_serialPort->waitForBytesWritten(1000);
    //接收回应
    QByteArray resultdata;
    QByteArray rbuf;
    QThread::sleep(1);  //挂起1秒，等待扫描结束
    bool end = false;
    while(!end)
    {
        end = !m_serialPort->waitForReadyRead(500);
        while (m_serialPort->bytesAvailable())
        {
            rbuf = m_serialPort->readAll();
            resultdata += rbuf;
        }
    }
    ret = ParseData(resultdata);
    //    while(1)
    //    {
    //        if(mapCmd["3033"]!="")
    //        {
    //            CommHelper::Instance()->ShowLog("收到了3033消息");
    //            break;
    //        }
    //        else
    //        {
    //            CommHelper::Instance()->ShowLog("未收到消息");
    //            sleepme(500);
    //        }
    //    }


    if( ret > 0 )
    {
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }
}

void CardSender::sleepme(unsigned int msec)
{
    QTime reachTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

int CardSender::SendCard()
{
    if(!IsStart)
        return -1;
    //timer->stop();

    while(1)
    {
        if(currcmd=="")
        {
            currcmd="7643";
            unsigned char * ReadData;
            int length = 0;
            int result =SendCard(1,5000,ReadData,length);
            return result;
            //break;
        }
        CommHelper::Instance()->sleepme(500);
    }
}

int CardSender::SendCard(int trytimes, int timeout, unsigned char* ReadData,int& length)
{
    //准备命令
    QString sendDataStr("F20003437643");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);

    emit OnSendMsg("CardSender",CommHelper::Instance()->ByteArrayToHexStringCard(sendData),0);//返回给UI

    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }

    //接收回应
    QByteArray resultdata;
    QByteArray rbuf;
    QThread::sleep(1);  //挂起1秒，等待扫描结束
    bool end = false;
    while(!end)
    {
        end = !m_serialPort->waitForReadyRead(2000);
        while (m_serialPort->bytesAvailable())
        {
            rbuf = m_serialPort->readAll();

            if (rbuf[0] ==char(0x06)&&rbuf.length()==1)
            {
                //CommHelper::Instance()->Showtime();
                //qDebug()<<"阻塞rbuf.length = "<<rbuf.length();
                //qDebug()<<rbuf;
                resultdata += rbuf;
                end = false;
            }
            else
            {
                //CommHelper::Instance()->Showtime();
                //qDebug()<<"阻塞A rbuf.length = "<<rbuf.length();
                //qDebug()<<rbuf;
                resultdata += rbuf;
            }
        }
    }
    ret =ParseData(resultdata);
    //    if(m_serialPort->waitForReadyRead(30))//30ms内读取到数据作为一包
    //    {
    //        length = m_serialPort->bytesAvailable(); //接收长度
    //        rxData = m_serialPort->readAll();
    //        //qDebug()<<"rxData = "<<rxData;
    //        if(!rxData.isEmpty())
    //        {
    //            //qDebug() << "ReadData length = "<< length;
    //            if(rxData[0] == char(0x06))//接收到正确应答
    //            {
    //                datalength = rxData[3];//数据长度
    //            }
    //            readData.append(rxData);
    //            sumlength += length;
    //            if(datalength + 6 == sumlength)//接收到完整数据进行解析( 6:4 + data + 2)
    //            {
    //                sumlength = 0;
    //                datalength = 0;
    //                ParseData(readData);
    //                readData.clear();
    //            }
    //        }
    //    }

    if( ret > 0 )
    {
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }
}

void CardSender::updateStatus()
{
    if(currcmd=="")
    {
        //QtConcurrent::run(this,&CardSender::RequestStatus);
        RequestStatus();
    }
}

int CardSender::RequestStatus()
{
    unsigned char * ReadStatusData;
    int length = 0;
    int result =RequestStatus(1,5000,ReadStatusData,length);
    switch (result)
    {
    case 0:
        break;
    case -1:
        //查询传感器状态，发送数据失败

        break;
    default:
        //查询传感器状态，接收数据异常

        break;
    }
    return result;
}

/// <summary>
/// 查询传感器状态，首先上位机发送查询传感器状态指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
/// </summary>，
/// <param name="trytimes">重试次数</param>
/// <param name="timeout">等待接收的超时时长，单位ms</param>
/// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
/// <param name="length">数据长度</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSender::RequestStatus(int trytimes,int timeout, unsigned char* ReadData,int& length)
{
    currcmd="7631";
    //准备命令76 31
    QString sendDataStr("F20003437631");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);

    emit OnSendMsg("CardSender",CommHelper::Instance()->ByteArrayToHexStringCard(sendData),0);//返回给UI

    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }
    //接收回应
    QByteArray resultdata;
    QByteArray rbuf;
    QThread::sleep(1);  //挂起1秒，等待扫描结束
    bool end = false;
    while(!end)
    {
        end = !m_serialPort->waitForReadyRead(500);
        while (m_serialPort->bytesAvailable())
        {
            rbuf = m_serialPort->readAll();
            //if (rbuf.at(0) != 0x06)
            //{
            resultdata += rbuf;
            //}
        }
    }
    ret = ParseData(resultdata);

    if( ret > 0 )
    {
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }
}
