#include "./ui_mainwindow.h"
#include "mainwindow.h"
#include <QInputDialog>
#include <iostream>

/**
 * Конструктор с параметром в виде указателя на родителський виджет.
 * Принимает указатель на родительский виджет в качестве параметра,
 * а также задает изгачальные настройки данному виджету.
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    tree = BTree(ui->graphicsView);
    tree.initializeWithStartValue();
    ui->msgBox->setText("");
    setFixedSize(width(), 725);
}

/**
 * Деструктор
 */
MainWindow::~MainWindow() {
    delete ui;  //удаляется интерфейс и его элементы
}

/**
 * Метод-обработчик события нажатия на кнопку мыши.
 * Снимает подсветку со всех узлов дерева.
 * @param event
 */
void MainWindow::mousePressEvent(QMouseEvent *event) {
    tree.clearHighlight();
    QMainWindow::mousePressEvent(event);
}

/**
 * Метод-обработчик события нажатия на кнопку "Сформировать".
 * Формирует новое идеально-сбалансированное дерево поиска,
 * упорядоченность элементов в котором, однако не гарантируется,
 * т.к. идеально-сбалансированное не означает, что оно является
 * еще и деревом поиска.
 */
void MainWindow::on_createButton_clicked() {
    try {
        tree.initializeWithStartValue();
        showMessage("Сформировано новое дерево!");
    } catch (exception &e) {
        showMessage(e.what());
    }
}

/**
 * Метод-обработчик события нажатия на кнопку "Добавить".
 * Добавляет в дерево новый элемент с заданным значением,
 * если его еще нет в дереве.
 * Если элемент уже есть, то выводится соотвествующее сообщение.
 */
void MainWindow::on_addButton_clicked() {
    double value;
    try {
        value = InputDialog::getDouble(this, "Введите значение, которое нужно добавить!");
        try {
            tree.insert(value);
            showMessage(QString("Элемент %1 был добавлен!").arg(value));
        } catch (exception &e) {
            showMessage(e.what());
        }
    } catch (exception &e) {
        showMessage(e.what());
    }
}

/**
 * Метод-обработчик события нажатия на кнопку "Удалить".
 * Ищет в дереве элемент с заданным значением и,
 * если тот найден, то удаляет его из дерева.
 * Если элемент не найден, то выводится соотвествующее сообщение.
 */
void MainWindow::on_deleteButton_clicked() {
    double value;
    try {
        value = value = InputDialog::getDouble(this, "Введите значение, которое нужно удалить!");
        try {
            tree.remove(value);
            showMessage(QString("Элемент %1 был удален!").arg(value));
        } catch (exception &e) {
            showMessage(e.what());
        }
    } catch (exception &e) {
        showMessage(e.what());
    }
}

/**
 * Метод-обработчик события нажатия на кнопку "Найти".
 * Ищет в дереве элемент с заданным значением и,
 * если тот найден, то выводит сообщение об этом в панель сообщений,
 * а также подсвечивает найденный элемент.
 * Если элемент не найден, то выводится соотвествующее сообщение.
 */
void MainWindow::on_searhButton_clicked() {
    try {
        double value = InputDialog::getDouble(this, "Введите значение, которое нужно найти!");
        try {
            Node *node = tree.search(value);
            tree.highlightNode(node);
            showMessage(QString("Элемент %1 найден!").arg(node->data));
            return;
        } catch (exception &e) {
            showMessage(e.what());
        }
    } catch (exception &e) {
        showMessage(e.what());
    }
    tree.clearHighlight();
}

/**
 * Метод-обработчик события нажатия на кнопку "Найти минимальный".
 * Ищет в дереве минимальный элемент и, если тот найден, то
 * выводит сообщение об этом в панель сообщений, а
 * также подсвечивает найденный элемент.
 * Если элемент не найден, то выводится соотвествующее сообщение.
 */
void MainWindow::on_minButton_clicked() {
    try {
        Node *minNode = tree.findMin();
        tree.highlightNode(minNode);
        showMessage(QString("Минимальный элемент = %1").arg(minNode->data));
        return;
    } catch (exception &e) {
        showMessage(e.what());
    }
    tree.clearHighlight();
}

/**
 * Метод-обработчик события нажатия на кнопку "Найти максимальный".
 * Ищет в дереве максимальный элемент и, если тот найден, то
 * выводит сообщение об этом в панель сообщений, а
 * также подсвечивает найденный элемент.
 * Если элемент не найден, то выводится соотвествующее сообщение.
 */
void MainWindow::on_maxButton_clicked() {
    try {
        Node *maxNode = tree.findMax();
        tree.highlightNode(maxNode);
        showMessage(QString("Максимальный элемент = %1").arg(maxNode->data));
        return;
    } catch (exception &e) {
        showMessage(e.what());
    }
    tree.clearHighlight();
}

/**
 * Метод-обработчик события нажатия на кнопку "Преобразовать в дерево поиска".
 * Вызывает метод конвертации дерева в дерево поиска.
 */
void MainWindow::on_convertButton_clicked() {
    try {
        tree.convertToBalancedBST();
        showMessage("Дерево успешно преобразовано в бинарное дерево поиска!");
    } catch (exception &e) {
        showMessage(e.what());
    }
}

/**
 * Метод для вывода сообщения в данном виджете.
 * Выводит переданный текст на специальной панели сообщений.
 * @param msg
 */
void MainWindow::showMessage(QString msg) {
    ui->msgBox->setText(msg);
}

/**
 * Метод для очищения панели сообщений от текста.
 */
void MainWindow::clearMessages() {
    ui->msgBox->clear();
}
