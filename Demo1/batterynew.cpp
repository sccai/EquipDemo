#pragma execution_character_set("utf-8")

#include "batterynew.h"
#include "qpainter.h"
#include "qtimer.h"
#include "qdebug.h"

BatteryNew::BatteryNew(QWidget *parent) : QWidget(parent)
{
    minValue = 0;
    maxValue = 100;
    value = 0;
    alarmValue = 20;//告警线,颜色变化的分界点
    midalarmValue=50;
    step = 1;
    //step = 0.5;

    borderColorStart = QColor(100, 100, 100);
    borderColorEnd = QColor(80, 80, 80);

    midalarmColorStart = QColor(255, 118, 27);//橙色QColor(255, 118, 27);
    midalarmColorEnd = QColor(255, 118, 0);//橙色QColor(255, 118, 00);

    alarmColorStart = QColor(50, 118, 113);//红色QColor(250, 118, 113);
    alarmColorEnd = QColor(204, 38, 38);//红色QColor(204, 38, 38);
    normalColorStart =QColor(50, 205, 51);//绿色QColor(50, 205, 51);
    normalColorEnd = QColor(60, 179, 133);//绿色QColor(60, 179, 133);

    isForward = false;
    currentValue = 0;

    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateValue()));
}

BatteryNew::~BatteryNew()
{
    if (timer->isActive()) {
        timer->stop();
    }
}

void BatteryNew::paintEvent(QPaintEvent *)
{
    //绘制准备工作,启用反锯齿
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    //绘制边框
    drawBorder(&painter);
    //绘制背景
    drawBg(&painter);
}

void BatteryNew::drawBorder(QPainter *painter)
{
    painter->save();
    double headWidth = width() / 10;
    double batteryWidth = width() - headWidth;

    //绘制电池边框
    QPointF topLeft(5, 5);

    QPointF bottomRight(batteryWidth, height() - 5);
    batteryRect = QRectF(topLeft, bottomRight);

    painter->setPen(QPen(borderColorStart, 5));
    painter->setBrush(Qt::NoBrush);
    painter->drawRoundRect(batteryRect, 10, 10);

    //绘制电池头部
    //QPointF headRectTopLeft(batteryRect.topRight().x(), height() / 3);
    //QPointF headRectBottomRight(width(), height() - height() / 3);
    //QRectF headRect(headRectTopLeft, headRectBottomRight);

    //QLinearGradient headRectGradient(headRect.topLeft(), headRect.bottomLeft());
    //headRectGradient.setColorAt(0.0, borderColorStart);
    //headRectGradient.setColorAt(1.0, borderColorEnd);

    //painter->setBrush(headRectGradient);
    //painter->drawRoundRect(headRect, 15, 25);
    painter->restore();
}

void BatteryNew::drawBg(QPainter *painter)
{
    painter->save();
    //qDebug() << "drawBg "<<currentValue;

    QLinearGradient batteryGradient(QPointF(0, 0), QPointF(0, height()));

    if (currentValue <= midalarmValue&&currentValue>alarmValue) {
        batteryGradient.setColorAt(0.0, midalarmColorStart);
        batteryGradient.setColorAt(1.0, midalarmColorEnd);
    }
    else  if (currentValue <= alarmValue) {
        batteryGradient.setColorAt(0.0, alarmColorStart);
        batteryGradient.setColorAt(1.0, alarmColorEnd);
    }
    else {
        batteryGradient.setColorAt(0.0, normalColorStart);
        batteryGradient.setColorAt(1.0, normalColorEnd);
    }

    painter->setPen(Qt::NoPen);
    painter->setBrush(batteryGradient);

    //int margin = qMin(width(), height()) / 20;
    //double unit = (batteryRect.width() - (margin * 2)) / 100;
    //double width = currentValue * unit;

    int marginH = width() / 20;

    //int marginH = height()/ 20;


    double unit = (batteryRect.height() - (marginH * 2)) / 100;
    double height = currentValue * unit;

    //double unitw = (batteryRect.width() - (marginW * 2)) / 100;
    //double width = currentValue * unitw;

    //====================================
    //qDebug() << "height ="<< height;
    //qDebug() << "width =" << width;
    //qDebug() << "margin =" << marginH;
    //====================================
    //qDebug() << "topLeft.X ="<< batteryRect.topLeft().x() ;
    //qDebug() << "topLeft.Y ="<<height -batteryRect.topLeft().y();
    //qDebug() << "bottomRight.X ="<<batteryRect.bottomRight().x() ;
    //qDebug() << "bottomRight.Y ="<< batteryRect.bottomRight().y() ;

    QPointF topLeft(batteryRect.topLeft().x() + marginH, batteryRect.bottomRight().y()-height-marginH);
    QPointF bottomRight(batteryRect.bottomRight().x() - marginH, batteryRect.bottomRight().y() - marginH);

    QRectF rect(topLeft, bottomRight);
    painter->drawRoundRect(rect, 5, 5);//圆角矩形
    painter->restore();
}

