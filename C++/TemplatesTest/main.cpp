#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyNumber
{
public:
MyNumber(void) { } // конструктор по умолчанию
void Mult2(T* t); // метод, умножающий число на 2
T MySquare(T); // метод, возвращающий квадрат числа для                                          //некоторого типа T
T DivNumbers(T, T);  // метод, который делит два числа                       типа //T и возвращает результат типа T  
};

// реализация метода, умножающего число на 2
template <class T>
void MyNumber<T>::Mult2(T* t)
{
*t = (*t) * 2;
}
// реализация метода, возвращающего квадрат числа
template <class T>
T MyNumber<T>::MySquare(T number)
{
return (T)(number * number);
}
// метод, который делит 2 числа и возвращает результат от деления
template <class T>
T MyNumber<T>::DivNumbers(T t1, T t2)
{
return (T)(t1 / t2);
};

int main()
{
MyNumber <int> mi; // объект mi класса работает с типом int
MyNumber <float> mf; // объект mf работает с типом float

int d = 8;
float x = 9.3f;

// умножение числа на 2
mi.Mult2(&d); // d = 16
mf.Mult2(&x); // x = 18.6

// возведение числа в квадрат
int dd;
dd = mi.MySquare(9); // dd = 81 - целое число

double z;
z = mf.MySquare(1.1); // z = 1.21000... - вещественное число

// деление чисел
long int t;
float f;

t = mi.DivNumbers(5, 2); // t = 2 - деление целых чисел
f = mf.DivNumbers(5, 2); // f = 2.5 - деление вещественных чисел
}
