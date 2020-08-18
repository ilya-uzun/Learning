#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    ed = new QTextEdit;
    
    // первый горизонтальный слой
    QHBoxLayout *layout_H = new QHBoxLayout;
    layout_H->addWidget(circle); // добавить  горизонтальное расположение круг

    // первый вертикальный слой
    QVBoxLayout *layout_V1 = new QVBoxLayout;
    layout_V1->addWidget(ed); // добавить  горизонтальное расположение Edit
    
    // Основной  горизонтальный слой
    QHBoxLayout *main = new QHBoxLayout;
    main->addLayout(layout_H);// Добавить на слой
    main->addLayout(layout_V1);
    setLayout(main);// помещаем на окно
}

MainWindow::~MainWindow()
{

}

