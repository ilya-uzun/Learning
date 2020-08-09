#include "btreewidget.h"

BtreeWidget::BtreeWidget(QWidget *parent): QGraphicsView(parent)
{
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
// запуск таймера обновления элементов виджета

void BtreeWidget::startItemUpdateTimer() {
    if (!timerId) {
        timerId = startTimer(1000 / 25);
    }
}

// удаление всех элементов из сцены виджета

void BtreeWidget::clearScene() {
    scene()->items().clear();
}
