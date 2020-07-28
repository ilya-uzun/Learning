#include "mainwindow.h"
#include "classmath.h"
#include <QApplication>
#include <mybutton.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    MyButton win;

//    win.resize(250, 250);
//    win.setWindowTitle("QPushButton");
//    win.show();

    return a.exec();

}
// инфа по lineEdit http://easy-qt.blogspot.com/2012/02/qpushbutton-qlineedit.html
