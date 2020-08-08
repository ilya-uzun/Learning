
#include "shapes.h"

Shapes::Shapes(QWidget* parent) : QWidget(parent) {}

void Shapes::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    doPainting();
}

void Shapes::doPainting()
{
    QPainter painter(this);

//    Shapes text;
    QString text = "U"; // выводимый текст
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 1));
    painter.setBrush(QBrush(QColor("#888")));
    painter.drawEllipse(40, 100, 60, 60);// первые две цифры- корденаты
    QPainter painter2(this);
    painter2.drawText(40, 100, text);

}
