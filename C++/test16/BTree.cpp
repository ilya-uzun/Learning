#include "btree.h"

// Функция-компаратор для сравнения чисел типа double.Используется в qsort.

int compare(const void *a, const void *b) {
    auto result = *(double *) a - *(double *) b;
    if (result > 0) {
        return 1;
    }
    if (result < 0) {
        return -1;
    }
    return 0;
}

//Функция-компаратор для сравнения чисел типа double. Используется в qsort.

int f_compare(const char a, const char b) {
    auto result = a - b;
    if (result > 0) {
        return 1;
    }
    if (result < 0) {
        return -1;
    }
    return 0;
}

// Конструктор с параметром в виде указателя на родителський виджет.  Создает пустое дерево и присваивает переданный указатель на виджет.

BTree::BTree(GraphWidget *graph) {
    this->wGraph = graph;
    this->root = nullptr;
}

BTree::~BTree() {
    if (root) {
        destroyTree();  //Удаляет все элементы дерева
    }
}

//Метод для инциализации дерева изначальными значениями. Создает из этих значений иделаьно-сбалансированное дерево.

void BTree::initializeWithStartValue() {
//    vector<double> datalist = {10, 5, 4, 7, 12, 2, 24};
    vector<char> datalist = {'l', 'p', 'i', 'n', 'g', 's', 'a'};
    makeBalancedTree(datalist);
    update();
}

//Метод для рекурсивного уничтожения всех узлов дерева. Вызывает рекурсивный перегруженный метод, начиная с корня дерева

void BTree::destroyTree() {
    destroyTree(root);
    root = nullptr;
}

// Метод для рекурсивного уничтожения всех узлов дерева, начиная с текущего переданного узла.

void BTree::destroyTree(Node *node) {
    if (node != nullptr) {
        destroyTree(node->left);    //сначала для левого потомка,
        destroyTree(node->right);   //после для правого потомка.
        delete node;                //Если потомков нет, она удалит узел, полученный в качестве параметра функции
    }
}

//Метод поиска элемента в дереве по значению

Node *BTree::search(char key) {
    return search(key, root);
}

//Рекурсивный метод поиска элемента в дереве по значению начиная с переданного узла.
//Поиск по правилам двоичного поиска.Если элмемент не найден то выбрасывается исключение.

