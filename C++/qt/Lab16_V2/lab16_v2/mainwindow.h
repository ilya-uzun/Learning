#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <iostream>
#include "binarytree.h"
#include "node.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    Ui::MainWindow *ui; //Указатель на интерфейс
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    BinaryTree tree;//Поле с бинарным деревом, над которым проводятся все операции ползователя
    void showMessage(QString msg);//Метод для вывода сообщения в данном виджете
    void clearMessages();//Метод для очищения панели сообщений от текста

private slots:
    void on_searchBt_clicked(); // Поиск элемента
    void on_addBt_clicked(); //Добавить элемент
    void on_deleteBt_clicked(); //Удалить элемент

    void on_searchTreeBt_clicked();

protected:
   // void mousePressEvent(QMouseEvent *event) override;  //Метод-обработчик события нажатия на кнопку мыши
};
#endif // MAINWINDOW_H
