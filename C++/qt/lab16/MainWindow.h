#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QHBoxLayout> // горизонтальное расположение
#include <QVBoxLayout> // Вертикальное расположение
#include "shapes.h"
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout> // новая разметка
#include <QMessageBox>

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();

private:
// Создание элементов
    QString text ;
    Shapes *circle;
    QLineEdit *ed;
    QPushButton *bt;
    QPushButton *del;//удаление
    QLabel *lbl;
    QVBoxLayout *layout;

private slots:
    void setLineEdit(const QString &); // метод запись из QLineEdit в перемменую
    void pushButton_cliked(); // слот для отработкиназатой кнопки
    void pushButton_delete(); // слот для отработкиназатой кнопки
};
#endif // MAINWINDOW_H
