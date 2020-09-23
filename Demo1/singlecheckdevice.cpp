#include "iostream"

#include "singlecheckdevice.h"
#include "ui_singlecheckdevice.h"
#include "tool/commhelper.h"
#include "renderthread.h"

SingleCheckDevice::SingleCheckDevice(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleCheckDevice)
{
    ui->setupUi(this);
    ui->widget_Checking->setStyleSheet("border-image: url(:/image/self80_blue.png);");

    //ui->widget->setStyleSheet("background:transparent;border:10px dashed red;");
    //QLabel{border:10px dashed #242424;}
    //ui->widget->setStyleSheet("background:transparent;border:3px solid red;");
    //ui->label_2->setStyleSheet("background:transparent;border:3px solid red;");
}

SingleCheckDevice::~SingleCheckDevice()
{
    delete ui;
}

void SingleCheckDevice::SetValue(QString _label,int _id,QString _imgsource)
{
    ui->label->setText(_label);
    this->id=_id;
    ui->widget_Img->setStyleSheet("border:1px solid blue;");

    //_imgsource
    ui->widget_Img->setStyleSheet("border-image: url(:"+_imgsource+");");

    //ui->widget_Normal->setStyleSheet("QWidget#widget_Normal{background:rgb(255, 0, 0);}");//when set stylesheet,need Add child control's name

}

void SingleCheckDevice::Checking()
{
    qDebug()<<"Checking ="<<this->id;
    isStop=false;
    connect(&render,SIGNAL(notify(int,int)),this,SLOT(OnDealNotify(int,int)));
    render.DoRun(this->id);
}

void SingleCheckDevice::OnDealNotify(int i,int _id)
{
    if(this->id!=_id)
    {
        return;
    }
    if(i==0){
        ui->widget_Checking->setStyleSheet("border-image: url(:/image/self80_blue_s1.png);");
        //i=index+1;
        //CommHelper::Instance()->sleepme(1000);
    }
    else if(i==1){
        ui->widget_Checking->setStyleSheet("border-image: url(:/image/self80_blue_s2.png);");
        //index=index+1;
        //CommHelper::Instance()->sleepme(1000);
    }
    else if(i==2){
        ui->widget_Checking->setStyleSheet("border-image: url(:/image/self80_blue_s3.png);");
        //index=index+1;
        //CommHelper::Instance()->sleepme(1000);
    }
}

void SingleCheckDevice::FinishChecking()
{
    qDebug()<<"FinishChecking ="<<this->id;
    render.FinishRun();
    isStop=true;
    ui->widget_Checking->setStyleSheet("border-image: url(:/image/self80_blue.png);");
}
