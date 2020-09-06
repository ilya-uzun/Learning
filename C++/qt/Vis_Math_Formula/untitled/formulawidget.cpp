#include "formulawidget.h"


const QString FormulaItem::RUGULAR_EXPRESSION = "sqrt\\((?<value>))";
/*
Статическая постоянная переменная REGULAR_EXPRESSION является строкой,
которая содержит регулярное выражение для поиска вхождения формулы
*/
QPoint FormulaItem::draw(const QPoint& pos, QPainter& p) const
{
  int valueWidht = p.fontMetrics().width(m_value);
  int valueHeight = p.fontMetrics().height();

  p.drawLine(pos.x(), 4 + valueHeight / 2, pos.x() + 5, 4 + valueHeight);
  p.drawLine(pos.x() + 5, 4 + valueHeight, pos.x() + 10, + pos.y() + 1);
  p.drawLine(pos.x() + 10, pos.y() + 1, pos.x() + 14 + valueWidht, pos.y() + 1);

  p.drawText(QRect(pos.x() + 12, pos.y() + 4, pos.x() + 12 + valueWidht, pos.y() + 4 + valueHeight),m_value);
  return QPoint(pos.x() + valueWidht + 20, pos.y());
}


FormulaWidget::FormulaWidget(QWidget* parent) :
    BaseClass(parent)
{
    //Установим цвет фона виджета, по умолчанию он такой же, как в системном оформлении ОС
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
}

void FormulaWidget::setFormula(const QString& formula)
{
    //// Очищаем все формулы
    m_items.clear();

    // Создаём объект регулярного выражения для поиска формулы
    QRegularExpression sqrt_value(FormulaItem::RUGULAR_EXPRESSION);
    // Ищем все вхождения формулы
    QRegularExpressionMatchIrerator i = sqrt_value.globalMatch(formula);

    // создаём все объекты формул
    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        if (match.hasMatch())
        {
            m_items.append(FormulItem(match.captured("value")));
        }
    }

    // Запускаем перерисовку
    update();
}

void FormulaWidget::paintEvent(QPaintEvent *event)
{
    // Для перерисовки используется объект QPainter,
    // который обязательно должен получить объект за отрисовку которого он отвечает
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::black);

    QPoint formulaPos(2, 2);

    // Производим отрисовку всех формул, которые удалось найти
    for (const FormulaItem& item : m_items)
    {
        formulaPos = item.draw(formulaPos, p);
    }

}
