#include "cardsenderform.h"
#include "ui_cardsenderform.h"
#include <QElapsedTimer>
#include <QDebug>

#include "tool/commhelper.h"
CardSenderForm::CardSenderForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardSenderForm)
{
    ui->setupUi(this);
}

CardSenderForm::~CardSenderForm()
{
    delete ui;
}

//枚举可用串口
void CardSenderForm::GetPort()
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
            qDebug()<<"info "<<info.portName();
            ui->comboBoxComm->addItem(serial.portName());
            serial.close();
        }
    }
}

/// <summary>
/// 打开设备，默认波特率38400，数据位8位，停止位1位，偶校验
/// </summary>
/// <param name="comname">串口号</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSenderForm::OpenDevice(QString comname)
{
    comname="ttyS0";
    qDebug()<<"OpenDevice "<<comname;
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

    //连接信号槽 当下位机发送数据QSerialPort会发送个readyRead信号,我们定义个槽void ReadData()解析数据
    connect(m_serialPort, &QSerialPort::readyRead, this, &CardSenderForm::ReadData);//Linux可能没有readyRead，需要定时轮询
    return 0;
}

// 发送数据给下位机
void CardSenderForm::SendData(QByteArray &sendData)
{
    // 发送数据帧
    m_serialPort->write(sendData);
    //刷新缓冲区
    //m_serialPort->flush();
}

//一次性读取串口数据
void CardSenderForm::ReadData()
{
    qDebug()<<"ReadData";
    static QByteArray readData;
    static int sumlength = 0;
    int length = 0;
    static int datalength = 0;
    QByteArray rxData;
    if(m_serialPort->waitForReadyRead(30))//30ms内读取到数据作为一包
    {
        length = m_serialPort->bytesAvailable(); //接收长度
        rxData = m_serialPort->readAll();
        if(!rxData.isEmpty())
        {
            qDebug() << "ReadData length ="<< length;
            if(rxData[0] == char(0x06))//接收到正确应答
            {
                datalength = rxData[3];//数据长度
            }
            readData.append(rxData);
            qDebug()<<CommHelper::Instance()->ByteArrayToHexStringCard(rxData);
            sumlength += length;
            if(datalength + 6 == sumlength)//接收到完整数据进行解析
            {
                sumlength = 0;
                datalength = 0;
                CheckData(readData);
                readData.clear();
            }
        }
    }

    rxData.clear();
}

void CardSenderForm::CheckData(QByteArray readdata)
{
    //rxTimer->stop();
    int length = readdata.length();
    qDebug() << "Check length ="<< length;
    qDebug()<<CommHelper::Instance()->ByteArrayToHexStringCard(readdata);
    ui->receivetextEdit->append(CommHelper::Instance()->ByteArrayToHexStringCard(readdata));
    if(readdata[5] == char(0x76) && readdata[6] == char(0x30))//查询版本
    {
        readdata.remove(0,1);//去掉0x06
        QString result = CommHelper::Instance()->GetStrData(readdata);
        qDebug()<<"固件版本号:"<<result;
        ui->receivetextEdit->append("固件版本号:" + result);
    }
}

// 读取下位机发来数据
int CardSenderForm::ReadDataT(int timeout,unsigned char* ReadData,int& length)
{

    QElapsedTimer timer;
    timer.start();//开始计时

    // timer.elapsed();//返回当前计时

    // 将下位机发来数据存储在数据缓冲区
    int data_status = 0;
    int ret = 0;
    int dataCount = 0;
    char tempdata[1024] = {0};
    QByteArray data;
    // char dataBuffer[1024] = {0};
    // QDebug()<<"getmessage";
    bool result = m_serialPort->waitForReadyRead(timeout);
    if(!result)
    {
        qDebug() << "count" << timeout << "milliseconds";//计时结束
        return -1;
    }

    while(1)
    {

        switch (data_status) {
        case 0:
        {
            //data = m_serialPort->readAll();
            ret = m_serialPort->read(&tempdata[0],1);
            if( ret > 0 )
            {
                // memcpy(&start_flag,tempdata,1);
                if(tempdata[0]==(char)0x06)
                {
                    qDebug() << tempdata[0];
                    data_status=1;//检测到第一个标志位
                }
            }

        }
        case 1:
        {
            ret = m_serialPort->read(&tempdata[0],1);
            // memcpy(&start_flag,tempdata,1);
            if(tempdata[0]==(char)0xF2)
            {
                qDebug() << tempdata[0];
                data_status=2;//检测到第二个标志位
            }
            else
            {
                data_status=0;//否则错误帧丢弃重来
            }
            break;
        }
        case 2:
        {
            ret = m_serialPort->read(&tempdata[1],1);
            // memcpy(&start_flag,tempdata,1);
            if(tempdata[1]==(char)0x00)
            {
                qDebug() << tempdata[1];
                data_status=3;//检测到第二个标志位
            }
            else
            {
                data_status=0;//否则错误帧丢弃重来
            }
            break;
        }
        case 3:
        {
            ret = m_serialPort->read(&tempdata[2],1);
            if( ret > 0)
            {
                qDebug() << tempdata[2];
                dataCount = (int)tempdata[2];
            }
            else
            {

            }

            break;
        }
        case 4:
            if(m_serialPort->bytesAvailable()>=dataCount)
            {
                ret = m_serialPort->read(&tempdata[3],dataCount);
                memcpy(ReadData,(unsigned char*)tempdata,dataCount+3);
                length = dataCount + 3;
                //ProcessInputData(tempdata);
                data_status=0;//重置位
            }
            break;
        default:
            break;
        }
        //sleep
    }
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
int CardSenderForm::Init(int trytimes, int timeout, unsigned char* ReadData,int& length)
{
    //准备命令
    QString sendDataStr("F2000E4330333332343030303031303030");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);
    ui->sendtextEdit->append(CommHelper::Instance()->ByteArrayToHexStringCard(sendData));
    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }
    ui->sendtextEdit->append("发送结果 ="+QString::number(ret));
    if( ret > 0 )
    {
        //接收数据
        //       int retR = ReadDataT(timeout,ReadData,length);
        //       if( retR < 0 )
        //           return -3;
        //       return 0;
    }
    else
    {
        return -2;//发送数据失败
    }

}

