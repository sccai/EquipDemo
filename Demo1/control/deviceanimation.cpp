#pragma execution_character_set("utf-8")

#include "deviceanimation.h"
#include "qpainter.h"
#include "qevent.h"
#include "qtimer.h"
#include "qdebug.h"

DeviceAnimation::DeviceAnimation(QWidget *parent) : QWidget(parent)
{
    text = "";
    textColor = QColor(255, 255, 255);
    alarmColor = QColor(255, 107, 107);
    normalColor = QColor(10, 10, 10);

    borderOutColorStart = QColor(255, 255, 255);
    borderOutColorEnd = QColor(166, 166, 166);

    borderInColorStart = QColor(166, 166, 166);
    borderInColorEnd = QColor(255, 255, 255);

    bgColor = QColor(100, 184, 255);

    showRect = false;
    showOverlay = true;
    overlayColor = QColor(255, 255, 255);

    canMove = false;

    this->installEventFilter(this);

    isAlarm = false;
    timerAlarm = new QTimer(this);
    //connect(timerAlarm, SIGNAL(timeout()), this, SLOT(alarm()));
    connect(timerAlarm, SIGNAL(timeout()), this, SLOT(alarmNew()));
    timerAlarm->setInterval(500);

    //setFont(QFont("Arial", 8));
}

bool DeviceAnimation::eventFilter(QObject *watched, QEvent *event)
{
    if (canMove) {
        static QPoint lastPoint;
        static bool pressed = false;
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);

        if (mouseEvent->type() == QEvent::MouseButtonPress) {
            if (this->rect().contains(mouseEvent->pos()) && (mouseEvent->button() == Qt::LeftButton)) {
                lastPoint = mouseEvent->pos();
                pressed = true;
            }
        } else if (mouseEvent->type() == QEvent::MouseMove && pressed) {
            int dx = mouseEvent->pos().x() - lastPoint.x();
            int dy = mouseEvent->pos().y() - lastPoint.y();
            this->move(this->x() + dx, this->y() + dy);
        } else if (mouseEvent->type() == QEvent::MouseButtonRelease && pressed) {
            pressed = false;
        }
    }

    return QWidget::eventFilter(watched, event);
}

void DeviceAnimation::paintEvent(QPaintEvent *)
{
    int width = this->width();
    int height = this->height();
    int side = qMin(width, height);

    //qDebug()<<"paintEvent showRect = "<<showRect;

    if(showPixmap)
    {
        //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

        //绘制矩形区域
        //painter.setPen(Qt::NoPen);
        //painter.setBrush(bgColor);
        //painter.drawRoundedRect(this->rect(), 5, 5);

        //背景图
        //QPixmap pixmap(":/images/1.png");
        //this->size()
        painter.drawPixmap(0,0,width,height,bgQPixmap);//拉伸 图片适应大小
        // painter.drawPixmap(bgQPixmap.rect(),bgQPixmap);

        //绘制文字
        //        if (!text.isEmpty()) {
        //            QFont font;
        //            font.setPixelSize(side - 20);
        //            painter.setFont(font);
        //            painter.setPen(textColor);
        //            painter.drawText(this->rect(), Qt::AlignCenter, text);
        //        }
    }
    else
    {
        //绘制准备工作,启用反锯齿,平移坐标轴中心,等比例缩放
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

        if (showRect) {
            //绘制矩形区域
            painter.setPen(Qt::NoPen);
            painter.setBrush(bgColor);
            painter.drawRoundedRect(this->rect(), 5, 5);

            //背景图
            //QPixmap pixmap(":/images/1.png");
            //painter.drawPixmap(pixmap.rect(),pixmap);

            //绘制文字
            if (!text.isEmpty()) {
                QFont font;
                font.setPixelSize(side - 20);
                painter.setFont(font);
                painter.setPen(textColor);
                painter.drawText(this->rect(), Qt::AlignCenter, text);
            }

        } else {
            painter.translate(width / 2, height / 2);
            painter.scale(side / 200.0, side / 200.0);

            //绘制外边框
            drawBorderOut(&painter);
            //绘制内边框
            drawBorderIn(&painter);
            //绘制内部指示颜色
            drawBg(&painter);
            //绘制居中文字
            drawText(&painter);
            //绘制遮罩层
            drawOverlay(&painter);
        }
    }

}

