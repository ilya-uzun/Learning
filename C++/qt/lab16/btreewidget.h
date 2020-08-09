#ifndef BTREEWIDGET_H
#define BTREEWIDGET_H

#include <QGraphicsView>
#include "globalvariable.h"

class BtreeWidget : public QGraphicsView
{
    int timerId = 0;  //Идентификатор таймера
public:
    BtreeWidget(QWidget *parent = nullptr);
    void startItemUpdateTimer();   // запуск таймера обновления элементов виджета
    void clearScene();     // удалениt всех элементов из сцены виджета
};

#endif // BTREEWIDGET_H
