#include "infoform.h"
#include "ui_infoform.h"

InfoForm::InfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
}

InfoForm*  InfoForm::m_self=nullptr;
InfoForm *InfoForm::instance()
{
    if(m_self==nullptr)
        m_self=new InfoForm();
    return m_self;
}

InfoForm::~InfoForm()
{
    delete ui;
}

void InfoForm::Show(QString info)
{
    ui->label->setText(info);
    show();
}

void InfoForm::on_btn_disagree_clicked()
{
    close();
}

