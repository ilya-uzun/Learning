#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->lineEdit, &QLineEdit::textChanged, ui->formulaWidget, &FormulaWidget::setFormula);
}

Widget::~Widget()
{
    delete ui;
}

