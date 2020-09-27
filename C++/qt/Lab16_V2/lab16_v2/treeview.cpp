#include "treeview.h"

TreeView::TreeView(QWidget *parent ) : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(0, 0, 800.0, 600.0); // 800-ширина, 600-высота
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(FullViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(1.0), qreal(1.0));
    setMinimumSize(800.0, 600.0); // 800-ширина, 600-высота
}
// запуск таймера для обновления элементов отрисовки
void TreeView::startTimerUpdate()
{
    if (!timerID) {
        timerID = startTimer(1000 / 25);
    }
}
// удаление всех элементов отрисовки
void TreeView::clearAllElements()
{
    scene()->items().clear();
}
