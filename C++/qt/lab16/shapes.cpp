
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

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 1));
    painter.setBrush(QBrush(QColor("#888")));

    QPainterPath path1;
/* QPainterPath это класс, используемый для создания более 
сложных фигур при помощи заданной траектории рисования. */
    path1.moveTo(5, 5);
    path1.cubicTo(40, 5, 50, 50, 99, 99);
    path1.cubicTo(5, 99, 50, 50, 5, 5);
    painter.drawPath(path1);

    painter.drawPie(130, 20, 90, 60, 30*16, 120*16);
}