Node *BTree::search(char key, Node *node) {
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

void BTree::insert(char key) {
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

void BTree::insert(char key, Node *node) {
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

void BTree::remove(char key) {
    remove(key, root);
    update();
}

//Рекурсивный метод для удаления узла с заданным значением, начиная с теущего переданного узла.
//Поиск по правилам двоичного поиска.Если элмемент не найден, то выбрасывается исключение.

void BTree::remove(char key, Node *node) {
    if (node == nullptr) {
        throw runtime_error("Элемент не найден и поэтому не удален!");
    }

    if (*node > key) {
        remove(key, node->left);
    } else if (*node < key) {
        remove(key, node->right);
    } else if (nullptr != node->left && nullptr != node->right) {
        Node *replacingNode = findMin(node->right);
        if (isFind(replacingNode->data, node->right)) {
            node->data = replacingNode->data;
            remove(node->data, node->right);
        } else {
            throw runtime_error("Элемент не может быть удален, т.к. дерево не упорядочено!");
        }
    } else {
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

//Метод для двоичного поиска элемента в дереве по значнеию. Возвращает true, если элемент найден,иначе - false.

bool BTree::isFind(char key) {
    return isFind(key, root);
}

// Рекурсивный метод для двоичного поиска элемента в дереве по значнеию, начиная с текущего переданного узла.
// Возвращает true, если элемент найден, иначе - false.

bool BTree::isFind(char key, Node *node) {
    if (nullptr == node) {
        return false;
    } else if (*node > key) {
        return isFind(key, node->left);
    } else if (*node < key) {
        return isFind(key, node->right);
    }
    return true;
}

// Метод для поиска минимального элемента дерева.
// Возвращает самый крайний левый элемент начиная с корня дерева.
// Если дерево не упорядочено, то может сработать некорректно.

Node *BTree::findMin() {
    if (!root) {
        throw runtime_error("Дерево пустое!");
    }

    Node *min = findMin(root);

    return min;
}

// Метод для поиска максимального элемента дерева.
// Возвращает самый крайний правый элемент начиная с корня дерева. Если дерево не упорядочено, то может сработать некорректно.

Node *BTree::findMax() {
    if (!root) {
        throw runtime_error("Дерево пустое!");
    }

    Node *max = findMax(root);

    return max;
}

//Рекурсивный метод для поиска минимального элемента дерева.
//Возвращает самый крайний левый элемент начиная с текущего переданного узла.
//Если дерево не упорядочено, то может сработать некорректно.

Node *BTree::findMin(Node *node) {
    if (node == nullptr || node->left == nullptr) {
        return node;
    }

    return findMin(node->left);
}

//  Рекурсивный метод для поиска максимального элемента дерева.
//  Возвращает самый крайний правый элемент начиная с текущего переданного узла.
//  Если дерево не упорядочено, то может сработать некорректно.

Node *BTree::findMax(Node *node) {
    if (node == nullptr || node->right == nullptr) {
        return node;
    }

    return findMax(node->right);
}

// Метод прямого обхода с печатью значений элементов дерева в консоль

void BTree::preOrder() {
    if (!root) {
        throw runtime_error("Дерево пустое!");
    }
    preOrder(root);
}

// Метод симметричного обхода с печатью значений элементов дерева в консоль
void BTree::inOrder() {
    if (!root) {
        throw runtime_error("Дерево пустое!");
    }
    inOrder(root);
}

// Метод обратного обхода с печатью значений  элементов дерева в консоль

void BTree::postOrder() {
    if (!root) {
        throw runtime_error("Дерево пустое!");
    }
    postOrder(root);
}

// Рекурсивный метод прямого обхода с печатью значений
// элементов дерева в консоль, начиная с текущего переданного узла

void BTree::preOrder(Node *node) {
    if (nullptr != node) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

/**
 * Рекурсивный метод симметричного обхода с печатью значений
 * элементов дерева в консоль, начиная с текущего
 * переданного узла
 */
void BTree::inOrder(Node *node) {
    if (nullptr != node) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

/**
 * Рекурсивный метод обратного обхода с печатью значений
 * элементов дерева в консоль, начиная с текущего
 * переданного узла
 */
void BTree::postOrder(Node *node) {
    if (nullptr != node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

/**
 * Метод создания иделаьно-сбалансированного дерева
 * из вектора со значениями.
 * Формирует новое идеально-сбалансированное дерево поиска,
 * упорядоченность элементов в котором, однако не гарантируется,
 * т.к. идеально-сбалансированное не означает, что оно является
 * еще и деревом поиска.
 */
void BTree::makeBalancedTree(vector<char> &datalist) {
    destroyTree();
    VectorIter iter = datalist.begin();
    VectorIter end = datalist.end();
    root = balancedTree(&iter, &end, datalist.size());
}

/**
 * Рекурсивный метод для построения идеально-сбалансировного дерева
 * на основе указателей на итераторы начала и конца вектора со значениями
 * и кол-ва элементов в векторе.
 */
Node *BTree::balancedTree(VectorIter *iter, VectorIter *end, long n) {
    if (n == 0 || iter == nullptr || end == nullptr || *iter == *end) {
        return nullptr;
    }
    double dt = **iter;
    (*iter)++;
    Node *tree = new Node(wGraph, dt);
    //строим левое поддерево с n/2
    //узлами, рекурсивно вызывая
    //функцию (выполняя те же шаги,
    //что и для создания корня)
    tree->insertLeft(balancedTree(iter, end, n / 2));
    //строим правое поддерево с (n – n/2 – 1) узлами,
    // рекурсивно вызывая функцию (выполняя те же
    //шаги, что и для создания корня)
    tree->insertRight(balancedTree(iter, end, n - n / 2 - 1));

    return tree;
}

/**
 * Рекурсивный метод для сохранения значений элементов дерева в массив
 * в симметричном обходе
 */
void BTree::storeInOrder(Node *node, char *inorder, int *index_ptr) {
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

/**
 * Метод для упорядочивания элементов в дереве
 */
void BTree::sortTree(Node *root) {
    if (root == nullptr) {
        return;
    }

    int n = countNodes(root);

    // Create a temp array arr[] and store inorder traversal of tree in arr[]
    char *arr = new char[n];
    int i = 0;
    storeInOrder(root, arr, &i);

    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);

    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);

    // delete dynamically allocated memory to avoid meory leak
    delete[] arr;
}

/**
 * Рекурсивный метод для распределения значений из
 * массива в элементы дерева в симметричном обходе.
 * Если элементы в массиве упорядочены, то делает
 * дерево упорядоченным.
 */
void BTree::arrayToBST(char *arr, Node *root, int *index_ptr) {
    if (root == nullptr) {
        return;
    }

    //Вызов метода для левого поддерева
    arrayToBST(arr, root->left, index_ptr);

    //Запись текущего элмента массива в текущий узел
    root->data = arr[*index_ptr];
    (*index_ptr)++;

    //Вызов метода для правого поддерева
    arrayToBST(arr, root->right, index_ptr);
}

/**
 * Метод преобразования дерево в бинарное дерево поиска
 */
void BTree::convertToBalancedBST() {
    vector<char> datalist;
    storeDataInOrder(root, datalist);  //сбор данных в симматричном обходе
    makeBalancedTree(datalist);  //создание сбалансированного дерева на основе элементов списка
    sortTree(root);   //сортировка элементов дерева
    update();  //Вызов метода обновления параметров отрисовки дерева
}

//Метод сбора в вектор узлов дерева в прямом обходе

void BTree::storeNodesPreOrder(Node *root, vector<Node *> &nodes) {
    if (root == nullptr) {
        return;
    }

    nodes.push_back(root);
    storeNodesPreOrder(root->left, nodes);
    storeNodesPreOrder(root->right, nodes);
}

// Метод сбора в вектор значений элементов дерева в прямом обходе

void BTree::storeDataPreOrder(Node *root, vector<char> &dataList) {
    if (root == nullptr) {
        return;
    }

    dataList.push_back(root->data);
    storeDataPreOrder(root->left, dataList);
    storeDataPreOrder(root->right, dataList);
}

// Метод сбора в вектор значений элементов дерева в симметричном обходе

void BTree::storeDataInOrder(Node *root, vector<char> &dataList) {
    if (root == nullptr) {
        return;
    }

    storeDataPreOrder(root->left, dataList);
    dataList.push_back(root->data);
    storeDataPreOrder(root->right, dataList);
}

// Рекрсивынй метод получения кол-ва уровней(глубины) дерева, начиная с текущего переданного узла

int BTree::getLevels(Node *currNode) {
    if (currNode == nullptr) {
        return 0;
    }
    return max(getLevels(currNode->left) + 1, getLevels(currNode->right) + 1);
}

/**
 * Метод обновления параметров отрисовки дерева.
 */
void BTree::update() {
    if (!root) {
        return;
    }
    levels = getLevels(root);       //кол-во уровней в дереве
    levelHeight = WINDOW_HEIGHT / levels;   //высота уровня в пикселях
    update(root, 1, 1);    //обновление целевых позиций для всех узлов дерева
    //Перерасчет целевого радиуса
    Node::nodeRadius = min(min(((WINDOW_WIDTH / pow(2, levels) * 1.0) / 2) * 0.8, ((WINDOW_HEIGHT / levels) / 2) * 0.8), MAX_NODE_RADIUS);
    Node::nodeRadius = max(Node::nodeRadius, MIN_NODE_RADIUS);
    refreshNodesInScene();  //Очищение и повторная вставка элементов дерева на виджет
}

// Рекрсивный метод обновления целевых позиций в прямом обходе для всех узлов дерева, начиная с текущего переданного.

void BTree::update(Node *currNode, int level, int col) {
    if (!currNode) {
        return;
    }

    currNode->level = level;  //уровень текущего узла
    currNode->col = col;      //скозной номер узла в дереве (по прямому обходу)

    //Вычисление absCol, т.е. номера узла на текущем уровне
    int absCol = col - pow(2, level - 1) + 1;

    double ww = ((WINDOW_WIDTH - HORIZONTAL_PADDING * 2) / pow(2, level - 1));  //Ширина доступная для текущего узла

    currNode->x = ww * (absCol - 1) + ww / 2;
    currNode->y = WINDOW_HEIGHT - (level * levelHeight - levelHeight / 2);

    update(currNode->left, level + 1, col << 1);
    update(currNode->right, level + 1, (col << 1) | 1);
}

//Метод очищения и повторной вставки элементов дерева на виджет. Используется для соотвествия узлов дерева и отображаемых на виджете.

void BTree::refreshNodesInScene() {
    if (!wGraph) {
        return;
    }
    this->wGraph->clearScene(); //удаление узлов из сцены виджета
    QGraphicsScene *widgetScene = this->wGraph->scene();
    addNodesToScene(widgetScene, root);  //добавление узлов на сцену виджета
}

/**
 * Рекурсивный метод добавления
 * указателей узлов из дерева в сцену виджета в прямом обходе
 */
void BTree::addNodesToScene(QGraphicsScene *widgetScene, Node *root) {
    if (!root) {
        return;
    }
    widgetScene->addItem(root);
    addNodesToScene(widgetScene, root->left);
    addNodesToScene(widgetScene, root->right);
}

/**
 * Метод для подсветки переданного узла

 */
void BTree::highlightNode(Node *node) {
    if (!root) {
        return;
    }
    highlightNode(node, root);
}

/**
 * Рекрсивный метод поиска и подсветки переданного узла
 * в прямом обходе, начиная с текущего переданного.

 */
void BTree::highlightNode(Node *node, Node *currentNode) {
    if (!node || !currentNode) {
        return;
    }
    if (node == currentNode) {
        currentNode->highlighted = true;
        currentNode->update();
    } else {
        currentNode->highlighted = false;
    }
    highlightNode(node, currentNode->left);
    highlightNode(node, currentNode->right);
}

/**
 * Метод для удаления подсветки со всех узлов дерева
 */
void BTree::clearHighlight() {
    if (!root) {
        return;
    }
    clearHighlight(root);
}

/**
 * Рекурсивны метод для удаления подсветки со всех узлов дерева
 * в прямом обходе, начиная с текущего переданного.
 */
void BTree::clearHighlight(Node *node) {
    if (!node) {
        return;
    }
    node->highlighted = false;
    node->update();
    clearHighlight(node->left);
    clearHighlight(node->right);
}

// Метод подсчета кол-ва узлов в дереве

int BTree::countNodes(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Метод проверки упорядоченности элементов дерева.
// Возвращает true, если элменты упорядочены, иначе - false.

bool BTree::checkOrder() {
    vector<char> nodes;
    storeDataPreOrder(root, nodes);

    for (auto &el : nodes) {
        if (!isFind(el)) {
            return false;
        }
    }

    return true;
}
