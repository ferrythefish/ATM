#include "qinspect.h"
#include "ui_qinspect.h"

QInspect::QInspect(Account* u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QInspect),user(u)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QInspect::~QInspect()
{
    delete ui;
}

void QInspect::on_pushButton_clicked()
{
    emit this->back();
    this->close();
}//取消按钮


void QInspect::on_pushButton_2_clicked()
{
    QString oldpass=ui->oldpassline->text();
    QString newpass=ui->newpassline->text();
    QString newpagain=ui->newpassline_2->text();

    std::string oldp=oldpass.toStdString();
    std::string newp=newpass.toStdString();
    std::string newpa=newpagain.toStdString();
    if((user->GetPassword())==oldp){
        if(newp==newpa){
            user->ChangePassword(newp);
            QMessageBox::information(this,"提示","密码修改成功");
            emit this->back();
            this->close();
        }
        else{
            QMessageBox::information(this,"警告","两次输入的密码不一致，请重新输入");
        }
    }
    else{
        QMessageBox::information(this,"警告","原密码错误");
    }
}//确定按钮

