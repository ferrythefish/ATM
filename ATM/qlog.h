#ifndef QLOG_H
#define QLOG_H

#include <QWidget>
#include <qpass.h>
#include <QMessageBox>
#include <fstream>
#include "qpass.h"
#include "qmain.h"
#include "account.h"
#include "qifice.h"
#include <QString>
#include <function.h>
QT_BEGIN_NAMESPACE
namespace Ui { class QLog; }
QT_END_NAMESPACE

class QLog : public QWidget
{
    Q_OBJECT

public:
    QLog(QWidget *parent = nullptr);
    ~QLog();
    //检查银行卡号是否正确
    bool check(QString usr);
    Account *account;

private slots:
    void on_loginButton_1_clicked(bool checked);

    void on_returnButton_1_clicked(bool checked);
//返回到输入银行卡号界面的槽函数
    void returnLog();

    void on_icebutton_1_clicked();

private:
    Ui::QLog *ui;
    Qpass *qpass;
    QIfIce *ifice;

};
#endif // QLOG_H
