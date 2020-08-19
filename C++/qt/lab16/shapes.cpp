
#include "shapes.h"

Shapes::Shapes()  {}

void Shapes::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    doPainting();
}

void Shapes::doPainting()
{
    QPainter painter(this);
    const QRect rect = QRect(40, 100, 60, 60);
    //QString text = "U"; // выводимый текст
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 2));// цифра толщена линии, #888 - цвет
    //painter.setBrush(QBrush(QColor("#888"))); // заполнение фигуры
    painter.drawText(rect, Qt::AlignCenter, text);
    painter.drawEllipse(40, 100, 60, 60);// первые две цифры- корденаты
// если передовать одинаковые кардинаты то тект и фигура будут вместе
}

QString Shapes::getText()
{
	return text;
}

void Shapes::setText(QString t)
{
	text = t;
}

~Shapes::Shapes()
{
}
