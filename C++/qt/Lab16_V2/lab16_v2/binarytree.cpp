#include "binarytree.h"

// Конструктор с параметром в виде указателя на родителський виджет.  Создает пустое дерево и присваивает переданный указатель на виджет.
BinaryTree::BinaryTree(TreeView *graph) {
    this->wGraph = graph;
    this->root = nullptr;
}

BinaryTree::~BinaryTree() {
    if (root) {
        destroyTree();  //Удаляет все элементы дерева
    }
}

//Метод для инциализации дерева изначальными значениями. Создает из этих значений иделаьно-сбалансированное дерево.
void BinaryTree::initializeWithStartValue() {
   // vector<double> datalist = {10, 5, 4, 7, 12, 2, 24};
    vector<char> datalist = {' ', ' ', 'a', 'a', 'a', 's', 's'};
    makeBalancedTree(datalist);
    update();
}

//Метод для рекурсивного уничтожения всех узлов дерева. Вызывает рекурсивный перегруженный метод, начиная с корня дерева
void BinaryTree::destroyTree() {
    destroyTree(root);
    root = nullptr;
}

// Метод для рекурсивного уничтожения всех узлов дерева, начиная с текущего переданного узла.
void BinaryTree::destroyTree(Node *node) {
    if (node != nullptr) {
        destroyTree(node->left);    //сначала для левого потомка,
        destroyTree(node->right);   //после для правого потомка.
        delete node;                //Если потомков нет, она удалит узел, полученный в качестве параметра функции
    }
}

//Метод поиска элемента в дереве по значению
Node *BinaryTree::search(char key) {
    return search(key, root);
}

//Рекурсивный метод поиска элемента в дереве по значению начиная с переданного узла.
//Поиск по правилам двоичного поиска.Если элмемент не найден то выбрасывается исключение.
Node *BinaryTree::search(char key, Node *node) {
    if (node != nullptr) {
        if (*node == key) {
            return node;
        }
        if (*node > key) {
            return search(key, node->left);
        } else {
            return search(key, node->right);
        }
    }
    throw runtime_error("Элемент не был найден!");
}

//Метод вставки узла с заданным значением в дерево.Поиск по правилам двоичного поиска.
//Если элмемент уже есть в дереве, то вставка не производится и выбрасывается исключение.
void BinaryTree::insert(char key) {
    if (root != nullptr) {
        insert(key, root);
    } else {
        root = new Node(wGraph, key);
    }
    update();
}

// Рекурсивный метод вставки узла с заданным значением в дерево, начиная с теущего переданного узла.
// Поиск по правилам двоичного поиска. Если элмемент уже есть в дереве, то вставка не производится  и выбрасывается исключение.
// Если вставка невозможна то тоже пробросится соответствующее исключение.
void BinaryTree::insert(char key, Node *node) {
    bool added = false;

    while (node != nullptr) {
        if (*node == key) {
            throw runtime_error("Такой элемент уже есть в дереве!");
        }
        if (*node <= key) {
            if (node->right != nullptr) {
                node = node->right;
            } else {
                Node *t = new Node(wGraph, key);
                t->parent = node;
                node->right = t;
                added = true;
                break;
            }
        } else if (*node > key) {
            if (node->left != nullptr) {
                node = node->left;
            } else {
                Node *t = new Node(wGraph, key);
                t->parent = node;
                node->left = t;
                added = true;
                break;
            }
        }
    }

    if (!added) {
        throw runtime_error("Элемент не был добавлен. Возможно, дерево не упорядочено!");
    }
}

// Метод для удаления узла с заданным значением. Поиск по правилам двоичного поиска.
// Если элмемент не найден, то выбрасывается исключение.
void BinaryTree::remove(char key) {
    remove(key, root);
    update();
}

