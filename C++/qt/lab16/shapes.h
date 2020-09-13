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
private:
    QString text ;
    QString *f ;

public:
    Shapes();
    ~Shapes();

public:
    void paintEvent(QPaintEvent* e);


public:

    void doPainting();

public Q_SLOTS: // куда

signals:
     void setText( QString);
};
#endif // SHAPES_H
