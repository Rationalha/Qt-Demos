#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QListView>
#include <QComboBox>
#include <QMouseEvent>
#include <QTranslator>
#include <QStandardItemModel>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QTreeView>
#include "infoform.h"
#include "config.h"
#include "tablemodel.h"
#include "tabledelegate.h"
#include "buttonitemdelegate.h"
#include "customdelegate.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    void init();
    void initTableView();
    void initTreeView();
    void initTableView2();
    void initGraphicsView();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void leaveEvent(QEvent *event) override;
    QStandardItem* getTreeItem(QString item);
protected slots:

private slots:
    void on_btn_close_clicked();
    void slotComboChangeHandle(int index);
    void on_btn_agree_clicked();

    void on_btn_hide_clicked();

    void on_btn_show_clicked();

private:
    Ui::Widget *ui;
    bool   m_IsPressed;
    QPoint m_pressPoint;
    QPoint m_movePoint;

    QTranslator *m_translator;

    TableModel* m_tablemodel;
    QItemSelectionModel* m_selectionModel;
    QStandardItemModel*  model;
    TableDelegate*  m_delegate;
    ButtonItemDelegate*   m_btnDelegate;
    QTreeView*    m_treeView;
    QStandardItemModel*  m_treemodel;
    QGraphicsEllipseItem*  m_ellipse;
    QGraphicsScene*        m_scene;
    CustomDelegate*     m_custDelegate;
};
#endif // WIDGET_H
