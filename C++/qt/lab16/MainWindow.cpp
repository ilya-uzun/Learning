#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Shapes *scene = new Shapes(this);

}


MainWindow::~MainWindow()
{

}

