#ifndef QTRANSNUM_H
#define QTRANSNUM_H

#include <QWidget>
#include <QMessageBox>
#include "account.h"
#include "function.h"
#include "qend.h"

namespace Ui {
class QTransNum;
}

class QTransNum : public QWidget
{
    Q_OBJECT

public:
    explicit QTransNum(Account* u,QWidget *parent = nullptr);
    ~QTransNum();
    Account* user;

signals:
    void back();

private slots:
    void on_canclebutton_clicked();

    void on_determinebutton_clicked();

private:
    Ui::QTransNum *ui;
};

#endif // QTRANSNUM_H
