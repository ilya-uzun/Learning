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
double z = 1.1;
float x = 9.3f;
long int t = 2;
float f =5;
// умножение числа на 2
// d = 16
cout << mi.Mult2(d) << endl;
; // x = 18.6
cout <<mf.Mult2(x) << endl;
// возведение числа в квадрат
// dd = 81 - целое число
// z = 1.21000... - вещественное число
cout << mi.MySquare(dd) << endl;
cout << mf.MySquare(z) << endl;
// деление чисел
// t = 2 - деление целых чисел
// f = 2.5 - деление вещественных чисел
cout << mi.DivNumbers(t, 2) << endl;
cout << mf.DivNumbers(f, 2) << endl;
cout << "end";
}
