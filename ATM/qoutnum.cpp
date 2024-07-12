#include "qoutnum.h"
#include "ui_qoutnum.h"

QOutNum::QOutNum(Account* u,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QOutNum),user(u)
{
    ui->setupUi(this);

    setAutoFillBackground(true);
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Window,QBrush(QPixmap(":/new/prefix1/image/back.jpg").scaled(this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(palette);
}

QOutNum::~QOutNum()
{
    delete ui;
}

void QOutNum::on_onehbutton_clicked()
{
    expression+=100;
    if(expression>5000)expression=5000;
    ui->lineEdit->setText(QString::number(expression,10));
}//金额增加一百


void QOutNum::on_fivehbutton_clicked()
{
    expression+=500;
    if(expression>5000)expression=5000;
    ui->lineEdit->setText(QString::number(expression,10));
}//金额增加五百


void QOutNum::on_onetbutton_clicked()
{
    expression+=1000;
    if(expression>5000)expression=5000;
    ui->lineEdit->setText(QString::number(expression,10));
}//金额增加一千


void QOutNum::on_twotbutton_clicked()
{
    expression+=2000;
    if(expression>5000)expression=5000;
    ui->lineEdit->setText(QString::number(expression,10));
}//金额增加两千


void QOutNum::on_threembutton_clicked()
{
    expression+=3000;
    if(expression>5000)expression=5000;
    ui->lineEdit->setText(QString::number(expression,10));
}//金额增加三千


void QOutNum::on_changebutton_clicked()
{
    expression=0;
    ui->lineEdit->clear();
}//清空金额


void QOutNum::on_determinebutton_clicked()
{
    expression=(ui->lineEdit->text()).toUInt();
   if(user->OutCount(expression) == 1){
        QEnd *end;
        end=new QEnd(user);
        end->show();
        this->close();
   }
   else if(user->OutCount(expression) == 2)
       QMessageBox::information(this,"警告","余额不足");
   else if(user->OutCount(expression) == 3)
       QMessageBox::information(this,"警告","取款失败,超过单笔取款上限");
    else{
        QMessageBox::information(this,"警告","取款金额不符合要求");
    }
}//确定按钮，若该账户金额充足则扣除金额并跳转到QEnd界面，若不足则弹出警告



void QOutNum::on_canclebutton_clicked()
{
    emit this->back();
    this->close();
}//取消按钮，退回上一界面