//Рекурсивный метод для удаления узла с заданным значением, начиная с теущего переданного узла.
//Поиск по правилам двоичного поиска.Если элмемент не найден, то выбрасывается исключение.
void BinaryTree::remove(char key, Node *node) {
    if (node == nullptr) {
        throw runtime_error("Элемент не найден и поэтому не удален!");
    }

    if (*node > key) {
        remove(key, node->left);
    } else if (*node < key) {
        remove(key, node->right);
    } /*else if (nullptr != node->left && nullptr != node->right) {
        Node *replacingNode = findMin(node->right);
        if (isFind(replacingNode->data, node->right)) {
            node->data = replacingNode->data;
            remove(node->data, node->right);
        } else {
            throw runtime_error("Элемент не может быть удален, т.к. дерево не упорядочено!");
        }
    } */ else {
        if (!node->parent && !node->left && !node->right) {
            destroyTree();
            return;
        }
        Node *oldNode = node;
        node = (node->left != nullptr) ? node->left : node->right;
        if (node != nullptr) {
            node->parent = oldNode->parent;
            if (node->parent) {
                if (node->parent->left == oldNode) {
                    node->parent->left = node;
                }
                if (node->parent->right == oldNode) {
                    node->parent->right = node;
                }
            } else {
                root = node;
            }
        }
        delete oldNode;
    }
}


//Метод создания иделаьно-сбалансированного дереваиз вектора со значениями.
//Формирует новое идеально-сбалансированное дерево поиска, упорядоченность элементов в котором, однако не гарантируется,
//т.к. идеально-сбалансированное не означает, что оно является еще и деревом поиска.

void BinaryTree::makeBalancedTree(vector<char> &datalist) {
    destroyTree();
    VectorIter iter = datalist.begin();
    VectorIter end = datalist.end();
    root = balancedTree(&iter, &end, datalist.size());
}

//Рекурсивный метод для построения идеально-сбалансировного дерева
//на основе указателей на итераторы начала и конца вектора со значениями и кол-ва элементов в векторе.
Node *BinaryTree::balancedTree(VectorIter *iter, VectorIter *end, long n) {
    if (n == 0 || iter == nullptr || end == nullptr || *iter == *end) {
        return nullptr;
    }
    double dt = **iter;
    (*iter)++;
    Node *tree = new Node(wGraph, dt);
    //строим левое поддерево с n/2 узлами, рекурсивно вызывая
    //функцию (выполняя те же шаги, что и для создания корня)
    tree->insertLeft(balancedTree(iter, end, n / 2));
    //строим правое поддерево с (n – n/2 – 1) узлами,
    // рекурсивно вызывая функцию (выполняя те же
    //шаги, что и для создания корня)
    tree->insertRight(balancedTree(iter, end, n - n / 2 - 1));

    return tree;
}

//Рекурсивный метод для сохранения значений элементов дерева в массив в симметричном обходе
void BinaryTree::storeInOrder(Node *node, char *inorder, int *index_ptr) {
    if (node == nullptr) {
        return;
    }

    //Сбор значений из левого поддерева
    storeInOrder(node->left, inorder, index_ptr);

    //Запись значения узла в массив
    inorder[*index_ptr] = node->data;
    (*index_ptr)++;  //увеличение индекса

    //Сбор значений из правого поддерева
    storeInOrder(node->right, inorder, index_ptr);
}

//Метод для упорядочивания элементов в дереве
void BinaryTree::sortTree(Node *root) {
    if (root == nullptr) {
        return;
    }

    char n = countNodes(root);
    // Create a temp array arr[] and store inorder traversal of tree in arr[]
    char *arr = new char[n];
    int i = 0;
    storeInOrder(root, arr, &i);
    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);
    // delete dynamically allocated memory to avoid meory leak
    delete[] arr;
}

//Рекурсивный метод для распределения значений из массива в элементы дерева в симметричном обходе.
//Если элементы в массиве упорядочены, то делает дерево упорядоченным.
void BinaryTree::arrayToBST(char *arr, Node *root, int *index_ptr) {
    if (root == nullptr) { return; }
    //Вызов метода для левого поддерева
    arrayToBST(arr, root->left, index_ptr);
    //Запись текущего элмента массива в текущий узел
    root->data = arr[*index_ptr];
    (*index_ptr)++;
    //Вызов метода для правого поддерева
    arrayToBST(arr, root->right, index_ptr);
}

