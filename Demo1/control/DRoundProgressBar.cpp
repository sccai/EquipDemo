/*
 * DRoundProgressBar - a circular progress bar Qt widget.
 *
 * Sintegrial Technologies (c) 2015-now
 *
 * The software is freeware and is distributed "as is" with the complete source codes.
 * Anybody is free to use it in any software projects, either commercial or non-commercial.
 * Please do not remove this copyright message and remain the name of the author unchanged.
 *
 * It is very appreciated if you produce some feedback to us case you are going to use
 * the software.
 *
 * Please send your questions, suggestions, and information about found issues to the
 *
 * sintegrial@gmail.com
 *
 */


#include "DRoundProgressBar.h"
#include "QDebug"
#include <QtGui/QPainter>


DRoundProgressBar::DRoundProgressBar(QWidget *parent) :
    QWidget(parent),
    m_min(0), m_max(100),
    m_value(1),
    m_nullPosition(PositionTop),
    m_barStyle(StyleDonut),
    m_outlinePenWidth(1),
    m_dataPenWidth(1),
    m_rebuildBrush(false),
    m_format("%p%"),
    //%p%  ： 百分比，这是默认的显示方式
    //%v     ： 当前进度
    //%m    ： 总步数
    m_decimals(1),
    m_updateFlags(UF_PERCENT)
{
    //setStyleSheet("QWidget{background-color: rgb(255,255,255);}");//背景板是白色
    //this->setStyleSheet("QWidget{background-color: yellow;}");//yellow
}

void DRoundProgressBar::setRange(double min, double max)
{
    m_min = min;
    m_max = max;

    if (m_max < m_min)
        qSwap(m_max, m_min);

    if (m_value < m_min)
        m_value = m_min;
    else if (m_value > m_max)
        m_value = m_max;

    if (!m_gradientData.isEmpty())
        m_rebuildBrush = true;

    update();
}

void DRoundProgressBar::setMinimum(double min)
{
    setRange(min, m_max);
}

void DRoundProgressBar::setMaximum(double max)
{
    setRange(m_min, max);
}

void DRoundProgressBar::setValue(double val)
{
    if (m_value != val)
    {
        if (val < m_min)
            m_value = m_min;
        else if (val > m_max)
            m_value = m_max;
        else
            m_value = val;

        update();
    }
}

void DRoundProgressBar::setValue(int val)
{
    setValue(double(val));
}

void DRoundProgressBar::setNullPosition(double position)
{
    if (position != m_nullPosition)
    {
        m_nullPosition = position;

        if (!m_gradientData.isEmpty())
            m_rebuildBrush = true;

        update();
    }
}

void DRoundProgressBar::setBarStyle(DRoundProgressBar::BarStyle style)
{
    if (style != m_barStyle)
    {
        m_barStyle = style;

        update();
    }
}

void DRoundProgressBar::setOutlinePenWidth(double penWidth)
{
    if (penWidth != m_outlinePenWidth)
    {
        m_outlinePenWidth = penWidth;

        update();
    }
}

void DRoundProgressBar::setDataPenWidth(double penWidth)
{
    if (penWidth != m_dataPenWidth)
    {
        m_dataPenWidth = penWidth;

        update();
    }
}

void DRoundProgressBar::setDataColors(const QGradientStops &stopPoints)
{
    if (stopPoints != m_gradientData)
    {
        m_gradientData = stopPoints;
        m_rebuildBrush = true;

        update();
    }
}

void DRoundProgressBar::setFormat(const QString &format)
{
    if (format != m_format)
    {
        m_format = format;

        valueFormatChanged();
    }
}

void DRoundProgressBar::resetFormat()
{
    m_format = QString::null;

    valueFormatChanged();
}

void DRoundProgressBar::setDecimals(int count)
{
    if (count >= 0 && count != m_decimals)
    {
        m_decimals = count;

        valueFormatChanged();
    }
}

