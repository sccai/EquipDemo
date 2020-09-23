#include "printform.h"
#include "ui_printform.h"
#include <QFileDialog>
#include "tool/commhelper.h"
#include "QtConcurrent"
#include "QCoreApplication"

PrintForm::PrintForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrintForm)
{
    ui->setupUi(this);

    QStringList qss;
    //全局无焦点虚边框,全局文字颜色,全局字号
    qss.append(QString("QTextEdit{outline:0px;color:#000000;}"));
    this->setStyleSheet(qss.join(""));//Wrong JPEG library version: library is 62, caller expects 80
    //qss.append(QString("QLabel#labTitle{font:%1px;}").arg(navIcoWidth));
}

PrintForm::~PrintForm()
{
    delete ui;
}

void PrintForm::on_pushButton_InitDevice_clicked()
{
    QString strIP= ui->txt_IP->toPlainText();


    bool simu=false;
    if(ui->chkSimu->checkState()== Qt::Checked)
    {
        qDebug()<<"模拟运行";
        simu=true;
    }
    else
    {
        simu=false;
    }
    //simu :模拟运行，不进行打印
    print_600=new Print_RCK600(strIP,9000,"1",this,simu);
    QObject::connect(print_600,&Print_RCK600::OnSendMsg,this,&PrintForm::OnRefreshSend);
    QObject::connect(print_600,&Print_RCK600::OnReceiveMsg,this,&PrintForm::OnRefresh);

    bool res= print_600->InitDevice();
    qDebug()<<"初始化结果 ="<<res;
    qDebug()<<"是否模拟运行 ="<<simu;
}

void PrintForm::on_pushButton_LoadTask_clicked()
{
    //双面打印
    bool double_print= ui->chkDoublePrint->checkState()==Qt::Checked?true:false;

    bool res= print_600->LoadPrintTask(ui->txt_FrontPath->toPlainText(),
                                       ui->txt_BackPath->toPlainText(),
                                       double_print);


}

void PrintForm::on_pushButton_FeedPrint_clicked()
{
    //print_600->GetStatus();
    print_600->FeedCardAndPrint();
}

void PrintForm::on_pushButton_EjectCard_clicked()
{
    print_600->EjectCard();
}

void PrintForm::on_pushButton_GetStatus_clicked()
{
    R600Status status;
    print_600->GetStatus(status);
    qDebug()<<"MainStatus ="<<  status.MainStatus;
    qDebug()<<"WarningStatus ="<<  status.WarningStatus;
    qDebug()<<"ErrorStatus ="<<  status.ErrorStatus;
    qDebug()<<"ChassisTemp ="<<  status.ChassisTemp;//机箱温度
    qDebug()<<"PrintheadTemp ="<<  status.PrintheadTemp;//打印头温度
    qDebug()<<"HeaterTemp ="<<  status.HeaterTemp;//加热辊温度

    if(status.MainStatus==1004)//准备打印状态
    {

    }
    else
    {
        if(status.MainStatus==1027)//制卡中，此时可以进卡。只过卡不打印时，没有制卡中（等待排卡状态）
        {

        }
        if(status.MainStatus==1025)//等待排卡，此时可以出卡
        {

        }
    }
}

void PrintForm::on_pushButton_BackImg_clicked()
{

    QFileDialog *fileDialog=new QFileDialog(this);
    fileDialog->setWindowTitle("OpenImage");
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Images(*.png)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);

    //fileDialog->selectFile("/home/aisino/project/EquipDemo/img.png");

    QStringList filenames;
    QString filename;
    if(fileDialog->exec())
    {
        filenames=fileDialog->selectedFiles();
        filename=filenames[0];
        ui->txt_BackPath->setText(filename);
    }
    qDebug()<<filename<<endl;
    QImage image(filename);
    ui->label_back_img->setPixmap(QPixmap::fromImage(image));
    ui->label_back_img->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->label_back_img->setScaledContents(true);

}

void PrintForm::on_pushButton_FrontImg_clicked()
{
    QFileDialog *fileDialog=new QFileDialog(this);
    fileDialog->setWindowTitle("OpenImage");
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("Images(*.png)"));
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    fileDialog->setViewMode(QFileDialog::Detail);

    fileDialog->selectFile("/home/aisino/project/EquipDemo/img.png");

    QStringList filenames;
    QString filename;
    if(fileDialog->exec())
    {
        filenames=fileDialog->selectedFiles();
        filename=filenames[0];
        ui->txt_FrontPath->setText(filename);
    }
    qDebug()<<filename<<endl;
    QImage image(filename);
    ui->label_front_img->setPixmap(QPixmap::fromImage(image));
    ui->label_front_img->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    ui->label_front_img->setScaledContents(true);

}

void PrintForm::OnRefreshSend(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构发送指令 ="+HexString);
    ui ->textEdit_Log ->append(ModType+" 机构发送指令 ="+HexString);
}
void PrintForm::OnRefresh(QString ModType,QString HexString,int c)
{
    CommHelper::Instance()->ShowLog(ModType+" 机构返回数据 = "+HexString);
    ui ->textEdit_Log ->append(ModType+" 机构返回数据 = "+HexString);//追加到编辑区中

    if(ModType=="Print")
    {


    }
}

void PrintForm::on_chkSimu_clicked()
{
    if(ui->chkSimu->checkState()== Qt::Unchecked)
    {
        qDebug()<<"Unchecked";
        print_600->SetSimulate(false);
    }
    else
    {
        print_600->SetSimulate(true);
        qDebug()<<"checked";
    }
}

void PrintForm::on_pushButton_RunLoad_clicked()
{
    QtConcurrent::run(this,&PrintForm::RunLoad);
}

void PrintForm::on_pushButton_RunFeed_clicked()
{
    QtConcurrent::run(this,&PrintForm::RunFeed);
}

void PrintForm::on_pushButton_RunEjectCard_clicked()
{
    QtConcurrent::run(this,&PrintForm::RunEjectCard);
}
void PrintForm::RunLoad()
{
    //双面打印
    bool double_print= ui->chkDoublePrint->checkState()==Qt::Checked?true:false;

    bool res= print_600->LoadPrintTask(ui->txt_FrontPath->toPlainText(),
                                       ui->txt_BackPath->toPlainText(),
                                       double_print);


}
void PrintForm::RunFeed()
{
    print_600->FeedCardAndPrint();
}
void PrintForm::RunEjectCard()
{
    print_600->EjectCard();
}
