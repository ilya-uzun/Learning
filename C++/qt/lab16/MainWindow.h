#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct node
{
    int key_value;//ключ – значение узла, типа int
    node* left;  //указатель на левого потомка
    node* reght; //указатель на правого потомка
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
