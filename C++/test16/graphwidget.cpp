#include "graphwidget.h"
#include "Node.h"
#include <QKeyEvent>
#include <QOpenGLWidget>

/**
 * Конструктор с параметром родительского виджета.
 * Допускает NULL
 * @param parent
 */
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

/**
 * Метод отрисовки фона
 * @param painter
 * @param rect
 */
void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect) {
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);
}

/**
 * Метод запуска таймера обновления элементов виджета
 */
void GraphWidget::startItemUpdateTimer() {
    if (!timerId) {
        timerId = startTimer(1000 / 25);
    }
}

/**
 * Метод-обработчик события таймера.
 * Обновляет(перерисовывает) элементы, пока они движутся
 * и некоторое время после их остановки.
 * @param event
 */
void GraphWidget::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);

    bool itemsMoved = true;

    const QList<QGraphicsItem *> items = scene()->items();
    for (QGraphicsItem *item : items) {
        if (qgraphicsitem_cast<Node *>(item)) {
            qgraphicsitem_cast<Node *>(item)->update();
            itemsMoved = qgraphicsitem_cast<Node *>(item)->isInPosition;
        }
    }

    if (itemsMoved) {
        killTimer(timerId);
        timerId = 0;
    }
}

/**
 * Метод-обработчик события нажатия клавиш
 * @param event
 */
void GraphWidget::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Plus:
            zoomIn();
            break;
        case Qt::Key_Minus:
            zoomOut();
            break;
        case Qt::Key_Space:
            repaint();
        default:
            QGraphicsView::keyPressEvent(event);
    }
}

/**
 * Метод увеличения масштаба сцены
 */
void GraphWidget::zoomIn() {
    scaleView(qreal(1.2));
}

/**
 * Метод уменьшения масштаба сцены
 */
void GraphWidget::zoomOut() {
    scaleView(1 / qreal(1.2));
}

/**
 * Метод масштабирования сцены по горизонтали и вертикали.
 * @param scaleFactor
 */
void GraphWidget::scaleView(qreal scaleFactor) {
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100) {
        return;
    }

    scale(scaleFactor, scaleFactor);
}

/**
 * Метод удаления всех элементов из сцены виджета
 */
void GraphWidget::clearScene() {
    scene()->items().clear();
}
