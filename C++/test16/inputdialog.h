#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
    class InputDialog;
}

/**
 * Класс "Диалог ввода значения"
 */
class InputDialog : public QDialog {
Q_OBJECT
private:
    Ui::InputDialog *ui;  //Указатель на интерфейс
    char value ;     //Поле под вводимое значение
private:
    char getValue();    //Селектор для поля с вводимым значением
private slots:
    void on_confirmButton_clicked();    //Метод-обработчик события "При нажатии подтверждающей кнопки"
    void on_InputDialog_rejected();     //Метод-обработчик события "При отмене ввода"
    void on_InputDialog_accepted();     //Метод-обработчик события "При принятии введенного значения"
public:
    explicit InputDialog(QWidget *parent = nullptr);  //Конструктор с параметром в виде указателя на родителський виджет
    ~InputDialog();                                   //Деструктор
    static char getDouble(QWidget *parent, QString label);   //Метод открытия диалога для ввода значения
};


#endif // INPUTDIALOG_H
