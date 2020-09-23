#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "parawindow.h"
#include "QtNetwork"
#include "PrintMod/printmod.h"
#include "SendMod/sendmod.h"
#include "LamMod/lammod.h"
#include "SortMod/sortmod.h"
#include "cleanform.h"
#include "QFont"

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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool sortModChecked = false;
    bool sendCardModChecked = false;
    bool lamModChecked = false;
    QMap<QString, bool> dicPrintModChecked;
    enum ApplicationStatus {Startup=0, Pause,Stop,NotInit,InitFinish};
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
    void InitSlot();
    void ModChange(QString);
    void on_pushButton_SmInit_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_SmFlipin_clicked();

    void on_pushButton_SmFlipout_clicked();

    void on_pushButton_SmCleanIn_clicked();

    void on_pushButton_SmCleanOut_clicked();

    void on_pushButton_SmCleanCache_clicked();

    void on_pushButton_PrintMod1_clicked();

    void on_pushButton_LamModInit_clicked();

    void on_pushButton_SortModInit_clicked();

    void title_closeBtn_clicked();
    void title_minBtn_clicked();
    void title_maxBtn_clicked();
    void changeLangue();
    void changeTheme();
    void funcParamter();
    void funcNav();
    void funcConsumables();
    void on_pushButton_SendCardInit_clicked();

    void on_pushButton_SendCard_clicked();

    void on_pushButton_Pause_clicked();

    void on_pushButton_Start_clicked();

    void on_pushButton_AllInit_clicked();

    void on_pushButton_SendCardInit_2_clicked();

    void on_pushButton_ConnectDB_clicked();

private:
    void createTitle();
    void createMainUI();
    void createTitleMenu();
    void retranslateUI();

private:
    ApplicationStatus currentStatus=ApplicationStatus::NotInit;
    Ui::MainWindow *ui;
    ParaWindow *dialog;
    CleanForm *cleanform;
    QFont iconFont;
    QVBoxLayout *mainLayout;
    QHBoxLayout *statusLayout;
    int minNum=0;
    int maxNum=100;
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
};

#endif // MAINWINDOW_H
