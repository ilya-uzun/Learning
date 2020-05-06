#pragma once
#include "Time.h"
#include "Vector.cpp"
#include <iostream>
using namespace std;

int main()
{
   //инициализация, ввод и вывод значений вектора
   Time t;
   cin>>t;
   cout<<t;
   Vector <int>  A(5,0);//создали вектор из 5 элементов, заполненые нулями 
   cout << "\n Input Vector A = " << A << endl;
   cin >> A;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   cout << A << "\n";//вывели значения элементов вектора
   Vector <int> B(3,0);//создали вектор из 5 элементов, заполненые нулями 
   cout << "Input Vector B " << endl;
   cin >> B;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
   //cout << b << "\n";//вывели значения элементов вектора
   Vector <int> C(2,0);
   C[0] = A[2]+B[1];// ввести у элемент вектора с сумму элементов векторов а и b
   cout << "Output Vector C sima A[2]+B[1]= "<< endl;
   cout <<  C << endl;
   // определение длины ектора
   cout << "Size Vector (C) = "<< endl;
   cout <<  C() << endl;
   cout << "\n";
   
return 0;
}

