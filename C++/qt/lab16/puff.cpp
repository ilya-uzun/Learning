#include "puff.h"

Puff::Puff(QWidget* parent)
    : QWidget(parent)
{
    x = 1;
    opacity = 1.0;
    timerId = startTimer(15);
}

void Puff:: paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    doPainting();
}

void Puff::doPainting()
{
    QPainter painter(this);
    QTextStream out(stdout);

    QString text = "Hello";

    painter.setPen(QPen(QBrush("#575555"), 1));

    QFont font("Courier", x, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width(text);

    painter.setFont(font);

    if (x > 10)
    {
        opacity -= 0.01;
        painter.setOpacity(opacity);
    }

    if (opacity <= 0)
    {
        killTimer(timerId);
        out << "timer stoopped" << endl;
    }

    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, text);
}

// Внутри timerEvent() мы увеличиваем размер шрифта и
// перерисовываем виджет:
void Puff::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e)

    x += 1;
    repaint();
}
