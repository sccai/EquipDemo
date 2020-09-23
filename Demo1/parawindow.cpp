#include "parawindow.h"
#include "ui_parawindow.h"
#include "iostream"
#include "QDebug"
#include "flatui.h"
#include "tool/appinit.h"

#define navIcoWidth 20
#define navBtnWidth 20

ParaWindow::ParaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ParaWindow)
{
    ui->setupUi(this);
    this->initForm();
}

ParaWindow::~ParaWindow()
{
    delete ui;
}

void ParaWindow::initForm()
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
    //ui->solt1_switch->setButtonStyle(ImageSwitch::ButtonStyle_1);
    //ui->solt2_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    //ui->solt3_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    //ui->solt4_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->solt1_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    ui->solt2_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    ui->solt3_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);
    ui->solt4_switch->setButtonStyle(ImageSwitch::ButtonStyle_2);


    ui->corder_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->use_EP_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->clearBeforePrint_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->ocr_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->checkreader_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);
    ui->use_LAM_switch->setButtonStyle(ImageSwitch::ButtonStyle_3);

    //设置右下角有个三角图标可以改变窗口大小
    this->setSizeGripEnabled(true);//QDialog具有的属性

    ui->labTitle->setText(tr("参数设置"));
    this->setWindowTitle(ui->labTitle->text());
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    ui->widgetTop->setProperty("flag", "nav");
    ui->widgetTop->setFixedHeight(28);

    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    //qss.append(QString("*{outline:0px;color:#FEFEFE;}"));
    //主窗体背景
    qss.append(QString("QWidget#widgetMain{border-image:url(%1);}").arg(":/image/main.png"));
    //标题字体大小
    qss.append(QString("QLabel#labTitle{font:%1px;}").arg(navIcoWidth));

    //顶部导航
    qss.append(QString("QWidget[flag=\"nav\"]{background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,"
                       "stop:0 %1,stop:1 %2);}").arg("#00688B").arg("#3498DB"));
    qss.append(QString("QWidget[flag=\"nav\"] QAbstractButton{background:none;border:none;"
                       "min-width:%1px;max-width:%1px;}").arg(navBtnWidth));

    this->setStyleSheet(qss.join(""));
    LoadParamter();
}

void ParaWindow::LoadParamter()
{
    para=new ParamterClass();

    AppInit::Instance()->LoadParamterFile();
    //OCR
    if(AppInit::Instance()->domparser->para->isUseCardBorder)
    {
        ui->corder_switch->setChecked(true);
    }
    else
    {
        ui->corder_switch->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isUsePrint1)
    {
        ui->chk_Print1_Print->setChecked(true);
    }
    else
    {
        ui->chk_Print1_Print->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isUsePrint2)
    {
        ui->chk_Print2_Print->setChecked(true);
    }
    else
    {
        ui->chk_Print2_Print->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isUsePrint3)
    {
        ui->chk_Print3_Print->setChecked(true);
    }
    else
    {
        ui->chk_Print3_Print->setChecked(false);
    }

    if(AppInit::Instance()->domparser->para->isPrint1ModEnable)
    {
        ui->chk_Print1->setChecked(true);
    }
    else
    {
        ui->chk_Print1->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isPrint2ModEnable)
    {
        ui->chk_Print2->setChecked(true);
    }
    else
    {
        ui->chk_Print2->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isPrint3ModEnable)
    {
        ui->chk_Print3->setChecked(true);
    }
    else
    {
        ui->chk_Print3->setChecked(false);
    }
    //是否覆膜
    if(AppInit::Instance()->domparser->para->isUseLam)
    {
        ui->use_LAM_switch->setChecked(true);
    }
    else
    {
        ui->use_LAM_switch->setChecked(false);
    }

    //是否启用可擦写
    if(AppInit::Instance()->domparser->para->isUseEPrint)
    {
        ui->use_EP_switch->setChecked(true);
    }
    else
    {
        ui->use_EP_switch->setChecked(false);
    }
    //打印前擦除
    if(AppInit::Instance()->domparser->para->isClearBeforePrint)
    {
        ui->clearBeforePrint_switch->setChecked(true);
    }
    else
    {
        ui->clearBeforePrint_switch->setChecked(false);
    }
    //卡槽
    if(AppInit::Instance()->domparser->para->isOpenSolt1)
    {
        ui->solt1_switch->setChecked(true);
    }
    else
    {
        ui->solt1_switch->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isOpenSolt2)
    {
        ui->solt2_switch->setChecked(true);
    }
    else
    {
        ui->solt2_switch->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isOpenSolt3)
    {
        ui->solt3_switch->setChecked(true);
    }
    else
    {
        ui->solt3_switch->setChecked(false);
    }
    if(AppInit::Instance()->domparser->para->isOpenSolt4)
    {
        ui->solt4_switch->setChecked(true);
    }
    else
    {
        ui->solt4_switch->setChecked(false);
    }
}

