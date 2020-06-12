#include "graphwidget.h"
#include "node.h"
#include <QKeyEvent>
#include <QOpenGLWidget>


GraphWidget::GraphWidget(QWidget *parent) : QGraphicsView(parent) {
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(FullViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1.0), qreal(1.0));
    setMinimumSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}
//Метод запуска таймера обновления элементов виджета

void GraphWidget::startItemUpdateTimer() {
    if (!timerId) {
        timerId = startTimer(1000 / 25);
    }
}

/**
 * Метод удаления всех элементов из сцены виджета
 */
void GraphWidget::clearScene() {
    scene()->items().clear();
}
