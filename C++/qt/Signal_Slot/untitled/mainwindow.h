#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void signalFormButton(int buttonID);// Сигнал для передачи номера нажатой кнопки

private:
    Ui::MainWindow *ui;
    
private slots:
    void slotButton1(); // Слоиты-обработчики нажатий кнопок
    void slotButton2();
    void slotButton3();
    // слот вызывающий сообщения с номером нажатой кнопки
    void slotMessage(int buttonID);
};
#endif // MAINWINDOW_H
