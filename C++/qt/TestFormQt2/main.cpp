//#include "mainwindow.h"
#include "/home/ilya/pgit/Study/C++/qt/TestFormQT/mybutton.h"
#include <plusminus.h>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    MyButton win;
//    win.resize(250, 250);
//    win.setWindowTitle("Qp");
//    win.show();

    PlusMinus window;

    window.resize(300, 190);
    window.setWindowTitle("Plus Minus");
    window.show();
    return a.exec();
}
