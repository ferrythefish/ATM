#include "qlog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLog w;
    w.show();
    return a.exec();
}
