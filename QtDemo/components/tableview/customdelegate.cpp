#include "customdelegate.h"

CustomDelegate::CustomDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}
/*设置单元格大小*/
QSize CustomDelegate::sizeHint(const QStyleOptionViewItem &option,
                               const QModelIndex &index) const
{
    //获取单元格默认大小
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    if(index.column()==0)
        size.setWidth(200);
    else
        size.setWidth(330);
    size.setHeight(50);

    return size;
}

/*设置单元格样式*/
void CustomDelegate::paint(QPainter *painter,
                           const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    Q_ASSERT(index.isValid());
    QStyleOptionViewItem opt(option);
    if(index.column()==0){
        initButtonOption(painter,&opt,index);
        return;
    }else
        initTextOption(&opt,index);
    QApplication::style()->drawControl(QStyle::CE_ItemViewItem,&opt,painter);
}

void CustomDelegate::initTextOption(QStyleOptionViewItem *option, const QModelIndex &index) const
{
    QString value=index.data(Qt::DisplayRole).toString();
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(17);
    //1. 设置字体
    option->font=font;
    //2. 设置字体颜色
    if(value==u8"离线")
        option->palette.setColor(QPalette::Text,Qt::red);
    else if(value==u8"在线")
        option->palette.setColor(QPalette::Text,Qt::green);
    else
        option->palette.setColor(QPalette::Text,Qt::white);
    //3. 设置背景色
    QBrush bg(QColor("#282c34"));
    option->backgroundBrush =bg;// qvariant_cast<QBrush>(index.data(Qt::BackgroundRole));
    //4.设置文本内容
    option->text=value;
    //5.文本居中
    //对齐方式
    option->displayAlignment = Qt::AlignCenter;
}

void CustomDelegate::initButtonOption(QPainter *painter,QStyleOptionViewItem *option,const QModelIndex &index) const
{
#if 0 //使用QStyleOptionButton实现，不灵活，很多效果实现不了
    QStyleOptionButton button;
    button.rect=QRect(option->rect.left()+10,option->rect.top(),option->rect.width(),option->rect.height());
    button.text=index.data(Qt::DisplayRole).toString();
    button.iconSize=QSize(28,28);
    button.icon=QIcon(QString(":/icons/sub.png"));
    // 设置按钮状态
    button.state |= QStyle::State_Enabled; // 启用状态
    button.state |= QStyle::State_Sunken;  // 按下状态
    button.state |= QStyle::State_MouseOver; // 鼠标悬停状态
    // 设置按钮特性
    button.features |= QStyleOptionButton::Flat; // 扁平样式
    button.features |= QStyleOptionButton::DefaultButton; // 默认按钮
    QApplication::style()->drawControl(QStyle::CE_PushButton, &button, painter);
#endif
    //  保存原始画笔
    painter->save();
    // 设置背景色
    if (option->state & QStyle::State_Selected) {
        painter->fillRect(option->rect, option->palette.highlight());
    } else {
        painter->fillRect(option->rect, QColor("#282c34")); // 浅灰色背景
    }
    QRect iconRect=QRect(option->rect.left()+10,
                         option->rect.top()+15,20,20);
    QPixmap iconPix(":/icons/sub.png");
    painter->drawPixmap(iconRect,iconPix);

    // 设置文本颜色
    painter->setPen(Qt::white);
    // 获取单元格数据
    QString text = index.data(Qt::DisplayRole).toString();
    // 绘制文本（带边距）
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(20);
    painter->setFont(font);

    QRect textRect =QRect(iconRect.right(),iconRect.top()-15,120,50);
    painter->drawText(textRect, Qt::AlignCenter, text);
    // 恢复画笔
    painter->restore();
}

QWidget *CustomDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget* editor = QStyledItemDelegate::createEditor(parent, option, index);
    editor->installEventFilter(const_cast<CustomDelegate*>(this));
    editor->setAttribute(Qt::WA_Hover);
    editor->setMouseTracking(true);
    return editor;
}

bool CustomDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(index.column()==0){  //处理hover事件
        QMouseEvent *pEvent = static_cast<QMouseEvent *> (event);
        m_mousePoint = pEvent->pos();
        switch (event->type()) {
        case QEvent::MouseMove:
            qDebug()<<"hover";
            break;
        case QEvent::MouseButtonPress:
            qDebug()<<"Press";
            break;
        case QEvent::MouseButtonRelease:
            qDebug()<<"Release";
            break;
        }
    }
    return true;
}

bool CustomDelegate::eventFilter(QObject* object, QEvent* event)
{
    if (event->type() == QEvent::HoverEnter ||
        event->type() == QEvent::HoverMove) {
        // 处理hover事件
        qDebug() << "Hover event captured";
        return true;
    }
    return QStyledItemDelegate::eventFilter(object, event);
}


