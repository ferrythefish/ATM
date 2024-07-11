#ifndef QMAIN_H
#define QMAIN_H

#include <QWidget>
#include "qinnum.h"
#include "account.h"
#include "function.h"
#include "qlog.h"
#include "qoutnum.h"
#include "qtransnum.h"
#include "qinspect.h"
#include "qcount.h"
#include "qend.h"

namespace Ui {
class Qmain;
}

class Qmain : public QWidget
{
    Q_OBJECT

public:
    explicit Qmain(Account *account,QWidget *parent = nullptr);
    ~Qmain();
    Account *user;

private slots:
    void on_pushButton_clicked(bool checked);
    void returnQmain();

    void on_pushButton_8_clicked(bool checked);

    void on_outnumButton_clicked(bool checked);

    void on_countButton_clicked(bool checked);

    void on_transButton_clicked(bool checked);

    void on_changepassbutton_clicked(bool checked);

private:
    Ui::Qmain *ui;
};

#endif // QMAIN_H
