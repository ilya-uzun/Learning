#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    ed = new QLineEdit;
    bt = new QPushButton("создать лист");// кнопка
    del = new QPushButton("удалить лист");// кнопка
    //lbl = new QLabel("0", this);

    // первый вертикальный слой (Оставил т.к. на горизонтальном находят друг на друга )
    layout = new QVBoxLayout;
    //layout->addWidget(lbl); // QLabel
    layout->addWidget(ed); //
    layout->addWidget(bt); // Кнопка
    layout->addWidget(del); // Кнопка delit

//    // Основной  горизонтальный слой
    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layout);// Добавить на слой
    setLayout(main);// помещаем на окно
    //connect(ed, &QLineEdit::textChanged, lbl, &QLabel::setText); // новый способ
    connect(bt, &QPushButton::clicked, this, &MainWindow::pushButton_cliked); // метод отклика кнопки
    connect(del, &QPushButton::clicked, this, &MainWindow::pushButton_delete); // метод отклика кнопки
    connect(ed, &QLineEdit::textChanged, this, &MainWindow::setLineEdit);// считываем из QLineEdit
}
// метод запись из QLineEdit в перемменую
void MainWindow::setLineEdit(const QString &t)
{
    text = t;
}

void MainWindow::pushButton_cliked()
{
    circle = new Shapes; // создаем новый элемента
    layout->addWidget(circle); // добавить  горизонтальное расположение круг
    circle->setText(text); // записываем текст в круг
}

void MainWindow::pushButton_delete()
{
    circle->close();
    //delete circle;
}

MainWindow::~MainWindow()
{

}

