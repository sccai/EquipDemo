#ifndef SORTMOD_H
#define SORTMOD_H

#include <QObject>
#include "QLabel"
#include "QApplication"
#include "QtNetwork"
#include "QMessageBox"
#include "iostream"
#include "string"
#include "QDebug"
#include "QTime"

class SortMod : public QObject
{
    Q_OBJECT
public:
    explicit SortMod(QObject *parent = 0);
    ~SortMod();
    explicit SortMod(QString ip,int port,QWidget *_parent);

    void InitDevice();
    void StopDevice();
    void PauseDevice();
    void SetCurrentStatus(QStringList &ba);
    void AdjustCardIn();
    void AdjustCardOut();
    void VerifyCardIn();
    void SlotCardOut(int);//正常出卡
    void SlotCardEject(int);//异常提卡
    void LightCheckControl(int color, int lightType);
    void LightCheck();
    void LightControl(int color, int lightType);
    void LightClose();
    enum ModStatus {Startup=0, Closed};
    enum AdjustCardStatus {HaveCard=0, NoCard};
    enum AdjustPosStatus {Busy=0, Idle};
    enum VerifyPosStatus {VerifyBusy=0, VerifyIdle};
    enum VerifyCardStatus {VerifyHaveCard=0, VerifyNoCard};
    enum SortPosStatus {SortBusy=0,SortIdle};

    enum PhotoCardStatus {PhotoHaveCard=0, PhotoNoCard};
    enum PhotoStatus {PhotoBusy=0, PhotoIdle};

    ModStatus currentOutcardModStatus =ModStatus::Closed;
    AdjustCardStatus currentAdjustCardStatus = AdjustCardStatus::NoCard;
    AdjustPosStatus currentAdjustPosStatus = AdjustPosStatus::Idle;
    VerifyCardStatus currentVerifyCardStatus = VerifyCardStatus::VerifyNoCard;
    VerifyPosStatus currentVerifyPosStatus = VerifyPosStatus::VerifyIdle;
    SortPosStatus currentSortPosStatus = SortPosStatus::SortIdle;
    //2020-09-17 去掉CIS设备，增加摄像头机构
    PhotoCardStatus currentPhotoCardStatus = PhotoCardStatus::PhotoNoCard;

    PhotoStatus currentPhotoStatus = PhotoStatus::PhotoIdle;
signals:
    void OnReceiveMsg(QString,QString,int);
    void OnSendMsg(QString,QString,int);
public slots:

private slots:
    void SendMsg(QString HexString);
    void SendLightMsg(QString HexString,int msn);
    void Socket_Read_Data();
    void socket_Disconnected();
private:
    QString ip;
    int port;
    int colorindex=0;
    QWidget *parent;
    bool IsStart=false;
    QTcpSocket *client;
    int msn=1;
    bool isStopCheckLight = false;
    QString START="AA 55 AA 01";//程序启动
    QString STOP = "AA 55 AC 01";
    QString ADJUSTCARDIN = "AA 55 40 01"; //矫正进卡
    QString CISCARDIN = "AA 55 41 01"; // 矫正出卡
    QString VERIFYCARDIN = "AA 55 42 01"; //核验进卡
    QString SLOT1OUTCARD = "AA 55 43 01"; //卡槽1进卡
    QString SLOT1EJECTCARD = "AA 55 44 01"; //卡槽1坏卡
    QString SLOT2OUTCARD = "AA 55 45 01"; //卡槽2进卡
    QString SLOT2EJECTCARD = "AA 55 46 01"; //卡槽2坏卡
    QString SLOT3OUTCARD = "AA 55 47 01"; //卡槽3进卡
    QString SLOT3EJECTCARD = "AA 55 48 01"; //卡槽3坏卡
    QString SLOT4OUTCARD = "AA 55 49 01"; //卡槽4进卡
    QString SLOT4EJECTCARD = "AA 55 4A 01"; //卡槽4坏卡
    QString SENSORCHECK = "AA 55 70 01";//查询传感器状态
    QString ADJUSTSETTING = "AA 55 4B 01";//设置校正强度
    QString LIGHTSWITCH = "AA 55 0A 01";//红黄绿灯开关
    QString LIGHTFLICKER = "AA 55 0B 01";//红黄绿灯闪烁
    QString FAILRECOVER = "AA 55 52 01";//分拣卡槽故障恢复
};
#endif // SORTMOD_H
