#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30;//максимальный размер вектора
class Vector
{
    int size;//текущий размер
    int *beg;//указатель на начало динамического массива
public:
    Vector(){size=0; beg=0;}//конструктор без параметров 
    Vector(int s);//конструктор с параметром
    Vector(int s, int* mas);//конструктор с параметром
    Vector(const Vector &v);//конструктор копирования
    ~Vector();//деструктор
    const Vector& operator=(const Vector &v);//операция присваивания
    int operator[](int i);//доступ по индексу
    Vector operator+(int a);//добавление элемента
    Vector operator--();//удаление элемента
//дружественные функции ввода-вывода
    friend ostream& operator<<(ostream& out, const Vector &v);
    friend istream& operator>>(istream& in, Vector &v);
};
