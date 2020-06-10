#include "btree.h"
#include <QApplication>
#include <QTime>
#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);  //Инициализация приложения

    MainWindow mainWindowWidget;   //Инициализация главного окна
    mainWindowWidget.show();       //Запуск главного окна

    return app.exec();  //Запуск приложения
}
