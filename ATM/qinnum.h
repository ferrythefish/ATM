#ifndef QINNUM_H
#define QINNUM_H

#include <QWidget>
#include "account.h"
#include "function.h"
#include "qend.h"
#include <QMessageBox>
namespace Ui {
class QInNum;
}

class QInNum : public QWidget
{
    Q_OBJECT

public:
    explicit QInNum(Account *account,QWidget *parent = nullptr);
    ~QInNum();
    Account *user;
signals:
    void back();

private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

    void on_pushButton_5_clicked(bool checked);

    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_4_clicked();

    void on_pushButton_4_clicked(bool checked);

    void on_pushButton_7_clicked(bool checked);

    void on_pushButton_8_clicked();

private:
    Ui::QInNum *ui;
};

#endif // QINNUM_H
