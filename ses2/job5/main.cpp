
#include "Pair.h"
#include "Rightangled.h"
#include "Object.h"
#include "Vector.h"
#include <iostream>
#include  <string>
using namespace std;

int main()
{
    Vector v(5); // вектор из 5 элементов
    Pair a; // объект класса Pair
    cin >> a;
    Rightangled b; //  объект класса Rightangled
    cin >> b; 
    Object* p = &a; // стаим указатель на объект класса  Pair
    v.Add(p);// добавляем объект в вектор
    p = &b; // ставим указатель на объект класса Rightangled
    v.Add(p); //  добавляем объект в вектор
    cout << v;// вывод вектора

}

