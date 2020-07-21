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
void MainWindow::nashSlot(int& str1, int& str2)
{

//    QString str1 = ui->lineEdit->text();  // получаем строку из первого QLineEdit
    // преообразовываем string в int
    str1 = ui->lineEdit->text().toInt();
    str2 = ui->lineEdit_2->text().toInt();
    // записать в label
    // setLabelText(str1);
    // записать на кнопку
    // ui->pushButton->setText(str1);
}
// вывод через return
int MainWindow::getListEdit(int str1)
{
    str1 = ui->lineEdit->text().toInt();
    return str1;
}


