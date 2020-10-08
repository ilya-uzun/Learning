#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = BinaryTree(ui->treeView);
    tree.initializeWithStartValue();
    setFixedSize(width(), 725);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Поиск элемента
void MainWindow::on_searchBt_clicked()
{

}

//Добавить элемент
void MainWindow::on_addBt_clicked()
{

}

//Удалить элемент
void MainWindow::on_deleteBt_clicked()
{

}


