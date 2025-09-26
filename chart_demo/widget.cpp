#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_chart=new DChart();
    m_chart->setTitle(u8"折线数据");
    QList<QPointF> datas;
    // 生成 0 到 99 之间的随机整数
    for(int i=0;i<10;i++){
        auto x= i*10;
        auto y= QRandomGenerator::global()->bounded(50);
        datas<<QPointF(x,y);
    }
    m_chart->addData(datas);
    m_chart->setAxis(0,100,u8"X轴数据",Qt::AlignBottom);
    m_chart->setAxis(0,50,u8"Y轴数据",Qt::AlignLeft);
    m_chart->resize(1000,800);
    m_chart->show();
}

Widget::~Widget()
{
    delete ui;
}

