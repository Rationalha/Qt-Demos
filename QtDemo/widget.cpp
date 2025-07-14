#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(1000,860);
    setWindowFlags(Qt::FramelessWindowHint);
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->comboBox->setView(new  QListView()); //该句让ComboBox的item样式生效
    ui->comboBox->addItem(tr(u8"按钮样式"));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),
            this,SLOT(slotComboChangeHandle(int)));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_IsPressed = true;
        m_pressPoint = event->globalPos();
    }
    return QWidget::mousePressEvent(event);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_IsPressed = false;
    }
    QWidget::mouseReleaseEvent(event);
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    //过滤combox事件
    {
        if(ui->comboBox->underMouse() &&
                (event->buttons()&Qt::LeftButton) ){
            return;
        }
    }
    if (m_IsPressed) {
        QPoint point = event->globalPos() - m_pressPoint;
        move(pos() + point);
        m_pressPoint = event->globalPos();
    }
    QWidget::mouseMoveEvent(event);
}

void Widget::leaveEvent(QEvent *event)
{
    m_IsPressed = false;
    QWidget::leaveEvent(event);
}


void Widget::on_btn_close_clicked()
{
    close();
}

void Widget::slotComboChangeHandle(int index)
{
    ui->comboBox->setCurrentIndex(index);
}


void Widget::on_btn_agree_clicked()
{
    INFO->Show(tr(u8"这是一个测试信息"));
}
