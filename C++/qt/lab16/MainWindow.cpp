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

    //QString t;
    //connect(bt, SIGNAL(clicked()), this, SLOT(setMainText()));
    //ed->returnPressed();// сигнал что нажат Enter
    //ed->setText(t);//setText - записывает в строку
    //circle->getText(t);

// проба нового vменедже компановки
//    QGridLayout* grid = new QGridLayout(this);
//    grid->addWidget(circle, 3, 3);
//    grid->addWidget(ed, 0, 1);
//    grid->addWidget(bt, 0, 2);

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
    //QObject::connect(ed, SIGNAL(textChanged(const QString)),circle,SLOT(getText(const QString)));
    //connect(ed, &QLineEdit::textChanged, lbl, &QLabel::setText); // новый способ
    connect(ed, SIGNAL(textChanged(QString)), lbl, SLOT(setText(QString))); // старый способ
    //connect(ed, SIGNAL(textChanged(QString)), this, SLOT(setMainText()));
    QObject::connect(bt, SIGNAL(clicked()), circle, SLOT(setText(QString)));
    //connect(ed, &QLineEdit::textChanged, circle, &Shapes::setText);
    //text = lbl->text();
    //circle->getText(text);
    //setMainText(text); // проверка связи с класом shapes
    //setMainText(text);s
}

void MainWindow::setMainText()
{
    QString ss;
    ss = "sd";
    emit circle->setText(ss);
}

MainWindow::~MainWindow()
{

}

