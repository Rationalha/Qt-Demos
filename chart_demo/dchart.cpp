#include "dchart.h"

DChart::DChart()
{
    initChart();
}

void DChart::setTitle(QString title)
{
    if(m_chart)
        m_chart->setTitle(title);
}

void DChart::addData(QList<QPointF> datas)
{
    m_points->setName(u8"测试数据");
    m_points->setPen(QPen(QBrush(Qt::green),2));
    m_labelPoints->setMarkerSize(0); // 隐藏默认散点
    m_labelPoints->setBorderColor(Qt::transparent);
    // 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
    m_points->setUseOpenGL(true);
    for(auto p:datas){
        m_points->append(p);
        m_labelPoints->append(p); // 与折线图相同的坐标
    }
    // 自定义散点图的绘制代理（显示文本）
    m_labelPoints->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
    m_labelPoints->setBrush(Qt::transparent);
    m_labelPoints->setPen(QPen(Qt::transparent));
    m_chart->addSeries(m_labelPoints);
    m_chart->addSeries(m_points);

}

void DChart::setAxis(double min,double max,QString title,Qt::Alignment pos)
{
    //设置x,y轴
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(12);
    font.setBold(true);
    QValueAxis *axis=new QValueAxis();
    axis->setRange(min,max);             // 设置坐标轴范围
    axis->setLabelFormat("%.1f");      // 标签格式
    axis->setTickCount(11);            // 主分隔个数
    axis->setMinorTickCount(0);        // 设置轴上每个刻度之间的小刻度数量
    axis->setTitleText(title);      // 标题
    axis->setLabelsFont(font);

    m_chart->addAxis(axis,pos);
    m_points->attachAxis(axis);
    m_labelPoints->attachAxis(axis);
}

void DChart::initChart()
{
    m_chart = new QChart();
    m_points = new QLineSeries();
    m_labelPoints = new QScatterSeries();
    m_chart->setTheme(QChart::ChartThemeDark); //会覆盖title，需要先设置
    // 设置字体
    QFont titleFont;
    titleFont.setFamily("Arial");
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    // 设置图表标题的字体
    m_chart->setTitleFont(titleFont);
    m_chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置图例
    QLegend* legend=m_chart->legend();
    legend->setVisible(true);
    legend->setBackgroundVisible(false);
    legend->setAlignment(Qt::AlignBottom);
    legend->setFont(titleFont);
    legend->setColor(Qt::white);
    // 创建默认的坐标系（笛卡尔坐标）
    m_chart->createDefaultAxes();

    //设置view
    setChart(m_chart);
    // 开启抗锯齿，让显示效果更好
    setRenderHint(QPainter::Antialiasing);
}

void DChart::paintEvent(QPaintEvent *event)
{
    QChartView::paintEvent(event);
    QPainter painter(viewport());
    painter.setPen(Qt::white);
    QPointF offset(5,-5);
    // 绘制文本标签
    QScatterSeries *series = static_cast<QScatterSeries*>(chart()->series()[1]);
    auto points = series->pointsVector();
    for (const QPointF &point : points) {
        QPointF pixelPos = chart()->mapToPosition(point);
        painter.drawText(pixelPos+offset, QString("(%1,%2)").arg(point.x()).arg(point.y()));
    }
}
