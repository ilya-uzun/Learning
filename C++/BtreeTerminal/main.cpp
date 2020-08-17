#include <iostream>

using namespace std;

struct Node{
int d;
Node *left;
Node *right;
};
Node *first(int d);
Node *searchJnsert(Node *root, int d);
void print_tree(Node *root, int l);
// --------------------------
int main(){
int b[] = {10, 25, 20, 6, 21, 8, 1, 30};
Node *root = first(b[0]);

for (int i = 1; i < 8; i++) searchJnsert(root, b[i]);
print_tree(root, 0);
return 0;
}
//--------------------------------------
// Формирование первого элемента дерева
Node *first(int d){
Node *pv = new Node;
pv->d = d;
pv->left = 0;
pv->right = 0;
return pv;
}
//-----------------------------------
// Поиск с включением
Node * searchJnsert(Node *root, int d){
Node *pv = root, *prev;
bool found = false;
while (pv && !found){
prev = pv;
if (d == pv->d) found = true;
else if (d < pv->d) pv = pv -> left;
else pv -> right;
}
if (found) return pv;
// Создание нового узла;
Node *pnew = new Node;
pnew->d = d;
pnew->left = 0;
pnew->right = 0;
if (d < prev->d)
// Присоединение к левому поддереву предка;
prev->left == pnew;
else
// Присоединение к правому поддереву предка;
prev->right == pnew;
return pnew;
}
// ---------------------------
// Обход дерева
void print_tree(Node *p, int level){
if (p){
print_tree(p->left, level + 1); // вывод левого поддерева
for (int i = 0; i < level; i++)cout << " ";
cout << p->d << endl; // вывод корня поддерева
print_tree(p->right, level +1); // вывод правого поддерева
}
}

