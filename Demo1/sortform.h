#ifndef SORTFORM_H
#define SORTFORM_H

#include <QWidget>
#include "SortMod/sortmod.h"

namespace Ui {
class SortForm;
}

class SortForm : public QWidget
{
    Q_OBJECT

public:
    explicit SortForm(QWidget *parent = 0);
    ~SortForm();
bool sortModChecked = false;

public slots:
    //更新界面
    void OnRefresh(QString,QString,int);
    void OnRefreshSend(QString,QString,int);

private slots:
    void initForm();
    void initEquip();
    void on_pushButton_SortModInit_clicked();

    void on_pushButton_SortMod_Light_clicked();

    void on_pushButton_SortMod_Light_Close_clicked();

    void on_pushButton_Sort_AdjustIn_clicked();

    void on_pushButton_Sort_AdjustOut_clicked();

    void on_pushButton_Sort_LongOut_clicked();

     void SortModChangedEvent();

     void on_pushButton_Sort_OCRReaderIn_clicked();

     void on_pushButton_Sort_VerifyIn_clicked();

private:
    Ui::SortForm *ui;
    //分拣机构
    SortMod *sortMod;

    //控制灯
    bool startCheckLight = false;
};

#endif // SORTFORM_H
