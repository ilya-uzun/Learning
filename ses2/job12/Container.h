#pragma once
#include <iostream>
#include <map> //словарь
using namespace std;
//параметризированный класс
template<class T>
class Container
{
  map<int, T> v; //контейнер словарь
    int len; //длина словаря
public:
    Container(void); //конструктор без параметров
    Container(int n); //конструктор с параметрами
    void Print(); //печать
    ~Container(void); //деструктор
    T Srednee();
    void Add(int n, T el);
    int Max();
    int Min();
    void Del();
    void Delenie();
};

// 


