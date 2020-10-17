#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include "node.h"
#include "treeview.h"

using namespace std;

typedef vector<char>::iterator VectorIter;

// Класс "Бинарное дерево"
class BinaryTree {
private:
    Node* root = nullptr;       //Указатель на корневой узел
    int levels;                 //Кол-во уровней в дереве
    double levelHeight;         //Высота одного уровня в пикселях исходя из высоты окна
    TreeView *wGraph;        //Указатель на графический виджет для вывода узлов дерева
private:
    void destroyTree(Node *node);   //Рекурсивный метод удаления дерева
    Node * balancedTree(VectorIter* iter, VectorIter* end, long n);  //Метод для построения идеально-сбалансировного дерева
    void arrayToBST(char* arr, Node *root, char* index_ptr);  //Метод записи значений массива в дерево
    void sortTree(Node *root);          //Метод для сортировки дерева, сортировка нужна ля преобразования в бинарное дерево поиска convertToBalancedBST
    void storeInOrder(Node *node, char* inorder, char* index_ptr);  //Метод сохранения значений из дерева в массив
    void storeDataPreOrder(Node *root, vector<char> &dataList);    //Метод сохранения значений из дерева в вектор
    void update(Node *currNode, int level, int col);   //Метод обновления целевых позиций узлов дерева
    void addNodesToScene(QGraphicsScene *widgetScene, Node *root);  //Метод добавления узлов в сцену виджета
public:
    BinaryTree(TreeView *wGraph = nullptr);   //Конструктор с параметром
    virtual ~BinaryTree();                       //Деструктор

    void initializeWithStartValue();  //Метод инциализации дерева изначальными значениями
    void destroyTree();          //Метод удаления дерева
    Node * search(char key);   //Метод поиска элемента по значению
    void insert(char key);     //Метод вставки элемента по значению
    void remove(char key);     //Метод удаления элемента по значению
    void makeBalancedTree(vector<char> &datalist);  //Метод создания идеально-сбалансированного дерева из вектора со значениями
    void convertToBalancedBST();    //Метод преобразования дерева в идеально-сбалансированное дерево поиска
    void storeDataInOrder(Node *root, vector<char> &dataList); //Метод сбора в вектор значений элементов дерева
    void insert(char key, Node *node);    //Метод вставки узла с заданным значением в дерево
    Node *search(char key, Node *node);   //Метод поиска элемента в дереве по значению
    void remove(char key, Node *node);    //Метод для удаления узла с заданным значением
    void storeNodesPreOrder(Node *root, vector<Node *> &nodes);  //Метод сбора в вектор узлов дерева в прямом обходе
    int getLevels(Node *currNode);  //Метод получения кол-ва уровней(глубины) дерева
    void update();                  //Метод обновления параметров отрисовки дерева
    void refreshNodesInScene();     //Метод обновления узлов в сцене виджета
    int countNodes(Node *root);     //Метод для подсчета числа узлов в дереве, нужет для упорядочивания дерева
    bool checkOrder();              //Метод проверки упорядоченности элементов в дереве
};

#endif // BINARYTREE_H
