#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QStyleOptionViewItem>
#include <QApplication>
#include <QComboBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QIcon>

class TableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    TableDelegate(QObject* parent=nullptr);
protected:
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void initMyStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const;
    QString getDisplayText(const QModelIndex &index) const;

//    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const override;
//    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
//    void setModelData(QWidget *editor,QAbstractItemModel *model,const QModelIndex &index) const override;
//    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const override;
private:
    QPixmap  m_icon;
};

#endif // TABLEDELEGATE_H
