#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textChanged, ui->formulaWidget, &FormulaWidget::setFormula);     
  
}

MainWindow::~MainWindow()
{
    delete ui;
}


