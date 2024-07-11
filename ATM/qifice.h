#ifndef QIFICE_H
#define QIFICE_H

#include <QWidget>
#include <QMessageBox>
#include "function.h"

namespace Ui {
class QIfIce;
}

class QIfIce : public QWidget
{
    Q_OBJECT

public:
    explicit QIfIce(QWidget *parent = nullptr);
    ~QIfIce();

signals:
    void back();

private slots:
    void on_canclebutton_clicked();

    void on_determinebutton_clicked();

private:
    Ui::QIfIce *ui;
};

#endif // QIFICE_H
