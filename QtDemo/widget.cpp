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
    if(Conf->getLanguage()==1){
        m_translator = new QTranslator(this); // 创建翻译器
        m_translator->load(":/lang_english.qm");
        qApp->installTranslator(m_translator); // 安装翻译器
        ui->retranslateUi(this); // 重新翻译界面
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    ui->comboBox->setView(new  QListView()); //该句让ComboBox的item样式生效
    ui->comboBox->addItem(tr(u8"按钮样式"));
    ui->comboBox->addItem(tr(u8"TableView"));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),
            this,SLOT(slotComboChangeHandle(int)));

    initTableView();

}

void Widget::initTableView()
{
   m_tablemodel=new TableModel();
   ui->tableView->setModel(m_tablemodel);
   ui->tableView->verticalHeader()->hide(); //隐藏垂直表头
   // 表格宽度自动根据UI进行计算，不可手动调整宽度
   ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   // 显示网格线
   ui->tableView->setShowGrid(true);
   // 线的样式
   ui->tableView->setGridStyle(Qt::DotLine);
   //设置选中时为整行选中
   ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
   for(int i=0;i<10;i++){
       TableData tmp;
       tmp.id=i;
       tmp.name=QString("Student_%1").arg(i);
       tmp.gender=i%2==0 ? "male":"female";
       tmp.age=29;
       tmp.department=u8"软件部门";
       m_tablemodel->appendRow(tmp);
   }
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
    ui->stackedWidget->setCurrentIndex(index);
}


void Widget::on_btn_agree_clicked()
{
    INFO->Show(tr(u8"这是一个测试信息"));
}
