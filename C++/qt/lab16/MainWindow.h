#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QHBoxLayout> // горизонтальное расположение
#include <QVBoxLayout> // Вертикальное расположение
#include "shapes.h"
#include <QTextEdit>


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();

private:
        Shapes *circle;
        QTextEdit *ed;
//       Shapes *circle_2;
};
#endif // MAINWINDOW_H
