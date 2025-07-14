#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QObject>
#include <QFont>
#include <QPixmap>

#pragma execution_character_set("utf-8") // qt支持显示中文

struct TableData{
    int  id;
    QString name;
    int  age;
    QString gender;
    QString department;
};


class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = nullptr);
    void appendRow(TableData data);
    // 返回行个数
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    // 返回列个数
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    // 返回头文本
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    // 返回索引数据
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    // 返回模型索引
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    // 返回模型索引的编辑方式
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    // 设置模型索引数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    // 插入行
    virtual bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    // 删除行
    virtual bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
    QStringList m_headData; //表头数据
    QMap<int, TableData> m_datas;    //显示的数据
    QFont m_Font;
    QPixmap  m_icon;
};

#endif // TABLEMODEL_H
