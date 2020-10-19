#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int str1 = ui->lineEdit->text().toInt();
    //int str2 = ui->lineEdit_2->text().toInt();

}

MainWindow::~MainWindow()
{
    delete ui;
}

