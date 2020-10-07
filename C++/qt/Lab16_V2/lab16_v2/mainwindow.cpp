#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tree = BinaryTree(ui->treeView);
    tree.initializeWithStartValue();
   // ui->msgBox->setText("");
    setFixedSize(width(), 725);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Поиск элемента
void MainWindow::on_searchBt_clicked()
{
   // try {
       // double value = InputDialog::getDouble(this, "Введите значение, которое нужно найти!");
        try {
            Node *node = tree.search(1); // 1  постаил как заглушку, требуется вводт номер элемнта который нужно найти
            tree.highlightNode(node);
            //showMessage(QString("Элемент %1 найден!").arg(node->data));
            return;
        } catch (exception &e) {
          //  showMessage(e.what());
        }
   // } catch (exception &e) {
    //    showMessage(e.what());

}

//Добавить элемент
void MainWindow::on_addBt_clicked()
{
    double value;
    // InputDialog - элемент второго окна
   // try {
        //value = InputDialog::getDouble(this, "Введите значение, которое нужно добавить!");
        try {
            tree.insert(value);
            //showMessage(QString("Элемент %1 был добавлен!").arg(value));
        } catch (exception &e) {
           // showMessage(e.what());
        }
   // } catch (exception &e) {
   //     shoowMessage(e.what());
   //}
}

//Удалить элемент
void MainWindow::on_deleteBt_clicked()
{
    double value;
    //try {
        //value = value = InputDialog::getDouble(this, "Введите значение, которое нужно удалить!");
        try {
            tree.remove(value);
           // showMessage(QString("Элемент %1 был удален!").arg(value));
        } catch (exception &e) {
           // showMessage(e.what());
        }
   // } catch (exception &e) {
   //     showMessage(e.what());
   // }
}

/**
 * Метод для вывода сообщения в данном виджете.
 * Выводит переданный текст на специальной панели сообщений.
 */
//void MainWindow::showMessage(QString msg) {
//    ui->msgBox->setText(msg);
//}

/**
 * Метод для очищения панели сообщений от текста.
 */
//void MainWindow::clearMessages() {
//    ui->msgBox->clear();
//}
//?
