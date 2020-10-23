#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    int int1;
    int int2;
    int int3;
    int int4;
    int int5;
    int int6;
    int int7;
    int int8;
    int int9;
    int int10;
    int int11;
    int int12;
    int int13;
    int int14;
    int int15;
    int int16;
    int int17;
    int int18;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
