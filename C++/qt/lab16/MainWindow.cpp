#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    ed = new QLineEdit;
    bt = new QPushButton("Название");// кнопка

    QString t;
    connect(bt, SIGNAL(clicked()), this, SLOT(setMainText()));
    ed->returnPressed();// сигнал что нажат Enter
    ed->setText(t);//setText - записывает в строку

    circle->getText(t);


// проба нового vменедже компановки
//    QGridLayout* grid = new QGridLayout(this);
//    grid->addWidget(circle, 3, 3);
//    grid->addWidget(ed, 0, 1);
//    grid->addWidget(bt, 0, 2);

    // первый вертикальный слой (Оставил т.к. на горизонтальном находят друг на друга )
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(circle); // добавить  горизонтальное расположение круг
    layout->addWidget(ed);
    layout->addWidget(bt);

//    // Основной  горизонтальный слой
    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layout);// Добавить на слой
    setLayout(main);// помещаем на окно
    QObject::connect(ed, SIGNAL(textChanged(const QString)),circle,SLOT(getText(const QString)));
}

QString MainWindow::setMainText()
{
      QString text = ed->text();
      return text;
}

MainWindow::~MainWindow()
{

}

