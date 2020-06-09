#include "BTree.h"
#include <QApplication>
#include <QTime>
#include "mainwindow.h"

/**
 * Главная функция
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv) {
    QApplication app(argc, argv);  //Инициализация приложения

    MainWindow mainWindowWidget;   //Инициализация главного окна
    mainWindowWidget.show();       //Запуск главного окна

    return app.exec();  //Запуск приложения
}