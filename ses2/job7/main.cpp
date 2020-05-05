#pragma once
#include "Time.h"
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
   //инициализация, ввод и вывод значений вектора
   Time t;
   cin>>t;
   cout<<t;
   Vector <int>  A(5,0);//создали вектор из 5 элементов, заполненые нулями 
   //cout << "\n Input Vector A = " << A << endl;
   //cin >> a;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   //cout << A << "\n";//вывели значения элементов вектора
   //  Vector <int> b(3);//создали вектор из 5 элементов, заполненые нулями 
   //  cout << "Input Vector B " << endl;
   //  cin >> b;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   //  //cout << b << "\n";//вывели значения элементов вектора
   //  Vector <int> c(2);
   //  c[0] = a[2]+b[1];// ввести у элемент вектора с сумму элементов векторов а и b
   //  cout << "Output Vector C sima A[2]+B[1]= "<< endl;
   //  cout <<  c << endl;
   //  // определение длины ектора
   //  cout << "Size Vector (C) = "<< endl;
   //  cout <<  c() << endl;
   //  cout << "\n";
    //разыменовываем значения, которое возвращает a.first() выводим его
    //cout << "First element Vektora A ="<< *(a.first()) << endl;
return 0;
}

