#ifndef NODE_H
#define NODE_H

#include "global.h"
#include <cstdlib>
#include <QGraphicsItem>
#include <QVector>

class GraphWidget;

/**
 * Класс "Узел дерева"
 */
class Node : public QGraphicsItem {
public:
    static double nodeRadius;           //Вычисленный целевой радиус узла
    static double nodeCurrentRadius;    //Фактический текущий радиус узла
    static const double nodeRadiusStep; //Шаг измнеения радиуса узла

    //double data;        //Поле с данными (значением узла)
    char data;
    Node *left;         //Указатель на левый дочерний узел
    Node *right;        //Указатель на правый дочерний узел
    Node *parent;       //Указатель на родительский узел
    int level;          //Уровень узла (в глубину от 1 (для корня) до n, где n - самый нижний уровень дерева)
    int col;            //Номер узла на уровне (в ширину от 1 до n, где n - номер последнего узла на уровне)
    double x;           //Вычисленная целевая координата x
    double y;           //Вычисленная целевая координата y
    double currX = 0;   //Текущая фактическая координата x
    double currY = 0;   //Текущая фактическая координата y
    bool isInPosition = false;  //Признак, прибыл ли узел в вычисленную целевую позицию
    bool highlighted = false;   //Признак, подсвечен ли данный узел
    double nodeSpeed = 20.0;     //Базовая скорость движения узла из текущей позиции в целевую вычисленную
    GraphWidget *graph;         //Указатель на графический виджета для отрисовки узлов

    enum { Type = UserType + 1 };  //Переопредление индекса текущего класса в перечислении графических элементов данного приложения
protected:

    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;   //Метод-обработчик события изменения параметров узла

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override; //Метод отрисовки текущего узла

    QRectF boundingRect() const override;   //Метод для получения прямоугольника ограничивающего узел

    QPainterPath shape() const override;    //Метол для получения фигуры узла

    void drawCircle(const QStyleOptionGraphicsItem *option, QPainter *painter);  //Метод отрисовки круглой части узла

    void drawText(QPainter *painter);       //Метод для отрисовки текста в узле

    void connectWithChildren(QPainter *painter);    //Метод для отрисовки соединяющих линий от текущего узла к дочерним

    bool goToPos();                         //Метод перемещения узла в целевую позицию

    void updatePos();                       //Метод для обновления координат узла на графическом виджете на основе вычилсяемых координат

    QPointF centerPos() const;              //Метод получения локального центра координат
public:
    //Конструкторы
    Node(GraphWidget *graphWidget);
    explicit Node(GraphWidget *graphWidget, char data);
    Node(Node &nd);

    //Деструктор
    virtual ~Node();

    int type() const override { return Type; }   //Метод получения индекса текущего класса в перечислении графических элементов данного приложения

    static void recalculateRadius();    //Метод перерасчета целевога радиуса узла

    void detachFromParent();            //Метод для отсоединения текщего узла от родительского

    bool isEmpty();                     //Метод проверки, является ли узел условно пустым

    void insertLeft(Node *node);        //Метод для вставвки узла слева

    void insertRight(Node *node);       //Метод для вставвки узла справа


    //Переопределенные опереаторы равенства и сравнения
    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;

    bool operator<(const Node &rhs) const;

    bool operator>(const Node &rhs) const;

    bool operator<=(const Node &rhs) const;

    bool operator>=(const Node &rhs) const;

    bool operator==(const double &value) const;

    bool operator!=(const double &value) const;

    bool operator<(const double &value) const;

    bool operator>(const double &value) const;

    bool operator<=(const double &value) const;

    bool operator>=(const double &value) const;
};
#endif // NODE_H
