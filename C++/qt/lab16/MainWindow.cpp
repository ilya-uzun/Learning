#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    ed = new QLineEdit;
    bt = new QPushButton("Название");// кнопка
    lbl = new QLabel("0", this);
    //circle = new Shapes;
    // тест запеси в circle
    //QString e = "fds";
    //circle->setText(e);

    // первый вертикальный слой (Оставил т.к. на горизонтальном находят друг на друга )
    layout = new QVBoxLayout;
    //layout->addWidget(circle); // добавить  горизонтальное расположение круг
    layout->addWidget(lbl); // QLabel
    layout->addWidget(ed); //
    layout->addWidget(bt); // Кнопка

//    // Основной  горизонтальный слой
    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layout);// Добавить на слой
    setLayout(main);// помещаем на окно
    connect(ed, &QLineEdit::textChanged, lbl, &QLabel::setText); // новый способ
    connect(bt, &QPushButton::clicked, this, &MainWindow::on_pushButton_cliked);
    connect(ed, &QLineEdit::textChanged, this, &MainWindow::getLineEdit);// считыаем из QLineEdit
}
// метод запись из QLineEdit в перемменую
void MainWindow::getLineEdit(const QString &t)
{
    text = t;
}

void MainWindow::on_pushButton_cliked()
{
    circle = new Shapes; // создаем новый элемента
    layout->addWidget(circle); // добавить  горизонтальное расположение круг
    circle->setText(text); // записываем текст в круг

}

MainWindow::~MainWindow()
{

}

