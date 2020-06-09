#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>

class Node;

/**
 * Класс "Графический виджет".
 * По сути - холст, на котором отрисовывается дерево.
 */
class GraphWidget : public QGraphicsView {
Q_OBJECT
private:
    int timerId = 0;  //Идентификатор таймера
protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override; //Метод отрисовки фона
    void timerEvent(QTimerEvent *event) override;  //Обработчик события таймера
    void keyPressEvent(QKeyEvent *event) override; //Обработчик события нажатия клавиш
    void scaleView(qreal scaleFactor);             //Метод масштабирования сцены
public:
    GraphWidget(QWidget *parent = nullptr); //Конструктор
    void startItemUpdateTimer();           //метод запуска таймера обновления элементов виджета
    void clearScene();     //метод удаления всех элементов из сцены виджета
public slots:
    void zoomIn();      //Метод увеличения масштаба сцены
    void zoomOut();     //Метод уменьшения масштаба сцены
};

#endif // GRAPHWIDGET_H
