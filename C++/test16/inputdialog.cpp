#include "inputdialog.h"
#include "ui_inputdialog.h"
#include <stdexcept>

/**
 * Конструктор с параметром указателя на родителський виджет
 * @param parent
 */
InputDialog::InputDialog(QWidget *parent) : QDialog(parent), ui(new Ui::InputDialog) {
    ui->setupUi(this);
    ui->doubleValue->setValue(value);
}

/**
 * Деструктор
 */
InputDialog::~InputDialog() {
    delete ui;
}

/**
 * Селектор для поля с вводимым значением
 * @return
 */
double InputDialog::getValue() {
    return value;
}

/**
 * Метод открытия диалога для ввода значения
 * @param parent
 * @param label
 * @return
 */
double InputDialog::getDouble(QWidget *parent, QString label) {
    InputDialog inputDialog(parent);
    inputDialog.setModal(false);
    inputDialog.setFixedSize(200, 150);
    inputDialog.ui->label->setText(label);
    inputDialog.ui->doubleValue->setRange(-100.0, +100.0);
    inputDialog.ui->doubleValue->setFocus();
    inputDialog.exec();
    double value = inputDialog.getValue();
    return value;
}

/**
 * Метод-обработчик события "При нажатии подтверждающей кнопки"
 */
void InputDialog::on_confirmButton_clicked() {
    this->accept();
}

/**
 * Метод-обработчик события "При отмене ввода"
 */
void InputDialog::on_InputDialog_rejected() {
    throw std::runtime_error("Окно было закрыто!");
}

/**
 * Метод-обработчик события "При принятии введенного значения"
 */
void InputDialog::on_InputDialog_accepted() {
    this->value = ui->doubleValue->value();
    this->close();
}