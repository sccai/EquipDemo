#ifndef CARDSENDER_H
#define CARDSENDER_H

#include <QObject>
#include "QSerialPort"      //提供访问串口的功能
#include "QSerialPortInfo"    //提供系统中存在的串口的信息
#include "QTime"
#include <QElapsedTimer>
#include <QTimer>
#include "QMap"
#include "devicebase.h"



class CardSender : public QObject,public devicebase
{
    Q_OBJECT
public:
    explicit CardSender(QObject *parent = nullptr);
    ~CardSender();
    explicit CardSender(QString ip,int port,QWidget *_parent);
    int OpenDevice();
    int InitDevice();
    void PauseDevice();
    int CloseDevice();
    int SendCard();
    int RequestStatus();
    void sleepme(unsigned int msec);
    /// <summary>
    /// 设备初始化，首先上位机发送初始化指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
    /// </summary>
    /// <param name="trytimes">重试次数</param>
    /// <param name="timeout">等待接收的超时时长，单位ms</param>
    /// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
    /// <param name="length">数据长度</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int Init(int trytimes, int timeout, unsigned char* ReadData,int& length);

    /// <summary>
    /// 查询传感器状态，首先上位机发送查询传感器状态指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
    /// </summary>，
    /// <param name="trytimes">重试次数</param>
    /// <param name="timeout">等待接收的超时时长，单位ms</param>
    /// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
    /// <param name="length">数据长度</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int RequestStatus(int trytimes,int timeout, unsigned char* ReadData,int& length);

    int SendCard(int trytimes, int timeout, unsigned char* ReadData,int& length);

    int ParseData(QByteArray readdata);

    int ReadDataAsync(int timeout,unsigned char* ReadData,int& length);

    int ParseStatusData(QByteArray readdata);
    //串口对象
    QSerialPort* m_serialPort;
    enum CardStatus { NoCard=0,LessCard,Normal};//HaveCard=0,

    CardStatus currentCardStatus = CardStatus::NoCard;

    Q_ENUM(CardStatus);
signals:
    //接收指令-UI界面更新
    void OnReceiveMsg(QString,QString,int);
    //发送指令-UI界面更新
    void OnSendMsg(QString,QString,int);

public slots:

private slots:
    void Socket_Read_Data();
    //定时循环更新传感器状态
    void updateStatus();
private:
    QString ip;
    int port;
    QWidget *parent;
    //卡勾状态
    bool cardHookIsReady=false;
    bool IsStart=false;
    //当前命令
    QString currcmd;
    //
    QTimer *timer;

    QMap<QString, QString> mapCmd;

public:
    int cardsenderdata = 0;
};

#endif // CARDSENDER_H
