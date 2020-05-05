#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyNumber
{
public:
MyNumber(void) { } // конструктор по умолчанию
T Mult2(T t); // метод, умножающий число на 2
T MySquare(T); // метод, возвращающий квадрат числа для                                          //некоторого типа T
T DivNumbers(T, T);  // метод, который делит два числа                       типа //T и возвращает результат типа T  
};

// реализация метода, умножающего число на 2
template <class T>
T MyNumber<T>::Mult2(T t)
{
//*t = (*t) * 2;
return (T) (t = t * 2);
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
int dd = 9;
double z;
float x = 9.3f;
long int t;
float f;
// умножение числа на 2
; // d = 16
cout << mi.Mult2(d) << endl;
mf.Mult2(x); // x = 18.6

// возведение числа в квадрат

dd = mi.MySquare(9); // dd = 81 - целое число
cout << mi.Mult2(d) << endl;
z = mf.MySquare(1.1); // z = 1.21000... - вещественное число

// деление чисел
t = mi.DivNumbers(5, 2); // t = 2 - деление целых чисел
f = mf.DivNumbers(5, 2); // f = 2.5 - деление вещественных чисел
cout << "end";
}
