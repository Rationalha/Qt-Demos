#ifndef CUSTOMDELEGATE_H
#define CUSTOMDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QEvent>
#include <QDebug>
#include <QMouseEvent>

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CustomDelegate(QObject *parent = nullptr);
protected:
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    // painting
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    void initTextOption(QStyleOptionViewItem *option, const QModelIndex &index) const;
    void initButtonOption(QPainter *painter,QStyleOptionViewItem *option,const QModelIndex &index) const;

    // editing
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    bool eventFilter(QObject* object, QEvent* event) override;
    bool editorEvent(QEvent *event,
                     QAbstractItemModel *model,
                     const QStyleOptionViewItem &option,
                     const QModelIndex &index) override;

private:
    QPoint m_mousePoint;
};

#endif // CUSTOMDELEGATE_H
