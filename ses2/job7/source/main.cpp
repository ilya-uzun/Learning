#pragma once
#include "Time.h"
#include "Vector.cpp"
//#include"Vector.h"
#include <iostream>
using namespace std;

int main()
{
    const int k = 11;
    Time p;
    cout << "\n Input Time p = " << p << endl;
    p = p + k;
    cout << "\n Input Time p + k = " << p << endl;
    Vector <int>  A(5,0);//создали вектор из 5 элементов, заполненые нулями 
    cout << "\n Input Vector A = " << A << endl;
    cin >> A;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
	A + k; // добавление константы ко всем элементам вектора
	cout << "\n Input Vector A + k(const 11) = " << A << endl;
    cout << A << "\n";//вывели значения элементов вектора
    Vector <int> B(3,0);//создали вектор из 5 элементов, заполненые нулями 
    cout << "Input Vector B " << endl;
    cin >> B;//ввели с клавиатуры значения элементов вектора(ошибка компиляции считает что cin вводит char)
    Vector <int> C(2,0);
    C[0] = A[2]+B[1];// ввести у элемент вектора с сумму элементов векторов а и b
    cout << "Output Vector C sima A[2]+B[1] = ";
    cout <<  C[0] << endl;
	Time t;
	cout << "Imput Time t  - " << endl;
	cin >> t;
	cout << "Output  Time t  - " << endl;
	cout << t;
	Vector<Time> N(5, t);
	cout << "\nImput Vector<Time> N(5,t)- " << endl;
	cin >> N;
	cout << "Output Vector<Time> N(5,t) = ";
	cout << N << endl;
   
return 0;
}

