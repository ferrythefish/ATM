#ifndef QINSPECT_H
#define QINSPECT_H

#include <QWidget>
#include <QMessageBox>
#include "function.h"
#include "account.h"
#include "qend.h"

namespace Ui {
class QInspect;
}

class QInspect : public QWidget
{
    Q_OBJECT

public:
    explicit QInspect(Account* u,QWidget *parent = nullptr);
    ~QInspect();
    Account* user;

signals:
    void back();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QInspect *ui;
};

#endif // QINSPECT_H
