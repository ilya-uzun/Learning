#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_searchBt_clicked(); // Поиск элемента

    void on_addBt_clicked(); //Добавить элемент

    void on_deleteBt_clicked(); //Удалить элемент

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
