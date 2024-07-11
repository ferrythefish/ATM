#include "qmain.h"
#include "ui_qmain.h"

Qmain::Qmain(Account *account,QWidget *parent) :
    QWidget(parent),
    user(account),
    ui(new Ui::Qmain)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

Qmain::~Qmain()
{
    delete ui;
}

//返回Qmain主界面的槽函数
void Qmain::returnQmain()
{
    this->show();
}

//从Qmain主界面跳转到 存款界面
void Qmain::on_pushButton_clicked(bool checked)
{
    QInNum *qinnum =new QInNum(user);
    //此处的connect 可以实现 从存款界面返回到主界面
    connect(qinnum,SIGNAL(back()),this,SLOT(returnQmain()));
    qinnum ->setWindowTitle("存款");
    qinnum ->show();
    this -> hide();
}

//从Qmain界面返回到 登录界面
void Qmain::on_pushButton_8_clicked(bool checked)
{
    close();
    QLog * qlog = new QLog;
    qlog -> show();
}

//从Qmain主界面跳转到 取款界面
void Qmain::on_outnumButton_clicked(bool checked)
{
    QOutNum *outnum = new QOutNum(user);
    //此处的connect 可以实现 从取款界面返回到主界面
    connect(outnum,SIGNAL(back()),this,SLOT(returnQmain()));
    outnum ->setWindowTitle("取款");
    outnum ->show();
    this -> hide();
}

//从Qmain主界面跳转到 查询余额界面
void Qmain::on_countButton_clicked(bool checked)
{
    QCount *qcount =new QCount(user);
    //此处的connect 可以实现 从查询余额界面返回到主界面
    connect(qcount,SIGNAL(back()),this,SLOT(returnQmain()));
    qcount ->setWindowTitle("查询余额");
    qcount ->show();
    this -> hide();
}

//从Qmain主界面跳转到 转账界面
void Qmain::on_transButton_clicked(bool checked)
{
    QTransNum *qtransnum =new QTransNum(user);
    //此处的connect 可以实现 从查询余额界面返回到主界面
    connect(qtransnum,SIGNAL(back()),this,SLOT(returnQmain()));
    qtransnum ->setWindowTitle("转账");
    qtransnum ->show();
    this -> hide();
}

//从Qmain主界面跳转到 修改密码界面
void Qmain::on_changepassbutton_clicked(bool checked)
{
    QInspect *qinspect =new QInspect(user);
    //此处的connect 可以实现 从查询余额界面返回到主界面
    connect(qinspect,SIGNAL(back()),this,SLOT(returnQmain()));
    qinspect ->setWindowTitle("修改密码");
    qinspect ->show();
    this -> hide();
}

