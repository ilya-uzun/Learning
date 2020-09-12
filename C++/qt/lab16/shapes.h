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
	QString text;	
	
public:
    Shapes();
    ~Shapes();

public:
    void paintEvent(QPaintEvent* e);

public:
    void doPainting();
    void getText(QString t);

public slots:
     QString setText();

};
#endif // SHAPES_H