void DeviceAnimation::drawBorderOut(QPainter *painter)
{
    int radius = 99;
    painter->save();
    painter->setPen(Qt::NoPen);
    QLinearGradient borderGradient(0, -radius, 0, radius);
    borderGradient.setColorAt(0, borderOutColorStart);
    borderGradient.setColorAt(1, borderOutColorEnd);
    painter->setBrush(borderGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void DeviceAnimation::drawBorderIn(QPainter *painter)
{
    int radius = 90;
    painter->save();
    painter->setPen(Qt::NoPen);
    QLinearGradient borderGradient(0, -radius, 0, radius);
    borderGradient.setColorAt(0, borderInColorStart);
    borderGradient.setColorAt(1, borderInColorEnd);
    painter->setBrush(borderGradient);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void DeviceAnimation::drawBg(QPainter *painter)
{
    int radius = 80;
    painter->save();
    painter->setPen(Qt::NoPen);
    painter->setBrush(bgColor);
    painter->drawEllipse(-radius, -radius, radius * 2, radius * 2);
    painter->restore();
}

void DeviceAnimation::drawText(QPainter *painter)
{
    if (text.isEmpty()) {
        return;
    }

    int radius = 100;
    painter->save();

    QFont font;
    font.setPixelSize(85);
    painter->setFont(font);
    painter->setPen(textColor);
    QRect rect(-radius, -radius, radius * 2, radius * 2);
    painter->drawText(rect, Qt::AlignCenter, text);
    painter->restore();
}

void DeviceAnimation::drawOverlay(QPainter *painter)
{
    if (!showOverlay) {
        return;
    }

    int radius = 80;
    painter->save();
    painter->setPen(Qt::NoPen);

    QPainterPath smallCircle;
    QPainterPath bigCircle;
    radius -= 1;
    smallCircle.addEllipse(-radius, -radius, radius * 2, radius * 2);
    radius *= 2;
    bigCircle.addEllipse(-radius, -radius + 140, radius * 2, radius * 2);

    //高光的形状为小圆扣掉大圆的部分
    QPainterPath highlight = smallCircle - bigCircle;

    QLinearGradient linearGradient(0, -radius / 2, 0, 0);
    overlayColor.setAlpha(100);
    linearGradient.setColorAt(0.0, overlayColor);
    overlayColor.setAlpha(30);
    linearGradient.setColorAt(1.0, overlayColor);
    painter->setBrush(linearGradient);
    painter->rotate(-20);
    painter->drawPath(highlight);

    painter->restore();
}

QString DeviceAnimation::getText() const
{
    return this->text;
}

QColor DeviceAnimation::getTextColor() const
{
    return this->textColor;
}

QColor DeviceAnimation::getAlarmColor() const
{
    return this->alarmColor;
}

QColor DeviceAnimation::getNormalColor() const
{
    return this->normalColor;
}

QColor DeviceAnimation::getBorderOutColorStart() const
{
    return this->borderOutColorStart;
}

QColor DeviceAnimation::getBorderOutColorEnd() const
{
    return this->borderOutColorEnd;
}

QColor DeviceAnimation::getBorderInColorStart() const
{
    return this->borderInColorStart;
}

QColor DeviceAnimation::getBorderInColorEnd() const
{
    return this->borderInColorEnd;
}

QColor DeviceAnimation::getBgColor() const
{
    return this->bgColor;
}

bool DeviceAnimation::getCanMove() const
{
    return this->canMove;
}

bool DeviceAnimation::getShowRect() const
{
    return this->showRect;
}

bool DeviceAnimation::getShowOverlay() const
{
    return this->showOverlay;
}

QColor DeviceAnimation::getOverlayColor() const
{
    return this->overlayColor;
}

QSize DeviceAnimation::sizeHint() const
{
    return QSize(100, 100);
}

QSize DeviceAnimation::minimumSizeHint() const
{
    return QSize(10, 10);
}

void DeviceAnimation::setText(const QString &text)
{
    if (this->text != text) {
        this->text = text;
        this->update();
    }
}

void DeviceAnimation::setTextColor(const QColor &textColor)
{
    if (this->textColor != textColor) {
        this->textColor = textColor;
        this->update();
    }
}

void DeviceAnimation::setAlarmColor(const QColor &alarmColor)
{
    if (this->alarmColor != alarmColor) {
        this->alarmColor = alarmColor;
        this->update();
    }
}

void DeviceAnimation::setNormalColor(const QColor &normalColor)
{
    if (this->normalColor != normalColor) {
        this->normalColor = normalColor;
        this->update();
    }
}

void DeviceAnimation::setBorderOutColorStart(const QColor &borderOutColorStart)
{
    if (this->borderOutColorStart != borderOutColorStart) {
        this->borderOutColorStart = borderOutColorStart;
        this->update();
    }
}

void DeviceAnimation::setBorderOutColorEnd(const QColor &borderOutColorEnd)
{
    if (this->borderOutColorEnd != borderOutColorEnd) {
        this->borderOutColorEnd = borderOutColorEnd;
        this->update();
    }
}

void DeviceAnimation::setBorderInColorStart(const QColor &borderInColorStart)
{
    if (this->borderInColorStart != borderInColorStart) {
        this->borderInColorStart = borderInColorStart;
        this->update();
    }
}

void DeviceAnimation::setBorderInColorEnd(const QColor &borderInColorEnd)
{
    if (this->borderInColorEnd != borderInColorEnd) {
        this->borderInColorEnd = borderInColorEnd;
        this->update();
    }
}

void DeviceAnimation::setBgColor(const QColor &bgColor)
{
    if (this->bgColor != bgColor) {
        this->bgColor = bgColor;
        this->update();
    }
}

void DeviceAnimation::setCanMove(bool canMove)
{
    if (this->canMove != canMove) {
        this->canMove = canMove;
        this->update();
    }
}

void DeviceAnimation::setShowRect(bool showRect)
{
    if (this->showRect != showRect) {
        this->showRect = showRect;
        this->update();
    }
}

void DeviceAnimation::setShowOverlay(bool showOverlay)
{
    if (this->showOverlay != showOverlay) {
        this->showOverlay = showOverlay;
        this->update();
    }
}

void DeviceAnimation::setOverlayColor(const QColor &overlayColor)
{
    if (this->overlayColor != overlayColor) {
        this->overlayColor = overlayColor;
        this->update();
    }
}

void DeviceAnimation::setGreen()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(0, 166, 0));
}

void DeviceAnimation::setRed()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(255, 0, 0));
}

