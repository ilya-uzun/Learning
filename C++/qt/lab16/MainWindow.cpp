#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(circle); // добавить  горизонтальное расположение круг

    // первый оризонтальный слой
    circle_2 = new Shapes;
    QVBoxLayout *layout_2 = new QVBoxLayout;
    layout_2->addWidget(circle_2); // добавить  горизонтальное расположение круг
    // второй вертикальный слой
    QHBoxLayout *main = new QHBoxLayout;
    main->addLayout(layout);// Добавить на слой
    main->addLayout(layout_2);

    setLayout(main);// помещаем на окно
}

MainWindow::~MainWindow()
{

}

