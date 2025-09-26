#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    showFullScreen();
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
    ui->comboBox->addItem(tr(u8"TreeView"));
    ui->comboBox->addItem(tr(u8"GraphicsView"));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),
            this,SLOT(slotComboChangeHandle(int)));

    initTableView();
    initTreeView();
    initGraphicsView();
}

void Widget::initTableView()
{
    ui->tableView->verticalHeader()->hide();
    // 设置表头数据
    QHeaderView* header=ui->tableView->horizontalHeader();
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(18);
    header->setFont(font);
    header->setFixedHeight(50);
    header->setStyleSheet(
        "QHeaderView::section {"
        "color:#aaaaaa;"
        "background-color: #282C34;"
        "padding: 4px;"
        "border: none;"
        "font-weight: bold;"
        "}"
    );
    model = new QStandardItemModel(this);
    QStringList headers = {"Id", "Name", "Age","Gender","Department","opt"};
    model->setHorizontalHeaderLabels(headers);


    //模拟一份固定的数据表
    const int col_count=6;
    const int row_count=10;
    for(int row=0;row<row_count;row++)
    {
        for(int col=0;col<col_count;col++)
        {
            QStandardItem *new_item=new QStandardItem;
            switch(col)
            {
            default: break;
                //int
            case 0:
                new_item->setData(row,Qt::DisplayRole);
                break;
                //string
            case 1:
                new_item->setData(QString::number(row),Qt::DisplayRole);
                break;
                //doublespinbox double
            case 2:
                new_item->setData(row,Qt::DisplayRole);
                break;
                //combobox list
            case 3:
                new_item->setData(row,Qt::DisplayRole);
                break;
                //linedit string
            case 4:
                new_item->setData(QString(u8"软件部门"),Qt::DisplayRole);
                break;
            }
            model->setItem(row, col, new_item);
        }
    }
    //view会根据model提供的数据来渲染
    ui->tableView->setModel(model);
    m_custDelegate=new CustomDelegate(this);
    ui->tableView->setItemDelegate(m_custDelegate);
    //resize模式，delegate的sizeHint才会生效
    ui->tableView->setShowGrid(false);
    ui->tableView->setFrameShape(QFrame::NoFrame);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //采用拉伸模式的话，delegate里设置的宽度将无效
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void Widget::initTreeView()
{
    QHBoxLayout *mainLayout = new QHBoxLayout;

    m_treeView = new QTreeView();
    m_treeView->header()->setVisible(false);

    m_treemodel = new QStandardItemModel(m_treeView);

    QStandardItem *itemRoot=getTreeItem(tr("ALL"));
    m_treemodel->appendRow(itemRoot);

    for (int i = 0; i < 3; i++) {
        QStandardItem *itemRt =getTreeItem(QString("RT%1").arg(i));
        itemRoot->appendRow(itemRt); //根节点子节点

        QStandardItem *itemRecv =getTreeItem(tr("Recv"));
        itemRt->appendRow(itemRecv); //二级子节点
        for (int j = 0; j < 3; j++) {
            QStandardItem *itemSA =getTreeItem(QString("SA%1").arg(j));
            itemRecv->appendRow(itemSA);
        }

        QStandardItem *itemSend =getTreeItem(tr("Send"));
        itemRt->appendRow(itemSend);//二级子节点
        for (int j = 0; j < 3; j++) {
            QStandardItem *itemSA =getTreeItem(QString("SA%1").arg(j));
            itemSend->appendRow(itemSA);//三级子节点
        }
    }

    m_treeView->setModel(m_treemodel);
    mainLayout->addWidget(m_treeView);
    ui->page_treeview->setLayout(mainLayout);
}

void Widget::initTableView2()
{
    //设置表头样式与内容

}

void Widget::initGraphicsView()
{
    m_ellipse= new QGraphicsEllipseItem(-50, -50,100,100);
    m_ellipse->setBrush(QBrush(Qt::gray));
    m_ellipse->setPen(QPen(Qt::black));
    m_scene=new QGraphicsScene();
    ui->graphicsView->setScene(m_scene);
    m_scene->addItem(m_ellipse);
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

QStandardItem *Widget::getTreeItem(QString item)
{
    QStandardItem *treeitem = new QStandardItem(item); //根节点
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(18);
    treeitem->setFont(font);

    treeitem->setCheckable(true);
    treeitem->setTristate(true); //支持三种状态：选中，未选中，部分选中
    treeitem->setEditable(false);//不可编辑
    return treeitem;
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

void Widget::on_btn_hide_clicked()
{
    m_ellipse->hide();
}


void Widget::on_btn_show_clicked()
{
    m_ellipse->show();
}