void BatteryNew::updateValue()
{
    if (isForward) {
        currentValue -= step;

        if (currentValue <= value) {
            timer->stop();
        }
    } else {
        currentValue += step;

        if (currentValue >= value) {
            timer->stop();
        }
    }

    update();
}

double BatteryNew::getMinValue() const
{
    return this->minValue;
}

double BatteryNew::getMaxValue() const
{
    return this->maxValue;
}

double BatteryNew::getValue() const
{
    return this->value;
}

double BatteryNew::getAlarmValue() const
{
    return this->alarmValue;
}

double BatteryNew::getStep() const
{
    return this->step;
}

QColor BatteryNew::getBorderColorStart() const
{
    return this->borderColorStart;
}

QColor BatteryNew::getBorderColorEnd() const
{
    return this->borderColorEnd;
}

QColor BatteryNew::getAlarmColorStart() const
{
    return this->alarmColorStart;
}

QColor BatteryNew::getAlarmColorEnd() const
{
    return this->alarmColorEnd;
}

QColor BatteryNew::getNormalColorStart() const
{
    return this->normalColorStart;
}

QColor BatteryNew::getNormalColorEnd() const
{
    return this->normalColorEnd;
}

QSize BatteryNew::sizeHint() const
{
    return QSize(150, 80);
}

QSize BatteryNew::minimumSizeHint() const
{
    return QSize(30, 10);
}

void BatteryNew::setRange(double minValue, double maxValue)
{
    //如果最小值大于或者等于最大值则不设置
    if (minValue >= maxValue) {
        return;
    }

    this->minValue = minValue;
    this->maxValue = maxValue;

    //如果目标值不在范围值内,则重新设置目标值
    if (value < minValue || value > maxValue) {
        setValue(value);
    }

    update();
}

void BatteryNew::setRange(int minValue, int maxValue)
{
    setRange((double)minValue, (double)maxValue);
}

void BatteryNew::setMinValue(double minValue)
{
    setRange(minValue, maxValue);
}

void BatteryNew::setMaxValue(double maxValue)
{
    setRange(minValue, maxValue);
}

void BatteryNew::setValue(double value)
{
    //值小于最小值或者值大于最大值或者值和当前值一致则无需处理
    if (value < minValue || value > maxValue || value == this->value) {
        return;
    }

    emit valueChanged(value);
    this->value = value;

    if (value > currentValue) {
        isForward = false;
    } else if (value < currentValue) {
        isForward = true;
    } else {
        return ;
    }

    timer->start();
    update();
}

void BatteryNew::setValue(int value)
{
    setValue((double)value);
}

void BatteryNew::setAlarmValue(double alarmValue)
{
    if (this->alarmValue != alarmValue) {
        this->alarmValue = alarmValue;
        update();
    }
}

void BatteryNew::setAlarmValue(int alarmValue)
{
    setAlarmValue((double)alarmValue);
}

void BatteryNew::setStep(double step)
{
    if (this->step != step) {
        this->step = step;
        update();
    }
}

void BatteryNew::setStep(int step)
{
    setStep((double)step);
}

void BatteryNew::setBorderColorStart(const QColor &borderColorStart)
{
    if (this->borderColorStart != borderColorStart) {
        this->borderColorStart = borderColorStart;
        update();
    }
}

void BatteryNew::setBorderColorEnd(const QColor &borderColorEnd)
{
    if (this->borderColorEnd != borderColorEnd) {
        this->borderColorEnd = borderColorEnd;
        update();
    }
}

void BatteryNew::setAlarmColorStart(const QColor &alarmColorStart)
{
    if (this->alarmColorStart != alarmColorStart) {
        this->alarmColorStart = alarmColorStart;
        update();
    }
}

void BatteryNew::setAlarmColorEnd(const QColor &alarmColorEnd)
{
    if (this->alarmColorEnd != alarmColorEnd) {
        this->alarmColorEnd = alarmColorEnd;
        update();
    }
}

void BatteryNew::setNormalColorStart(const QColor &normalColorStart)
{
    if (this->normalColorStart != normalColorStart) {
        this->normalColorStart = normalColorStart;
        update();
    }
}

void BatteryNew::setNormalColorEnd(const QColor &normalColorEnd)
{
    if (this->normalColorEnd != normalColorEnd) {
        this->normalColorEnd = normalColorEnd;
        update();
    }
}

void BatteryNew::setDefault(int defvalue)
{
    if(defvalue!=0)
    {
        return;
    }
    value=100;
    currentValue=100;
    //值小于最小值或者值大于最大值或者值和当前值一致则无需处理
    if (value < minValue || value > maxValue || value == this->value) {
        return;
    }

    emit valueChanged(value);
    this->value = value;

    if (value > currentValue) {
        isForward = false;
    } else if (value < currentValue) {
        isForward = true;
    } else {
        return ;
    }

    timer->start();
    update();
}
