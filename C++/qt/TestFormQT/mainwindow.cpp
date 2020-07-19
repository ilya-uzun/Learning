#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// label
QString MainWindow::labelText()
{
    return ui->label->text();
}
// позваляет записать в label
void MainWindow::setLabelText(QString text)
{
  ui->label->setText(text);
}

void MainWindow::nashSlot()
{
    QString str1 = ui->lineEdit->text();  // получаем строку из первого QLineEdit
}


void MainWindow::on_pushButton_clicked()
{
    QString str1 = ui->lineEdit->text();
}
