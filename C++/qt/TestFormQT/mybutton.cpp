#include "mybutton.h"

MyButton::MyButton(QWidget *parent): QWidget(parent)
{
    QPushButton *quitBtn = new QPushButton("Quit", this); // создаём новую кнопку
    quitBtn->setGeometry(50, 40, 75, 30);// изменяем размеры кнопки и помещаем на форму окна

    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}