void DRoundProgressBar::paintEvent(QPaintEvent* /*event*/)
{
    double outerRadius = qMin(width(), height());

    QRectF baseRect(1, 1, outerRadius-2, outerRadius-2);
    QRectF baseRectInner(25, 25, 110, 110);
    QImage buffer(outerRadius, outerRadius, QImage::Format_ARGB32_Premultiplied);
    QPainter p(&buffer);
    p.setRenderHint(QPainter::Antialiasing);

    // data brush
    rebuildDataBrushIfNeeded();

    // background
    drawBackground(p, buffer.rect());

    // base circle 底圆环
    drawBase(p, baseRect,baseRectInner);

    // data circle
    double arcStep = 360.0 / (m_max - m_min) * m_value;
    drawValue(p, baseRect, m_value, arcStep);

    // center circle
    double innerRadius(0);
    QRectF innerRect;
    calculateInnerRect(baseRect, outerRadius, innerRect, innerRadius);
    drawInnerBackground(p, innerRect);//内圆背景

    // text
    drawText(p, innerRect, innerRadius, m_value);

    // finally draw the bar
    p.end();

    QPainter painter(this);
    painter.fillRect(baseRect, palette().background());
    painter.drawImage(0,0, buffer);


    //painter.fillRect(baseRectInner, palette().link());
    //painter.drawImage(0,0, bufferInner);
}

void DRoundProgressBar::drawBackground(QPainter &p, const QRectF &baseRect)
{
    p.fillRect(baseRect, palette().background());
}

void DRoundProgressBar::drawBase(QPainter &p, const QRectF &baseRect, const QRectF &baseRectInner)
{
    switch (m_barStyle)
    {

    case StyleDonut:
        qDebug()<<"m_barStyle1"<<m_barStyle;
        p.setPen(QPen(palette().shadow().color(), m_outlinePenWidth));
        p.setBrush(palette().dark());
        p.drawEllipse(baseRect);
        break;

    case StylePie:
        qDebug()<<"m_barStyle2"<<m_barStyle;
        p.setPen(QPen(palette().base().color(), m_outlinePenWidth));
        p.setBrush(palette().base());
        p.drawEllipse(baseRect);
        break;

    case StyleLine:
        qDebug()<<"m_barStyle3"<<m_barStyle;
        p.setPen(QPen(palette().dark().color(), m_outlinePenWidth));//底部圆环
        p.setBrush(palette().alternateBase());
        p.drawEllipse(baseRect.adjusted(m_outlinePenWidth/2, m_outlinePenWidth/2, -m_outlinePenWidth/2, -m_outlinePenWidth/2));

        innerPenWidth=30;
        p.setPen(QPen(palette().background().color(), innerPenWidth));//底部圆环
        p.setBrush(palette().background());
        p.drawEllipse(baseRectInner.adjusted(innerPenWidth/2, innerPenWidth/2, -innerPenWidth/2, -innerPenWidth/2));
        break;

    default:;
    }

}

void DRoundProgressBar::drawBaseInner(QPainter &p, const QRectF &baseRect)
{
    switch (m_barStyle)
    {

    case StyleDonut:
        p.setPen(QPen(palette().shadow().color(), m_outlinePenWidth));
        p.setBrush(palette().base());
        p.drawEllipse(baseRect);
        break;

    case StylePie:
        p.setPen(QPen(palette().base().color(), m_outlinePenWidth));
        p.setBrush(palette().base());
        p.drawEllipse(baseRect);
        break;

    case StyleLine:
        p.setPen(QPen(palette().dark().color(), m_outlinePenWidth));//底部圆环

        p.setBrush(palette().link());

        p.drawEllipse(baseRect.adjusted(m_outlinePenWidth/2, m_outlinePenWidth/2, -m_outlinePenWidth/2, -m_outlinePenWidth/2));

        //innerPenWidth=10;
        //p.drawEllipse(baseRect.adjusted(innerPenWidth/2, innerPenWidth/2, -innerPenWidth/2, -innerPenWidth/2));


        break;

    default:;
    }

}


void DRoundProgressBar::drawValue(QPainter &p, const QRectF &baseRect, double value, double arcLength)
{
    // nothing to draw
    if (value == m_min)
        return;

    // for Line style
    if (m_barStyle == StyleLine)
    {
        p.setPen(QPen(palette().highlight().color(), m_dataPenWidth));
        p.setBrush(Qt::NoBrush);
        p.drawArc(baseRect.adjusted(m_outlinePenWidth/2, m_outlinePenWidth/2, -m_outlinePenWidth/2, -m_outlinePenWidth/2),
                  m_nullPosition * 16,
                  -arcLength * 16);
        return;
    }

    // for Pie and Donut styles
    QPainterPath dataPath;
    dataPath.setFillRule(Qt::WindingFill);

    // pie segment outer
    dataPath.moveTo(baseRect.center());
    dataPath.arcTo(baseRect, m_nullPosition, -arcLength);
    dataPath.lineTo(baseRect.center());

    p.setBrush(palette().highlight());
    p.setPen(QPen(palette().shadow().color(), m_dataPenWidth));
    p.drawPath(dataPath);
}

