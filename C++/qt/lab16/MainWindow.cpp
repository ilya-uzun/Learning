#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    circle = new Shapes;
    ed = new QLineEdit;
    bt = new QPushButton("Название");// кнопка
    lbl = new QLabel("0", this);
    // тест запеси в circle
    //QString e = "fds";
    //circle->setText(e);

    // первый вертикальный слой (Оставил т.к. на горизонтальном находят друг на друга )
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(circle); // добавить  горизонтальное расположение круг
    layout->addWidget(lbl); // QLabel
    layout->addWidget(ed);//
    layout->addWidget(bt); // Кнопка

//    // Основной  горизонтальный слой
    QVBoxLayout *main = new QVBoxLayout;
    main->addLayout(layout);// Добавить на слой
    setLayout(main);// помещаем на окно
    connect(ed, &QLineEdit::textChanged, lbl, &QLabel::setText); // новый способ
    connect(bt, &QPushButton::clicked, this, &MainWindow::setButton);
    connect(ed, &QLineEdit::textChanged, this, &MainWindow::signalForm);// передает в signalForm
    connect(this, &MainWindow::signalForm, this, &MainWindow::slotMessage);

}

void MainWindow::setButton()
{
    emit signalForm(text);
}

void MainWindow::slotMessage(QString buttonID)
{
    QMessageBox::information(this,
                             "Увидомление ",
                             "Текст  " + (buttonID));

}

MainWindow::~MainWindow()
{

}

