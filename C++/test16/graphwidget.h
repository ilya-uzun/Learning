#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class Node;

/**
 * Класс "Графический виджет".
 * По сути - холст, на котором отрисовывается дерево.
 */
class GraphWidget : public QGraphicsView {
    int timerId = 0;  //Идентификатор таймера
public:
   GraphWidget(QWidget *parent = nullptr); //Конструктор
    void startItemUpdateTimer();           //метод запуска таймера обновления элементов виджета
    void clearScene();     //метод удаления всех элементов из сцены виджета

};
#endif // GRAPHWIDGET_H
