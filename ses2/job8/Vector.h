#pragma once
#include "Object.h"
#include "Person.h"
#include "Abiturient.h"
#include <iostream>
class Vector
{
public:
    Vector(void){};//по умолчанию для класса DIalog
    Vector(int);//конструктор с параметрами
public:
~Vector(void);//деструктор
void Add();//добавление элемента в вектор
void Del();
void AverageAge();
void Show();
int operator()();//размер вектора
virtual void HandleEvent(const TEvent&e); // события 
protected:
Object**beg;//указатель на первый элемент вектора
int size;//размер
int cur;//текущая позиция
};
