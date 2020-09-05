#ifndef FORMULAWIDGET_H
#define FORMULAWIDGET_H

// Класс визуализации формулы
class FormulaItem
{
 public:
  explicit FormulaItem(QString value): m_value(value){}

  static const QString RUGULAR_EXPRESSION; // Строка регулярного выражения для поиска формулы
  //Метод отрисовки
  QPoint draw(const QPoint& pos, QPainter& p) const;

 privte:
  QString m_value;// Значение форулы
}


#endif // FORMULAWIDGET_H
