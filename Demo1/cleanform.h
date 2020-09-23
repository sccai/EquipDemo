#ifndef CLEANFORM_H
#define CLEANFORM_H

#include <QDialog>
#include <QMainWindow>
#include <QWidget>
#include <map>
#include "parawindow.h"
#include "QtNetwork"
#include "PrintMod/printmod.h"
#include "SendMod/sendmod.h"
#include "LamMod/lammod.h"
#include "SortMod/sortmod.h"
#include "CardSender/cardsender.h"

namespace Ui {
class CleanForm;
}

class CleanForm : public QWidget
{
    Q_OBJECT

public:
    explicit CleanForm(QWidget *parent = 0);
    ~CleanForm();
    int data_index=0;
    bool sortModChecked = false;
    bool sendCardModChecked = false;
    bool lamModChecked = false;
    QMap<QString, bool> dicPrintModChecked;

    QMutex   m_mutex;   //（可以是私有成员变量，也可以是全局变量）

    // QMutexLocker m_locker(&m_mutex);


    //槽
public slots:
    //更新界面
    void OnRefresh(QString,QString,int);
    void OnRefreshSend(QString,QString,int);
private slots:
    void initForm();
    void InitEquip();
    void on_pushButton_Stop_clicked();

    void on_pushButton_AllInit_clicked();

    void on_pushButton_Start_clicked();

    void on_pushButton_SortModInit_clicked();

    void on_pushButton_PM1_CLeanSlide_clicked();

    void on_pushButton_LamModInit_clicked();

    void on_pushButton_LamCleanSlide_clicked();

    void on_pushButton_LamOut_clicked();

    void on_pushButton_CardSenderInit_clicked();

    void on_pushButton_CardSender_clicked();

    void on_pushButton_CardSenderRequest_clicked();

    void on_pushButton_SmInit_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_StartWhile_clicked();

    void SendModChangedEvent();
    void PrintModChangedEvent();
    void LamModChangedEvent();
    void SortModChangedEvent();
    void FlipCardInFun();
    void FlipCardOutFun();
    void CleanCardOutFun();
    void CacheCardOutFun();
    void PrintMod2CardOutFun();
    void PrintMod3CardOutFun();
    void LamLongSlideCardInFun();
    void LamLongSlide2CardOutFun();
    void SortAdjustCardOutFun();
    void SortCardOutFun();
    void on_pushButton_SmFlipin_clicked();

    void on_pushButton_SmFlipout_clicked();

    void on_pushButton_PrintMod1_clicked();

    void on_pushButton_PrintMod2_clicked();

    void on_pushButton_PrintMod3_clicked();

private:
    bool initFinish=false;
    int minNum=0;
    int maxNum=100;
    Ui::CleanForm *ui;
    CardSender *cardsender;
    //进卡机构
    SendMod *sendMod;
    //打印机构1
    PrintMod *printMod1;
    PrintMod *printMod2;
    PrintMod *printMod3;
    //覆膜机构
    LamMod * lamMod;
    //分拣机构
    SortMod *sortMod;
    //开始自检
    bool startCheckLight = false;
    //持续进卡
    bool forloop = false;

    bool flipInFinish=false;
    bool cacheInFinish=false;
    bool flipCardIn=false;

};

#endif // CLEANFORM_H
