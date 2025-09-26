#ifndef BUTTONITEMDELEGATE_H
#define BUTTONITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QPushButton>
#include <QApplication>
#include <QMouseEvent>
#include <QToolTip>

#define FILE_OPERATE_COLUMN 5

class ButtonItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT

   public:
       explicit ButtonItemDelegate(QWidget *parent = 0);
       ~ButtonItemDelegate(){};
       void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
       bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);

   signals:
       void open(const QModelIndex &index);
       void deleteData(const QModelIndex &index);

   private:
       QPoint m_mousePoint;  // 鼠标位置
       QScopedPointer<QPushButton> m_pOpenButton;
       QScopedPointer<QPushButton> m_pDeleteButton;
       QStringList m_list;
       int m_nSpacing;  // 按钮之间的间距
       int m_nWidth;  // 按钮宽度
       int m_nHeight;  // 按钮高度
       int m_nType;  // 按钮状态-1：划过 2：按下
};

#endif // BUTTONITEMDELEGATE_H
