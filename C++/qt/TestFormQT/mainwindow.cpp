#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // надпись на кнопке

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



// вывод и суммы дdух lineEdit через кнопку

void MainWindow::on_pushButton_clicked()
{
   ClassMath m;
   QString text;
   int str1 = ui->lineEdit->text().toInt();
   int str2 = ui->lineEdit_2->text().toInt();

   text = m.summe_number(str1, str2);
   ui->label->setText(text);
    //ui->pushButton->close();//  закрывает кнопку
//    connect(pushButton, &QPushButton::clicked, qApp, &MainWindow::getListEdit)
}
