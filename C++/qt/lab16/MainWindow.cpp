#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(circle); // добавить  горизонтальное расположение круг

    QHBoxLayout *main = new QHBoxLayout;
    main->addLayout(layout);

    setLayout(main);
}

MainWindow::~MainWindow()
{

}

