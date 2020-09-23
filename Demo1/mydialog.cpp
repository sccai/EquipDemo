#include "mydialog.h"
#include "ui_mydialog.h"
#include "iostream"
#include "QDebug"
#include "flatui.h"

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    this->initForm();
}
void MyDialog::initForm()
{
    this->setStyleSheet("*{outline:0px;}QWidget#MyDialog{background:#FFFFFF;}");//点击单选按钮时出现的无色背景框

    FlatUI::Instance()->setLineEditQss(ui->txt1);
    FlatUI::Instance()->setLineEditQss(ui->txt2, 5, 2, "#DCE4EC", "#1ABC9C");
    FlatUI::Instance()->setLineEditQss(ui->txt3, 3, 1, "#DCE4EC", "#3498DB");
    FlatUI::Instance()->setLineEditQss(ui->txt4, 3, 1, "#DCE4EC", "#E74C3C");

    FlatUI::Instance()->setRadioButtonQss(ui->rbtn1);
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn2, 8, "#D7DBDE", "#1ABC9C");
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn3, 8, "#D7DBDE", "#3498DB");
    FlatUI::Instance()->setRadioButtonQss(ui->rbtn4, 8, "#D7DBDE", "#E74C3C");


    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Save, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->pushButton_Cancle, 5, 8, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");

    QPixmap icon1(":/image/main_config.png");
    ui->pushButton_Save->setIcon(icon1);

    //开关按钮
    ui->solt1_switch->setSize(90,25);
    ui->solt2_switch->setSize(90,28);
    ui->solt3_switch->setSize(90,28);
    ui->solt4_switch->setSize(90,28);
    ui->solt1_switch->setButtonStyle(ImageSwitch::ButtonStyle_1);
    ui->solt2_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    ui->solt3_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    ui->solt4_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    //设置右下角有个三角图标可以改变窗口大小
    this->setSizeGripEnabled(true);
}

MyDialog::~MyDialog()
{
    delete ui;
}

QByteArray HexStringToByteArrayDD(QString HexString)
 {
     bool ok;
     QByteArray ret;
     HexString = HexString.trimmed();
     HexString = HexString.simplified();
     QStringList sl = HexString.split(" ");

     foreach (QString s, sl) {
         if(!s.isEmpty()) {
             char c = s.toInt(&ok,16)&0xFF;
             if(ok){
                 ret.append(c);
             }else{
                 qDebug()<<"非法的16进制字符："<<s;
             }
         }
     }
     return ret;
 }


void MyDialog::SetText(const QString &text)
{
    std::cout <<"HexString";
    std::cout << text.toStdString() <<std::endl;
    ui->label->setText(text);
    //ui->label->setText(QString::fromLocal8Bit("大家"));
   // ui->label->setText("asdasd");
}


void MyDialog::on_pushButton_Cancle_clicked()
{
    close();
}

void MyDialog::on_pushButton_Save_clicked()
{
    close();
}
