#ifndef QOUTNUM_H
#define QOUTNUM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include "qend.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QOutNum; }
QT_END_NAMESPACE

class QOutNum : public QWidget
{
    Q_OBJECT

public:
    Account* user;
    QOutNum(Account* u,QWidget *parent = nullptr);
    ~QOutNum();

signals:
    void back();

private slots:
    void on_onehbutton_clicked();

    void on_fivehbutton_clicked();

    void on_onetbutton_clicked();

    void on_twotbutton_clicked();

    void on_threembutton_clicked();

    void on_changebutton_clicked();

    void on_determinebutton_clicked();

    void on_canclebutton_clicked();

private:
    Ui::QOutNum *ui;
    int expression=0;
};
#endif // QOUTNUM_H
