#include "MainWindow.h"

#include <QApplication>
#include "shapes.h"
#include "puff.h"
#include "btreewidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.resize(400,400);
//    w.show();

    BtreeWidget s;

    s.setWindowTitle("lab16");
    s.show();

//    Puff s;
//    s.resize(300, 300);
//    s.setWindowTitle("ss");
//    s.show();

    return a.exec();
}
