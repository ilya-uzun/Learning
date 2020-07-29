//#include "mainwindow.h"
#include "/home/ilya/pgit/Study/C++/qt/TestFormQT/mybutton.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    MyButton win;
    win.resize(250, 250);
    win.setWindowTitle("Qp");
    win.show();
    return a.exec();
}
