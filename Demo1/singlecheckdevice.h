#ifndef SINGLECHECKDEVICE_H
#define SINGLECHECKDEVICE_H

#include <QWidget>
#include <QThread>
#include "renderthread.h"

namespace Ui {
class SingleCheckDevice;
}

class SingleCheckDevice : public QWidget
{
    Q_OBJECT

public:
    explicit SingleCheckDevice(QWidget *parent = nullptr);
    ~SingleCheckDevice();
    void Checking();
    void FinishChecking();
    void SetValue(QString,int,QString);
private:
    Ui::SingleCheckDevice *ui;
    QString Text;
    volatile bool isStop=true;       //isStop是易失性变量，需要用volatile进行申明
    RenderThread render;
    int id;

public slots:
    //处理信号的事件
    void OnDealNotify(int,int);
};

#endif // SINGLECHECKDEVICE_H
