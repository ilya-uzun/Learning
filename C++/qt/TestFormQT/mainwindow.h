#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    QString labelText();
    void setLabelText(QString string);

    int getListEdit(int str1);

public slots:
    virtual void nashSlot(int& str1, int& str2);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
