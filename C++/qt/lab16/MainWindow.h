#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QHBoxLayout> // горизонтальное расположение
#include "shapes.h"


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();

private:
        Shapes *circle;
};
#endif // MAINWINDOW_H
