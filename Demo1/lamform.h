#ifndef LAMFORM_H
#define LAMFORM_H

#include <QWidget>
#include "LamMod/lammod.h"
#include "QtNetwork"

namespace Ui {
class LamForm;
}

class LamForm : public QWidget
{
    Q_OBJECT

public:
    explicit LamForm(QWidget *parent = 0);
    ~LamForm();

public slots:
    //更新界面
    void OnRefresh(QString,QString,int);
    void OnRefreshSend(QString,QString,int);

private slots:
    void initForm();
    void initEquip();

    void on_pushButton_LamModInit_clicked();

    void on_pushButton_LamCleanSlide_clicked();

    void on_pushButton_LamCacheCardIn_clicked();

    void on_pushButton_LamCacheCardOut_clicked();

    void on_pushButton_LamCleanCardIn_clicked();

    void on_pushButton_LamCleanCardOut_clicked();

    void on_pushButton_LamShortSlide2In_clicked();

    void on_pushButton_LamShortSlideOut_clicked();
    void LamModChangedEvent();
private:
    Ui::LamForm *ui;
    //覆膜机构
    LamMod * lamMod;
    bool lamModChecked = false;
};

#endif // LAMFORM_H
