#ifndef PRINT_RCK600_H
#define PRINT_RCK600_H

#include <QObject>
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"
#include <r600printer.h>


class Print_RCK600 : public QObject
{
    Q_OBJECT
public:
    explicit Print_RCK600(QObject *parent = 0);
    ~Print_RCK600();
    explicit Print_RCK600(QString ip,int port,QString id,QWidget *_parent,bool simu);

    bool InitDevice();
    void StopDevice();
    void PauseDevice();

    //下发打印任务
    bool LoadPrintTask(QString FImagePath, QString BImagePath, bool isDouble);

    //进卡并打印
    bool FeedCardAndPrint();

    //退卡
    bool EjectCard();

    //    /查询状态
    bool GetStatus(R600Status &status);
    //设置是否模拟打印
    void SetSimulate(bool isSimulate);
    //恢复
    bool PrintReset();

    //    enum ModStatus {Startup=0, Closed};
    //    enum LongSlideCardStatus {HaveCard=0, NoCard};
    //    enum LongSildeStatus {Busy=0, Idle};
    //    enum WriterCardStatus {WriterHaveCard=0, WriterNoCard};
    //    enum WriterStatus {WriterBusy=0, WriterIdle};
    //    enum SwingCardStatus {SwingHaveCard=0, SwingNoCard};
    //    enum SwingStatus {SwingBusy=0, SwingIdle};
    //    enum ShortSildeCardStatus {ShortHaveCard=0, ShortNoCard};
    //    enum ShortSlideStatus {ShortBusy=0, ShortIdle};
    //    enum LongSildeReady {YesLong=0, NoLong};
    //    enum ShortSildeReady{YesShort=0, NoShort};
    //    //属性
    //    ModStatus currentPrinterModStatus=ModStatus::Closed;
    //    LongSlideCardStatus currentLongSildeCardStatus = LongSlideCardStatus::NoCard;
    //    LongSildeStatus currentLongSildeStatus=LongSildeStatus::Idle;
    //    WriterCardStatus currentWriterCardStatus = WriterCardStatus::WriterNoCard;
    //    WriterStatus currentWriterStatus = WriterStatus::WriterIdle;
    //    SwingCardStatus currentSwingCardStatus =SwingCardStatus::SwingNoCard;
    //    SwingStatus  currentSwingStatus =SwingStatus::SwingIdle;
    //    ShortSildeCardStatus currentShortSildeCardStatus = ShortSildeCardStatus::ShortNoCard;
    //    ShortSlideStatus currentShortSildeStatus = ShortSlideStatus::ShortIdle;
    //    LongSildeReady currentLongSildeReady = LongSildeReady::YesLong;
    //    ShortSildeReady currentShortSildeReady = ShortSildeReady::NoShort;

    //    Q_ENUM(ModStatus);
    //    Q_ENUM(LongSlideCardStatus);
    //    Q_ENUM(LongSildeStatus);
    //    Q_ENUM(WriterCardStatus);
    //    Q_ENUM(WriterStatus);
    //    Q_ENUM(SwingCardStatus);
    //    Q_ENUM(SwingStatus);
    //    Q_ENUM(ShortSildeCardStatus);
    //    Q_ENUM(ShortSlideStatus);
    //    Q_ENUM(LongSildeReady);
    //    Q_ENUM(ShortSildeReady);
signals:
    void OnReceiveMsg(QString,QString,int);
    void OnSendMsg(QString,QString,int);
public slots:

private slots:

private:
    QString ip;
    int port;
    QString id;
    QWidget *parent;
    bool IsStart=false;
    int msn=1;

    R600Printer *print;
public:
    bool isSimulated=false;

};
#endif // PRINT_RCK600_H
