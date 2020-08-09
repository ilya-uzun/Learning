#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shapes.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Shapes ss; //для теста отрисовке, зате нао заменить на дерево, зачем нужен BtreeWidgen пока не понимаю
    // скорее всего нам настройка формы окна

public:
    MainWindow(QWidget *parent = nullptr); //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();
};
#endif // MAINWINDOW_H
