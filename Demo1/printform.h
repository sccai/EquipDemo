#ifndef PRINTFORM_H
#define PRINTFORM_H

#include <QWidget>
#include "printform.h"
#include "Print/print_rck600.h"

namespace Ui {
class PrintForm;
}

class PrintForm : public QWidget
{
    Q_OBJECT

public:
    explicit PrintForm(QWidget *parent = 0);
    ~PrintForm();

private slots:
    void on_pushButton_InitDevice_clicked();

    void on_pushButton_LoadTask_clicked();

    void on_pushButton_FeedPrint_clicked();

    void on_pushButton_EjectCard_clicked();

    void on_pushButton_GetStatus_clicked();

    void on_pushButton_BackImg_clicked();

    void on_pushButton_FrontImg_clicked();

    //槽
    void on_chkSimu_clicked();

    void on_pushButton_RunLoad_clicked();

    void on_pushButton_RunFeed_clicked();

    void on_pushButton_RunEjectCard_clicked();
    void RunLoad();
    void RunFeed();
    void RunEjectCard();

public slots:
    //更新界面
    void OnRefresh(QString,QString,int);
    void OnRefreshSend(QString,QString,int);

private:
    Ui::PrintForm *ui;
    Print_RCK600 *print_600;
};

#endif // PRINTFORM_H



