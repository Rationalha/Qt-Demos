#include "ttksplititemlabel.h"

#include <QPainter>
#include <QMouseEvent>
#include <QFontMetrics>

TTKSplitItemLabel::TTKSplitItemLabel(QWidget *parent)
    : QLabel(parent)
{
    setAlignment(Qt::AlignVCenter);
    setMouseTracking(true);
}

void TTKSplitItemLabel::enterEvent(QEvent *event)
{
    QLabel::enterEvent(event);
    m_lineGeometry = QRectF();
    m_currentString.clear();
    update();
}

void TTKSplitItemLabel::leaveEvent(QEvent *event)
{
    QLabel::leaveEvent(event);
    m_lineGeometry = QRectF();
    m_currentString.clear();
    update();
}

void TTKSplitItemLabel::mousePressEvent(QMouseEvent *event)
{
    QLabel::mousePressEvent(event);
    if(event->button() == Qt::LeftButton && !m_currentString.isEmpty())
    {
        emit changed(m_currentString);
    }
}

void TTKSplitItemLabel::mouseMoveEvent(QMouseEvent *event)
{
    QLabel::mouseMoveEvent(event);

    unsetCursor();
    m_lineGeometry = QRectF();
    m_currentString.clear();

    QFontMetrics metrics = QFontMetrics(font());
    QStringList data(text().split(" - "));
    int offset = 0;
    foreach(const QString &var, data)
    {
        int fs = metrics.width(var.trimmed());
        if(offset <= event->pos().x() && event->pos().x() <= offset + fs)
        {
            setCursor(QCursor(Qt::PointingHandCursor));
            m_lineGeometry = QRectF(offset, height() - 3, fs, 0.5);
            m_currentString = var.trimmed();
            break;
        }
        offset += (fs + metrics.width(" - "));
    }
    update();
}

void TTKSplitItemLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    painter.drawRect(m_lineGeometry);
    painter.end();
}
