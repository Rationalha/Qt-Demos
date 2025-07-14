#ifndef INFOFORM_H
#define INFOFORM_H

#include <QWidget>



namespace Ui {
class InfoForm;
}

#define INFO  InfoForm::instance()

class InfoForm : public QWidget
{
    Q_OBJECT
public:
    static InfoForm* instance();
    ~InfoForm();
    void Show(QString info);
private:
    explicit InfoForm(QWidget *parent = nullptr);

private slots:
    void on_btn_disagree_clicked();

private:
    Ui::InfoForm *ui;
    static InfoForm*  m_self;
};

#endif // INFOFORM_H
