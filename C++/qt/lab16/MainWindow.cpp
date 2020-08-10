#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}


void MainWindow::test()
{
    Shapes * www = new Shapes;
    www->doPainting();
}

MainWindow::~MainWindow()
{

}

