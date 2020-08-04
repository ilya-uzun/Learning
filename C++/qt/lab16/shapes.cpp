
#include "shapes.h"

Shapes::Shapes(QWidgit* parent) : QWidgit(parent) {}

void Shapes::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    doPainting();
}

void Shapes::doPainting()
{
    QPainter painter(this);

    painter.setRederHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 1));
    painter.setBrush(QBrush(QColor("#888")));

    QPainterPath path1;
/* QPainterPath это класс, используемый для создания более 
сложных фигур при помощи заданной траектории рисования. */
    path.move(5, 5);
    path.cubicTo(40, 5, 50, 50, 99, 99);
    path.cubicTo(5, 99, 50, 50, 5, 5);
    painter.drawPath(path1);

    painter.drawPie(130, 20, 90, 60, 30*16, 120*16);
}