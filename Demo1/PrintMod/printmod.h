#ifndef PRINTMOD_H
#define PRINTMOD_H

#include <QObject>
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"

class PrintMod : public QObject
{
    Q_OBJECT
public:
    explicit PrintMod(QObject *parent = 0);
    ~PrintMod();
    explicit PrintMod(QString ip,int port,std::string id,QWidget *_parent);

    void InitDevice();
    void StopDevice();
    void PauseDevice();
    //清洁轨道
    void CleanSlide();

    void WriteIn();
    void WriteOut();
    void PrinterIn();
    void PrinterOut();
    void Silde2Out();
    void LongSildePass();
    void SetCurrentStatus(QStringList &ba);
    //机构恢复

    enum ModStatus {Startup=0, Closed};
    enum LongSlideCardStatus {HaveCard=0, NoCard};
    enum LongSildeStatus {Busy=0, Idle};
    enum WriterCardStatus {WriterHaveCard=0, WriterNoCard};
    enum WriterStatus {WriterBusy=0, WriterIdle};
    enum SwingCardStatus {SwingHaveCard=0, SwingNoCard};
    enum SwingStatus {SwingBusy=0, SwingIdle};
    enum ShortSildeCardStatus {ShortHaveCard=0, ShortNoCard};
    enum ShortSlideStatus {ShortBusy=0, ShortIdle};
    enum LongSildeReady {YesLong=0, NoLong};
    enum ShortSildeReady{YesShort=0, NoShort};
    //属性
    ModStatus currentPrinterModStatus=ModStatus::Closed;
    LongSlideCardStatus currentLongSildeCardStatus = LongSlideCardStatus::NoCard;
    LongSildeStatus currentLongSildeStatus=LongSildeStatus::Idle;
    WriterCardStatus currentWriterCardStatus = WriterCardStatus::WriterNoCard;
    WriterStatus currentWriterStatus = WriterStatus::WriterIdle;
    SwingCardStatus currentSwingCardStatus =SwingCardStatus::SwingNoCard;
    SwingStatus  currentSwingStatus =SwingStatus::SwingIdle;
    ShortSildeCardStatus currentShortSildeCardStatus = ShortSildeCardStatus::ShortNoCard;
    ShortSlideStatus currentShortSildeStatus = ShortSlideStatus::ShortIdle;
    LongSildeReady currentLongSildeReady = LongSildeReady::YesLong;
    ShortSildeReady currentShortSildeReady = ShortSildeReady::NoShort;

    Q_ENUM(ModStatus);
    Q_ENUM(LongSlideCardStatus);
    Q_ENUM(LongSildeStatus);
    Q_ENUM(WriterCardStatus);
    Q_ENUM(WriterStatus);
    Q_ENUM(SwingCardStatus);
    Q_ENUM(SwingStatus);
    Q_ENUM(ShortSildeCardStatus);
    Q_ENUM(ShortSlideStatus);
    Q_ENUM(LongSildeReady);
    Q_ENUM(ShortSildeReady);
signals:
    void OnReceiveMsg(QString,QString,int);
    void OnSendMsg(QString,QString,int);
public slots:

private slots:
    void SendMsg(QString HexString);
    void Socket_Read_Data();

private:
    QString ip;
    int port;
    std::string id;
    QWidget *parent;
    bool IsStart=false;
    QTcpSocket *client;
    int msn=1;
    QString START="AA 55 AA 01";//程序启动
    QString STOP = "AA 55 AC 01";
    QString WRITERCARDIN = "AA 55 10 01";//写卡机构进卡
    QString SWINGCARDIN = "AA 55 11 01";//转向机构进卡
    QString PRINTERCARDIN = "AA 55 12 01";//打印机进卡
    QString SWINGCARDINVALID = "AA 55 13 01";// 写卡废卡
    QString PRINTERCARDOUT = "AA 55 14 01";//打印机出卡
    QString SHORTSLIDEOUT = "AA 55 15 01";//短轨道机构出卡
    QString SHORTSLIDEINVALID = "AA 55 16 01";//短轨道机构废卡
    QString LONGSLIDEPASSING = "AA 55 17 01";//长轨道过卡
    QString SENSORCHECK = "AA 55 70 01";
    QString RECOVERYLONGSlLID = "AA 55 2A 01";// 长轨道过卡恢复
    QString RECOVERYSHORTSLIDE = "AA 55 29 01";// 短轨道出卡恢复
    QString RECOVERYWRITERCARDIN = "AA 55 25 01";// 写卡工位进卡恢复
    QString RECOVERYWRITER2SWING = "AA 55 26 01";// 写卡工位 -> 转向进卡故障恢复
    QString RECOVERYSWINGIN = "AA 55 27 01";// 转向机构进卡与打印前废卡故障恢复
    QString SLIDECLEAN = "AA 55 20 01";//轨道清洁
    QString PRINTERINVALID = "AA 55 21 01";// 打印机废卡
};
#endif // PRINTMOD_H
