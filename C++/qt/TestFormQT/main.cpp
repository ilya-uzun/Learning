#include "mainwindow.h"
#include "classmath.h"
#include <QApplication>
#include <QLabel>
#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // test metod summe_nuber
    //QLabel label ("sdsdd");
    int b = 3;
    int c = 5;
    ClassMath test;
    int bc;
    bc = test.summe_number(b,c);
    //label.show();
    return a.exec();
}
