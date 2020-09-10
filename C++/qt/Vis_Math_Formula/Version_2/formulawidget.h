#ifndef FORMULAWIDGET_H
#define FORMULAWIDGET_H

#include <QPainter>
#include <QWidget>
#include <QRegularExpression>
#include <QStyleOption>

// Класс визуализации формулы
class FormulaItem
{

 public:
  explicit FormulaItem(QString value): m_value(value){}

  static const QString RUGULAR_EXPRESSION; // Строка регулярного выражения для поиска формулы
  //Метод отрисовки
  QPoint draw(const QPoint& pos, QPainter& p) const;

 private:
  QString m_value;// Значение форулы
};

// класс для отрисовки всех формул
class FormulaWidget : public QWidget
{
    Q_OBJECT
    using BaseClass = QWidget;
public:
    explicit FormulaWidget(QWidget* parent = nullptr);

public slots:
    //Слот для установки формулы
    void setFormula(const QString& formula);

protected:
    virtual void paintEvent (QPaintEvent* event) override;

private:
    QList<FormulaItem> m_items;
};

#endif // FORMULAWIDGET_H
