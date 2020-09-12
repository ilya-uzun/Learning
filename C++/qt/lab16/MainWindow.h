#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QHBoxLayout> // горизонтальное расположение
#include <QVBoxLayout> // Вертикальное расположение
#include "shapes.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout> // новая разметка

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();

private:
    Shapes *circle;
    QLineEdit *ed;
    QPushButton *bt;
private slots:
    QString setMainText();
};
#endif // MAINWINDOW_H
