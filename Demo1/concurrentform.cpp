#include "concurrentform.h"
#include "ui_concurrentform.h"
#include "QDebug"
#include "QtConcurrent"//要记得添加该头文件
#include <QThread>
#include "sys/stat.h"



ConcurrentForm::ConcurrentForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConcurrentForm)
{
    ui->setupUi(this);
    myEnable = 0;//死循环标志位
    myLock=0;

}

ConcurrentForm::~ConcurrentForm()
{
    delete ui;
}
//start
void ConcurrentForm::on_pushButton_clicked()
{
    myEnable = 1;
    xunhuan(); //非多线程执行死循环

}
//duo
void ConcurrentForm::on_pushButton_2_clicked()
{
    myEnable = 1;
    star();//多线程启动死循环
}
//stop
void ConcurrentForm::on_pushButton_3_clicked()
{
    myEnable=0;//标志位置零，退出死循环
    qDebug()<<"退出死循环!";
}

void ConcurrentForm::xunhuan()//死循环操作，代替原有代码的函数功能
{
    int i=0;
    while(myEnable)
    {
        i++;
        QTime t;
        t.start();
        while(t.elapsed()<1000);

        //sleep(1000);
        qDebug()<<i;
    }
}
void ConcurrentForm::star()//启动函数是需要在原有代码基础上增加
{
    QtConcurrent::run(this,&ConcurrentForm::xunhuan);//多线程执行死循环启动，可以带参数，具体格式可以查阅网上其它资料
}

void ConcurrentForm::on_pushButton_4_clicked()
{

}

void ConcurrentForm::on_pushButton_5_clicked()
{
    //相当与机构每秒钟返回的事件
    qDebug()<<"myLock ="<<myLock;
    qDebug()<<"Start";

    //传递参数
    QtConcurrent::run(this,&ConcurrentForm::fun1,1);

    qDebug()<<"End";
}
void ConcurrentForm::fun1(int num)//死循环操作，代替原有代码的函数功能
{
    if( myLock==1)
        return;

    qDebug()<<"sub-开始";
    qDebug()<<num;
    myLock=1;
    QTime t;
    t.start();
    while(t.elapsed()<3000);

    qDebug()<<"sub-结束";
    myLock=0;
}