/// <summary>
/// 发卡，首先上位机发送发卡指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
/// </summary>
/// <param name="trytimes">重试次数</param>
/// <param name="timeout">等待接收的超时时长，单位ms</param>
/// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
/// <param name="length">数据长度</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSenderForm::SendCard(int trytimes, int timeout, unsigned char* ReadData,int& length)
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
    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }
    if( ret > 0 )
    {
        //        //接收数据
        //        int retR = ReadDataT(timeout,ReadData,length);
        //        if( retR < 0 )
        //            return -3;
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }

}

/// <summary>
/// 查询传感器状态，首先上位机发送查询传感器状态指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
/// </summary>，
/// <param name="trytimes">重试次数</param>
/// <param name="timeout">等待接收的超时时长，单位ms</param>
/// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
/// <param name="length">数据长度</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSenderForm::RequestStatus(int trytimes,int timeout, unsigned char* ReadData,int& length)
{
    //准备命令
    QString sendDataStr("F20003437631");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);
    ui->sendtextEdit->append(CommHelper::Instance()->ByteArrayToHexStringCard(sendData));
    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }
    if( ret > 0 )
    {
        //接收数据
        //        int retR = ReadDataT(timeout,ReadData,length);
        //        if( retR < 0 )
        //            return -3;
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }

}


/// <summary>
/// 查询设备版本，首先上位机发送查询设备版本指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
/// </summary>
/// <param name="trytimes">重试次数</param>
/// <param name="timeout">等待接收的超时时长，单位ms</param>
/// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
/// <param name="length">数据长度</param>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSenderForm::RequestVision(int trytimes,int timeout, unsigned char* ReadData,int& length)
{
    //准备命令
    QString sendDataStr("F20003437630");
    QByteArray sendData = CommHelper::Instance()->QString2Hex(sendDataStr);
    //c和d就是CRC16校验的2个字节
    quint16 result = CommHelper::Instance()->Cal_crc16(sendData.data(), sendData.length());
    unsigned char c = result >> 8;
    unsigned char d = result & 255;
    sendData.append(c);
    sendData.append(d);
    ui->sendtextEdit->append(CommHelper::Instance()->ByteArrayToHexStringCard(sendData));
    //发送数据
    int ret = m_serialPort->write(sendData);
    while( (ret==-1) && (trytimes>0))
    {
        ret = m_serialPort->write(sendData);
        trytimes--;
        continue;
    }
    if( ret > 0 )
    {
        //接收数据
        //        int retR = ReadDataT(timeout,ReadData,length);
        //        if( retR < 0 )
        //            return -3;
        return 0;
    }
    else
    {
        return -2;//发送数据失败
    }


}


/// <summary>
/// 关闭设备
/// </summary>
/// <returns>结果 0:成功；其他参见错误码</returns>
int CardSenderForm::CloseDevice(void)
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }
    delete m_serialPort;
    return 0;
}

//获取现有端口
void CardSenderForm::on_GetPort_clicked()
{
    GetPort();
}

//初始化设备
void CardSenderForm::on_pushButton_clicked()
{
    qDebug()<<"打开设备";
    int result = OpenDevice(ui->comboBoxComm->currentText());
    if(result == 0)
    {
        ui->receivetextEdit->append("打开设备成功！");
    }
    else
    {
        ui->receivetextEdit->append("打开设备失败！");
    }
    unsigned char * ReadData;
    int length = 0;
    result =Init(1,5000,ReadData,length);
}

void CardSenderForm::on_pushButton_3_clicked()
{
    unsigned char * ReadData;
    int length = 0;
    int result =SendCard(1,5000,ReadData,length);
}

//查询状态
void CardSenderForm::on_pushButton_GetStatus_clicked()
{
    unsigned char * ReadData;
    int length = 0;
    int result =RequestStatus(1,5000,ReadData,length);
}
