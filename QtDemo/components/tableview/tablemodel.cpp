#include "tablemodel.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
    m_headData<<"ID"<<"姓名"<<"年龄"<<"性别"<<"部门";
    m_icon.load(":/icons/user.png");
}

/*在表格末尾追加一行数据*/
void TableModel::appendRow(TableData data)
{
    int cnt=m_datas.size();
    //需要将操作放到beginInsertRows和endInsertRows两个函数调用之间
    beginInsertRows(QModelIndex(), cnt, cnt);
    //在接口对应行插入空数据
    m_datas.insert(cnt,data);
    endInsertRows();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return m_datas.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return m_headData.size();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) // 返回一个默认数据的表头
        return QAbstractTableModel::headerData(section, orientation, role);

    // 仅仅只是返回水平方向的表头
    if (orientation == Qt::Orientation::Horizontal) {
        return this->m_headData[section];
    }

    return QAbstractTableModel::headerData(section, orientation, role);
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    // 不存在则返回默认
    if (!index.isValid())
        return QVariant();

    // 如果角色为显示和编辑模式
    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        //索引对应的数据
        switch (index.column()) {
        case 0:
            return m_datas[index.row()].id;
            break;

        case 1:
            return m_datas[index.row()].name;
            break;

        case 2:
            return m_datas[index.row()].age;
            break;

        case 3:
            return m_datas[index.row()].gender;
            break;

        case 4:
            return m_datas[index.row()].department;
            break;
        default:
            return QVariant();
            break;
        }
    }else if (role == Qt::TextAlignmentRole) {   //对其方式
        return Qt::AlignCenter; //对齐格式为居中
    }else if(role==Qt::FontRole){  //设置字体
        return m_Font;
    }else if(role==Qt::DecorationRole)
        if(index.column()==0)
            return m_icon;

    return QVariant();
}


// 返回模型索引
QModelIndex TableModel::index(int row, int column, const QModelIndex &parent) const {
    // 行和列的合法性检查
    if (row < 0 || row >= m_datas.size()
            || column < 0 || column >= m_headData.size()) {
        return QModelIndex();
    }
    int id=0,age;
    QString name,gender,department;
    switch (column) {
    case 0:
        // 获取对应行和列单元格的数据
        id = m_datas[row].id;
        // 新建一个索引并绑定指针数据返回
        return createIndex(row, column, &id);
        break;

    case 1:
        name = m_datas[row].name;
        return createIndex(row, column,&name);
        break;

    case 2:
        age=m_datas[row].age;
        return createIndex(row, column,&age);
        break;

    case 3:
        gender=m_datas[row].gender;
        return createIndex(row, column,&gender);
        break;

    case 4:
        department=m_datas[row].department;
        return createIndex(row, column,&department);
        break;

    default:
        return createIndex(row, column);
        break;
    }


    return createIndex(row, column);
}

// 返回模型索引的编辑方式
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        // 返回用户可以与界面进行交互
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    }

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

// 设置模型索引数据
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role == Qt::EditRole) {
        switch (index.column()) {
        case 0:
            m_datas[index.row()].id=value.toInt();
            break;
        case 1:
            m_datas[index.row()].name=value.toString();
            break;

        case 2:
            m_datas[index.row()].age=value.toInt();
            break;

        case 3:
            m_datas[index.row()].gender=value.toString();
            break;

        case 4:
            m_datas[index.row()].department=value.toString();
            break;

        default:
            break;
        }
        // 设置完成后发射信号告诉视图数据有修改
        emit dataChanged(index, index);	// 参数是左上角和右下角的模型索引（这里是相同的）

        return true;

    } else if (index.isValid() && role == Qt::CheckStateRole) {


        return true;
    }

    return false;
}

// 插入行	参数：插入的位置；插入的行数；父项的模型索引
bool TableModel::insertRows(int row, int count, const QModelIndex &parent) {
    // 如果插入零行，则返回false，表示插入失败
    if (count == 0) return false;

    // 没有父类
    if (!parent.isValid()) {
        // 从row开始插入行，直到row + count - 1处
        beginInsertRows(QModelIndex(), row, row + count - 1);

        // 有父类
    } else {
        // 从row开始插入行，直到row + count - 1处
        beginInsertRows(parent, row, row + count - 1);
    }

    // 按照位置在链表对应位置进行插入数据
    for (int addCount = 0; addCount < count; addCount++) {
        TableData data;
        data.id=0;
        data.name="";
        data.age=0;
        data.gender="";
        data.department="";
        m_datas.insert(row + addCount,data);
    }


    // 结束插入行
    endInsertRows();

    return true;
}

// 删除行
bool TableModel::removeRows(int row, int count, const QModelIndex &parent) {
    if (count == 0) return false;

    if (!parent.isValid()) {
        beginRemoveRows(QModelIndex(), row, row + count - 1);
    } else {
        beginInsertRows(parent, row, row + count - 1);
    }

    // 按照位置在链表对应位置进行移除数据
    for (int removeCount = 0; removeCount < count; removeCount++) {
        m_datas.remove(row);
    }

    endRemoveRows();
    return true;
}






