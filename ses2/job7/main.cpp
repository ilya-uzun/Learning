#pragma once
#include "Vector.h"
#include <iostream>
using namespace std;
int main()
{
   //инициализация, ввод и вывод значений вектора
Vector<int>A(5,0);
cin>>A;
cout<<A<<endl;
//инициализация и вывод значений вектора
Vector <int>B(10,1);
cout<<B<<endl;
//операция присваивания
B=A;
cout<<B<<endl;
//доступ по индексу
cout <<A[2]<<endl;
//получение длины вектора
cout<<"size="<<A()<<endl;
//операция сложения с константой
B=A+10;
cout<<B<<endl;

Time t;
cin>>t;
cout<<t;
// тестироание сложения 
int k;
cout<<"k?";
cin>>k;
Time p;
p=t+k;
cout<<p;
Time t;
cin>>t;
cout<<t;
Vector<Time>A(5,t);
cin>>A;
cout<<A<<endl;
Vector <Time>B(10,t);
cout<<B<<endl;
B=A;
cout<<B<<endl;
cout <<A[2]<<endl;
cout<<"size="<<A()<<endl;
B=A+t;
cout<<B<<endl;
}

