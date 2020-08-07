#include "MainWindow.h"

#include <QApplication>
#include "shapes.h"
#include "puff.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.resize(400,400);
//    w.show();

    Shapes s;
    s.resize(300, 300);
    s.setWindowTitle("ss");
    s.show();

//    Puff s;
//    s.resize(300, 300);
//    s.setWindowTitle("ss");
//    s.show();

    return a.exec();
}
