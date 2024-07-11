#include "qlog.h"
#include "ui_qlog.h"
using namespace std;
QLog::QLog(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QLog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录界面");

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QLog::~QLog()
{
    delete ui;
}


void QLog::on_loginButton_1_clicked(bool checked)
{

       string usr = ui->usernumber->text().toStdString();
//        string name,number,password;
//        int count,isice;

        Function f;
//调用登录函数，如果用户文件中包含用户的银行卡号，则返回Account类对象的指针
        Account *user = f.Sign(usr);

        if(user!=NULL)
      {
          qpass = new Qpass(user);
          qpass->resize(600,400);
          qpass->setWindowTitle("登录界面");
          //此处的connect 可以实现 从Qpass页面跳转到Qlog页面
          connect(qpass,SIGNAL(returnQlogSignal()),this,SLOT(returnLog()));
          this->hide();
          qpass->show();
      }
        else
        QMessageBox::warning(this,tr("登录失败"),tr("查无此银行卡号"),QMessageBox::Ok);
}


void QLog::on_returnButton_1_clicked(bool checked)
{
    close();
}

void QLog::returnLog()
{
    this->show();
}


void QLog::on_icebutton_1_clicked()
{
    ifice=new QIfIce;
    ifice->setWindowTitle("查询账户是否冻结");
    connect(ifice,SIGNAL(back()),this,SLOT(returnLog()));
    this->hide();
    ifice->show();
}

