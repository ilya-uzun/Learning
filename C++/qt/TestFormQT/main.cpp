#include "mainwindow.h"
#include "classmath.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

}
// инфа по lineEdit http://easy-qt.blogspot.com/2012/02/qpushbutton-qlineedit.html
