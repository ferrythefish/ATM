#include "qend.h"
#include "ui_qend.h"


QEnd::QEnd(Account *u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QEnd),user(u)
{
    ui->setupUi(this);
    this->setWindowTitle("操作完成");

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QEnd::~QEnd()
{
    delete ui;
}

void QEnd::on_pushButton_clicked()
{
    Qmain *w;
    w=new Qmain(user);
    w->show();
    this->close();
}//继续交易，退回QMain界面


void QEnd::on_pushButton_2_clicked()
{
    QLog *w;
    w=new QLog;
    w->show();
    this->close();
}//退卡，退回QLog界面

