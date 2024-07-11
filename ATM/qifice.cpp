#include "qifice.h"
#include "ui_qifice.h"

QIfIce::QIfIce(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QIfIce)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QIfIce::~QIfIce()
{
    delete ui;
}

void QIfIce::on_canclebutton_clicked()
{
    emit this->back();
    this->close();
}//取消按钮，退回登陆界面


void QIfIce::on_determinebutton_clicked()
{
    Function f;
    QString qstr=ui->lineEdit->text();
    std::string str=qstr.toStdString();
    int num=f.IfIce(str);
    if(num==0){
        QMessageBox::information(this,"结果","您的帐户未冻结");
    }
    else if(num==1){
        QMessageBox::information(this,"结果","您的帐户已冻结");
    }
    else if(num==2){
        QMessageBox::information(this,"结果","查无此账户");
    }
}//确定按钮，显示输入的账号是否冻结或“查无此账号”

