#include "qpass.h"
#include "ui_qpass.h"
#include "qmain.h"
#include "qpushbutton.h"
Qpass::Qpass(Account *account,QWidget *parent) :
    QWidget(parent),user(account),
    ui(new Ui::Qpass)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

Qpass::~Qpass()
{
    delete ui;
}

void Qpass::on_pushButton_clicked(bool checked)
{
    //从密码界面跳转到主界面
    Qmain *qmain = new Qmain(user);
    qmain->setWindowTitle("主界面");
    //调用密码检验的函数，用户输入错误5次会被冻结
     int num = f.InspectPass(user,ui->userpassword->text().toStdString());
    if(num==1)
    {
        ui->userpassword->clear();
        this->hide();
        qmain->show();
    }
    else if(num== 2)
    {
        QMessageBox::warning(this,tr("登录失败"),tr("该账户已被冻结，请自行联系管理员"),QMessageBox::Ok);
    }
    else
    {
        ui->userpassword->clear();
        QMessageBox::warning(this,tr("登录失败"),tr("密码错误"),QMessageBox::Ok);
    }
}


void Qpass::on_pushButton_2_clicked(bool checked)
{
    //产生信号
        this->hide();
        emit returnQlogSignal();
}

