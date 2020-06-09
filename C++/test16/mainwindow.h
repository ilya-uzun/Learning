#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graphwidget.h"
#include "inputdialog.h"
#include "BTree.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * Класс "Клавное окно".
 * Представляет собой виджет главного окна
 * и содержит основной графический интерфейс
 * данного приложения.
 */
class MainWindow : public QMainWindow {
Q_OBJECT
private:
    Ui::MainWindow *ui;  //Указатель на интерфейс
    BTree tree;          //Поле с бинарным деревом, над которым проводятся все операции ползователя
private:
    void showMessage(QString msg);      //Метод для вывода сообщения в данном виджете
    void clearMessages();               //Метод для очищения панели сообщений от текста
private slots:
    void on_createButton_clicked();     //Метод-обработчик события нажатия на кнопку "Сформировать"
    void on_addButton_clicked();        //Метод-обработчик события нажатия на кнопку "Добавить"
    void on_deleteButton_clicked();     //Метод-обработчик события нажатия на кнопку "Удалить"
    void on_searhButton_clicked();      //Метод-обработчик события нажатия на кнопку "Найти"
    void on_minButton_clicked();        //Метод-обработчик события нажатия на кнопку "Найти минимальный"
    void on_maxButton_clicked();        //Метод-обработчик события нажатия на кнопку "Найти максимальный"
    void on_convertButton_clicked();    //Метод-обработчик события нажатия на кнопку "Преобразовать в дерево поиска"
protected:
    void mousePressEvent(QMouseEvent *event) override;  //Метод-обработчик события нажатия на кнопку мыши
public:
    MainWindow(QWidget *parent = nullptr);  //Конструктор с параметром в виде указателя на родителський виджет
    ~MainWindow();                          //Деструктор
};

#endif // MAINWINDOW_H
