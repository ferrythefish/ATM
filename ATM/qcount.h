#ifndef QCOUNT_H
#define QCOUNT_H

#include <QWidget>
#include "account.h"
#include "qend.h"

namespace Ui {
class QCount;
}

class QCount : public QWidget
{
    Q_OBJECT

public:
    explicit QCount(Account* u,QWidget *parent = nullptr);
    ~QCount();
    Account* user;

signals:
    void back();

private slots:
    void on_backbutton_clicked();

    void on_pushButton_clicked();

private:
    Ui::QCount *ui;
};

#endif // QCOUNT_H
