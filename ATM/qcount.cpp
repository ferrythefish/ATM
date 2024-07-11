#include "qcount.h"
#include "ui_qcount.h"

QCount::QCount(Account* u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QCount),user(u)
{
    ui->setupUi(this);

    int c=user->GetCount();
    QString expression=QString::number(c);
    ui->moneylable->setText(expression);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);

}

QCount::~QCount()
{
    delete ui;
}

void QCount::on_backbutton_clicked()
{
    emit this->back();
    this->close();
}//返回按钮


void QCount::on_pushButton_clicked()
{
    emit this->back();
    this->close();
}//确定按钮