void DeviceAnimation::setYellow()
{
    textColor = QColor(25, 50, 7);
    setBgColor(QColor(238, 238, 0));
}

void DeviceAnimation::setBlack()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(10, 10, 10));
}

void DeviceAnimation::setGray()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(129, 129, 129));
}

void DeviceAnimation::setBlue()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(0, 0, 166));
}

void DeviceAnimation::setLightBlue()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(100, 184, 255));
}

void DeviceAnimation::setLightRed()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(255, 107, 107));
}

void DeviceAnimation::setLightGreen()
{
    textColor = QColor(255, 255, 255);
    setBgColor(QColor(24, 189, 155));
}

void DeviceAnimation::startAlarm()
{
    if (!timerAlarm->isActive()) {
        timerAlarm->start();
    }
}

void DeviceAnimation::stopAlarm()
{
    if (timerAlarm->isActive()) {
        timerAlarm->stop();
    }
}

void DeviceAnimation::alarm()
{
    if (isAlarm) {
        textColor = QColor(255, 255, 255);
        bgColor = normalColor;
    } else {
        textColor = QColor(255, 255, 255);
        bgColor = alarmColor;
    }

    this->update();
    isAlarm = !isAlarm;
}
void DeviceAnimation::setStatusImageColor(const QPixmap &img1,const QPixmap &img2,const QPixmap &img3,const QPixmap &img4)
{
    status1=img1;
    status2=img2;
    status3=img3;
    status4=img4;
}
void DeviceAnimation::startAlarmNew()
{
    if (!timerAlarm->isActive()) {
        timerAlarm->start();
    }
}
void DeviceAnimation::alarmNew()
{
    if (index==1) {
        bgQPixmap = status1;
    }
    else if (index==2) {
        bgQPixmap = status2;
    }
    else if (index==3) {
        bgQPixmap = status3;
    }
    else if (index==4) {
        bgQPixmap = status4;
    }
    this->update();
    if (index==4)
    {
        index=1;
    }
    else
    {
        index=index+1;
    }
}
void DeviceAnimation::setShowPixmap(bool b)
{
    showPixmap=b;
}
void DeviceAnimation::setBgPixmap()
{
    bgQPixmap = status1;
    this->update();
}
