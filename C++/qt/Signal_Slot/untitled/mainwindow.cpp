#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        
    // инициализация кнопок
    QPushButton *but_1 = new QPushButton(this);
    QPushButton *but_2 = new QPushButton(this);
    QPushButton *but_3 = new QPushButton(this);
    
    // Устанавливаем номера кнопок
    but_1->setText("1");
    but_2->setText("2");
    but_3->setText("3");
    
    // Добовляем кнопки на слои с вертикальной ориентацией
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(but_1);
    layout->addWidget(but_2);
    layout->addWidget(but_3);
    window->setLayout(layout);
    window->show();// show - показывать
    
    //Подключаем к напкам индивидуальные слоты
    //старый способ записи
    connect(but_1, SIGNAL(clicked()), this, SLOT(slotButton1()));
    connect(but_2, SIGNAL(clicked()), this, SLOT(slotButton2()));
    connect(but_3, SIGNAL(clicked()), this, SLOT(slotButton3()));
    
    // Подключаем сигнал с передачей номера кнопки к слоту вывода сообщения
    //новый способ записи
    connect(this, &MainWindow::signalFormButton, this, &MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Слоты для обработки нажатия кнопок

void MainWindow::slotButton1()
{
    emit signalFormButton(1);
}    

void MainWindow::slotButton2()
{
    emit signalFormButton(2);
} 

void MainWindow::slotButton3()
{
    emit signalFormButton(3);
}

// слоты вывод сообщения

void MainWindow::slotMessage(int buttonID)
{
    QMessageBox::information(this,
                             "Увидомление о нажатой кнопке",
                             "Нажата кнопка под номером " + QString::number(buttonID));
}
