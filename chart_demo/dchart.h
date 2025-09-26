#ifndef DCHART_H
#define DCHART_H

#include <QObject>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QList>
#include <QScatterSeries>

QT_CHARTS_USE_NAMESPACE

class DChart:public QChartView
{
    Q_OBJECT
public:
    DChart();
    void setTitle(QString title);
    void addData(QList<QPointF>  datas);
    void setAxis(double min,double max,QString title,Qt::Alignment pos);
protected:
    void initChart();
    void paintEvent(QPaintEvent *event) override;
private:
    QChart       *m_chart;
    QLineSeries *m_points;
    QScatterSeries *m_labelPoints;
};

#endif // DCHART_H
