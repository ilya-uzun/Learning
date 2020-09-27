#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>
#include <QOpenGLWidget>

class Node;

/*
 Класс для отрисовки дерева
 */

class TreeView : public QGraphicsView
{
    int timerID = 0; // таймер
public:
     TreeView(QWidget *parent = nullptr);
     void startTimerUpdate(); // запуск таймера для обновления элементов отрисовки
     void clearAllElements(); // удаление всех элементов отрисовки
};

#endif // TREEVIEW_H
