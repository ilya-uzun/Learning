#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyNumber
{
public:
MyNumber() { } // конструктор по умолчанию
void Mult2(T *t); // метод, умножающий число на 2
void MySquare(T *number); // метод, возвращающий квадрат числа для                                          //некоторого типа T
void DivNumbers(T t1, T t2,  T *t3);  // метод, который делит два числа                       типа //T и возвращает результат типа T  
};

// реализация метода, умножающего число на 2
template <class T>
void MyNumber<T>::Mult2(T *t)
{
*t = (*t) * 2;
//return (T) (t = t * 2);
}
// реализация метода, возвращающего квадрат числа
template <class T>
void MyNumber<T>::MySquare(T *number)
{
    *number *= (*number);
//return (T)(number * number);
}
// метод, который делит 2 числа и возвращает результат от деления
template <class T>
void MyNumber<T>::DivNumbers(T t1, T t2, T *t3)
{
    *t3 = (t1 / t2); 
//return (T)(t1 / t2);
};

int main()
{
MyNumber <int> mi; // объект mi класса работает с типом int
MyNumber <float> mf; // объект mf работает с типом float
MyNumber <double> md;
int d = 8;
int dd = 9;
double z = 1.1;
float x = 9.3f;
int t = 4;
float f =5;
// умножение числа на 2
// d = 16
mi.Mult2(&d);
cout << d << endl;
// x = 18.6
mf.Mult2(&x);
cout << x << endl;
//cout <<mf.Mult2(x) << endl;
// возведение числа в квадрат
// dd = 81 - целое число
// z = 1.21000... - вещественное число
mi.MySquare(&dd);
cout << dd << endl;
md.MySquare(&z);
cout << z << endl;
// деление чисел
// t = 2 - деление целых чисел
// f = 2.5 - деление вещественных чисел
 mi.DivNumbers(t, 2, &t);
cout << t << endl;
mf.DivNumbers(f, 2, &f); 
cout << f << endl;
cout << "end";
}
