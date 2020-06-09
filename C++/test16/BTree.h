#pragma once

#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include "Node.h"
#include "global.h""
#include "graphwidget.h"

using namespace std;

typedef vector<double>::iterator VectorIter;

/**
 * Класс "Бинарное дерево"
 */

class BTree {
private:
    Node* root = nullptr;       //Указатель на корневой узел
    int levels;                 //Кол-во уровней в дереве
    double levelHeight;         //Высота одного уровня в пикселях исходя из высоты окна
    GraphWidget *wGraph;        //Указатель на графический виджет для вывода узлов дерева
private:
    void destroyTree(Node *node);       //Рекурсивный метод удаления дерева
    void preOrder(Node *node);          //Прямой обход с печатью
    void inOrder(Node *node);           //Симметричный обход с печатью
    void postOrder(Node *node);         //Обратный обход с печатью
    Node *findMin(Node *node);              //Метод для поиска минимального элемента дерева
    Node *findMax(Node *node);              //Метод для поиска максимального элемента дерева
    Node * balancedTree(VectorIter* iter, VectorIter* end, long n);  //Метод для построения идеально-сбалансировного дерева
    void arrayToBST(double* arr, Node *root, int* index_ptr);  //Метод записи значений массива в дерево
    void sortTree(Node *root);          //Метод для сортировки дерева
    void storeInOrder(Node *node, double* inorder, int* index_ptr);  //Метод сохранения значений из дерева в массив
    void storeDataPreOrder(Node *root, vector<double> &dataList);    //Метод сохранения значений из дерева в вектор
    void update(Node *currNode, int level, int col);   //Метод обновления целевых позиций узлов дерева
    void highlightNode(Node *node, Node *currentNode); //Метод для подсветки переданного узла
    void clearHighlight(Node *node);        //Метод удаления подсветки со всех узлов дерева
    void addNodesToScene(QGraphicsScene *widgetScene, Node *root);  //Метод добавления узлов в сцену виджета
public:
    BTree(GraphWidget *wGraph = nullptr);   //Конструктор с параметром
    virtual ~BTree();                       //Деструктор

    void initializeWithStartValue();  //Метод инциализации дерева изначальными значениями
    void destroyTree();          //Метод удаления дерева
    Node * search(double key);   //Метод поиска элемента по значению
    void insert(double key);     //Метод вставки элемента по значению
    void remove(double key);     //Метод удаления элемента по значению
    bool isFind(double key);     //Метод бинарного поиска элемента по значнию
    Node * findMin();            //Метод бинарного поиска элемента с минимальным значением
    Node * findMax();            //Метод бинарного поиска элемента с минимальным значением
    void preOrder();             //Метод прямого обхода дерева с печатью
    void inOrder();              //Метод симметричного обхода дерева с печатью
    void postOrder();            //Метод обратного обхода дерева с печатью
    void makeBalancedTree(vector<double> &datalist);  ////Метод создания идеально-сбалансированного дерева из вектора со значениями
    void convertToBalancedBST();    //Метод преобразования дерева в идеально-сбалансированное дерево поиска
    void storeDataInOrder(Node *root, vector<double> &dataList); //Метод сбора в вектор значений элементов дерева
    void insert(double key, Node *node);    //Метод вставки узла с заданным значением в дерево
    Node *search(double key, Node *node);   //Метод поиска элемента в дереве по значению
    void remove(double key, Node *node);    //Метод для удаления узла с заданным значением
    bool isFind(double key, Node *node);    //Метод для двоичного поиска элемента в дереве по значнеию
    void storeNodesPreOrder(Node *root, vector<Node *> &nodes);  //Метод сбора в вектор узлов дерева в прямом обходе
    int getLevels(Node *currNode);  //Метод получения кол-ва уровней(глубины) дерева
    void update();                  //Метод обновления параметров отрисовки дерева
    void refreshNodesInScene();     //Метод обновления узлов в сцене виджета
    void highlightNode(Node *node); //Метод подсветки узла в дереве
    void clearHighlight();          //Метод удаления подсветки со всех улов дерева
    int countNodes(Node *root);     //Метод для подсчета числа узлов в дереве
    bool checkOrder();              //Метод проверки упорядоченности элементов в дереве
};