void ParaWindow::on_pushButton_Cancle_clicked()
{
    reject();
}

void ParaWindow::on_pushButton_Save_clicked()
{
    if(ui->chk_Print1->checkState()== Qt::Checked)
    {
        para->isPrint1ModEnable=true;
    }
    else
    {
        para->isPrint1ModEnable=false;
    }

    if(ui->chk_Print1_Print->checkState()== Qt::Checked)
    {
        para->isUsePrint1=true;
    }
    else
    {
        para->isUsePrint1=false;
    }

    if(ui->chk_Print2->checkState()== Qt::Checked)
    {
        para->isPrint2ModEnable=true;
    }
    else
    {
        para->isPrint2ModEnable=false;
    }

    if(ui->chk_Print2_Print->checkState()== Qt::Checked)
    {
        para->isUsePrint2=true;
    }
    else
    {
        para->isUsePrint2=false;
    }
    if(ui->chk_Print3->checkState()== Qt::Checked)
    {
        para->isPrint3ModEnable=true;
    }
    else
    {
        para->isPrint3ModEnable=false;
    }

    if(ui->chk_Print3_Print->checkState()== Qt::Checked)
    {
        para->isUsePrint3=true;
    }
    else
    {
        para->isUsePrint3=false;
    }
    //是否覆膜
    if(ui->use_LAM_switch->getChecked()== true)
    {
        ///getChecked
        para->isUseLam=true;
    }
    else
    {
        para->isUseLam=false;
    }
    //是否启用可擦写
    if(ui->use_EP_switch->getChecked()== true)
    {
        para->isUseEPrint=true;
    }
    else
    {
        para->isUseEPrint=false;
    }
    //打印前擦除
    if(ui->clearBeforePrint_switch->getChecked()== true)
    {
        para->isClearBeforePrint=true;
    }
    else
    {
        para->isClearBeforePrint=false;
    }
    //卡槽启用
    if(ui->solt1_switch->getChecked()== true)
    {
        para->isOpenSolt1=true;
    }
    else
    {
        para->isOpenSolt1=false;
    }
    if(ui->solt2_switch->getChecked()== true)
    {
        para->isOpenSolt2=true;
    }
    else
    {
        para->isOpenSolt2=false;
    }
    if(ui->solt3_switch->getChecked()== true)
    {
        para->isOpenSolt3=true;
    }
    else
    {
        para->isOpenSolt3=false;
    }
    if(ui->solt4_switch->getChecked()== true)
    {
        para->isOpenSolt4=true;
    }
    else
    {
        para->isOpenSolt4=false;
    }
    this->SaveParamter2File(para);
    accept();
    //  close();
}
//TODO保存参数文件，
void ParaWindow::SaveParamter2File(ParamterClass *paramterClass)
{
    AppInit::Instance()->SaveParamterFile(para);
}
