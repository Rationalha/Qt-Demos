#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QRandomGenerator>
#include "dchart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    DChart*   m_chart;
};
#endif // WIDGET_H
