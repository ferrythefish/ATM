#ifndef QPASS_H
#define QPASS_H
#include <QMessageBox>
#include <QWidget>
#include <account.h>
#include <function.h>
namespace Ui {
class Qpass;
}

class Qpass : public QWidget
{
    Q_OBJECT

public:
    Account *user;
    Function f;
    explicit Qpass(Account *account,QWidget *parent = nullptr);
    ~Qpass();
signals:
    void returnQlogSignal();
private slots:
    void on_pushButton_clicked(bool checked);

    void on_pushButton_2_clicked(bool checked);



private:
    Ui::Qpass *ui;
};

#endif // QPASS_H
