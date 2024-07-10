#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int color READ getColor WRITE setColor)
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int getColor(){ return _color;}
    void  setColor(int color);
private slots:
    void on_btn_start_clicked();

private:
    Ui::Widget *ui;
    int _color;
    QPropertyAnimation* m_animation;
    QLabel* m_rect;
};
#endif // WIDGET_H
