#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_rect=ui->rect;
    m_rect->setText(QString::fromUtf8("理智同学"));
    m_rect->setAlignment(Qt::AlignCenter);
    m_rect->setStyleSheet("QLabel{color: rgb(0, 160, 230);}");

    m_animation=new QPropertyAnimation(this,"color");
    m_animation->setDuration(1000);
    m_animation->setKeyValueAt(0.0,0);
    m_animation->setKeyValueAt(0.2,50);
    m_animation->setKeyValueAt(0.5,100);
    m_animation->setKeyValueAt(0.7,150);
    m_animation->setKeyValueAt(1.0,255);
    m_animation->setLoopCount(-1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setColor(int color)
{
    if(color<0 || color>255)
        return ;
    QString strQSS = QString("color: rgb(0, 160, 230);"
                    " background-color: rgba(10, 160, 105, %1);").arg(color);
    m_rect->setStyleSheet(strQSS);
}


void Widget::on_btn_start_clicked()
{
     m_animation->start();
}
