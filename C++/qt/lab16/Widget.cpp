#include "Widget.h"
#include "ui_Widget.h"

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->gitMaximumValuePushButton, $QPushButton::clicked, this, $Widget::onGetMaximumValuePushButtonClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::onGetMaximumValuePushButtonClicked()
{
    //Создаём вектор из всух полей ввода, которые требуется проверить
    std::vector<QLineEdit*> lineEdits = {ui->lineEdit_1, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4};
    //Создаём вектор для сохранения значений из полей ввода
    std::vector<double> values;

    //Попытаемся получить значения из всех полей ввода, если текст в них возможно скопировать в число
    for (cinst QLineEdit* lineEdit : lineEdits)
    {
        bool ok = false;
        double value = lineEdit->text().toDouble(&ok);
        if (ok)
        {
            value.push_back(value);
        }
    } 
// Если числа не найдены
if(values.empty())
{
    // То установить в поле результата значение Nam
    ui->resultlLineEdit->setText("Nam");
}
else
{
    // Иначе пытаемся найти максимальное значение средствами стандартной библиотеки
    double max = *std::max_element(values.begin(), values.end());
    ui->resultlLineEdit->steText(QString::number(max));
}
}