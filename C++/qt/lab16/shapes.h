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
    Shapes();

public:
    void paintEvent(QPaintEvent* e);

public:
    void doPainting();
    void getText();

};
#endif // SHAPES_H
