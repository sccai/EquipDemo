#ifndef NEWMAINWINDOW_H
#define NEWMAINWINDOW_H

#include <QWidget>
#include "parawindow.h"
#include "QtNetwork"
#include "PrintMod/printmod.h"
#include "SendMod/sendmod.h"
#include "LamMod/lammod.h"
#include "SortMod/sortmod.h"
#include "cleanform.h"
#include "QFont"
#include "control/cthermometer.h"
#include "CardSender/cardsender.h"
#include "Print/print_rck600.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QMenu;
class QActionGroup;
class QTranslator;
class QGroupBox;
class QLineEdit;
class QScrollBar;
class QSlider;
class QProgressBar;
class QCheckBox;
class QRadioButton;
class QLineEdit;
QT_END_NAMESPACE

namespace Ui {
class NewMainWindow;
}

class NewMainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NewMainWindow(QWidget *parent = 0);
    ~NewMainWindow();
    bool sortModChecked = false;
    bool sendCardModChecked = false;
    bool lamModChecked = false;
    QMap<QString, bool> dicPrintModChecked;
    enum ApplicationStatus {Startup=0, Pause,Stop,NotInit,InitFinish};
    QMutex   m_mutex;   //（可以是私有成员变量，也可以是全局变量）
protected:
    bool eventFilter(QObject *obj, QEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    //槽
public slots:
    //更新界面
    void OnRefresh(QString,QString,int);
    void OnRefreshSend(QString,QString,int);
private slots:
    void InitEquip();
    void InitForm();
    void SendModChangedEvent();
    void PrintModChangedEvent(QString);
    void LamModChangedEvent();
    void SortModChangedEvent();
    void FlipCardInFun();
    void FlipCardOutFun();
    void CleanCardInFun();
    void CleanCardOutFun();
    void CacheCardOutFun();
    void PrintMod2CardOutFun();
    void PrintMod3CardOutFun();
    void LamLongSlideCardInFun();
    void LamLongSlide2CardOutFun();
    void SortAdjustCardOutFun();
    void SortCardOutFun();
    void SortCheckCardInFun();
    //打印工位进卡、出卡
    void CardInAndCardOut(int);
    //转向进卡
    void Printer1FlipCardInFun();
    //转向进卡
    void Printer2FlipCardInFun();
    void FeedCardAndPrint(int);
    //打印机进卡
    void Printer1CardInFun();
    void Printer2CardInFun();
    //打印机出卡
    void Printer1CardOutFun();
    void Printer2CardOutFun();
    void on_pushButton_SmInit_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_SmFlipin_clicked();

    void on_pushButton_SmFlipout_clicked();

    void on_pushButton_SmCleanIn_clicked();

    void on_pushButton_SmCleanOut_clicked();

    void on_pushButton_SmCleanCache_clicked();

    void on_pushButton_LamModInit_clicked();

    void on_pushButton_SortModInit_clicked();

    void title_closeBtn_clicked();
    void title_minBtn_clicked();
    void title_maxBtn_clicked();
    void changeLangue();
    void changeTheme();
    void funcParamter();
    void updateParamter(ParamterClass *para);
    void funcNav();
    void funcConsumables();
    void on_pushButton_SendCardInit_clicked();

    void on_pushButton_SendCard_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_Start_clicked();

    void on_pushButton_AllInit_clicked();

    bool IsLongSlidesReady(int,int);

    void on_pushButton_GetStatus_clicked();

    void on_pushButton_Retrun_clicked();

private:
    void CreateTitle();
    void CreateMainUI();
    //创建标题栏菜单内容
    void CreateTitleMenu();
    void RetranslateUI();
    void RetranslateUIEnglish();
    void InitSlot();
    void InitStatusImage();
    //设备消耗
    void InitEquipConsume();
    //参数设置
    bool isPrint1=false;//打印机1是否打印
    bool isPrint2=false;//打印机2是否打印
    bool isPrint3=false;//打印机3是否打印
    bool isUsePrintMod1=true;//是否启动打印模块1
    bool isUsePrintMod2=false;//是否启动打印模块2
    bool isUsePrintMod3=false;//是否启动打印模块3
    bool isUseLam=false;//是否启动覆膜
    int soltIndex=1;//出卡槽
private:
    ApplicationStatus currentStatus=ApplicationStatus::NotInit;
    Ui::NewMainWindow *ui;
    ParaWindow *dialog;
    CleanForm *cleanform;
    QFont iconFont;
    QVBoxLayout *mainLayout;
    QHBoxLayout *statusLayout;
    int minNum=0;
    int maxNum=100;
    bool initFinish=false;
    //发卡器
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
    //打印机
    Print_RCK600 *printer1;
    Print_RCK600 *printer2;
    //内置打印图片
    //QString frontimagepath=":/image/CETeam/image-front.png";//添加到项目资源，相对路径
    QString frontimagepath="/home/aisino/project/EquipDemo/Demo1/image/CETeam/image-front.png";
    //QString backimagepath=":/image/CETeam/image-back.png";//添加到项目资源，相对路径
    QString backimagepath="/home/aisino/project/EquipDemo/Demo1/image/CETeam/image-back.png";

    QLabel *title_icon;
    QLabel *title_name;
    QPushButton *title_minBtn;
    QPushButton *title_maxBtn;
    QPushButton *title_closeBtn;
    QPushButton *title_menuBtn;
    QWidget *title_widget;
    QHBoxLayout *title_layout;
    QWidget *titleBtn_widget;
    QHBoxLayout *titleBtn_layout;
    QMenu *title_menu;
    QMenu *langue_menu;
    QMenu *theme_menu;
    QActionGroup *langueGroup;
    QActionGroup *themeGroup;
    QAction *setChinese;
    QAction *setEnglish;
    QAction *setBlue;
    QAction *setBlack;
    QAction *setPara;
    QAction *setNav;
    QAction *setConsumables;

    QTranslator *translator;
    bool isMousePressed;
    QPoint mousePressPos;
    int windowWidth;
    //持续进卡
    bool forloop = false;
    bool flipInFinish=false;
    bool cacheInFinish=false;
    bool flipCardIn=false;
    //变量
    bool syncCardInAndCardOut=false;
    bool syncPrintFlipCardIn=false;
    bool syncPrint2FlipCardIn=false;
    bool syncPrinterCardIn=false;
    bool syncPrinter2CardIn=false;
    bool syncPrinterLoadTask=false;
    bool syncPrinter2LoadTask=false;
    bool syncPrinterCardOut=false;
    bool syncPrinter2CardOut=false;
    bool syncLamCleanSlideCardIn=false;
};

#endif // NEWMAINWINDOW_H
