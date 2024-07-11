#include "qinnum.h"
#include "ui_qinnum.h"
QInNum::QInNum(Account *account,QWidget *parent) :
    QWidget(parent),
    user(account),
    ui(new Ui::QInNum)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QInNum::~QInNum()
{
    delete ui;
}

//+100
void QInNum::on_pushButton_clicked(bool checked)
{
    QString a =this->ui->count->text();
    int b =a.toInt()+100;
    a = QString::number(b);
    this->ui->count->setText(a);
}

//+500
void QInNum::on_pushButton_2_clicked(bool checked)
{
    QString a =this->ui->count->text();
    int b =a.toInt()+500;
    a = QString::number(b);
    this->ui->count->setText(a);
}

//+2000
void QInNum::on_pushButton_3_clicked(bool checked)
{
    QString a =this->ui->count->text();
    int b =a.toInt()+2000;
    a = QString::number(b);
    this->ui->count->setText(a);
}

//+3000
void QInNum::on_pushButton_6_clicked(bool checked)
{
    QString a =this->ui->count->text();
    int b =a.toInt()+3000;
    a = QString::number(b);
    this->ui->count->setText(a);
}

//清0
void QInNum::on_pushButton_5_clicked(bool checked)
{

    this->ui->count->setText("");
}

//存款

void QInNum::on_pushButton_4_clicked(bool checked)
{
  //存款成功
    if((user->InCount(this->ui->count->text().toInt())==1)){
        QEnd *end=new QEnd(user);
        end->show();
        this->close();
    }
    else if((user->InCount(this->ui->count->text().toInt())==0))
        QMessageBox::warning(this,tr("存款失败"),tr("存款失败"),QMessageBox::Ok);
    else
        QMessageBox::warning(this,tr("存款失败"),tr("存款失败,超过单笔存款上限"),QMessageBox::Ok);

}
//没用
void  QInNum::on_pushButton_4_clicked()
{}


//存款界面返回到Qmain主界面
void QInNum::on_pushButton_7_clicked(bool checked)
{
    //产生信号 并且关闭存款界面
    emit back();
    close();
}

//+1000
void QInNum::on_pushButton_8_clicked()
{
    QString a =this->ui->count->text();
    int b =a.toInt()+1000;
    a = QString::number(b);
    this->ui->count->setText(a);
}

