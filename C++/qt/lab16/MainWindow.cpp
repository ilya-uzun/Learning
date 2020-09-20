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
    QVBoxLayout *layout = new QVBoxLayout;
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
    connect(ed, &QLineEdit::textChanged, this, &MainWindow::setButton);
    connect(ed, &QLineEdit::textChanged, this, &MainWindow::signalForm);// передает в buttonID
    // connect(this, &MainWindow::signalForm, this, &MainWindow::slotMessage);

}

void MainWindow::setButton(QString buttonID)
{
    emit signalForm(buttonID);
    text = buttonID;
    circle = new Shapes;

}

void MainWindow::slotMessage(QString buttonID)
{
    QMessageBox::information(this,
                             "Увидомление ",
                             "Текст  " + (buttonID));
}

void MainWindow::on_pushButton_cliked()
{
    lbl->setText("dddddd");
}

MainWindow::~MainWindow()
{

}

