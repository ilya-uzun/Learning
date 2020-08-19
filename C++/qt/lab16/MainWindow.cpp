#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    ed = new QLineEdit;
    bt = new QPushButton;// кнопка
    
    // первый вертикальный слой (Оставил т.к. на горезонтальном находят друг на друга )
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(circle); // добавить  горизонтальное расположение круг
    layout->addWidget(ed);
	layout->addWidget(bt);

    // Основной  горизонтальный слой
    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layout);// Добавить на слой
    setLayout(main);// помещаем на окно
}

MainWindow::~MainWindow()
{

}

