#include "tabledelegate.h"

TableDelegate::TableDelegate(QObject* parent):
    QStyledItemDelegate(parent)
{
    m_icon.load(":/icons/user.png");
}
//设置表格的宽高
QSize TableDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 调用基类实现获取默认大小
    QSize size = QStyledItemDelegate::sizeHint(option, index);
    if(index.column()==0){
        size.setWidth(100); // 设置固定宽度
    }else
        size.setWidth(200); // 设置固定宽度
    size.setHeight(40); // 例如设置固定高度
    return size;
}
/*
 * 表格项的显示样式
*/
void TableDelegate::paint(QPainter *painter,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    //注意，此时index是logicIndex（model坐标），我们可以通过拖拽表头项交换列来测试
    Q_ASSERT(index.isValid());
    //QStyle会根据option的属性进行绘制，我们也可以不使用QStyle的规则，完全自定义
    QStyleOptionViewItem opt = option;
    opt.state &= ~QStyle::State_HasFocus;
    initMyStyleOption(&opt, index);

    const QWidget *widget = opt.widget;
    QStyle *style = widget ? widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
}
/*
 * 设置单元格的显示样式
 * index: 对应单元格的索引对象
 * option: 对应该对象显示的样式
*/
void TableDelegate::initMyStyleOption(QStyleOptionViewItem *option,
                                      const QModelIndex &index) const
{
    //设置字体
    QFont font;
    font.setFamily("Microsoft Yahei");
    font.setPixelSize(17);

    option->font=font;
    //对齐方式
    option->displayAlignment = Qt::AlignCenter;
    //前景色(字体颜色)
    option->palette.setBrush(QPalette::Text,QColor("#aaaaaa"));
    option->index = index;
    option->features |= QStyleOptionViewItem::HasDisplay;
    //设置显示文本内容
    option->text = getDisplayText(index); //displayText(value, option->locale);
    //背景色
    QBrush bg(QColor("#282c34"));
    option->backgroundBrush =bg;// qvariant_cast<QBrush>(index.data(Qt::BackgroundRole));

    // disable style animations for checkboxes etc. within itemviews (QTBUG-30146)
    option->styleObject = nullptr;
}

//设置显示内容
QString TableDelegate::getDisplayText(const QModelIndex &index) const
{
    //注意，此时index是logicIndex（model坐标），我们可以通过拖拽表头项交换列来测试
    const QVariant value = index.data(Qt::DisplayRole); //获取文本内容
    //我们可以根据variant的type或者index的行列来特殊处理
    switch(index.column())
    {
    default: break;
    case 0://bool
        return QString("%1").arg(value.toInt());
    case 1://int
        return value.toString();
    case 2://double
        return QString::number(value.toDouble(),'f',0);
    case 3://list
    {
        const QStringList str_list=value.toStringList();
        //这里使用userrole来保存列表的下标
        const int str_index=index.data(Qt::UserRole).toInt();
        if(str_index>=0&&str_index<str_list.count())
            //给字符串加个括号
            return QString("%1").arg(str_list.at(str_index));
    }
        break;
    case 4://string
        //给字符串加个括号
        return QString("%1").arg(value.toString());
    }
    return QString();
}

///*编辑单元格时调用的函数*/
//QWidget *TableDelegate::createEditor(QWidget *parent,
//                                     const QStyleOptionViewItem &option,
//                                     const QModelIndex &index) const
//{
//    Q_UNUSED(option)
//    //参照了实例spinboxdelegate
//    if (!index.isValid())
//        return nullptr;

//    switch(index.column())
//    {
//    default: break;
//    case 0://int
//    {
//        QSpinBox *editor=new QSpinBox(parent);
//        editor->setFrame(false);
//        editor->setMinimum(0);
//        editor->setMaximum(10000);
//        return editor;
//    }
//    case 1://string
//    {
//        QLineEdit *editor=new QLineEdit(parent);
//        editor->setFrame(false);
//        //editor->setText(index.data(Qt::DisplayRole).toString());
//        return editor;
//    }
//    case 2://int
//    {
//        QDoubleSpinBox *editor=new QDoubleSpinBox(parent);
//        editor->setFrame(false);
//        editor->setMinimum(0);
//        editor->setMaximum(100);
//        editor->setDecimals(3);
//        //editor->setValue(index.data(Qt::DisplayRole).toDouble());
//        return editor;
//    }
//    case 3://
//    {
//        QComboBox *editor=new QComboBox(parent);
//        editor->setFrame(false);
//        const QStringList str_list=index.data(Qt::DisplayRole).toStringList();
//        editor->addItems(str_list);
//        //这里使用userrole来保存列表的下标
//        //const int str_index=index.data(Qt::UserRole).toInt();
//        //if(str_index>=0&&str_index<str_list.count())
//        //    editor->setCurrentIndex(str_index);
//        return editor;
//    }
//    case 4://string
//    {
//        QLineEdit *editor=new QLineEdit(parent);
//        editor->setFrame(false);
//        //editor->setText(index.data(Qt::DisplayRole).toString());
//        return editor;
//    }
//    }
//    return nullptr;
//}
///*
// * 完成编辑单元格后调用
//*/
//void TableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    switch(index.column())
//    {
//    default: break;
//    case 0://int
//    {
//        QSpinBox *box = static_cast<QSpinBox*>(editor);
//        box->setValue(index.data(Qt::DisplayRole).toInt());
//    }break;
//    case 1://string
//    {
//        QLineEdit *line = static_cast<QLineEdit*>(editor);
//        line->setText(index.data(Qt::DisplayRole).toString());
//    }break;
//    case 2://double
//    {
//        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
//        spinBox->setValue(index.data(Qt::DisplayRole).toDouble());
//    }break;
//    case 3://list
//    {
//        QComboBox *box = static_cast<QComboBox*>(editor);
//        //这里使用userrole来保存列表的下标
//        const int str_index=index.data(Qt::UserRole).toInt();
//        if(str_index>=0&&str_index<box->count())
//            box->setCurrentIndex(str_index);
//    }break;
//    case 4://string
//    {
//        QLineEdit *edit = static_cast<QLineEdit*>(editor);
//        edit->setText(index.data(Qt::DisplayRole).toString());
//    }break;
//    }
//}

//void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    switch(index.column())
//    {
//    default: break;
//    case 0://int
//    {
//        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
//        model->setData(index,spinBox->value(),Qt::DisplayRole);

//        //        QComboBox *box = static_cast<QComboBox*>(editor);
//        //        model->setData(index,box->currentIndex()==0?true:false,Qt::EditRole);
//    }break;
//    case 1://string
//    {
//        QLineEdit *edit = static_cast<QLineEdit*>(editor);
//        model->setData(index,edit->text(),Qt::DisplayRole);
//        //        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
//        //        model->setData(index,spinBox->value(),Qt::DisplayRole);
//    }break;
//    case 2://double
//    {
//        QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox*>(editor);
//        model->setData(index,spinBox->value(),Qt::DisplayRole);
//    }break;
//    case 3://list
//    {
//        QComboBox *box = static_cast<QComboBox*>(editor);
//        //这里使用userrole来保存列表的下标
//        model->setData(index,box->currentIndex(),Qt::UserRole);
//    }break;
//    case 4://string
//    {
//        QLineEdit *edit = static_cast<QLineEdit*>(editor);
//        model->setData(index,edit->text(),Qt::DisplayRole);
//    }break;
//    }
//}

//void TableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
//{
//    Q_UNUSED(index)
//    editor->setGeometry(option.rect);
//}

