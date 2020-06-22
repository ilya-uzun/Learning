#include "node.h"
#include "graphwidget.h"
#include <QGraphicsSceneMouseEvent>
#include <QStyleOption>
#include "iostream"

// Функция-предикат для проверки на равенство значений типа double с заданной точностью

bool equals(double a, double b, double epsilon = 0.01) {
    return fabs(a - b) < epsilon;
}

// Функция-предикат для проверки значений типа double с заданной точностью на отношение "<"

bool f_less(double a, double b) {
    return !equals(a, b) && signbit(a - b);
}

// Функция-предикат для проверки значений типа double с заданной точностью на отношение ">"

bool f_more(double a, double b) {
    return !equals(a, b) && !signbit(a - b);
}

 //Конструктор с парметром в виде указателя на родительский виджет.
//Создает условно пустой узел.

Node::Node(GraphWidget *graphWidget) : graph(graphWidget) {
    //this->data = -1000000.00;
    this->data = 'a';
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->graph = graphWidget;
    updatePos();

    //Флаг получения событий о наведении курсора
    setAcceptHoverEvents(true);

    //Флаг, что данный элемент посылает события об изменении своих координат
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

// Конструктор с парметром в виде указателя на родительский виджет и
// значением узла.
// Создает узел с заданным значением.

Node::Node(GraphWidget *graphWidget, char data) : graph(graphWidget) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->graph = graphWidget;
    updatePos();

    //Флаг получения событий о наведении курсора
    setAcceptHoverEvents(true);

    //Флаг, что данный элемент посылает события об изменении своих координат
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

//Конструктор копирования.
//Учитывает самоприсваивание.

Node::Node(Node &nd) : graph(nd.graph) {
    if (this == &nd) {
        return;
    }
    this->data = nd.data;
    this->parent = nd.parent;
    this->left = nd.left;
    this->right = nd.right;
    this->x = nd.x;
    this->y = nd.y;
    this->currX = nd.currX;
    this->currY = nd.currY;
    this->graph = nd.graph;
    updatePos();

    //Флаг получения событий о наведении курсора
    setAcceptHoverEvents(true);

    //Флаг, что данный элемент посылает события об изменении своих координат
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

 //Деструктор

Node::~Node() {
    detachFromParent();
}


//Метод перерасчета целевога радиуса узла

void Node::recalculateRadius() {
    if (abs(nodeRadius - nodeCurrentRadius) > nodeRadiusStep) {
        if (nodeRadius > nodeCurrentRadius) {
            nodeCurrentRadius += nodeRadiusStep;
        } else {
            nodeCurrentRadius -= nodeRadiusStep;
        }
    }
}

//Метод для отсоединения текщего узла от родительского

void Node::detachFromParent() {
    if (!parent) {
        return;
    }
    if (parent->left == this) {
        parent->left = nullptr;
    }
    if (parent->right == this) {
        parent->right = nullptr;
    }
}

// Метод проверки, является ли узел условно пустым

bool Node::isEmpty() {
    return (this->data == -1000000.00
    && this->parent == nullptr
    && this->left == nullptr
    && this->right == nullptr);
}


 // Метод для вставвки узла слева от текущего,
 // Т.е. в качестве левого дочернего узла.

void Node::insertLeft(Node *node) {
    if (!node) {
        return;
    }

    if (left) {
        left->parent = node;
        node->left = this->left;
        this->left = node;
        node->parent = this;
    } else {
        left = node;
        node->parent = this;
    }
}

// Метод для вставвки узла справа от текущего,
// Т.е. в качестве правого дочернего узла.

void Node::insertRight(Node *node) {
    if (!node) {
        return;
    }

    if (right) {
        right->parent = node;
        node->right = this->right;
        this->right = node;
        node->parent = this;
    } else {
        right = node;
        node->parent = this;
    }
}


//Метод-обработчик события изменения параметров узла.

QVariant Node::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionHasChanged && scene()) {   //Если позиция узла была измнеения
        graph->startItemUpdateTimer();  //Запуск таймера обновления элементов виджета
    }
    return QGraphicsItem::itemChange(change, value);
}

//Метод отрисовки текущего узла

void Node::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *) {
    isInPosition = goToPos();
    connectWithChildren(painter);
    drawCircle(option, painter);
    drawText(painter);

    if (!this->parent) {
        Node::recalculateRadius();
        cout << endl << to_string(qrand()) + "Repainting!" << endl;
    }
}

// Метод для получения прямоугольника ограничивающего узел

QRectF Node::boundingRect() const {
    return QRectF(-nodeCurrentRadius, -nodeCurrentRadius, nodeCurrentRadius * 2, nodeCurrentRadius * 2);
}


// Метол для получения фигуры узла.
// Формирует фигуру в виде векторного объекта-пути
// и возвращает её.

QPainterPath Node::shape() const {
    QPainterPath path;
    path.addEllipse(centerPos(), nodeCurrentRadius * 2, nodeCurrentRadius * 2);
    return path;
}

//Метод отрисовки круглой части узла

