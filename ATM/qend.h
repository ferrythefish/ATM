#ifndef QEND_H
#define QEND_H

#include <QWidget>
#include "qlog.h"
#include "qmain.h"

namespace Ui {
class QEnd;
}

class QEnd : public QWidget
{
    Q_OBJECT

public:
    explicit QEnd(Account *u,QWidget *parent = nullptr);
    Account *user;
    ~QEnd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QEnd *ui;
};

#endif // QEND_H
