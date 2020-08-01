#ifndef BTREE_H
#define BTREE_H

struct node
{
    int key_value;//ключ – значение узла, типа int
    node* left;  //указатель на левого потомка
    node* right; //указатель на правого потомка
};


class Btree
{
public:
    Btree();
    ~Btree();

    void insert(int key);  //Функция вставки
    node* search(int key); //Функция поиска
    void destroy_tree();   //Функция удаления дерева

private:
    void destroy_tree(node* leaf);    //Рекурсивная функция удаления
    void insert(int key, node* leaf); //Рекурсивная функция //добавления узла в дерево
    node* search(int key, node* leaf);//Рекурсивная функция поиска //узла дерева с заданным //ключевым значением

    node* root; //Атрибут класса(Корневой узел)
};

#endif // BTREE_H
