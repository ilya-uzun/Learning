#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // надпись на кнопке
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(nashSlot()));
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
// считываем с lineEdit
void MainWindow::nashSlot()
{
    QString str1 = ui->lineEdit->text();  // получаем строку из первого QLineEdit
    QString str2 = ui->lineEdit_2->text();
    // записать в label
    setLabelText(str1);
    // записать на кнопку
    //ui->pushButton->setText(str1);
}

