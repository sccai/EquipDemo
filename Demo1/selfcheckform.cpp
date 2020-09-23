#include "selfcheckform.h"
#include "ui_selfcheckform.h"
#include "QWidget"
#include "QPainter"
#include "tool/commhelper.h"
#include "singlecheckdevice.h"
#include "flatui.h"
#include "control/DRoundProgressBar.h"

SelfCheckForm::SelfCheckForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelfCheckForm)
{
    ui->setupUi(this);
    this->initForm();
    this->InitEquip();

}

SelfCheckForm::~SelfCheckForm()
{
    delete ui;
}

void SelfCheckForm::initForm()
{
    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    //qss.append(QString("*{outline:0px;color:#ffffff;}"));
    qss.append(QString("*{outline:0px;}"));
    this->setStyleSheet(qss.join(""));

    //border:3px solid #006ab4;border-radius:10px
    ui->widget_Top->setStyleSheet("QWidget#widget_Top{background:#e9e9e9;}");//when set stylesheet,need Add child control's name

    ui->widget_Parent->setStyleSheet("QWidget#widget_Parent{background:rgb(255, 255, 255);border:3px solid #006ab4;border-radius:10px}");//when set stylesheet,need Add child control's name
    ui->label->setStyleSheet("color:black");

//    QColor c(255,0,255);
//    //QColor >> QRgb(uint)
//    QRgb mRgb = qRgb(c.red(),c.green(),c.blue());
//    //QRgb(uint) >> QColor;
//    QColor mColor = QColor(mRgb);
//    //QRgb(uint) >> QString;
//    QString mRgbStr = QString::number(mRgb,16);
//    //QString >> unint >> QColor
//    QColor color2(mRgbStr.toUInt(NULL,16));
//    qDebug() << mRgb << mColor << mRgbStr;

    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    QPalette p1;//字体颜色
    p1.setBrush(QPalette::AlternateBase, Qt::white);//内圆背景色
    p1.setColor(QPalette::Text, Qt::white);
    QPalette p2(p1);//继承p1的属性值
    //p2.setBrush(QPalette::Base, Qt::red);
    QColor c("#006ab4");//自定义颜色
    QColor ca("#00cafd");//蓝色
    QColor carm("#ff0000");//告警色
    QColor cbg("#e9e9e9");//灰色
    p2.setColor(QPalette::Text, ca);
    p2.setColor(QPalette::Highlight, Qt::green); //已完成覆盖的圆环颜色
    p2.setColor(QPalette::Background, cbg);//圆环四周覆盖的背景色
    //p2.setColor(QPalette::Shadow, Qt::yellow);
    //p2.setColor(QPalette::Window, Qt::black);//圆环之外的颜色
    //ui->roundProgressBar_DeviceCheck->setFormat("%v");
    //ui->roundProgressBar_DeviceCheck->setDataColors(gradientPoints);//根据百分比改变圆环的颜色
    ui->roundProgressBar_DeviceCheck->setDecimals(0);
    ui->roundProgressBar_DeviceCheck->setStartAngle(90);
    ui->roundProgressBar_DeviceCheck->setPalette(p2);
    ui->roundProgressBar_DeviceCheck->setValue(4);

    FlatUI::Instance()->setPushButtonQss(ui->pushButton, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_2);


    QPalette p3;
    p3.setBrush(QPalette::AlternateBase, Qt::blue);//内圆背景色
    p3.setColor(QPalette::Text, Qt::black);
    p3.setBrush(QPalette::Base, Qt::white);
    p3.setBrush(QPalette::Dark, Qt::yellow);
    p3.setBrush(QPalette::Link, Qt::gray);
    p3.setColor(QPalette::Highlight, Qt::green); //已完成覆盖的圆环颜色
    p3.setColor(QPalette::Background,Qt::red);//圆环四周覆盖的背景色

    ui->roundProgressBar2->setBarStyle(DRoundProgressBar::BarStyle::StyleLine);
    ui->roundProgressBar2->setOutlinePenWidth(10);//外环的宽度
    ui->roundProgressBar2->setDataPenWidth(8);//内环的宽度
    ui->roundProgressBar2->setDecimals(0);
    ui->roundProgressBar2->setPalette(p3);
    ui->roundProgressBar2->setValue(1);


    ui->roundProgressBar2->hide();
}

void SelfCheckForm::InitEquip()
{
    //addWidget(QWidget , int , int , int , int)总,
    //第一个int变量是widget的起始行数即(row),下一个是起始列数(即column),下一个是为所跨的行数,最后一个是所跨的列数.
    //需要注意的是,在widget的起始行数不为0时,所跨行数最小不可以为0,最少必须是widget所在的行数.列数同样如此.否则控制台将报错
    int num=1;
    for(int j=1;j<3;j++)
    {  for(int i=1;i<5;i++)
        {
            SingleCheckDevice *singledev=new SingleCheckDevice;
            if(j==1)
            {
               singledev->SetValue("发卡器["+QString::number(j)+","+QString::number(i)+"]",num,"/image/CETeam/cardsend.png");
            }
            else{
               singledev->SetValue("打印机["+QString::number(j)+","+QString::number(i)+"]",num,"/image/CETeam/printer.png");
            }
            //ui->gridLayout->addWidget(singledev,1,4);//row:2,col:4
            ui->gridLayout->addWidget(singledev,j,i);
            singVec.append(singledev);
            num++;
        }
    }
    ui->roundProgressBar_DeviceCheck->setRange(0,singVec.length());
    ui->roundProgressBar2->setRange(0,singVec.length());
}

void SelfCheckForm::on_pushButton_clicked()
{
    for (int i=0;i<singVec.length();i++) {
        SingleCheckDevice *temp=singVec.at(i);

        temp->Checking();

        CommHelper::Instance()->sleepme(2000);

        temp->FinishChecking();

        ui->roundProgressBar_DeviceCheck->setValue(i+1);
        ui->roundProgressBar2->setValue(i+1);
    }
}

void SelfCheckForm::on_pushButton_2_clicked()
{
    for (int i=0;i<singVec.length();i++) {

        qDebug()<<"FinishChecking ="<<i;
        SingleCheckDevice *temp=singVec.at(i);
        temp->FinishChecking();
    }
}

