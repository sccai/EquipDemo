#ifndef LAMMOD_H
#define LAMMOD_H

#include <QObject>
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"

class LamMod : public QObject
{
    Q_OBJECT
public:
    explicit LamMod(QObject *parent = 0);
    ~LamMod();
    explicit LamMod(QString ip,int port,QWidget *_parent);

    void InitDevice();
    void StopDevice();
    void PauseDevice();
    void SetCurrentStatus(QStringList &ba);
    //清洁轨道
    void CleanSlide();

    //前缓冲进卡
    void FrontCacheCardIn();
    //前轨道进卡
    void LongSlideCardIn();

    //可擦写进卡
    void EPrintCardIn();
    //可擦写出卡
    void EPrintCardOut();

    //清洁进卡
    void CleanCardIn();
    //覆膜机进卡
    void LamCardIn();
    //长轨道２进卡
    void LongSlide2In();
    //长轨道２出卡
    void LongSlide2Out();

    //传感器属性
    enum ModStatus {Startup=0, Closed};
    enum FrontCacheCardStatus {HaveCard=0, NoCard};
    enum FrontCacheStatus {Busy=0, Idle};
    enum LongSildeStatus {LongBusy=0, LongIdle};
    enum LongSildeCardStatus {LongSildeHaveCard=0, LongSildeNoCard};
    //enum ReaderCardStatus {ReaderHaveCard=0,ReaderNoCard};
    //enum ReaderStatus {ReaderBusy=0, ReaderIdle};
    enum CleanCardStatus {CleanHaveCard=0, CleanNoCard};
    enum CleanStatus {CleanBusy=0, CleanIdle};
    enum LongSilde2Status {Long2Busy=0, Long2Idle};
    enum LongSilde2CardStatus {LongSilde2HaveCard=0, LongSilde2NoCard};
    enum PauseButtonStatus{Press=0, Normal};
    enum Cache2CardStatus {Cache2HaveCard=0, Cache2NoCard};
    enum Cache2Status {Cache2Busy=0, Cache2Idle};

    ModStatus currentErasableLaminationModStatus = ModStatus::Closed;
    FrontCacheCardStatus currentFrontCacheCardStatus = FrontCacheCardStatus::NoCard;
    FrontCacheStatus currentFrontCacheStatus = FrontCacheStatus::Idle;
    LongSildeStatus currentLongSildeStatus =LongSildeStatus::LongIdle;
    //ReaderCardStatus currentReaderCardStatus = ReaderCardStatus::ReaderNoCard;
    //ReaderStatus currentReaderStatus = ReaderStatus::ReaderIdle;
    CleanCardStatus currentCleanCardStatus = CleanCardStatus::CleanNoCard;
    CleanStatus currentCleanStatus = CleanStatus::CleanIdle;
    LongSilde2CardStatus currentLongSilde2CardStatus = LongSilde2CardStatus::LongSilde2NoCard;
    LongSilde2Status currentLongSilde2Status = LongSilde2Status::Long2Idle;
    LongSildeCardStatus currentLongSildeCardStatus = LongSildeCardStatus::LongSildeNoCard;
    PauseButtonStatus currentPauseButtonStatus = PauseButtonStatus::Normal;

    Cache2CardStatus currentCache2CardStatus = Cache2CardStatus::Cache2NoCard;
    Cache2Status currentCache2Status = Cache2Status::Cache2Idle;

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

    QWidget *parent;
    bool IsStart=false;
    QTcpSocket *client;
    int msn=1;
    QString START="AA 55 AA 01";//程序启动
    QString STOP = "AA 55 AC 01";
    QString FRONTCACHECARDIN = "AA 55 30 01";//前缓冲工位进卡
    QString FRONTCACHETOLONGSILDE = "AA 55 31 01";//缓冲工位1出卡到轨道1
    QString ERASABLEPRINTERCARDIN = "AA 55 32 01";//可擦写打印机进卡
    QString ROTATIONCARDINANDCLEAN = "AA 55 33 01";//翻转机构进卡并翻转与清洁
    QString LAMINATORCARDIN = "AA 55 34 01";//覆膜机进卡
    QString CLEANWHEEL = "AA 55 35 01";//清洁机构清洁滚轮
    QString CACHE2CARDIN= "AA 55 3A 01";//缓冲工位2进卡
    QString LONGSILDE2IN= "AA 55 36 01";//长轨道2进卡
    QString LONGSILDE2OUT = "AA 55 37 01";//长轨道2出卡
    QString ERASEPRINTERCLEANIN = "AA 55 39 01";//签注打印机清洁进卡
    QString ERASEPRINTERSETCLEANCARD = "AA 55 38 01";//签注打印机清洁放卡
    QString SENSORCHECK = "AA 55 70 01";//查询传感器状态
    QString LAMINATIONMODCLEAN = "AA 55 3E 01";// 机构清洁
    QString RECOVERYFRONTCACHE = "AA 55 61 01";//故障恢复-缓冲1机构
    QString RECOVERYLONGSILDE = "AA 55 62 01";//故障恢复-轨道1机构
    QString RECOVERYCLEANCARDIN = "AA 55 63 01";//清洁机构进卡复位
    QString RECOVERYCACHE2 = "AA 55 64 01";//缓冲2机构
    QString RECOVERYLONGSILDE2IN = "AA 55 65 01";//轨道2进卡复位
    QString SETCLEANCOUNT = "AA 55 CE 01";//设置清洁次数

};
#endif // LAMMOD_H
