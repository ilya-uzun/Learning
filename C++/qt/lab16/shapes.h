#ifndef SHAPES_H
#define SHAPES_H

#include <QWidget>
#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include "puff.h"

//Класс рисует элементы

class Shapes : public QWidget
{
public:
    Shapes(QWidget* parent = 0);

public:
    void paintEvent(QPaintEvent* e);

private:
    void doPainting();

};
#endif // SHAPES_H