void DRoundProgressBar::calculateInnerRect(const QRectF &/*baseRect*/, double outerRadius, QRectF &innerRect, double &innerRadius)
{
    // for Line style
    if (m_barStyle == StyleLine)
    {
        innerRadius = outerRadius - m_outlinePenWidth;
    }
    else    // for Pie and Donut styles
    {
        innerRadius = outerRadius * 0.75;
    }

    double delta = (outerRadius - innerRadius) / 2;
    innerRect = QRectF(delta, delta, innerRadius, innerRadius);
}

void DRoundProgressBar::drawInnerBackground(QPainter &p, const QRectF &innerRect)
{
    if (m_barStyle == StyleDonut)
    {
        //画圈中文字的背景色
        p.setBrush(palette().alternateBase());
        p.drawEllipse(innerRect);
    }
}

void DRoundProgressBar::drawText(QPainter &p, const QRectF &innerRect, double innerRadius, double value)
{
    if (m_format.isEmpty())
        return;

    // !!! to revise
    QFont f(font());
    f.setPixelSize(innerRadius * qMax(0.05, (0.35 - (double)m_decimals * 0.08)));
    p.setFont(f);

    QRectF textRect(innerRect);
    p.setPen(palette().text().color());
    p.drawText(textRect, Qt::AlignCenter, valueToText(value));
}

QString DRoundProgressBar::valueToText(double value) const
{
    QString textToDraw(m_format);

    if (m_updateFlags & UF_VALUE)
        textToDraw.replace("%v", QString::number(value, 'f', m_decimals));

    if (m_updateFlags & UF_PERCENT)
    {
        double procent = (value - m_min) / (m_max - m_min) * 100.0;
        textToDraw.replace("%p", QString::number(procent, 'f', m_decimals));
    }

    if (m_updateFlags & UF_MAX)
        textToDraw.replace("%m", QString::number(m_max - m_min + 1, 'f', m_decimals));

    return textToDraw;
}

void DRoundProgressBar::valueFormatChanged()
{
    m_updateFlags = 0;

    if (m_format.contains("%v"))
        m_updateFlags |= UF_VALUE;

    if (m_format.contains("%p"))
        m_updateFlags |= UF_PERCENT;

    if (m_format.contains("%m"))
        m_updateFlags |= UF_MAX;

    update();
}

void DRoundProgressBar::rebuildDataBrushIfNeeded()
{
    if (m_rebuildBrush)
    {
        m_rebuildBrush = false;

        QConicalGradient dataBrush;
        dataBrush.setCenter(0.5,0.5);
        dataBrush.setCoordinateMode(QGradient::StretchToDeviceMode);

        // invert colors
        for (int i = 0; i < m_gradientData.count(); i++)
        {
            dataBrush.setColorAt(1.0 - m_gradientData.at(i).first, m_gradientData.at(i).second);
        }

        // angle
        dataBrush.setAngle(m_nullPosition);

        QPalette p(palette());

        //已完成覆盖的圆环颜色
        //p.setColor(QPalette::, Qt::green);

        //p.setBrush(QPalette::Highlight, dataBrush);

        setPalette(p);
    }
}


void DRoundProgressBar::rebuildDataBrushIfNeededInner()
{
    if (m_rebuildBrush)
    {
        m_rebuildBrush = false;

        QConicalGradient dataBrush;
        dataBrush.setCenter(0.5,0.5);
        dataBrush.setCoordinateMode(QGradient::StretchToDeviceMode);

        // invert colors
        for (int i = 0; i < m_gradientData.count(); i++)
        {
            dataBrush.setColorAt(1.0 - m_gradientData.at(i).first, m_gradientData.at(i).second);
        }

        // angle
        dataBrush.setAngle(m_nullPosition);

        //QPalette p(palette());
        //已完成覆盖的圆环颜色
        //p.setColor(QPalette::, Qt::green);
        //p.setBrush(QPalette::Highlight, dataBrush);
        //setPalette(p);
    }
}

void DRoundProgressBar::drawBackgroundInner(QPainter &p, const QRectF &baseRect)
{
    p.fillRect(baseRect, palette().highlight());
}



