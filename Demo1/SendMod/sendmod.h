#ifndef SENDMOD_H
#define SENDMOD_H

#include <QObject>
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"
#include "QMap"

class SendMod : public QObject
{
    Q_OBJECT
public:
    explicit SendMod(QObject *parent = 0);
    ~SendMod();
    explicit SendMod(QString ip,int port,QWidget *_parent);
    void InitDevice();
    void StopDevice();
    void PauseDevice();
    void FlipCardInFun();
    void FlipCardOutFun();
    void CleanCardInFun();
    void CleanCardOutFun();
    void CardCacheOutFun();
    void SetCurrentStatus(QStringList &ba);
    void CmdFinish(QString cmd);
    enum ModStatus {Startup=0, Closed};
    enum CardStatus {HaveCard=0, NoCard};
    enum FlipStatus {Busy=0, Idle};
    enum CleanCardStatus {CleanHaveCard=0, CleanNoCard};
    enum CleanStatus {CleanBusy=0, CleanIdle};
    enum CacheCardStatus {CacheHaveCard=0, CacheNoCard};
    enum CacheStatus {CacheBusy=0, CacheIdle};

    enum PhotoStatus {PhotoBusy=0, PhotoIdle};
    enum PhotoCardStatus {PhotoHaveCard=0, PhotoNoCard};
    enum CommandStatus {Runing=0, Finish};
    //属性
    ModStatus currentSendCardModStatus=ModStatus::Closed;

    CardStatus currentRotationFlipCardStatus = CardStatus::NoCard;

    FlipStatus currentRotationFlipStatus = FlipStatus::Idle;

    CleanCardStatus currentCleanCardStatus = CleanCardStatus::CleanNoCard;

    CleanStatus currentCleanStatus = CleanStatus::CleanIdle;

    CacheCardStatus currentCacheCardStatus = CacheCardStatus::CacheNoCard;

    CacheStatus currentCacheStatus = CacheStatus::CacheIdle;
    //拍照工位  2020-09-17 去掉CIS设备，增加摄像头机构
    PhotoStatus currentPhotoStatus = PhotoStatus::PhotoIdle;
    //拍照工位有卡 2020-09-17 去掉CIS设备，增加摄像头机构
    PhotoCardStatus currentPhotoCardStatus = PhotoCardStatus::PhotoNoCard;

    CommandStatus currentCleanCommandStatus = CommandStatus::Runing;

    Q_ENUM(ModStatus);
    Q_ENUM(CardStatus);
    Q_ENUM(FlipStatus);
    Q_ENUM(CleanCardStatus);
    Q_ENUM(CleanStatus);
    Q_ENUM(CacheCardStatus);
    Q_ENUM(CacheStatus);
    Q_ENUM(PhotoStatus);
    Q_ENUM(PhotoCardStatus);
    Q_ENUM(CommandStatus);
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
    QMap<QString, QString> mapCmd;
    QString START="AA 55 AA 01";//程序启动
    QString STOP = "AA 55 AC 01";
    QString ROTATIONFLIPCARDIN = "AA 55 01 01";//转向翻转机构进卡
    QString ROTATIONFLIPCARDOUT = "AA 55 02 01";//转向翻转机构出卡，CIS设备进卡
    QString FLIPCARDBACK = "AA 55 03 01";//卡片返回转向翻转机构并翻转
    QString ROTATIONCARDBACK = "AA 55 04 01";//卡片返回转向翻转机构并转向
    QString ROTATIONFLIPCARDBACK = "AA 55 05 01";//卡片返回转向翻转机构翻转并转向
    QString CLEANCARDIN = "AA 55 06 01";//卡片到清洁机构并清洁卡片
    QString CLEANCARDOUT = "AA 55 07 01";//清洁机构出卡
    QString CLEANWHEEL = "AA 55 08 01";//清洁机构清洁滚轮
    QString CACHECARDOUT = "AA 55 09 01";//缓冲机构出卡
    QString TOCLEANCARD = "AA 55 0C 01";//卡片直接到清洁机构
    QString SENSORCHECK = "AA 55 70 01";//查询传感器状态
    QString RISE = "AA 55 0A 01";//送料机构等待接卡
    QString PUTCARD = "AA 55 0B 01";//送料机构开始放卡
    QString DROP = "AA 55 0D 01";//送料机构开始压卡
    QString RESET = "AA 55 0E 01";//送料机构复位
    QString RECOVERYCLEANCARDIN = "AA 55 13 01";//清洁机构进卡复位
    QString RECOVERYCLEANCARDOUT = "AA 55 14 01";//清洁机构出卡复位
    QString RECOVERYROTATIONFLIP = "AA 55 12 01";//转向机构出卡复位
    QString CLEANTRACK = "AA 55 0C 01";//清洁机构并清洁轨道



public:
    int flipdata=0;
};

#endif // SENDMOD_H
