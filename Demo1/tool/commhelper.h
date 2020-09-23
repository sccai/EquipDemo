#ifndef COMMHELPER_H
#define COMMHELPER_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

#include "QDebug"
#include "QTime"
/*
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"*/

//通用类
class CommHelper : public QObject
{
    Q_OBJECT
public:
    static CommHelper *Instance();
    explicit CommHelper(QObject *parent = 0);
    void sleepme(unsigned int msec);
    QByteArray HexStringToByteArray(QString HexString);
    //解析７０指令
    QStringList HexStringToBytes(QString HexString);
    QString ByteArrayToHexString(QByteArray &ba);

    //解析传感器标志位，返回二进制的集合
    QStringList GetStatusBackData(QStringList &ba);

    void Showtime();
    void ShowLog(QString HexString);
    void SetDebug(bool);
    //是否输出调试信息
    bool IsShowDebug=false;
    //
    char ConvertHexChar(char c);
    QString GetStrData(QByteArray binaryData);
    QByteArray QString2Hex(QString hexStr);
    QString ByteArrayToHexStringCard(QByteArray data);
    quint16 Cal_crc16(char *data, int size);
    bool CheckCode();

signals:

public slots:

private:
    static CommHelper *self;    //对象自身
   // QString logpath="/home/dg/EquipDemo/log.txt";
    QString logpath="log.txt";
};

#endif // COMMHELPER_H
