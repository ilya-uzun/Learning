#ifndef SHAPES_H
#define SHAPES_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QPainter>
#include <QPainterPath>

#include "puff.h"

//Класс рисует элементы

class Shapes : public QDialog
{
    //Q_OBJECT

private:
    QString text ;
    QString *f ;

public:
    explicit Shapes(QWidget *parent = nullptr);
    ~Shapes();

public:
    void paintEvent(QPaintEvent* e);


public:

    void doPainting();

public Q_SLOTS: // куда

     void setText(const QString &);
};
#endif // SHAPES_H
