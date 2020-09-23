#ifndef CARDSENDERFORM_H
#define CARDSENDERFORM_H

#include <QWidget>
#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QMainWindow>
#include <QMessageBox>
#include <QComboBox>
#include <QElapsedTimer>
#include <QTimer>
#include <QTextEdit>

namespace Ui {
class CardSenderForm;
}

class CardSenderForm : public QWidget
{
    Q_OBJECT

public:
    explicit CardSenderForm(QWidget *parent = 0);
    ~CardSenderForm();

    /// <summary>
    /// 打开设备，默认波特率38400，数据位8位，停止位1位，偶校验
    /// </summary>
    /// <param name="comname">串口号</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int OpenDevice(QString comname);

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
    /// 发卡，首先上位机发送发卡指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
    /// </summary>
    /// <param name="trytimes">重试次数</param>
    /// <param name="timeout">等待接收的超时时长，单位ms</param>
    /// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
    /// <param name="length">数据长度</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int SendCard(int trytimes, int timeout, unsigned char* ReadData,int& length);

    /// <summary>
    /// 查询传感器状态，首先上位机发送查询传感器状态指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
    /// </summary>，
    /// <param name="trytimes">重试次数</param>
    /// <param name="timeout">等待接收的超时时长，单位ms</param>
    /// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
    /// <param name="length">数据长度</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int RequestStatus(int trytimes,int timeout, unsigned char* ReadData,int& length);


    /// <summary>
    /// 查询设备版本，首先上位机发送查询设备版本指令，最后2字节采用X16+X15+X5+1的多项式CRC16校验，发卡器收到指令后进行校验正确返回0x06（如果校验错误返回0x15，上位机需要重新发送指令），然后上位机解析数据
    /// </summary>
    /// <param name="trytimes">重试次数</param>
    /// <param name="timeout">等待接收的超时时长，单位ms</param>
    /// <param name="ReadData">数据存放的地址指针（除去0x06，以0xF2开始的数据）</param>
    /// <param name="length">数据长度</param>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int RequestVision(int trytimes,int timeout, unsigned char* ReadData,int& length);

    /// <summary>
    /// 关闭设备
    /// </summary>
    /// <returns>结果 0:成功；其他参见错误码</returns>
    int CloseDevice(void);
    void SendData(QByteArray &sendData);
    int ReadDataT(int timeout,unsigned char* ReadData,int& length);
    void GetPort();
    void CheckData(QByteArray readdata);
    //创建串口对象
    QSerialPort* m_serialPort;
private slots:
    void ReadData();
    void on_GetPort_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_GetStatus_clicked();

private:
    Ui::CardSenderForm *ui;
};

#endif // CARDSENDERFORM_H
