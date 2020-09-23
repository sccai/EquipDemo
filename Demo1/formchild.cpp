#include "formchild.h"
#include "ui_formchild.h"
#include "QDebug"
#include <QPainter>
#include <QTransform>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QString>
#include "QFileDialog"
#include <QDomElement>
#include "deviceinfo.h"
#include "tool/domparser.h"
#include "tool/appinit.h"


FormChild::FormChild(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormChild)
{
    //QLabel *label=new QLabel("HELLO");
    //label->show();

    ui->setupUi(this);
    //显示图片,方式1
    //QMovie *movie =new QMovie(":/bol.png");
    //ui->label_2->setMovie(movie);
    //movie->start();

    //label显示图片,方式2
    //ui->label_2->setPixmap(QPixmap(":/bol.png"));

    //显示图片,方式3
    //QImage *image= new QImage(":/bol.png");
    QImage image(":/bol.png");
    ui->label_2->setPixmap(QPixmap::fromImage(image));

    //显示图片,方式4
    //QImage image2;
    //image2.load(":/bol.png");
    //ui->label_2->clear();
    //ui->label_2->setPixmap(QPixmap::fromImage(image2));

    //按钮设备背景图片，方式1
    //ui->toolButton->setStyleSheet(tr("background-image: url(:/eng.png);"));

    //按钮设备背景图片，方式2
    //QPixmap icon1(tr(":/eng.png"));
    QPixmap icon1(":/eng.png");
    ui->toolButton->setIcon(icon1);
    //QSize size2(200,200);
    //ui->toolButton->setFixedSize(size2);
    //ui->toolButton->setFixedSize(icon1.size());
    //ui->toolButton->setFixedSize(250,250);

    //按钮设备背景图片，方式3
    //QIcon icon;
    //icon.addFile(tr(":/eng.png"));
    //ui->toolButton->setIcon(icon);

    //ui->widget_Battery_New->setValue(100);
    ui->widget_Battery_New->setDefault(0);


    //按钮设备背景图片，方式1
    //ui->widget_img->setStyleSheet(tr("background-image: url(:/image/img.png);"));

    //QPalette palette;
    //palette.setColor(QPalette::Background, QColor(192,253,123));
    //palette.setBrush(QPalette::Background, QBrush(QPixmap(":/bol.png")));
    //ui->widget_img->setPalette(palette);
    ui->widget_img->setStyleSheet("border-image: url(:/image/img.png);");

}

FormChild::~FormChild()
{
    delete ui;
}

void FormChild::on_pushButton_clicked()
{

}

void FormChild::on_pushButton_2_clicked()
{
    ui->widget_Battery_New->setValue(50);
}



