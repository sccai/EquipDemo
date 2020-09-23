#include "roundprogressbartest.h"
#include "ui_roundprogressbartest.h"

RoundProgressBarTest::RoundProgressBarTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RoundProgressBarTest)
{
    ui->setupUi(this);

    //圆环
    ui->roundBar1->setFormat("%v");
    ui->roundBar1->setDecimals(0);
    connectToSlider(ui->roundBar1);
    connectToBaseCircleCheckBox(ui->roundBar1);
    connectToDataCircleCheckBox(ui->roundBar1);
    connectToCenterCircleCheckBox(ui->roundBar1);
    connectToTextCheckBox(ui->roundBar1);

    QGradientStops grandientPoints;
    grandientPoints << QGradientStop(0, Qt::red) << QGradientStop(1, Qt::yellow);
    ui->roundBar4->setStartAngle(RoundProgressBar::PositionLeft);
    ui->roundBar4->setDecimals(0);
    ui->roundBar4->setDataColors(grandientPoints);
    connectToSlider(ui->roundBar4);
    connectToBaseCircleCheckBox(ui->roundBar4);
    connectToDataCircleCheckBox(ui->roundBar4);
    connectToCenterCircleCheckBox(ui->roundBar4);
    connectToTextCheckBox(ui->roundBar4);

    //饼状
    ui->roundBar2->setStartAngle(RoundProgressBar::PositionRight);
    ui->roundBar2->setBarStyle(RoundProgressBar::StylePie);
    ui->roundBar2->setDecimals(0);
    connectToSlider(ui->roundBar2);
    connectToBaseCircleCheckBox(ui->roundBar2);
    connectToDataCircleCheckBox(ui->roundBar2);
    connectToCenterCircleCheckBox(ui->roundBar2);
    connectToTextCheckBox(ui->roundBar2);

    //线条
    ui->roundBar3->setStartAngle(RoundProgressBar::PositionTop);
    ui->roundBar3->setBarStyle(RoundProgressBar::StyleLine);
    ui->roundBar3->setOutlinePenWidth(4);
    ui->roundBar3->setDataPenWidth(4);
    ui->roundBar3->setDecimals(0);
    connectToSlider(ui->roundBar3);
    connectToBaseCircleCheckBox(ui->roundBar3);
    connectToDataCircleCheckBox(ui->roundBar3);
    connectToCenterCircleCheckBox(ui->roundBar3);
    connectToTextCheckBox(ui->roundBar3);

    QGradientStops gradientPoints;
    gradientPoints << QGradientStop(0, Qt::green) << QGradientStop(0.5, Qt::yellow) << QGradientStop(1, Qt::red);
    QPalette p1;//字体颜色
    p1.setBrush(QPalette::AlternateBase, Qt::black);
    p1.setColor(QPalette::Text, Qt::white);
    QPalette p2(p1);
    p2.setBrush(QPalette::Base, Qt::red);
    p2.setColor(QPalette::Text, Qt::blue);
    p2.setColor(QPalette::Shadow, Qt::yellow);
    p2.setColor(QPalette::Window, Qt::green);
    ui->roundBar3->setPalette(p2);



    ui->roundBar5->setStartAngle(RoundProgressBar::PositionLeft);
    ui->roundBar5->setBarStyle(RoundProgressBar::StylePie);
    ui->roundBar5->setDecimals(0);
    connectToSlider(ui->roundBar5);
    connectToBaseCircleCheckBox(ui->roundBar5);
    connectToDataCircleCheckBox(ui->roundBar5);
    connectToCenterCircleCheckBox(ui->roundBar5);
    connectToTextCheckBox(ui->roundBar5);



    ui->roundBar6->setStartAngle(RoundProgressBar::PositionTop);
    ui->roundBar6->setBarStyle(RoundProgressBar::StyleLine);
    ui->roundBar6->setDecimals(2);
    ui->roundBar6->setClockwise(false);
    ui->roundBar6->setOutlinePenWidth(18);
    ui->roundBar6->setDataPenWidth(10);
    connectToSlider(ui->roundBar6);
    connectToBaseCircleCheckBox(ui->roundBar6);
    connectToDataCircleCheckBox(ui->roundBar6);
    connectToCenterCircleCheckBox(ui->roundBar6);
    connectToTextCheckBox(ui->roundBar6);

//this->setStyleSheet("background:#ff0000;");
    this->setStyleSheet("border-image:url(:/image/main.jpg);");
}

RoundProgressBarTest::~RoundProgressBarTest()
{
    delete ui;
}

void RoundProgressBarTest::connectToSlider(RoundProgressBar *bar)
{
    bar->setRange(ui->valueSlider->minimum(), ui->valueSlider->maximum());
    bar->setValue(ui->valueSlider->value());
    connect(ui->valueSlider, SIGNAL(valueChanged(int)), bar, SLOT(setValue(int)));
}

void RoundProgressBarTest::connectToBaseCircleCheckBox(RoundProgressBar *bar)
{
    connect(ui->base_circle_ckb, SIGNAL(toggled(bool)), bar, SLOT(setBaseCircleVisible(bool)));
}

void RoundProgressBarTest::connectToDataCircleCheckBox(RoundProgressBar *bar)
{
    connect(ui->data_circle_ckb, SIGNAL(toggled(bool)), bar, SLOT(setDataCircleVisible(bool)));
}

void RoundProgressBarTest::connectToCenterCircleCheckBox(RoundProgressBar *bar)
{
    connect(ui->center_circle_ckb, SIGNAL(toggled(bool)), bar, SLOT(setCenterCircleVisible(bool)));
}

void RoundProgressBarTest::connectToTextCheckBox(RoundProgressBar *bar)
{
    connect(ui->text_ckb, SIGNAL(toggled(bool)), bar, SLOT(setTextVisible(bool)));
}


void RoundProgressBarTest::on_pushButton_clicked()
{
    close();
}
