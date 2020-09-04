#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();
    return a.exec();
}

// https://evileg.com/ru/post/339/   Урок по сайту
// В примере использован класс QWidget ?