void Node::drawCircle(const QStyleOptionGraphicsItem *option, QPainter *painter) {
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(Qt::white);

    if (highlighted) {   //если узел подсвечен
        painter->setPen(QPen(Qt::blue, 3));
        painter->setBrush(Qt::yellow);
    } else if (option->state & QStyle::State_MouseOver) {  //если курсор поверх узла
        painter->setBrush(Qt::cyan);
    }

    painter->drawEllipse(centerPos(), nodeCurrentRadius, nodeCurrentRadius);
}

//Метод для отрисовки текста в узле

void Node::drawText(QPainter *painter) {
    QString str = QString::number(data, 'f', 2);
    painter->setFont(QFont("Arial", 12, QFont::Bold));
    painter->drawText(shape().boundingRect(), Qt::AlignCenter, str);
}

//Метод для отрисовки соединяющих линий от текущего узла к дочерним

void Node::connectWithChildren(QPainter *painter) {
    painter->setPen(QPen(Qt::black, 3));
    if (left) {
        if (left->isInPosition) {
            QLineF line(mapFromItem(this, 0, 0), mapFromItem(this->left, 0, 0));
            painter->drawLine(line);
        }
    }
    if (right) {
        if (right->isInPosition) {
            QLineF line(mapFromItem(this, 0, 0), mapFromItem(this->right, 0, 0));
            painter->drawLine(line);
        }
    }
}


 // Метод перемещения узла в целевую позицию.
 // Если узел уже на месте, то возращает true, иначе - false

bool Node::goToPos() {
    double y1 = currY;
    double x1 = currX;
    double dy = (y - currY);
    double dx = (x - currX);
    double slope = (dy / dx == INFINITY) ? 0 : dy / dx;

    if (abs(dy) > nodeSpeed || abs(dx) > nodeSpeed) {
        if (abs(dy) > abs(dx)) {
            if (y > currY) {
                currY += nodeSpeed;
            } else {
                currY -= nodeSpeed;
            }

            if (slope == 0) {
                currX += nodeSpeed;
            } else {
                currX = (currY + slope * x1 - y1) / slope;
            }

            if (abs(slope) < EP) {
                if (x > currX) {
                    currX += nodeSpeed;
                } else {
                    currX -= nodeSpeed;
                }
            } else {
                currX = (currY + slope * x1 - y1) / slope;
            }
        } else {
            if (x > currX) {
                currX += nodeSpeed;
            } else {
                currX -= nodeSpeed;
            }

            if (abs(slope) < EP) {
                if (y > currY) {
                    currY += nodeSpeed;
                } else {
                    currY -= nodeSpeed;
                }
            } else {
                currY = (slope * currX - slope * x1 + y1);
            }
        }
        updatePos();
        return false;
    } else {
        return true;
    }
}

// Метод для обновления координат узла на графическом виджете на основе вычилсяемых координат

void Node::updatePos() {
    setPos(graph->sceneRect().left() + currX, graph->sceneRect().bottom() - currY);
}

//Метод получения локального центра координат

QPointF Node::centerPos() const {
    QPointF center = QPointF(this->boundingRect().center());
    return center;
}

// Перегруженный оператор проверки узлов на равенство

bool Node::operator==(const Node &rhs) const {
    return data == rhs.data;
}

// Перегруженный оператор проверки узлов на неравенство

bool Node::operator!=(const Node &rhs) const {
    return !(rhs == *this);
}

// Перегруженный оператор проверки узлов на отношение "<"

bool Node::operator<(const Node &rhs) const {
    return data < rhs.data;
}

// Перегруженный оператор проверки узлов на отношение ">"

bool Node::operator>(const Node &rhs) const {
    return rhs < *this;
}

//Перегруженный оператор проверки узлов на отношение "<="

bool Node::operator<=(const Node &rhs) const {
    return !(rhs < *this);
}

// Перегруженный оператор проверки узлов на отношение ">="

bool Node::operator>=(const Node &rhs) const {
    return !(*this < rhs);
}

// Перегруженный оператор "==" для сравнения значения узла с другим значением такого же типа на равенство

bool Node::operator==(const double &value) const {
    return equals(data, value);
}

// Перегруженный оператор "==" для сравнения значения узла с другим значением такого же типа на неравенство

bool Node::operator!=(const double &value) const {
    return !equals(data, value);
}

//Перегруженный оператор "==" для сравнения значения узла с другим значением такого же типа на отношение "<"

bool Node::operator<(const double &value) const {
    return f_less(data, value);
}

//Перегруженный оператор "==" для сравнения значенияузла с другим значением такого же типана отношение ">"

bool Node::operator>(const double &value) const {
    return f_more(data, value);
}

// Перегруженный оператор "==" для сравнения значенияузла с другим значением такого же типана отношение "<="
bool Node::operator<=(const double &value) const {
    return f_less(data, value) || equals(data, value);
}

//Перегруженный оператор "==" для сравнения значения узла с другим значением такого же типа на отношение ">="
bool Node::operator>=(const double &value) const {
    return f_more(data, value) || equals(data, value);
}

//СТАТИЧЕСКАЯ ИНИЦИАЛИЗАЦИЯ
double Node::nodeRadius = 0;
double Node::nodeCurrentRadius = MIN_NODE_RADIUS;
const double Node::nodeRadiusStep = 0.2;
