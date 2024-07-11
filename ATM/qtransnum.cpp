#include "qtransnum.h"
#include "ui_qtransnum.h"
#include <QMessageBox>

QTransNum::QTransNum(Account* u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTransNum),user(u)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QTransNum::~QTransNum()
{
    delete ui;
}

void QTransNum::on_canclebutton_clicked()
{
    emit this->back();
    this->close();
}//取消按钮，退回上一界面


void QTransNum::on_determinebutton_clicked()
{
    QString qpass=ui->passwordline->text();
    std::string pass=qpass.toStdString();
    QString qnum=ui->innumline->text();
    std::string num=qnum.toStdString();
    QString qcount=ui->incountline->text();
    int coun=qcount.toInt();

    Function f;
    if(user->GetPassword()==pass){//首先验证密码是否正确

        if(f.Sign(num)==NULL){
            QMessageBox::information(this,"警告","查无此用户");
        }//验证该账号是否存在

        else{
            bool myif=f.TransCount(user,num,coun);
            if(myif==1){
                QEnd* end;
                end=new QEnd(user);
                end->show();
                this->close();
            }
            else if(myif==0){
                QMessageBox::information(this,"警告","余额不足");
            }
        }
    }
    else{
        QMessageBox::information(this,"警告","密码错误");
    }//密码错误
}//确定按钮，转账