//Метод преобразования дерево в бинарное дерево поиска
void BinaryTree::convertToBalancedBST() {
    vector<char> datalist;
    storeDataInOrder(root, datalist);  //сбор данных в симматричном обходе
    makeBalancedTree(datalist);  //создание сбалансированного дерева на основе элементов списка
    sortTree(root);   //сортировка элементов дерева
    update();  //Вызов метода обновления параметров отрисовки дерева
}

//Метод сбора в вектор узлов дерева в прямом обходе
void BinaryTree::storeNodesPreOrder(Node *root, vector<Node *> &nodes)
{
    if (root == nullptr) {return; }

    nodes.push_back(root);
    storeNodesPreOrder(root->left, nodes);
    storeNodesPreOrder(root->right, nodes);
}

// Метод сбора в вектор значений элементов дерева в прямом обходе
void BinaryTree::storeDataPreOrder(Node *root, vector<char> &dataList)
{
    if (root == nullptr) {return; }

    dataList.push_back(root->data);
    storeDataPreOrder(root->left, dataList);
    storeDataPreOrder(root->right, dataList);
}

// Метод сбора в вектор значений элементов дерева в симметричном обходе
void BinaryTree::storeDataInOrder(Node *root, vector<char> &dataList)
{
    if (root == nullptr) { return;}
    storeDataPreOrder(root->left, dataList);
    dataList.push_back(root->data);
    storeDataPreOrder(root->right, dataList);
}

// Рекрсивынй метод получения кол-ва уровней(глубины) дерева, начиная с текущего переданного узла
int BinaryTree::getLevels(Node *currNode)
{
    if (currNode == nullptr) {return 0; }
    return max(getLevels(currNode->left) + 1, getLevels(currNode->right) + 1);
}

//Метод обновления параметров отрисовки дерева.
void BinaryTree::update() {
    if (!root) {
        return;
    }
    levels = getLevels(root);       //кол-во уровней в дереве
    levelHeight = 800.0 / levels;   //высота уровня в пикселях
    update(root, 1, 1);    //обновление целевых позиций для всех узлов дерева
    //Перерасчет целевого радиуса
    Node::nodeRadius = min(min(((800.0 / pow(2, levels) * 1.0) / 2) * 0.8, ((600.0 / levels) / 2) * 0.8), 80.0);
    Node::nodeRadius = max(Node::nodeRadius, 25.0); // 25 Минимальный радиус узла
    refreshNodesInScene();  //Очищение и повторная вставка элементов дерева на виджет
}

// Рекурсивный метод обновления целевых позиций в прямом обходе для всех узлов дерева, начиная с текущего переданного.
void BinaryTree::update(Node *currNode, int level, int col) {
    if (!currNode) {return;}

    currNode->level = level;  //уровень текущего узла
    currNode->col = col;      //скозной номер узла в дереве (по прямому обходу)
    //Вычисление absCol, т.е. номера узла на текущем уровне
    int absCol = col - pow(2, level - 1) + 1;

    double ww = ((800.0 - 0 * 2) / pow(2, level - 1));  //Ширина доступная для текущего узла

    currNode->x = ww * (absCol - 1) + ww / 2;
    currNode->y = 800.0 - (level * levelHeight - levelHeight / 2);

    update(currNode->left, level + 1, col << 1);
    update(currNode->right, level + 1, (col << 1) | 1);
}

//Метод очищения и повторной вставки элементов дерева на виджет. Используется для соотвествия узлов дерева и отображаемых на виджете.
void BinaryTree::refreshNodesInScene() {
    if (!wGraph) {
        return;
    }
    this->wGraph->clearAllElements(); //удаление узлов из сцены виджета
    QGraphicsScene *widgetScene = this->wGraph->scene();
    addNodesToScene(widgetScene, root);  //добавление узлов на сцену виджета
}

//Рекурсивный метод добавления указателей узлов из дерева в сцену виджета в прямом обходе
void BinaryTree::addNodesToScene(QGraphicsScene *widgetScene, Node *root) {
    if (!root) {
        return;
    }
    widgetScene->addItem(root);
    addNodesToScene(widgetScene, root->left);
    addNodesToScene(widgetScene, root->right);
}


// Метод подсчета кол-ва узлов в дереве
int BinaryTree::countNodes(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
