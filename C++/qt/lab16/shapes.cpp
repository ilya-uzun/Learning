
#include "shapes.h"

Shapes::Shapes(QWidget *parent)
    : QMainWindow(parent)
{
}

// метод печати
void Shapes::paintEvent(QPaintEvent* e)
{
    Q_UNUSED(e);
    doPainting(text);
}

// метод для ввода текста
void Shapes::setText(const QString &t)
{
  text = t;
}

void Shapes::doPainting(QString &t)
{
    QPainter painter(this);
    //emit setText(text); // записыает значение из функции getText
    const QRect rect = QRect(30, 5, 60, 60);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(QBrush("#888"), 2));// цифра толщена линии, #888 - цвет
    //painter.setBrush(QBrush(QColor("#888"))); // заполнение фигуры
    painter.drawText(rect, Qt::AlignCenter, t);
    painter.drawEllipse(30, 5, 60, 60);// первые две цифры- коорденаты
// если передовать одинаковые кординаты то тект и фигура будут вместе
}

Shapes::~Shapes()
{
}
