#ifndef CONCURRENTFORM_H
#define CONCURRENTFORM_H

#include <QWidget>

namespace Ui {
class ConcurrentForm;
}

class ConcurrentForm : public QWidget
{
    Q_OBJECT

public:
    explicit ConcurrentForm(QWidget *parent = 0);
    ~ConcurrentForm();
    void star();//多线程启动函数，在原有的代码基础上增加该函数
    void xunhuan();//死循环函数，用这个函数代替原有代码的函数
    void fun1(int num);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::ConcurrentForm *ui;
    int myEnable;//标志位，用于退出死循环操作
      int myLock;//标志位，用于退出死循环操作

};

#endif // CONCURRENTFORM_H
