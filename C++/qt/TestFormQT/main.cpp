#include "mainwindow.h"
#include "classmath.h"
#include <QApplication>
//#include <QLabel>
//#include <QString>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

// test metod summe_nuber
//    int b = 3;
//    int c = 5;
//    ClassMath test;
//    //выводим в leber результат метода summe_number
//    w.setLabelText(test.summe_number(b,c));

// тест Edit
//    int n1;
    QString n1 = w.get_TextEdit1();
    w.setLabelText("ww");
    return a.exec();
}
